///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_Bit.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

static int CharAsInt(const std::tstring& s)
{
	if(s.length() == 0)
		return 0;
	TCHAR ch = s[0];
	int code = ch & 0xFF;
	return code;
}

static std::tstring IntAsChar(int code)
{
	TCHAR ch = (TCHAR) (code & 0xFF);
	if(ch == 0)
		return std::tstring();
	else
		return std::tstring(1, ch);
}

static std::tstring HexForm(int i)
{
	TCHAR buf[64];
	_stprintf(buf, _T("0x%X"), i);
	return buf;
}

// Bit operations
#define BIT_AND(a, b)	((a) & (b))
#define BIT_OR(a, b)	((a) | (b))
#define BIT_NOT(a)		(~(a))

// Returns the integer value corresponding to the first character of the string. 
#define CHAR_AS_INT(c)	(CharAsInt(c))

// Returns a string result of length 1 containing the character 
// corresponding to the integer value. 
// Only the lowest order 8-bits of the integer are used. 
#define INT_AS_CHAR(c)	(IntAsChar(c))

// Hex representation
#define HEXFORM(i)		(HexForm(i))