///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Bit.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Bit operations
#define BIT_OR(a, b)		(bit.or (a) (b))
#define BIT_AND(a, b)		(bit.and (a) (b))
#define BIT_NOT(a)		(bit.not (a))

// Returns the integer value corresponding to the first character of the string. 
#define CHAR_AS_INT(c)		(bit.charAsInt(c))

// Returns a string result of length 1 containing the character 
// corresponding to the integer value. 
// Only the lowest order 8-bits of the integer are used. 
#define INT_AS_CHAR(c)		(bit.intAsChar(c))

// Hex representation
#define HEXFORM(i)			("0x" + (StringUtils.UCase (bit.intAsHex (i))))

