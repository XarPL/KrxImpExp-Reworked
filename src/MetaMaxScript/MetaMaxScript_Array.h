///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Array.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
function AppendArray arr newval =
(
	if heapFree < 500000 then heapSize += 1000000
	append arr (newval)
)

// Array of items
#define TARRAY(itemtype)                Array
#define EMPTY_ARRAY(itemtype)           HASH()

// Get size of array
#define SIZE(arr)                		((arr).count)

// Get array item by zero-based index
#define GET_ELEM(arr, index)         	((arr)[index + 1])

// Set array item by zero-based index
#define SET_ELEM(arr, index, newval) 	arr[index + 1] = (newval)

// Append an item to array
#define APPEND(arr, newval)    	   		AppendArray arr (newval)

// Allocate space for appending items
#define RESERVE(arr, count)
