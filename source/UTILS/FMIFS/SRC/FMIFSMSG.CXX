#include "ulib.hxx"
#include "fmifsmsg.hxx"
#include "rtmsg.h"


DEFINE_CONSTRUCTOR(FMIFS_MESSAGE, MESSAGE);


FMIFS_MESSAGE::~FMIFS_MESSAGE(
    )
/*++

Routine Description:

    Destructor for FMIFS_MESSAGE.

Arguments:

    None.

Return Value:

    None.

--*/
{
    Destroy();
}


VOID
FMIFS_MESSAGE::Construct(
    )
/*++

Routine Description:

    This routine initializes the object to a default initial state.

Arguments:

    None.

Return Value:

    None.

--*/
{
    _msgid = 0;
    _callback = NULL;
    _kilobytes_total_disk_space = 0;
}


VOID
FMIFS_MESSAGE::Destroy(
    )
/*++

Routine Description:

    This routine returns the object to a default initial state.

Arguments:

    None.

Return Value:

    None.

--*/
{
    _msgid = 0;
    _callback = NULL;
    _kilobytes_total_disk_space = 0;
}


BOOLEAN
FMIFS_MESSAGE::Initialize(
    IN  FMIFS_CALLBACK  CallBack
    )
/*++

Routine Description:

    This routine initializes the class to a valid initial state.

Arguments:

    CallBack    - Supplies the callback to the file manager.

Return Value:

    FALSE   - Failure.
    TRUE    - Success.

--*/
{
    Destroy();
    _callback = CallBack;
    return _callback ? TRUE : FALSE;
}


BOOLEAN
FMIFS_MESSAGE::DisplayV(
    IN  PCSTR   Format,
    IN  va_list VarPointer
    )
/*++

Routine Description:

    This routine displays the message with the specified parameters.

    The format string supports all printf options.

Arguments:

    Format      - Supplies a printf style format string.
    VarPointer  - Supplies a varargs pointer to the arguments.

Return Value:

    FALSE   - Failure.
    TRUE    - Success.

--*/
{
    FMIFS_PERCENT_COMPLETE_INFORMATION  percent_info;
    FMIFS_FORMAT_REPORT_INFORMATION     fmt_report;
    FMIFS_INSERT_DISK_INFORMATION       insert_info;
    FMIFS_IO_ERROR_INFORMATION          io_error_info;
    BOOLEAN                             r = TRUE;
    PWSTRING                            drive_name, file_name;


    switch (_msgid) {

        case MSG_PERCENT_COMPLETE:
            percent_info.PercentCompleted = va_arg(VarPointer, ULONG);
            r = _callback(FmIfsPercentCompleted,
                          sizeof(FMIFS_PERCENT_COMPLETE_INFORMATION),
                          &percent_info);
            break;

        case MSG_DCOPY_INSERT_TARGET:
            insert_info.DiskType = DISK_TYPE_TARGET;
            r = _callback(FmIfsInsertDisk,
                          sizeof(FMIFS_INSERT_DISK_INFORMATION),
                          &insert_info);
            break;

        case MSG_DCOPY_INSERT_SOURCE:
            insert_info.DiskType = DISK_TYPE_SOURCE;
            r = _callback(FmIfsInsertDisk,
                          sizeof(FMIFS_INSERT_DISK_INFORMATION),
                          &insert_info);
            break;

        case MSG_DCOPY_INSERT_SOURCE_AND_TARGET:
            insert_info.DiskType = DISK_TYPE_SOURCE_AND_TARGET;
            r = _callback(FmIfsInsertDisk,
                          sizeof(FMIFS_INSERT_DISK_INFORMATION),
                          &insert_info);
            break;

        case MSG_HPFS_FORMAT_NO_FLOPPIES:
        case MSG_HPFS_FORMAT_BAD_SECTOR_SIZE:
            r = _callback(FmIfsIncompatibleFileSystem, 0, NULL);
            break;

        case MSG_DCOPY_FORMATTING_WHILE_COPYING:
            r = _callback(FmIfsFormattingDestination, 0, NULL);
            break;

        case MSG_DCOPY_BAD_DEST:
        case MSG_DCOPY_NON_COMPAT_DISKS:
            r = _callback(FmIfsIncompatibleMedia, 0, NULL);
            break;

        case MSG_TOTAL_DISK_SPACE:
            _kilobytes_total_disk_space = va_arg(VarPointer, ULONG)/1024;
            break;

        case MSG_AVAILABLE_DISK_SPACE:
            fmt_report.KiloBytesTotalDiskSpace = _kilobytes_total_disk_space;
            fmt_report.KiloBytesAvailable = va_arg(VarPointer, ULONG)/1024;
            r = _callback(FmIfsFormatReport,
                          sizeof(FMIFS_FORMAT_REPORT_INFORMATION),
                          &fmt_report);
            break;

        case MSG_TOTAL_KILOBYTES:
        case MSG_CHK_NTFS_TOTAL_DISK_SPACE:
            _kilobytes_total_disk_space = va_arg(VarPointer, ULONG);
            break;

        case MSG_AVAILABLE_KILOBYTES:
        case MSG_CHK_NTFS_AVAILABLE_SPACE:
            fmt_report.KiloBytesTotalDiskSpace = _kilobytes_total_disk_space;
            fmt_report.KiloBytesAvailable = va_arg(VarPointer, ULONG);
            r = _callback(FmIfsFormatReport,
                          sizeof(FMIFS_FORMAT_REPORT_INFORMATION),
                          &fmt_report);
            break;

        case MSG_DCOPY_WRITE_ERROR:
        case MSG_DCOPY_READ_ERROR:
            io_error_info.DiskType = (_msgid == MSG_DCOPY_READ_ERROR) ?
                                     DISK_TYPE_SOURCE : DISK_TYPE_TARGET;
            va_arg(VarPointer, PVOID);
            io_error_info.Head = va_arg(VarPointer, ULONG);
            io_error_info.Track = va_arg(VarPointer, ULONG);
            r = _callback(FmIfsIoError,
                          sizeof(FMIFS_IO_ERROR_INFORMATION),
                          &io_error_info);
            break;

        case MSG_CANT_LOCK_THE_DRIVE:
            r = _callback(FmIfsCantLock, 0, NULL);
            break;

        case MSG_DASD_ACCESS_DENIED:
            r = _callback(FmIfsAccessDenied, 0, NULL);
            break;

        case MSG_CANT_QUICKFMT:
            r = _callback(FmIfsCantQuickFormat, 0, NULL);
            break;

        case MSG_FMT_WRITE_PROTECTED_MEDIA:
            r = _callback(FmIfsMediaWriteProtected, 0, NULL);
            break;

        case MSG_INVALID_LABEL_CHARACTERS:
            r = _callback(FmIfsBadLabel, 0, NULL);
            break;

#if defined ( DBLSPACE_ENABLED )
        case MSG_DBLSPACE_VOLUME_NOT_CREATED:
            r = _callback(FmIfsDblspaceCreateFailed, 0, NULL);
            break;

        case MSG_DBLSPACE_CANT_MOUNT:
            r = _callback(FmIfsDblspaceMountFailed, 0, NULL);
            break;

        case MSG_DBLSPACE_CANT_ASSIGN_DRIVE_LETTER:
            r = _callback(FmIfsDblspaceDriveLetterFailed, 0, NULL);
            break;

        case MSG_DBLSPACE_VOLUME_CREATED:
            // Both arguments to this message are PWSTRING's;
            // the first is the drive, the second is the
            // Compressed Volume File name.
            //
            drive_name = va_arg( VarPointer, PWSTRING );
            file_name = va_arg( VarPointer, PWSTRING );
            r = _callback(FmIfsDblspaceCreated,
                          file_name->QueryChCount() * sizeof(WCHAR),
                          (PVOID)file_name->GetWSTR() );
            break;

        case MSG_DBLSPACE_MOUNTED:
            r = _callback(FmIfsDblspaceMounted, 0, NULL);
            break;
#endif // DBLSPACE_ENABLED

        default:
            break;
    }

    return r;
}


PMESSAGE
FMIFS_MESSAGE::Dup(
    )
/*++

Routine Description:

    This routine returns a new MESSAGE of the same type.

Arguments:

    None.

Return Value:

    A pointer to a new MESSAGE object.

--*/
{
    PFMIFS_MESSAGE  p;

    if (!(p = NEW FMIFS_MESSAGE)) {
        return NULL;
    }

    if (!p->Initialize(_callback)) {
        DELETE(p);
        return NULL;
    }

    return p;
}
