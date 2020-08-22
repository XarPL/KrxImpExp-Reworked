///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Exception.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

global g_lastException = ""

#define TRY                 try (
#define END_TRY             )

#define CATCH               catch (local currentException = g_lastException
#define END_CATCH           )

#define CURRENT_EXCEPTION   currentException

#define THROW(msg) 			(g_lastException = msg; throw g_lastException)
#define THROW_AGAIN         (g_lastException = currentException; throw())
