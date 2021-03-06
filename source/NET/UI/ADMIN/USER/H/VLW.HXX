/**********************************************************************/
/**			  Microsoft Windows NT  		     **/
/**		Copyright(c) Microsoft Corp., 2000		     **/
/**********************************************************************/

/*
    vlw.hxx

    Header file for the Valid Logon Workstations subdialog class

    VLW_DIALOG is the  Valid Logon Workstations subdialog class.
    This header file describes this class.
    The inheritance diagram is as follows:

	 ...
	  |
    DIALOG_WINDOW  PERFORMER
	       \    /
            BASEPROP_DLG
	    /		\
	SUBPROP_DLG   PROP_DLG
	   /		  \
    USER_SUBPROP_DLG    USERPROP_DLG
	  |
     VLW_DIALOG


    FILE HISTORY:
        o-SimoP 14-May-2000 Created
	o-SimoP 10-Oct-2000 modified to inherit from USER_SUBPROP_DLG
	o-SimoP 15-Oct-2000 Code Review changes, attended by JimH, JonN
			    TerryK and I
	JonN	18-Dec-2000 Logon Hours code review changes part 2
        JonN    09-Sep-2000 Added SLT array
*/

#ifndef _VLW_HXX_
#define _VLW_HXX_

#include <usubprop.hxx>

#define NUMBER_OF_SLE    8


/*************************************************************************

    NAME:	VLW_DIALOG

    SYNOPSIS:	VLW_DIALOG is the class for the User Accounts
		subdialog.

    INTERFACE:	VLW_DIALOG()	-	constructor

    		~VLW_DIALOG()	-	destructor


    PARENT:	USER_SUBPROP_DLG

    USES:	MAGIC_GROUP

    NOTES:	_fIndeterminateWksta: TRUE iff multiple users are selected
		who did not originally all have the same Wksta value.

    HISTORY:
        o-SimoP 14-May-2000 Created
        o-SimoP 03-Dec-2000 _sltCanLogOnFrom added
        JonN    02-Jul-2000 _sltCanLogOnFrom removed (use radio buttons)
**************************************************************************/
class VLW_DIALOG : public USER_SUBPROP_DLG
{
private:

    BOOL   	_fIndeterminateWksta;
    BOOL   	_fIndetNowWksta;
    NLS_STR  	_nlsWkstaNames;
    SLE_STRIP *	_psleFirstBadName;

    MAGIC_GROUP _mgrpMaster;
    SLE_STRIP *	_apsleArray[NUMBER_OF_SLE];
    SLT *	_apsltArray[NUMBER_OF_SLE];

    void FillFields( const TCHAR *pszWorkStations );
    APIERR CheckNames();
    APIERR RemoveDuplicates();

protected:
    virtual BOOL OnOK(void);

    /* inherited from BASEPROP_DLG */
    virtual APIERR InitControls();

    virtual BOOL ChangesUser2Ptr( UINT iObject );

    virtual ULONG QueryHelpContext( void );

    /* four next ones inherited from USER_SUBPROP_DLG */
    virtual APIERR W_LMOBJtoMembers( UINT iObject );

    virtual APIERR W_MembersToLMOBJ(
	USER_2 *	puser2,
	USER_MEMB *	pusermemb
	);

    virtual APIERR W_DialogToMembers();

public:
    VLW_DIALOG(  USERPROP_DLG * puserpropdlgParent,
    		 const LAZY_USER_LISTBOX * pulb );

    virtual ~VLW_DIALOG();

};   // class VLW_DIALOG

#endif // _VLW_HXX_
