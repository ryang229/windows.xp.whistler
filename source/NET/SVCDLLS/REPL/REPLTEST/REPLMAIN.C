/*++

Copyright (c) 2000-92  Microsoft Corporation

Module Name:

    ReplMain.c

Abstract:

    Startup program to test repl service.

Author:

    11/19/91        madana

Revision History:

    12-Jan-2000 JohnRo
        Added debug output; try direct call to ReplMain().
        Deleted tabs in source file.
        Get ReplMain's prototype from a header file.
    13-Jan-2000 JohnRo
        Fix parsing error.
    27-Jan-2000 JohnRo
        Arg passing still wasn't right.
    17-Feb-2000 JohnRo
        Initialize the RPC server.
    04-Mar-2000 JohnRo
        Changed ReplMain's interface to match new service controller.
    19-Mar-2000 JohnRo
        Fixed bug where RPC stuff was being stopped too soon.
    31-Mar-2000 JohnRo
        Service controller changed parameter list format.
    05-May-2000 JohnRo
        Avoid internal compiler error (initializing static struct).

--*/

#include <nt.h>
#include <ntrtl.h>
#include <nturtl.h>
#include <windef.h>
#include <winbase.h>

#include <lmcons.h>
#include <rpc.h>        // Needed by <rpcutil.h>.

#include <lmsname.h>    // SERVICE_REPL.
#include <netdebug.h>   // NetpDbgPrint(), FORMAT_ equates
#include <repl.h>       // repl_ServerIfHandle.
#include <repldefs.h>   // ReplMain().
#include <rpcutil.h>    // NetpInitRpcServer().
#include <winsvc.h>     // SERVICE_TABLE_ENTRY.


#if 0
SERVICE_TABLE_ENTRY ReplDispatchTable[] = {
                    { SERVICE_REPL,          ReplMain        },
                    { NULL,                  NULL                }
                };
#endif


void
main (
    void
    )

/*++

Routine Description:

    This is a temporary main routine for the replicator service.  It is
    separated from the workstation service for now so that the NT test
    machine can be updated without rebooting because the workstation
    service will be running and it cannot be terminated.

Arguments:

    None.

Return Value:

    None.

--*/
{
    NET_API_STATUS ApiStatus;
    NetpDbgPrint( "[replmain/main] beginning execution.\n" );

    NetpDbgPrint( "Calling NetpInitRpcServer...\n" );
    ApiStatus = NetpInitRpcServer();
    NetpAssert( ApiStatus == NO_ERROR );

    NetpDbgPrint( "[replmain/main] calling ReplMain.\n" );

    ReplMain( 0, NULL );

    NetpDbgPrint( "[replmain/main] Back from ReplMain.\n" );

    NetpDbgPrint( "[replmain] Stopping RPC server (if any).\n" );
    (void) NetpStopRpcServer( repl_ServerIfHandle );

    NetpDbgPrint( "[replmain/main] done execution.\n" );
}
