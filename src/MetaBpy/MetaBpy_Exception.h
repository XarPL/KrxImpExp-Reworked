///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Exception.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 11, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#define TRY 				try: INDENT
#define END_TRY				END_INDENT
#define CATCH 				except RuntimeError as ex: INDENT
#define END_CATCH			END_INDENT

#define CURRENT_EXCEPTION	(ex.args[0] if (len(ex.args) >= 1 and type(ex.args[0]) == str) else str(ex.args))
#define THROW(message)		raise RuntimeError(message)
#define THROW_AGAIN			raise

