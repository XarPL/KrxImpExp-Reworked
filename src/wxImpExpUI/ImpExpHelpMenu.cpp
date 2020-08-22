///////////////////////////////////////////////////////////////////////////////
// Name:        ImpExpHelpMenu.cpp
// Purpose:     Implementation of class wxImpExpHelpMenu.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"
#include "ImpExpHelpMenu.h"
#include "AboutDlg.h"
#include "ImpExpUITools.h"

enum
{
	wxID_ABOUT_PLUGINS	= 100,
	wxID_CONTENTS       = 101,
};

wxImpExpHelpMenu::wxImpExpHelpMenu()
{
	Append(wxID_CONTENTS, _("Contents"));
	Connect(wxID_CONTENTS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(wxImpExpHelpMenu::OnContents), NULL, this);

	AppendSeparator();

	Append(wxID_ABOUT_PLUGINS, _("About these plugins"));
	Connect(wxID_ABOUT_PLUGINS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(wxImpExpHelpMenu::OnAboutPlugins), NULL, this);
}

void wxImpExpHelpMenu::OnAboutPlugins(wxCommandEvent& event)
{
	wxAboutDlg dlg(NULL);
	dlg.ShowModal();
}

void wxImpExpHelpMenu::OnContents(wxCommandEvent& event)
{
	ShowHelp(_T("index"));
}
