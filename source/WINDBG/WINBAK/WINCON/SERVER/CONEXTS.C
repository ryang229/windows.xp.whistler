/***************************** Module Header ******************************\
* Module Name: conexts.c
*
* Copyright (c) 1985-93, Microsoft Corporation
*
* This module contains random debugging related functions.
*
\***************************************************************************/


#include "precomp.h"
#pragma hdrstop
#define NOEXTAPI
#include <wdbgexts.h>

/***************************************************************************\
* Global variables
\***************************************************************************/
PSTR pszAccessViolation = "USEREXTS: Access violation on \"%s\", switch to server context\n";
PSTR pszMoveException   = "exception in move()\n";
PSTR pszReadFailure     = "lpReadProcessMemoryRoutine failed!\n";

/***************************************************************************\
* Macros
\***************************************************************************/
#define move(dst, src)  moveBlock(dst, src, sizeof(dst))

#define moveBlock(dst, src, size)                                     \
try {                                                                 \
    if (lpExtensionApis->nSize >= sizeof(WINDBG_EXTENSION_APIS)) {    \
        if (!(*lpExtensionApis->lpReadProcessMemoryRoutine)(          \
             (DWORD) (src), &(dst), (size), NULL)) {                  \
            (*lpExtensionApis->lpOutputRoutine)(pszReadFailure);      \
            return FALSE;                                             \
         }                                                            \
    } else {                                                          \
        NtReadVirtualMemory(hCurrentProcess,                          \
             (LPVOID)(src), &(dst), (size), NULL);                    \
    }                                                                 \
} except (EXCEPTION_EXECUTE_HANDLER) {                                \
    (*lpExtensionApis->lpOutputRoutine)(pszMoveException);            \
    return FALSE;                                                     \
}

#define moveExpressionValue(dst, src)                                 \
try {                                                                 \
    DWORD dwGlobal = lpExtensionApis->lpGetExpressionRoutine(src);    \
    if (lpExtensionApis->nSize < sizeof(WINDBG_EXTENSION_APIS)) {     \
        move(dwGlobal, dwGlobal);                                     \
    }                                                                 \
    (DWORD)dst = dwGlobal;                                            \
} except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ?          \
            EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {  \
    (*lpExtensionApis->lpOutputRoutine)(pszAccessViolation, src);     \
    return FALSE;                                                     \
}

#define moveExpressionAddress(dst, src)                               \
try {                                                                 \
    if (lpExtensionApis->nSize >= sizeof(WINDBG_EXTENSION_APIS)) {    \
        (DWORD)dst = lpExtensionApis->lpGetExpressionRoutine("&"src); \
    } else {                                                          \
        (DWORD)dst = lpExtensionApis->lpGetExpressionRoutine(src);    \
    }                                                                 \
} except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ?          \
            EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {  \
    (*lpExtensionApis->lpOutputRoutine)(pszAccessViolation, src);     \
    return FALSE;                                                     \
}

BOOL DebugConvertToAnsi(
    HANDLE hCurrentProcess,
    PWINDBG_EXTENSION_APIS lpExtensionApis,
    LPWSTR psrc,
    LPSTR pdst)
{
    WCHAR awch[80];
    ULONG cchText;

    move(awch, psrc);

    cchText = wcslen(awch) + 1;
    if (cchText == 0) {
        strcpy(pdst, "<null>");
    } else {
        awch[sizeof(awch) / sizeof(WCHAR) - 1] = L'\0';
        RtlUnicodeToMultiByteN(pdst, cchText, NULL,
                awch, cchText * sizeof(WCHAR));
    }
}


/***************************************************************************\
* help - list help for debugger extensions in CONEXTS.
*
*
* 04-Feb-1994 IanJa     Created.
\***************************************************************************/

BOOL help(
    HANDLE hCurrentProcess,
    HANDLE hCurrentThread,
    DWORD dwCurrentPc,
    PWINDBG_EXTENSION_APIS lpExtensionApis,
    LPSTR lpArgumentString)
{
    PWINDBG_OUTPUT_ROUTINE Print;
    PWINDBG_GET_EXPRESSION EvalExpression;
    PWINDBG_GET_SYMBOL GetSymbol;

    UNREFERENCED_PARAMETER(hCurrentProcess);
    UNREFERENCED_PARAMETER(hCurrentThread);
    UNREFERENCED_PARAMETER(dwCurrentPc);

    Print = lpExtensionApis->lpOutputRoutine;
    EvalExpression = lpExtensionApis->lpGetExpressionRoutine;
    GetSymbol = lpExtensionApis->lpGetSymbolRoutine;

    while (*lpArgumentString == ' ')
        lpArgumentString++;

    if (*lpArgumentString == '\0') {
        Print("conexts help:\n\n");
        Print("!help [cmd]            - this list, or details about cmd\n");
        Print("!dc [v] [pconsole]     - Dump CONSOLE_INFORMATION struct\n");
        Print("!ds <pscreen>          - Dump SCREEN_INFORMATION struct\n");
        Print("!dt <pconsole>         - Dump screen buffer info\n");
        Print("!df                    - Dump font cache\n");
        Print("!di <p>                - Dump input buffer info\n");
        Print("!dir <p>               - Dump input record ???\n");
        Print("!dcpt [address]        - Dump CPTABLEINFO (default: GlyphCP)\n");
    } else {
        if (*lpArgumentString == '!')
            lpArgumentString++;
        if (strcmp(lpArgumentString, "df") == 0) {
            Print("!df         - dumps Faces and then the cache\n");

        } else if (strcmp(lpArgumentString, "dc") == 0) {
            Print("!dc            - dumps simple CONSOLE_INFORMATION struct for all consoles\n");
            Print("!dc v          - dumps verbose CONSOLE_INFORMATION struct for all consoles\n");
            Print("!dc address    - dumps simple CONSOLE_INFORMATION struct for console at address\n");
            Print("!dc v address  - dumps verbose CONSOLE_INFORMATION struct for all consoles\n");

        } else if (strcmp(lpArgumentString, "dt") == 0) {
            Print("!dt address - dumps text buffer info for Console at address\n");
            Print("!dt         - dumps text buffer info for all Consoles\n");

        } else if (strcmp(lpArgumentString, "di") == 0) {
            Print("!di address - dumps text buffer info (INPUT_INFORMATION)\n");
            Print("!di         - dumps text buffer info for all Consoles\n");

        } else if (strcmp(lpArgumentString, "ds") == 0) {
            Print("!ds address - dumps SCREEN_INFORMATION struct at address\n");

        }
    }

    return 0;
}

/***************************************************************************\
* dc - Dump Console - dump CONSOLE_INFORMATION struct
*
* dc address    - dumps simple info for console at address
*                 (takes handle too)
\***************************************************************************/

BOOL dc(
    HANDLE hCurrentProcess,
    HANDLE hCurrentThread,
    DWORD dwCurrentPc,
    PWINDBG_EXTENSION_APIS lpExtensionApis,
    LPSTR lpArgumentString)
{
    PNTSD_OUTPUT_ROUTINE Print;
    PNTSD_GET_EXPRESSION EvalExpression;
    PNTSD_GET_SYMBOL GetSymbol;

    char ach[120];
    char chVerbose;
    BOOL fPrintLine;
    ULONG i;
    ULONG NumberOfConsoleHandles;
    PCONSOLE_INFORMATION *ConsoleHandles;
    CONSOLE_INFORMATION Console;
    PCONSOLE_INFORMATION pConsole;

    Print = lpExtensionApis->lpOutputRoutine;
    EvalExpression = lpExtensionApis->lpGetExpressionRoutine;
    GetSymbol = lpExtensionApis->lpGetSymbolRoutine;


    /*
     * Skip white space
     */
    while (*lpArgumentString == ' ')
        lpArgumentString++;

    /*
     * Get arguments
     */
    chVerbose = ' ';
    if (*lpArgumentString == 'v') {
        chVerbose = 'v';
        lpArgumentString++;
    }

    /*
     * If no console is specified, loop through all of them
     */
    if (*lpArgumentString == 0) {
        moveExpressionValue(NumberOfConsoleHandles,
                            "winsrv!NumberOfConsoleHandles");
        moveExpressionValue(ConsoleHandles,
                            "winsrv!ConsoleHandles");
        fPrintLine = FALSE;
        for (i = 0; i < NumberOfConsoleHandles; i++) {
            move(pConsole, ConsoleHandles);
            if (pConsole != NULL) {
                if (fPrintLine)
                    Print("---\n");
                sprintf(ach, "%c %lx", chVerbose, pConsole);
                if (!dc(hCurrentProcess, hCurrentThread,
                                 dwCurrentPc, lpExtensionApis, ach)) {
                    return FALSE;
                }
                fPrintLine = TRUE;
            }
            ConsoleHandles++;
        }
        return TRUE;
    }

    pConsole = (PCONSOLE_INFORMATION)EvalExpression(lpArgumentString);
    move(Console, pConsole);

    Print("PCONSOLE @ 0x%lX\n", pConsole);
    DebugConvertToAnsi(hCurrentProcess,lpExtensionApis,Console.Title, ach);
    Print("\t Title                  %s\n"
          "\t pConsoleLock           0x%08lX\n"
          "\t RefCount               0x%08lX\n"
          "\t pInputBuffer           0x%08lX\n"
          "\t pCurrentScreenBuffer   0x%08lX\n"
          "\t pScreenBuffers         0x%08lX\n"
          "\t spWnd                  0x%08lX\n"
          "\t hDC                    0x%08lX\n"
          "\t LastAttributes         0x%04lX\n"
          "\t Flags                  0x%08lX\n"
          "\t FullScreenFlags        0x%04lX\n"
          "\t ConsoleHandle          0x%08lX\n"
          "\t CtrlFlags              0x%08lX\n",
          ach,
          &pConsole->ConsoleLock,
          Console.RefCount,
          &pConsole->InputBuffer,
          Console.CurrentScreenBuffer,
          Console.ScreenBuffers,
          Console.spWnd,
          Console.hDC,
          Console.LastAttributes,
          Console.Flags,
          Console.FullScreenFlags,
          Console.ConsoleHandle,
          Console.CtrlFlags
          );

    if (chVerbose == 'v') {
        Print("\t hMenu                  0x%08lX\n"
              "\t hHeirMenu              0x%08lX\n"
              "\t hSysPalette            0x%08lX\n"
              "\t WindowRect.L T R B     0x%08lX 0x%08lX 0x%08lX 0x%08lX\n"
              "\t ResizeFlags            0x%08lX\n"
              "\t pOutputQueue           0x%08lX\n"
              "\t InitEvents[]           0x%08lX 0x%08lX\n"
              "\t ClientThreadHandle     0x%08lX\n"
              "\t pProcessHandleList     0x%08lX\n"
              "\t pCommandHistoryList    0x%08lX\n"
              "\t pExeAliasList          0x%08lX\n",
              Console.hMenu,
              Console.hHeirMenu,
              Console.hSysPalette,
              Console.WindowRect.left,
              Console.WindowRect.top,
              Console.WindowRect.right,
              Console.WindowRect.bottom,
              Console.ResizeFlags,
              &pConsole->OutputQueue,
              Console.InitEvents[0],
              Console.InitEvents[1],
              Console.ClientThreadHandle,
              &pConsole->ProcessHandleList,
              &pConsole->CommandHistoryList,
              &pConsole->ExeAliasList
              );
        DebugConvertToAnsi(hCurrentProcess,
                           lpExtensionApis,
                           Console.OriginalTitle,
                           ach
                           );
        Print("\t NumCommandHistories    0x%04lX\n"
              "\t MaxCommandHistories    0x%04lX\n"
              "\t CommandHistorySize     0x%04lX\n"
              "\t OriginalTitleLength    0x%04lX\n"
              "\t TitleLength            0x%04lX\n"
              "\t OriginalTitle          %s\n"
              "\t dwHotKey               0x%08lX\n"
              "\t ghIcon                 0x%08lX\n"
              "\t cbIcon                 0x%08lX\n"
              "\t ReserveKeys            0x%02lX\n"
              "\t WaitQueue              0x%08lX\n",
              Console.NumCommandHistories,
              Console.MaxCommandHistories,
              Console.CommandHistorySize,
              Console.OriginalTitleLength,
              Console.TitleLength,
              ach,
              Console.dwHotKey,
              Console.ghIcon,
              Console.cbIcon,
              Console.ReserveKeys,
              Console.WaitQueue
              );
        Print("\t SelectionFlags         0x%08lX\n"
              "\t SelectionRect.L T R B  0x%04lX 0x%04lX 0x%04lX 0x%04lX\n"
              "\t SelectionAnchor.X Y    0x%04lX 0x%04lX\n"
              "\t TextCursorPosition.X Y 0x%04lX 0x%04lX\n"
              "\t TextCursorSize         0x%08lX\n"
              "\t TextCursorVisible      0x%02lX\n"
              "\t InsertMode             0x%02lX\n"
              "\t wShowWindow            0x%04lX\n"
              "\t dwWindowOriginX        0x%08lX\n"
              "\t dwWindowOriginY        0x%08lX\n"
              "\t PopupCount             0x%04lX\n",
              Console.SelectionFlags,
              Console.SelectionRect.Left,
              Console.SelectionRect.Top,
              Console.SelectionRect.Right,
              Console.SelectionRect.Bottom,
              Console.SelectionAnchor.X,
              Console.SelectionAnchor.Y,
              Console.TextCursorPosition.X,
              Console.TextCursorPosition.Y,
              Console.TextCursorSize,
              Console.TextCursorVisible,
              Console.InsertMode,
              Console.wShowWindow,
              Console.dwWindowOriginX,
              Console.dwWindowOriginY,
              Console.PopupCount
              );
        Print("\t VDMStartHardwareEvent  0x%08lX\n"
              "\t VDMEndHardwareEvent    0x%08lX\n"
              "\t VDMProcessHandle       0x%08lX\n"
              "\t VDMProcessId           0x%08lX\n"
              "\t VDMBufferSectionHandle 0x%08lX\n"
              "\t VDMBuffer              0x%08lX\n"
              "\t VDMBufferClient        0x%08lX\n"
              "\t VDMBufferSize.X Y      0x%04lX 0x%04lX\n"
              "\t StateSectionHandle     0x%08lX\n"
              "\t StateBuffer            0x%08lX\n"
              "\t StateBufferClient      0x%08lX\n"
              "\t StateLength            0x%08lX\n",
              Console.VDMStartHardwareEvent,
              Console.VDMEndHardwareEvent,
              Console.VDMProcessHandle,
              Console.VDMProcessId,
              Console.VDMBufferSectionHandle,
              Console.VDMBuffer,
              Console.VDMBufferClient,
              Console.VDMBufferSize.X,
              Console.VDMBufferSize.Y,
              Console.StateSectionHandle,
              Console.StateBuffer,
              Console.StateBufferClient,
              Console.StateLength
              );
        Print("\t CP                     0x%08lX\n"
              "\t OutputCP               0x%08lX\n"
              "\t hWndProgMan            0x%08lX\n"
              "\t bIconInit              0x%08lX\n"
              "\t ConsoleId              0x%08lX\n"
              "\t LimitingProcessId      0x%08lX\n"
              "\t TerminationEvent       0x%08lX\n"
              "\t VerticalClientToWin    0x%04lX\n"
              "\t HorizontalClientToWin  0x%04lX\n",
              Console.CP,
              Console.OutputCP,
              Console.hWndProgMan,
              Console.bIconInit,
              Console.ConsoleId,
              Console.LimitingProcessId,
              Console.TerminationEvent,
              Console.VerticalClientToWindow,
              Console.HorizontalClientToWindow
              );
    }
    return TRUE;
}

/***************************************************************************\
* dt - Dump Text - dump text buffer information
*
* dt address    - dumps text buffer information  for console at address
*
\***************************************************************************/

BOOL dt(
    HANDLE hCurrentProcess,
    HANDLE hCurrentThread,
    DWORD dwCurrentPc,
    PWINDBG_EXTENSION_APIS lpExtensionApis,
    LPSTR lpArgumentString)
{
    PNTSD_OUTPUT_ROUTINE Print;
    PNTSD_GET_EXPRESSION EvalExpression;
    PNTSD_GET_SYMBOL GetSymbol;

    char ach[120];
    BOOL fPrintLine;
    ULONG i;
    ULONG NumberOfConsoleHandles;
    PCONSOLE_INFORMATION *ConsoleHandles;
    CONSOLE_INFORMATION Console;
    SCREEN_INFORMATION Screen;
    PCONSOLE_INFORMATION pConsole;
    DWORD FrameBufPtr;

    Print = lpExtensionApis->lpOutputRoutine;
    EvalExpression = lpExtensionApis->lpGetExpressionRoutine;
    GetSymbol = lpExtensionApis->lpGetSymbolRoutine;


    /*
     * Skip with space
     */

    while (*lpArgumentString == ' ')
        lpArgumentString++;

    /*
     * If no console is specified, dt all of them
     */
    if (*lpArgumentString == 0) {
        moveExpressionValue(NumberOfConsoleHandles,
                            "winsrv!NumberOfConsoleHandles");
        moveExpressionValue(ConsoleHandles,
                            "winsrv!ConsoleHandles");
        fPrintLine = FALSE;
        for (i = 0; i < NumberOfConsoleHandles; i++) {
            move(pConsole, ConsoleHandles);
            if (pConsole != NULL) {
                if (fPrintLine)
                    Print("---\n");
                itoa((ULONG)pConsole, ach, 16);
                if (!dt(hCurrentProcess, hCurrentThread,
                                 dwCurrentPc, lpExtensionApis, ach)) {
                    return FALSE;
                }
                fPrintLine = TRUE;
            }
            ConsoleHandles++;
        }
        return TRUE;
    } else {
        pConsole = (PCONSOLE_INFORMATION)EvalExpression(lpArgumentString);
    }

    move(Console, pConsole);

    Print("PCONSOLE @ 0x%lX\n", pConsole);
    DebugConvertToAnsi(hCurrentProcess,lpExtensionApis,Console.Title, ach);
    Print("\t Title                %s\n"
          "\t pCurrentScreenBuffer 0x%08lX\n"
          "\t pScreenBuffers       0x%08lX\n"
          "\t VDMBuffer            0x%08lx\n"
          "\t CP %d,  OutputCP %d\n",
          ach,
          Console.CurrentScreenBuffer,
          Console.ScreenBuffers,
          Console.VDMBuffer,
          Console.CP,
          Console.OutputCP
          );

    moveExpressionValue(FrameBufPtr, "winsrv!FrameBufPtr");
    move(Screen, Console.CurrentScreenBuffer);
    if (Screen.Flags & CONSOLE_TEXTMODE_BUFFER) {
        Print("\t TextInfo.Rows         0x%08X\n"
              "\t TextInfo.TextRows     0x%08X\n"
              "\t TextInfo.FirstRow     0x%08X\n"
              "\t FrameBufPtr           0x%08X\n",
              Screen.BufferInfo.TextInfo.Rows,
              Screen.BufferInfo.TextInfo.TextRows,
              Screen.BufferInfo.TextInfo.FirstRow,
              FrameBufPtr);
    }

    return TRUE;
}

/***************************************************************************\
* df - Dump Font - dump Font information
*
* df address    - dumps simple info for console at address
*                 (takes handle too)
\***************************************************************************/

BOOL df(
    HANDLE hCurrentProcess,
    HANDLE hCurrentThread,
    DWORD dwCurrentPc,
    PWINDBG_EXTENSION_APIS lpExtensionApis,
    LPSTR lpArgumentString)
{
    PNTSD_OUTPUT_ROUTINE Print;
    PNTSD_GET_EXPRESSION EvalExpression;
    PNTSD_GET_SYMBOL GetSymbol;
    BYTE Buff[sizeof(FACENODE) + (LF_FACESIZE * sizeof(WCHAR))];
    PFACENODE pFN;

    DWORD NumberOfFonts;
    DWORD FontInfoLength;
    FONT_INFO FontInfo;
    PFONT_INFO pFontInfo;
    DWORD dw;

    Print = lpExtensionApis->lpOutputRoutine;
    EvalExpression = lpExtensionApis->lpGetExpressionRoutine;
    GetSymbol = lpExtensionApis->lpGetSymbolRoutine;


    /*
     * Skip space
     */

    while (*lpArgumentString == ' ')
        lpArgumentString++;


    Print("Faces:\n");
    moveExpressionValue(pFN, "winsrv!gpFaceNames");
    while (pFN != 0) {
        move(Buff, pFN);
        pFN = (PFACENODE)Buff;
        Print(" \"%ls\"\t%s %s %s %s %s %s\n",
              &pFN->awch[0],
              pFN->dwFlag & EF_NEW        ? "NEW"        : "   ",
              pFN->dwFlag & EF_OLD        ? "OLD"        : "   ",
              pFN->dwFlag & EF_ENUMERATED ? "ENUMERATED" : "          ",
              pFN->dwFlag & EF_OEMFONT    ? "OEMFONT"    : "       ",
              pFN->dwFlag & EF_TTFONT     ? "TTFONT"     : "      ",
              pFN->dwFlag & EF_DEFFACE    ? "DEFFACE"    : "       ");
        pFN = pFN->pNext;
    }

    moveExpressionValue(FontInfoLength, "winsrv!FontInfoLength");
    moveExpressionValue(NumberOfFonts, "winsrv!NumberOfFonts");
    moveExpressionValue(pFontInfo, "winsrv!FontInfo");

    Print("0x%lx fonts cached, 0x%lx allocated:\n", NumberOfFonts, FontInfoLength);

    for (dw = 0; dw < NumberOfFonts; dw++, pFontInfo++) {
        WCHAR FaceName[LF_FACESIZE];
        move(FontInfo, pFontInfo);
        move(FaceName, FontInfo.FaceName);
        Print("%04x hFont    0x%08lX \"%ls\"\n"
              "     SizeWant (%d;%d)\n"
              "     Size     (%d;%d)\n"
              "     Family   %02X\n"
              "     Weight   0x%08lX\n",
              dw,
              FontInfo.hFont,
              FaceName,
              FontInfo.SizeWant.X, FontInfo.SizeWant.Y,
              FontInfo.Size.X, FontInfo.Size.Y,
              FontInfo.Family,
              FontInfo.Weight);
    }

    return TRUE;
}

/***************************************************************************\
* di - Dump Input - dump input buffer
*
* di address    - dumps simple info for input at address
*
\***************************************************************************/

BOOL di(
    HANDLE hCurrentProcess,
    HANDLE hCurrentThread,
    DWORD dwCurrentPc,
    PWINDBG_EXTENSION_APIS lpExtensionApis,
    LPSTR lpArgumentString)
{
    PNTSD_OUTPUT_ROUTINE Print;
    PNTSD_GET_EXPRESSION EvalExpression;
    PNTSD_GET_SYMBOL GetSymbol;

    INPUT_INFORMATION Input;
    PINPUT_INFORMATION pInput;

    PCONSOLE_INFORMATION pConsole;
    ULONG NumberOfConsoleHandles;
    PCONSOLE_INFORMATION *ConsoleHandles;
    BOOL fPrintLine;
    ULONG i;
    char ach[120];

    Print = lpExtensionApis->lpOutputRoutine;
    EvalExpression = lpExtensionApis->lpGetExpressionRoutine;
    GetSymbol = lpExtensionApis->lpGetSymbolRoutine;


    /*
     * Skip with space
     */

    while (*lpArgumentString == ' ')
        lpArgumentString++;

    /*
     * If no INPUT_INFORMATION is specified, dt all of them
     */
    if (*lpArgumentString == 0) {
        moveExpressionValue(NumberOfConsoleHandles,
                            "winsrv!NumberOfConsoleHandles");
        moveExpressionValue(ConsoleHandles,
                            "winsrv!ConsoleHandles");
        fPrintLine = FALSE;
        for (i = 0; i < NumberOfConsoleHandles; i++) {
            move(pConsole, ConsoleHandles);
            if (pConsole != NULL) {
                if (fPrintLine)
                    Print("---\n");
                pInput = &pConsole->InputBuffer;
                itoa((ULONG)pInput, ach, 16);
                if (!di(hCurrentProcess, hCurrentThread,
                                 dwCurrentPc, lpExtensionApis, ach)) {
                    return FALSE;
                }
                fPrintLine = TRUE;
            }
            ConsoleHandles++;
        }
        return TRUE;
    } else {
        pInput = (PINPUT_INFORMATION)EvalExpression(lpArgumentString);
    }

    move(Input, pInput);

    Print("PINPUT @ 0x%lX\n", pInput);
    Print("\t pInputBuffer         0x%08lX\n"
          "\t InputBufferSize      0x%08lX\n"
          "\t AllocatedBufferSize  0x%08lX\n"
          "\t InputMode            0x%08lX\n"
          "\t RefCount             0x%08lX\n"
          "\t First                0x%08lX\n"
          "\t In                   0x%08lX\n"
          "\t Out                  0x%08lX\n"
          "\t Last                 0x%08lX\n"
          "\t ReadWaitQueue.Flink  0x%08lX\n"
          "\t ReadWaitQueue.Blink  0x%08lX\n"
          "\t InputWaitEvent       0x%08lX\n",
          Input.InputBuffer,
          Input.InputBufferSize,
          Input.AllocatedBufferSize,
          Input.InputMode,
          Input.RefCount,
          Input.First,
          Input.In,
          Input.Out,
          Input.Last,
          Input.ReadWaitQueue.Flink,
          Input.ReadWaitQueue.Blink,
          Input.InputWaitEvent
          );

    return TRUE;
}
/***************************************************************************\
* dir - Dump Input Record - dump input buffer
*
* dir address number    - dumps simple info for input at address
*
\***************************************************************************/

BOOL dir(
    HANDLE hCurrentProcess,
    HANDLE hCurrentThread,
    DWORD dwCurrentPc,
    PWINDBG_EXTENSION_APIS lpExtensionApis,
    LPSTR lpArgumentString)
{
    PNTSD_OUTPUT_ROUTINE Print;
    PNTSD_GET_EXPRESSION EvalExpression;
    PNTSD_GET_SYMBOL GetSymbol;

    INPUT_RECORD InputRecord;
    PINPUT_RECORD pInputRecord;

    char ach[80];
    int cch;
    LPSTR lpAddress;
    DWORD NumRecords,i;

    Print = lpExtensionApis->lpOutputRoutine;
    EvalExpression = lpExtensionApis->lpGetExpressionRoutine;
    GetSymbol = lpExtensionApis->lpGetSymbolRoutine;


    /*
     * Skip with space
     */

    while (*lpArgumentString == ' ')
        lpArgumentString++;

    lpAddress = lpArgumentString;
    while (*lpArgumentString != ' ' && *lpArgumentString != 0)
        lpArgumentString++;

    cch = lpArgumentString - lpAddress;
    if (cch > 79)
        cch = 79;

    strncpy(ach, lpAddress, cch);

    pInputRecord = (PINPUT_RECORD)EvalExpression(lpAddress);
    NumRecords = (DWORD)EvalExpression(lpArgumentString);

    Print("%x PINPUTRECORDs @ 0x%lX\n", NumRecords, pInputRecord);
    for (i=0;i<NumRecords;i++) {
        move(InputRecord, pInputRecord);

        switch (InputRecord.EventType) {
            case KEY_EVENT:
                Print("\t KEY_EVENT\n");
                if (InputRecord.Event.KeyEvent.bKeyDown)
                    Print("\t  KeyDown\n");
                else
                    Print("\t  KeyUp\n");
                Print("\t  wRepeatCount %d\n",
                      InputRecord.Event.KeyEvent.wRepeatCount);
                Print("\t  wVirtualKeyCode %x\n",
                      InputRecord.Event.KeyEvent.wVirtualKeyCode);
                Print("\t  wVirtualScanCode %x\n",
                      InputRecord.Event.KeyEvent.wVirtualScanCode);
                Print("\t  aChar is %c",
                      InputRecord.Event.KeyEvent.uChar.AsciiChar);
                Print("\n");
                Print("\t  uChar is %x\n",
                      InputRecord.Event.KeyEvent.uChar.UnicodeChar);
                Print("\t  dwControlKeyState %x\n",
                      InputRecord.Event.KeyEvent.dwControlKeyState);
                break;
            case MOUSE_EVENT:
                Print("\t MOUSE_EVENT\n"
                      "\t   dwMousePosition %x %x\n"
                      "\t   dwButtonState %x\n"
                      "\t   dwControlKeyState %x\n"
                      "\t   dwEventFlags %x\n",
                      InputRecord.Event.MouseEvent.dwMousePosition.X,
                      InputRecord.Event.MouseEvent.dwMousePosition.Y,
                      InputRecord.Event.MouseEvent.dwButtonState,
                      InputRecord.Event.MouseEvent.dwControlKeyState,
                      InputRecord.Event.MouseEvent.dwEventFlags
                     );

                break;
            case WINDOW_BUFFER_SIZE_EVENT:
                Print("\t WINDOW_BUFFER_SIZE_EVENT\n"
                      "\t   dwSize %x %x\n",
                      InputRecord.Event.WindowBufferSizeEvent.dwSize.X,
                      InputRecord.Event.WindowBufferSizeEvent.dwSize.Y
                     );
                break;
            case MENU_EVENT:
                Print("\t MENU_EVENT\n"
                      "\t   dwCommandId %x\n",
                      InputRecord.Event.MenuEvent.dwCommandId
                     );
                break;
            case FOCUS_EVENT:
                Print("\t FOCUS_EVENT\n");
                if (InputRecord.Event.FocusEvent.bSetFocus)
                    Print("\t bSetFocus is TRUE\n");
                else
                    Print("\t bSetFocus is FALSE\n");
                break;
            default:
                Print("\t Unknown event type %x\n",InputRecord.EventType);
                break;
        }
        pInputRecord++;
    }
    return TRUE;
}

/***************************************************************************\
* ds - Dump Screen - dump SCREEN_INFORMATION struct
*
* ds address    - dumps simple info for input at address
*
\***************************************************************************/

BOOL ds(
    HANDLE hCurrentProcess,
    HANDLE hCurrentThread,
    DWORD dwCurrentPc,
    PWINDBG_EXTENSION_APIS lpExtensionApis,
    LPSTR lpArgumentString)
{
    PNTSD_OUTPUT_ROUTINE Print;
    PNTSD_GET_EXPRESSION EvalExpression;
    PNTSD_GET_SYMBOL GetSymbol;

    SCREEN_INFORMATION Screen;
    PSCREEN_INFORMATION pScreen;

    Print = lpExtensionApis->lpOutputRoutine;
    EvalExpression = lpExtensionApis->lpGetExpressionRoutine;
    GetSymbol = lpExtensionApis->lpGetSymbolRoutine;


    /*
     * Skip with space
     */

    while (*lpArgumentString == ' ')
        lpArgumentString++;


    pScreen = (PSCREEN_INFORMATION)EvalExpression(lpArgumentString);
    move(Screen, pScreen);

    Print("PSCREEN @ 0x%lX\n", pScreen);
    Print("\t pConsole             0x%08lX\n"
          "\t Flags                0x%08lX %s | %s\n"
          "\t OutputMode           0x%08lX\n"
          "\t RefCount             0x%08lX\n"
          "\t ScreenBufferSize.X Y 0x%08X 0x%08X\n"
          "\t MaxWindowSize.X Y    0x%08X 0x%08X\n"
          "\t Window.L T R B       0x%08X 0x%08X 0x%08X 0x%08X\n"
          "\t MaxWindow.X Y        0x%08X 0x%08X\n"
          "\t ResizingWindow       0x%08X\n",
          Screen.Console,
          Screen.Flags,
          Screen.Flags & CONSOLE_TEXTMODE_BUFFER ? "TEXTMODE" : "GRAPHICS",
          Screen.Flags & CONSOLE_OEMFONT_DISPLAY ? "OEMFONT" : "TT FONT",
          Screen.OutputMode,
          Screen.RefCount,
          (DWORD)Screen.ScreenBufferSize.X,
          (DWORD)Screen.ScreenBufferSize.Y,
          (DWORD)Screen.MaximumWindowSize.X,
          (DWORD)Screen.MaximumWindowSize.Y,
          (DWORD)Screen.Window.Left,
          (DWORD)Screen.Window.Top,
          (DWORD)Screen.Window.Right,
          (DWORD)Screen.Window.Bottom,
          (DWORD)Screen.MaxWindow.X,
          (DWORD)Screen.MaxWindow.Y,
          Screen.ResizingWindow
          );
    Print("\t Attributes           0x%08X\n"
          "\t PopupAttributes      0x%08X\n"
          "\t MinX                 0x%08X\n"
          "\t WindowMaximizedX     0x%08X\n"
          "\t WindowMaximizedY     0x%08X\n"
          "\t WindowMaximized      0x%08X\n"
          "\t CommandIdLow High    0x%08X 0x%08X\n"
          "\t CursorHandle         0x%08X\n"
          "\t hPalette             0x%08X\n"
          "\t hBackground          0x%08X\n"
          "\t dwUsage              0x%08X\n"
          "\t CursorDisplayCount   0x%08X\n",
          Screen.Attributes,
          Screen.PopupAttributes,
          Screen.MinX,
          Screen.WindowMaximizedX,
          Screen.WindowMaximizedY,
          Screen.WindowMaximized,
          Screen.CommandIdLow,
          Screen.CommandIdHigh,
          Screen.CursorHandle,
          Screen.hPalette,
          Screen.hBackground,
          Screen.dwUsage,
          Screen.CursorDisplayCount
          );
    if (Screen.Flags & CONSOLE_TEXTMODE_BUFFER) {
        Print("\t TextInfo.Rows         0x%08X\n"
              "\t TextInfo.TextRows     0x%08X\n"
              "\t TextInfo.FirstRow     0x%08X\n"
              "\t TextInfo.FontSize       0x%04X,0x%04X\n"
              "\t TextInfo.FontNumber     0x%08X\n",
              Screen.BufferInfo.TextInfo.Rows,
              Screen.BufferInfo.TextInfo.TextRows,
              Screen.BufferInfo.TextInfo.FirstRow,

              Screen.BufferInfo.TextInfo.FontSize.X,
              Screen.BufferInfo.TextInfo.FontSize.Y,
              Screen.BufferInfo.TextInfo.FontNumber);

        Print("\t TextInfo.Family, Weight 0x%08X, 0x%08X\n"
              "\t TextInfo.FaceName       %ls\n",
              Screen.BufferInfo.TextInfo.Family,
              Screen.BufferInfo.TextInfo.Weight,
              Screen.BufferInfo.TextInfo.FaceName);

        Print("\t TextInfo.ModeIndex         0x%08X\n"
#ifdef i386
              "\t TextInfo.WindowedWindowSize.X Y 0x%08X 0x%08X\n"
              "\t TextInfo.WindowedScreenSize.X Y 0x%08X 0x%08X\n"
              "\t TextInfo.MousePosition.X Y 0x%08X 0x%08X\n"
#endif
              "\t TextInfo.Flags             0x%08X\n",

              Screen.BufferInfo.TextInfo.ModeIndex,
#ifdef i386
              Screen.BufferInfo.TextInfo.WindowedWindowSize.X,
              Screen.BufferInfo.TextInfo.WindowedWindowSize.Y,
              Screen.BufferInfo.TextInfo.WindowedScreenSize.X,
              Screen.BufferInfo.TextInfo.WindowedScreenSize.Y,
              Screen.BufferInfo.TextInfo.MousePosition.X,
              Screen.BufferInfo.TextInfo.MousePosition.Y,
#endif
              Screen.BufferInfo.TextInfo.Flags);

        Print("\t TextInfo.CursorVisible        0x%08X\n"
              "\t TextInfo.CursorOn             0x%08X\n"
              "\t TextInfo.DelayCursor          0x%08X\n"
              "\t TextInfo.CursorPosition.X Y   0x%08X 0x%08X\n"
              "\t TextInfo.CursorSize           0x%08X\n"
              "\t TextInfo.CursorYSize          0x%08X\n"
              "\t TextInfo.UpdatingScreen       0x%08X\n",
              Screen.BufferInfo.TextInfo.CursorVisible,
              Screen.BufferInfo.TextInfo.CursorOn,
              Screen.BufferInfo.TextInfo.DelayCursor,
              Screen.BufferInfo.TextInfo.CursorPosition.X,
              Screen.BufferInfo.TextInfo.CursorPosition.Y,
              Screen.BufferInfo.TextInfo.CursorSize,
              Screen.BufferInfo.TextInfo.CursorYSize,
              Screen.BufferInfo.TextInfo.UpdatingScreen);

    } else {
        Print("\t GraphicsInfo.BitMapInfoLength 0x%08X\n"
              "\t GraphicsInfo.lpBitMapInfo     0x%08X\n"
              "\t GraphicsInfo.BitMap           0x%08X\n"
              "\t GraphicsInfo.ClientBitMap     0x%08X\n"
              "\t GraphicsInfo.ClientProcess    0x%08X\n"
              "\t GraphicsInfo.hMutex           0x%08X\n"
              "\t GraphicsInfo.hSection         0x%08X\n"
              "\t GraphicsInfo.dwUsage          0x%08X\n",
              Screen.BufferInfo.GraphicsInfo.BitMapInfoLength,
              Screen.BufferInfo.GraphicsInfo.lpBitMapInfo,
              Screen.BufferInfo.GraphicsInfo.BitMap,
              Screen.BufferInfo.GraphicsInfo.ClientBitMap,
              Screen.BufferInfo.GraphicsInfo.ClientProcess,
              Screen.BufferInfo.GraphicsInfo.hMutex,
              Screen.BufferInfo.GraphicsInfo.hSection,
              Screen.BufferInfo.GraphicsInfo.dwUsage
        );
    }

    return TRUE;
}

/***************************************************************************\
* dcpt - Dump CPTABLEINFO
*
* dcpt address    - dumps CPTABLEINFO at address
* dcpt            - dumps CPTABLEINFO at GlyphCP
*
\***************************************************************************/

BOOL dcpt(
    HANDLE hCurrentProcess,
    HANDLE hCurrentThread,
    DWORD dwCurrentPc,
    PWINDBG_EXTENSION_APIS lpExtensionApis,
    LPSTR lpArgumentString)
{
    PNTSD_OUTPUT_ROUTINE Print;
    PNTSD_GET_EXPRESSION EvalExpression;
    PNTSD_GET_SYMBOL GetSymbol;

    PCPTABLEINFO pcpt;
    CPTABLEINFO cpt;

    Print = lpExtensionApis->lpOutputRoutine;
    EvalExpression = lpExtensionApis->lpGetExpressionRoutine;
    GetSymbol = lpExtensionApis->lpGetSymbolRoutine;


    /*
     * Skip with space
     */

    while (*lpArgumentString == ' ')
        lpArgumentString++;

    /*
     * If no console is specified, loop through all of them
     */
    if (*lpArgumentString == 0) {
        lpArgumentString = "winsrv!GlyphCP";
    }
    pcpt = (PCPTABLEINFO)EvalExpression(lpArgumentString);
    move(cpt, pcpt);

    Print("CPTABLEINFO @ 0x%lX\n", pcpt);

    Print("  CodePage = 0x%x (%d)\n"
          "  MaximumCharacterSize = %x\n"
          "  DefaultChar = %x\n",
          cpt.CodePage, cpt.CodePage,
          cpt.MaximumCharacterSize,
          cpt.DefaultChar);

    Print("  UniDefaultChar = 0x%04x\n"
          "  TransDefaultChar = %x\n"
          "  TransUniDefaultChar = 0x%04x\n"
          "  DBCSCodePage = 0x%x (%d)\n",
          cpt.UniDefaultChar,
          cpt.TransDefaultChar,
          cpt.TransUniDefaultChar,
          cpt.DBCSCodePage, cpt.DBCSCodePage);

    Print("  LeadByte[MAXIMUM_LEADBYTES] = %04x,%04x,%04x,...\n"
          "  MultiByteTable = %x\n"
          "  WideCharTable = %lx\n"
          "  DBCSRanges = %lx\n"
          "  DBCSOffsets = %lx\n",
          cpt.LeadByte[0], cpt.LeadByte[1], cpt.LeadByte[2],
          cpt.MultiByteTable,
          cpt.WideCharTable,
          cpt.DBCSRanges,
          cpt.DBCSOffsets);

    return TRUE;
}
