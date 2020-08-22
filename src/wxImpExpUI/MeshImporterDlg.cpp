///////////////////////////////////////////////////////////////////////////////
// Name:        MeshImporterDlg.cpp
// Purpose:     Implementation of class wxMeshImporterDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "MeshImporterDlgInput.meta"
#include "MeshImporterDlgOutput.meta"
#include "FormatMsg.meta"

// wxImpExpUI headers
#include "imp3ds.xpm"
#include "ImpExpUITools.h"
#include "ImpExpHelpMenu.h"
#include "MeshImporterDlg.h"
#include "SpaceTransformImpDlg.h"
#include "SpaceTransformTools.h"
#include "OptionsDlg.h"




////////////////////////////////////////////////////////////////////////////////
// wxMeshImporterDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxMeshImporterDlg::wxMeshImporterDlg(wxWindow* parent, TMeshImporterDlgInput& dlgInput, 
								   TMeshImporterDlgOutput& dlgOutput)
: wxFB_MeshImporterDlg(parent) 
{
	m_dlgInput = &dlgInput;
	m_dlgOutput = &dlgOutput;

    // set the dialog icon
    // SetIcon(wxIcon(imp3ds_xpm));

	// setup layout
	SetMinSize(GetSize());
}

// Dtor
wxMeshImporterDlg::~wxMeshImporterDlg()
{
}

// Dialog data transfer (input data file -> dialog controls)
bool wxMeshImporterDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// set the window's title
	if(m_dlgInput->GetFileFormat() == _T("MSH"))
		SetTitle(_T("Kerrax Compiled Mesh Importer"));
	else if(m_dlgInput->GetFileFormat() == _T("MRM"))
		SetTitle(_T("Kerrax Multi-Resolution Mesh Importer"));
	else if(m_dlgInput->GetFileFormat() == _T("ZEN"))
		SetTitle(_T("Kerrax ZenGin World Importer"));

	// setup the "File Properties" section
	m_textFileName->SetValue(m_dlgInput->GetImportFileName());
	int nFileNameLen = (int) m_textFileName->GetValue().length();
	m_textFileName->SetSelection(nFileNameLen, nFileNameLen);
	m_textFileSize->SetValue(FileSizeToString(m_dlgInput->GetImportFileSize()));

	// setup the "Do you want to:" section
	int curSceneMode = m_dlgInput->GetCurrentSceneMode();
	bool mergeScene = false;
	pConfig->Read(_T("3dsImp/MergeScene"), &mergeScene, mergeScene);
	if(curSceneMode == CURSCN_REPLACE_SCENE && mergeScene)
		curSceneMode = CURSCN_MERGE_SCENE;
	if(curSceneMode == CURSCN_MERGE_SCENE && !mergeScene)
		curSceneMode = CURSCN_REPLACE_SCENE;

	if(curSceneMode == CURSCN_REPLACE_SCENE )
	{	
		m_radioReplaceScene->SetValue(true);
	}
	else if(curSceneMode == CURSCN_MERGE_SCENE)
	{
		m_radioMergeScene->SetValue(true);
	}
	
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
	m_dlgOutput->SetContinueImport(false);
	return true;
}

// Dialog data transfer (dialog controls -> output data file)
bool wxMeshImporterDlg::TransferDataFromWindow()
{
	wxConfigBase *pConfig = wxConfigBase::Get();

	// read data from the "Do you want to:" section
	if(m_radioReplaceScene->GetValue())
	{	
		m_dlgOutput->SetCurrentSceneMode(CURSCN_REPLACE_SCENE);
		pConfig->Write(_T("3dsImp/MergeScene"), false);
	}
	else if(m_radioMergeScene->GetValue())
	{
		m_dlgOutput->SetCurrentSceneMode(CURSCN_MERGE_SCENE);
		pConfig->Write(_T("3dsImp/MergeScene"), true);
	}

	// read data from the "Information Window" section
	bool showInfoWnd = m_checkShowInfoWnd->GetValue();
	bool autoClose = m_checkAutoClose->GetValue();
	int timeout = m_spinTimeout->GetValue();
	pConfig->Write(_T("InfoWnd/Show"), showInfoWnd);
	pConfig->Write(_T("InfoWnd/AutoClose"), autoClose);
	pConfig->Write(_T("InfoWnd/Timeout"), timeout);

	// close dialog
	m_dlgOutput->SetContinueImport(true);
	return true;
}

// Command buttons
void wxMeshImporterDlg::OnImport(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wxMeshImporterDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

void wxMeshImporterDlg::OnHelp(wxCommandEvent& event)
{
	wxImpExpHelpMenu menu;
	PopupMenu(&menu);
}

// Space transform button clicked
void wxMeshImporterDlg::OnSpaceTransform(wxCommandEvent& event)
{
	wxSpaceTransformImpDlg dlg(this, m_dlgOutput->GetSpaceTransform());
	dlg.ShowModal();
	UpdateSpaceTransformButton();
}

void wxMeshImporterDlg::UpdateSpaceTransformButton()
{
	float scaleCoef = m_dlgOutput->GetSpaceTransform().GetSystemUnitsPerFileUnit();
	wxString text = FormatMsg1(std::tstring(_("Scale: %1")), FLOAT_TO_STRING(scaleCoef));
	m_buttonSpaceTransform->SetLabel(text);
}

void wxMeshImporterDlg::OnShowInfoWnd( wxCommandEvent& event )
{
	bool bEnableAutoClose = m_checkShowInfoWnd->IsChecked();
	m_checkAutoClose->Enable(bEnableAutoClose);
	bool bEnableTimeout = bEnableAutoClose && m_checkAutoClose->IsChecked();
	m_staticTimeout->Enable(bEnableTimeout);
	m_spinTimeout->Enable(bEnableTimeout);
}

void wxMeshImporterDlg::OnAutoClose( wxCommandEvent& event )
{
	bool bEnableTimeout = m_checkAutoClose->IsChecked();
	m_staticTimeout->Enable(bEnableTimeout);
	m_spinTimeout->Enable(bEnableTimeout);
}

// Options button clicked
void wxMeshImporterDlg::OnOptions(wxCommandEvent& event)
{
	wxOptionsDlg dlg(this);
	dlg.ShowModal();
}