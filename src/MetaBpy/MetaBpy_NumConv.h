///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_NumConv.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 7, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Macroses for conversion
#define BOOL_TO_INT(b)         (bool_to_int(b))
#define BOOL_TO_FLOAT(b)       (bool_to_float(b))
#define BOOL_TO_STRING(b)      (bool_to_string(b))
#define INT_TO_BOOL(i)         (int_to_bool(i))
#define INT_TO_FLOAT(i)        (int_to_float(i))
#define INT_TO_STRING(i)       (int_to_string(i))
#define FLOAT_TO_BOOL(f)       (float_to_bool(f))
#define FLOAT_TO_INT(f)        (float_to_int(f))
#define FLOAT_TO_STRING(f)     (float_to_string(f))
#define STRING_TO_BOOL(s)      (string_to_bool(s))
#define STRING_TO_INT(s)       (string_to_int(s))
#define STRING_TO_FLOAT(s)     (string_to_float(s))
