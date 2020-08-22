///////////////////////////////////////////////////////////////////////////////
// Name:        MeshInfoDlg.cpp
// Purpose:     Implementation of class wxMeshInfoDlg.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "ObjectStats.meta"
#include "MeshInfoDlgInput.meta"
#include "MeshInfoDlgOutput.meta"

// wxImpExpUI headers
#include "ImpExpUITools.h"
#include "MeshInfoDlg.h"




////////////////////////////////////////////////////////////////////////////////
// wxMeshInfoDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxMeshInfoDlg::wxMeshInfoDlg(wxWindow* parent, TMeshInfoDlgInput& dlgInput, TMeshInfoDlgOutput& dlgOutput)
: wxFB_MeshInfoDlg(parent), 
  m_timer(this),
  m_dlgInput(&dlgInput),
  m_dlgOutput(&dlgOutput)
{
	this->Connect( wxEVT_TIMER, wxTimerEventHandler( wxMeshInfoDlg::OnTimer ) );

    // set the dialog icon
	// SetIcon(wxIcon(exp3ds_xpm));

	// setup layout
	SetMinSize(GetSize());
}

// Dtor
wxMeshInfoDlg::~wxMeshInfoDlg()
{
	this->Disconnect( wxEVT_TIMER, wxTimerEventHandler( wxMeshInfoDlg::OnTimer ) );
}

// Shows a modal dialog
int wxMeshInfoDlg::ShowModal()
{
	// whether there is a warning about too many verts/faces
	bool showWarning = false;
	if(m_dlgInput->GetExportMode())
	{
		std::vector<TObjectStats> allObjectStats = m_dlgInput->GetObjectStats();
		for(int i = 0; i < (int) allObjectStats.size(); ++i)
		{
			TObjectStats& objst = allObjectStats[i];
			if(objst.GetNumFaces() > 65535 || objst.GetNumVertsInScene() > 65535 || objst.GetNumVertsInFile() > 65535)
			{
				showWarning = true;
				break;
			}
		}
	}

	// don't show dialog if user don't want it
	wxConfigBase* pConfig = wxConfigBase::Get();
	bool showInfoWnd;
	pConfig->Read(_T("InfoWnd/Show"), &showInfoWnd, true);
	if(!showInfoWnd && !showWarning)
	{
		return GetAffirmativeId();
	}
	return wxFB_MeshInfoDlg::ShowModal();
}

// Dialog data transfer (input data file -> dialog controls)
bool wxMeshInfoDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();

	// setup title
	if(m_dlgInput->GetExportMode())
		SetTitle(_("Mesh Export Information"));
	else
		SetTitle(_("Mesh Import Information"));

	// setup "File Properties" section
	m_textFileName->SetValue(m_dlgInput->GetFileName());
	int nFileNameLen = (int) m_textFileName->GetValue().length();
	m_textFileName->SetSelection(nFileNameLen, nFileNameLen);
	m_textFileSize->SetValue(FileSizeToString(m_dlgInput->GetFileSize()));

	// setup "Objects" section
	if(m_dlgInput->GetExportMode())
		m_sbSizerObjects->GetStaticBox()->SetLabel(_("Exported Objects"));
	else
		m_sbSizerObjects->GetStaticBox()->SetLabel(_("Imported Objects"));

	// setup columns
	float width = float (m_listObjects->GetClientSize().x);
	m_listObjects->InsertColumn(0, _("#"),              wxLIST_FORMAT_LEFT, int(width * 0.05));
	m_listObjects->InsertColumn(1, _("Name in file"),   wxLIST_FORMAT_LEFT, int(width * 0.2));
	m_listObjects->InsertColumn(2, _("Name in scene"),  wxLIST_FORMAT_LEFT, int(width * 0.2));
	m_listObjects->InsertColumn(3, _("Materials"),      wxLIST_FORMAT_LEFT, int(width * 0.13));
	m_listObjects->InsertColumn(4, _("Faces"),          wxLIST_FORMAT_LEFT, int(width * 0.12));

	if(m_dlgInput->GetExportMode())
	{
		m_listObjects->InsertColumn(5, _("Verts in scene"), wxLIST_FORMAT_LEFT, int(width * 0.15));
		m_listObjects->InsertColumn(6, _("Verts in file"),  wxLIST_FORMAT_LEFT, int(width * 0.15));
	}
	else
	{
		m_listObjects->InsertColumn(5, _("Verts in file"),  wxLIST_FORMAT_LEFT, int(width * 0.15));
		m_listObjects->InsertColumn(6, _("Verts in scene"), wxLIST_FORMAT_LEFT, int(width * 0.15));
	}

	// setup items
	bool showWarning = false;
	std::vector<TObjectStats> allObjectStats = m_dlgInput->GetObjectStats();
	for(int i = 0; i < (int) allObjectStats.size(); ++i)
	{
		TObjectStats& objst = allObjectStats[i];
		wxString str;
		str.Printf(_T("%d"), i + 1);
		m_listObjects->InsertItem(i, wxString(str));
		m_listObjects->SetItem(i, 1, objst.GetNameInFile());
		m_listObjects->SetItem(i, 2, objst.GetNameInScene());
		str.Printf(_T("%d"), objst.GetNumMtls());
		m_listObjects->SetItem(i, 3, str);
		str.Printf(_T("%d"), objst.GetNumFaces());
		m_listObjects->SetItem(i, 4, str);
		str.Printf(_T("%d"), objst.GetNumVertsInScene());
		m_listObjects->SetItem(i, m_dlgInput->GetExportMode() ? 5 : 6, str);
		str.Printf(_T("%d"), objst.GetNumVertsInFile());
		m_listObjects->SetItem(i, m_dlgInput->GetExportMode() ? 6 : 5, str);
		
		if(m_dlgInput->GetExportMode())
			if(objst.GetNumFaces() > 65535 || objst.GetNumVertsInScene() > 65535 || objst.GetNumVertsInFile() > 65535)
			{
				m_listObjects->SetItemTextColour(i, *wxRED);
				showWarning = true;
			}
	}
	m_staticWarning->Show(showWarning);

	// start timer
	bool autoClose;
	pConfig->Read(_T("InfoWnd/AutoClose"), &autoClose, TRUE);
	if(showWarning)
		autoClose = false;

	m_buttonStopTimer->Enable(autoClose);
	if(autoClose)
	{
		pConfig->Read(_T("InfoWnd/Timeout"), &m_restSeconds, 5);
		m_timer.Start(1000); // 1 second interval
		UpdateCloseButton();
	}
	return true;
}

// Close the dialog
void wxMeshInfoDlg::OnClose(wxCommandEvent& event)
{
	Close();
}

// Stop timer that can close the dialog automatically
void wxMeshInfoDlg::OnStopTimer(wxCommandEvent& event)
{
	m_timer.Stop();
	m_buttonStopTimer->Enable(false);
	UpdateCloseButton();
}

// called automatically 1 time per second
void wxMeshInfoDlg::OnTimer(wxTimerEvent& event)
{
	if(m_restSeconds-- == 0)
		Close();

	UpdateCloseButton();
}

// Update label on the face of close button
void wxMeshInfoDlg::UpdateCloseButton()
{
	wxString strLabel = _("Close");
	if(m_timer.IsRunning())
	{
		wxString strTimeRest;
		strTimeRest.Printf(_T(" (%d)"), m_restSeconds);
		strLabel = strLabel + strTimeRest;
	}
	m_buttonClose->SetLabel(strLabel);
}