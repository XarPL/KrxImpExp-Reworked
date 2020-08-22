///////////////////////////////////////////////////////////////////////////////
// Name:        3DSExporterDlg.cpp
// Purpose:     Implementation of class wx3DSExporterDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "3dsExporterDlgInput.meta"
#include "3dsExporterDlgOutput.meta"
#include "MatRenParams.meta"
#include "FormatMsg.meta"

// wxImpExpUI headers
#include "exp3ds.xpm"
#include "ImpExpUITools.h"
#include "ImpExpHelpMenu.h"
#include "3DSExporterDlg.h"
#include "SpaceTransformExpDlg.h"
#include "SpaceTransformTools.h"
#include "MatRenTools.h"
#include "MatRenParamsDlg.h"
#include "OptionsDlg.h"




////////////////////////////////////////////////////////////////////////////////
// wx3DSExporterDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wx3DSExporterDlg::wx3DSExporterDlg(wxWindow* parent, T3DSExporterDlgInput& dlgInput, 
								   T3DSExporterDlgOutput& dlgOutput)
: wxFB_3DSExporterDlg(parent) 
{
	m_dlgInput = &dlgInput;
	m_dlgOutput = &dlgOutput;

    // set the dialog icon
    SetIcon(wxIcon(exp3ds_xpm));

	// setup layout
	SetMinSize(GetSize());
}

// Dtor
wx3DSExporterDlg::~wx3DSExporterDlg()
{
}


// Dialog data transfer (input data file -> dialog controls)
bool wx3DSExporterDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();
	
	// set the window's title
	SetTitle(_T("Kerrax 3D Studio Mesh Exporter"));

	// setup the "File Properties" section
	m_textFileName->SetValue(m_dlgInput->GetExportFileName());
	int nFileNameLen = (int) m_textFileName->GetValue().length();
	m_textFileName->SetSelection(nFileNameLen, nFileNameLen);

	// setup the "Objects" section
	std::vector<std::tstring> sceneObjects = m_dlgInput->GetSceneObjects();
	std::vector<std::tstring> selectedObjects = m_dlgInput->GetSelectedObjects();
	for(size_t i = 0; i < sceneObjects.size(); ++i)
		m_listObjects->Append(sceneObjects[i]);

	if(selectedObjects.size() > 0)
		m_listObjects->SetFirstItem(m_listObjects->FindString(selectedObjects[0]));

	for(size_t j = 0; j < selectedObjects.size(); ++j)
	{
		m_listObjects->Check(m_listObjects->FindString(selectedObjects[j]), true);
	}
	OnObjectSelected(wxCommandEvent());

	// setup the "Coordinate System" section
	bool useLocalCS = true;
	pConfig->Read(_T("3dsExp/UseLocalCS"), &useLocalCS, useLocalCS);
	if(useLocalCS)
		m_radioLocalCS->SetValue(true);
	else
		m_radioWorldCS->SetValue(true);

	// setup the "Material Renaming" section
	wxString matRenParamsPath = _T("");
	pConfig->Read(_T("3dsExp/MatRenParams"), &matRenParamsPath, matRenParamsPath);
	m_checkRenameMaterials->SetValue(!matRenParamsPath.IsEmpty());
	m_buttonMatRenParams->Enable(m_checkRenameMaterials->GetValue());

	// update space transform button
	ReadSpaceTransformConfig(m_dlgOutput->GetSpaceTransform());
	UpdateSpaceTransformButton();

	// setup the "Information Window" section
	bool showInfoWnd = true;
	bool autoClose = true;
	int timeout = 5;
	pConfig->Read(_T("InfoWnd/Show"), &showInfoWnd, showInfoWnd);
	pConfig->Read(_T("InfoWnd/AutoClose"), &autoClose, autoClose);
	pConfig->Read(_T("InfoWnd/Timeout"), &timeout, timeout);
	m_checkShowInfoWnd->SetValue(showInfoWnd);
	OnShowInfoWnd(wxCommandEvent());
	m_checkAutoClose->SetValue(autoClose);
	OnAutoClose(wxCommandEvent());
	m_spinTimeout->SetValue(timeout);

	// setup default output values
	m_dlgOutput->SetContinueExport(false);
	return true;
}

// Dialog data transfer (dialog controls -> output data file)
bool wx3DSExporterDlg::TransferDataFromWindow()
{
	wxConfigBase *pConfig = wxConfigBase::Get();

	// read data from the "Objects" section
	std::vector<std::tstring> selectedObjects;
	for(size_t j = 0; j < m_listObjects->GetCount(); ++j)
		if(m_listObjects->IsChecked((unsigned int)j))
			selectedObjects.push_back(std::tstring(m_listObjects->GetString((int)j)));
	m_dlgOutput->SetSelectedObjects(selectedObjects);

	// read data from the "Coordinate System" section
	bool useLocalCS = m_radioLocalCS->GetValue();
	m_dlgOutput->SetUseLocalCS(useLocalCS);
	pConfig->Write(_T("3dsExp/UseLocalCS"), useLocalCS);

	// read data from the "Material Renaming" section
	wxString matRenParamsPath = (m_checkRenameMaterials->GetValue() ? GetMatRenParamsPath() : _T(""));
	m_dlgOutput->SetMatRenParamsPath(std::tstring(matRenParamsPath));
	pConfig->Write(_T("3dsExp/MatRenParams"), matRenParamsPath);

	// read data from the "Information Window" section
	bool showInfoWnd = m_checkShowInfoWnd->GetValue();
	bool autoClose = m_checkAutoClose->GetValue();
	int timeout = m_spinTimeout->GetValue();
	pConfig->Write(_T("InfoWnd/Show"), showInfoWnd);
	pConfig->Write(_T("InfoWnd/AutoClose"), autoClose);
	pConfig->Write(_T("InfoWnd/Timeout"), timeout);

	// close dialog
	m_dlgOutput->SetContinueExport(true);
	return true;
}

// Command buttons
void wx3DSExporterDlg::OnExport(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wx3DSExporterDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

void wx3DSExporterDlg::OnHelp(wxCommandEvent& event)
{
	wxImpExpHelpMenu menu;
	PopupMenu(&menu);
}

// Space transform button clicked
void wx3DSExporterDlg::OnSpaceTransform(wxCommandEvent& event)
{
	wxSpaceTransformExpDlg dlg(this, m_dlgOutput->GetSpaceTransform());
	dlg.ShowModal();
	UpdateSpaceTransformButton();
}

void wx3DSExporterDlg::UpdateSpaceTransformButton()
{
	float scaleCoef = m_dlgOutput->GetSpaceTransform().GetFileUnitsPerSystemUnit();
	wxString text = wxString(FormatMsg1(std::tstring(_("Scale: %1")), FLOAT_TO_STRING(scaleCoef)));
	m_buttonSpaceTransform->SetLabel(text);
}

void wx3DSExporterDlg::OnRenameMaterials( wxCommandEvent& event )
{
	m_buttonMatRenParams->Enable(m_checkRenameMaterials->GetValue());
}

void wx3DSExporterDlg::OnMatRenParams( wxCommandEvent& event )
{
	wxMatRenParamsDlg dlg(this);
	dlg.ShowModal();
}

void wx3DSExporterDlg::OnObjectDClicked( wxCommandEvent& event )
{
	int nPos = event.GetInt();
	m_listObjects->Check(nPos, !m_listObjects->IsChecked(nPos));
	OnObjectSelected(wxCommandEvent());
}

void wx3DSExporterDlg::OnObjectSelected( wxCommandEvent& event )
{
	int numSelected = 0;
	for(unsigned int i = 0; i < m_listObjects->GetCount(); ++i)
	{
		if(m_listObjects->IsChecked(i)) 
			++numSelected;
	}
	wxString strNumSelected;
	strNumSelected.Printf(_T("%d"), numSelected);
	m_textNumSelected->SetValue(strNumSelected);
}

void wx3DSExporterDlg::OnSelectAll( wxCommandEvent& event )
{
	for(unsigned int i = 0; i < m_listObjects->GetCount(); ++i)
	{
		m_listObjects->Check(i, true);
	}
	OnObjectSelected(wxCommandEvent());
}

void wx3DSExporterDlg::OnSelectNone( wxCommandEvent& event )
{
	for(unsigned int i = 0; i < m_listObjects->GetCount(); ++i)
	{
		m_listObjects->Check(i, false);
	}
	OnObjectSelected(wxCommandEvent());
}

void wx3DSExporterDlg::OnShowInfoWnd( wxCommandEvent& event )
{
	bool bEnableAutoClose = m_checkShowInfoWnd->IsChecked();
	m_checkAutoClose->Enable(bEnableAutoClose);
	bool bEnableTimeout = bEnableAutoClose && m_checkAutoClose->IsChecked();
	m_staticTimeout->Enable(bEnableTimeout);
	m_spinTimeout->Enable(bEnableTimeout);
}

void wx3DSExporterDlg::OnAutoClose( wxCommandEvent& event )
{
	bool bEnableTimeout = m_checkAutoClose->IsChecked();
	m_staticTimeout->Enable(bEnableTimeout);
	m_spinTimeout->Enable(bEnableTimeout);
}

// Options button clicked
void wx3DSExporterDlg::OnOptions(wxCommandEvent& event)
{
	wxOptionsDlg dlg(this);
	dlg.ShowModal();
}