/*++

Copyright (c) 2000-92  Microsoft Corporation

Module Name:

    NetLibNT.h

Abstract:

    This header file declares various common routines for use in the
    NT networking code.

Author:

    John Rogers (JohnRo) 02-Apr-2000

Environment:

    Only runs under NT; has an NT-specific interface (with Win32 types).
    Requires ANSI C extensions: slash-slash comments, long external names.

Notes:

    You must include <nt.h> and <lmcons.h> before this file.

Revision History:

    02-Apr-2000 JohnRo
        Created.
    16-Apr-2000 JohnRo
        Avoid conflicts with MIDL-generated files.
    06-May-2000 JohnRo
        Implement UNICODE.  Avoid NET_API_FUNCTION for non-APIs.
    06-Sep-2000 CliffV
        Added NetpApiStatusToNtStatus.
    27-Nov-2000 JohnRo
        Added NetpAllocTStrFromString() for local NetConfig APIs.
    03-Jan-2000 JohnRo
        Added NetpCopyStringToTStr() for FAKE_PER_PROCESS_RW_CONFIG handling.
    13-Mar-2000 JohnRo
        Added NetpAllocStringFromTStr() for NetpGetDomainId().
    22-Sep-2000 JohnRo
        RAID 6739: Browser too slow when not logged into browsed domain.
    01-Dec-2000 JohnRo
        RAID 3844: remote NetReplSetInfo uses local machine type.  (Added
        NetpGetProductType and NetpIsProductTypeValid.)

--*/

#ifndef _NETLIBNT_
#define _NETLIBNT_


PSTRING                  // Returns NULL on err; free with NetApiBufferFree.
NetpAllocStringFromTStr(
    IN LPTSTR Src
    );

NET_API_STATUS
NetpAllocTStrFromString(
    IN PSTRING lpstringSrc,
    OUT LPTSTR * BufPtr         // Must be freed with NetApiBufferFree().
    );

VOID
NetpCopyStringToTStr(
    OUT LPTSTR Dest,
    IN PSTRING Src
    );

NET_API_STATUS
NetpGetProductType(
    IN LPTSTR UncServerName OPTIONAL,
    OUT PNT_PRODUCT_TYPE ProductType
    );

// BOOL
// NetpIsProductTypeValid(
//     IN DWORD ProductType
//     );
//
#define NetpIsProductTypeValid( prod ) \
    (  ( (prod) == NtProductWinNt ) \
    || ( (prod) == NtProductLanManNt ) \
    || ( (prod) == NtProductServer ))

NET_API_STATUS
NetpNtStatusToApiStatus(
    IN NTSTATUS NtStatus
    );

NTSTATUS
NetpApiStatusToNtStatus(
    NET_API_STATUS NetStatus
    );

NET_API_STATUS
NetpRdrFsControlTree(
    IN LPTSTR TreeName,
    IN LPTSTR TransportName OPTIONAL,
    IN ULONG ConnectionType,
    IN DWORD FsControlCode,
    IN LPVOID SecurityDescriptor OPTIONAL,
    IN LPVOID InputBuffer OPTIONAL,
    IN DWORD InputBufferSize,
    OUT LPVOID OutputBuffer OPTIONAL,
    IN DWORD OutputBufferSize,
    IN BOOL NoPermissionRequired
    );

#endif // ndef _NETLIBNT_
