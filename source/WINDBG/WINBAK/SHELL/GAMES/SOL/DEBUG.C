#include "sol.h"
#include <io.h>
#include <string.h>
#include "assert.h"
VSZASSERT

#ifdef DEBUG

MDBG rgmdbg[imdbgMax];
INT lvl = 0;
INT imdbgCur = 0;


VOID InitDebug()
        {
        INT imdbg;
        MDBG *pmdbg;

        for(imdbg = 0; imdbg < imdbgMax; imdbg++)
                {
                pmdbg = &rgmdbg[imdbg];
                pmdbg->pgmcol = NULL;
                pmdbg->lvl = 0;
                pmdbg->msg = 0xcccc;
                pmdbg->wp1 = 0xcccc;
                pmdbg->wp2 = 0xcccc;
                pmdbg->wResult = 0xcccc;
                }

        imdbgCur = 0;
        lvl = 0;
        }



WORD ILogMsg(VOID *pgmcol, INT msg, INT wp1, INT wp2, BOOL fGm)
        {
        MDBG *pmdbg;
        INT imdbgRet;

        Assert(FInRange(imdbgCur, 0, imdbgMax-1));
        pmdbg = &rgmdbg[imdbgCur];

        Assert(fGm == 0 || fGm == 1);
        pmdbg->pgmcol = pgmcol;
        pmdbg->msg = msg + (fGm << 15);
        pmdbg->wp1 = wp1;
        pmdbg->wp2 = wp2;
        pmdbg->wResult = 0xcccc;
        pmdbg->lvl = lvl;
        lvl++;
        imdbgRet = imdbgCur++;
        imdbgCur %= imdbgMax;
        Assert(FInRange(imdbgCur, 0, imdbgMax-1));
        return imdbgRet;
        }



VOID LogMsgResult(INT imdbg, INT wResult)
        {
        lvl--;

        Assert(FInRange(imdbg, 0, imdbgMax-1));
        rgmdbg[imdbg].wResult = wResult;
        }

VOID WriteCrlf(INT fh)
        {
        write(fh, "\x0d\n", 2);
        }


VOID WriteSz(INT fh, CHAR *sz)
        {
        write(fh, sz, strlen(sz));
        WriteCrlf(fh);
        }

VOID WriteIField(INT fh, CHAR *szField, INT ifld)
        {
        CHAR szBuf[128];
        INT cch;

        write(fh, szField, strlen(szField));
        write(fh, " = ", 3);
        cch = CchDecodeInt(szBuf, ifld);
        write(fh, szBuf, cch);
        WriteCrlf(fh);
        }




VOID DumpCol(INT fh, COL *pcol)
        {
        INT icrd;
        MOVE *pmove;

        WriteCrlf(fh);
        WriteIField(fh, ">>> *pcol", (INT) pcol);
        WriteIField(fh, "pcolcls->tcls", pcol->pcolcls->tcls);
        WriteIField(fh, "icrdMac", pcol->icrdMac);
        WriteIField(fh, "pmove", (INT) pcol->pmove);
        if(pcol->pmove != NULL)
                {
                pmove = pcol->pmove;
                WriteIField(fh, "pmove->icrdSel", pmove->icrdSel);
                WriteIField(fh, "pmove->ccrdSel", pmove->ccrdSel);
                WriteIField(fh, "pmove->delHit.x", pmove->delHit.dx);
                WriteIField(fh, "pmove->delHit.y", pmove->delHit.dy);
                WriteIField(fh, "pmove->fHdc", pmove->fHdc);
                WriteIField(fh, "pmove->dyCol", pmove->dyCol);
                WriteIField(fh, "pmove->hdcScreen", (INT)pmove->hdcScreen);

                WriteIField(fh, "pmove->hdcCol", (INT)pmove->hdcCol);
                WriteIField(fh, "pmove->hbmColOld", (INT)pmove->hbmColOld);

                WriteIField(fh, "pmove->hdcScreenSave", (INT)pmove->hdcScreenSave);
                WriteIField(fh, "pmove->hbmScreenSaveOld", (INT)pmove->hbmScreenSaveOld);

                WriteIField(fh, "pmove->hdcT", (INT)pmove->hdcT);
                WriteIField(fh, "pmove->hbmT", (INT)pmove->hbmT);
                }
        for(icrd = 0; icrd < pcol->icrdMac; icrd++)
                {
                WriteIField(fh, "\t-card ", icrd);
                WriteIField(fh, "\t    cd", pcol->rgcrd[icrd].cd);
                WriteIField(fh, "\t   fUp", pcol->rgcrd[icrd].fUp);
                WriteIField(fh, "\t  pt.x", pcol->rgcrd[icrd].pt.x);
                WriteIField(fh, "\t  pt.y", pcol->rgcrd[icrd].pt.y);
                }
        }


VOID DumpGm(INT fh, GM *pgm)
        {
        INT icol;

        WriteIField(fh, "pgm", (INT) pgm);
        WriteIField(fh, "udr.fAvail", pgm->udr.fAvail);
        WriteIField(fh, "udr.sco", pgm->udr.sco);
        WriteIField(fh, "udr.icol1", pgm->udr.icol1);
        WriteIField(fh, "udr.icol2", pgm->udr.icol2);
        WriteIField(fh, "udr.rgpcol[1]", (INT) pgm->udr.rgpcol[1]);
        WriteIField(fh, "udr.rgpcol[2]", (INT) pgm->udr.rgpcol[2]);
        WriteIField(fh, "fDealt", pgm->fDealt);
        WriteIField(fh, "fWon", pgm->fWon);
        WriteIField(fh, "fInput", pgm->fInput);
        WriteIField(fh, "sco", pgm->sco);
        WriteIField(fh, "iqsecScore", pgm->iqsecScore);
        WriteIField(fh, "dqsecScore", pgm->dqsecScore);
        WriteIField(fh, "ccrdDeal", pgm->ccrdDeal);
        WriteIField(fh, "irep", pgm->irep);
        WriteIField(fh, "ptMousePrev->x", pgm->ptMousePrev.x);
        WriteIField(fh, "ptMousePrev->y", pgm->ptMousePrev.y);
        WriteIField(fh, "fButtonDown", pgm->fButtonDown);
        WriteIField(fh, "icolKbd", pgm->icolKbd);
        WriteIField(fh, "icrdKbd", pgm->icrdKbd);
        WriteIField(fh, "icolSel", pgm->icolSel);
        WriteIField(fh, "icolHilight", pgm->icolHilight);
        WriteIField(fh, "icolMac", pgm->icolMac);
        WriteIField(fh, "icolMax", pgm->icolMax);
        for(icol = 0; icol < pgm->icolMac; icol++)
                DumpCol(fh, pgm->rgpcol[icol]);
        }

CHAR *PchDecodeWp(CHAR *pch, INT wp)
        {
        INT icol;
        extern GM *pgmCur;

        if(pgmCur == NULL)
                return pch;
        if(wp == (INT) pgmCur)
                return PszCopy("(pgmCur)", pch);

        for(icol = 0; icol < pgmCur->icolMac; icol++)
                {
                if(wp == (INT) pgmCur->rgpcol[icol])
                        {
                        pch = PszCopy("(col ", pch);
                        pch += CchDecodeInt(pch, icol);
                        *pch++ = ')';
                        break;
                        }
                }
        return pch;
        }


VOID DumpRgmdbg(CHAR *szFile, INT li)
        {
        OFSTRUCT of;
        INT fh;
        INT imdbg;
        INT lvl;
        MDBG *pmdbg;
        CHAR szBuf[128];
        CHAR *pch;
        extern GM *pgmCur;
        extern INT igmCur;


        if((fh = (OpenFile("sol.dbg", &of, OF_CREATE|OF_WRITE))) == -1)
                return;

        WriteSz(fh, "Assertion Failure");
        WriteIField(fh, szFile, li);
        WriteSz(fh, szVer);
        WriteIField(fh, "Game #", igmCur);
        WriteCrlf(fh);



        /* write game and col structs */
        if(pgmCur != NULL)
                DumpGm(fh, pgmCur);

        imdbg = imdbgCur;
        do
                {
                Assert(FInRange(imdbgCur, 0, imdbgMax-1));
                pmdbg = &rgmdbg[imdbg];
                Assert(pmdbg->lvl < 60);
                for(lvl = 0; lvl < pmdbg->lvl; lvl++)
                        write(fh, "\t", 1);
                pch = PchDecodeWp(szBuf, (INT) pmdbg->pgmcol);
                pmdbg->msg &= 0x7fff;
                *pch++ = ' ';
                pch += CchDecodeInt(pch, pmdbg->msg);
                *pch++ = ',';
                *pch++ = ' ';
                pch += CchDecodeInt(pch, pmdbg->wp1);
                pch = PchDecodeWp(pch, pmdbg->wp1);
                *pch++ = ',';
                *pch++ = ' ';
                pch += CchDecodeInt(pch, pmdbg->wp2);
                pch = PchDecodeWp(pch, pmdbg->wp2);
                *pch++ = ' ';
                *pch++ = '-';
                *pch++ = '>';
                *pch++ = ' ';
                pch += CchDecodeInt(pch, pmdbg->wResult);
                write(fh, szBuf, pch-szBuf);
                WriteCrlf(fh);

                imdbg--;
                if(imdbg < 0)
                        imdbg = imdbgMax-1;
                Assert(FInRange(imdbg, 0, imdbgMax-1));
                }       while(imdbg != imdbgCur);

        close(fh);
        }





/* Puts msg on bottom of screen.  Useful because I don't have a debug console now */
VOID DisplayMsg(CHAR *sz, INT msgc, INT wp1, INT wp2)
        {

        INT y;
        INT x;
        HDC hdc;
        INT cch;
        CHAR szInt[20];
        TEXTMETRIC tm;
        extern HWND hwndApp;
        extern BOOL fScreenShots;

        if(fScreenShots)
                return;

        x = 0;

        hdc = GetDC(hwndApp);
        GetTextMetrics(hdc, (LPTEXTMETRIC)&tm);
        y = 0;/*        dyScreen - tm.tmHeight; */

        TextOut(hdc, x, y, "                         ", 24);
        TextOut(hdc, x, y, sz, cch = CchSzLen(sz));
        x += (cch+1) * tm.tmMaxCharWidth;

        cch = CchDecodeInt(szInt, msgc);
        TextOut(hdc, x, y, szInt, cch);
        x += (cch+1) * tm.tmAveCharWidth;

        cch = CchDecodeInt(szInt, wp1);
        TextOut(hdc, x, y, szInt, cch);
        x += (cch+1) * tm.tmAveCharWidth;

        cch = CchDecodeInt(szInt, wp2);
        TextOut(hdc, x, y, szInt, cch);
        x += (cch+1) * tm.tmAveCharWidth;

        ReleaseDC(hwndApp, hdc);
        }

VOID PrintCardMacs(GM *pgm)
        {
        INT icol;
        CHAR sz[20];
        INT cch;
        HDC hdc;
        extern HWND hwndApp;

        hdc = GetDC(hwndApp);
        for(icol = 0; icol < pgm->icolMac; icol++)
                {
                cch = CchDecodeInt(sz, pgm->rgpcol[icol]->icrdMac);
                TextOut(hdc, 30 * icol, 10, sz, cch);
                }
        ReleaseDC(hwndApp, hdc);
        }



BOOL APIENTRY GameNo(HWND hdlg, INT iMessage, WPARAM wParam, LONG lParam)
        {
        BOOL fTranslated;
        INT igmNext;
        extern INT igmCur;

        if (iMessage == WM_COMMAND)
                {
                if( GET_WM_COMMAND_ID( wParam, lParam ) == IDOK )
                        {
                        igmNext = GetDlgItemInt(hdlg, ideGameNoEdit, &fTranslated, fFalse);
                        if(fTranslated && igmNext >= 0)
                                igmCur = igmNext;
                        else
                                {
                                Error("Invalid game number");
                                return fFalse;
                                }
                        }
                if(wParam == IDOK || wParam == IDCANCEL)
                        EndDialog(hdlg, wParam == IDOK);
                return fTrue;
                }
        else if (iMessage == WM_INITDIALOG)
                {
                SetDlgItemInt(hdlg, ideGameNoEdit, igmCur, fFalse);
                return fTrue;
                }
        else
                return fFalse;
        }



BOOL FSetGameNo()
        {
        BOOL fResult;
        FARPROC lpprocGameNo;
        extern HANDLE hinstApp;
        extern HWND hwndApp;
        extern INT igmCur;


        lpprocGameNo = MakeProcInstance( (FARPROC)GameNo, hinstApp);
        if(fResult = DialogBox(hinstApp,
                               MAKEINTRESOURCE(iddGameNo),
                               hwndApp,
                               (WNDPROC)lpprocGameNo))

                srand(igmCur);
        FreeProcInstance(lpprocGameNo);
        return fResult;
        }






BOOL FValidCol(COL *pcol)
        {
        INT icol;
        extern GM *pgmCur;

        if(pcol == NULL)
                return fFalse;

        for(icol = 0; icol < pgmCur->icolMax; icol++)
                {
                if(pcol == pgmCur->rgpcol[icol])
                        {
                        if(pcol->pcolcls == NULL)
                                return fFalse;
                        if(pcol->icrdMac > pcol->icrdMax)
                                return fFalse;

                        return fTrue;
                        }
                }
        return fFalse;
        }












/*      AssertFailed
 *
 *      Puts up assertion failure dialog.
 *
 *      Arguments:
 *              szFile -
 *              li -
 *
 *      Returns:
 *              nothing.
 */
#ifdef OLD
VOID AssertFailed(CHAR *szFile, INT li)
        {
        CHAR szOut[256];
        CHAR szTitle[74];
        CHAR *pch;
        BOOL f;
        CHAR *PszCopy();
        extern HWND hwndApp;
        extern CHAR szAppName[];

        pch = PszCopy("Assertion Failed:  File ", szTitle);
        pch = PszCopy(szFile, pch);
        pch = PszCopy(", line ", pch);
        pch += CchDecodeInt(pch, li);
        pch = PszCopy(", ", pch);
        pch = PszCopy(szVer, pch);


        pch = PszCopy("Please mail bug report to winbug, include file, line, version, and steps to reproduce", szOut);
        MessageBeep(MB_OKCANCEL|MB_ICONHAND|MB_SYSTEMMODAL);
        f = MessageBox(NULL, (LPSTR)szOut, (LPSTR)szTitle,
                        MB_OKCANCEL|MB_ICONHAND|MB_SYSTEMMODAL);

        DumpRgmdbg(szTitle);
        if(f != IDOK)
                +++ExitWindows - NO 32BIT FORM+++(0L);

        }
#endif

CHAR *vszFile;
INT vli;

CHAR vszLi[32];

BOOL APIENTRY AssertDlgProc(HANDLE hdlg, INT wm, INT wParam, LONG lParam)
        {
        extern INT igmCur;

        switch(wm)
                {
        case WM_INITDIALOG:
                SetWindowText(GetDlgItem(hdlg, FILE), vszFile);
                CchDecodeInt(vszLi, vli);
                SetWindowText(GetDlgItem(hdlg, LINE), vszLi);
                CchDecodeInt(vszLi, igmCur);
                SetWindowText(GetDlgItem(hdlg, GAMENO), vszLi);
/*              SetWindowText(GetDlgItem(hdlg, SOLVERSION), szVer); */
                break;
        case WM_COMMAND:
                switch( GET_WM_COMMAND_ID( wParam, lParam ))
                        {
                default:
                        return fFalse;
                case IDOK:
                        EndDialog(hdlg, 0);
                        break;
                case EXIT:
                        EndDialog(hdlg, 1);
                        break;
                        }
                break;

        default:
                return fFalse;
                }

        return fTrue;
        }


VOID AssertFailed(CHAR *szFile, INT li)
        {
        INT f;
        FARPROC lpprocAssert;
        extern HANDLE hinstApp;
        extern HWND hwndApp;

        vszFile = szFile;
        vli = li;

        lpprocAssert = MakeProcInstance((FARPROC) AssertDlgProc, hinstApp);
        f = DialogBox(hinstApp,
                      MAKEINTRESOURCE(ASSERTFAILED),
                      hwndApp,
                      (WNDPROC)lpprocAssert);

        FreeProcInstance(lpprocAssert);

        DumpRgmdbg(szFile, li);
//      if(f)
//               +++ExitWindows - NO 32BIT FORM+++();
        }

#endif
