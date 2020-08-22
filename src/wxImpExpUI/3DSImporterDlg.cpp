///////////////////////////////////////////////////////////////////////////////
// Name:        3DSImporterDlg.cpp
// Purpose:     Implementation of class wx3DSImporterDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "3dsImporterDlgInput.meta"
#include "3dsImporterDlgOutput.meta"
#include "FormatMsg.meta"

// wxImpExpUI headers
#include "imp3ds.xpm"
#include "ImpExpUITools.h"
#include "ImpExpHelpMenu.h"
#include "3DSImporterDlg.h"
#include "SpaceTransformImpDlg.h"
#include "SpaceTransformTools.h"
#include "OptionsDlg.h"




////////////////////////////////////////////////////////////////////////////////
// wx3DSImporterDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wx3DSImporterDlg::wx3DSImporterDlg(wxWindow* parent, T3DSImporterDlgInput& dlgInput, 
								   T3DSImporterDlgOutput& dlgOutput)
: wxFB_3DSImporterDlg(parent) 
{
	m_dlgInput = &dlgInput;
	m_dlgOutput = &dlgOutput;

    // set the dialog icon
    SetIcon(wxIcon(imp3ds_xpm));

	// setup layout
	m_staticThreshold->SetMinSize(wxSize(m_staticTimeout->GetSize().x, -1));
	SetMinSize(GetSize());
}

// Dtor
wx3DSImporterDlg::~wx3DSImporterDlg()
{
}

// Dialog data transfer (input data file -> dialog controls)
bool wx3DSImporterDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// set the window's title
	SetTitle(_T("Kerrax 3D Studio Mesh Importer"));

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
	else if(curSceneMode == CURSCN_REPLACE_SLOT)
	{
		m_radioReplaceSlot->SetValue(true);
	}
	else if(curSceneMode == CURSCN_REPLACE_BONE)
	{
		m_radioReplaceBone->SetValue(true);
	}
	OnCurSceneModeChanged(wxCommandEvent());
	
	// setup slots and bones choices
	int numSlots = FillWxChoiceWithStrings(m_choiceSlots, m_dlgInput->GetSlots(), m_dlgInput->GetSelectedSlot());
	m_radioReplaceSlot->Enable(numSlots != 0);
	int numBones = FillWxChoiceWithStrings(m_choiceBones, m_dlgInput->GetBones(), m_dlgInput->GetSelectedBone());
	m_radioReplaceBone->Enable(numBones != 0);

	// update space transform button
	ReadSpaceTransformConfig(m_dlgOutput->GetSpaceTransform());
	UpdateSpaceTransformButton();

	// setup the "Weld Vertices" section
	bool weldVertices = false;
	double threshold = 0.1;
	pConfig->Read(_T("3dsImp/Threshold"), &threshold, threshold);
	m_checkWeldVertices->SetValue(weldVertices);
	OnWeldVertices(wxCommandEvent());
	m_spinThreshold->SetRange(-100, 100);
	m_spinThreshold->SetValue(0);
	m_textThreshold->SetValue(ThresholdToString(threshold));

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
bool wx3DSImporterDlg::TransferDataFromWindow()
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
	else if(m_radioReplaceSlot->GetValue())
	{
		m_dlgOutput->SetCurrentSceneMode(CURSCN_REPLACE_SLOT);
		m_dlgOutput->SetSelectedSlot(std::tstring(m_choiceBones->GetStringSelection()));
	}
	else if(m_radioReplaceBone->GetValue())
	{
		m_dlgOutput->SetCurrentSceneMode(CURSCN_REPLACE_BONE);
		m_dlgOutput->SetSelectedBone(std::tstring(m_choiceBones->GetStringSelection()));
	}

	// read data from the "Weld Vertices" section
	bool weldVertices = m_checkWeldVertices->GetValue();
	float threshold = StringToThreshold(m_textThreshold->GetValue());
	pConfig->Write(_T("3dsImp/Threshold"), threshold);
	m_dlgOutput->SetWeldVertices(weldVertices);
	m_dlgOutput->SetThreshold(threshold);

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
void wx3DSImporterDlg::OnImport(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wx3DSImporterDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

void wx3DSImporterDlg::OnHelp(wxCommandEvent& event)
{
	wxImpExpHelpMenu menu;
	PopupMenu(&menu);
}

// Space transform button clicked
void wx3DSImporterDlg::OnSpaceTransform(wxCommandEvent& event)
{
	wxSpaceTransformImpDlg dlg(this, m_dlgOutput->GetSpaceTransform());
	dlg.ShowModal();
	UpdateSpaceTransformButton();
}

void wx3DSImporterDlg::UpdateSpaceTransformButton()
{
	float scaleCoef = m_dlgOutput->GetSpaceTransform().GetSystemUnitsPerFileUnit();
	wxString text = FormatMsg1(std::tstring(_("Scale: %1")), FLOAT_TO_STRING(scaleCoef));
	m_buttonSpaceTransform->SetLabel(text);
}

// Enable controls depending on other controls
void wx3DSImporterDlg::OnCurSceneModeChanged( wxCommandEvent& event )
{
	bool r = (m_radioReplaceBone->GetValue());
	m_choiceBones->Enable(r);
	m_staticSelectBone->Enable(r);
	bool s = (m_radioReplaceSlot->GetValue());
	m_choiceSlots->Enable(s);
	m_staticSelectSlot->Enable(s);
}

void wx3DSImporterDlg::OnWeldVertices( wxCommandEvent& event )
{
	bool bEnableThreshold = m_checkWeldVertices->IsChecked();
	m_staticThreshold->Enable(bEnableThreshold);
	m_textThreshold->Enable(bEnableThreshold);
	m_spinThreshold->Enable(bEnableThreshold);
}

void wx3DSImporterDlg::OnShowInfoWnd( wxCommandEvent& event )
{
	bool bEnableAutoClose = m_checkShowInfoWnd->IsChecked();
	m_checkAutoClose->Enable(bEnableAutoClose);
	bool bEnableTimeout = bEnableAutoClose && m_checkAutoClose->IsChecked();
	m_staticTimeout->Enable(bEnableTimeout);
	m_spinTimeout->Enable(bEnableTimeout);
}

void wx3DSImporterDlg::OnAutoClose( wxCommandEvent& event )
{
	bool bEnableTimeout = m_checkAutoClose->IsChecked();
	m_staticTimeout->Enable(bEnableTimeout);
	m_spinTimeout->Enable(bEnableTimeout);
}

// Called whenever an arrow of threshold spin button is pressed
void wx3DSImporterDlg::OnThresholdSpin( wxSpinEvent& event )
{
	float current_threshold = StringToThreshold(m_textThreshold->GetValue());
	
	float new_threshold = current_threshold + m_spinThreshold->GetValue() * THRESHOLD_STEP;
	if(new_threshold < THRESHOLD_MIN_VALUE)
		new_threshold = THRESHOLD_MIN_VALUE;
	if(new_threshold > THRESHOLD_MAX_VALUE)
		new_threshold = THRESHOLD_MAX_VALUE;
	
	m_spinThreshold->SetValue(0);
	m_textThreshold->SetValue(ThresholdToString(new_threshold));
	m_textThreshold->SetFocus();
	m_textThreshold->SetSelection(-1, -1);
}

// Options button clicked
void wx3DSImporterDlg::OnOptions(wxCommandEvent& event)
{
	wxOptionsDlg dlg(this);
	dlg.ShowModal();
}