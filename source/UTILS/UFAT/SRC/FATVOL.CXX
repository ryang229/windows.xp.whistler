#include <pch.cxx>

#include "error.hxx"
#include "message.hxx"
#include "rtmsg.h"
#include "wstring.hxx"


DEFINE_CONSTRUCTOR( FAT_VOL, VOL_LIODPDRV );

VOID
FAT_VOL::Construct (
	)

/*++

Routine Description:

    Constructor for FAT_VOL.

Arguments:

    None.

Return Value:

    None.

--*/
{
	// unreferenced parameters
	(void)(this);
}


FAT_VOL::~FAT_VOL(
    )
/*++

Routine Description:

    Destructor for FAT_VOL.

Arguments:

    None.

Return Value:

    None.

--*/
{
    Destroy();
}


BOOLEAN
FAT_VOL::Initialize(
    IN      PCWSTRING   NtDriveName,
    IN OUT  PMESSAGE    Message,
    IN      BOOLEAN     ExclusiveWrite,
    IN      BOOLEAN     FormatMedia,
    IN      MEDIA_TYPE  MediaType
    )
/*++

Routine Description:

    This routine initializes a FAT_VOL object.

Arguments:

    NtDriveName     - Supplies the drive path for the volume.
    Message         - Supplies an outlet for messages.
    ExclusiveWrite  - Supplies whether or not the drive should be
                        opened for exclusive write.
    FormatMedia     - Supplies whether or not to format the media.
    MediaType       - Supplies the type of media to format to.

Return Value:

    FALSE   - Failure.
    TRUE    - Success.

--*/
{
    MESSAGE msg;

    Destroy();

    if (!VOL_LIODPDRV::Initialize(NtDriveName, &_fatsa, Message,
                                  ExclusiveWrite, FormatMedia,
                                  MediaType)) {
        Destroy();
        return FALSE;
    }

    if (!Message) {
        Message = &msg;
    }

    if (FormatMedia) {
        if (!_fatsa.Initialize(this, Message, FALSE)) {
            Destroy();
            return FALSE;
        }
    } else {
        if (!_fatsa.Initialize(this, &msg, TRUE) &&
            !_fatsa.Initialize(this, Message, FALSE)) {
            Destroy();
            return FALSE;
        }

        if (!_fatsa.Read(Message)) {
            Destroy();
            return FALSE;
        }
    }

    return TRUE;
}


BOOLEAN
FAT_VOL::IsFileContiguous(
    IN      PCWSTRING   FullPathFileName,
    IN OUT  PMESSAGE    Message,
    OUT     PULONG      NumBlocks
    )
/*++

Routine Description:

    This routine computes the number of contiguous blocks for the given
    file.  If the file has only one block then the file is contiguous and
    this function returns TRUE.  Otherwise this function returns FALSE and
    the number of blocks is optionally returned into 'NumBlocks'.

Arguments:

    FullPathFileName    - Supplies the file name of the file to check for
                            contiguity.
    Message             - Supplies an outlet for messages.
    NumBlocks           - Returns the number of contiguous blocks.

Return Value:

    FALSE   - The file is not contiguous.
    TRUE    - The file is contiguous.

--*/
{
    ULONG       num_blocks;
    PFAT        fat;
    USHORT      clus;
    DSTRING     slash;

    if (NumBlocks) {
        *NumBlocks = 0;
    }

    if (!slash.Initialize("\\")) {
        Message ? Message->Set(MSG_CHK_NO_MEMORY) : 1;
        Message ? Message->Display("") : 1;
        return FALSE;
    }

    if (*FullPathFileName == slash) {
        *NumBlocks = 1;
        return TRUE;
    }

    if ((clus = _fatsa.QueryFileStartingCluster(FullPathFileName)) == 1) {
        Message ? Message->Set(MSG_FILE_NOT_FOUND) : 1;
        Message ? Message->Display("%W", FullPathFileName) : 1;
        return FALSE;
    }

    if (clus == 0xFFFF) {
        Message ? Message->Set(MSG_CHK_NO_MEMORY) : 1;
        Message ? Message->Display("") : 1;
        return FALSE;
    }

    // Say that a zero length file is contiguous.

    if (clus == 0) {
        *NumBlocks = 1;
        return TRUE;
    }


    fat = _fatsa.GetFat();

    DbgAssert(fat);

    for (num_blocks = 1; ; num_blocks++) {
		while (!fat->IsEndOfChain(clus) &&
			   (USHORT)(clus + 1) == fat->QueryEntry(clus)) {
            clus++;
        }
        if (fat->IsEndOfChain(clus)) {
            break;
        }
        clus = fat->QueryEntry(clus);
    }

    if (NumBlocks) {
        *NumBlocks = num_blocks;
    }

    return num_blocks == 1;
}


BOOLEAN
FAT_VOL::ContiguityReport(
    IN      PCWSTRING   DirectoryPath,
    IN      PCDSTRING   FilesToCheck,
    IN      ULONG       NumberOfFiles,
    IN OUT  PMESSAGE    Message
    )
/*++

Routine Description:

    This routine generates a contiguity report for all of the 'FilesToCheck'.
    These file are assumed to all be in the directory pointed to by
    'DirectoryPath'.

Arguments:

    DirectoryPath   - Supplies the directory containing the files to check.
    FilesToCheck    - Supplies an array of files to check.
    NumberOfFiles   - Supplies the number of files in the preceeding array.
    Message         - Suppliea an outlet for messages.

Return Value:

    FALSE   - Failure.
    TRUE    - Success.

--*/
{
    ULONG       num_blocks;
    PFAT        fat;
    USHORT      clus;
    DSTRING     slash;
    FILEDIR     filedir;
    PFATDIR     dir;
    HMEM        hmem;
    BOOLEAN     all_contig;
    FAT_DIRENT  fatdent;
    DSTRING     current_file;
    ULONG       i;
    DSTRING     directory_path;

    if (!slash.Initialize("\\")) {
        Message ? Message->Set(MSG_CHK_NO_MEMORY) : 1;
        Message ? Message->Display() : 1;
        return FALSE;
    }

    if ((clus = _fatsa.QueryFileStartingCluster(DirectoryPath)) == 1) {
        Message->Set(MSG_FILE_NOT_FOUND);
        Message->Display("%W", DirectoryPath);
        return FALSE;
    }

    if (clus == 0xFFFF) {
        Message ? Message->Set(MSG_CHK_NO_MEMORY) : 1;
        Message ? Message->Display() : 1;
        return FALSE;
    }

    fat = _fatsa.GetFat();

    if (!clus) {
        dir = _fatsa.GetRootDir();
    } else {
        dir = &filedir;
        if (!hmem.Initialize() ||
            !filedir.Initialize(&hmem, this, &_fatsa, fat, clus)) {
            Message->Set(MSG_CHK_NO_MEMORY);
            Message->Display();
            return FALSE;
        }

        if (!filedir.Read()) {
            Message->Set(MSG_FILE_NOT_FOUND);
            Message->Display("%W", DirectoryPath);
            return FALSE;
        }
    }

    if (*DirectoryPath == slash) {

        if (!directory_path.Initialize("")) {
            Message->Set(MSG_CHK_NO_MEMORY);
            Message->Display();
            return FALSE;
        }
    } else {
        if (!directory_path.Initialize(DirectoryPath)) {
            Message->Set(MSG_CHK_NO_MEMORY);
            Message->Display();
            return FALSE;
        }
    }


    all_contig = TRUE;
    for (i = 0; i < NumberOfFiles; i++) {

        if (!current_file.Initialize(&directory_path) ||
            !current_file.Strcat(&slash) ||
            !current_file.Strcat(&FilesToCheck[i])) {

            Message->Set(MSG_CHK_NO_MEMORY);
            Message->Display();
            return FALSE;
        }

        if (fatdent.Initialize(dir->SearchForDirEntry(&FilesToCheck[i]))) {

            if (clus = fatdent.QueryStartingCluster()) {

                for (num_blocks = 1; ; num_blocks++) {
            		while (!fat->IsEndOfChain(clus) &&
            			   (USHORT)(clus + 1) == fat->QueryEntry(clus)) {
                        clus++;
                    }
                    if (fat->IsEndOfChain(clus)) {
                        break;
                    }
                    clus = fat->QueryEntry(clus);
                }

                if (num_blocks != 1) {
                    Message->Set(MSG_CONTIGUITY_REPORT);
                    Message->Display("%W%d", &current_file, num_blocks);
                    all_contig = FALSE;
                }

            }

        } else {
            Message->Set(MSG_FILE_NOT_FOUND);
            Message->Display("%W", &current_file);
            all_contig = FALSE;
        }
    }

    if (all_contig) {
        Message->Set(MSG_ALL_FILES_CONTIGUOUS);
        Message->Display("");
    }

    return TRUE;
}


PVOL_LIODPDRV
FAT_VOL::QueryDupVolume(
    IN      PCWSTRING   NtDriveName,
    IN OUT  PMESSAGE    Message,
    IN      BOOLEAN     ExclusiveWrite,
    IN      BOOLEAN     FormatMedia,
    IN      MEDIA_TYPE  MediaType
    ) CONST
/*++

Routine Description:

    This routine allocates a FAT_VOL and initializes it to 'NtDriveName'.

Arguments:

    NtDriveName     - Supplies the drive path for the volume.
    Message         - Supplies an outlet for messages.
    ExclusiveWrite  - Supplies whether or not the drive should be
                        opened for exclusive write.
    FormatMedia     - Supplies whether or not to format the media.
    MediaType       - Supplies the type of media to format to.

Return Value:

    A pointer to a newly allocated FAT volume.

--*/
{
    PFAT_VOL    vol;

	// unreferenced parameters
	(void)(this);

	if (!(vol = NEW FAT_VOL)) {
        Message ? Message->Set(MSG_FMT_NO_MEMORY) : 1;
        Message ? Message->Display("") : 1;
        return NULL;
    }

    if (!vol->Initialize(NtDriveName, Message, ExclusiveWrite,
                         FormatMedia, MediaType)) {
        DELETE(vol);
        return NULL;
    }

    return vol;
}


VOID
FAT_VOL::Destroy(
    )
/*++

Routine Description:

    This routine returns a FAT_VOL object to its initial state.

Arguments:

    None.

Return Value:

    None.

--*/
{
	// unreferenced parameters
	(void)(this);
}
