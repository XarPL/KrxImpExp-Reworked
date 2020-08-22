///////////////////////////////////////////////////////////////////////////////
// Name:        textfile.cpp
// Purpose:     Functions to operate on text files
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "textfile.h"
#include "datatransfer.h"


// Open a file for writing in text mode.
void createFile(const tstring& strFileName)
{
	FILE* file = _tfopen(strFileName.c_str(), _T("wt"));
	long nHandle = (long)(void*) file;
	SendToMaxScript(nHandle);
}

// Open an existing file for append output.
void openFile(const tstring& strFileName, const tstring& strMode)
{
	long nHandle = 0;
	if(strMode == _T("a") || strMode == _T("at"))
	{
		FILE* file = _tfopen(strFileName.c_str(), _T("at"));
		nHandle = (long)(void*) file;
	}
	SendToMaxScript(nHandle);
}

// Close the file.
void close(long nHandle)
{
	FILE* file = (FILE*)(void*) nHandle;
	fclose(file);
}

// Returns the current file pointer position
void filePos(long nHandle)
{
	FILE* file = (FILE*)(void*) nHandle;
	long nPos = ftell(file);
	SendToMaxScript(nPos);
}

// Move the file pointer to the specified location.
void seek(long nHandle, long nOffset)
{
	FILE* file = (FILE*)(void*) nHandle;
	fseek(file, nOffset, SEEK_SET);
}

// Write a string to the file.
void format(long nHandle, const tstring& str)
{
	FILE* file = (FILE*)(void*) nHandle;
	_fputts(str.c_str(), file);
}
