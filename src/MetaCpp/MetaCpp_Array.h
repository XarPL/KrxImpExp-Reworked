///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_Array.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Array of items
#define TARRAY(itemtype)                   std::vector<itemtype>
#define EMPTY_ARRAY(itemtype)              std::vector<itemtype>()

// Get size of array
#define SIZE(arr)        	        	((int)(arr).size())

// Get array item by zero-based index
#define GET_ELEM(arr, index)         	((arr)[index])

// Set array item by zero-based index
#define SET_ELEM(arr, index, newval)  	arr[index] = (newval);

// Append an item to array
#define APPEND(arr, newval)    			arr.push_back(newval);

// Allocate space for appending items
#define RESERVE(arr, count)				arr.reserve(count);

// If argument is an array then it must be transferred by reference to speed up
template<typename T>
struct FC<std::vector<T> >
{
	typedef std::vector<T>& ArgType;
};
