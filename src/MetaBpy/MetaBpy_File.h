///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_File.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 11, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Operations on files without opening of them
#define FILE_EXISTS(filename)				file_exists(filename)
#define FILE_SIZE(filename)					get_file_size(filename)
#define DELETE_FILE(filename)				delete_file(filename)

// File's stream type
#define TSTREAM				                file

// The value returned by the "OPEN_FILE" macro when file cannot be opened
#define INVALID_STREAM		                None

// Open file
#define OPEN_FILE(filename, openmode)		open_file(filename, openmode)

// Close file
#define CLOSE_FILE(strm)					close_file(strm)

// Get position of file pointer
#define FILE_TELL(strm)                  	file_tell(strm)

// Move file pointer to a new position
#define FILE_SEEK(strm, ofs)         		file_seek(strm, ofs);

// File write operations
#define WRITE_SIGNED_CHAR(strm, i)          (write_signed_char(strm, i))
#define WRITE_UNSIGNED_CHAR(strm, i)        (write_unsigned_char(strm, i))
#define WRITE_SIGNED_SHORT(strm, i)         (write_signed_short(strm, i))
#define WRITE_UNSIGNED_SHORT(strm, i)       (write_unsigned_short(strm, i))
#define WRITE_SIGNED_LONG(strm, i)          (write_signed_long(strm, i))
#define WRITE_UNSIGNED_LONG(strm, i)        (write_unsigned_long(strm, i))
#define WRITE_FLOAT(strm, f)                (write_float(strm, f))
#define WRITE_STRING(strm, str)             (write_stringz(strm, str))
#define WRITE_LINE(strm, str)               (write_line(strm, str))

// File read operations
#define READ_SIGNED_CHAR(strm)              (read_signed_char(strm))
#define READ_UNSIGNED_CHAR(strm)            (read_unsigned_char(strm))
#define READ_SIGNED_SHORT(strm)             (read_signed_short(strm))
#define READ_UNSIGNED_SHORT(strm)           (read_unsigned_short(strm))
#define READ_SIGNED_LONG(strm)              (read_signed_long(strm))
#define READ_UNSIGNED_LONG(strm)            (read_unsigned_long(strm))
#define READ_FLOAT(strm)                    (read_float(strm))
#define READ_STRING(strm)                   (read_stringz(strm))
#define READ_LINE(strm)                     (read_line(strm))

