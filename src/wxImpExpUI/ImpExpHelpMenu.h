///////////////////////////////////////////////////////////////////////////////
// Name:        ImpExpHelpMenu.h
// Purpose:     Declaration of class wxImpExpHelpMenu.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __ImpExpHelpMenu__
#define __ImpExpHelpMenu__

class wxImpExpHelpMenu : public wxMenu
{
public:
	wxImpExpHelpMenu();

protected:
	virtual void OnAboutPlugins( wxCommandEvent& event );
	virtual void OnContents( wxCommandEvent& event );
};

#endif // __ImpExpHelpMenu__