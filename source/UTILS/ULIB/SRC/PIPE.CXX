/*++

Copyright (c) 2000	Microsoft Corporation

Module Name:

	pipe.cxx

Abstract:

	This module contains the implementation of the PIPE class.

Author:

	Barry J. Gilhuly	(W-Barry)		June 27, 2000

Environment:

	ULIB, User Mode


--*/

#include <pch.cxx>

#define _ULIB_MEMBER_

#include "ulib.hxx"
#include "pipestrm.hxx"
#include "pipe.hxx"
#include "wstring.hxx"


DEFINE_CONSTRUCTOR( PIPE, OBJECT );

DEFINE_CAST_MEMBER_FUNCTION( PIPE );


VOID
PIPE::Destroy(
	)
/*++

Routine Description:

	Close the handles which were opened by the initialize method.

Arguments:

	None.

Return Value:

	None.

--*/
{
	if( !_fInitialized ) {
		return;
	}

	//
	// Close the pipe...
	//
	CloseHandle( _hReadPipe );
	CloseHandle( _hWritePipe );
	_fInitialized = FALSE;

	return;
}

BOOLEAN
PIPE::Initialize(
	IN	LPSECURITY_ATTRIBUTES	PipeAttributes,
	IN	ULONG					PipeSize,
	IN	PWSTRING				PipeName
	)
/*++

Routine Description:

	Create a PIPE by making a call to the system API.  If the PIPE object
	has been previously initialized, destroy it first.

Arguments:

	PipeAttributes - A pointer to a structure which defines the attributes
				of the pipe to be created.

	PipeSize	   - A suggested buffer size for the pipe.

	PipeName	   - The name of the pipe.	Currently, this option is
				unimplemented, it should ALWAYS be NULL.

Return Value:

	TRUE if the PIPE was created successfully.

--*/
{
	BOOLEAN PipeStatus = FALSE;

	Destroy();

	if( PipeName == NULL ) {
		//
		// Create an anonomous pipe...
		//
		if( !( PipeStatus = CreatePipe( &_hReadPipe,
						&_hWritePipe,
						PipeAttributes,
						PipeSize ) ) ) {
			DbgPrint( "Unable to create the pipe - returning failure!\n" );
			_fInitialized = FALSE;
		} else {
			_fInitialized = TRUE;
		}
	} else {
		DbgPrint( "Named Pipes are not currently implemented!\n" );
	}
	return( PipeStatus );
}

PPIPE_STREAM
PIPE::QueryPipeStream(
	IN	HANDLE			hPipe,
	IN	STREAMACCESS	Access
	)
/*++

Routine Description:

	Create and initialize a stream to the PIPE object.

Arguments:

	hPipe	- A handle to use in the initialization of the stream.

	Access	- The desired access on this stream.

Return Value:

	Returns a pointer to the created PIPE STREAM if successful.  Otherwise,
	it returns NULL.

--*/
{
	PPIPE_STREAM	NewStream;

	if( !_fInitialized ) {
		DbgPrint( "Pipe object is uninitialized!\n" );
		NewStream = NULL;
	} else {
		if( ( NewStream = NEW PIPE_STREAM ) == NULL ) {
			DbgPrint( "Unable to create a new copy of the Read Stream!\n" );
		} else {
			if( !NewStream->Initialize( hPipe, Access ) ) {
				DbgPrint( "Unable to initialize the new stream!\n" );
				DELETE( NewStream );
				NewStream = NULL;
			}
		}
	}
	return( NewStream );
}
