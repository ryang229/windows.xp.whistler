/****************************************************************************
*                                                                           *
* windef.h -- Basic Windows Type Definitions                                *
*                                                                           *
* Copyright (c) 1985-1994, Microsoft Corp. All rights reserved.             *
*                                                                           *
****************************************************************************/

/*++ BUILD Version: 0003    // Increment this if a change has global effects ;internal_NT
                                                                         ;internal_NT
Copyright (c) 1985-91, Microsoft Corporation                             ;internal_NT
                                                                         ;internal_NT
Module Name:                                                             ;internal_NT
                                                                         ;internal_NT
    windefp.h                                                            ;internal_NT
                                                                         ;internal_NT
Abstract:                                                                ;internal_NT
                                                                         ;internal_NT
    Private                                                              ;internal_NT
    Procedure declarations, constant definitions and macros for the Basic ;internal_NT
    Windows Types                                                        ;internal_NT
                                                                         ;internal_NT
--*/                                                                     ;internal_NT

#ifndef _WINDEF_        
#define _WINDEF_

#ifndef _WINDEFP_       ;internal_NT
#define _WINDEFP_       ;internal_NT

#ifndef NO_STRICT       ;public_NT
#ifndef STRICT          ;public_NT
#define STRICT 1        ;public_NT
#endif                  ;public_NT
#endif /* NO_STRICT */  ;public_NT

#ifdef __cplusplus      ;both
extern "C" {            ;both
#endif                  ;both

#ifndef WINVER          ;public_win40
#define WINVER 0x0400   ;public_win40 
#endif /* WINVER */     ;public_win40

/*
 * BASETYPES is defined in ntdef.h if these types are already defined
 */

#ifndef BASETYPES
#define BASETYPES
typedef unsigned long ULONG;
typedef ULONG *PULONG;
typedef unsigned short USHORT;
typedef USHORT *PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR *PUCHAR;
typedef char *PSZ;
#endif  /* !BASETYPES */

#define MAX_PATH          260

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#undef far
#undef near
#undef pascal

#define far
#define near
#if (_MSC_VER >= 800)
#define pascal __stdcall
#else
#define pascal
#endif

#ifdef DOSWIN32
#define cdecl _cdecl
#ifndef CDECL
#define CDECL _cdecl
#endif
#else
#define cdecl
#ifndef CDECL
#define CDECL
#endif
#endif

#if (_MSC_VER >= 800)
#define CALLBACK    __stdcall
#define WINAPI      __stdcall
#define WINAPIV     __cdecl
#define APIENTRY    WINAPI
#define APIPRIVATE  __stdcall
#define PASCAL      __stdcall
#else
#define CALLBACK
#define WINAPI
#define WINAPIV
#define APIENTRY    WINAPI
#define APIPRIVATE
#define PASCAL      pascal
#endif

#define FAR                 far
#define NEAR                near
#ifndef CONST
#define CONST               const
#endif

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef FLOAT               *PFLOAT;
typedef BOOL near           *PBOOL;
typedef BOOL far            *LPBOOL;
typedef BYTE near           *PBYTE;
typedef BYTE far            *LPBYTE;
typedef int near            *PINT;
typedef int far             *LPINT;
typedef WORD near           *PWORD;
typedef WORD far            *LPWORD;
typedef long far            *LPLONG;
typedef DWORD near          *PDWORD;
typedef DWORD far           *LPDWORD;
typedef void far            *LPVOID;
typedef CONST void far      *LPCVOID;

typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;

#ifndef NT_INCLUDED
#include <winnt.h>
#endif /* NT_INCLUDED */

/* Types use for passing & returning polymorphic values */
typedef UINT WPARAM;
typedef LONG LPARAM;
typedef LONG LRESULT;

#ifndef NOMINMAX

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#endif  /* NOMINMAX */

#define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))
#define LOWORD(l)           ((WORD)(l))
#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
#define LOBYTE(w)           ((BYTE)(w))
#define HIBYTE(w)           ((BYTE)(((WORD)(w) >> 8) & 0xFF))


#ifndef WIN_INTERNAL
DECLARE_HANDLE            (HWND);
DECLARE_HANDLE            (HHOOK);
#endif

typedef WORD                ATOM;

typedef HANDLE NEAR         *SPHANDLE;
typedef HANDLE FAR          *LPHANDLE;
typedef HANDLE              HGLOBAL;
typedef HANDLE              HLOCAL;
typedef HANDLE              GLOBALHANDLE;
typedef HANDLE              LOCALHANDLE;
typedef int (FAR WINAPI *FARPROC)();
typedef int (NEAR WINAPI *NEARPROC)();
typedef int (WINAPI *PROC)();

#ifdef STRICT
typedef void NEAR* HGDIOBJ;
#else
DECLARE_HANDLE(HGDIOBJ);
#endif

DECLARE_HANDLE(HACCEL);
DECLARE_HANDLE(HBITMAP);
DECLARE_HANDLE(HBRUSH);
;begin_winver_400
DECLARE_HANDLE(HCOLORSPACE);
;end_winver_400
DECLARE_HANDLE(HDC);
DECLARE_HANDLE(HGLRC);          // OpenGL
DECLARE_HANDLE(HDESK);
DECLARE_HANDLE(HENHMETAFILE);
DECLARE_HANDLE(HFONT);
DECLARE_HANDLE(HICON);
DECLARE_HANDLE(HMENU);
DECLARE_HANDLE(HMETAFILE);
DECLARE_HANDLE(HINSTANCE);
typedef HINSTANCE HMODULE;      /* HMODULEs can be used in place of HINSTANCEs */
DECLARE_HANDLE(HPALETTE);
DECLARE_HANDLE(HPEN);
DECLARE_HANDLE(HRGN);
DECLARE_HANDLE(HRSRC);
DECLARE_HANDLE(HSTR);
DECLARE_HANDLE(HTASK);
DECLARE_HANDLE(HWINSTA);
DECLARE_HANDLE(HKL);

typedef int HFILE;      
typedef HICON HCURSOR;      /* HICONs & HCURSORs are polymorphic */

typedef DWORD   COLORREF;
typedef DWORD   *LPCOLORREF;

#define HFILE_ERROR ((HFILE)-1)

typedef struct tagRECT
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT, *PRECT, NEAR *NPRECT, FAR *LPRECT;

typedef const RECT FAR* LPCRECT;        ;public_chicago

typedef struct _RECTL       /* rcl */
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECTL, *PRECTL, *LPRECTL;

typedef const RECTL FAR* LPCRECTL;      ;public_chicago

typedef struct tagPOINT
{
    LONG  x;
    LONG  y;
} POINT, *PPOINT, NEAR *NPPOINT, FAR *LPPOINT;

typedef struct _POINTL      /* ptl  */
{
    LONG  x;
    LONG  y;
} POINTL, *PPOINTL;

typedef struct tagSIZE
{
    LONG        cx;
    LONG        cy;
} SIZE, *PSIZE, *LPSIZE;

typedef SIZE               SIZEL;
typedef SIZE               *PSIZEL, *LPSIZEL;

typedef struct tagPOINTS
{
    SHORT   x;
    SHORT   y;
} POINTS, *PPOINTS, *LPPOINTS;

/* mode selections for the device mode function */
#define DM_UPDATE           1
#define DM_COPY             2
#define DM_PROMPT           4
#define DM_MODIFY           8

#define DM_IN_BUFFER        DM_MODIFY
#define DM_IN_PROMPT        DM_PROMPT
#define DM_OUT_BUFFER       DM_COPY
#define DM_OUT_DEFAULT      DM_UPDATE

/* device capabilities indices */
#define DC_FIELDS           1
#define DC_PAPERS           2
#define DC_PAPERSIZE        3
#define DC_MINEXTENT        4
#define DC_MAXEXTENT        5
#define DC_BINS             6
#define DC_DUPLEX           7
#define DC_SIZE             8
#define DC_EXTRA            9
#define DC_VERSION          10
#define DC_DRIVER           11
#define DC_BINNAMES         12
#define DC_ENUMRESOLUTIONS  13
#define DC_FILEDEPENDENCIES 14
#define DC_TRUETYPE         15
#define DC_PAPERNAMES       16
#define DC_ORIENTATION      17
#define DC_COPIES           18

#ifdef __cplusplus  ;both
}                   ;both
#endif              ;both

;begin_internal_NT
#ifndef _WINDEFP_NO_PDEVBRUSH
typedef PVOID   PDEVBRUSH;
#endif

typedef ULONG   LBOOL;
typedef ULONG   RBOOL;

typedef ULONG   COLOR;
typedef ULONG   COUNT;
typedef ULONG   PID;
typedef ULONG	TID;

// Note: these are not duplicates of types declared in ntdef.h, so
//	 you don't need to delete them.  Really, you don't.

#define CHAR_TO_WCHAR(ch)      ((WCHAR) ((UCHAR) (ch)))


typedef PVOID *PPVOID;

/* DEFALULT NEAR FONT MAPPER WEIGHTS */

#define NEAR_WT_FACENAME          0
#define NEAR_WT_FAMILYNAME        0
#define NEAR_WT_AVGWIDTH        250
#define NEAR_WT_XHEIGHT         100
#define NEAR_WT_SIZE            250
#define NEAR_WT_TECH              0
#define NEAR_WT_PANOSE          500
#define NEAR_WT_PANFAMILY         0
#define NEAR_WT_PANSERIF          7
#define NEAR_WT_PANWEIGHT         7
#define NEAR_WT_PANPROP           5
#define NEAR_WT_PANCONTRAST       6
#define NEAR_WT_PANSTROKEVAR      4
#define NEAR_WT_PANARMSTYLE       3
#define NEAR_WT_PANLETTER         5
#define NEAR_WT_PANMIDLINE        9
#define NEAR_WT_PANXHEIGHT        1
#define NEAR_WT_CHARSET         900

/* DEFAULT FAR FONT MAPPER WEIGHTS */

#define FAR_WT_FACENAME           0
#define FAR_WT_FAMILYNAME         0
#define FAR_WT_AVGWIDTH         250
#define FAR_WT_XHEIGHT          100
#define FAR_WT_SIZE             250
#define FAR_WT_TECH               0
#define FAR_WT_PANOSE           300
#define FAR_WT_PANFAMILY          0
#define FAR_WT_PANSERIF           8
#define FAR_WT_PANWEIGHT          5
#define FAR_WT_PANPROP            3
#define FAR_WT_PANCONTRAST        2
#define FAR_WT_PANSTROKEVAR       2
#define FAR_WT_PANARMSTYLE        2
#define FAR_WT_PANLETTER          2
#define FAR_WT_PANMIDLINE         1
#define FAR_WT_PANXHEIGHT         4
#define FAR_WT_CHARSET          900

/* DEFAULT FONT MAPPER CRITICAL DISTANCES */

#define FAR_DIST_FACENAME        10
#define FAR_DIST_FAMILYNAME      10
#define FAR_DIST_AVGWIDTH        10
#define FAR_DIST_XHEIGHT         10
#define FAR_DIST_SIZE            10
#define FAR_DIST_TECH            10
#define FAR_DIST_PANOSE          10
#define FAR_DIST_PANFAMILY       10
#define FAR_DIST_PANSERIF        10
#define FAR_DIST_PANWEIGHT       10
#define FAR_DIST_PANPROP         10
#define FAR_DIST_PANCONTRAST     10
#define FAR_DIST_PANSTROKEVAR    10
#define FAR_DIST_PANARMSTYLE     10
#define FAR_DIST_PANLETTER       10
#define FAR_DIST_PANMIDLINE      10
#define FAR_DIST_PANXHEIGHT      10
#define FAR_DIST_CHARSET         10

/* DEFAULT MAX DISTANCE SUM FOR FONT MAPPER */

#define FM_DISTSETSUM_MAX       1000
#endif /* _WINDEFP_ */ 
;end_internal_NT

#endif /* _WINDEF_ */   
