///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_String.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 7, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Strings
#define TSTRING            
#define EMPTY_STRING                ""

// Invalid string - a special return value for functions
#define INVALID_STRING	     	    None

// Gets string length
#define STRLEN(s)					len(s)

// String concatenation
#define STRCAT(s, s2)			    s += (s2);

// Gets a substring of at most some number of characters from a string beginning from a specified position;
// start is zero-based index of the first extracting character;
// stop is zero-based index of the character after the last extracting character
#define SUBSTR(s, start, stop)		(s)[start:stop]

// Finds first substring from one string in another string
#define STRFIND(s, s2)			    (s).find(s2)

// Value that STRFIND returns if substring was not found
#define NOT_FOUND					-1

// Makes a string upper case
#define UPPER_CASE(s)				uppercase(s)

// Makes a string lower case
#define LOWER_CASE(str)				lowercase(s)

// Compares strings with case sensitive (returns 0 if the strings are equal, 
// -1 if the first string < the second string, 1 if the first string > the second string)
#define STRCMP(s1, s2)		 	    strcmp(s1, s2)

// Compares strings with case insentive (returns 0 if the strings are equal, 
// -1 if the first string < the second string, 1 if the first string > the second string)
#define STRICMP(s1, s2)			    stricmp(s1, s2)

// No effects in Python
#define T(text)	 text
#define _T(text) text
#define _(text)  text
