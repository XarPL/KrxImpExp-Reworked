///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Array.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 10, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Array of items
#define TARRAY(itemtype)
#define EMPTY_ARRAY(itemtype)           []

// Get size of array
#define SIZE(arr)        	        	(len(arr))

// Get array item by zero-based index
#define GET_ELEM(arr, index)         	((arr)[index])

// Set array item by zero-based index
#define SET_ELEM(arr, index, newval)  	arr[index] = (newval)

// Append an item to array
#define APPEND(arr, newval)    			arr.append(newval)

// Allocate space for appending items
#define RESERVE(arr, count)			
