/*++

Copyright (c) 2000-1993  Microsoft Corporation

Module Name:

    TestExp0.c

Abstract:

    Test only export APIs, in a simple process (no threads).

Author:

    John Rogers (JohnRo) 16-Mar-2000

Revision History:

    16-Mar-2000 JohnRo
        Created.
    20-Mar-2000 JohnRo
        Main should wait for service start (if necessary), not Test routines.
    27-Jul-2000 JohnRo
        RAID 2274: repl svc should impersonate caller.
    22-Sep-2000 JohnRo
        Work with stdcall.
    03-Dec-2000 JohnRo
        Repl tests for remote registry.  Undo old thread junk.
    23-Jul-1993 JohnRo
        RAID 16685: NT repl should ignore LPTn to protect downlevel.

--*/


// These must be included first:

#include <windows.h>            // DWORD, IN, API, etc.
#include <lmcons.h>

// These may be included in any order:

#include <netdebug.h>           // NetpDbgPrint(), FORMAT_ equates
#include <repltest.h>   // TestReplApis(), etc.
#include <stdio.h>      // printf(), etc.
#include <stdlib.h>     // EXIT_FAILURE, EXIT_SUCCESS, _CRTAPI1.
#include <tstring.h>    // NetpAllocTStrFromStr().


DBGSTATIC VOID
Usage (
    VOID
    )
{
    (void) printf(
            "Usage: TestExp0 [-i] [-u] [-v] [-s \\\\server_name]\n\n"
            "flags:\n"
            "       -i              target is import-only\n"
            "       -s server_name  server to remove APIs to "
                                   "(default is local system)\n"
            "       -u              only does ordinary user tests "
                                   "(default include admin tests)\n"
            "       -v              verbose\n"
            "\n"
            "Example: TestExp0 -s \\\\somebody\n");
}


int _CRTAPI1
main(
    IN int argc,
    IN char *argv[]
    )

{
    int    ArgNumber;
    BOOL   ImportOnly = FALSE;
    BOOL   OrdinaryUserOnly = FALSE;
    LPTSTR UncServerName = NULL;
    BOOL   Verbose = FALSE;

    for (ArgNumber = 1; ArgNumber < argc; ArgNumber++) {
        if ((*argv[ArgNumber] == '-') || (*argv[ArgNumber] == '/')) {
            switch (tolower(*(argv[ArgNumber]+1))) // Process switches
            {
            case 'i' :
                ImportOnly = TRUE;
                break;
            case 'u' :
                OrdinaryUserOnly = TRUE;
                break;
            case 's' :
                UncServerName
                        = NetpAllocTStrFromStr( (LPSTR) argv[++ArgNumber]);
                NetpAssert( UncServerName != NULL );
                break;
            case 'v' :
                Verbose = TRUE;
                break;
            default :
                Usage();
                return (EXIT_FAILURE);
            }
        } else {
            Usage();  // Bad flag char.
            return (EXIT_FAILURE);
        }
    }

    NetpDbgPrint( "TestExp0: starting up ...\n" );
    TestExportDirApis(
            UncServerName,
            ImportOnly,
            OrdinaryUserOnly,
            Verbose );

    NetpDbgPrint( "TestExp0: done!\n" );

    return (EXIT_SUCCESS);

} // main
