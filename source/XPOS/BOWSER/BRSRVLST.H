/*++

Copyright (c) 2000 Microsoft Corporation

Module Name:

    brsrvlst.c.

Abstract:

    This module implements the NtDeviceIoControlFile API's for the NT datagram
receiver (bowser).


Author:

    Larry Osterman (larryo) 6-May-2000

Revision History:

    6-May-2000 larryo

        Created

--*/
#ifndef _BRSRVLST_
#define _BRSRVLST_

VOID
BowserFreeBrowserServerList (
    IN PWSTR *BrowserServerList,
    IN ULONG BrowserServerListLength
    );

VOID
BowserShuffleBrowserServerList (
    IN PWSTR *BrowserServerList,
    IN ULONG BrowserServerListLength,
    IN BOOLEAN PrimaryDomain
    );

NTSTATUS
BowserGetBrowserServerList(
    IN PIRP Irp,
    IN PTRANSPORT Transport,
    IN PUNICODE_STRING DomainName OPTIONAL,
    OUT PWSTR **BrowserServerList,
    OUT PULONG BrowserServerListLength
    );

DATAGRAM_HANDLER(
    BowserGetBackupListResponse
    );
DATAGRAM_HANDLER(
    BowserGetBackupListRequest
    );

VOID
BowserpInitializeGetBrowserServerList(
    VOID
    );

VOID
BowserpUninitializeGetBrowserServerList(
    VOID
    );


#endif // _BRSRVLST_

