///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Bit.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 10, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Bit operations
#define BIT_AND(a, b)	((a) & (b))
#define BIT_OR(a, b)	((a) | (b))
#define BIT_NOT(a)		(~(a))

// Returns the integer value corresponding to the first character of the string. 
#define CHAR_AS_INT(c)		(ord(c))

// Returns a string result of length 1 containing the character 
// corresponding to the integer value. 
// Only the lowest order 8-bits of the integer are used. 
#define INT_AS_CHAR(c)		(chr(c))

// Hex representation
#define HEXFORM(i)		    ("0x"+hex(i)[2:].upper())
