//+---------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 2000 - 1994.
//
//  File:	thopsint.cxx
//
//  Notes:	This file is automatically generated
//		Do not modify by hand
//
//  History:	Fri May 27 10:39:02 1994	Generated
//
//----------------------------------------------------------------------------

THOP thopsIClassFactory_CreateInstance[] =
{
    THOP_IFACE | THOP_IN, THI_IUnknown, THOP_COPY | THOP_IN, 16, THOP_IFACEGENOWNER | THOP_OUT, 4, 8, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIClassFactory_LockServer[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIMarshal_GetUnmarshalClass[] =
{
    THOP_COPY | THOP_IN, 16, THOP_IFACEGEN | THOP_IN, 4, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_COPY, 4, THOP_COPY | THOP_OUT, 16, THOP_END, THOP_ROUTINEINDEX, 4
};
THOP thopsIMarshal_GetMarshalSizeMax[] =
{
    THOP_COPY | THOP_IN, 16, THOP_IFACEGEN | THOP_IN, 4, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_COPY, 4, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 4
};
THOP thopsIMarshal_MarshalInterface[] =
{
    THOP_IFACE | THOP_IN, THI_IStream, THOP_COPY | THOP_IN, 16, THOP_IFACEGEN | THOP_IN, 4, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 4
};
THOP thopsIMarshal_UnmarshalInterface[] =
{
    THOP_IFACE | THOP_IN, THI_IStream, THOP_COPY | THOP_IN, 16, THOP_IFACEGEN | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIMarshal_ReleaseMarshalData[] =
{
    THOP_IFACE | THOP_IN, THI_IStream, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIMarshal_DisconnectObject[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIStdMarshalInfo_GetClassForHandler[] =
{
    THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_COPY | THOP_OUT, 16, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIMessageFilter_HandleInComingCall[] =
{
    THOP_RETURNTYPE, THOP_COPY, 4, THOP_COPY, 4, THOP_HTASK, THOP_COPY, 4, THOP_INTERFACEINFO | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIMessageFilter_RetryRejectedCall[] =
{
    THOP_RETURNTYPE, THOP_COPY, 4, THOP_HTASK, THOP_COPY, 4, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIMessageFilter_MessagePending[] =
{
    THOP_RETURNTYPE, THOP_COPY, 4, THOP_HTASK, THOP_COPY, 4, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIExternalConnection_AddConnection[] =
{
    THOP_RETURNTYPE, THOP_COPY, 4, THOP_COPY, 4, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIExternalConnection_ReleaseConnection[] =
{
    THOP_RETURNTYPE, THOP_COPY, 4, THOP_COPY, 4, THOP_COPY, 4, THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIEnumString_Next[] =
{
    THOP_ENUM, THE_IEnumString, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIEnumString_Skip[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumString_Reset[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIEnumString_Clone[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumString, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumUnknown_Next[] =
{
    THOP_ENUM, THE_IEnumUnknown, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIEnumUnknown_Skip[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumUnknown_Reset[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIEnumUnknown_Clone[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumUnknown, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumSTATSTG_Next[] =
{
    THOP_ENUM, THE_IEnumSTATSTG, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIEnumSTATSTG_Skip[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumSTATSTG_Reset[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIEnumSTATSTG_Clone[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumSTATSTG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsILockBytes_ReadAt[] =
{
    THOP_COPY, 8, THOP_BUFFER | THOP_OUT, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 9
};
THOP thopsILockBytes_WriteAt[] =
{
    THOP_COPY, 8, THOP_BUFFER | THOP_IN, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 9
};
THOP thopsILockBytes_Flush[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsILockBytes_SetSize[] =
{
    THOP_COPY, 8, THOP_END, THOP_ROUTINEINDEX, 10
};
THOP thopsILockBytes_LockRegion[] =
{
    THOP_COPY, 8, THOP_COPY, 8, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 11
};
THOP thopsILockBytes_UnlockRegion[] =
{
    THOP_COPY, 8, THOP_COPY, 8, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 11
};
THOP thopsILockBytes_Stat[] =
{
    THOP_STATSTG | THOP_OUT, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIStream_Read[] =
{
    THOP_BUFFER | THOP_OUT, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIStream_Write[] =
{
    THOP_BUFFER | THOP_IN, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIStream_Seek[] =
{
    THOP_COPY, 8, THOP_COPY, 4, THOP_COPY | THOP_OUT, 8, THOP_END, THOP_ROUTINEINDEX, 12
};
THOP thopsIStream_SetSize[] =
{
    THOP_COPY, 8, THOP_END, THOP_ROUTINEINDEX, 10
};
THOP thopsIStream_CopyTo[] =
{
    THOP_IFACE | THOP_IN, THI_IStream, THOP_COPY, 8, THOP_COPY | THOP_OUT, 8, THOP_COPY | THOP_OUT, 8, THOP_END, THOP_ROUTINEINDEX, 13
};
THOP thopsIStream_Commit[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIStream_Revert[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIStream_LockRegion[] =
{
    THOP_COPY, 8, THOP_COPY, 8, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 11
};
THOP thopsIStream_UnlockRegion[] =
{
    THOP_COPY, 8, THOP_COPY, 8, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 11
};
THOP thopsIStream_Stat[] =
{
    THOP_STATSTG | THOP_OUT, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIStream_Clone[] =
{
    THOP_IFACE | THOP_OUT, THI_IStream, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIStorage_CreateStream[] =
{
    THOP_LPSTR | THOP_IN, THOP_COPY, 4, THOP_COPY, 4, THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IStream, THOP_END, THOP_ROUTINEINDEX, 7
};
THOP thopsIStorage_OpenStream[] =
{
    THOP_LPSTR | THOP_IN, THOP_NULL | THOP_IN, THOP_COPY, 4, THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IStream, THOP_END, THOP_ROUTINEINDEX, 7
};
THOP thopsIStorage_CreateStorage[] =
{
    THOP_LPSTR | THOP_IN, THOP_COPY, 4, THOP_COPY, 4, THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IStorage, THOP_END, THOP_ROUTINEINDEX, 7
};
THOP thopsIStorage_OpenStorage[] =
{
    THOP_LPSTR | THOP_IN, THOP_IFACE | THOP_IN, THI_IStorage, THOP_COPY, 4, THOP_SNB, THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IStorage, THOP_END, THOP_ROUTINEINDEX, 4
};
THOP thopsIStorage_CopyTo[] =
{
    THOP_CRGIID, THOP_SNB, THOP_IFACE | THOP_IN, THI_IStorage, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIStorage_MoveElementTo[] =
{
    THOP_LPSTR | THOP_IN, THOP_IFACE | THOP_IN, THI_IStorage, THOP_LPSTR | THOP_IN, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIStorage_Commit[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIStorage_Revert[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIStorage_EnumElements[] =
{
    THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IEnumSTATSTG, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIStorage_DestroyElement[] =
{
    THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIStorage_RenameElement[] =
{
    THOP_LPSTR | THOP_IN, THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIStorage_SetElementTimes[] =
{
    THOP_LPSTR | THOP_IN, THOP_COPY | THOP_IN, 8, THOP_COPY | THOP_IN, 8, THOP_COPY | THOP_IN, 8, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIStorage_SetClass[] =
{
    THOP_COPY | THOP_IN, 16, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIStorage_SetStateBits[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIStorage_Stat[] =
{
    THOP_STATSTG | THOP_OUT, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIRootStorage_SwitchToFile[] =
{
    THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumFORMATETC_Next[] =
{
    THOP_ENUM, THE_IEnumFORMATETC, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIEnumFORMATETC_Skip[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumFORMATETC_Reset[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIEnumFORMATETC_Clone[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumFORMATETC, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumSTATDATA_Next[] =
{
    THOP_ENUM, THE_IEnumSTATDATA, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIEnumSTATDATA_Skip[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumSTATDATA_Reset[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIEnumSTATDATA_Clone[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumSTATDATA, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIDataObject_GetData[] =
{
    THOP_FORMATETC | THOP_IN, THOP_STGMEDIUM | THOP_OUT, 0, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIDataObject_GetDataHere[] =
{
    THOP_FORMATETC | THOP_IN, THOP_STGMEDIUM | THOP_IN, 0, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIDataObject_QueryGetData[] =
{
    THOP_FORMATETC | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIDataObject_GetCanonicalFormatEtc[] =
{
    THOP_FORMATETC | THOP_IN, THOP_FORMATETC | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIDataObject_SetData[] =
{
    THOP_FORMATETC | THOP_IN, THOP_STGMEDIUM | THOP_IN, 1, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIDataObject_EnumFormatEtc[] =
{
    THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IEnumFORMATETC, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIDataObject_DAdvise[] =
{
    THOP_FORMATETC | THOP_IN, THOP_COPY, 4, THOP_IFACE | THOP_IN, THI_IAdviseSink, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIDataObject_DUnadvise[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIDataObject_EnumDAdvise[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumSTATDATA, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIViewObject_Draw[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_DVTARGETDEVICE | THOP_IN, THOP_HGDI, THOP_HGDI, THOP_COPY | THOP_IN, 16, THOP_COPY | THOP_IN, 16, THOP_CALLBACK, THOP_END, THOP_ROUTINEINDEX, 14
};
THOP thopsIViewObject_GetColorSet[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_DVTARGETDEVICE | THOP_IN, THOP_HGDI, THOP_LOGPALETTE | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 4
};
THOP thopsIViewObject_Freeze[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIViewObject_Unfreeze[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIViewObject_SetAdvise[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_IFACE | THOP_IN, THI_IAdviseSink, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIViewObject_GetAdvise[] =
{
    THOP_COPY | THOP_OUT, 4, THOP_COPY | THOP_OUT, 4, THOP_IFACE | THOP_OUT, THI_IAdviseSink, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIViewObject2_Draw[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_DVTARGETDEVICE | THOP_IN, THOP_HGDI, THOP_HGDI, THOP_COPY | THOP_IN, 16, THOP_COPY | THOP_IN, 16, THOP_CALLBACK, THOP_END, THOP_ROUTINEINDEX, 14
};
THOP thopsIViewObject2_GetColorSet[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_DVTARGETDEVICE | THOP_IN, THOP_HGDI, THOP_LOGPALETTE | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 4
};
THOP thopsIViewObject2_Freeze[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIViewObject2_Unfreeze[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIViewObject2_SetAdvise[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_IFACE | THOP_IN, THI_IAdviseSink, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIViewObject2_GetAdvise[] =
{
    THOP_COPY | THOP_OUT, 4, THOP_COPY | THOP_OUT, 4, THOP_IFACE | THOP_OUT, THI_IAdviseSink, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIViewObject2_GetExtent[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_DVTARGETDEVICE | THOP_IN, THOP_COPY | THOP_OUT, 8, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIAdviseSink_OnDataChange[] =
{
    THOP_FORMATETC | THOP_IN, THOP_STGMEDIUM | THOP_IN, 0, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIAdviseSink_OnViewChange[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIAdviseSink_OnRename[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIAdviseSink_OnSave[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIAdviseSink_OnClose[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIAdviseSink2_OnDataChange[] =
{
    THOP_FORMATETC | THOP_IN, THOP_STGMEDIUM | THOP_IN, 0, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIAdviseSink2_OnViewChange[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIAdviseSink2_OnRename[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIAdviseSink2_OnSave[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIAdviseSink2_OnClose[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIAdviseSink2_OnLinkSrcChange[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIDataAdviseHolder_Advise[] =
{
    THOP_IFACE | THOP_IN, THI_IDataObject, THOP_FORMATETC | THOP_IN, THOP_COPY, 4, THOP_IFACE | THOP_IN, THI_IAdviseSink, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 7
};
THOP thopsIDataAdviseHolder_Unadvise[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIDataAdviseHolder_EnumAdvise[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumSTATDATA, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIDataAdviseHolder_SendOnDataChange[] =
{
    THOP_IFACE | THOP_IN, THI_IDataObject, THOP_COPY, 4, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleCache_Cache[] =
{
    THOP_FORMATETC | THOP_IN, THOP_COPY, 4, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleCache_Uncache[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleCache_EnumCache[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumSTATDATA, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleCache_InitCache[] =
{
    THOP_IFACE | THOP_IN, THI_IDataObject, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleCache_SetData[] =
{
    THOP_FORMATETC | THOP_IN, THOP_STGMEDIUM | THOP_IN, 1, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleCache2_Cache[] =
{
    THOP_FORMATETC | THOP_IN, THOP_COPY, 4, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleCache2_Uncache[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleCache2_EnumCache[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumSTATDATA, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleCache2_InitCache[] =
{
    THOP_IFACE | THOP_IN, THI_IDataObject, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleCache2_SetData[] =
{
    THOP_FORMATETC | THOP_IN, THOP_STGMEDIUM | THOP_IN, 1, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleCache2_UpdateCache[] =
{
    THOP_IFACE | THOP_IN, THI_IDataObject, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleCache2_DiscardCache[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleCacheControl_OnRun[] =
{
    THOP_IFACE | THOP_IN, THI_IDataObject, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleCacheControl_OnStop[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIDropTarget_DragEnter[] =
{
    THOP_IFACE | THOP_IN, THI_IDataObject, THOP_COPY, 4, THOP_COPY, 8, THOP_COPY | THOP_INOUT, 4, THOP_END, THOP_ROUTINEINDEX, 15
};
THOP thopsIDropTarget_DragOver[] =
{
    THOP_COPY, 4, THOP_COPY, 8, THOP_COPY | THOP_INOUT, 4, THOP_END, THOP_ROUTINEINDEX, 16
};
THOP thopsIDropTarget_DragLeave[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIDropTarget_Drop[] =
{
    THOP_IFACE | THOP_IN, THI_IDataObject, THOP_COPY, 4, THOP_COPY, 8, THOP_COPY | THOP_INOUT, 4, THOP_END, THOP_ROUTINEINDEX, 15
};
THOP thopsIDropSource_QueryContinueDrag[] =
{
    THOP_SHORTLONG, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIDropSource_GiveFeedback[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersist_GetClassID[] =
{
    THOP_COPY | THOP_OUT, 16, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersistStorage_GetClassID[] =
{
    THOP_COPY | THOP_OUT, 16, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersistStorage_IsDirty[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIPersistStorage_InitNew[] =
{
    THOP_IFACE | THOP_IN, THI_IStorage, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersistStorage_Load[] =
{
    THOP_IFACE | THOP_IN, THI_IStorage, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersistStorage_Save[] =
{
    THOP_IFACE | THOP_IN, THI_IStorage, THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIPersistStorage_SaveCompleted[] =
{
    THOP_IFACE | THOP_IN, THI_IStorage, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersistStorage_HandsOffStorage[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIPersistStream_GetClassID[] =
{
    THOP_COPY | THOP_OUT, 16, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersistStream_IsDirty[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIPersistStream_Load[] =
{
    THOP_IFACE | THOP_IN, THI_IStream, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersistStream_Save[] =
{
    THOP_IFACE | THOP_IN, THI_IStream, THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIPersistStream_GetSizeMax[] =
{
    THOP_COPY | THOP_OUT, 8, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersistFile_GetClassID[] =
{
    THOP_COPY | THOP_OUT, 16, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersistFile_IsDirty[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIPersistFile_Load[] =
{
    THOP_LPSTR | THOP_IN, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIPersistFile_Save[] =
{
    THOP_LPSTR | THOP_IN, THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIPersistFile_SaveCompleted[] =
{
    THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPersistFile_GetCurFile[] =
{
    THOP_LPLPSTR, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIBindCtx_RegisterObjectBound[] =
{
    THOP_IFACE | THOP_IN, THI_IUnknown, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIBindCtx_RevokeObjectBound[] =
{
    THOP_IFACE | THOP_IN, THI_IUnknown, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIBindCtx_ReleaseBoundObjects[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIBindCtx_SetBindOptions[] =
{
    THOP_BINDOPTS | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIBindCtx_GetBindOptions[] =
{
    THOP_BINDOPTS | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIBindCtx_GetRunningObjectTable[] =
{
    THOP_IFACE | THOP_OUT, THI_IRunningObjectTable, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIBindCtx_RegisterObjectParam[] =
{
    THOP_LPSTR | THOP_IN, THOP_IFACE | THOP_IN, THI_IUnknown, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIBindCtx_GetObjectParam[] =
{
    THOP_LPSTR | THOP_IN, THOP_IFACE | THOP_OUT, THI_IUnknown, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIBindCtx_EnumObjectParam[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumString, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIBindCtx_RevokeObjectParam[] =
{
    THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIMoniker_GetClassID[] =
{
    THOP_COPY | THOP_OUT, 16, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIMoniker_IsDirty[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIMoniker_Load[] =
{
    THOP_IFACE | THOP_IN, THI_IStream, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIMoniker_Save[] =
{
    THOP_IFACE | THOP_IN, THI_IStream, THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIMoniker_GetSizeMax[] =
{
    THOP_COPY | THOP_OUT, 8, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIMoniker_BindToObject[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_IFACE | THOP_IN, THI_IMoniker, THOP_COPY | THOP_IN, 16, THOP_IFACEGEN | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIMoniker_BindToStorage[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_IFACE | THOP_IN, THI_IMoniker, THOP_COPY | THOP_IN, 16, THOP_IFACEGEN | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIMoniker_Reduce[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_COPY, 4, THOP_IFACE | THOP_INOUT, THI_IMoniker, THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIMoniker_ComposeWith[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_SHORTLONG, THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIMoniker_Enum[] =
{
    THOP_SHORTLONG, THOP_IFACE | THOP_OUT, THI_IEnumMoniker, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIMoniker_IsEqual[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIMoniker_Hash[] =
{
    THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIMoniker_IsRunning[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_IFACE | THOP_IN, THI_IMoniker, THOP_IFACE | THOP_IN, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIMoniker_GetTimeOfLastChange[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_IFACE | THOP_IN, THI_IMoniker, THOP_COPY | THOP_OUT, 8, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIMoniker_Inverse[] =
{
    THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIMoniker_CommonPrefixWith[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIMoniker_RelativePathTo[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIMoniker_GetDisplayName[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_IFACE | THOP_IN, THI_IMoniker, THOP_LPLPSTR, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIMoniker_ParseDisplayName[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_IFACE | THOP_IN, THI_IMoniker, THOP_LPSTR | THOP_IN, THOP_COPY | THOP_OUT, 4, THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 7
};
THOP thopsIMoniker_IsSystemMoniker[] =
{
    THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRunningObjectTable_Register[] =
{
    THOP_COPY, 4, THOP_IFACE | THOP_IN, THI_IUnknown, THOP_IFACE | THOP_IN, THI_IMoniker, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIRunningObjectTable_Revoke[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRunningObjectTable_IsRunning[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRunningObjectTable_GetObject[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_IFACE | THOP_OUT, THI_IUnknown, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIRunningObjectTable_NoteChangeTime[] =
{
    THOP_COPY, 4, THOP_COPY | THOP_IN, 8, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIRunningObjectTable_GetTimeOfLastChange[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_COPY | THOP_OUT, 8, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIRunningObjectTable_EnumRunning[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumMoniker, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumMoniker_Next[] =
{
    THOP_ENUM, THE_IEnumMoniker, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIEnumMoniker_Skip[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumMoniker_Reset[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIEnumMoniker_Clone[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumMoniker, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumOLEVERB_Next[] =
{
    THOP_ENUM, THE_IEnumOLEVERB, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIEnumOLEVERB_Skip[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIEnumOLEVERB_Reset[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIEnumOLEVERB_Clone[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumOLEVERB, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleObject_SetClientSite[] =
{
    THOP_IFACE | THOP_IN, THI_IOleClientSite, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleObject_GetClientSite[] =
{
    THOP_IFACE | THOP_OUT, THI_IOleClientSite, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleObject_SetHostNames[] =
{
    THOP_LPSTR | THOP_IN, THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleObject_Close[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleObject_SetMoniker[] =
{
    THOP_COPY, 4, THOP_IFACE | THOP_IN, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleObject_GetMoniker[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleObject_InitFromData[] =
{
    THOP_IFACE | THOP_IN, THI_IDataObject, THOP_SHORTLONG, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleObject_GetClipboardData[] =
{
    THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IDataObject, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleObject_DoVerb[] =
{
    THOP_COPY, 4, THOP_MSG | THOP_IN, THOP_IFACE | THOP_IN, THI_IOleClientSite, THOP_COPY, 4, THOP_HUSER, THOP_RECT | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 4
};
THOP thopsIOleObject_EnumVerbs[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumOLEVERB, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleObject_Update[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleObject_IsUpToDate[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleObject_GetUserClassID[] =
{
    THOP_COPY | THOP_OUT, 16, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleObject_GetUserType[] =
{
    THOP_COPY, 4, THOP_LPLPSTR, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleObject_SetExtent[] =
{
    THOP_COPY, 4, THOP_COPY | THOP_IN, 8, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleObject_GetExtent[] =
{
    THOP_COPY, 4, THOP_COPY | THOP_OUT, 8, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleObject_Advise[] =
{
    THOP_IFACE | THOP_IN, THI_IAdviseSink, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleObject_Unadvise[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleObject_EnumAdvise[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumSTATDATA, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleObject_GetMiscStatus[] =
{
    THOP_COPY, 4, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleObject_SetColorScheme[] =
{
    THOP_LOGPALETTE | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleClientSite_SaveObject[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleClientSite_GetMoniker[] =
{
    THOP_COPY, 4, THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleClientSite_GetContainer[] =
{
    THOP_IFACE | THOP_OUT, THI_IOleContainer, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleClientSite_ShowObject[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleClientSite_OnShowWindow[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleClientSite_RequestNewObjectLayout[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIRunnableObject_GetRunningClass[] =
{
    THOP_COPY | THOP_OUT, 16, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRunnableObject_Run[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRunnableObject_IsRunning[] =
{
    THOP_RETURNTYPE, THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIRunnableObject_LockRunning[] =
{
    THOP_SHORTLONG, THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIRunnableObject_SetContainedObject[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIParseDisplayName_ParseDisplayName[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_LPSTR | THOP_IN, THOP_COPY | THOP_OUT, 4, THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIOleContainer_ParseDisplayName[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_LPSTR | THOP_IN, THOP_COPY | THOP_OUT, 4, THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIOleContainer_EnumObjects[] =
{
    THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IEnumUnknown, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleContainer_LockContainer[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleItemContainer_ParseDisplayName[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_LPSTR | THOP_IN, THOP_COPY | THOP_OUT, 4, THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIOleItemContainer_EnumObjects[] =
{
    THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IEnumUnknown, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleItemContainer_LockContainer[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleItemContainer_GetObject[] =
{
    THOP_LPSTR | THOP_IN, THOP_COPY, 4, THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_COPY | THOP_IN, 16, THOP_IFACEGEN | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 7
};
THOP thopsIOleItemContainer_GetObjectStorage[] =
{
    THOP_LPSTR | THOP_IN, THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_COPY | THOP_IN, 16, THOP_IFACEGEN | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIOleItemContainer_IsRunning[] =
{
    THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleAdviseHolder_Advise[] =
{
    THOP_IFACE | THOP_IN, THI_IAdviseSink, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleAdviseHolder_Unadvise[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleAdviseHolder_EnumAdvise[] =
{
    THOP_IFACE | THOP_OUT, THI_IEnumSTATDATA, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleAdviseHolder_SendOnRename[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleAdviseHolder_SendOnSave[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleAdviseHolder_SendOnClose[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleLink_SetUpdateOptions[] =
{
    THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleLink_GetUpdateOptions[] =
{
    THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleLink_SetSourceMoniker[] =
{
    THOP_IFACE | THOP_IN, THI_IMoniker, THOP_COPY | THOP_IN, 16, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleLink_GetSourceMoniker[] =
{
    THOP_IFACE | THOP_OUT, THI_IMoniker, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleLink_SetSourceDisplayName[] =
{
    THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleLink_GetSourceDisplayName[] =
{
    THOP_LPLPSTR, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleLink_BindToSource[] =
{
    THOP_COPY, 4, THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleLink_BindIfRunning[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleLink_GetBoundSource[] =
{
    THOP_IFACE | THOP_OUT, THI_IUnknown, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleLink_UnbindSource[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleLink_Update[] =
{
    THOP_IFACE | THOP_IN, THI_IBindCtx, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleWindow_GetWindow[] =
{
    THOP_HUSER | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleWindow_ContextSensitiveHelp[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceObject_GetWindow[] =
{
    THOP_HUSER | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceObject_ContextSensitiveHelp[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceObject_InPlaceDeactivate[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleInPlaceObject_UIDeactivate[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleInPlaceObject_SetObjectRects[] =
{
    THOP_RECT | THOP_IN, THOP_RECT | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleInPlaceObject_ReactivateAndUndo[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleInPlaceActiveObject_GetWindow[] =
{
    THOP_HUSER | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceActiveObject_ContextSensitiveHelp[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceActiveObject_TranslateAccelerator[] =
{
    THOP_MSG | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceActiveObject_OnFrameWindowActivate[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceActiveObject_OnDocWindowActivate[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceActiveObject_ResizeBorder[] =
{
    THOP_RECT | THOP_IN, THOP_IFACE | THOP_IN, THI_IOleInPlaceFrame, THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleInPlaceActiveObject_EnableModeless[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceUIWindow_GetWindow[] =
{
    THOP_HUSER | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceUIWindow_ContextSensitiveHelp[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceUIWindow_GetBorder[] =
{
    THOP_RECT | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceUIWindow_RequestBorderSpace[] =
{
    THOP_RECT | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceUIWindow_SetBorderSpace[] =
{
    THOP_RECT | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceUIWindow_SetActiveObject[] =
{
    THOP_IFACE | THOP_IN, THI_IOleInPlaceActiveObject, THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleInPlaceFrame_GetWindow[] =
{
    THOP_HUSER | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceFrame_ContextSensitiveHelp[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceFrame_GetBorder[] =
{
    THOP_RECT | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceFrame_RequestBorderSpace[] =
{
    THOP_RECT | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceFrame_SetBorderSpace[] =
{
    THOP_RECT | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceFrame_SetActiveObject[] =
{
    THOP_IFACE | THOP_IN, THI_IOleInPlaceActiveObject, THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleInPlaceFrame_InsertMenus[] =
{
    THOP_HUSER, THOP_COPY | THOP_INOUT, 24, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIOleInPlaceFrame_SetMenu[] =
{
    THOP_HUSER, THOP_ALIAS32, ALIAS_RESOLVE, THOP_HUSER, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIOleInPlaceFrame_RemoveMenus[] =
{
    THOP_HUSER, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceFrame_SetStatusText[] =
{
    THOP_LPSTR | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceFrame_EnableModeless[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceFrame_TranslateAccelerator[] =
{
    THOP_MSG | THOP_IN, THOP_WORDDWORD, THOP_END, THOP_ROUTINEINDEX, 17
};
THOP thopsIOleInPlaceSite_GetWindow[] =
{
    THOP_HUSER | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceSite_ContextSensitiveHelp[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceSite_CanInPlaceActivate[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleInPlaceSite_OnInPlaceActivate[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleInPlaceSite_OnUIActivate[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleInPlaceSite_GetWindowContext[] =
{
    THOP_IFACE | THOP_OUT, THI_IOleInPlaceFrame, THOP_IFACE | THOP_OUT, THI_IOleInPlaceUIWindow, THOP_RECT | THOP_OUT, THOP_RECT | THOP_OUT, THOP_OIFI | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 7
};
THOP thopsIOleInPlaceSite_Scroll[] =
{
    THOP_SIZE, THOP_END, THOP_ROUTINEINDEX, 18
};
THOP thopsIOleInPlaceSite_OnUIDeactivate[] =
{
    THOP_SHORTLONG, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIOleInPlaceSite_OnInPlaceDeactivate[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleInPlaceSite_DiscardUndoState[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleInPlaceSite_DeactivateAndUndo[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIOleInPlaceSite_OnPosRectChange[] =
{
    THOP_RECT | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRpcChannelBuffer_GetBuffer[] =
{
    THOP_RPCOLEMESSAGE | THOP_INOUT, THOP_COPY | THOP_IN, 16, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIRpcChannelBuffer_SendReceive[] =
{
    THOP_RPCOLEMESSAGE | THOP_INOUT, THOP_COPY | THOP_OUT, 4, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIRpcChannelBuffer_FreeBuffer[] =
{
    THOP_RPCOLEMESSAGE | THOP_INOUT, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRpcChannelBuffer_GetDestCtx[] =
{
    THOP_COPY | THOP_OUT, 4, THOP_NULL | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIRpcChannelBuffer_IsConnected[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIRpcProxyBuffer_Connect[] =
{
    THOP_IFACE | THOP_IN, THI_IRpcChannelBuffer, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRpcProxyBuffer_Disconnect[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIRpcStubBuffer_Connect[] =
{
    THOP_IFACE | THOP_IN, THI_IUnknown, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRpcStubBuffer_Disconnect[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIRpcStubBuffer_Invoke[] =
{
    THOP_RPCOLEMESSAGE | THOP_INOUT, THOP_IFACE | THOP_IN, THI_IRpcChannelBuffer, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIRpcStubBuffer_IsIIDSupported[] =
{
    THOP_RETURNTYPE, THOP_IFACE | THOP_IN, THI_IRpcStubBuffer, THOP_COPY | THOP_IN, 16, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRpcStubBuffer_CountRefs[] =
{
    THOP_RETURNTYPE, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIRpcStubBuffer_DebugServerQueryInterface[] =
{
    THOP_IFACE | THOP_OUT, THI_IUnknown, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRpcStubBuffer_DebugServerRelease[] =
{
    THOP_IFACECLEAN | THOP_IN, THI_IUnknown, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIPSFactoryBuffer_CreateProxy[] =
{
    THOP_IFACE | THOP_IN, THI_IUnknown, THOP_COPY | THOP_IN, 16, THOP_IFACEOWNER | THOP_OUT, THI_IRpcProxyBuffer, 8, THOP_IFACEGENOWNER | THOP_OUT, 8, 12, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIPSFactoryBuffer_CreateStub[] =
{
    THOP_COPY | THOP_IN, 16, THOP_IFACE | THOP_IN, THI_IUnknown, THOP_IFACEOWNER | THOP_OUT, THI_IRpcStubBuffer, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
THOP thopsIRpcChannel_GetStream[] =
{
    THOP_COPY | THOP_IN, 16, THOP_SHORTLONG, THOP_SHORTLONG, THOP_SHORTLONG, THOP_COPY, 4, THOP_IFACE | THOP_OUT, THI_IStream, THOP_END, THOP_ROUTINEINDEX, 4
};
THOP thopsIRpcChannel_Call[] =
{
    THOP_IFACE | THOP_IN, THI_IStream, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRpcChannel_GetDestCtx[] =
{
    THOP_COPY | THOP_OUT, 4, THOP_NULL | THOP_OUT, THOP_END, THOP_ROUTINEINDEX, 0
};
THOP thopsIRpcChannel_IsConnected[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIRpcProxy_Connect[] =
{
    THOP_IFACE | THOP_IN, THI_IRpcChannel, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRpcProxy_Disconnect[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIRpcStub_Connect[] =
{
    THOP_IFACE | THOP_IN, THI_IUnknown, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRpcStub_Disconnect[] =
{
    THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIRpcStub_Invoke[] =
{
    THOP_COPY | THOP_IN, 16, THOP_SHORTLONG, THOP_IFACE | THOP_IN, THI_IStream, THOP_COPY, 4, THOP_NULL | THOP_IN, THOP_END, THOP_ROUTINEINDEX, 7
};
THOP thopsIRpcStub_IsIIDSupported[] =
{
    THOP_RETURNTYPE, THOP_SHORTLONG, THOP_COPY | THOP_IN, 16, THOP_END, THOP_ROUTINEINDEX, 3
};
THOP thopsIRpcStub_CountRefs[] =
{
    THOP_RETURNTYPE, THOP_COPY, 4, THOP_END, THOP_ROUTINEINDEX, 1
};
THOP thopsIPSFactory_CreateProxy[] =
{
    THOP_IFACE | THOP_IN, THI_IUnknown, THOP_COPY | THOP_IN, 16, THOP_IFACEOWNER | THOP_OUT, THI_IRpcProxy, 8, THOP_IFACEGENOWNER | THOP_OUT, 8, 12, THOP_END, THOP_ROUTINEINDEX, 5
};
THOP thopsIPSFactory_CreateStub[] =
{
    THOP_COPY | THOP_IN, 16, THOP_IFACE | THOP_IN, THI_IUnknown, THOP_IFACEOWNER | THOP_OUT, THI_IRpcStub, 4, THOP_END, THOP_ROUTINEINDEX, 2
};
