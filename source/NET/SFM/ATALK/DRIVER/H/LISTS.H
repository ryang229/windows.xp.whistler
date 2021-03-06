/*

Copyright (c) 2000  Microsoft Corporation

Module Name:

	lists.h

Abstract:

	This module contains the macros for managing lists

Author:

	Jameel Hyder (microsoft!jameelh)


Revision History:
	25 Oct 2000		Initial Version

Notes:	Tab stop: 4
--*/

#ifndef _LISTS_
#define _LISTS_

#define	AtalkLinkDoubleAtHead(pHead, p, Next, Prev)				\
								(p)->Next = pHead;				\
								(p)->Prev = (&pHead);			\
								if ((pHead) != NULL)			\
									(pHead)->Prev = &(p)->Next;	\
								pHead = (p);

#define	AtalkLinkDoubleAtEnd(pThis, pLast, Next, Prev)			\
							(pLast)->Next = pThis;				\
							(pThis)->Prev = &(pLast)->Next;		\
							(pThis)->Next = NULL;

#define	AtalkInsertDoubleBefore(pThis, pBefore, Next, Prev)		\
							(pThis)->Next = (pBefore);			\
							(pThis)->Prev = (pBefore)->Prev;	\
							(pBefore)->Prev = &(pThis)->Next;	\
							*((pThis)->Prev) = pThis;

#define	AtalkUnlinkDouble(p, Next, Prev)						\
								*((p)->Prev) = (p)->Next;		\
								if ((p)->Next != NULL)			\
									(p)->Next->Prev = (p)->Prev;

#endif	// _LISTS_

