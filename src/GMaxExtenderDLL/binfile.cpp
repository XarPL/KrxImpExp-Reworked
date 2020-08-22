///////////////////////////////////////////////////////////////////////////////
// Name:        binfile.cpp
// Purpose:     Functions to operate on binary files
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "binfile.h"
#include "datatransfer.h"

// Open a file for writing in binary mode.
void FOpen(const tstring& strFileName, const tstring& strMode)
{
	long nHandle = 0;
	if(strMode == _T("wb"))
	{
		FILE* file = _tfopen(strFileName.c_str(), _T("wb"));
		nHandle = (long)(void*) file;
	}
	SendToMaxScript(nHandle);
}

// Close file.
void FClose(long nHandle)
{
	FILE* file = (FILE*)(void*) nHandle;
	fclose(file);
}

// Returns the current file pointer position
void FTell(long nHandle)
{
	FILE* file = (FILE*)(void*) nHandle;
	long nPos = ftell(file);
	SendToMaxScript(nPos);
}

// Move the file pointer to the specified location.
void FSeek(long nHandle, long nOffset, const tstring& strOrigin)
{
	int nOrigin;
	if(_tcsicmp(strOrigin.c_str(), _T("#seek_set")) == 0)
		nOrigin = SEEK_SET;
	else if(_tcsicmp(strOrigin.c_str(), _T("#seek_cur")) == 0)
		nOrigin = SEEK_CUR;
	else if(_tcsicmp(strOrigin.c_str(), _T("#seek_end")) == 0)
		nOrigin = SEEK_END;
	else
		return;

	FILE* file = (FILE*)(void*) nHandle;
	fseek(file, nOffset, nOrigin);
}


// Write an integer to the file as one byte.
void WriteByte(long nHandle, char nByte)
{
	FILE* file = (FILE*)(void*) nHandle;
	fwrite(&nByte, 1, 1, file);
}

// Write an integer to the file as two bytes.
void WriteShort(long nHandle, short nShort)
{
	FILE* file = (FILE*)(void*) nHandle;
	fwrite(&nShort, 2, 1, file);
}

// Write an integer to the file as four bytes.
void WriteLong(long nHandle, long nLong)
{
	FILE* file = (FILE*)(void*) nHandle;
	fwrite(&nLong, 4, 1, file);
}

// Write a float to the file as four bytes.
void WriteFloat(long nHandle, float fFloat)
{
	FILE* file = (FILE*)(void*) nHandle;
	fwrite(&fFloat, 4, 1, file);
}

// Write a string to the file with terminating zero character.
void WriteString(long nHandle, const tstring& str)
{
	FILE* file = (FILE*)(void*) nHandle;
	long len = str.length();
	string cstr;
	cstr.reserve(len + 1);
	for(int i = 0; i < len; ++i)
		cstr.push_back( (char) str[i] );
	fwrite(cstr.c_str(), 1, len + 1, file);
}