///////////////////////////////////////////////////////////////////////////////
// Name:        MetaCpp_ErrBox.h
// Purpose:     Macroses to use when compiling plugins in C++ language
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Displays a modal message box containing the message string and an OK button
#define SHOW_ERROR_BOX(titl, msg)	\
	::MessageBox(NULL, (msg).c_str(), (titl).c_str(), \
	MB_OK | MB_ICONERROR | MB_TASKMODAL);

