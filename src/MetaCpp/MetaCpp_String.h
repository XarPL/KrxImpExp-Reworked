///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_String.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static std::tstring UCaseStr(const std::tstring& str)
{
	std::tstring result = str;
	for(size_t i = 0; i < result.length(); ++i)
	{
		result[i] = _totupper(result[i]);
	}
	return result;
}
	
static std::tstring LCaseStr(const std::tstring& str)
{
	std::tstring result = str;
	for(size_t i = 0; i < result.length(); ++i)
	{
		result[i] = _totlower(result[i]);
	}
	return result;
}
	
static int CmpStr(const std::tstring& str1, const std::tstring& str2)
{
	return _tcscmp(str1.c_str(), str2.c_str());
}

static int ICmpStr(const std::tstring& str1, const std::tstring& str2)
{
	return _tcsicmp(str1.c_str(), str2.c_str());
}
	
// Strings
#define TSTRING                    std::tstring
#define EMPTY_STRING               std::tstring()

// String as argument type
template <> struct FC<TSTRING> {typedef const std::tstring& ArgType;};

// Invalid string - a special return value for functions
#define INVALID_STRING			_T("$$INVALID$$")

// Gets string length
#define STRLEN(str)					((int) ((str).length()))

// String concatenation
#define STRCAT(str, str2)			str += (str2);

// Gets a substring of at most some number of characters from a string beginning from a specified position;
// start is zero-based index of the first extracting character 
#define SUBSTR(str, start, stop)	((str).substr((start), (stop) - (start)))

// Finds first substring from one string in another string
#define STRFIND(str, str2)			((int) ((str).find(str2)))

// Value that STRFIND returns if substring was not found
#define NOT_FOUND					-1

// Makes a string upper case
#define UPPER_CASE(str)				(UCaseStr(str))

// Makes a string lower case
#define LOWER_CASE(str)				(LCaseStr(str))

// Compares strings with case sensitive (returns 0 if the strings are equal, 
// -1 if the first string < the second string, 1 if the first string > the second string)
#define STRCMP(str1, str2)			(CmpStr(str1, str2))

// Compares strings with case insentive (returns 0 if the strings are equal, 
// -1 if the first string < the second string, 1 if the first string > the second string)
#define STRICMP(str1, str2)			(ICmpStr(str1, str2))

// Convert to std::tstring
#ifdef _UNICODE
template<typename DummyType>
std::tstring ToTString(const char* psz, size_t len)
{
	int sz = MultiByteToWideChar(CP_ACP, 0, psz, -1, NULL, 0);
	std::tstring tstr(sz - 1, _T(' '));
	MultiByteToWideChar(CP_ACP, 0, psz, -1, &tstr[0], sz);
	return tstr;
}

template<typename DummyType>
std::string ToCString(const TCHAR* psz, size_t len)
{
	int sz = WideCharToMultiByte(CP_ACP, 0, psz, -1, NULL, 0, NULL, FALSE);
	std::string str(sz - 1, _T(' '));
	WideCharToMultiByte(CP_ACP, 0, psz, -1, &str[0], sz, NULL, FALSE);
	return str;
}		

inline std::tstring ToTString(const char* psz)
{
	return ToTString<float>(psz, strlen(psz));
}

inline std::tstring ToTString(const std::string& str)
{
	return ToTString<float>(str.c_str(), str.length());
}

inline std::string ToCString(const TCHAR* psz)
{
	return ToCString<float>(psz, _tcslen(psz));
}		

inline std::string ToCString(const std::tstring& tstr)
{
	return ToCString<float>(tstr.c_str(), tstr.length());
}		

#define T(text)	std::tstring(_T(text))

#else // _UNICODE

inline std::tstring ToTString(const char* psz)
{
	return std::tstring(psz);
}

inline const std::tstring& ToTString(const std::string& str)
{
	return str;
}

inline std::string ToCString(const TCHAR* psz)
{
	return std::string(psz);
}		

inline const std::string& ToCString(const std::tstring& tstr)
{
	return tstr;
}		

#define T(text)	std::string(_T(text))

#endif // _UNICODE

#ifndef _
#define _(text) T(text)
#endif