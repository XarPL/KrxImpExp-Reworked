///////////////////////////////////////////////////////////////////////////////
// Name:        OptionsDlg.cpp
// Purpose:     Declaration of class wxOptionsDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// wxImpExpUI headers
#include "ImpExpUITools.h"
#include "OptionsDlg.h"




////////////////////////////////////////////////////////////////////////////////
// wxOptionsDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxOptionsDlg::wxOptionsDlg(wxWindow* parent)
: wxFB_OptionsDlg(parent) 
{
	// setup layout
	SetMinSize(GetSize());
}

// Dtor
wxOptionsDlg::~wxOptionsDlg()
{
}


// Dialog data transfer (configuration data -> dialog controls)
bool wxOptionsDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// fill list with supported languages
	wxString curLang = ReadUILangFromConfig();
	wxArrayString arrLangs = GetAllSupportedLanguages();
	m_listLanguages->Clear();
	for(unsigned int i = 0; i < arrLangs.GetCount(); ++i)
	{
		m_listLanguages->Append(arrLangs[i]);
	}
	m_listLanguages->SetStringSelection(curLang);
		
	return true;
}

// Dialog data transfer (dialog controls -> configuration data)
bool wxOptionsDlg::TransferDataFromWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();
	bool bChanges = false;

	// get new user interface language
	wxString curLang = m_listLanguages->GetStringSelection();
	if(curLang != wxEmptyString && curLang != ReadUILangFromConfig())
	{
		WriteUILangToConfig(curLang);
		bChanges = true;
	}

	// show message if some values were changed
	if(bChanges)
	{
		wxMessageDialog msgdlg(this, _("The changes will take effect next time you run one of the plugins."), _("Options"));
		msgdlg.ShowModal();
	}
	return true;
}

// Command buttons
void wxOptionsDlg::OnOK(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wxOptionsDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

