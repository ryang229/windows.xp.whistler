/*++
 *
 *  WOW v1.0
 *
 *  Copyright (c) 2000, Microsoft Corporation
 *
 *  WSHTBL2.h
 *  WOW32 16-bit SHELL API tables
 *
 *  History:
 *  Created 14-April-2000 by Chandan Chauhan (ChandanC)
--*/

    {W32FUN(WG32UNIMPLEMENTEDAPI,      "DUMMYENTRY",          MOD_SHELL,  0)},
    {W32FUN(WS32RegOpenKey,            "RegOpenKey",          MOD_SHELL,  sizeof(REGOPENKEY16))},
    {W32FUN(WS32RegCreateKey,          "RegCreateKey",        MOD_SHELL,  sizeof(REGCREATEKEY16))},
    {W32FUN(WS32RegCloseKey,           "RegCloseKey",         MOD_SHELL,  sizeof(REGCLOSEKEY16))},
    {W32FUN(WS32RegDeleteKey,          "RegDeleteKey",        MOD_SHELL,  sizeof(REGDELETEKEY16))},
    {W32FUN(WS32RegSetValue,           "RegSetValue",         MOD_SHELL,  sizeof(REGSETVALUE16))},
    {W32FUN(WS32RegQueryValue,         "RegQueryValue",       MOD_SHELL,  sizeof(REGQUERYVALUE16))},
    {W32FUN(WS32RegEnumKey,            "RegEnumKey",          MOD_SHELL,  sizeof(REGENUMKEY16))},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WS32DragAcceptFiles,       "DragAcceptFiles",     MOD_SHELL,  sizeof(DRAGACCEPTFILES16))},

  /*** 0010 ***/
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WS32DragQueryFile,         "DragQueryFile",       MOD_SHELL,  sizeof(DRAGQUERYFILE16))},
    {W32FUN(WS32DragFinish,            "DragFinish",          MOD_SHELL,  sizeof(DRAGFINISH16))},
    {W32FUN(LOCALAPI,                  "DragQueryPoint",      MOD_SHELL,  sizeof(DRAGQUERYPOINT16))},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},

  /*** 0020 ***/
    {W32FUN(WS32ShellExecute,          "ShellExecute",        MOD_SHELL,  sizeof(SHELLEXECUTE16))},
    {W32FUN(WS32FindExecutable,        "FindExecutable",      MOD_SHELL,  sizeof(FINDEXECUTABLE16))},
    {W32FUN(WS32ShellAbout,            "ShellAbout",          MOD_SHELL,  sizeof(SHELLABOUT16))},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},

  /*** 0030 ***/
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "WCI",                 MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "ABOUTDLGPROC",        MOD_SHELL,  0)},
    {W32FUN(WS32ExtractIcon,           "ExtractIcon",         MOD_SHELL,  sizeof(EXTRACTICON16))},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "ExtractAssociatedIcon",MOD_SHELL, sizeof(EXTRACTASSOCIATEDICON16))},
    {W32FUN(WS32DoEnvironmentSubst,    "DoEnvironmentSubst",  MOD_SHELL,  sizeof(DOENVIRONMENTSUBST16))},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "FINDENVIRONMENTSTRING",MOD_SHELL, 0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "INTERNALEXTRACTICON", MOD_SHELL,  0)},

  /*** 0040 ***/
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},

  /*** 0050 ***/
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},

  /*** 0060 ***/
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},

  /*** 0070 ***/
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},

  /*** 0080 ***/
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},

  /*** 0090 ***/
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "",                    MOD_SHELL,  0)},

  /*** 0100 ***/
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "HERETHARBETYGARS",    MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "FINDEXEDLGPROC",      MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "REGISTERSHELLHOOK",   MOD_SHELL,  0)},
    {W32FUN(WG32UNIMPLEMENTEDAPI,      "SHELLHOOKPROC",       MOD_SHELL,  0)},
