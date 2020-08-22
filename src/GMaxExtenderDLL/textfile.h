///////////////////////////////////////////////////////////////////////////////
// Name:        textfile.h
// Purpose:     Functions to operate on text files
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef TEXTFILE_H
#define TEXTFILE_H


// Open a file for writing in text mode.
// Result of this creating is stored to file "KrxExtender.res"
// If a file will be opened then the "KrxExtender.res" file will contain
// one four-byte value that is handle of the opened file.
// If a file will be failed to open then the "KrxExtender.res" file
// will be cleared by this function.
void createFile(const tstring& strFileName);

// Open an existing file for append output.
// The second parameter must be equal to "a" or "at".
void openFile(const tstring& strFileName, const tstring& strMode);

// Close the file.
void close(long nHandle);

// Returns the current file pointer position
void filePos(long nHandle);

// Move the file pointer to the specified location.
void seek(long nHandle, long nOffset);

// Write a string to the file.
void format(long nHandle, const tstring& strText);


#endif // TEXTFILE_H