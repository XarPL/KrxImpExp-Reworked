///////////////////////////////////////////////////////////////////////////////
// Name:        MatRenParamsDlg.cpp
// Purpose:     Implementation of class wxMatRenParamsDlg.
// Author:      Vitaly Baranov
// Created:     June 1, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// Meta headers
#include "MatRenParams.meta"

// wxImpExpUI headers
#include "MatRenParamsDlg.h"
#include "MatRenTools.h"




////////////////////////////////////////////////////////////////////////////////
// wxMatRenParamsDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxMatRenParamsDlg::wxMatRenParamsDlg(wxWindow* parent)
: wxFB_MatRenParamsDlg(parent)
{
	m_matRenParams = new TMatRenParams;

	// setup layout
	SetMinSize(GetSize());
}

// Dtor
wxMatRenParamsDlg::~wxMatRenParamsDlg()
{
	if(m_matRenParams != NULL)
		delete m_matRenParams;
}

// Dialog data transfer
bool wxMatRenParamsDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();
	wxString matLibIniPath = _T("");
	pConfig->Read(_T("3dsExp/MatLibIni"), &matLibIniPath, matLibIniPath);
	m_textMatLibIniPath->SetValue(matLibIniPath);

	m_matRenParams->LoadTextFile(std::tstring(GetMatRenParamsPath()));

	float width = float (m_listKnownMaterials->GetClientSize().x);
	m_listKnownMaterials->InsertColumn(0, _("#"), wxLIST_FORMAT_LEFT, int(width * 0.1));
	m_listKnownMaterials->InsertColumn(1, _("Material"),   wxLIST_FORMAT_LEFT, int(width * 0.4));
	m_listKnownMaterials->InsertColumn(2, _("Texture"),  wxLIST_FORMAT_LEFT, int(width * 0.49));
	UpdateListKnownMaterials();

	m_checkAutoNames->SetValue(m_matRenParams->GetAutoNames());
	return true;
}

bool wxMatRenParamsDlg::TransferDataFromWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();
	wxString matLibIniPath = m_textMatLibIniPath->GetValue();
	pConfig->Write(_T("3dsExp/MatLibIni"), matLibIniPath);
	m_matRenParams->SetAutoNames(m_checkAutoNames->GetValue());

	m_matRenParams->SaveTextFile(std::tstring(GetMatRenParamsPath()));
	return true;
}

// Command buttons
void wxMatRenParamsDlg::OnOK(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wxMatRenParamsDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

void wxMatRenParamsDlg::OnBrowseMatLibIni( wxCommandEvent& event )
{
	wxString matLibIniPath = m_textMatLibIniPath->GetValue();
	wxFileDialog filedlg(this, _("Specify \"matlib.ini\""), _T(""), matLibIniPath, _T("matlib.ini|matlib.ini"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if(filedlg.ShowModal() != wxID_OK)
		return;
	wxString path = filedlg.GetPath();
	m_textMatLibIniPath->SetValue(path);
}

void wxMatRenParamsDlg::OnLoadMaterialFilter( wxCommandEvent& event )
{
	wxString matLibIniPath = m_textMatLibIniPath->GetValue();
	if(matLibIniPath.IsEmpty() || !wxFile::Exists(matLibIniPath))
	{
		wxString msg = _("Specify path to the \"matlib.ini\" file at first.");
		wxMessageDialog msgdlg(NULL, msg, _T("KrxImpExpUI"), wxOK|wxICON_EXCLAMATION);
		msgdlg.ShowModal();
		return;
	}
	m_matRenParams->LoadMaterialFilter(std::tstring(matLibIniPath));
	UpdateListKnownMaterials();
}

// Update list of known materials
void wxMatRenParamsDlg::UpdateListKnownMaterials()
{
	m_listKnownMaterials->DeleteAllItems();
	for(int i = 0; i < m_matRenParams->GetNumMaterials(); ++i)
	{
		wxString str;
		str.Printf(_T("%d"), i + 1);
		m_listKnownMaterials->InsertItem(i, wxString(str));
		m_listKnownMaterials->SetItem(i, 1, m_matRenParams->GetName(i));
		m_listKnownMaterials->SetItem(i, 2, m_matRenParams->GetTexture(i));
	}
}