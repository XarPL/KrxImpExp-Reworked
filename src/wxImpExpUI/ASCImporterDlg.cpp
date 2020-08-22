///////////////////////////////////////////////////////////////////////////////
// Name:        ASCImporterDlg.cpp
// Purpose:     Implementation of class wxASCImporterDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "AscImporterDlgInput.meta"
#include "AscImporterDlgOutput.meta"
#include "FormatMsg.meta"

// wxImpExpUI headers
#include "ImpExpUITools.h"
#include "ImpExpHelpMenu.h"
#include "ASCImporterDlg.h"
#include "CheckNotebook.h"
#include "OptionsDlg.h"
#include "SpaceTransformImpDlg.h"
#include "SpaceTransformTools.h"
#include "TimeTransformImpDlg.h"

#include "impasc.xpm"
#include "orc_body.xpm"
#include "orc_walk.xpm"
#include "bow.xpm"
#include "bow_shoot.xpm"
#include "ladder.xpm"


////////////////////////////////////////////////////////////////////////////////
// wxASCImporterDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxASCImporterDlg::wxASCImporterDlg(wxWindow* parent, TASCImporterDlgInput& dlgInput, 
								   TASCImporterDlgOutput& dlgOutput )
: wxFB_ASCImporterDlg(parent) 
{
	m_dlgInput = &dlgInput;
	m_dlgOutput = &dlgOutput;

    // set the dialog icon
    SetIcon(wxIcon(impasc_xpm));

	// setup layout
	Centre();
}

// Dtor
wxASCImporterDlg::~wxASCImporterDlg()
{
}


// Dialog data transfer (input data file -> dialog controls)
bool wxASCImporterDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();
	
	// set the window's title
	SetTitle(_T("Kerrax ASCII Model Importer"));

	// setup the "File Properties" section
	m_textFileName->SetValue(m_dlgInput->GetImportFileName());
	int nFileNameLen = (int) m_textFileName->GetValue().length();
	m_textFileName->SetSelection(nFileNameLen, nFileNameLen);
	m_textFileSize->SetValue(FileSizeToString(m_dlgInput->GetImportFileSize()));

	// use the "AscImp/MergeScene" value read from the configuration file
	bool replaceScene = true;
	pConfig->Read(_T("AscImp/ReplaceScene"), &replaceScene, replaceScene);
	if(m_dlgInput->GetCurrentSceneMode() == CURSCN_REPLACE_SCENE && !replaceScene)
		m_dlgInput->SetCurrentSceneMode(CURSCN_MERGE_SCENE);
	if(m_dlgInput->GetCurrentSceneMode() == CURSCN_MERGE_SCENE && replaceScene)
		m_dlgInput->SetCurrentSceneMode(CURSCN_REPLACE_SCENE);

	// use the "AscImp/MergeAnimation" value read from the configuration file
	bool replaceAnimation = true;
	pConfig->Read(_T("AscImp/ReplaceAnimation"), &replaceAnimation, replaceAnimation);
	m_dlgInput->SetCurrentAnimationMode(replaceAnimation ? CURANIM_REPLACE_ANIMATION : CURANIM_MERGE_ANIMATION);

	// select the notebook's panel
	for(int iPage = m_notebook->GetPageCount() - 1; iPage >= 0; --iPage)
	{
		bool bRemovePage = true;

		wxWindow* wndPage = m_notebook->GetPage(iPage);
		if(wndPage == m_panelMorphMesh)
			bRemovePage &= (m_dlgInput->GetAscType() != ASCTYPE_MORPH_MESH);
		else if(wndPage == m_panelMorphAnim)
			bRemovePage &= (m_dlgInput->GetAscType() != ASCTYPE_MORPH_ANIM);
		else if(wndPage == m_panelStaticMesh)
			bRemovePage &= (m_dlgInput->GetAscType() != ASCTYPE_STATIC_MESH);
		else if(wndPage == m_panelDynamicMesh)
			bRemovePage &= (m_dlgInput->GetAscType() != ASCTYPE_DYNAMIC_MESH);
		else if(wndPage == m_panelDynamicAnim)
			bRemovePage &= (m_dlgInput->GetAscType() != ASCTYPE_DYNAMIC_ANIM);

		if(bRemovePage)
		{
			m_notebook->RemovePage(iPage);
			wndPage->Hide();
		}
	}
	Fit();
	SetMinSize(GetSize());

	wxIcon pageicon;
	switch(m_dlgInput->GetAscType())
	{
		case ASCTYPE_MORPH_MESH:   pageicon = wxIcon(bow_xpm); break;
		case ASCTYPE_MORPH_ANIM:   pageicon = wxIcon(bow_shoot_xpm); break;
		case ASCTYPE_STATIC_MESH:  pageicon = wxIcon(ladder_xpm); break;
		case ASCTYPE_DYNAMIC_MESH: pageicon = wxIcon(orc_body_xpm); break;
		case ASCTYPE_DYNAMIC_ANIM: pageicon = wxIcon(orc_walk_xpm); break;
	}
	wxImageList* imageList = new wxImageList(16, 16, true);
	imageList->Add(pageicon);
	m_notebook->AssignImageList(imageList);
	m_notebook->SetPageImage(0, 0);

	ReadSpaceTransformConfig(m_dlgOutput->GetSpaceTransform());
	UpdateSpaceTransformButton();
	UpdateTimeTransformButton();

	bool bOk = false;
	switch(m_dlgInput->GetAscType())
	{
		case ASCTYPE_MORPH_MESH:  bOk = TransferDataToWindow_MM(); break;
		case ASCTYPE_MORPH_ANIM:  bOk = TransferDataToWindow_MA(); break;
		case ASCTYPE_STATIC_MESH: bOk = TransferDataToWindow_SM(); break;
		case ASCTYPE_DYNAMIC_MESH: bOk = TransferDataToWindow_DM(); break;
		case ASCTYPE_DYNAMIC_ANIM: bOk = TransferDataToWindow_DA(); break;
	}
	m_dlgOutput->SetContinueImport(false);
	return bOk;
}

bool wxASCImporterDlg::TransferDataToWindow_MM()
{
	// setup the imported model info
	m_textNumMeshes_MM->SetValue(INT_TO_STRING(m_dlgInput->GetNumFileMeshes()));
	m_textNumSlots_MM->SetValue(INT_TO_STRING(m_dlgInput->GetNumFileSlots()));
	m_textNumBones_MM->SetValue(INT_TO_STRING(m_dlgInput->GetNumFileBones()));

	// setup the "What do you want to do with current scene" section
	if(m_dlgInput->GetCurrentSceneMode() == CURSCN_REPLACE_SCENE)
	{	
		m_radioReplaceScene_MM->SetValue(true);
	}
	else if(m_dlgInput->GetCurrentSceneMode() == CURSCN_MERGE_SCENE)
	{
		m_radioMergeScene_MM->SetValue(true);
	}
	else if(m_dlgInput->GetCurrentSceneMode() == CURSCN_LINK_TO_SLOT)
	{
		m_radioLinkToSlot_MM->SetValue(true);
	}
	else if(m_dlgInput->GetCurrentSceneMode() == CURSCN_LINK_TO_BONE)
	{
		m_radioLinkToBone_MM->SetValue(true);
	}
	OnCurSceneModeChanged(wxCommandEvent());

	// setup slots and bones choices
	int numSlots = FillWxChoiceWithStrings(m_choiceSlots_MM, m_dlgInput->GetSlots(), m_dlgInput->GetSelectedSlot());
	m_radioLinkToSlot_MM->Enable(numSlots != 0);
	int numBones = FillWxChoiceWithStrings(m_choiceBones_MM, m_dlgInput->GetBones(), m_dlgInput->GetSelectedBone());
	m_radioLinkToBone_MM->Enable(numBones != 0);

	// setup the "Model Prefix" section
	m_textPrefix_MM->SetValue(m_dlgInput->GetUniquePrefix());

	return true;
}

bool wxASCImporterDlg::TransferDataToWindow_MA()
{
	// setup the imported model info
	m_textFirstFrame_MA->SetValue(INT_TO_STRING(m_dlgInput->GetAnimStartFrame()));
	m_textLastFrame_MA->SetValue(INT_TO_STRING(m_dlgInput->GetAnimEndFrame()));
	m_textFPS_MA->SetValue(INT_TO_STRING(m_dlgInput->GetAnimFrameRate()));

	// setup the "What do you want to do with current animation" section
	if(m_dlgInput->GetCurrentAnimationMode() == CURANIM_REPLACE_ANIMATION)
	{	
		m_radioReplaceAnim_MA->SetValue(true);
	}
	else if(m_dlgInput->GetCurrentAnimationMode() == CURANIM_MERGE_ANIMATION)
	{
		m_radioMergeAnim_MA->SetValue(true);
	}

	// setup the "Model Prefix" section
	int numPrefixes = FillWxChoiceWithPrefixes(m_choicePrefixes_MA, m_dlgInput->GetPrefixes(), m_dlgInput->GetSelectedPrefix());
	if(numPrefixes == 0)
	{
		m_radioReplaceAnim_MA->Enable(false);
		m_radioMergeAnim_MA->Enable(false);
		m_staticPrefixInfo_MA->Enable(false);
		m_staticPrefix_MA->Enable(false);
		m_choicePrefixes_MA->Enable(false);
		m_buttonImport->Enable(false);
	}
	
	return true;
}

bool wxASCImporterDlg::TransferDataToWindow_SM()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// setup the imported model info
	m_textNumMeshes_SM->SetValue(INT_TO_STRING(m_dlgInput->GetNumFileMeshes()));
	m_textNumSlots_SM->SetValue(INT_TO_STRING(m_dlgInput->GetNumFileSlots()));
	m_textNumBones_SM->SetValue(INT_TO_STRING(m_dlgInput->GetNumFileBones()));

	// setup the "What do you want to do with current scene" section
	if(m_dlgInput->GetCurrentSceneMode() == CURSCN_REPLACE_SCENE)
	{	
		m_radioReplaceScene_SM->SetValue(true);
	}
	else
	{
		m_radioMergeScene_SM->SetValue(true);
	}
	OnCurSceneModeChanged(wxCommandEvent());

	// setup the "Model Prefix" section
	m_textPrefix_SM->SetValue(m_dlgInput->GetSelectedPrefix());

	// setup the "Bones and Slots" section
	bool useSampleMeshes = true;
	pConfig->Read(_T("AscImp/UseSampleMeshes"), &useSampleMeshes, useSampleMeshes);
	m_checkSampleMeshes_SM->SetValue(useSampleMeshes);

	wxString sampleMeshesDir = m_dlgInput->GetSampleMeshesDir().c_str();
	pConfig->Read(_T("AscImp/SampleMeshesDir"), &sampleMeshesDir, sampleMeshesDir);
	m_textSampleMeshesDir_SM->SetValue(sampleMeshesDir);

	return true;
}

bool wxASCImporterDlg::TransferDataToWindow_DM()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// setup the imported model info
	m_textNumMeshes_DM->SetValue(INT_TO_STRING(m_dlgInput->GetNumFileMeshes()));
	m_textNumSlots_DM->SetValue(INT_TO_STRING(m_dlgInput->GetNumFileSlots()));
	m_textNumBones_DM->SetValue(INT_TO_STRING(m_dlgInput->GetNumFileBones()));

	// setup the "What do you want to do with current scene" section
	if(m_dlgInput->GetCurrentSceneMode() == CURSCN_REPLACE_SCENE)
	{	
		m_notebook_DM->ChangeSelection(0);
		m_radioReplaceScene_NDM->SetValue(true);
		m_radioReplaceSkin_MDM->SetValue(true);
	}
	else if(m_dlgInput->GetCurrentSceneMode() == CURSCN_MERGE_SCENE)
	{
		m_notebook_DM->ChangeSelection(0);
		m_radioMergeScene_NDM->SetValue(true);
		m_radioReplaceSkin_MDM->SetValue(true);
	}
	else if(m_dlgInput->GetCurrentSceneMode() == CURSCN_REPLACE_SKIN)
	{
		m_notebook_DM->ChangeSelection(1);
		m_radioReplaceSkin_MDM->SetValue(true);
		m_radioReplaceScene_NDM->SetValue(true);
	}
	else if(m_dlgInput->GetCurrentSceneMode() == CURSCN_MERGE_SKIN)
	{
		m_notebook_DM->ChangeSelection(1);
		m_radioMergeSkin_MDM->SetValue(true);
		m_radioReplaceScene_NDM->SetValue(true);
	}
	OnCurSceneModeChanged(wxCommandEvent());

	// setup the "Model Prefix" section
	if(0 == FillWxChoiceWithPrefixes(m_choicePrefixes_MDM, m_dlgInput->GetPrefixes(), m_dlgInput->GetSelectedPrefix()))
	{
		m_notebook_DM->RemovePage(1);
	}

	// setup the "Skinning method" section
	std::vector<std::tstring>& supportedSkinTypes = m_dlgInput->GetSupportedSkinTypes();
	for(size_t j = 0; j < supportedSkinTypes.size(); ++j)
	{
		m_listSkinTypes_NDM->Append(supportedSkinTypes[j]);
		m_listSkinTypes_MDM->Append(supportedSkinTypes[j]);
	}

	wxString skinningMethod = _T("");
	pConfig->Read(_T("AscImp/SkinningMethod"), &skinningMethod, skinningMethod);
	int selectedSkinType = m_listSkinTypes_NDM->FindString(skinningMethod);
	if(selectedSkinType == wxNOT_FOUND && !m_listSkinTypes_NDM->IsEmpty())
		selectedSkinType = 0;
	m_listSkinTypes_NDM->Check(selectedSkinType);
	m_listSkinTypes_MDM->Check(selectedSkinType);

	// setup the "Bones and Slots" section
	bool connectBones = true;
	pConfig->Read(_T("AscImp/ConnectBones"), &connectBones, connectBones);
	m_checkConnectBones_NDM->SetValue(connectBones);
	
	bool useSampleMeshes = true;
	pConfig->Read(_T("AscImp/UseSampleMeshes"), &useSampleMeshes, useSampleMeshes);
	m_checkSampleMeshes_NDM->SetValue(useSampleMeshes);

	wxString sampleMeshesDir = m_dlgInput->GetSampleMeshesDir().c_str();
	pConfig->Read(_T("AscImp/SampleMeshesDir"), &sampleMeshesDir, sampleMeshesDir);
	m_textSampleMeshesDir_NDM->SetValue(sampleMeshesDir);

	return true;
}

bool wxASCImporterDlg::TransferDataToWindow_DA()
{
	// setup the imported model info
	m_textFirstFrame_DA->SetValue(INT_TO_STRING(m_dlgInput->GetAnimStartFrame()));
	m_textLastFrame_DA->SetValue(INT_TO_STRING(m_dlgInput->GetAnimEndFrame()));
	m_textFPS_DA->SetValue(INT_TO_STRING(m_dlgInput->GetAnimFrameRate()));

	// setup the "What do you want to do with current animation" section
	if(m_dlgInput->GetCurrentAnimationMode() == CURANIM_REPLACE_ANIMATION)
	{	
		m_radioReplaceAnim_DA->SetValue(true);
	}
	else if(m_dlgInput->GetCurrentAnimationMode() == CURANIM_MERGE_ANIMATION)
	{
		m_radioMergeAnim_DA->SetValue(true);
	}

	// setup the "Model Prefix" section
	int numPrefixes = FillWxChoiceWithPrefixes(m_choicePrefixes_DA, m_dlgInput->GetPrefixes(), m_dlgInput->GetSelectedPrefix());
	if(numPrefixes == 0)
	{
		m_radioReplaceAnim_DA->Enable(false);
		m_radioMergeAnim_DA->Enable(false);
		m_staticPrefixInfo_DA->Enable(false);
		m_staticPrefix_DA->Enable(false);
		m_choicePrefixes_DA->Enable(false);
		m_buttonImport->Enable(false);
	}

	return true;
}

// Dialog data transfer (dialog controls -> output data file)
bool wxASCImporterDlg::TransferDataFromWindow()
{
	bool bOk;
	switch(m_dlgInput->GetAscType())
	{
		case ASCTYPE_MORPH_MESH:  bOk = TransferDataFromWindow_MM(); break;
		case ASCTYPE_MORPH_ANIM:  bOk = TransferDataFromWindow_MA(); break;
		case ASCTYPE_STATIC_MESH: bOk = TransferDataFromWindow_SM(); break;
		case ASCTYPE_DYNAMIC_MESH: bOk = TransferDataFromWindow_DM(); break;
		case ASCTYPE_DYNAMIC_ANIM: bOk = TransferDataFromWindow_DA(); break;
	}

	if(bOk)
	{
		m_dlgOutput->SetContinueImport(true);
	}
	return bOk;
}

bool wxASCImporterDlg::TransferDataFromWindow_MM()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// read data from the "What to do with current scene" section
	if(m_radioReplaceScene_MM->GetValue())
	{	
		m_dlgOutput->SetCurrentSceneMode(CURSCN_REPLACE_SCENE);
	}
	else if(m_radioMergeScene_MM->GetValue())
	{
		m_dlgOutput->SetCurrentSceneMode(CURSCN_MERGE_SCENE);
	}
	else if(m_radioLinkToSlot_MM->GetValue())
	{
		m_dlgOutput->SetCurrentSceneMode(CURSCN_LINK_TO_SLOT);
		m_dlgOutput->SetSelectedSlot(std::tstring(m_choiceSlots_MM->GetStringSelection().c_str()));
	}
	else if(m_radioLinkToBone_MM->GetValue())
	{
		m_dlgOutput->SetCurrentSceneMode(CURSCN_LINK_TO_BONE);
		m_dlgOutput->SetSelectedBone(std::tstring(m_choiceBones_MM->GetStringSelection().c_str()));
	}
	bool replaceScene = m_radioReplaceScene_MM->GetValue();
	pConfig->Write(_T("AscImp/ReplaceScene"), replaceScene);

	// read the "Model Prefix" section
	std::tstring prefix = GetPrefixFromWxTextCtrl(m_textPrefix_MM);
	if(!replaceScene && !CheckPrefixForUnique(prefix, m_dlgInput->GetPrefixes()))
		return false;
	
	m_dlgOutput->SetSelectedPrefix(prefix);
	return true;
}

bool wxASCImporterDlg::TransferDataFromWindow_MA()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// read data from the "What to do with current animation" section
	bool replaceAnimation = m_radioReplaceAnim_MA->GetValue();
	m_dlgOutput->SetCurrentAnimationMode(replaceAnimation ? CURANIM_REPLACE_ANIMATION : CURANIM_MERGE_ANIMATION);
	pConfig->Write(_T("AscImp/ReplaceAnimation"), replaceAnimation);

	// read the "Model Prefix" section
	m_dlgOutput->SetSelectedPrefix(GetPrefixFromWxChoice(m_choicePrefixes_MA));

	return true;
}

bool wxASCImporterDlg::TransferDataFromWindow_SM()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// read data from the "What to do with current scene" section
	bool replaceScene = m_radioReplaceScene_SM->GetValue();
	m_dlgOutput->SetCurrentSceneMode(replaceScene ? CURSCN_REPLACE_SCENE : CURSCN_MERGE_SCENE);
	pConfig->Write(_T("AscImp/ReplaceScene"), replaceScene);

	// read the "Model Prefix" section
	std::tstring prefix = GetPrefixFromWxTextCtrl(m_textPrefix_SM);
	if(!replaceScene && !CheckPrefixForUnique(prefix, m_dlgInput->GetPrefixes()))
		return false;
	m_dlgOutput->SetSelectedPrefix(prefix);

	// read the "Bones and Slots" section
	bool useSampleMeshes = m_checkSampleMeshes_SM->GetValue();
	m_dlgOutput->SetUseSampleMeshes(useSampleMeshes);
	pConfig->Write(_T("AscImp/UseSampleMeshes"), useSampleMeshes);

	wxString sampleMeshesDir = m_textSampleMeshesDir_SM->GetValue();
	m_dlgOutput->SetSampleMeshesDir(std::tstring(sampleMeshesDir.c_str()));
	pConfig->Write(_T("AscImp/SampleMeshesDir"), sampleMeshesDir);

	return true;
}

bool wxASCImporterDlg::TransferDataFromWindow_DM()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// read data from the "What to do with current scene" section
	bool replaceScene = false;
	bool newModel = false;
	if(m_notebook_DM->GetSelection() == 0 && m_radioReplaceScene_NDM->GetValue())
	{	
		m_dlgOutput->SetCurrentSceneMode(CURSCN_REPLACE_SCENE);
		replaceScene = true;
		newModel = true;
	}
	else if(m_notebook_DM->GetSelection() == 0 && m_radioMergeScene_NDM->GetValue())
	{
		m_dlgOutput->SetCurrentSceneMode(CURSCN_MERGE_SCENE);
		newModel = true;
	}
	else if(m_notebook_DM->GetSelection() == 1 && m_radioReplaceSkin_MDM->GetValue())
	{
		m_dlgOutput->SetCurrentSceneMode(CURSCN_REPLACE_SKIN);
	}
	else if(m_notebook_DM->GetSelection() == 1 && m_radioMergeSkin_MDM->GetValue())
	{
		m_dlgOutput->SetCurrentSceneMode(CURSCN_MERGE_SKIN);
	}
	pConfig->Write(_T("AscImp/ReplaceScene"), replaceScene);

	// read the "Model Prefix" section
	if(newModel)
	{
		std::tstring prefix = GetPrefixFromWxTextCtrl(m_textPrefix_NDM);
		if(!replaceScene && !CheckPrefixForUnique(prefix, m_dlgInput->GetPrefixes()))
			return false;
		m_dlgOutput->SetSelectedPrefix(prefix);
	}
	else
	{
		m_dlgOutput->SetSelectedPrefix(GetPrefixFromWxChoice(m_choicePrefixes_MDM));
	}

	// read the "Skinning method" section
	wxString selectedSkinType = _T("");
	for(unsigned int j = 0; j < m_listSkinTypes_NDM->GetCount(); ++j)
		if(m_listSkinTypes_NDM->IsChecked(j))
		{
			selectedSkinType = m_listSkinTypes_NDM->GetString(j);
			break;
		}
	m_dlgOutput->SetSelectedSkinType(std::tstring(selectedSkinType.c_str()));
	pConfig->Write(_T("AscImp/SkinningMethod"), selectedSkinType);

	// read the "Bones and Slots" section
	if(newModel)
	{
		bool connectBones = m_checkConnectBones_NDM->GetValue();
		m_dlgOutput->SetConnectBones(connectBones);
		pConfig->Write(_T("AscImp/ConnectBones"), connectBones);

		bool useSampleMeshes = m_checkSampleMeshes_NDM->GetValue();
		m_dlgOutput->SetUseSampleMeshes(useSampleMeshes);
		pConfig->Write(_T("AscImp/UseSampleMeshes"), useSampleMeshes);

		wxString sampleMeshesDir = m_textSampleMeshesDir_NDM->GetValue();
		m_dlgOutput->SetSampleMeshesDir(std::tstring(sampleMeshesDir.c_str()));
		pConfig->Write(_T("AscImp/SampleMeshesDir"), sampleMeshesDir);
	}

	return true;
}

bool wxASCImporterDlg::TransferDataFromWindow_DA()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// read data from the "What to do with current animation" section
	bool replaceAnimation = m_radioReplaceAnim_DA->GetValue();
	m_dlgOutput->SetCurrentAnimationMode(replaceAnimation ? CURANIM_REPLACE_ANIMATION : CURANIM_MERGE_ANIMATION);
	pConfig->Write(_T("AscImp/ReplaceAnimation"), replaceAnimation);

	// read the "Model Prefix" section
	m_dlgOutput->SetSelectedPrefix(GetPrefixFromWxChoice(m_choicePrefixes_DA));

	return true;
}

void wxASCImporterDlg::OnAutoPrefix( wxCommandEvent& event )
{
	bool replaceScene = true;
	switch(m_dlgInput->GetAscType())
	{
		case ASCTYPE_MORPH_MESH: replaceScene = m_radioReplaceScene_MM->GetValue(); break;
		case ASCTYPE_STATIC_MESH: replaceScene = m_radioReplaceScene_SM->GetValue(); break;
		case ASCTYPE_DYNAMIC_MESH: replaceScene = m_radioReplaceScene_NDM->GetValue(); break;
	}

	std::tstring prefix = replaceScene ? _T("") : m_dlgInput->GetUniquePrefix();
	m_textPrefix_MM->SetValue(prefix);
	m_textPrefix_SM->SetValue(prefix);
	m_textPrefix_NDM->SetValue(prefix);
}

void wxASCImporterDlg::OnSkinTypeChanged( wxCommandEvent& event )
{
	int nPos = event.GetInt();
	if(nPos != -1)
	{
		wxCheckListBox* listBox = (wxCheckListBox*) event.GetEventObject();
		if(!listBox->IsChecked(nPos))
			listBox->Check(nPos);

		for(unsigned int j = 0; j < m_listSkinTypes_NDM->GetCount(); ++j)
		{
			if(j == nPos)
			{
				m_listSkinTypes_NDM->Check(j, true);
				m_listSkinTypes_MDM->Check(j, true);
				m_listSkinTypes_NDM->Select(j);
				m_listSkinTypes_MDM->Select(j);
			}
			else
			{
				m_listSkinTypes_NDM->Check(j, false);
				m_listSkinTypes_MDM->Check(j, false);
				m_listSkinTypes_NDM->Deselect(j);
				m_listSkinTypes_MDM->Deselect(j);
			}
		}
	}
}

// Command buttons
void wxASCImporterDlg::OnImport(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wxASCImporterDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

void wxASCImporterDlg::OnHelp(wxCommandEvent& event)
{
	wxImpExpHelpMenu menu;
	PopupMenu(&menu);
}

// Enable controls depending on other controls
void wxASCImporterDlg::OnNotebookPageChanging( wxNotebookEvent& event )
{
	if(event.GetEventObject() == m_notebook)
	{
		event.Veto();
	}
	else if(event.GetEventObject() == m_notebook_DM)
	{
	}
}

void wxASCImporterDlg::OnCurSceneModeChanged( wxCommandEvent& event )
{
	switch(m_dlgInput->GetAscType())
	{
		case ASCTYPE_MORPH_MESH:
		{
			m_choiceBones_MM->Enable(m_radioLinkToBone_MM->GetValue());
			m_choiceSlots_MM->Enable(m_radioLinkToSlot_MM->GetValue());
			break;
		}
		case ASCTYPE_STATIC_MESH:
		{
			break;
		}
		case ASCTYPE_DYNAMIC_MESH:
		{
			break;
		}
	}
	OnAutoPrefix(wxCommandEvent());
}

void wxASCImporterDlg::OnSampleMeshesDir( wxCommandEvent& event )
{
	std::tstring dir;
	switch(m_dlgInput->GetAscType())
	{
		case ASCTYPE_STATIC_MESH:
		{
			dir = m_textSampleMeshesDir_SM->GetValue();
			break;
		}
		case ASCTYPE_DYNAMIC_MESH:
		{
			dir = m_textSampleMeshesDir_NDM->GetValue();
			break;
		}
	}

	wxDirDialog dirdlg(this, _("Choose a directory"), dir, wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
	if(dirdlg.ShowModal() != wxID_OK)
		return;
	dir = dirdlg.GetPath();
	if(dir[dir.length() - 1] != _T('\\'))
		dir.push_back(_T('\\'));

	m_textSampleMeshesDir_SM->SetValue(dir);
	m_textSampleMeshesDir_NDM->SetValue(dir);
}


// Options button clicked
void wxASCImporterDlg::OnOptions(wxCommandEvent& event)
{
	wxOptionsDlg dlg(this);
	dlg.ShowModal();
}

// Space transform button clicked
void wxASCImporterDlg::OnSpaceTransform(wxCommandEvent& event)
{
	wxSpaceTransformImpDlg dlg(this, m_dlgOutput->GetSpaceTransform());
	dlg.ShowModal();
	UpdateSpaceTransformButton();
}

void wxASCImporterDlg::UpdateSpaceTransformButton()
{
	float scaleCoef = m_dlgOutput->GetSpaceTransform().GetSystemUnitsPerFileUnit();
	wxString text = FormatMsg1(std::tstring(_("Scale: %1")), FLOAT_TO_STRING(scaleCoef)).c_str();
	m_buttonSpaceTransform_MM->SetLabel(text);
	m_buttonSpaceTransform_MA->SetLabel(text);
	m_buttonSpaceTransform_SM->SetLabel(text);
	m_buttonSpaceTransform_NDM->SetLabel(text);
	m_buttonSpaceTransform_MDM->SetLabel(text);
	m_buttonSpaceTransform_DA->SetLabel(text);
}

// Time transform button clicked
void wxASCImporterDlg::OnTimeTransform(wxCommandEvent& event)
{
	wxTimeTransformImpDlg dlg(this, m_dlgOutput->GetTimeTransform());
	dlg.ShowModal();
	UpdateTimeTransformButton();
}

void wxASCImporterDlg::UpdateTimeTransformButton()
{
	TTimeTransform& timeTransform = m_dlgOutput->GetTimeTransform();
	wxString text = FormatMsg4(std::tstring(_("Frames: %1 -> %2, ..., %3 -> %4")),
		FLOAT_TO_STRING(timeTransform.GetStartFrameInFile()).c_str(),
		FLOAT_TO_STRING(timeTransform.GetStartFrameInScene()).c_str(),
		FLOAT_TO_STRING(timeTransform.GetEndFrameInFile()).c_str(),
		FLOAT_TO_STRING(timeTransform.GetEndFrameInScene()).c_str());
	m_buttonTimeTransform_MA->SetLabel(text);
	m_buttonTimeTransform_DA->SetLabel(text);
}