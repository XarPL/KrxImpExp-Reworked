///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_ErrBox.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Displays a modal message box containing the message string and an OK button
#define SHOW_ERROR_BOX(titl, msg)	\
	messageBox (msg) title:(titl)

