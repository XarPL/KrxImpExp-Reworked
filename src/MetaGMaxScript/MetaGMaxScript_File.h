///////////////////////////////////////////////////////////////////////////////
// Name:        MetaGMaxScript_File.h
// Purpose:     Macroses to build plugins for gmax in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
function RequireGMaxExtender = 
(
	if(classOf(_IsKrxGMaxExtenderDllLoaded) == UndefinedClass or _IsKrxGMaxExtenderDllLoaded() == false) then
	(
		local msg = "This script require KrxGMaxExtender to run." 
		messageBox msg
		THROW("An error occured. Operation stopped.")
	)
)

function FlExists filename = 
(
	return ((getFiles (filename)).count != 0)
)

function DeleteFl filename = 
(
	deleteFile filename
)

function GetFlSize filename = 
(
	return (getFileSize filename)
)

function OpenFl filename openmode = 
(
	local bin = (findString openmode "b" != undefined)
	local crm = (findString openmode "w" != undefined)
	local strm = undefined
	if bin then
	(
		if crm then
		(
			RequireGMaxExtender()
			strm = _fopen filename openmode
		)
		else
			strm = fopen filename openmode
	)
	else
	(
		if crm then
		(
			RequireGMaxExtender()
			strm = _createFile filename
		)
		else
			strm = openFile filename
	)		
	return strm
)

function CloseFl strm =
(
	if (strm != undefined) then
	(
		if (classOf(strm) == BinStream) then
			fclose strm
		else if(classOf(strm) == FileStream) then
			close strm
		else if(classOf(strm) == Integer) then
			_fclose strm
	)
)

function FlTell strm = 
(
	local pos = 0
	if (classOf(strm) == BinStream)then
	(
		pos = ftell strm
	)
	else if (classOf(strm) == FileStream) then
	(	
		pos = filePos strm
	)
	else if (classOf(strm) == Integer) then
	(
		pos = _ftell strm
	)
	return pos
)

function FlSeek strm ofs = 
(
	if (classOf(strm) == BinStream) then
	(
		fseek strm ofs HASH seek_set
	)
	else if (classOf(strm) == FileStream) then
	(
		seek strm ofs
	)
	else if (classOf(strm) == Integer) then
	(
		_fseek strm ofs HASH seek_set
	)
)

function WriteSChar strm i =
(
	return (_WriteByte strm i HASH signed)
)

function WriteUChar strm i =
(
	return (_WriteByte strm i HASH unsigned)
)

function WriteSShort strm i =
(
	return (_WriteShort strm i HASH signed)
)

function WriteUShort strm i =
(
	return (_WriteShort strm i HASH unsigned)
)

function WriteSLong strm i =
(
	return (_WriteLong strm i HASH signed)
)

function WriteULong strm i =
(
	_WriteLong strm i HASH unsigned
)

function WriteFlt strm f =
(
	return (_WriteFloat strm f)
)

function WriteStrz strm str =
(
	return (_WriteString strm str)
)

function WriteLn strm str =
(
	_format (str + "\n") _to:strm
	return true
)

function ReadSChar strm =
(
	return (ReadByte strm HASH signed)
)

function ReadUChar strm =
(
	return (ReadByte strm HASH unsigned)
)

function ReadSShort strm =
(
	return (ReadShort strm HASH signed)
)

function ReadUShort strm =
(
	return (ReadShort strm HASH unsigned)
)

function ReadSLong strm =
(
	return (ReadLong strm HASH signed)
)

function ReadULong strm =
(
	return (ReadLong strm HASH unsigned)
)

function ReadFlt strm =
(
	return (ReadFloat strm)
)

function ReadStrz strm =
(
	return (ReadString strm)
)

function ReadLn strm =
(
	local str = readLine strm
	if (eof strm) then
	  seek strm #eof
	return str
)

// Operations on files without opening of them
#define FILE_EXISTS(filename)				(FlExists (filename))
#define FILE_SIZE(filename)					(GetFlSize (filename))
#define DELETE_FILE(filename)				DeleteFl (filename)

// File's stream type
#define TSTREAM                           	File

// The value returned by the "OPEN_FILE" macro when file cannot be opened
#define INVALID_STREAM                     	undefined

// Open file
#define OPEN_FILE(filename, openmode)		(OpenFl (filename) (openmode))

// Close file
#define CLOSE_FILE(strm)					CloseFl(strm)

// Get position of file pointer
#define FILE_TELL(strm)                  	(FlTell(strm))

// Move file pointer to a new position
#define FILE_SEEK(strm, ofs)         		FlSeek (strm) (ofs)

// File write operations
#define WRITE_SIGNED_CHAR(strm, i)          (WriteSChar (strm) (i))
#define WRITE_UNSIGNED_CHAR(strm, i)        (WriteUChar (strm) (i))
#define WRITE_SIGNED_SHORT(strm, i)         (WriteSShort (strm) (i))
#define WRITE_UNSIGNED_SHORT(strm, i)       (WriteUShort (strm) (i))
#define WRITE_SIGNED_LONG(strm, i)          (WriteSLong (strm) (i))
#define WRITE_UNSIGNED_LONG(strm, i)        (WriteULong (strm) (i))
#define WRITE_FLOAT(strm, f)                (WriteFlt (strm) (f))
#define WRITE_STRING(strm, str)             (WriteStrz (strm) (str))
#define WRITE_LINE(strm, str)               (WriteLn (strm) (str))

// File read operations
#define READ_SIGNED_CHAR(strm)              (ReadSChar (strm))
#define READ_UNSIGNED_CHAR(strm)            (ReadUChar (strm))
#define READ_SIGNED_SHORT(strm)             (ReadSShort (strm))
#define READ_UNSIGNED_SHORT(strm)           (ReadUShort (strm))
#define READ_SIGNED_LONG(strm)              (ReadSLong (strm))
#define READ_UNSIGNED_LONG(strm)            (ReadULong (strm))
#define READ_FLOAT(strm)                    (ReadFlt (strm))
#define READ_STRING(strm)                   (ReadStrz (strm))
#define READ_LINE(strm)                     (ReadLn (strm))
