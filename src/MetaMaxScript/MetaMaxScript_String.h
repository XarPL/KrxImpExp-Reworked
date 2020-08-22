///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_String.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
function FindStr str str2 =
(
	i = (findString (str) (str2))
	if(i != undefined) then
		i = i - 1
	return i
) 
	
function UCaseStr str = 
(
	local upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	local lower="abcdefghijklmnopqrstuvwxyz" 
	local result = copy str
	for i=1 to result.count do 
	(  
		j=findString lower result[i] 
		if (j != undefined) then
			result[i]=upper[j] 
	)
	return result
)

function LCaseStr str = 
(
	local upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	local lower="abcdefghijklmnopqrstuvwxyz" 
	local result = copy str
	for i=1 to result.count do 
	(  
		j=findString upper result[i] 
		if (j != undefined) then
			result[i]=lower[j] 
	)
	return result
)
	
function CmpStr str1 str2 =
(
	local result
	if str1 == str2 then
		result = 0
	else if str1 < str2 then
		result = -1
	else
		result = 1
	return result
)

function ICmpStr str1 str2 = 
(
	return (CmpStr (UCaseStr str1) (UCaseStr str2))
)

// Strings
#define TSTRING                     String
#define EMPTY_STRING               	""

// Invalid string - a special return value for functions
#define INVALID_STRING				undefined

// Gets string length
#define STRLEN(str)					((str).count)

// String concatenation
#define STRCAT(str, str2)			str = str + (str2)

// Gets a substring of at most some number of characters from a string beginning from a specified position;
// start is zero-based index of the first extracting character;
// stop is zero-based index of the character after the last extracting character
#define SUBSTR(str, start, stop)	(substring (str) ((start) + 1) ((stop) - (start)))

// Finds first substring from one string in another string
#define STRFIND(str, str2)			(FindStr (str) (str2))

// Value that STRFIND returns if substring was not found
#define NOT_FOUND					undefined

// Makes a string upper case
#define UPPER_CASE(str)				(UCaseStr(str))

// Makes a string lower case
#define LOWER_CASE(str)				(LCaseStr(str))

// Compares strings with case sensitive (returns 0 if the strings are equal, 
// -1 if the first string < the second string, 1 if the first string > the second string)
#define STRCMP(str1, str2)			(CmpStr (str1) (str2))

// Compares strings with case insentive (returns 0 if the strings are equal, 
// -1 if the first string < the second string, 1 if the first string > the second string)
#define STRICMP(str1, str2)			(ICmpStr (str1) (str2))

// These macroses have no effects in gmax
#define _T(text)					(text)
#define T(text)						(text)
#define _(text)                     (text)
