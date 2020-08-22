///////////////////////////////////////////////////////////////////////////////
// Name:        ASCExporterDlg.cpp
// Purpose:     Implementation of class wxASCExporterDlg.
// Author:      Vitaly Baranov
// Created:     January 31, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "AscExporterDlgInput.meta"
#include "AscExporterDlgOutput.meta"
#include "FormatMsg.meta"

// wxImpExpUI headers
#include "expasc.xpm"
#include "ImpExpUITools.h"
#include "ImpExpHelpMenu.h"
#include "CheckTreeCtrl.h"
#include "ASCExporterDlg.h"
#include "OptionsDlg.h"
#include "SpaceTransformExpDlg.h"
#include "SpaceTransformTools.h"
#include "TimeTransformExpDlg.h"



////////////////////////////////////////////////////////////////////////////////
// wxASCExporterDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxASCExporterDlg::wxASCExporterDlg(wxWindow* parent, TASCExporterDlgInput& dlgInput, 
								   TASCExporterDlgOutput& dlgOutput)
: wxFB_ASCExporterDlg(parent) 
{
	m_dlgInput = &dlgInput;
	m_dlgOutput = &dlgOutput;
	m_curModelHierarchy = NULL;

    // set the dialog icon
    SetIcon(wxIcon(expasc_xpm));

	// setup layout
	SetMinSize(GetSize());

	// connect Events
	m_treeObjects->Connect( wxEVT_COMMAND_CHECKTREECTRL_TOGGLED, wxCommandEventHandler( wxASCExporterDlg::OnObjectSelected ), NULL, this );
}

// Dtor
wxASCExporterDlg::~wxASCExporterDlg()
{
	// disconnect Events
	m_treeObjects->Disconnect( wxEVT_COMMAND_CHECKTREECTRL_TOGGLED, wxCommandEventHandler( wxASCExporterDlg::OnObjectSelected ), NULL, this );

	if(m_curModelHierarchy) delete m_curModelHierarchy;
}


// Dialog data transfer (input data file -> dialog controls)
bool wxASCExporterDlg::TransferDataToWindow()
{
	// set the window's title
	SetTitle(_T("Kerrax ASCII Model Exporter"));

	// setup the "File Properties" section
	m_textFileName->SetValue(m_dlgInput->GetExportFileName());

	// setup the "Space Transform" and "Time Transform" buttons
	ReadSpaceTransformConfig(m_dlgOutput->GetSpaceTransform());
	UpdateSpaceTransformButton();
	UpdateTimeTransformButton();

	// setup the "Model to Export" section
	std::vector<std::tstring> prefixes;
	for(size_t i = 0; i < m_dlgInput->GetModelHierarchies().size(); ++i)
		prefixes.push_back(m_dlgInput->GetModelHierarchies()[i].GetModelPrefix());
	
	if(0 == FillWxChoiceWithPrefixes(m_choicePrefixes, prefixes, m_dlgInput->GetSelectedPrefix()))
	{
		m_radioExportMesh->Enable(false);
		m_radioExportAnimation->Enable(false);
		m_textNumSelected->SetValue(_T("0"));
		m_buttonExport->Enable(false);
		m_dlgOutput->SetContinueExport(false);
		return true;
	}

	// setup the "Type of Export" section
	wxConfigBase* pConfig = wxConfigBase::Get();
	bool expAnim = false;
	pConfig->Read(_T("AscExp/ExportAnimation"), &expAnim, expAnim);
	if(expAnim)
		m_radioExportAnimation->SetValue(true);
	else
		m_radioExportMesh->SetValue(true);

	// Update tree of objects, model type
	OnPrefixChanged(wxCommandEvent());

	// setup default output values
	m_dlgOutput->SetContinueExport(false);
	return true;
}

// Dialog data transfer (dialog controls -> output data file)
bool wxASCExporterDlg::TransferDataFromWindow()
{
	// read data from the "Model to Export" section
	m_dlgOutput->SetSelectedPrefix(GetPrefixFromWxChoice(m_choicePrefixes));

	// read data from the "Objects To Export" section
	if(m_curModelHierarchy)
	{
		std::vector<std::tstring> selectedObjects;
		for(size_t i = 0; i < m_curModelHierarchy->GetObjects().size(); ++i)
		{
			std::tstring objName = m_curModelHierarchy->GetObjects()[i];
			if(m_treeObjects->IsItemChecked(objName.c_str()))
				selectedObjects.push_back(objName);
		}
		m_dlgOutput->SetSelectedObjects(selectedObjects);
	}
	
	// read data from the "Type of Export" section
	bool expAnim = m_radioExportAnimation->GetValue();
	m_dlgOutput->SetExportAnimation(expAnim);
	if(expAnim)
	{
	}

	// save settings to configuration file
	wxConfigBase *pConfig = wxConfigBase::Get();
	pConfig->Write(_T("AscExp/ExportAnimation"), expAnim);

	// close dialog
	m_dlgOutput->SetContinueExport(true);
	return true;
}

// Command buttons
void wxASCExporterDlg::OnExport(wxCommandEvent& event)
{
	AcceptAndClose();
}

void wxASCExporterDlg::OnCancel(wxCommandEvent& event)
{
	Close();
}

void wxASCExporterDlg::OnHelp(wxCommandEvent& event)
{
	wxImpExpHelpMenu menu;
	PopupMenu(&menu);
}

// Options button clicked
void wxASCExporterDlg::OnOptions(wxCommandEvent& event)
{
	wxOptionsDlg dlg(this);
	dlg.ShowModal();
}

// Enable controls depending on other controls
void wxASCExporterDlg::OnPrefixChanged( wxCommandEvent& event )
{
	std::tstring prefix = GetPrefixFromWxChoice(m_choicePrefixes);
	if(m_curModelHierarchy) delete m_curModelHierarchy;
	m_curModelHierarchy = NULL;
	for(size_t i = 0; i < m_dlgInput->GetModelHierarchies().size(); ++i)
		if(m_dlgInput->GetModelHierarchies()[i].GetModelPrefix() == prefix)
		{
			m_curModelHierarchy = new TModelHierarchy(m_dlgInput->GetModelHierarchies()[i]);
			break;
		}
	
	if(!m_curModelHierarchy)
	{
		m_textModelType->SetValue(_T(""));
		m_radioExportMesh->Enable(false);
		m_radioExportAnimation->Enable(false);
	}
	else
	{
		if(m_curModelHierarchy->GetModelType() == MODELTYPE_DYNAMIC)
		{
			m_textModelType->SetValue(_("Dynamic model"));
			m_radioExportMesh->Enable(true);
			m_radioExportAnimation->Enable(true);
		}
		else if(m_curModelHierarchy->GetModelType() == MODELTYPE_STATIC)
		{
			m_textModelType->SetValue(_("Static model"));
			m_radioExportMesh->Enable(true);
			m_radioExportAnimation->Enable(false);
		}
		else if(m_curModelHierarchy->GetModelType() == MODELTYPE_MORPH)
		{
			m_textModelType->SetValue(_("Morph mesh"));
			m_radioExportMesh->Enable(true);
			m_radioExportAnimation->Enable(true);
		}
		else
		{
			m_textModelType->SetValue(_T(""));
			m_radioExportMesh->Enable(false);
			m_radioExportAnimation->Enable(false);
		}
	}

	if(!m_radioExportMesh->GetValue() && !m_radioExportAnimation->GetValue())
	{
		m_radioExportMesh->SetValue(true);
	}
	if(!m_radioExportAnimation->IsEnabled())
	{
		m_radioExportMesh->SetValue(true);
		if(!m_radioExportMesh->IsEnabled())
			m_radioExportMesh->SetValue(false);
	}

	OnTypeOfExportChanged(wxCommandEvent());
}

void wxASCExporterDlg::OnTypeOfExportChanged( wxCommandEvent& event )
{
	bool expAnim = m_radioExportAnimation->GetValue();
	m_buttonTimeTransform->Enable(expAnim);

	bool morphMesh = (!expAnim && m_curModelHierarchy->GetModelType() == MODELTYPE_MORPH);
	bool morphAnim = (expAnim && m_curModelHierarchy->GetModelType() == MODELTYPE_MORPH);
	bool staticMesh = (m_curModelHierarchy->GetModelType() == MODELTYPE_STATIC);
	bool dynamicMesh = (!expAnim && m_curModelHierarchy->GetModelType() == MODELTYPE_DYNAMIC);
	bool dynamicAnim = (expAnim && m_curModelHierarchy->GetModelType() == MODELTYPE_DYNAMIC);

	wxString info = _T("");
	if(morphMesh || morphAnim)
	{
		info = _("\
Morph meshes can be used for modelling heads, bows, crossbows, flags, and so on. \
A morph mesh is represented by one MMS file and two or more ASC files. \
A compiled morph mesh is represented by one MMB file. \
Export of any morph mesh contains two steps: 1) export an initial mesh; \
and 2) export mesh'es animations.\n\n");

		if(morphMesh)
			info += _("\
Current mode: Export mesh.\n\n\
You should write the ASC file name to the \"morphRef\" section of your MMS file.");
		else
			info += _("\
Current mode: Export animation.\n\n\
You should write the ASC file name to the \"morphAni\" section of your MMS file.");
	}
	else if(staticMesh)
	{
		info = _("\
Static models can be used for modelling beds, anvils, ladders, idols, chairs, and other objects, \
which can move only entirely (i.e. any part of an object is immovable relative to any other part of the same object). \
A static model is represented by one ASC file. \
A compiled static model is represented by one MDL file.\n\n");
	}
	else if(dynamicMesh || dynamicAnim)
	{
		info = _("\
Dynamic models can be used for modelling humans, orcs, monsters, their overlays, doors, chests, \
and other objects which have skeletons. \
A dynamic model is represented by one MDS file and two or more ASC files. \
A compiled dynamic model is represented by one MDH file, one or more MDM files, and one or more MAN files. \
Export of any dynamic model contains two steps: 1) export a model in initial pose; \
and 2) export model's animations.\n\n");
		if(dynamicMesh)
			info += _("\
Current mode: Export mesh.\n\n\
You should write the ASC file name to the \"meshAndTree\" or \"RegisterMesh\" section of your MDS file. \
There are two choices: you can press the \"All\" button to export the dynamic model entirely; \
or you can press \"None\" button to export bones and slots only (meshes aren't exported in this case). \
The last choice can be useful if you want to save an overlay's skeleton.");
		else
			info += _("\
Current mode: Export animation.\n\n\
You should write the ASC file name to the \"ani\" section of your MDS file. \
There are two choices: you can press the \"All\" button to export animation of all the bones and slots; \
or you can select bones and slots to export animation of some part of bones and slots. \
You should use the last choice if you want to save animation for the second layer. \n\n\
Here is a short explanation. \
Animations of different layers can be overlayed. \
For example, animation of sword's drawing is putted on animation of running man, \
and the result is sword's drawing while running. \
Therefore the animation of running man is at the first layer (export animation of all bones and slots) \
and the sword's drawing is at the second later (export animation of subtree starting with the \"Bip01 Spine1\" object).");
	}
	info.Replace(_T("\n"), _T("\r\n"));
	m_textInformation->SetLabel(info);

	m_treeObjects->SetCheckingMode(dynamicAnim ? wxCHECKTREE_MODE_BRANCH : wxCHECKTREE_MODE_ITEM);
	m_treeObjects->DeleteAllItems();
	m_treeObjects->AddCheckedRoot(_T("root"));

	for(size_t j = 0; j < m_curModelHierarchy->GetObjects().size(); ++j)
	{
		std::tstring objName = m_curModelHierarchy->GetObjects()[j];
		std::tstring parentName = m_curModelHierarchy->GetObjectParents()[j];
		int objType = m_curModelHierarchy->GetObjectTypes()[j];
		if(parentName.empty()) parentName = _T("root");
		if(morphMesh || morphAnim || staticMesh)
		{
			m_treeObjects->AddCheckedItem(parentName, objName, true, false);
		}
		else if(dynamicMesh)
		{
			m_treeObjects->AddCheckedItem(parentName, objName, true, 
				!(objType == OBJTYPE_BONE || objType == OBJTYPE_SLOT));
		}
		else if(dynamicAnim)
		{
			if(objType == OBJTYPE_BONE || objType == OBJTYPE_SLOT)
				m_treeObjects->AddCheckedItem(parentName, objName, true, true);
		}
	}
	m_treeObjects->ExpandAll();

	OnObjectSelected(wxCommandEvent());
}

void wxASCExporterDlg::OnObjectSelected( wxCommandEvent& event )
{
	// number of checked items without root item
	int numSelected = m_treeObjects->GetCheckedItemCount();
	wxTreeItemId rootId = m_treeObjects->GetRootItem();
	if(rootId.IsOk())
	{
		if(m_treeObjects->IsItemChecked(rootId))
			--numSelected;
	}
	// print number of checked items into the control m_textNumSelected
	wxString strNumSelected;
	strNumSelected.Printf(_T("%d"), numSelected);
	m_textNumSelected->SetValue(strNumSelected);
}

void wxASCExporterDlg::OnSelectAll( wxCommandEvent& event )
{
	m_treeObjects->CheckAllItems();
	OnObjectSelected(wxCommandEvent());
}

void wxASCExporterDlg::OnSelectNone( wxCommandEvent& event )
{
	m_treeObjects->CheckAllItems(false);
	OnObjectSelected(wxCommandEvent());
}

// Space transform button clicked
void wxASCExporterDlg::OnSpaceTransform(wxCommandEvent& event)
{
	wxSpaceTransformExpDlg dlg(this, m_dlgOutput->GetSpaceTransform());
	dlg.ShowModal();
	UpdateSpaceTransformButton();
}

void wxASCExporterDlg::UpdateSpaceTransformButton()
{
	float scaleCoef = m_dlgOutput->GetSpaceTransform().GetFileUnitsPerSystemUnit();
	wxString text = FormatMsg1(std::tstring(_("Scale: %1")), FLOAT_TO_STRING(scaleCoef)).c_str();
	m_buttonSpaceTransform->SetLabel(text);
}

// Time transform button clicked
void wxASCExporterDlg::OnTimeTransform(wxCommandEvent& event)
{
	wxTimeTransformExpDlg dlg(this, m_dlgOutput->GetTimeTransform());
	dlg.ShowModal();
	UpdateTimeTransformButton();
}

void wxASCExporterDlg::UpdateTimeTransformButton()
{
	TTimeTransform& timeTransform = m_dlgOutput->GetTimeTransform();
	wxString text = FormatMsg4(std::tstring(_("Frames: %1 -> %2, ..., %3 -> %4")),
		FLOAT_TO_STRING(timeTransform.GetStartFrameInScene()).c_str(),
		FLOAT_TO_STRING(timeTransform.GetStartFrameInFile()).c_str(),
		FLOAT_TO_STRING(timeTransform.GetEndFrameInScene()).c_str(),
		FLOAT_TO_STRING(timeTransform.GetEndFrameInFile()).c_str());
	m_buttonTimeTransform->SetLabel(text);
}