///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_File.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static bool FlExists(const std::tstring& filename)
{
	return _taccess(filename.c_str(), 00) == 0;
}

static void DeleteFl(const std::tstring& filename)
{
	_tremove(filename.c_str());
}

static int GetFlSize(const std::tstring& filename)
{
	FILE* strm = _tfopen(filename.c_str(), _T("rb"));
	if(!strm) return INVALID_INT;
	fseek(strm, 0, SEEK_END);
	int sz = ftell(strm);
	fclose(strm);
	return sz;
}	

static FILE* OpenFl(const std::tstring& filename, const std::tstring& openmode)
{
	FILE* strm = _tfopen(filename.c_str(), openmode.c_str());
	return strm;
}

static void CloseFl(FILE* strm)
{
	fclose(strm);
}

static int FlTell(FILE* strm)
{
	return ftell(strm);
}

static void FlSeek(FILE* strm, long ofs)
{
	fseek(strm, ofs, SEEK_SET);
}

static bool WriteSChar(FILE* strm, int i)
{
	return 1 == fwrite(&i, 1, 1, strm);
}

static bool WriteUChar(FILE* strm, int i)
{
	return 1 == fwrite(&i, 1, 1, strm);
}

static bool WriteSShort(FILE* strm, int i)
{
	return 2 == fwrite(&i, 1, 2, strm);
}

static bool WriteUShort(FILE* strm, int i)
{
	return 2 == fwrite(&i, 1, 2, strm);
}

static bool WriteSLong(FILE* strm, int i)
{
	return 4 == fwrite(&i, 1, 4, strm);
}

static bool WriteULong(FILE* strm, int i)
{
	return 4 == fwrite(&i, 1, 4, strm);
}

static bool WriteFlt(FILE* strm, float f)
{
	return 4 == fwrite(&f, 1, 4, strm);
}

static bool WriteStrz(FILE* strm, const std::tstring& tstr)
{
	std::string cstr = ToCString(tstr);
	int sz = (int) cstr.length() + 1;
	return sz == fwrite(cstr.c_str(), 1, sz, strm);
}

static bool WriteLn(FILE* strm, const std::tstring& tstr)
{
	std::string cstr = ToCString(tstr);
	return (fputs(cstr.c_str(), strm) != EOF && fputs("\n", strm) != EOF);
}

static int ReadSChar(FILE* strm)
{
	signed char i = 0;
	if(1 != fread(&i, 1, 1, strm))
		return INVALID_INT;
	return (int) i;
}

static int ReadUChar(FILE* strm)
{
	unsigned char i = 0;
	if(1 != fread(&i, 1, 1, strm))
		return INVALID_INT;
	return (int) i;
}

static int ReadSShort(FILE* strm)
{
	signed short i = 0;
	if(2 != fread(&i, 1, 2, strm))
		return INVALID_INT;
	return (int) i;
}

static int ReadUShort(FILE* strm)
{
	unsigned short i = 0;
	if(2 != fread(&i, 1, 2, strm))
		return INVALID_INT;
	return (int) i;
}

static int ReadSLong(FILE* strm)
{
	signed long i = 0;
	if(4 != fread(&i, 1, 4, strm))
		return INVALID_INT;
	return (int) i;
}

static int ReadULong(FILE* strm)
{
	unsigned long i = 0;
	if(4 != fread(&i, 1, 4, strm))
		return INVALID_INT;
	return (int) i;
}

static float ReadFlt(FILE* strm)
{
	float f = 0;
	if(4 != fread(&f, 1, 4, strm))
		return INVALID_FLOAT;
	return f;
}

static std::tstring ReadStrz(FILE* strm)
{
	const size_t bufsize = 4096;
	char buf[bufsize];
	size_t pos = ftell(strm);
	size_t size_read = fread(buf, 1, bufsize, strm);
	size_t len = 0;
	
	while(len < size_read && buf[len] != 0)
		++len;

	if(len == size_read)
		return INVALID_STRING;

	fseek(strm, (long) (pos + len + 1), SEEK_SET);
	buf[len] = 0;
	return ToTString(buf);
}

static std::tstring ReadLn(FILE* strm)
{
	const size_t bufsize = 1024;
	char buf[bufsize];
	size_t pos = ftell(strm);
	if(fgets(buf, bufsize, strm) == NULL)
		return INVALID_STRING;

	buf[bufsize - 1] = 0;
	size_t len = strlen(buf);
	if(buf[len - 1] == _T('\n'))
		buf[len - 1] = _T('\0');
	
	return ToTString(buf);	
}

// Operations on files without opening of them
#define FILE_EXISTS(filename)				FlExists(filename)
#define FILE_SIZE(filename)					GetFlSize(filename)
#define DELETE_FILE(filename)				DeleteFl(filename);

// File's stream type
#define TSTREAM				                FILE*

// The value returned by the "OPEN_FILE" macro when file cannot be opened
#define INVALID_STREAM		                NULL

// Open file
#define OPEN_FILE(filename, openmode)		OpenFl(filename, openmode)

// Close file
#define CLOSE_FILE(strm)					CloseFl(strm);

// Get position of file pointer
#define FILE_TELL(strm)                  	FlTell(strm)

// Move file pointer to a new position
#define FILE_SEEK(strm, ofs)         		FlSeek(strm, ofs);

// File write operations
#define WRITE_SIGNED_CHAR(strm, i)          (WriteSChar(strm, i))
#define WRITE_UNSIGNED_CHAR(strm, i)        (WriteUChar(strm, i))
#define WRITE_SIGNED_SHORT(strm, i)         (WriteSShort(strm, i))
#define WRITE_UNSIGNED_SHORT(strm, i)       (WriteUShort(strm, i))
#define WRITE_SIGNED_LONG(strm, i)          (WriteSLong(strm, i))
#define WRITE_UNSIGNED_LONG(strm, i)        (WriteULong(strm, i))
#define WRITE_FLOAT(strm, f)                (WriteFlt(strm, f))
#define WRITE_STRING(strm, str)             (WriteStrz(strm, str))
#define WRITE_LINE(strm, str)               (WriteLn(strm, str))

// File read operations
#define READ_SIGNED_CHAR(strm)              (ReadSChar(strm))
#define READ_UNSIGNED_CHAR(strm)            (ReadUChar(strm))
#define READ_SIGNED_SHORT(strm)             (ReadSShort(strm))
#define READ_UNSIGNED_SHORT(strm)           (ReadUShort(strm))
#define READ_SIGNED_LONG(strm)              (ReadSLong(strm))
#define READ_UNSIGNED_LONG(strm)            (ReadULong(strm))
#define READ_FLOAT(strm)                    (ReadFlt(strm))
#define READ_STRING(strm)                   (ReadStrz(strm))
#define READ_LINE(strm)                     (ReadLn(strm))

