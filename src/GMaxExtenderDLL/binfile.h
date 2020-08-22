///////////////////////////////////////////////////////////////////////////////
// Name:        binfile.h
// Purpose:     Functions to operate on binary files
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef BINFILE_H
#define BINFILE_H

// Open a file for writing in binary mode.
// The second parameter must be equal to "wb".
// Result of this opening is stored to file "KrxExtender.res"
// If a file will be opened then the "KrxExtender.res" file will contain
// one four-byte value that is handle of the opened file.
// If a file will be failed to open then the "KrxExtender.res" file
// will be cleared by this function.
void FOpen(const tstring& strFileName, const tstring& strMode);

// Close file.
void FClose(long nHandle);

// Returns the current file pointer position
void FTell(long nHandle);

// Move the file pointer to the specified location.
// strOrigin can be one of the following values: "#seek_set", "#seek_cur", "#seek_end".
void FSeek(long nHandle, long nOffset, const tstring& strOrigin);

// Write an integer to the file as one byte.
void WriteByte(long nHandle, char nByte);

// Write an integer to the file as two bytes.
void WriteShort(long nHandle, short nShort);

// Write an integer to the file as four bytes.
void WriteLong(long nHandle, long nLong);

// Write a float to the file as four bytes.
void WriteFloat(long nHandle, float f);

// Write a string to the file with terminating zero character.
void WriteString(long nHandle, const tstring& str);

#endif // BINFILE_H