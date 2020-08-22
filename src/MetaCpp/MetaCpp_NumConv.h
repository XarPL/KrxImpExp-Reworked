///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_NumConv.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static int BoolToInt(bool b)
{
	return (int)b;
}

static float BoolToFloat(bool b)
{
	return (float)b;
}

static std::tstring BoolToString(bool b)
{
	return std::tstring(b ? _T("true") : _T("false"));
}

static bool IntToBool(int i)
{
	return (i != 0);
}

static float IntToFloat(int i)
{
	return (float)i;
}

static std::tstring IntToString(int i)
{
	TCHAR buf[64];
	_itot(i, buf, 10);
	return buf;
}

static bool FloatToBool(float f)
{
	return (f != 0.0f);
}	

static int FloatToInt(float f)
{
	return (int) floorf(f + 0.5f);
}	

static std::tstring FloatToString(float f)
{
	TCHAR buf[128];
	_stprintf(buf, _T("%g"), f);
	for(TCHAR* p = buf; *p != 0; ++p)
	{
		if(*p == _T(','))
			*p = _T('.');
	}		
	return std::tstring(buf);
}
		
static bool StringToBool(const std::tstring& str)
{
	if(str == _T("true") || str == _T("True") || str == _T("TRUE")
		|| str == _T("yes")  || str == _T("Yes")  || str == _T("YES"))
	{
		return true;
	}
	return false;
}

static int StringToInt(const std::tstring& str)
{
	TCHAR* endptr;
	int i = (int) _tcstol(str.c_str(), &endptr, 10);
	int count = (int) (endptr - str.c_str());
	if(count != str.length() || i == LONG_MAX || i == LONG_MIN)
	{
		return INVALID_INT;
	}
	return i;
}

static float StringToFloat(const std::tstring& str)
{
	TCHAR* endptr;
	float f = (float) _tcstod(str.c_str(), &endptr);
	int count = (int) (endptr - str.c_str());
	if(count != str.length() || !_finite(f))
	{
		std::tstring str2 = str;
		for(size_t i = 0; i < str2.length(); ++i)
		{
			if(str2[i] == _T('.'))
				str2[i] = _T(',');
		}
		f = (float) _tcstod(str2.c_str(), &endptr);
		count = (int) (endptr - str2.c_str());
		if(count != str2.length() || !_finite(f))
			return INVALID_FLOAT;
	}
	return f;
}

// Macroses for conversion
#define BOOL_TO_INT(b)         (BoolToInt(b))
#define BOOL_TO_FLOAT(b)       (BoolToFloat(b))
#define BOOL_TO_STRING(b)      (BoolToString(b))
#define INT_TO_BOOL(i)         (IntToBool(i))
#define INT_TO_FLOAT(i)        (IntToFloat(i))
#define INT_TO_STRING(i)       (IntToString(i))
#define FLOAT_TO_BOOL(f)       (FloatToBool(f))
#define FLOAT_TO_INT(f)        (FloatToInt(f))
#define FLOAT_TO_STRING(f)     (FloatToString(f))
#define STRING_TO_BOOL(str)    (StringToBool(str))
#define STRING_TO_INT(str)     (StringToInt(str))
#define STRING_TO_FLOAT(str)   (StringToFloat(str))
