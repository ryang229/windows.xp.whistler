/******************************Module*Header*******************************\
* Module Name: lfntobj.hxx
*
* The logical font user object and memory object.
*
* The logical font:
* ----------------
*
*   o  represents "wish list" of font attributes
*
*   o  a logical font may map to one or more realized fonts
*
*   o  multiple DCs may have the same logical font selected simultaneously
*
*   o  except for stock fonts, logical fonts are not shared between
*      processes
*
*   o  concerned with creation, deletion, selection, and realization:
*
*       o  logical fonts are created by calling CreateFont or
*          CreateFontIndirect at the API
*
*       o  logical fonts are selected into a DC by calling SelectObject at
*          the API
*
*       o  logical fonts are deleted by calling DeleteObject at the API
*
*       o  logical fonts are lazily mapped/realized (realization postponed to
*          the last possible moment)
*
*           o  text out time
*
*           o  querying the metrics of currently selected font
*
*           o  etc.
*
*   o  supports the following APIs:
*
*       o  CreateFont/CreateFontIndirect
*
*       o  DeleteObject
*
*
* Created: 25-Oct-1990 13:13:03
* Author: Gilman Wong [gilmanw]
*
* Copyright (c) 1990 Microsoft Corporation
\**************************************************************************/

#ifndef _LFNTOBJ_
#define _LFNTOBJ_

struct MAPCACHE
{
    HPDEV hpdev;
    EFLOAT      efM11;
    EFLOAT      efM12;
    EFLOAT      efM21;
    EFLOAT      efM22;
    HPFE        hpfe;
    FLONG       flSim;
    POINTL      ptlSim;
    FLONG       flAboutMatch;
};

#define MAXCACHEENTRIES 3

/**************************************************************************\
 * LFONT flags.
 *
 * Allowed properties of a LFONT:
 *
 *      Aliased -- an aliased LFONT is device specific.  An aliased LFONT
 *                 represents a SET OF LFONTs.  The specfic member of the set
 *                 represented in any given instance is dependent upon the
 *                 the device (i.e., varies with DC).
 *
 *      Stock -- a stock LFONT.
 *
 *      Undeletable -- flag is set for non-stock fonts which are undeletable
 *                     (like USERSRV cached fonts).
 *
 *
 * Aliased  Stock
 * -----------------
 *  0       0           user (app) defined LFONT
 *  0       1           stock font
 *  1       0           NOT ALLOWED
 *  1       1           aliased stock font
 *
\**************************************************************************/

#define LF_FLAG_ALIASED     0x00000001
#define LF_FLAG_STOCK       0x00000002

/*********************************Class************************************\
* class LFONT : public OBJECT
*
* Logical font object
*
*   lft             LFONT type.  An enumerated type.
*
*   fl              LFONT flags.
*
*   elfw            The attributes of this logical font.
*
*   cMapsInCache    Number of entries in the font mapping cache.
*
*   mapcache        Cache of font mappings.
*
* History:
*  25-Oct-1990 -by- Gilman Wong [gilmanw]
* Wrote it.
\**************************************************************************/

class LFONT : public OBJECT         /* lfnt */
{
public:

// state

    LFTYPE      lft;                // font type
    FLONG       fl;                 // flags

// data

    EXTLOGFONTW  elfw;              // logical font attributes

// Font mapping cache

    INT      cMapsInCache;
    MAPCACHE mapcache[MAXCACHEENTRIES];
    WCHAR    wcCapFacename[LF_FACESIZE];
};

typedef LFONT *PLFONT;
#define PLFNTNULL   ((PLFONT) NULL)

EFLOAT efCvtTenths(LONG l);

/**************************************************************************\
*  Allowed Bit fields for flAboutMatch, returned by                       *
*  LFONTOBJ::ppfeMapFont()                                                *
\**************************************************************************/

#define MAPFONT_FOUND_NAME       0x00000001      // facename matched
#define MAPFONT_ALTFACE_USED     0x00000002      // alternate facename matched

/*********************************Class************************************\
* class LFONTOBJ
*
* User object for logical fonts.
*
* History:
*  25-Oct-1990 -by- Gilman Wong [gilmanw]
* Wrote it.
\**************************************************************************/

class PFE;

class LFONTOBJ     /* lfo */
{
public:

    PLFONT      plfnt;  // pointer to logical font object

public:

// Constructors -- lock LFONT object.

    LFONTOBJ (HLFONT hlfnt, PDEVOBJ* ppdo = (PDEVOBJ *) NULL);
   ~LFONTOBJ ()
    {
        if (plfnt != PLFNTNULL)
        {
            DEC_SHARE_REF_CNT(plfnt);
        }
    }

    LBOOL   bValid ()                       { return(plfnt != PLFNTNULL); }
    HLFONT  hlfnt ()                        { return((HLFONT) plfnt->hGet()); }
    FLONG   fl()                            { return(plfnt->fl); }

// hrfntRealizeFont -- return HRFONT that matches the LFONT.

    PFE  *ppfeMapFont(XDCOBJ&, FLONG*, POINTL*, FLONG *);

// plfw -- return pointer to LOGFONTW structure.

    PLOGFONTW plfw()
    {
        return((LOGFONTW*) &(plfnt->elfw.elfLogFont));
    }

    EXTLOGFONTW* pelfw()
    {
        return(&(plfnt->elfw));
    }

// gets the escapement in tenths of degrees and converts the
// to the corresponding EFLOAT that our efSine and efCosine routines
// understand

    LONG lEscapement()
    {
        return (plfnt->elfw.elfLogFont.lfEscapement);
    }



#ifdef FONTLINK /*EUDC*/
// set the width of the logfont if it is non-zero and returns the old width
    LONG lWidth( LONG lWidth )
    {
        LONG lSave = plfnt->elfw.elfLogFont.lfWidth;
        if( lWidth )
        {
           plfnt->elfw.elfLogFont.lfWidth = lWidth;
        }
        return( lSave );
    }

// set the width of the logfont if it is non-zero and returns the old width
    LONG lHeight( LONG lHeight )
    {
        LONG lSave = plfnt->elfw.elfLogFont.lfHeight;
        if( lHeight )
        {
           plfnt->elfw.elfLogFont.lfHeight = lHeight;
        }
        return( lSave );
    }

// flSimulationFlags -- returns the text simulation flags

    FLONG flFontTypeFlags( BOOL bNonSimItalic, BOOL bSimItalic, USHORT usNonSimWeight )
    {
        LONG    lWish = plfnt->elfw.elfLogFont.lfWeight;
        LONG    lPen =  (LONG) usNonSimWeight - ( ( lWish ) ? ( lWish ) : FW_NORMAL );
        FLONG   fl = 0L;

        if ( !bNonSimItalic && plfnt->elfw.elfLogFont.lfItalic && bSimItalic )
            fl |= FO_SIM_ITALIC;
        if( lPen < 0 )
            fl |= FO_SIM_BOLD;

        return (fl);
    }


#endif


// flSimulationFlags -- returns the text simulation flags

    FLONG flSimulationFlags()
    {
        FLONG   fl = 0L;

        if (plfnt->elfw.elfLogFont.lfUnderline)
            fl |= TSIM_UNDERLINE1;
        if (plfnt->elfw.elfLogFont.lfStrikeOut)
            fl |= TSIM_STRIKEOUT;

        return (fl);
    }

 #if DBG
// vDump -- debugging info.

    VOID    vDump ();                           // LFNTOBJ.CXX
#endif
};

typedef LFONTOBJ *PLFONTOBJ;

BOOL bDeleteFont(HLFONT,BOOL);
BOOL bInitStockFonts(VOID);
extern "C" HFONT hfontCreate(LPEXTLOGFONTW pelfw,LFTYPE lft,FLONG fl);

#endif
