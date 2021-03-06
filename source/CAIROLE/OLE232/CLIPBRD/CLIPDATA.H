//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 2000 - 1993.
//
//  File:	clipdata.h
//
//  Contents: 	Declaration of the clipboard data object.
//
//  Classes:	CClipDataObject
//
//  Functions:
//
//  History:    dd-mmm-yy Author    Comment
// 		31-Mar-94 alexgo    author
//
//--------------------------------------------------------------------------

#ifndef _CLIPDATA_H
#define _CLIPDATA_H


typedef enum
{
	RESET_AND_FREE = 1,
	JUST_RESET = 2
} FreeResourcesFlags;

//+-------------------------------------------------------------------------
//
//  Class:	CClipDataObject
//
//  Purpose: 	clipboard data object
//
//  Interface: 	IDataObject
//
//  History:    dd-mmm-yy Author    Comment
//		04-Jun-94 alexgo    added OLE1 support
// 		31-Mar-94 alexgo    author
//
//  Notes:	See clipdata.cpp for a description of OLE1 support
//
//--------------------------------------------------------------------------

class CClipDataObject : public IDataObject, public CPrivAlloc
{
public:
	// IUnknown methods
	STDMETHOD(QueryInterface) (REFIID riid, LPVOID FAR* ppvObj);
	STDMETHOD_(ULONG,AddRef) (void);
	STDMETHOD_(ULONG,Release) (void);
	
	// IDataObject methods
	STDMETHOD(GetData) (LPFORMATETC pformatetcIn, LPSTGMEDIUM pmedium);
	STDMETHOD(GetDataHere) (LPFORMATETC pformatetc,
			LPSTGMEDIUM pmedium);
	STDMETHOD(QueryGetData) (LPFORMATETC pformatetc);
	STDMETHOD(GetCanonicalFormatEtc) (LPFORMATETC pformatetc,
			LPFORMATETC pformatetcOut);
	STDMETHOD(SetData) (LPFORMATETC pformatetc,
			STGMEDIUM FAR* pmedium, BOOL fRelease);
	STDMETHOD(EnumFormatEtc) (DWORD dwDirection,
			LPENUMFORMATETC FAR* ppenumFormatEtc);
	STDMETHOD(DAdvise) (FORMATETC FAR* pFormatetc, DWORD advf,
			IAdviseSink FAR* pAdvSink, DWORD FAR* pdwConnection);
	STDMETHOD(DUnadvise) (DWORD dwConnection);
	STDMETHOD(EnumDAdvise) (LPENUMSTATDATA FAR* ppenumAdvise);
	
	static HRESULT CClipDataObject::Create(IDataObject **ppDataObj,
				FORMATETC *prgFormats, DWORD cFormats);
private:

	CClipDataObject();		// constructor
	~CClipDataObject();		// destructor

        void GetDataObjectForClip();    // Get real data object for clipboard

	// the following methods and data items are used for OLE1
	// support
	void		FreeResources( FreeResourcesFlags fFlags );
	HRESULT 	GetAndTranslateOle1( UINT cf, LPOLESTR *ppszClass,
				LPOLESTR *ppszFile, LPOLESTR *ppszItem,
				LPSTR *ppszItemA );
	HRESULT		GetEmbeddedObjectFromOle1( STGMEDIUM *pmedium );
	HRESULT		GetEmbedSourceFromOle1( STGMEDIUM *pmedium );
	HRESULT		GetLinkSourceFromOle1( STGMEDIUM *pmedium );
	HRESULT		GetObjectDescriptorFromOle1( UINT cf,
				STGMEDIUM *pmedium );
	HRESULT		GetOle2FromOle1( UINT cf, STGMEDIUM *pmedium );
	HRESULT		OleGetClipboardData( UINT cf, HANDLE *pHandle );
	BOOL		OleIsClipboardFormatAvailable( UINT cf );

	HGLOBAL		m_hOle1;	// hGlobal to OLE2 data constructed
					// from OLE1 data
	IUnknown *	m_pUnkOle1;	// IUnknown to either a storage or
					// a stream of OLE1 data

	// end of OLE1 support

	ULONG 		m_refs; 	// reference count
	FORMATETC *	m_rgFormats;	// array of formatetcs (if available)
	DWORD		m_cFormats;	// count of the formats
        IDataObject *   m_pDataObject;  // Actual data object for data.
	BOOL		m_fTriedToGetDataObject;
					// indicates whether or not we've
					// tried to get the real IDataObject
					// from the clipboard source
					// (see GetDataObjectForClip)
};


//+-------------------------------------------------------------------------
//
//  Class: 	CClipEnumFormatEtc
//
//  Purpose:	Enumerator for the formats available on the clipboard
//
//  Interface: 	IEnumFORMATETC
//
//  History:    dd-mmm-yy Author    Comment
// 		05-Apr-94 alexgo    author
//
//  Notes:
//
//--------------------------------------------------------------------------

class CClipEnumFormatEtc :public IEnumFORMATETC, public CPrivAlloc
{
public:
	STDMETHOD(QueryInterface)(REFIID riid, LPLPVOID ppvObj);
	STDMETHOD_(ULONG,AddRef)(void);
	STDMETHOD_(ULONG,Release)(void);

	STDMETHOD(Next) (ULONG celt, FORMATETC *rgelt,
			ULONG *pceltFetched);
	STDMETHOD(Skip) (ULONG celt);
	STDMETHOD(Reset) (void);
	STDMETHOD(Clone) (IEnumFORMATETC **ppenum);

	static HRESULT Create(IEnumFORMATETC **ppIEnum, FORMATETC *prgFormats,
			DWORD cFormats);

private:
	CClipEnumFormatEtc();	// constructor
	~CClipEnumFormatEtc();	// destructor

	ULONG		m_refs;		// reference count
	ULONG		m_iCurrent;	// current clipboard format
	ULONG		m_cTotal;	// total number of formats
	FORMATETC *	m_rgFormats;	// array of available formats
};

#endif // !_CLIPDATA_H

