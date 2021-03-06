#include <windows.h>
#include "insignia.h"
#include "host_def.h"

#ifdef SIM32
/* 
 *      sim32.c -       Sim32 for Microsoft NT SoftPC.
 *
 *      Ade Brownlow    
 *      Wed Jun 5 91    
 *
 *      %W% %G% (c) Insignia Solutions 2000 
 *
 *      This module provides the Microsoft sim32 interface with the additional sas
 *      functionality and some host sas routines. We also provide cpu idling facilities.
 *      
 *      This module in effect provides (along with the cpu) what Microsoft term as the IEU -
 *      see documentation.
 */
#include "xt.h"
#include "sim32.h"
#include "sas.h"
#include "gmi.h"
#include "ckmalloc.h"
#include "cpu.h"

/********************************************************/
/* IMPORTS & EXPORTS */

/* Sas/gmi Sim32 crossovers */
GLOBAL BOOL Sim32FlushVDMPointer (double_word, word, UTINY *, BOOL);
GLOBAL BOOL Sim32FreeVDMPointer (double_word, word, UTINY *, BOOL);
GLOBAL BOOL Sim32GetVDMMemory (double_word, word, UTINY *, BOOL);
GLOBAL BOOL Sim32SetVDMMemory (double_word, word, UTINY *, BOOL);
GLOBAL sys_addr sim32_effective_addr (double_word, BOOL);

GLOBAL UTINY *sas_alter_size(sys_addr);
GLOBAL UTINY *host_sas_init(sys_addr);
GLOBAL UTINY *host_sas_term(void);

/* Microsoft sas extensions */
GLOBAL IMEMBLOCK *sas_mem_map (void);
GLOBAL void sas_clear_map(void);

IMPORT ULONG Sas_wrap_mask;

/********************************************************/
/* MACROS */
/* macro to convert the supplied address to intel address */
#define convert_addr(a,b,c,d) \
        { \
                if ((a = sim32_effective_addr (b,c)) == (sys_addr)-1)\
                {\
                        return (d);\
                }\
        }

/********************************************************/
/*      The actual sim32 interfaces, most of these routines can be more or less mapped directly
 *      to existing routines in sas or gmi.
 *
 *      WARNING: This routine returns a pointer into M, and
 *               WILL NOT work for backward M.
 */
UCHAR *Sim32pGetVDMPointer(ULONG addr, UCHAR pm)
{
        sys_addr iaddr;

        if (pm && (addr == 0))
	    return(NULL);

        convert_addr (iaddr, addr, pm, NULL);
//STF - need sas_wrap_mask with PE....iaddr &= Sas_wrap_mask;
        return (&(Start_of_M_area[iaddr]));
}

/*
 *  See Sim32pGetVDMPointer
 *
 *  This call must be maintaned as is because it is exported for VDD's
 *  in product 1.0.
 */
UCHAR *ExpSim32GetVDMPointer IFN3(double_word, addr, double_word, size, UCHAR, pm)
{
        return Sim32pGetVDMPointer(addr, (UCHAR)pm);
}


GLOBAL BOOL Sim32FlushVDMPointer IFN4(double_word, addr, word, size, UTINY *, buff, BOOL, pm)
{
        sys_addr iaddr;
        convert_addr (iaddr, addr, pm, 0);

//STF - need sas_wrap_mask with PE....iaddr &= Sas_wrap_mask;
	sas_overwrite_memory(iaddr, (ULONG)size);
        return (TRUE);
}

GLOBAL BOOL Sim32FreeVDMPointer IFN4(double_word, addr, word, size, UTINY *, buff, BOOL, pm)
{
        /* we haven't allocated any new memory so always return success */
        return (TRUE);
}

GLOBAL BOOL Sim32GetVDMMemory IFN4(double_word, addr, word, size, UTINY *, buff, BOOL, pm)
{
        sys_addr iaddr;
        convert_addr (iaddr, addr, pm, FALSE);
        /* effectivly a sas_loads */
        sas_loads (iaddr, buff, (sys_addr)size);

        /* always return success */
        return (TRUE);
}

GLOBAL BOOL Sim32SetVDMMemory IFN4(double_word, addr, word, size, UTINY *, buff, BOOL, pm)
{
        sys_addr iaddr;
        convert_addr (iaddr, addr, pm, FALSE);
        /* effectivly a sas_stores */
        sas_stores (iaddr, buff, (sys_addr)size);

        /* always return success */
        return (TRUE);
}

/********************************************************/
/* Support routines for sim32 above */
GLOBAL sys_addr sim32_effective_addr IFN2(double_word, addr, BOOL, pm)
{
    word seg, off;
    double_word descr_addr;
    DESCR entry;

    seg = (word)(addr>>16);
    off = (word)(addr & 0xffff);

    if (pm == FALSE)
    {
	return ((double_word)seg << 4) + off;
    }
    else
    {
	if ( selector_outside_table(seg, &descr_addr) == 1 )
	{
	/*
	This should not happen, but is a check the real effective_addr
	includes. Return error -1.
	*/
#ifndef PROD
        printf("NTVDM:sim32:effective addr: Error for addr %#x (seg %#x)\n",addr, seg);
        HostDebugBreak();
#endif
            return ((sys_addr)-1);
	}
	else
	{
	    read_descriptor(descr_addr, &entry);
	    return entry.base + off;
	}
    }
}


/********************************************************/
/* Microsoft extensions to sas interface */
LOCAL IMEMBLOCK *imap_start=NULL, *imap_end=NULL;
GLOBAL IMEMBLOCK *sas_mem_map ()
{
        /* produce a memory map for the whole of intel space */
        sys_addr iaddr;
        int mem_type;

        if (imap_start)
                sas_clear_map();

        for (iaddr=0; iaddr < Length_of_M_area; iaddr++)
        {
                mem_type = sas_memory_type (iaddr);
                if (!imap_end)
                {
                        /* this is the first record */
                        check_malloc (imap_start, 1, IMEMBLOCK);
                        imap_start->Next = NULL;
                        imap_end = imap_start;
                        imap_end->Type = mem_type;
                        imap_end->StartAddress = iaddr;
                        continue;
                }
                if (imap_end->Type != mem_type)
                {
                        /* end of a memory section & start of a new one */
                        imap_end->EndAddress = iaddr-1;
                        check_malloc (imap_end->Next, 1,IMEMBLOCK);
                        imap_end = imap_end->Next;
                        imap_end->Next = NULL;
                        imap_end->Type =mem_type;
                        imap_end->StartAddress = iaddr;
                }
        }
        /* terminate last record */
        imap_end->EndAddress = iaddr;
        return (imap_start);
}

GLOBAL void sas_clear_map()
{
        IMEMBLOCK *p, *q;
        for (p=imap_start; p; p=q)
        {
                q=p->Next;
                free(p);
        }
        imap_start=imap_end=NULL;
}

/********************************************************/
/* Microsoft specific sas stuff (ie host sas) */
#define SIXTEENMEG 1024*1024*12
LOCAL UTINY *reserve_for_sas = NULL;
LOCAL sys_addr current_sas_size =0;             /* A local Length_of_M_area */
GLOBAL UTINY *host_sas_init IFN1(sys_addr, size)
{
	UTINY *rez;
	DWORD M_plus_type_size;

        /* allocate 16 MEG of virtual memory */
        if (!reserve_for_sas)
        {
                if (!(reserve_for_sas = (UTINY *)VirtualAlloc ((void *)NULL, SIXTEENMEG,
                        MEM_RESERVE, PAGE_READWRITE)))
                {
#ifndef PROD
                        printf ("NTVDM:Failed to reserve 16 Meg virtual memory for sas\n");
#endif
                        exit (0);
                }
        }

	/* now commit to our size */
	M_plus_type_size = size + NOWRAP_PROTECTION +
			   ((size + NOWRAP_PROTECTION) >> 12);
	rez = (UTINY *)VirtualAlloc ((void *) reserve_for_sas,
				     M_plus_type_size,
				     MEM_COMMIT,
				     PAGE_READWRITE);
	if (rez)
		Length_of_M_area = current_sas_size = size;
	return (rez);
}

GLOBAL UTINY *host_sas_term()
{
        if (!reserve_for_sas)
                return (NULL);

        /* deallocate the reserves */
        VirtualFree (reserve_for_sas, SIXTEENMEG, MEM_RELEASE);

        /* null out reserve pointer */
        reserve_for_sas = NULL;

        Length_of_M_area = current_sas_size = 0;

        return (NULL);
}

GLOBAL UTINY *sas_alter_size IFN1(sys_addr, new)
{
        UTINY *tmp, *rez;
        if (!reserve_for_sas)
        {
#ifndef PROD
                printf ("NTVDM:Sas trying to alter size before reserve setup\n");
#endif 
                return (NULL);
        }

        /* if we are already at the right size return success */
        if (new == current_sas_size)
        {
                return (reserve_for_sas);
        }

        if (new > current_sas_size)
        {
                /* move to end of current commited area */
                tmp = reserve_for_sas + current_sas_size;
                if (!VirtualAlloc ((void *)tmp, (DWORD)(new - current_sas_size), MEM_COMMIT, 
                        PAGE_READWRITE))
                {
                        printf ("NTVDM:Virtual Allocate for resize from %d to %d FAILED!\n",
                                current_sas_size, new);
                        return (NULL);
                }
        }
        else
        {
                /* move to the place where sas needs to end */
                tmp = reserve_for_sas + new;

                /* now decommit the unneeded memory */
                if (!VirtualFree ((void *)tmp, (DWORD)(current_sas_size - new), MEM_DECOMMIT)) 
                {
                        printf ("NTVDM:Virtual Allocate for resize from %d to %d FAILED!\n",
                                current_sas_size, new);
                        return (NULL);
                }
        }
        Length_of_M_area = current_sas_size = new; 
        return (reserve_for_sas);
}

#endif /* SIM32 */
