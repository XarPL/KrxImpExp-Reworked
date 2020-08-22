///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_NumConv.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
function BoolToInt b = 
(
	if b then 
		return 1 
	else 
		return 0
)

function BoolToFloat b =
(
	if b then 
		return 1.0 
	else 
		return 0.0
)	
	
function BoolToString b =
(
	if b then 
		return "true" 
	else 
		return "false"
)	

function IntToBool i =
(
	return (i != 0)
)

function IntToFloat i =
(
	return (i as Float)
)

function IntToString i =
(
	return (i as String)
)
	
function FloatToBool f =
(
	return (f != 0.0)
)

function FloatToInt f =
(
	return (floor(f + 0.5) as Integer)
)
	
function FloatToString f =
(
	return (f as String)
)
			
function StringToBool str =
(
	if str == "true" or str == "True" or str == "TRUE" \
	or str == "yes"  or str == "Yes"  or str == "YES" then
		return true
	return false
)

function StringToInt str =
(
	return (str as Integer)
)

function StringToFloat str =
(
	return (str as Float)
)

// Macroses for conversion
#define BOOL_TO_INT(b)         BoolToInt(b)
#define BOOL_TO_FLOAT(b)       BoolToFloat(b)
#define BOOL_TO_STRING(b)      BoolToString(b)
#define INT_TO_BOOL(i)         IntToBool(i)
#define INT_TO_FLOAT(i)        IntToFloat(i)
#define INT_TO_STRING(i)       IntToString(i)
#define FLOAT_TO_BOOL(f)       FloatToBool(f)
#define FLOAT_TO_INT(f)        FloatToInt(f)
#define FLOAT_TO_STRING(f)     FloatToString(f)
#define STRING_TO_BOOL(str)    StringToBool(str)
#define STRING_TO_INT(str)     StringToInt(str)
#define STRING_TO_FLOAT(str)   StringToFloat(str)

