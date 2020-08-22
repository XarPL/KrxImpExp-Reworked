///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FB_ImpExpUI__
#define __FB_ImpExpUI__

#include <wx/intl.h>

class wxCheckNotebook;
class wxCheckTreeCtrl;

#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/spinbutt.h>
#include <wx/spinctrl.h>
#include <wx/listctrl.h>
#include <wx/checklst.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/statbmp.h>
#include <wx/hyperlink.h>
#include <wx/gbsizer.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_OptionsDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_OptionsDlg : public wxDialog 
{
	private:
	
	protected:
		wxListBox* m_listLanguages;
		
		
		wxButton* m_buttonOK;
		wxButton* m_buttonCancel;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_OptionsDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Options"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 293,294 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~wxFB_OptionsDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_3DSImporterDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_3DSImporterDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticFileName;
		wxTextCtrl* m_textFileName;
		wxStaticText* m_staticFileSize;
		wxTextCtrl* m_textFileSize;
		
		wxRadioButton* m_radioReplaceScene;
		wxRadioButton* m_radioMergeScene;
		wxRadioButton* m_radioReplaceSlot;
		wxStaticText* m_staticSelectSlot;
		wxChoice* m_choiceSlots;
		wxRadioButton* m_radioReplaceBone;
		wxStaticText* m_staticSelectBone;
		wxChoice* m_choiceBones;
		
		wxButton* m_buttonSpaceTransform;
		wxCheckBox* m_checkWeldVertices;
		
		wxStaticText* m_staticThreshold;
		wxTextCtrl* m_textThreshold;
		wxSpinButton* m_spinThreshold;
		
		wxStaticText* m_staticInfoWnd;
		wxCheckBox* m_checkShowInfoWnd;
		wxCheckBox* m_checkAutoClose;
		wxStaticText* m_staticTimeout;
		wxSpinCtrl* m_spinTimeout;
		
		
		wxButton* m_buttonImport;
		wxButton* m_buttonCancel;
		wxButton* m_buttonOptions;
		wxButton* m_buttonHelp;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCurSceneModeChanged( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSpaceTransform( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnWeldVertices( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnThresholdChanged( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnThresholdSpin( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnShowInfoWnd( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAutoClose( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnImport( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOptions( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_3DSImporterDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~wxFB_3DSImporterDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_MeshImporterDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_MeshImporterDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticFileName;
		wxTextCtrl* m_textFileName;
		wxStaticText* m_staticFileSize;
		wxTextCtrl* m_textFileSize;
		
		wxRadioButton* m_radioReplaceScene;
		wxRadioButton* m_radioMergeScene;
		
		wxButton* m_buttonSpaceTransform;
		
		wxStaticText* m_staticInfoWnd;
		wxCheckBox* m_checkShowInfoWnd;
		wxCheckBox* m_checkAutoClose;
		wxStaticText* m_staticTimeout;
		wxSpinCtrl* m_spinTimeout;
		
		
		wxButton* m_buttonImport;
		wxButton* m_buttonCancel;
		wxButton* m_buttonOptions;
		wxButton* m_buttonHelp;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCurSceneModeChanged( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSpaceTransform( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnShowInfoWnd( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAutoClose( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnImport( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOptions( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_MeshImporterDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~wxFB_MeshImporterDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_MeshInfoDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_MeshInfoDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticFileName;
		wxTextCtrl* m_textFileName;
		wxStaticText* m_staticFileSize;
		wxTextCtrl* m_textFileSize;
		wxStaticBoxSizer* m_sbSizerObjects;
		wxListCtrl* m_listObjects;
		wxStaticText* m_staticWarning;
		
		
		wxButton* m_buttonClose;
		wxButton* m_buttonStopTimer;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnStopTimer( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_MeshInfoDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~wxFB_MeshInfoDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_MatRenParamsDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_MatRenParamsDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticMatLibIniPath;
		wxTextCtrl* m_textMatLibIniPath;
		wxButton* m_buttonBrowseMatLibIni;
		wxStaticText* m_staticInfo;
		wxButton* m_buttonLoadMaterialFilter;
		
		wxListCtrl* m_listKnownMaterials;
		
		wxCheckBox* m_checkAutoNames;
		
		
		wxButton* m_buttonOK;
		wxButton* m_buttonCancel;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnBrowseMatLibIni( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnLoadMaterialFilter( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_MatRenParamsDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Material Renaming Parameters"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~wxFB_MatRenParamsDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_3DSExporterDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_3DSExporterDlg : public wxDialog 
{
	private:
	
	protected:
		wxCheckListBox* m_listObjects;
		wxStaticText* m_staticNumSelected;
		wxTextCtrl* m_textNumSelected;
		wxButton* m_buttonAll;
		wxButton* m_buttonNone;
		wxRadioButton* m_radioWorldCS;
		
		wxStaticText* m_staticWorldCSDesc;
		wxRadioButton* m_radioLocalCS;
		
		wxStaticText* m_staticLocalCSDesc;
		wxButton* m_buttonSpaceTransform;
		wxCheckBox* m_checkRenameMaterials;
		wxButton* m_buttonMatRenParams;
		wxStaticText* m_staticInfoWnd;
		wxCheckBox* m_checkShowInfoWnd;
		wxCheckBox* m_checkAutoClose;
		wxStaticText* m_staticTimeout;
		wxSpinCtrl* m_spinTimeout;
		wxButton* m_buttonExport;
		wxButton* m_buttonCancel;
		wxButton* m_buttonOptions;
		wxButton* m_buttonHelp;
		wxStaticText* m_staticFileName;
		wxTextCtrl* m_textFileName;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnObjectDClicked( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnObjectSelected( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectAll( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectNone( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSpaceTransform( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnRenameMaterials( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnMatRenParams( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnShowInfoWnd( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAutoClose( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnExport( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOptions( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_3DSExporterDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~wxFB_3DSExporterDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_ASCImporterDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_ASCImporterDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticFileName;
		wxTextCtrl* m_textFileName;
		wxStaticText* m_staticFileSize;
		wxTextCtrl* m_textFileSize;
		wxNotebook* m_notebook;
		wxPanel* m_panelMorphMesh;
		wxStaticText* m_staticNumMeshes_MM;
		wxTextCtrl* m_textNumMeshes_MM;
		
		wxStaticText* m_staticNumSlots_MM;
		wxTextCtrl* m_textNumSlots_MM;
		
		wxStaticText* m_staticNumBones_MM;
		wxTextCtrl* m_textNumBones_MM;
		
		wxRadioButton* m_radioReplaceScene_MM;
		wxRadioButton* m_radioMergeScene_MM;
		wxRadioButton* m_radioLinkToSlot_MM;
		wxStaticText* m_staticChooseSlot_MM;
		wxChoice* m_choiceSlots_MM;
		wxRadioButton* m_radioLinkToBone_MM;
		wxStaticText* m_staticChooseBone_MM;
		wxChoice* m_choiceBones_MM;
		
		wxStaticText* m_staticPrefixInfo_MM;
		wxStaticText* m_staticPrefix_MM;
		wxTextCtrl* m_textPrefix_MM;
		wxButton* m_buttonAutoPrefix_MM;
		
		wxButton* m_buttonSpaceTransform_MM;
		
		wxPanel* m_panelMorphAnim;
		wxStaticText* m_staticFirstFrame_MA;
		wxTextCtrl* m_textFirstFrame_MA;
		
		wxStaticText* m_staticLastFrame_MA;
		wxTextCtrl* m_textLastFrame_MA;
		
		wxStaticText* m_staticFPS_MA;
		wxTextCtrl* m_textFPS_MA;
		
		wxRadioButton* m_radioReplaceAnim_MA;
		wxRadioButton* m_radioMergeAnim_MA;
		
		wxStaticText* m_staticPrefixInfo_MA;
		wxStaticText* m_staticPrefix_MA;
		wxChoice* m_choicePrefixes_MA;
		
		wxButton* m_buttonSpaceTransform_MA;
		wxButton* m_buttonTimeTransform_MA;
		wxPanel* m_panelStaticMesh;
		wxStaticText* m_staticNumMeshes_SM;
		wxTextCtrl* m_textNumMeshes_SM;
		
		wxStaticText* m_staticNumSlots_SM;
		wxTextCtrl* m_textNumSlots_SM;
		
		wxStaticText* m_staticNumBones_SM;
		wxTextCtrl* m_textNumBones_SM;
		
		wxRadioButton* m_radioReplaceScene_SM;
		wxRadioButton* m_radioMergeScene_SM;
		
		wxStaticText* m_staticPrefixInfo_SM;
		wxStaticText* m_staticPrefix_SM;
		wxTextCtrl* m_textPrefix_SM;
		wxButton* m_buttonAutoPrefix_SM;
		
		wxButton* m_buttonSpaceTransform_SM;
		wxCheckBox* m_checkSampleMeshes_SM;
		wxTextCtrl* m_textSampleMeshesDir_SM;
		wxButton* m_buttonSampleMeshesDir_SM;
		wxPanel* m_panelDynamicMesh;
		wxStaticText* m_staticNumMeshes_DM;
		wxTextCtrl* m_textNumMeshes_DM;
		
		wxStaticText* m_staticNumSlots_DM;
		wxTextCtrl* m_textNumSlots_DM;
		
		wxStaticText* m_staticNumBones_DM;
		wxTextCtrl* m_textNumBones_DM;
		
		wxCheckNotebook* m_notebook_DM;
		wxPanel* m_panelNewModel_DM;
		wxRadioButton* m_radioReplaceScene_NDM;
		wxRadioButton* m_radioMergeScene_NDM;
		
		wxStaticText* m_staticPrefixInfo_NDM;
		wxStaticText* m_staticPrefix_NDM;
		wxTextCtrl* m_textPrefix_NDM;
		wxButton* m_buttonAutoPrefix_NDM;
		
		wxCheckListBox* m_listSkinTypes_NDM;
		wxButton* m_buttonSpaceTransform_NDM;
		
		wxCheckBox* m_checkConnectBones_NDM;
		wxCheckBox* m_checkSampleMeshes_NDM;
		wxTextCtrl* m_textSampleMeshesDir_NDM;
		wxButton* m_buttonSampleMeshesDir_NDM;
		wxPanel* m_panelMergeModel_DM;
		wxRadioButton* m_radioReplaceSkin_MDM;
		wxRadioButton* m_radioMergeSkin_MDM;
		
		wxStaticText* m_staticPrefixInfo_MDM;
		wxStaticText* m_staticPrefix_MDM;
		wxChoice* m_choicePrefixes_MDM;
		
		wxCheckListBox* m_listSkinTypes_MDM;
		wxButton* m_buttonSpaceTransform_MDM;
		
		wxPanel* m_panelDynamicAnim;
		wxStaticText* m_staticFirstFrame_DA;
		wxTextCtrl* m_textFirstFrame_DA;
		
		wxStaticText* m_staticLastFrame_DA;
		wxTextCtrl* m_textLastFrame_DA;
		
		wxStaticText* m_staticFPS_DA;
		wxTextCtrl* m_textFPS_DA;
		wxRadioButton* m_radioReplaceAnim_DA;
		wxRadioButton* m_radioMergeAnim_DA;
		wxStaticText* m_staticPrefixInfo_DA;
		wxStaticText* m_staticPrefix_DA;
		wxChoice* m_choicePrefixes_DA;
		wxButton* m_buttonSpaceTransform_DA;
		wxButton* m_buttonTimeTransform_DA;
		
		
		wxButton* m_buttonImport;
		wxButton* m_buttonCancel;
		wxButton* m_buttonOptions;
		wxButton* m_buttonHelp;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCurSceneModeChanged( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAutoPrefix( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSpaceTransform( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOperationChanged( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTimeTransform( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSampleMeshesDir( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSkinTypeChanged( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnImport( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOptions( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_ASCImporterDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~wxFB_ASCImporterDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_ASCExporterDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_ASCExporterDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticPrefix;
		wxChoice* m_choicePrefixes;
		wxStaticText* m_staticModelType;
		wxTextCtrl* m_textModelType;
		
		wxRadioButton* m_radioExportMesh;
		wxRadioButton* m_radioExportAnimation;
		
		wxButton* m_buttonSpaceTransform;
		wxButton* m_buttonTimeTransform;
		
		wxTextCtrl* m_textInformation;
		wxCheckTreeCtrl* m_treeObjects;
		wxStaticText* m_staticNumSelected;
		wxTextCtrl* m_textNumSelected;
		wxButton* m_buttonAll;
		wxButton* m_buttonNone;
		wxButton* m_buttonExport;
		wxButton* m_buttonCancel;
		wxButton* m_buttonOptions;
		wxButton* m_buttonHelp;
		
		wxStaticText* m_staticFileName;
		wxTextCtrl* m_textFileName;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnPrefixChanged( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTypeOfExportChanged( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSpaceTransform( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTimeTransform( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectAll( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectNone( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnExport( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOptions( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_ASCExporterDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 821,595 ), long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~wxFB_ASCExporterDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_AboutDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_AboutDlg : public wxDialog 
{
	private:
	
	protected:
		
		wxStaticBitmap* m_bitmapLogo;
		wxStaticText* m_staticTitle;
		wxStaticText* m_staticReleaseDate;
		wxStaticText* m_staticDescription;
		
		wxStaticText* m_staticDevelopedBy;
		wxStaticText* m_staticAuthor;
		wxStaticText* m_staticTranslatedBy;
		wxStaticText* m_staticTranslator;
		wxStaticText* m_staticDownloadPage;
		wxHyperlinkCtrl* m_hyperlinkDownloadPage;
		wxStaticText* m_staticEngSupForum;
		wxHyperlinkCtrl* m_hyperlinkEngSupForum;
		wxStaticText* m_staticRusSupForum;
		wxHyperlinkCtrl* m_hyperlinkRusSupForum;
		
		wxStaticText* m_staticUsedComponents;
		wxTextCtrl* m_textUsedComponents;
		wxStaticBitmap* m_bitmapCrazy;
		
		
		wxButton* m_buttonClose;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_AboutDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("About these plugins"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~wxFB_AboutDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_TimeTransformImpDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_TimeTransformImpDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticIndexInFile;
		wxStaticText* m_staticFrameInScene;
		wxStaticText* m_staticFirstFrame;
		wxSpinCtrl* m_spinFirstInFile;
		wxStaticText* m_staticFirstArrow;
		wxSpinCtrl* m_spinFirstInScene;
		wxStaticText* m_staticSecondFrame;
		wxSpinCtrl* m_spinSecondInFile;
		wxStaticText* m_staticSecondArrow;
		wxSpinCtrl* m_spinSecondInScene;
		wxStaticText* m_staticThirdFrame;
		wxSpinCtrl* m_spinThirdInFile;
		wxStaticText* m_staticThirdArrow;
		wxSpinCtrl* m_spinThirdInScene;
		wxStaticText* m_staticVDots;
		wxStaticText* m_staticLastFrame;
		wxSpinCtrl* m_spinLastInFile;
		wxStaticText* m_staticLastArrow;
		wxSpinCtrl* m_spinLastInScene;
		
		
		wxButton* m_buttonOK;
		wxButton* m_buttonCancel;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFirstInFileChanged( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnFirstInSceneChanged( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnLastInFileChanged( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_TimeTransformImpDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Time Transformation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~wxFB_TimeTransformImpDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_TimeTransformExpDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_TimeTransformExpDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticFrameInScene;
		wxStaticText* m_staticIndexInFile;
		wxStaticText* m_staticFirstFrame;
		wxSpinCtrl* m_spinFirstInScene;
		wxStaticText* m_staticFirstArrow;
		wxSpinCtrl* m_spinFirstInFile;
		wxStaticText* m_staticSecondFrame;
		wxSpinCtrl* m_spinSecondInScene;
		wxStaticText* m_staticSecondArrow;
		wxSpinCtrl* m_spinSecondInFile;
		wxStaticText* m_staticThirdFrame;
		wxSpinCtrl* m_spinThirdInScene;
		wxStaticText* m_staticThirdArrow;
		wxSpinCtrl* m_spinThirdInFile;
		wxStaticText* m_staticVDots;
		wxStaticText* m_staticLastFrame;
		wxSpinCtrl* m_spinLastInScene;
		wxStaticText* m_staticLastArrow;
		wxSpinCtrl* m_spinLastInFile;
		
		
		wxButton* m_buttonOK;
		wxButton* m_buttonCancel;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFirstInSceneChanged( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnFirstInFileChanged( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnLastInSceneChanged( wxSpinEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_TimeTransformExpDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Time Transformation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~wxFB_TimeTransformExpDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_SpaceTransformImpDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_SpaceTransformImpDlg : public wxDialog 
{
	private:
	
	protected:
		wxRadioButton* m_radioKeepCurSettings;
		wxRadioButton* m_radioSetupSystemUnit;
		wxStaticText* m_staticSystemUnit;
		wxChoice* m_choiceSystemUnit;
		
		wxStaticText* m_staticScaleCoef;
		wxTextCtrl* m_textScaleCoef;
		
		
		wxButton* m_buttonOK;
		wxButton* m_buttonCancel;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnRadioChanged( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSystemUnitChanged( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_SpaceTransformImpDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Space Transformation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~wxFB_SpaceTransformImpDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_SpaceTransformExpDlg
///////////////////////////////////////////////////////////////////////////////
class wxFB_SpaceTransformExpDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticScaleCoef;
		wxTextCtrl* m_textScaleCoef;
		
		
		wxButton* m_buttonOK;
		wxButton* m_buttonCancel;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_SpaceTransformExpDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Space Transformation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~wxFB_SpaceTransformExpDlg();
	
};

#endif //__FB_ImpExpUI__
