///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef META_CPP_H
#define META_CPP_H

// Disable deprecate warnings
#pragma warning(disable : 4996)

// Disable truncation from 'double' to 'float' warnings
// #pragma warning(disable : 4305)

// standard headers
#include <tchar.h>
#include <string>
#include <tstl.h>
#include <vector>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <io.h>
#include <windows.h>

#include "MetaCpp_Var.h"
#include "MetaCpp_ControlFlow.h"
#include "MetaCpp_Function.h"
#include "MetaCpp_Class.h"
#include "MetaCpp_Numeric.h"
#include "MetaCpp_String.h"
#include "MetaCpp_Bit.h"
#include "MetaCpp_Exception.h"
#include "MetaCpp_NumConv.h"
#include "MetaCpp_File.h"
#include "MetaCpp_System.h"
#include "MetaCpp_Array.h"
#include "MetaCpp_ErrBox.h"

#endif // META_CPP_H