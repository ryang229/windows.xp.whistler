/*++

Copyright (c) 2000 Microsoft Corporation

Module Name:

    DispVer.c

Abstract:

    This module contains NetpDbgDisplayLanManVersion().

Author:

    John Rogers (JohnRo) 25-Jul-2000

Environment:

    Portable to any flat, 32-bit environment.  (Uses Win32 typedefs.)
    Requires ANSI C extensions: slash-slash comments, long external names.

Revision History:

    25-Jul-2000 JohnRo
        Wksta debug support.
    18-Aug-2000 JohnRo
        PC-LINT found a portability problem.

--*/

#if DBG

// These must be included first:

#include <windef.h>             // IN, DWORD, etc.
#include <lmcons.h>             // NET_API_STATUS.

// These may be included in any order:

#include <netdebug.h>           // NetpDbgDisplay routines, FORMAT_ equates.
#include <lmserver.h>           // MAJOR_VERSION_MASK equate.


VOID
NetpDbgDisplayLanManVersion(
    IN DWORD MajorVersion,
    IN DWORD MinorVersion
    )
{
    NetpDbgDisplayTag( "LanMan version" );
    NetpDbgPrint(FORMAT_DWORD "." FORMAT_DWORD "\n",
            (DWORD) (MajorVersion & (MAJOR_VERSION_MASK)),
            (DWORD) (MinorVersion) );

} // NetpDbgDisplayLanManVersion

#endif // DBG
