///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

#include "CheckNotebook.h"
#include "CheckTreeCtrl.h"

#include "FB_ImpExpUI.h"

#include "../gfx/impexp.xpm"

///////////////////////////////////////////////////////////////////////////

wxFB_OptionsDlg::wxFB_OptionsDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerLanguages;
	sbSizerLanguages = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Language") ), wxVERTICAL );
	
	m_listLanguages = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizerLanguages->Add( m_listLanguages, 1, wxALL|wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerLanguages, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 0, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCmdButtons->SetMinSize( wxSize( -1,45 ) ); 
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonOK, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonCancel, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	
	// Connect Events
	m_buttonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_OptionsDlg::OnOK ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_OptionsDlg::OnCancel ), NULL, this );
}

wxFB_OptionsDlg::~wxFB_OptionsDlg()
{
	// Disconnect Events
	m_buttonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_OptionsDlg::OnOK ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_OptionsDlg::OnCancel ), NULL, this );
}

wxFB_3DSImporterDlg::wxFB_3DSImporterDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Tahoma") ) );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerFileProps;
	sbSizerFileProps = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("File Properties") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerFileProps2;
	fgSizerFileProps2 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerFileProps2->AddGrowableCol( 1 );
	fgSizerFileProps2->SetFlexibleDirection( wxBOTH );
	fgSizerFileProps2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticFileName = new wxStaticText( this, wxID_ANY, _("File name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFileName->Wrap( -1 );
	fgSizerFileProps2->Add( m_staticFileName, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textFileName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textFileName->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerFileProps2->Add( m_textFileName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticFileSize = new wxStaticText( this, wxID_ANY, _("File size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFileSize->Wrap( -1 );
	fgSizerFileProps2->Add( m_staticFileSize, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_textFileSize = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textFileSize->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerFileProps2->Add( m_textFileSize, 0, wxALL|wxEXPAND, 5 );
	
	sbSizerFileProps->Add( fgSizerFileProps2, 0, wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerFileProps, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCurrentScene;
	sbSizerCurrentScene = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("What to do with current scene") ), wxVERTICAL );
	
	m_radioReplaceScene = new wxRadioButton( this, wxID_ANY, _("Completely replace current scene"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene->Add( m_radioReplaceScene, 0, wxALL|wxEXPAND, 5 );
	
	m_radioMergeScene = new wxRadioButton( this, wxID_ANY, _("Merge imported objects with current scene"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene->Add( m_radioMergeScene, 0, wxALL|wxEXPAND, 5 );
	
	m_radioReplaceSlot = new wxRadioButton( this, wxID_ANY, _("Replace a slot with the first imported object"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene->Add( m_radioReplaceSlot, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticSelectSlot = new wxStaticText( this, wxID_ANY, _("Choose a slot:"), wxDefaultPosition, wxSize( 180,-1 ), wxALIGN_RIGHT );
	m_staticSelectSlot->Wrap( -1 );
	bSizer62->Add( m_staticSelectSlot, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxArrayString m_choiceSlotsChoices;
	m_choiceSlots = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSlotsChoices, 0 );
	m_choiceSlots->SetSelection( 0 );
	bSizer62->Add( m_choiceSlots, 1, wxALL, 5 );
	
	sbSizerCurrentScene->Add( bSizer62, 1, wxEXPAND, 5 );
	
	m_radioReplaceBone = new wxRadioButton( this, wxID_ANY, _("Replace a bone with the first imported object"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene->Add( m_radioReplaceBone, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticSelectBone = new wxStaticText( this, wxID_ANY, _("Choose a bone:"), wxDefaultPosition, wxSize( 180,-1 ), wxALIGN_RIGHT );
	m_staticSelectBone->Wrap( -1 );
	bSizer63->Add( m_staticSelectBone, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxArrayString m_choiceBonesChoices;
	m_choiceBones = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBonesChoices, 0 );
	m_choiceBones->SetSelection( 0 );
	bSizer63->Add( m_choiceBones, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizerCurrentScene->Add( bSizer63, 1, wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerCurrentScene, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer115;
	bSizer115 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSpaceTransform;
	sbSizerSpaceTransform = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Space Transformation") ), wxHORIZONTAL );
	
	m_buttonSpaceTransform = new wxButton( this, wxID_ANY, _("Scale: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceTransform->Add( m_buttonSpaceTransform, 1, wxALL, 5 );
	
	bSizer115->Add( sbSizerSpaceTransform, 1, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerPostImport;
	sbSizerPostImport = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Post-Import Events") ), wxVERTICAL );
	
	m_checkWeldVertices = new wxCheckBox( this, wxID_ANY, _("Weld vertices of all imported meshes"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbSizerPostImport->Add( m_checkWeldVertices, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer61->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticThreshold = new wxStaticText( this, wxID_ANY, _("Threshold (cm):"), wxDefaultPosition, wxSize( -1,-1 ), wxALIGN_RIGHT );
	m_staticThreshold->Wrap( -1 );
	bSizer61->Add( m_staticThreshold, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textThreshold = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), 0 );
	bSizer61->Add( m_textThreshold, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_spinThreshold = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxSize( 17,-1 ), wxSP_ARROW_KEYS );
	bSizer61->Add( m_spinThreshold, 0, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	sbSizerPostImport->Add( bSizer61, 1, wxEXPAND, 5 );
	
	bSizer115->Add( sbSizerPostImport, 2, wxEXPAND|wxALL, 5 );
	
	bSizerMain->Add( bSizer115, 0, wxEXPAND, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbInfoWnd;
	sbInfoWnd = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Information Window") ), wxVERTICAL );
	
	m_staticInfoWnd = new wxStaticText( this, wxID_ANY, _("The information window can be shown you after the import."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticInfoWnd->Wrap( -1 );
	sbInfoWnd->Add( m_staticInfoWnd, 0, wxALL, 5 );
	
	m_checkShowInfoWnd = new wxCheckBox( this, wxID_ANY, _("Show information window"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbInfoWnd->Add( m_checkShowInfoWnd, 0, wxALL|wxEXPAND, 5 );
	
	m_checkAutoClose = new wxCheckBox( this, wxID_ANY, _("Close automatically"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbInfoWnd->Add( m_checkAutoClose, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerTimeBeforeClose;
	bSizerTimeBeforeClose = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTimeout = new wxStaticText( this, wxID_ANY, _("Time before close (seconds):"), wxDefaultPosition, wxSize( 180,-1 ), wxALIGN_RIGHT );
	m_staticTimeout->Wrap( -1 );
	bSizerTimeBeforeClose->Add( m_staticTimeout, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_spinTimeout = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 117,-1 ), wxSP_ARROW_KEYS, 0, 60, 5 );
	bSizerTimeBeforeClose->Add( m_spinTimeout, 0, wxALL, 5 );
	
	sbInfoWnd->Add( bSizerTimeBeforeClose, 1, wxEXPAND, 5 );
	
	bSizerMain->Add( sbInfoWnd, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 15, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCmdButtons->SetMinSize( wxSize( -1,45 ) ); 
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonImport = new wxButton( this, wxID_ANY, _("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonImport->SetDefault(); 
	bSizerCmdButtons->Add( m_buttonImport, 1, wxALL|wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonCancel, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	m_buttonOptions = new wxButton( this, wxID_ANY, _("Options"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonOptions, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonHelp = new wxButton( this, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonHelp, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_radioReplaceScene->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeScene->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioReplaceSlot->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioReplaceBone->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_buttonSpaceTransform->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnSpaceTransform ), NULL, this );
	m_checkWeldVertices->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnWeldVertices ), NULL, this );
	m_textThreshold->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnThresholdChanged ), NULL, this );
	m_spinThreshold->Connect( wxEVT_SCROLL_THUMBTRACK, wxSpinEventHandler( wxFB_3DSImporterDlg::OnThresholdSpin ), NULL, this );
	m_checkShowInfoWnd->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnShowInfoWnd ), NULL, this );
	m_checkAutoClose->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnAutoClose ), NULL, this );
	m_buttonImport->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnImport ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnCancel ), NULL, this );
	m_buttonOptions->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnOptions ), NULL, this );
	m_buttonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnHelp ), NULL, this );
}

wxFB_3DSImporterDlg::~wxFB_3DSImporterDlg()
{
	// Disconnect Events
	m_radioReplaceScene->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeScene->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioReplaceSlot->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioReplaceBone->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_buttonSpaceTransform->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnSpaceTransform ), NULL, this );
	m_checkWeldVertices->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnWeldVertices ), NULL, this );
	m_textThreshold->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnThresholdChanged ), NULL, this );
	m_spinThreshold->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxSpinEventHandler( wxFB_3DSImporterDlg::OnThresholdSpin ), NULL, this );
	m_checkShowInfoWnd->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnShowInfoWnd ), NULL, this );
	m_checkAutoClose->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnAutoClose ), NULL, this );
	m_buttonImport->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnImport ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnCancel ), NULL, this );
	m_buttonOptions->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnOptions ), NULL, this );
	m_buttonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSImporterDlg::OnHelp ), NULL, this );
}

wxFB_MeshImporterDlg::wxFB_MeshImporterDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Tahoma") ) );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerFileProps;
	sbSizerFileProps = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("File Properties") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerFileProps2;
	fgSizerFileProps2 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerFileProps2->AddGrowableCol( 1 );
	fgSizerFileProps2->SetFlexibleDirection( wxBOTH );
	fgSizerFileProps2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticFileName = new wxStaticText( this, wxID_ANY, _("File name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFileName->Wrap( -1 );
	fgSizerFileProps2->Add( m_staticFileName, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textFileName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textFileName->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerFileProps2->Add( m_textFileName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticFileSize = new wxStaticText( this, wxID_ANY, _("File size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFileSize->Wrap( -1 );
	fgSizerFileProps2->Add( m_staticFileSize, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_textFileSize = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textFileSize->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerFileProps2->Add( m_textFileSize, 0, wxALL|wxEXPAND, 5 );
	
	sbSizerFileProps->Add( fgSizerFileProps2, 0, wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerFileProps, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCurrentScene;
	sbSizerCurrentScene = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("What to do with current scene") ), wxVERTICAL );
	
	m_radioReplaceScene = new wxRadioButton( this, wxID_ANY, _("Completely replace current scene"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene->Add( m_radioReplaceScene, 0, wxALL|wxEXPAND, 5 );
	
	m_radioMergeScene = new wxRadioButton( this, wxID_ANY, _("Merge imported objects with current scene"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene->Add( m_radioMergeScene, 0, wxALL|wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerCurrentScene, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer115;
	bSizer115 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSpaceTransform;
	sbSizerSpaceTransform = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Space Transformation") ), wxHORIZONTAL );
	
	m_buttonSpaceTransform = new wxButton( this, wxID_ANY, _("Scale: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceTransform->Add( m_buttonSpaceTransform, 1, wxALL, 5 );
	
	bSizer115->Add( sbSizerSpaceTransform, 1, wxEXPAND|wxALL, 5 );
	
	bSizerMain->Add( bSizer115, 0, wxEXPAND, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbInfoWnd;
	sbInfoWnd = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Information Window") ), wxVERTICAL );
	
	m_staticInfoWnd = new wxStaticText( this, wxID_ANY, _("The information window can be shown you after the import."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticInfoWnd->Wrap( -1 );
	sbInfoWnd->Add( m_staticInfoWnd, 0, wxALL, 5 );
	
	m_checkShowInfoWnd = new wxCheckBox( this, wxID_ANY, _("Show information window"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbInfoWnd->Add( m_checkShowInfoWnd, 0, wxALL|wxEXPAND, 5 );
	
	m_checkAutoClose = new wxCheckBox( this, wxID_ANY, _("Close automatically"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbInfoWnd->Add( m_checkAutoClose, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerTimeBeforeClose;
	bSizerTimeBeforeClose = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTimeout = new wxStaticText( this, wxID_ANY, _("Time before close (seconds):"), wxDefaultPosition, wxSize( 180,-1 ), wxALIGN_RIGHT );
	m_staticTimeout->Wrap( -1 );
	bSizerTimeBeforeClose->Add( m_staticTimeout, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_spinTimeout = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 117,-1 ), wxSP_ARROW_KEYS, 0, 60, 5 );
	bSizerTimeBeforeClose->Add( m_spinTimeout, 0, wxALL, 5 );
	
	sbInfoWnd->Add( bSizerTimeBeforeClose, 1, wxEXPAND, 5 );
	
	bSizerMain->Add( sbInfoWnd, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 15, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCmdButtons->SetMinSize( wxSize( -1,45 ) ); 
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonImport = new wxButton( this, wxID_ANY, _("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonImport->SetDefault(); 
	bSizerCmdButtons->Add( m_buttonImport, 1, wxALL|wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonCancel, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	m_buttonOptions = new wxButton( this, wxID_ANY, _("Options"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonOptions, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonHelp = new wxButton( this, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonHelp, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_radioReplaceScene->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeScene->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_buttonSpaceTransform->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnSpaceTransform ), NULL, this );
	m_checkShowInfoWnd->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnShowInfoWnd ), NULL, this );
	m_checkAutoClose->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnAutoClose ), NULL, this );
	m_buttonImport->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnImport ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnCancel ), NULL, this );
	m_buttonOptions->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnOptions ), NULL, this );
	m_buttonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnHelp ), NULL, this );
}

wxFB_MeshImporterDlg::~wxFB_MeshImporterDlg()
{
	// Disconnect Events
	m_radioReplaceScene->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeScene->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_buttonSpaceTransform->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnSpaceTransform ), NULL, this );
	m_checkShowInfoWnd->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnShowInfoWnd ), NULL, this );
	m_checkAutoClose->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnAutoClose ), NULL, this );
	m_buttonImport->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnImport ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnCancel ), NULL, this );
	m_buttonOptions->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnOptions ), NULL, this );
	m_buttonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshImporterDlg::OnHelp ), NULL, this );
}

wxFB_MeshInfoDlg::wxFB_MeshInfoDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Tahoma") ) );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerFileProps;
	sbSizerFileProps = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("File Properties") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerFileProps2;
	fgSizerFileProps2 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerFileProps2->AddGrowableCol( 1 );
	fgSizerFileProps2->SetFlexibleDirection( wxBOTH );
	fgSizerFileProps2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticFileName = new wxStaticText( this, wxID_ANY, _("File name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFileName->Wrap( -1 );
	fgSizerFileProps2->Add( m_staticFileName, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textFileName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textFileName->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerFileProps2->Add( m_textFileName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticFileSize = new wxStaticText( this, wxID_ANY, _("File size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFileSize->Wrap( -1 );
	fgSizerFileProps2->Add( m_staticFileSize, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_textFileSize = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textFileSize->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerFileProps2->Add( m_textFileSize, 0, wxALL|wxEXPAND, 5 );
	
	sbSizerFileProps->Add( fgSizerFileProps2, 0, wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerFileProps, 0, wxEXPAND|wxALL, 5 );
	
	m_sbSizerObjects = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Exported Objects") ), wxVERTICAL );
	
	m_listObjects = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( 600,300 ), wxLC_NO_SORT_HEADER|wxLC_REPORT );
	m_sbSizerObjects->Add( m_listObjects, 1, wxALL|wxEXPAND, 5 );
	
	m_staticWarning = new wxStaticText( this, wxID_ANY, _("Some objects have not been saved because they contain too many vertices or faces. \nNumber of vertices of one object must not exceed 65535, and number of faces must not exceed 65535 too.\nTry to split up objects colored red into several parts."), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticWarning->Wrap( -1 );
	m_staticWarning->SetForegroundColour( wxColour( 215, 0, 0 ) );
	
	m_sbSizerObjects->Add( m_staticWarning, 0, wxALL|wxEXPAND, 5 );
	
	bSizerMain->Add( m_sbSizerObjects, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 15, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCmdButtons->SetMinSize( wxSize( -1,45 ) ); 
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonClose = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonClose->SetDefault(); 
	bSizerCmdButtons->Add( m_buttonClose, 1, wxALL|wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	m_buttonStopTimer = new wxButton( this, wxID_ANY, _("Stop timer"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonStopTimer, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_buttonClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshInfoDlg::OnClose ), NULL, this );
	m_buttonStopTimer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshInfoDlg::OnStopTimer ), NULL, this );
}

wxFB_MeshInfoDlg::~wxFB_MeshInfoDlg()
{
	// Disconnect Events
	m_buttonClose->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshInfoDlg::OnClose ), NULL, this );
	m_buttonStopTimer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MeshInfoDlg::OnStopTimer ), NULL, this );
}

wxFB_MatRenParamsDlg::wxFB_MatRenParamsDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Tahoma") ) );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerMaterialfilter;
	sbSizerMaterialfilter = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Materialfilter") ), wxVERTICAL );
	
	wxBoxSizer* bSizerMaterialfilter;
	bSizerMaterialfilter = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticMatLibIniPath = new wxStaticText( this, wxID_ANY, _("Path to \"matlib.ini\":"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticMatLibIniPath->Wrap( -1 );
	bSizerMaterialfilter->Add( m_staticMatLibIniPath, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textMatLibIniPath = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textMatLibIniPath->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	bSizerMaterialfilter->Add( m_textMatLibIniPath, 1, wxALL, 5 );
	
	m_buttonBrowseMatLibIni = new wxButton( this, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizerMaterialfilter->Add( m_buttonBrowseMatLibIni, 0, wxALL, 5 );
	
	sbSizerMaterialfilter->Add( bSizerMaterialfilter, 0, wxEXPAND, 5 );
	
	m_staticInfo = new wxStaticText( this, wxID_ANY, _("Hint: Look for the \"matlib.ini\" file in the \"<gothic>\\_work\\tools\\data\" folder."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticInfo->Wrap( -1 );
	sbSizerMaterialfilter->Add( m_staticInfo, 0, wxALL, 5 );
	
	m_buttonLoadMaterialFilter = new wxButton( this, wxID_ANY, _("Load Materialfilter"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerMaterialfilter->Add( m_buttonLoadMaterialFilter, 0, wxALL|wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerMaterialfilter, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerKnownMaterials;
	sbSizerKnownMaterials = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Known Materials") ), wxVERTICAL );
	
	m_listKnownMaterials = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( 600,400 ), wxLC_NO_SORT_HEADER|wxLC_REPORT );
	sbSizerKnownMaterials->Add( m_listKnownMaterials, 1, wxALL|wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerKnownMaterials, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerUnknownMaterials;
	sbSizerUnknownMaterials = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Unknown Materials") ), wxVERTICAL );
	
	m_checkAutoNames = new wxCheckBox( this, wxID_ANY, _("Name unknown materials by diffuse texture map's file name"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbSizerUnknownMaterials->Add( m_checkAutoNames, 0, wxALL, 5 );
	
	bSizerMain->Add( sbSizerUnknownMaterials, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCmdButtons->SetMinSize( wxSize( -1,45 ) ); 
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonOK->SetDefault(); 
	bSizerCmdButtons->Add( m_buttonOK, 1, wxALL|wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonCancel, 1, wxEXPAND|wxALIGN_BOTTOM|wxALL, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_buttonBrowseMatLibIni->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MatRenParamsDlg::OnBrowseMatLibIni ), NULL, this );
	m_buttonLoadMaterialFilter->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MatRenParamsDlg::OnLoadMaterialFilter ), NULL, this );
	m_buttonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MatRenParamsDlg::OnOK ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MatRenParamsDlg::OnCancel ), NULL, this );
}

wxFB_MatRenParamsDlg::~wxFB_MatRenParamsDlg()
{
	// Disconnect Events
	m_buttonBrowseMatLibIni->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MatRenParamsDlg::OnBrowseMatLibIni ), NULL, this );
	m_buttonLoadMaterialFilter->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MatRenParamsDlg::OnLoadMaterialFilter ), NULL, this );
	m_buttonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MatRenParamsDlg::OnOK ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_MatRenParamsDlg::OnCancel ), NULL, this );
}

wxFB_3DSExporterDlg::wxFB_3DSExporterDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Tahoma") ) );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerMain2;
	bSizerMain2 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerObjects;
	sbSizerObjects = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Objects to Export") ), wxVERTICAL );
	
	wxArrayString m_listObjectsChoices;
	m_listObjects = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 200,400 ), m_listObjectsChoices, wxLB_EXTENDED|wxLB_SINGLE );
	sbSizerObjects->Add( m_listObjects, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNumSelected;
	bSizerNumSelected = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticNumSelected = new wxStaticText( this, wxID_ANY, _("Selected:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumSelected->Wrap( -1 );
	bSizerNumSelected->Add( m_staticNumSelected, 0, wxRIGHT|wxLEFT, 5 );
	
	m_textNumSelected = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxNO_BORDER );
	m_textNumSelected->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	bSizerNumSelected->Add( m_textNumSelected, 1, wxRIGHT|wxLEFT, 5 );
	
	sbSizerObjects->Add( bSizerNumSelected, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerObjectsCmd;
	bSizerObjectsCmd = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonAll = new wxButton( this, wxID_ANY, _("All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerObjectsCmd->Add( m_buttonAll, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonNone = new wxButton( this, wxID_ANY, _("None"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerObjectsCmd->Add( m_buttonNone, 0, wxALL, 5 );
	
	sbSizerObjects->Add( bSizerObjectsCmd, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizerMain2->Add( sbSizerObjects, 1, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizerMain3;
	bSizerMain3 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerCS;
	sbSizerCS = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Coordinate System") ), wxVERTICAL );
	
	m_radioWorldCS = new wxRadioButton( this, wxID_ANY, _("Transform vertices into world coordinate system"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCS->Add( m_radioWorldCS, 1, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer75->Add( 16, 0, 0, wxEXPAND, 5 );
	
	m_staticWorldCSDesc = new wxStaticText( this, wxID_ANY, _("Use this item for saving levels, and you will not need to attach all objects to one mesh before the export."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticWorldCSDesc->Wrap( 300 );
	bSizer75->Add( m_staticWorldCSDesc, 0, wxALL, 5 );
	
	sbSizerCS->Add( bSizer75, 0, wxEXPAND, 5 );
	
	m_radioLocalCS = new wxRadioButton( this, wxID_ANY, _("Keep vertices in local coordinate system"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCS->Add( m_radioLocalCS, 1, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer751;
	bSizer751 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer751->Add( 16, 0, 0, wxEXPAND, 5 );
	
	m_staticLocalCSDesc = new wxStaticText( this, wxID_ANY, _("Use this item for saving items and mobs. Vertices of any object will be saved relative to the object's pivot. The old versions of the 3ds exporter doesn't allow you to select one of these two choices, and they used local coordinate system always."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticLocalCSDesc->Wrap( 300 );
	bSizer751->Add( m_staticLocalCSDesc, 0, wxALL, 5 );
	
	sbSizerCS->Add( bSizer751, 0, wxEXPAND, 5 );
	
	bSizerMain3->Add( sbSizerCS, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerSpaceTransform;
	sbSizerSpaceTransform = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Space Transformation") ), wxHORIZONTAL );
	
	m_buttonSpaceTransform = new wxButton( this, wxID_ANY, _("Scale: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceTransform->Add( m_buttonSpaceTransform, 1, wxALL, 5 );
	
	bSizerMain3->Add( sbSizerSpaceTransform, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerRenameMaterials;
	sbSizerRenameMaterials = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Material Autorenaming") ), wxHORIZONTAL );
	
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );
	
	m_checkRenameMaterials = new wxCheckBox( this, wxID_ANY, _("Rename materials"), wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer78->Add( m_checkRenameMaterials, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonMatRenParams = new wxButton( this, wxID_ANY, _("Parameters..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( m_buttonMatRenParams, 0, wxALL, 5 );
	
	sbSizerRenameMaterials->Add( bSizer78, 1, wxEXPAND, 5 );
	
	bSizerMain3->Add( sbSizerRenameMaterials, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbInfoWnd;
	sbInfoWnd = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Information Window") ), wxVERTICAL );
	
	m_staticInfoWnd = new wxStaticText( this, wxID_ANY, _("The information window can be shown you after the export."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticInfoWnd->Wrap( -1 );
	sbInfoWnd->Add( m_staticInfoWnd, 0, wxALL, 5 );
	
	m_checkShowInfoWnd = new wxCheckBox( this, wxID_ANY, _("Show information window"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbInfoWnd->Add( m_checkShowInfoWnd, 0, wxALL|wxEXPAND, 5 );
	
	m_checkAutoClose = new wxCheckBox( this, wxID_ANY, _("Close automatically"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbInfoWnd->Add( m_checkAutoClose, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerTimeBeforeClose;
	bSizerTimeBeforeClose = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTimeout = new wxStaticText( this, wxID_ANY, _("Time before close (seconds):"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticTimeout->Wrap( -1 );
	bSizerTimeBeforeClose->Add( m_staticTimeout, 1, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_spinTimeout = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 60, 5 );
	bSizerTimeBeforeClose->Add( m_spinTimeout, 0, wxALL, 5 );
	
	sbInfoWnd->Add( bSizerTimeBeforeClose, 0, wxEXPAND, 5 );
	
	bSizerMain3->Add( sbInfoWnd, 1, wxEXPAND|wxALL, 5 );
	
	bSizerMain2->Add( bSizerMain3, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxVERTICAL );
	
	m_buttonExport = new wxButton( this, wxID_ANY, _("Export"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonExport->SetDefault(); 
	m_buttonExport->SetMinSize( wxSize( -1,30 ) );
	
	bSizerCmdButtons->Add( m_buttonExport, 0, wxALL|wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonCancel->SetMinSize( wxSize( -1,30 ) );
	
	bSizerCmdButtons->Add( m_buttonCancel, 0, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	m_buttonOptions = new wxButton( this, wxID_ANY, _("Options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonOptions->SetMinSize( wxSize( -1,30 ) );
	
	bSizerCmdButtons->Add( m_buttonOptions, 0, wxALL|wxEXPAND, 5 );
	
	m_buttonHelp = new wxButton( this, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonHelp->SetMinSize( wxSize( -1,30 ) );
	
	bSizerCmdButtons->Add( m_buttonHelp, 0, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	bSizerMain2->Add( bSizerCmdButtons, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	bSizerMain->Add( bSizerMain2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerFileName;
	bSizerFileName = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizerFileProps;
	fgSizerFileProps = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerFileProps->AddGrowableCol( 1 );
	fgSizerFileProps->SetFlexibleDirection( wxBOTH );
	fgSizerFileProps->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticFileName = new wxStaticText( this, wxID_ANY, _("File name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFileName->Wrap( -1 );
	fgSizerFileProps->Add( m_staticFileName, 0, wxTOP|wxLEFT, 5 );
	
	m_textFileName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxNO_BORDER );
	m_textFileName->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerFileProps->Add( m_textFileName, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	bSizerFileName->Add( fgSizerFileProps, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	bSizerMain->Add( bSizerFileName, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_listObjects->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnObjectDClicked ), NULL, this );
	m_listObjects->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnObjectSelected ), NULL, this );
	m_buttonAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnSelectAll ), NULL, this );
	m_buttonNone->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnSelectNone ), NULL, this );
	m_buttonSpaceTransform->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnSpaceTransform ), NULL, this );
	m_checkRenameMaterials->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnRenameMaterials ), NULL, this );
	m_buttonMatRenParams->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnMatRenParams ), NULL, this );
	m_checkShowInfoWnd->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnShowInfoWnd ), NULL, this );
	m_checkAutoClose->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnAutoClose ), NULL, this );
	m_buttonExport->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnExport ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnCancel ), NULL, this );
	m_buttonOptions->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnOptions ), NULL, this );
	m_buttonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnHelp ), NULL, this );
}

wxFB_3DSExporterDlg::~wxFB_3DSExporterDlg()
{
	// Disconnect Events
	m_listObjects->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnObjectDClicked ), NULL, this );
	m_listObjects->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnObjectSelected ), NULL, this );
	m_buttonAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnSelectAll ), NULL, this );
	m_buttonNone->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnSelectNone ), NULL, this );
	m_buttonSpaceTransform->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnSpaceTransform ), NULL, this );
	m_checkRenameMaterials->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnRenameMaterials ), NULL, this );
	m_buttonMatRenParams->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnMatRenParams ), NULL, this );
	m_checkShowInfoWnd->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnShowInfoWnd ), NULL, this );
	m_checkAutoClose->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnAutoClose ), NULL, this );
	m_buttonExport->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnExport ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnCancel ), NULL, this );
	m_buttonOptions->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnOptions ), NULL, this );
	m_buttonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_3DSExporterDlg::OnHelp ), NULL, this );
}

wxFB_ASCImporterDlg::wxFB_ASCImporterDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Tahoma") ) );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerFileProps;
	sbSizerFileProps = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("File Information") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerFileProps2;
	fgSizerFileProps2 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerFileProps2->AddGrowableCol( 1 );
	fgSizerFileProps2->SetFlexibleDirection( wxBOTH );
	fgSizerFileProps2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticFileName = new wxStaticText( this, wxID_ANY, _("File name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFileName->Wrap( -1 );
	fgSizerFileProps2->Add( m_staticFileName, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_textFileName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textFileName->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerFileProps2->Add( m_textFileName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticFileSize = new wxStaticText( this, wxID_ANY, _("File size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFileSize->Wrap( -1 );
	fgSizerFileProps2->Add( m_staticFileSize, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_textFileSize = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textFileSize->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerFileProps2->Add( m_textFileSize, 0, wxALL|wxEXPAND, 5 );
	
	sbSizerFileProps->Add( fgSizerFileProps2, 0, wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerFileProps, 0, wxEXPAND|wxALL, 5 );
	
	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelMorphMesh = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerMorphMesh;
	bSizerMorphMesh = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerModelInfo_MM;
	sbSizerModelInfo_MM = new wxStaticBoxSizer( new wxStaticBox( m_panelMorphMesh, wxID_ANY, _("Model Information") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerModelInfo_MM;
	fgSizerModelInfo_MM = new wxFlexGridSizer( 2, 8, 0, 0 );
	fgSizerModelInfo_MM->AddGrowableCol( 1 );
	fgSizerModelInfo_MM->AddGrowableCol( 2 );
	fgSizerModelInfo_MM->AddGrowableCol( 4 );
	fgSizerModelInfo_MM->AddGrowableCol( 5 );
	fgSizerModelInfo_MM->AddGrowableCol( 7 );
	fgSizerModelInfo_MM->SetFlexibleDirection( wxBOTH );
	fgSizerModelInfo_MM->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticNumMeshes_MM = new wxStaticText( m_panelMorphMesh, wxID_ANY, _("Num. Meshes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumMeshes_MM->Wrap( -1 );
	fgSizerModelInfo_MM->Add( m_staticNumMeshes_MM, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textNumMeshes_MM = new wxTextCtrl( m_panelMorphMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerModelInfo_MM->Add( m_textNumMeshes_MM, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerModelInfo_MM->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticNumSlots_MM = new wxStaticText( m_panelMorphMesh, wxID_ANY, _("Num. Slots:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumSlots_MM->Wrap( -1 );
	fgSizerModelInfo_MM->Add( m_staticNumSlots_MM, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textNumSlots_MM = new wxTextCtrl( m_panelMorphMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerModelInfo_MM->Add( m_textNumSlots_MM, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerModelInfo_MM->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticNumBones_MM = new wxStaticText( m_panelMorphMesh, wxID_ANY, _("Num. Bones:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumBones_MM->Wrap( -1 );
	fgSizerModelInfo_MM->Add( m_staticNumBones_MM, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textNumBones_MM = new wxTextCtrl( m_panelMorphMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerModelInfo_MM->Add( m_textNumBones_MM, 0, wxALL|wxEXPAND, 5 );
	
	sbSizerModelInfo_MM->Add( fgSizerModelInfo_MM, 1, wxEXPAND, 5 );
	
	bSizerMorphMesh->Add( sbSizerModelInfo_MM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMorphMesh->Add( 0, 7, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCurrentScene_MM;
	sbSizerCurrentScene_MM = new wxStaticBoxSizer( new wxStaticBox( m_panelMorphMesh, wxID_ANY, _("What to do with current scene") ), wxVERTICAL );
	
	m_radioReplaceScene_MM = new wxRadioButton( m_panelMorphMesh, wxID_ANY, _("Completely replace current scene"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene_MM->Add( m_radioReplaceScene_MM, 0, wxALL|wxEXPAND, 5 );
	
	m_radioMergeScene_MM = new wxRadioButton( m_panelMorphMesh, wxID_ANY, _("Merge imported objects with current scene"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene_MM->Add( m_radioMergeScene_MM, 0, wxALL|wxEXPAND, 5 );
	
	m_radioLinkToSlot_MM = new wxRadioButton( m_panelMorphMesh, wxID_ANY, _("Link root of imported objects to a slot"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene_MM->Add( m_radioLinkToSlot_MM, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticChooseSlot_MM = new wxStaticText( m_panelMorphMesh, wxID_ANY, _("Choose a slot:"), wxDefaultPosition, wxSize( 160,-1 ), wxALIGN_RIGHT );
	m_staticChooseSlot_MM->Wrap( -1 );
	bSizer64->Add( m_staticChooseSlot_MM, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxArrayString m_choiceSlots_MMChoices;
	m_choiceSlots_MM = new wxChoice( m_panelMorphMesh, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSlots_MMChoices, 0 );
	m_choiceSlots_MM->SetSelection( 0 );
	bSizer64->Add( m_choiceSlots_MM, 1, wxALL|wxEXPAND, 5 );
	
	sbSizerCurrentScene_MM->Add( bSizer64, 1, wxEXPAND, 5 );
	
	m_radioLinkToBone_MM = new wxRadioButton( m_panelMorphMesh, wxID_ANY, _("Link root of imported objects to a bone"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene_MM->Add( m_radioLinkToBone_MM, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticChooseBone_MM = new wxStaticText( m_panelMorphMesh, wxID_ANY, _("Choose a bone:"), wxDefaultPosition, wxSize( 160,-1 ), wxALIGN_RIGHT );
	m_staticChooseBone_MM->Wrap( -1 );
	bSizer65->Add( m_staticChooseBone_MM, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxArrayString m_choiceBones_MMChoices;
	m_choiceBones_MM = new wxChoice( m_panelMorphMesh, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBones_MMChoices, 0 );
	m_choiceBones_MM->SetSelection( 0 );
	bSizer65->Add( m_choiceBones_MM, 1, wxALL|wxEXPAND, 5 );
	
	sbSizerCurrentScene_MM->Add( bSizer65, 1, wxEXPAND, 5 );
	
	bSizerMorphMesh->Add( sbSizerCurrentScene_MM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMorphMesh->Add( 0, 7, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerPrefix_MM;
	sbSizerPrefix_MM = new wxStaticBoxSizer( new wxStaticBox( m_panelMorphMesh, wxID_ANY, _("Model prefix") ), wxVERTICAL );
	
	m_staticPrefixInfo_MM = new wxStaticText( m_panelMorphMesh, wxID_ANY, _("A model prefix is a string which is inserted before any object's name. By default the model prefix is an empty string. The model prefix can be used for importing and editing more than one model in the same scene."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticPrefixInfo_MM->Wrap( 450 );
	sbSizerPrefix_MM->Add( m_staticPrefixInfo_MM, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerPrefix_MM;
	bSizerPrefix_MM = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticPrefix_MM = new wxStaticText( m_panelMorphMesh, wxID_ANY, _("Type a new model prefix:"), wxDefaultPosition, wxSize( 160,-1 ), wxALIGN_RIGHT );
	m_staticPrefix_MM->Wrap( -1 );
	bSizerPrefix_MM->Add( m_staticPrefix_MM, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textPrefix_MM = new wxTextCtrl( m_panelMorphMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textPrefix_MM->SetMinSize( wxSize( 200,-1 ) );
	
	bSizerPrefix_MM->Add( m_textPrefix_MM, 1, wxALL, 5 );
	
	m_buttonAutoPrefix_MM = new wxButton( m_panelMorphMesh, wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerPrefix_MM->Add( m_buttonAutoPrefix_MM, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	sbSizerPrefix_MM->Add( bSizerPrefix_MM, 1, wxEXPAND, 5 );
	
	bSizerMorphMesh->Add( sbSizerPrefix_MM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMorphMesh->Add( 0, 7, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerSpaceTransform;
	bSizerSpaceTransform = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSpaceTransform_MM;
	sbSizerSpaceTransform_MM = new wxStaticBoxSizer( new wxStaticBox( m_panelMorphMesh, wxID_ANY, _("Space Transformation") ), wxHORIZONTAL );
	
	m_buttonSpaceTransform_MM = new wxButton( m_panelMorphMesh, wxID_ANY, _("Scale: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceTransform_MM->Add( m_buttonSpaceTransform_MM, 1, wxALL, 5 );
	
	bSizerSpaceTransform->Add( sbSizerSpaceTransform_MM, 1, wxALL, 5 );
	
	
	bSizerSpaceTransform->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerMorphMesh->Add( bSizerSpaceTransform, 1, wxEXPAND, 5 );
	
	m_panelMorphMesh->SetSizer( bSizerMorphMesh );
	m_panelMorphMesh->Layout();
	bSizerMorphMesh->Fit( m_panelMorphMesh );
	m_notebook->AddPage( m_panelMorphMesh, _("Morph Mesh"), false );
	m_panelMorphAnim = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerMorphAnim;
	bSizerMorphAnim = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerAnimInfo_MA;
	sbSizerAnimInfo_MA = new wxStaticBoxSizer( new wxStaticBox( m_panelMorphAnim, wxID_ANY, _("Animation Information") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerAnimInfo_MA;
	fgSizerAnimInfo_MA = new wxFlexGridSizer( 2, 8, 0, 0 );
	fgSizerAnimInfo_MA->AddGrowableCol( 1 );
	fgSizerAnimInfo_MA->AddGrowableCol( 2 );
	fgSizerAnimInfo_MA->AddGrowableCol( 4 );
	fgSizerAnimInfo_MA->AddGrowableCol( 5 );
	fgSizerAnimInfo_MA->AddGrowableCol( 7 );
	fgSizerAnimInfo_MA->SetFlexibleDirection( wxBOTH );
	fgSizerAnimInfo_MA->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticFirstFrame_MA = new wxStaticText( m_panelMorphAnim, wxID_ANY, _("First Frame:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFirstFrame_MA->Wrap( -1 );
	fgSizerAnimInfo_MA->Add( m_staticFirstFrame_MA, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textFirstFrame_MA = new wxTextCtrl( m_panelMorphAnim, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerAnimInfo_MA->Add( m_textFirstFrame_MA, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerAnimInfo_MA->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticLastFrame_MA = new wxStaticText( m_panelMorphAnim, wxID_ANY, _("Last Frame:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticLastFrame_MA->Wrap( -1 );
	fgSizerAnimInfo_MA->Add( m_staticLastFrame_MA, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textLastFrame_MA = new wxTextCtrl( m_panelMorphAnim, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerAnimInfo_MA->Add( m_textLastFrame_MA, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerAnimInfo_MA->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticFPS_MA = new wxStaticText( m_panelMorphAnim, wxID_ANY, _("FPS:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFPS_MA->Wrap( -1 );
	fgSizerAnimInfo_MA->Add( m_staticFPS_MA, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textFPS_MA = new wxTextCtrl( m_panelMorphAnim, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerAnimInfo_MA->Add( m_textFPS_MA, 0, wxALL|wxEXPAND, 5 );
	
	sbSizerAnimInfo_MA->Add( fgSizerAnimInfo_MA, 1, wxEXPAND, 5 );
	
	bSizerMorphAnim->Add( sbSizerAnimInfo_MA, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMorphAnim->Add( 0, 7, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCurAnim_MA;
	sbSizerCurAnim_MA = new wxStaticBoxSizer( new wxStaticBox( m_panelMorphAnim, wxID_ANY, _("What to do with current animation") ), wxVERTICAL );
	
	m_radioReplaceAnim_MA = new wxRadioButton( m_panelMorphAnim, wxID_ANY, _("Completely replace current model's animation"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurAnim_MA->Add( m_radioReplaceAnim_MA, 0, wxALL|wxEXPAND, 5 );
	
	m_radioMergeAnim_MA = new wxRadioButton( m_panelMorphAnim, wxID_ANY, _("Merge an imported animation with current model's animation"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurAnim_MA->Add( m_radioMergeAnim_MA, 0, wxALL|wxEXPAND, 5 );
	
	bSizerMorphAnim->Add( sbSizerCurAnim_MA, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMorphAnim->Add( 0, 7, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerPrefix_MA;
	sbSizerPrefix_MA = new wxStaticBoxSizer( new wxStaticBox( m_panelMorphAnim, wxID_ANY, _("Model prefix") ), wxVERTICAL );
	
	m_staticPrefixInfo_MA = new wxStaticText( m_panelMorphAnim, wxID_ANY, _("The following list contains prefixes of models which can be animated. These prefixes are listed for appropriate models only. An appropriate model is a model which has a mesh with the same number of vertices as in the animation imported from the file."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticPrefixInfo_MA->Wrap( 450 );
	sbSizerPrefix_MA->Add( m_staticPrefixInfo_MA, 0, wxALL, 5 );
	
	wxBoxSizer* bSizerPrefix_MA;
	bSizerPrefix_MA = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticPrefix_MA = new wxStaticText( m_panelMorphAnim, wxID_ANY, _("Choose a model prefix:"), wxDefaultPosition, wxSize( 160,-1 ), wxALIGN_RIGHT );
	m_staticPrefix_MA->Wrap( -1 );
	bSizerPrefix_MA->Add( m_staticPrefix_MA, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxArrayString m_choicePrefixes_MAChoices;
	m_choicePrefixes_MA = new wxChoice( m_panelMorphAnim, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePrefixes_MAChoices, 0 );
	m_choicePrefixes_MA->SetSelection( 0 );
	m_choicePrefixes_MA->SetMinSize( wxSize( 200,-1 ) );
	
	bSizerPrefix_MA->Add( m_choicePrefixes_MA, 1, wxALL, 5 );
	
	sbSizerPrefix_MA->Add( bSizerPrefix_MA, 1, wxEXPAND, 5 );
	
	bSizerMorphAnim->Add( sbSizerPrefix_MA, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMorphAnim->Add( 0, 7, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerSpaceAndTimeTransform_MA;
	sbSizerSpaceAndTimeTransform_MA = new wxStaticBoxSizer( new wxStaticBox( m_panelMorphAnim, wxID_ANY, _("Space and Time Transformation") ), wxHORIZONTAL );
	
	m_buttonSpaceTransform_MA = new wxButton( m_panelMorphAnim, wxID_ANY, _("Scale: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceAndTimeTransform_MA->Add( m_buttonSpaceTransform_MA, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonTimeTransform_MA = new wxButton( m_panelMorphAnim, wxID_ANY, _("Frames: %1 -> %2, ..., %3 -> %4"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceAndTimeTransform_MA->Add( m_buttonTimeTransform_MA, 2, wxALL, 5 );
	
	bSizerMorphAnim->Add( sbSizerSpaceAndTimeTransform_MA, 0, wxEXPAND|wxALL, 5 );
	
	m_panelMorphAnim->SetSizer( bSizerMorphAnim );
	m_panelMorphAnim->Layout();
	bSizerMorphAnim->Fit( m_panelMorphAnim );
	m_notebook->AddPage( m_panelMorphAnim, _("Morph Animation"), false );
	m_panelStaticMesh = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerStaticMesh;
	bSizerStaticMesh = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerModelInfo_SM;
	sbSizerModelInfo_SM = new wxStaticBoxSizer( new wxStaticBox( m_panelStaticMesh, wxID_ANY, _("Model Information") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerModelInfo_SM;
	fgSizerModelInfo_SM = new wxFlexGridSizer( 2, 8, 0, 0 );
	fgSizerModelInfo_SM->AddGrowableCol( 1 );
	fgSizerModelInfo_SM->AddGrowableCol( 2 );
	fgSizerModelInfo_SM->AddGrowableCol( 4 );
	fgSizerModelInfo_SM->AddGrowableCol( 5 );
	fgSizerModelInfo_SM->AddGrowableCol( 7 );
	fgSizerModelInfo_SM->SetFlexibleDirection( wxBOTH );
	fgSizerModelInfo_SM->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticNumMeshes_SM = new wxStaticText( m_panelStaticMesh, wxID_ANY, _("Num. Meshes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumMeshes_SM->Wrap( -1 );
	fgSizerModelInfo_SM->Add( m_staticNumMeshes_SM, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textNumMeshes_SM = new wxTextCtrl( m_panelStaticMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerModelInfo_SM->Add( m_textNumMeshes_SM, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerModelInfo_SM->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticNumSlots_SM = new wxStaticText( m_panelStaticMesh, wxID_ANY, _("Num. Slots:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumSlots_SM->Wrap( -1 );
	fgSizerModelInfo_SM->Add( m_staticNumSlots_SM, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textNumSlots_SM = new wxTextCtrl( m_panelStaticMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerModelInfo_SM->Add( m_textNumSlots_SM, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerModelInfo_SM->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticNumBones_SM = new wxStaticText( m_panelStaticMesh, wxID_ANY, _("Num. Bones:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumBones_SM->Wrap( -1 );
	fgSizerModelInfo_SM->Add( m_staticNumBones_SM, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textNumBones_SM = new wxTextCtrl( m_panelStaticMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerModelInfo_SM->Add( m_textNumBones_SM, 0, wxALL|wxEXPAND, 5 );
	
	sbSizerModelInfo_SM->Add( fgSizerModelInfo_SM, 1, wxEXPAND, 5 );
	
	bSizerStaticMesh->Add( sbSizerModelInfo_SM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerStaticMesh->Add( 0, 7, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerCurrentScene_SM;
	sbSizerCurrentScene_SM = new wxStaticBoxSizer( new wxStaticBox( m_panelStaticMesh, wxID_ANY, _("What to do with current scene") ), wxVERTICAL );
	
	m_radioReplaceScene_SM = new wxRadioButton( m_panelStaticMesh, wxID_ANY, _("Completely replace current scene"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene_SM->Add( m_radioReplaceScene_SM, 0, wxALL|wxEXPAND, 5 );
	
	m_radioMergeScene_SM = new wxRadioButton( m_panelStaticMesh, wxID_ANY, _("Merge imported objects with current scene"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene_SM->Add( m_radioMergeScene_SM, 0, wxALL|wxEXPAND, 5 );
	
	bSizerStaticMesh->Add( sbSizerCurrentScene_SM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerStaticMesh->Add( 0, 7, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerPrefix_SM;
	sbSizerPrefix_SM = new wxStaticBoxSizer( new wxStaticBox( m_panelStaticMesh, wxID_ANY, _("Model prefix") ), wxVERTICAL );
	
	m_staticPrefixInfo_SM = new wxStaticText( m_panelStaticMesh, wxID_ANY, _("A model prefix is a string which is inserted before any object's name. By default the model prefix is an empty string. The model prefix can be used for importing and editing more than one model in the same scene."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticPrefixInfo_SM->Wrap( 450 );
	sbSizerPrefix_SM->Add( m_staticPrefixInfo_SM, 0, wxALL, 5 );
	
	wxBoxSizer* bSizerPrefix_SM;
	bSizerPrefix_SM = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticPrefix_SM = new wxStaticText( m_panelStaticMesh, wxID_ANY, _("Type a new model prefix:"), wxDefaultPosition, wxSize( 160,-1 ), wxALIGN_RIGHT );
	m_staticPrefix_SM->Wrap( -1 );
	bSizerPrefix_SM->Add( m_staticPrefix_SM, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textPrefix_SM = new wxTextCtrl( m_panelStaticMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textPrefix_SM->SetMinSize( wxSize( 200,-1 ) );
	
	bSizerPrefix_SM->Add( m_textPrefix_SM, 1, wxALL, 5 );
	
	m_buttonAutoPrefix_SM = new wxButton( m_panelStaticMesh, wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerPrefix_SM->Add( m_buttonAutoPrefix_SM, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	sbSizerPrefix_SM->Add( bSizerPrefix_SM, 1, wxEXPAND, 5 );
	
	bSizerStaticMesh->Add( sbSizerPrefix_SM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerStaticMesh->Add( 0, 7, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerBonesSlots_SM;
	bSizerBonesSlots_SM = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizerSpaceTransform_SM;
	sbSizerSpaceTransform_SM = new wxStaticBoxSizer( new wxStaticBox( m_panelStaticMesh, wxID_ANY, _("Space Transformation") ), wxHORIZONTAL );
	
	m_buttonSpaceTransform_SM = new wxButton( m_panelStaticMesh, wxID_ANY, _("Scale: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceTransform_SM->Add( m_buttonSpaceTransform_SM, 1, wxALL, 5 );
	
	bSizerBonesSlots_SM->Add( sbSizerSpaceTransform_SM, 1, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerBonesSlots_SM;
	sbSizerBonesSlots_SM = new wxStaticBoxSizer( new wxStaticBox( m_panelStaticMesh, wxID_ANY, _("Bones and slots") ), wxVERTICAL );
	
	m_checkSampleMeshes_SM = new wxCheckBox( m_panelStaticMesh, wxID_ANY, _("Use sample meshes from folder:"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbSizerBonesSlots_SM->Add( m_checkSampleMeshes_SM, 0, wxALL, 5 );
	
	wxBoxSizer* bSizerSampleMeshes_SM;
	bSizerSampleMeshes_SM = new wxBoxSizer( wxHORIZONTAL );
	
	m_textSampleMeshesDir_SM = new wxTextCtrl( m_panelStaticMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textSampleMeshesDir_SM->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	bSizerSampleMeshes_SM->Add( m_textSampleMeshesDir_SM, 1, wxALL, 5 );
	
	m_buttonSampleMeshesDir_SM = new wxButton( m_panelStaticMesh, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizerSampleMeshes_SM->Add( m_buttonSampleMeshesDir_SM, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	sbSizerBonesSlots_SM->Add( bSizerSampleMeshes_SM, 1, wxEXPAND, 5 );
	
	bSizerBonesSlots_SM->Add( sbSizerBonesSlots_SM, 1, wxALL|wxEXPAND, 5 );
	
	bSizerStaticMesh->Add( bSizerBonesSlots_SM, 0, wxEXPAND, 5 );
	
	m_panelStaticMesh->SetSizer( bSizerStaticMesh );
	m_panelStaticMesh->Layout();
	bSizerStaticMesh->Fit( m_panelStaticMesh );
	m_notebook->AddPage( m_panelStaticMesh, _("Static Model"), false );
	m_panelDynamicMesh = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelDynamicMesh->Hide();
	
	wxBoxSizer* bSizerDynamicMesh;
	bSizerDynamicMesh = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerModelInfo_DM;
	sbSizerModelInfo_DM = new wxStaticBoxSizer( new wxStaticBox( m_panelDynamicMesh, wxID_ANY, _("Model Information") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerModelInfo_DM;
	fgSizerModelInfo_DM = new wxFlexGridSizer( 2, 8, 0, 0 );
	fgSizerModelInfo_DM->AddGrowableCol( 1 );
	fgSizerModelInfo_DM->AddGrowableCol( 2 );
	fgSizerModelInfo_DM->AddGrowableCol( 4 );
	fgSizerModelInfo_DM->AddGrowableCol( 5 );
	fgSizerModelInfo_DM->AddGrowableCol( 7 );
	fgSizerModelInfo_DM->SetFlexibleDirection( wxBOTH );
	fgSizerModelInfo_DM->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticNumMeshes_DM = new wxStaticText( m_panelDynamicMesh, wxID_ANY, _("Num. Meshes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumMeshes_DM->Wrap( -1 );
	fgSizerModelInfo_DM->Add( m_staticNumMeshes_DM, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textNumMeshes_DM = new wxTextCtrl( m_panelDynamicMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerModelInfo_DM->Add( m_textNumMeshes_DM, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerModelInfo_DM->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticNumSlots_DM = new wxStaticText( m_panelDynamicMesh, wxID_ANY, _("Num. Slots:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumSlots_DM->Wrap( -1 );
	fgSizerModelInfo_DM->Add( m_staticNumSlots_DM, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textNumSlots_DM = new wxTextCtrl( m_panelDynamicMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerModelInfo_DM->Add( m_textNumSlots_DM, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerModelInfo_DM->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticNumBones_DM = new wxStaticText( m_panelDynamicMesh, wxID_ANY, _("Num. Bones:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumBones_DM->Wrap( -1 );
	fgSizerModelInfo_DM->Add( m_staticNumBones_DM, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textNumBones_DM = new wxTextCtrl( m_panelDynamicMesh, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerModelInfo_DM->Add( m_textNumBones_DM, 0, wxALL|wxEXPAND, 5 );
	
	sbSizerModelInfo_DM->Add( fgSizerModelInfo_DM, 1, wxEXPAND, 5 );
	
	bSizerDynamicMesh->Add( sbSizerModelInfo_DM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerDynamicMesh->Add( 0, 7, 0, wxEXPAND, 5 );
	
	m_notebook_DM = new wxCheckNotebook( m_panelDynamicMesh, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelNewModel_DM = new wxPanel( m_notebook_DM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerNewModel_DM;
	bSizerNewModel_DM = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerCurrentScene_NDM;
	sbSizerCurrentScene_NDM = new wxStaticBoxSizer( new wxStaticBox( m_panelNewModel_DM, wxID_ANY, _("What to do with current scene") ), wxVERTICAL );
	
	m_radioReplaceScene_NDM = new wxRadioButton( m_panelNewModel_DM, wxID_ANY, _("Completely replace current scene"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	sbSizerCurrentScene_NDM->Add( m_radioReplaceScene_NDM, 0, wxALL|wxEXPAND, 5 );
	
	m_radioMergeScene_NDM = new wxRadioButton( m_panelNewModel_DM, wxID_ANY, _("Merge imported objects with current scene"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene_NDM->Add( m_radioMergeScene_NDM, 0, wxALL|wxEXPAND, 5 );
	
	bSizerNewModel_DM->Add( sbSizerCurrentScene_NDM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerNewModel_DM->Add( 0, 7, 0, 0, 5 );
	
	wxStaticBoxSizer* sbSizerPrefix_NDM;
	sbSizerPrefix_NDM = new wxStaticBoxSizer( new wxStaticBox( m_panelNewModel_DM, wxID_ANY, _("Model prefix") ), wxVERTICAL );
	
	m_staticPrefixInfo_NDM = new wxStaticText( m_panelNewModel_DM, wxID_ANY, _("A model prefix is a string which is inserted before any object's name. By default the model prefix is an empty string. The model prefix can be used for importing and editing more than one model in the same scene."), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE );
	m_staticPrefixInfo_NDM->Wrap( 450 );
	sbSizerPrefix_NDM->Add( m_staticPrefixInfo_NDM, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerPrefix_NDM;
	bSizerPrefix_NDM = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticPrefix_NDM = new wxStaticText( m_panelNewModel_DM, wxID_ANY, _("Type a new model prefix:"), wxDefaultPosition, wxSize( 160,-1 ), wxALIGN_RIGHT );
	m_staticPrefix_NDM->Wrap( -1 );
	bSizerPrefix_NDM->Add( m_staticPrefix_NDM, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textPrefix_NDM = new wxTextCtrl( m_panelNewModel_DM, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_textPrefix_NDM->SetMinSize( wxSize( 200,-1 ) );
	
	bSizerPrefix_NDM->Add( m_textPrefix_NDM, 1, wxALL, 5 );
	
	m_buttonAutoPrefix_NDM = new wxButton( m_panelNewModel_DM, wxID_ANY, _("Auto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerPrefix_NDM->Add( m_buttonAutoPrefix_NDM, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	sbSizerPrefix_NDM->Add( bSizerPrefix_NDM, 1, wxEXPAND, 5 );
	
	bSizerNewModel_DM->Add( sbSizerPrefix_NDM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerNewModel_DM->Add( 0, 7, 0, 0, 5 );
	
	wxBoxSizer* bSizerSkinningBonesSlots_NDM;
	bSizerSkinningBonesSlots_NDM = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer116;
	bSizer116 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerSkinning_NDM;
	sbSizerSkinning_NDM = new wxStaticBoxSizer( new wxStaticBox( m_panelNewModel_DM, wxID_ANY, _("Skinning method") ), wxVERTICAL );
	
	wxArrayString m_listSkinTypes_NDMChoices;
	m_listSkinTypes_NDM = new wxCheckListBox( m_panelNewModel_DM, wxID_ANY, wxDefaultPosition, wxSize( -1,70 ), m_listSkinTypes_NDMChoices, wxLB_EXTENDED|wxLB_SINGLE );
	sbSizerSkinning_NDM->Add( m_listSkinTypes_NDM, 0, wxALL|wxEXPAND, 5 );
	
	bSizer116->Add( sbSizerSkinning_NDM, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerSpaceTransform_NDM;
	sbSizerSpaceTransform_NDM = new wxStaticBoxSizer( new wxStaticBox( m_panelNewModel_DM, wxID_ANY, _("Space Transformation") ), wxHORIZONTAL );
	
	m_buttonSpaceTransform_NDM = new wxButton( m_panelNewModel_DM, wxID_ANY, _("Scale: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceTransform_NDM->Add( m_buttonSpaceTransform_NDM, 1, wxALL, 5 );
	
	bSizer116->Add( sbSizerSpaceTransform_NDM, 0, wxALL|wxEXPAND, 5 );
	
	bSizerSkinningBonesSlots_NDM->Add( bSizer116, 1, wxEXPAND, 5 );
	
	
	bSizerSkinningBonesSlots_NDM->Add( 7, 0, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerBonesSlots_NDM;
	sbSizerBonesSlots_NDM = new wxStaticBoxSizer( new wxStaticBox( m_panelNewModel_DM, wxID_ANY, _("Bones and slots") ), wxVERTICAL );
	
	m_checkConnectBones_NDM = new wxCheckBox( m_panelNewModel_DM, wxID_ANY, _("Try to connect bones"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbSizerBonesSlots_NDM->Add( m_checkConnectBones_NDM, 0, wxALL, 5 );
	
	m_checkSampleMeshes_NDM = new wxCheckBox( m_panelNewModel_DM, wxID_ANY, _("Use sample meshes from folder:"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sbSizerBonesSlots_NDM->Add( m_checkSampleMeshes_NDM, 0, wxALL, 5 );
	
	wxBoxSizer* bSizerSampleMeshes_NDM;
	bSizerSampleMeshes_NDM = new wxBoxSizer( wxHORIZONTAL );
	
	m_textSampleMeshesDir_NDM = new wxTextCtrl( m_panelNewModel_DM, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textSampleMeshesDir_NDM->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	bSizerSampleMeshes_NDM->Add( m_textSampleMeshesDir_NDM, 1, wxALL, 5 );
	
	m_buttonSampleMeshesDir_NDM = new wxButton( m_panelNewModel_DM, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizerSampleMeshes_NDM->Add( m_buttonSampleMeshesDir_NDM, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	sbSizerBonesSlots_NDM->Add( bSizerSampleMeshes_NDM, 1, wxEXPAND, 5 );
	
	bSizerSkinningBonesSlots_NDM->Add( sbSizerBonesSlots_NDM, 1, wxALL|wxEXPAND, 5 );
	
	bSizerNewModel_DM->Add( bSizerSkinningBonesSlots_NDM, 0, wxEXPAND, 5 );
	
	m_panelNewModel_DM->SetSizer( bSizerNewModel_DM );
	m_panelNewModel_DM->Layout();
	bSizerNewModel_DM->Fit( m_panelNewModel_DM );
	m_notebook_DM->AddPage( m_panelNewModel_DM, _("Create a new model"), true );
	m_panelMergeModel_DM = new wxPanel( m_notebook_DM, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerMergeModel;
	bSizerMergeModel = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerCurrentScene_MDM;
	sbSizerCurrentScene_MDM = new wxStaticBoxSizer( new wxStaticBox( m_panelMergeModel_DM, wxID_ANY, _("What to do with the existing model") ), wxVERTICAL );
	
	m_radioReplaceSkin_MDM = new wxRadioButton( m_panelMergeModel_DM, wxID_ANY, _("Replace current model's skin with an imported skin"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	sbSizerCurrentScene_MDM->Add( m_radioReplaceSkin_MDM, 0, wxALL, 5 );
	
	m_radioMergeSkin_MDM = new wxRadioButton( m_panelMergeModel_DM, wxID_ANY, _("Merge current model's skin with an imported skin"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurrentScene_MDM->Add( m_radioMergeSkin_MDM, 0, wxALL, 5 );
	
	bSizerMergeModel->Add( sbSizerCurrentScene_MDM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMergeModel->Add( 0, 7, 0, 0, 5 );
	
	wxStaticBoxSizer* sbSizerPrefix_MDM;
	sbSizerPrefix_MDM = new wxStaticBoxSizer( new wxStaticBox( m_panelMergeModel_DM, wxID_ANY, _("Model prefix") ), wxVERTICAL );
	
	m_staticPrefixInfo_MDM = new wxStaticText( m_panelMergeModel_DM, wxID_ANY, _("The following list contains prefixes of models which can be skinned with meshes imported from the file. These prefixes are listed for appropriate models only. An appropriate model is a model which has all the same bones' and slots' names as in the model imported from the file."), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE );
	m_staticPrefixInfo_MDM->Wrap( 450 );
	sbSizerPrefix_MDM->Add( m_staticPrefixInfo_MDM, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerPrefix_MDM;
	bSizerPrefix_MDM = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticPrefix_MDM = new wxStaticText( m_panelMergeModel_DM, wxID_ANY, _("Choose a model prefix:"), wxDefaultPosition, wxSize( 160,-1 ), wxALIGN_RIGHT );
	m_staticPrefix_MDM->Wrap( -1 );
	bSizerPrefix_MDM->Add( m_staticPrefix_MDM, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxArrayString m_choicePrefixes_MDMChoices;
	m_choicePrefixes_MDM = new wxChoice( m_panelMergeModel_DM, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), m_choicePrefixes_MDMChoices, 0 );
	m_choicePrefixes_MDM->SetSelection( 0 );
	bSizerPrefix_MDM->Add( m_choicePrefixes_MDM, 1, wxALL, 5 );
	
	sbSizerPrefix_MDM->Add( bSizerPrefix_MDM, 1, wxEXPAND, 5 );
	
	bSizerMergeModel->Add( sbSizerPrefix_MDM, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMergeModel->Add( 0, 7, 0, 0, 5 );
	
	wxBoxSizer* bSizer117;
	bSizer117 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizerSkinningBoneCre_MDM;
	bSizerSkinningBoneCre_MDM = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerSkinning_MDM;
	sbSizerSkinning_MDM = new wxStaticBoxSizer( new wxStaticBox( m_panelMergeModel_DM, wxID_ANY, _("Skinning method") ), wxVERTICAL );
	
	wxArrayString m_listSkinTypes_MDMChoices;
	m_listSkinTypes_MDM = new wxCheckListBox( m_panelMergeModel_DM, wxID_ANY, wxDefaultPosition, wxSize( -1,70 ), m_listSkinTypes_MDMChoices, wxLB_EXTENDED|wxLB_SINGLE );
	sbSizerSkinning_MDM->Add( m_listSkinTypes_MDM, 0, wxALL|wxEXPAND, 5 );
	
	bSizerSkinningBoneCre_MDM->Add( sbSizerSkinning_MDM, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerSpaceTransform_MDM;
	sbSizerSpaceTransform_MDM = new wxStaticBoxSizer( new wxStaticBox( m_panelMergeModel_DM, wxID_ANY, _("Space Transformation") ), wxHORIZONTAL );
	
	m_buttonSpaceTransform_MDM = new wxButton( m_panelMergeModel_DM, wxID_ANY, _("Scale: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceTransform_MDM->Add( m_buttonSpaceTransform_MDM, 1, wxALL, 5 );
	
	bSizerSkinningBoneCre_MDM->Add( sbSizerSpaceTransform_MDM, 0, wxEXPAND|wxALL, 5 );
	
	bSizer117->Add( bSizerSkinningBoneCre_MDM, 1, wxEXPAND, 5 );
	
	
	bSizer117->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerMergeModel->Add( bSizer117, 1, wxEXPAND, 5 );
	
	m_panelMergeModel_DM->SetSizer( bSizerMergeModel );
	m_panelMergeModel_DM->Layout();
	bSizerMergeModel->Fit( m_panelMergeModel_DM );
	m_notebook_DM->AddPage( m_panelMergeModel_DM, _("Merge with an existing model"), false );
	
	bSizerDynamicMesh->Add( m_notebook_DM, 0, wxALL|wxEXPAND, 5 );
	
	m_panelDynamicMesh->SetSizer( bSizerDynamicMesh );
	m_panelDynamicMesh->Layout();
	bSizerDynamicMesh->Fit( m_panelDynamicMesh );
	m_notebook->AddPage( m_panelDynamicMesh, _("Dynamic Model"), true );
	m_panelDynamicAnim = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelDynamicAnim->Hide();
	
	wxBoxSizer* bSizerDynamicAnim;
	bSizerDynamicAnim = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerAnimInfo_DA;
	sbSizerAnimInfo_DA = new wxStaticBoxSizer( new wxStaticBox( m_panelDynamicAnim, wxID_ANY, _("Animation Information") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerAnimInfo_DA;
	fgSizerAnimInfo_DA = new wxFlexGridSizer( 2, 8, 0, 0 );
	fgSizerAnimInfo_DA->AddGrowableCol( 1 );
	fgSizerAnimInfo_DA->AddGrowableCol( 2 );
	fgSizerAnimInfo_DA->AddGrowableCol( 4 );
	fgSizerAnimInfo_DA->AddGrowableCol( 5 );
	fgSizerAnimInfo_DA->AddGrowableCol( 7 );
	fgSizerAnimInfo_DA->SetFlexibleDirection( wxBOTH );
	fgSizerAnimInfo_DA->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticFirstFrame_DA = new wxStaticText( m_panelDynamicAnim, wxID_ANY, _("First Frame:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFirstFrame_DA->Wrap( -1 );
	fgSizerAnimInfo_DA->Add( m_staticFirstFrame_DA, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textFirstFrame_DA = new wxTextCtrl( m_panelDynamicAnim, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerAnimInfo_DA->Add( m_textFirstFrame_DA, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerAnimInfo_DA->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticLastFrame_DA = new wxStaticText( m_panelDynamicAnim, wxID_ANY, _("Last Frame:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticLastFrame_DA->Wrap( -1 );
	fgSizerAnimInfo_DA->Add( m_staticLastFrame_DA, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textLastFrame_DA = new wxTextCtrl( m_panelDynamicAnim, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerAnimInfo_DA->Add( m_textLastFrame_DA, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizerAnimInfo_DA->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticFPS_DA = new wxStaticText( m_panelDynamicAnim, wxID_ANY, _("FPS:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFPS_DA->Wrap( -1 );
	fgSizerAnimInfo_DA->Add( m_staticFPS_DA, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textFPS_DA = new wxTextCtrl( m_panelDynamicAnim, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), wxTE_READONLY );
	fgSizerAnimInfo_DA->Add( m_textFPS_DA, 0, wxALL|wxEXPAND, 5 );
	
	sbSizerAnimInfo_DA->Add( fgSizerAnimInfo_DA, 1, wxEXPAND, 5 );
	
	bSizerDynamicAnim->Add( sbSizerAnimInfo_DA, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerCurAnim_DA;
	sbSizerCurAnim_DA = new wxStaticBoxSizer( new wxStaticBox( m_panelDynamicAnim, wxID_ANY, _("What to do with current animation") ), wxVERTICAL );
	
	m_radioReplaceAnim_DA = new wxRadioButton( m_panelDynamicAnim, wxID_ANY, _("Completely replace current model's animation"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurAnim_DA->Add( m_radioReplaceAnim_DA, 0, wxALL|wxEXPAND, 5 );
	
	m_radioMergeAnim_DA = new wxRadioButton( m_panelDynamicAnim, wxID_ANY, _("Merge an imported animation with current model's animation"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerCurAnim_DA->Add( m_radioMergeAnim_DA, 0, wxALL|wxEXPAND, 5 );
	
	bSizerDynamicAnim->Add( sbSizerCurAnim_DA, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerPrefix_DA;
	sbSizerPrefix_DA = new wxStaticBoxSizer( new wxStaticBox( m_panelDynamicAnim, wxID_ANY, _("Model prefix") ), wxVERTICAL );
	
	m_staticPrefixInfo_DA = new wxStaticText( m_panelDynamicAnim, wxID_ANY, _("The following list contains prefixes of models which can be animated. These prefixes are listed for appropriate models only. An appropriate model is a model which has all the same bones' and slots' names as in the animation imported from the file."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticPrefixInfo_DA->Wrap( 450 );
	sbSizerPrefix_DA->Add( m_staticPrefixInfo_DA, 0, wxALL, 5 );
	
	wxBoxSizer* bSizerPrefix_DA;
	bSizerPrefix_DA = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticPrefix_DA = new wxStaticText( m_panelDynamicAnim, wxID_ANY, _("Choose a model prefix:"), wxDefaultPosition, wxSize( 160,-1 ), wxALIGN_RIGHT );
	m_staticPrefix_DA->Wrap( -1 );
	bSizerPrefix_DA->Add( m_staticPrefix_DA, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxArrayString m_choicePrefixes_DAChoices;
	m_choicePrefixes_DA = new wxChoice( m_panelDynamicAnim, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePrefixes_DAChoices, 0 );
	m_choicePrefixes_DA->SetSelection( 0 );
	m_choicePrefixes_DA->SetMinSize( wxSize( 200,-1 ) );
	
	bSizerPrefix_DA->Add( m_choicePrefixes_DA, 1, wxALL, 5 );
	
	sbSizerPrefix_DA->Add( bSizerPrefix_DA, 1, wxEXPAND, 5 );
	
	bSizerDynamicAnim->Add( sbSizerPrefix_DA, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerSpaceAndTimeTransform_DA;
	sbSizerSpaceAndTimeTransform_DA = new wxStaticBoxSizer( new wxStaticBox( m_panelDynamicAnim, wxID_ANY, _("Space and Time Transformation") ), wxHORIZONTAL );
	
	m_buttonSpaceTransform_DA = new wxButton( m_panelDynamicAnim, wxID_ANY, _("Scale: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceAndTimeTransform_DA->Add( m_buttonSpaceTransform_DA, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonTimeTransform_DA = new wxButton( m_panelDynamicAnim, wxID_ANY, _("Frames: %1 -> %2, ..., %3 -> %4"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceAndTimeTransform_DA->Add( m_buttonTimeTransform_DA, 2, wxALL, 5 );
	
	bSizerDynamicAnim->Add( sbSizerSpaceAndTimeTransform_DA, 0, wxEXPAND|wxALL, 5 );
	
	m_panelDynamicAnim->SetSizer( bSizerDynamicAnim );
	m_panelDynamicAnim->Layout();
	bSizerDynamicAnim->Fit( m_panelDynamicAnim );
	m_notebook->AddPage( m_panelDynamicAnim, _("Dynamic Model Animation"), false );
	
	bSizerMain->Add( m_notebook, 0, wxEXPAND | wxALL, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCmdButtons->SetMinSize( wxSize( -1,45 ) ); 
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonImport = new wxButton( this, wxID_ANY, _("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonImport->SetDefault(); 
	bSizerCmdButtons->Add( m_buttonImport, 1, wxALL|wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonCancel, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	m_buttonOptions = new wxButton( this, wxID_ANY, _("Options"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonOptions, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonHelp = new wxButton( this, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonHelp, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_radioReplaceScene_MM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeScene_MM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioLinkToSlot_MM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioLinkToBone_MM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_buttonAutoPrefix_MM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnAutoPrefix ), NULL, this );
	m_buttonSpaceTransform_MM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_radioReplaceAnim_MA->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnOperationChanged ), NULL, this );
	m_radioMergeAnim_MA->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnOperationChanged ), NULL, this );
	m_buttonSpaceTransform_MA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_buttonTimeTransform_MA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnTimeTransform ), NULL, this );
	m_radioReplaceScene_SM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeScene_SM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_buttonAutoPrefix_SM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnAutoPrefix ), NULL, this );
	m_buttonSpaceTransform_SM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_buttonSampleMeshesDir_SM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSampleMeshesDir ), NULL, this );
	m_radioReplaceScene_NDM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeScene_NDM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_buttonAutoPrefix_NDM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnAutoPrefix ), NULL, this );
	m_listSkinTypes_NDM->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_listSkinTypes_NDM->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_listSkinTypes_NDM->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_buttonSpaceTransform_NDM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_buttonSampleMeshesDir_NDM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSampleMeshesDir ), NULL, this );
	m_radioReplaceSkin_MDM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeSkin_MDM->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_listSkinTypes_MDM->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_listSkinTypes_MDM->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_listSkinTypes_MDM->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_buttonSpaceTransform_MDM->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_radioReplaceAnim_DA->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnOperationChanged ), NULL, this );
	m_radioMergeAnim_DA->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnOperationChanged ), NULL, this );
	m_buttonSpaceTransform_DA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_buttonTimeTransform_DA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnTimeTransform ), NULL, this );
	m_buttonImport->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnImport ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCancel ), NULL, this );
	m_buttonOptions->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnOptions ), NULL, this );
	m_buttonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnHelp ), NULL, this );
}

wxFB_ASCImporterDlg::~wxFB_ASCImporterDlg()
{
	// Disconnect Events
	m_radioReplaceScene_MM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeScene_MM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioLinkToSlot_MM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioLinkToBone_MM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_buttonAutoPrefix_MM->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnAutoPrefix ), NULL, this );
	m_buttonSpaceTransform_MM->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_radioReplaceAnim_MA->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnOperationChanged ), NULL, this );
	m_radioMergeAnim_MA->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnOperationChanged ), NULL, this );
	m_buttonSpaceTransform_MA->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_buttonTimeTransform_MA->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnTimeTransform ), NULL, this );
	m_radioReplaceScene_SM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeScene_SM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_buttonAutoPrefix_SM->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnAutoPrefix ), NULL, this );
	m_buttonSpaceTransform_SM->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_buttonSampleMeshesDir_SM->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSampleMeshesDir ), NULL, this );
	m_radioReplaceScene_NDM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeScene_NDM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_buttonAutoPrefix_NDM->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnAutoPrefix ), NULL, this );
	m_listSkinTypes_NDM->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_listSkinTypes_NDM->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_listSkinTypes_NDM->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_buttonSpaceTransform_NDM->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_buttonSampleMeshesDir_NDM->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSampleMeshesDir ), NULL, this );
	m_radioReplaceSkin_MDM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_radioMergeSkin_MDM->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCurSceneModeChanged ), NULL, this );
	m_listSkinTypes_MDM->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_listSkinTypes_MDM->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_listSkinTypes_MDM->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSkinTypeChanged ), NULL, this );
	m_buttonSpaceTransform_MDM->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_radioReplaceAnim_DA->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnOperationChanged ), NULL, this );
	m_radioMergeAnim_DA->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnOperationChanged ), NULL, this );
	m_buttonSpaceTransform_DA->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnSpaceTransform ), NULL, this );
	m_buttonTimeTransform_DA->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnTimeTransform ), NULL, this );
	m_buttonImport->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnImport ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnCancel ), NULL, this );
	m_buttonOptions->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnOptions ), NULL, this );
	m_buttonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCImporterDlg::OnHelp ), NULL, this );
}

wxFB_ASCExporterDlg::wxFB_ASCExporterDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 8, 74, 90, 90, false, wxT("Tahoma") ) );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizerExpObjs;
	bSizerExpObjs = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizerExpObjs;
	fgSizerExpObjs = new wxFlexGridSizer( 1, 3, 0, 0 );
	fgSizerExpObjs->AddGrowableCol( 1 );
	fgSizerExpObjs->AddGrowableRow( 0 );
	fgSizerExpObjs->SetFlexibleDirection( wxBOTH );
	fgSizerExpObjs->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizerExpObjsLeft;
	bSizerExpObjsLeft = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerModel;
	sbSizerModel = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Model to Export") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizerModel;
	fgSizerModel = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerModel->SetFlexibleDirection( wxBOTH );
	fgSizerModel->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticPrefix = new wxStaticText( this, wxID_ANY, _("Model prefix:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticPrefix->Wrap( -1 );
	fgSizerModel->Add( m_staticPrefix, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxArrayString m_choicePrefixesChoices;
	m_choicePrefixes = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), m_choicePrefixesChoices, 0 );
	m_choicePrefixes->SetSelection( 0 );
	fgSizerModel->Add( m_choicePrefixes, 1, wxALL, 5 );
	
	m_staticModelType = new wxStaticText( this, wxID_ANY, _("Model type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticModelType->Wrap( -1 );
	fgSizerModel->Add( m_staticModelType, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_textModelType = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textModelType->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerModel->Add( m_textModelType, 0, wxALL|wxEXPAND, 5 );
	
	sbSizerModel->Add( fgSizerModel, 1, wxEXPAND, 5 );
	
	bSizerExpObjsLeft->Add( sbSizerModel, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerExpObjsLeft->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerTypeOfExport;
	sbSizerTypeOfExport = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Type of Export") ), wxVERTICAL );
	
	wxBoxSizer* bSizerTypeOfExport;
	bSizerTypeOfExport = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );
	
	m_radioExportMesh = new wxRadioButton( this, wxID_ANY, _("Export mesh"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_radioExportMesh, 1, wxALL|wxEXPAND, 5 );
	
	m_radioExportAnimation = new wxRadioButton( this, wxID_ANY, _("Export animation"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_radioExportAnimation, 1, wxALL|wxEXPAND, 5 );
	
	bSizerTypeOfExport->Add( bSizer81, 1, wxEXPAND, 5 );
	
	sbSizerTypeOfExport->Add( bSizerTypeOfExport, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	bSizerExpObjsLeft->Add( sbSizerTypeOfExport, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerExpObjsLeft->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerSpaceAndTimeTransform;
	sbSizerSpaceAndTimeTransform = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Space and Time Transformation") ), wxHORIZONTAL );
	
	m_buttonSpaceTransform = new wxButton( this, wxID_ANY, _("Scale: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceAndTimeTransform->Add( m_buttonSpaceTransform, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonTimeTransform = new wxButton( this, wxID_ANY, _("Frames: %1 -> %2, ..., %3 -> %4"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSpaceAndTimeTransform->Add( m_buttonTimeTransform, 2, wxALL, 5 );
	
	bSizerExpObjsLeft->Add( sbSizerSpaceAndTimeTransform, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerExpObjsLeft->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer37;
	sbSizer37 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Information") ), wxVERTICAL );
	
	m_textInformation = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	m_textInformation->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	sbSizer37->Add( m_textInformation, 1, wxALL|wxEXPAND, 5 );
	
	bSizerExpObjsLeft->Add( sbSizer37, 1, wxEXPAND|wxALL, 5 );
	
	fgSizerExpObjs->Add( bSizerExpObjsLeft, 0, wxRIGHT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerExpObjsRight;
	bSizerExpObjsRight = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerObjects;
	sbSizerObjects = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Objects to Export") ), wxVERTICAL );
	
	m_treeObjects = new wxCheckTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxSize(300,240), wxTR_DEFAULT_STYLE|wxTR_SINGLE|wxTR_HIDE_ROOT );
	sbSizerObjects->Add( m_treeObjects, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizerNumSelected;
	bSizerNumSelected = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticNumSelected = new wxStaticText( this, wxID_ANY, _("Selected:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticNumSelected->Wrap( -1 );
	bSizerNumSelected->Add( m_staticNumSelected, 0, wxRIGHT|wxLEFT, 5 );
	
	m_textNumSelected = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxNO_BORDER );
	m_textNumSelected->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	bSizerNumSelected->Add( m_textNumSelected, 1, wxRIGHT|wxLEFT, 5 );
	
	sbSizerObjects->Add( bSizerNumSelected, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerObjectsCmd;
	bSizerObjectsCmd = new wxBoxSizer( wxHORIZONTAL );
	
	m_buttonAll = new wxButton( this, wxID_ANY, _("All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerObjectsCmd->Add( m_buttonAll, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonNone = new wxButton( this, wxID_ANY, _("None"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerObjectsCmd->Add( m_buttonNone, 0, wxALL, 5 );
	
	sbSizerObjects->Add( bSizerObjectsCmd, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizerExpObjsRight->Add( sbSizerObjects, 1, wxEXPAND|wxALL, 5 );
	
	fgSizerExpObjs->Add( bSizerExpObjsRight, 1, wxEXPAND|wxLEFT, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxVERTICAL );
	
	m_buttonExport = new wxButton( this, wxID_ANY, _("Export"), wxDefaultPosition, wxSize( -1,35 ), 0 );
	m_buttonExport->SetDefault(); 
	bSizerCmdButtons->Add( m_buttonExport, 1, wxALL|wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonCancel, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	m_buttonOptions = new wxButton( this, wxID_ANY, _("Options"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonOptions, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonHelp = new wxButton( this, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonHelp, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	fgSizerExpObjs->Add( bSizerCmdButtons, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizerExpObjs->Add( fgSizerExpObjs, 1, wxEXPAND, 5 );
	
	bSizerMain->Add( bSizerExpObjs, 1, wxEXPAND, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerFileName;
	bSizerFileName = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizerFileProps;
	fgSizerFileProps = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizerFileProps->AddGrowableCol( 1 );
	fgSizerFileProps->SetFlexibleDirection( wxBOTH );
	fgSizerFileProps->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticFileName = new wxStaticText( this, wxID_ANY, _("File name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFileName->Wrap( -1 );
	fgSizerFileProps->Add( m_staticFileName, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textFileName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxNO_BORDER );
	m_textFileName->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	fgSizerFileProps->Add( m_textFileName, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	bSizerFileName->Add( fgSizerFileProps, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	bSizerMain->Add( bSizerFileName, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	
	// Connect Events
	m_choicePrefixes->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnPrefixChanged ), NULL, this );
	m_radioExportMesh->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnTypeOfExportChanged ), NULL, this );
	m_radioExportAnimation->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnTypeOfExportChanged ), NULL, this );
	m_buttonSpaceTransform->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnSpaceTransform ), NULL, this );
	m_buttonTimeTransform->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnTimeTransform ), NULL, this );
	m_buttonAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnSelectAll ), NULL, this );
	m_buttonNone->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnSelectNone ), NULL, this );
	m_buttonExport->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnExport ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnCancel ), NULL, this );
	m_buttonOptions->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnOptions ), NULL, this );
	m_buttonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnHelp ), NULL, this );
}

wxFB_ASCExporterDlg::~wxFB_ASCExporterDlg()
{
	// Disconnect Events
	m_choicePrefixes->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnPrefixChanged ), NULL, this );
	m_radioExportMesh->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnTypeOfExportChanged ), NULL, this );
	m_radioExportAnimation->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnTypeOfExportChanged ), NULL, this );
	m_buttonSpaceTransform->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnSpaceTransform ), NULL, this );
	m_buttonTimeTransform->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnTimeTransform ), NULL, this );
	m_buttonAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnSelectAll ), NULL, this );
	m_buttonNone->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnSelectNone ), NULL, this );
	m_buttonExport->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnExport ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnCancel ), NULL, this );
	m_buttonOptions->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnOptions ), NULL, this );
	m_buttonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_ASCExporterDlg::OnHelp ), NULL, this );
}

wxFB_AboutDlg::wxFB_AboutDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer61->Add( 0, 10, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmapLogo = new wxStaticBitmap( this, wxID_ANY, wxBitmap( impexp_xpm ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( m_bitmapLogo, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );
	
	m_staticTitle = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTitle->Wrap( -1 );
	m_staticTitle->SetFont( wxFont( 25, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer53->Add( m_staticTitle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticReleaseDate = new wxStaticText( this, wxID_ANY, _("Release Date: %1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticReleaseDate->Wrap( -1 );
	m_staticReleaseDate->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer53->Add( m_staticReleaseDate, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer52->Add( bSizer53, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer59->Add( bSizer52, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticDescription = new wxStaticText( this, wxID_ANY, _("Open Source Import/Export Plugins\nfor games \"Gothic\" and \"Gothic II\""), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticDescription->Wrap( -1 );
	m_staticDescription->SetFont( wxFont( 13, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer59->Add( m_staticDescription, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer61->Add( bSizer59, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer61->Add( 0, 10, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxVERTICAL );
	
	m_staticDevelopedBy = new wxStaticText( this, wxID_ANY, _("Developed by:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDevelopedBy->Wrap( -1 );
	m_staticDevelopedBy->SetFont( wxFont( 10, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer60->Add( m_staticDevelopedBy, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticAuthor = new wxStaticText( this, wxID_ANY, _("Vitaly Baranov (Kerrax)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticAuthor->Wrap( -1 );
	m_staticAuthor->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer60->Add( m_staticAuthor, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticTranslatedBy = new wxStaticText( this, wxID_ANY, _("Translated to Language by:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTranslatedBy->Wrap( -1 );
	m_staticTranslatedBy->SetFont( wxFont( 10, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer60->Add( m_staticTranslatedBy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticTranslator = new wxStaticText( this, wxID_ANY, _("TranslatorName"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTranslator->Wrap( -1 );
	m_staticTranslator->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer60->Add( m_staticTranslator, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticDownloadPage = new wxStaticText( this, wxID_ANY, _("Home page:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticDownloadPage->Wrap( -1 );
	m_staticDownloadPage->SetFont( wxFont( 10, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer60->Add( m_staticDownloadPage, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_hyperlinkDownloadPage = new wxHyperlinkCtrl( this, wxID_ANY, _("..."), wxT("..."), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	m_hyperlinkDownloadPage->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer60->Add( m_hyperlinkDownloadPage, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticEngSupForum = new wxStaticText( this, wxID_ANY, _("English support forum:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticEngSupForum->Wrap( -1 );
	m_staticEngSupForum->SetFont( wxFont( 10, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer60->Add( m_staticEngSupForum, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_hyperlinkEngSupForum = new wxHyperlinkCtrl( this, wxID_ANY, _("..."), wxT("..."), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	m_hyperlinkEngSupForum->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer60->Add( m_hyperlinkEngSupForum, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticRusSupForum = new wxStaticText( this, wxID_ANY, _("Russian support forum:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticRusSupForum->Wrap( -1 );
	m_staticRusSupForum->SetFont( wxFont( 10, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer60->Add( m_staticRusSupForum, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_hyperlinkRusSupForum = new wxHyperlinkCtrl( this, wxID_ANY, _("..."), wxT("..."), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	m_hyperlinkRusSupForum->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer60->Add( m_hyperlinkRusSupForum, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer61->Add( bSizer60, 0, wxEXPAND, 5 );
	
	
	bSizer61->Add( 0, 10, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxVERTICAL );
	
	m_staticUsedComponents = new wxStaticText( this, wxID_ANY, _("Used free components:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticUsedComponents->Wrap( -1 );
	bSizer54->Add( m_staticUsedComponents, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_textUsedComponents = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	bSizer54->Add( m_textUsedComponents, 0, wxEXPAND|wxALL, 5 );
	
	bSizer61->Add( bSizer54, 0, wxEXPAND, 5 );
	
	bSizer62->Add( bSizer61, 1, wxEXPAND, 5 );
	
	m_bitmapCrazy = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	m_bitmapCrazy->SetBackgroundColour( wxColour( 128, 128, 128 ) );
	
	bSizer62->Add( m_bitmapCrazy, 0, wxALIGN_BOTTOM|wxEXPAND|wxALL, 5 );
	
	bSizerMain->Add( bSizer62, 1, wxEXPAND, 5 );
	
	
	bSizerMain->Add( 0, 15, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonClose = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonClose->SetDefault(); 
	bSizerCmdButtons->Add( m_buttonClose, 1, wxEXPAND|wxALL, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_buttonClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_AboutDlg::OnClose ), NULL, this );
}

wxFB_AboutDlg::~wxFB_AboutDlg()
{
	// Disconnect Events
	m_buttonClose->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_AboutDlg::OnClose ), NULL, this );
}

wxFB_TimeTransformImpDlg::wxFB_TimeTransformImpDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerFramesIndicesMapping;
	sbSizerFramesIndicesMapping = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Mapping of the File Frames' Indices to the Scene Frames' Indices") ), wxVERTICAL );
	
	wxGridBagSizer* gbSizerFramesIndicesMapping;
	gbSizerFramesIndicesMapping = new wxGridBagSizer( 0, 0 );
	gbSizerFramesIndicesMapping->SetFlexibleDirection( wxBOTH );
	gbSizerFramesIndicesMapping->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	gbSizerFramesIndicesMapping->SetEmptyCellSize( wxSize( 0,0 ) );
	
	m_staticIndexInFile = new wxStaticText( this, wxID_ANY, _("Frame's Index In File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticIndexInFile->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticIndexInFile, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticFrameInScene = new wxStaticText( this, wxID_ANY, _("Frame's Index In Scene"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFrameInScene->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticFrameInScene, wxGBPosition( 0, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticFirstFrame = new wxStaticText( this, wxID_ANY, _("First processing frame:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFirstFrame->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticFirstFrame, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_spinFirstInFile = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	gbSizerFramesIndicesMapping->Add( m_spinFirstInFile, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticFirstArrow = new wxStaticText( this, wxID_ANY, _("--->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFirstArrow->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticFirstArrow, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinFirstInScene = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	gbSizerFramesIndicesMapping->Add( m_spinFirstInScene, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticSecondFrame = new wxStaticText( this, wxID_ANY, _("Second processing frame:"), wxDefaultPosition, wxSize( -1,-1 ), wxALIGN_CENTRE );
	m_staticSecondFrame->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticSecondFrame, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_spinSecondInFile = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	m_spinSecondInFile->Enable( false );
	
	gbSizerFramesIndicesMapping->Add( m_spinSecondInFile, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticSecondArrow = new wxStaticText( this, wxID_ANY, _("--->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticSecondArrow->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticSecondArrow, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_spinSecondInScene = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	m_spinSecondInScene->Enable( false );
	
	gbSizerFramesIndicesMapping->Add( m_spinSecondInScene, wxGBPosition( 2, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticThirdFrame = new wxStaticText( this, wxID_ANY, _("Third processing frame:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticThirdFrame->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticThirdFrame, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_spinThirdInFile = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	m_spinThirdInFile->Enable( false );
	
	gbSizerFramesIndicesMapping->Add( m_spinThirdInFile, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticThirdArrow = new wxStaticText( this, wxID_ANY, _("--->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticThirdArrow->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticThirdArrow, wxGBPosition( 3, 2 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinThirdInScene = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	m_spinThirdInScene->Enable( false );
	
	gbSizerFramesIndicesMapping->Add( m_spinThirdInScene, wxGBPosition( 3, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticVDots = new wxStaticText( this, wxID_ANY, _(".\n.\n."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticVDots->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticVDots, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticLastFrame = new wxStaticText( this, wxID_ANY, _("Last processing frame:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticLastFrame->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticLastFrame, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_spinLastInFile = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	gbSizerFramesIndicesMapping->Add( m_spinLastInFile, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticLastArrow = new wxStaticText( this, wxID_ANY, _("--->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticLastArrow->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticLastArrow, wxGBPosition( 5, 2 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinLastInScene = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	m_spinLastInScene->Enable( false );
	
	gbSizerFramesIndicesMapping->Add( m_spinLastInScene, wxGBPosition( 5, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	sbSizerFramesIndicesMapping->Add( gbSizerFramesIndicesMapping, 0, wxALL, 5 );
	
	bSizerMain->Add( sbSizerFramesIndicesMapping, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCmdButtons->SetMinSize( wxSize( -1,45 ) ); 
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonOK, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonCancel, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_spinFirstInFile->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformImpDlg::OnFirstInFileChanged ), NULL, this );
	m_spinFirstInScene->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformImpDlg::OnFirstInSceneChanged ), NULL, this );
	m_spinLastInFile->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformImpDlg::OnLastInFileChanged ), NULL, this );
	m_buttonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_TimeTransformImpDlg::OnOK ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_TimeTransformImpDlg::OnCancel ), NULL, this );
}

wxFB_TimeTransformImpDlg::~wxFB_TimeTransformImpDlg()
{
	// Disconnect Events
	m_spinFirstInFile->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformImpDlg::OnFirstInFileChanged ), NULL, this );
	m_spinFirstInScene->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformImpDlg::OnFirstInSceneChanged ), NULL, this );
	m_spinLastInFile->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformImpDlg::OnLastInFileChanged ), NULL, this );
	m_buttonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_TimeTransformImpDlg::OnOK ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_TimeTransformImpDlg::OnCancel ), NULL, this );
}

wxFB_TimeTransformExpDlg::wxFB_TimeTransformExpDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerFramesIndicesMapping;
	sbSizerFramesIndicesMapping = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Mapping of the Scene Frames' Indices to the File Frames' Indices") ), wxVERTICAL );
	
	wxGridBagSizer* gbSizerFramesIndicesMapping;
	gbSizerFramesIndicesMapping = new wxGridBagSizer( 0, 0 );
	gbSizerFramesIndicesMapping->SetFlexibleDirection( wxBOTH );
	gbSizerFramesIndicesMapping->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	gbSizerFramesIndicesMapping->SetEmptyCellSize( wxSize( 0,0 ) );
	
	m_staticFrameInScene = new wxStaticText( this, wxID_ANY, _("Frame's Index In Scene"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFrameInScene->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticFrameInScene, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticIndexInFile = new wxStaticText( this, wxID_ANY, _("Frame's Index In File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticIndexInFile->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticIndexInFile, wxGBPosition( 0, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticFirstFrame = new wxStaticText( this, wxID_ANY, _("First processing frame:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFirstFrame->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticFirstFrame, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_spinFirstInScene = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	gbSizerFramesIndicesMapping->Add( m_spinFirstInScene, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticFirstArrow = new wxStaticText( this, wxID_ANY, _("--->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticFirstArrow->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticFirstArrow, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinFirstInFile = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	gbSizerFramesIndicesMapping->Add( m_spinFirstInFile, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticSecondFrame = new wxStaticText( this, wxID_ANY, _("Second processing frame:"), wxDefaultPosition, wxSize( -1,-1 ), wxALIGN_CENTRE );
	m_staticSecondFrame->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticSecondFrame, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_spinSecondInScene = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	m_spinSecondInScene->Enable( false );
	
	gbSizerFramesIndicesMapping->Add( m_spinSecondInScene, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticSecondArrow = new wxStaticText( this, wxID_ANY, _("--->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticSecondArrow->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticSecondArrow, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinSecondInFile = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	m_spinSecondInFile->Enable( false );
	
	gbSizerFramesIndicesMapping->Add( m_spinSecondInFile, wxGBPosition( 2, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticThirdFrame = new wxStaticText( this, wxID_ANY, _("Third processing frame:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticThirdFrame->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticThirdFrame, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_spinThirdInScene = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	m_spinThirdInScene->Enable( false );
	
	gbSizerFramesIndicesMapping->Add( m_spinThirdInScene, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticThirdArrow = new wxStaticText( this, wxID_ANY, _("--->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticThirdArrow->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticThirdArrow, wxGBPosition( 3, 2 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinThirdInFile = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	m_spinThirdInFile->Enable( false );
	
	gbSizerFramesIndicesMapping->Add( m_spinThirdInFile, wxGBPosition( 3, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticVDots = new wxStaticText( this, wxID_ANY, _(".\n.\n."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticVDots->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticVDots, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticLastFrame = new wxStaticText( this, wxID_ANY, _("Last processing frame:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticLastFrame->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticLastFrame, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_spinLastInScene = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	gbSizerFramesIndicesMapping->Add( m_spinLastInScene, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticLastArrow = new wxStaticText( this, wxID_ANY, _("--->"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticLastArrow->Wrap( -1 );
	gbSizerFramesIndicesMapping->Add( m_staticLastArrow, wxGBPosition( 5, 2 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_spinLastInFile = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	m_spinLastInFile->Enable( false );
	
	gbSizerFramesIndicesMapping->Add( m_spinLastInFile, wxGBPosition( 5, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	sbSizerFramesIndicesMapping->Add( gbSizerFramesIndicesMapping, 0, wxALL, 5 );
	
	bSizerMain->Add( sbSizerFramesIndicesMapping, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCmdButtons->SetMinSize( wxSize( -1,45 ) ); 
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonOK, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonCancel, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_spinFirstInScene->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformExpDlg::OnFirstInSceneChanged ), NULL, this );
	m_spinFirstInFile->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformExpDlg::OnFirstInFileChanged ), NULL, this );
	m_spinLastInScene->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformExpDlg::OnLastInSceneChanged ), NULL, this );
	m_buttonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_TimeTransformExpDlg::OnOK ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_TimeTransformExpDlg::OnCancel ), NULL, this );
}

wxFB_TimeTransformExpDlg::~wxFB_TimeTransformExpDlg()
{
	// Disconnect Events
	m_spinFirstInScene->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformExpDlg::OnFirstInSceneChanged ), NULL, this );
	m_spinFirstInFile->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformExpDlg::OnFirstInFileChanged ), NULL, this );
	m_spinLastInScene->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( wxFB_TimeTransformExpDlg::OnLastInSceneChanged ), NULL, this );
	m_buttonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_TimeTransformExpDlg::OnOK ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_TimeTransformExpDlg::OnCancel ), NULL, this );
}

wxFB_SpaceTransformImpDlg::wxFB_SpaceTransformImpDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerSystemUnit;
	sbSizerSystemUnit = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("System unit") ), wxVERTICAL );
	
	m_radioKeepCurSettings = new wxRadioButton( this, wxID_ANY, _("Keep current settings"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSystemUnit->Add( m_radioKeepCurSettings, 0, wxALL, 5 );
	
	m_radioSetupSystemUnit = new wxRadioButton( this, wxID_ANY, _("Setup system unit"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerSystemUnit->Add( m_radioSetupSystemUnit, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticSystemUnit = new wxStaticText( this, wxID_ANY, _("Select system unit:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticSystemUnit->Wrap( -1 );
	bSizer81->Add( m_staticSystemUnit, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_choiceSystemUnitChoices;
	m_choiceSystemUnit = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 140,-1 ), m_choiceSystemUnitChoices, 0 );
	m_choiceSystemUnit->SetSelection( 0 );
	bSizer81->Add( m_choiceSystemUnit, 1, wxALL|wxEXPAND, 5 );
	
	sbSizerSystemUnit->Add( bSizer81, 0, wxALIGN_RIGHT, 5 );
	
	bSizerMain->Add( sbSizerSystemUnit, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizerScaleCoef;
	sbSizerScaleCoef = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Scale coefficient") ), wxHORIZONTAL );
	
	m_staticScaleCoef = new wxStaticText( this, wxID_ANY, _("Number of system units per 1 file unit:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticScaleCoef->Wrap( -1 );
	sbSizerScaleCoef->Add( m_staticScaleCoef, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textScaleCoef = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 140,-1 ), 0 );
	sbSizerScaleCoef->Add( m_textScaleCoef, 1, wxALL|wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerScaleCoef, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizerMain->Add( 0, 10, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCmdButtons->SetMinSize( wxSize( -1,45 ) ); 
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonOK, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonCancel, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_radioKeepCurSettings->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_SpaceTransformImpDlg::OnRadioChanged ), NULL, this );
	m_radioSetupSystemUnit->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_SpaceTransformImpDlg::OnRadioChanged ), NULL, this );
	m_choiceSystemUnit->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( wxFB_SpaceTransformImpDlg::OnSystemUnitChanged ), NULL, this );
	m_buttonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_SpaceTransformImpDlg::OnOK ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_SpaceTransformImpDlg::OnCancel ), NULL, this );
}

wxFB_SpaceTransformImpDlg::~wxFB_SpaceTransformImpDlg()
{
	// Disconnect Events
	m_radioKeepCurSettings->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_SpaceTransformImpDlg::OnRadioChanged ), NULL, this );
	m_radioSetupSystemUnit->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( wxFB_SpaceTransformImpDlg::OnRadioChanged ), NULL, this );
	m_choiceSystemUnit->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( wxFB_SpaceTransformImpDlg::OnSystemUnitChanged ), NULL, this );
	m_buttonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_SpaceTransformImpDlg::OnOK ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_SpaceTransformImpDlg::OnCancel ), NULL, this );
}

wxFB_SpaceTransformExpDlg::wxFB_SpaceTransformExpDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerScaleCoef;
	sbSizerScaleCoef = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Scale coefficient") ), wxHORIZONTAL );
	
	m_staticScaleCoef = new wxStaticText( this, wxID_ANY, _("Number of file units per 1 system unit:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticScaleCoef->Wrap( -1 );
	sbSizerScaleCoef->Add( m_staticScaleCoef, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textScaleCoef = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerScaleCoef->Add( m_textScaleCoef, 1, wxALL|wxEXPAND, 5 );
	
	bSizerMain->Add( sbSizerScaleCoef, 0, wxEXPAND|wxALL, 5 );
	
	
	bSizerMain->Add( 0, 10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizerCmdButtons;
	bSizerCmdButtons = new wxBoxSizer( wxHORIZONTAL );
	
	bSizerCmdButtons->SetMinSize( wxSize( -1,45 ) ); 
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonOK = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonOK, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerCmdButtons->Add( m_buttonCancel, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizerCmdButtons->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizerMain->Add( bSizerCmdButtons, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	
	// Connect Events
	m_buttonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_SpaceTransformExpDlg::OnOK ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_SpaceTransformExpDlg::OnCancel ), NULL, this );
}

wxFB_SpaceTransformExpDlg::~wxFB_SpaceTransformExpDlg()
{
	// Disconnect Events
	m_buttonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_SpaceTransformExpDlg::OnOK ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxFB_SpaceTransformExpDlg::OnCancel ), NULL, this );
}
