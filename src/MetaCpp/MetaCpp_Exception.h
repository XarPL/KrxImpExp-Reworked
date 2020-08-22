///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_Exception.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#define TRY try {
#define END_TRY }

#define CATCH catch(const std::tstring& currentException) {const std::tstring& unusedLocalVariableToPreventWarning = currentException;
#define END_CATCH }

#define CURRENT_EXCEPTION    (currentException)

#define THROW(message)       throw (message);
#define THROW_AGAIN          throw;

