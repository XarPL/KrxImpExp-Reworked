///////////////////////////////////////////////////////////////////////////////
// Name:        AboutDlg.cpp
// Purpose:     Implementation of class wxAboutDlg.
// Author:      Vitaly Baranov
// Created:     February 20, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// wxImpExpUI headers
#include "AboutDlg.h"

// icon
#include "draconian_ladder.xpm"
#include "gobbo_wine.xpm"
#include "orc_two_swords.xpm"
#include "gold_chest.xpm"

////////////////////////////////////////////////////////////////////////////////
// wxAboutDlg
////////////////////////////////////////////////////////////////////////////////

// Ctor
wxAboutDlg::wxAboutDlg(wxWindow* parent)
: wxFB_AboutDlg(parent) 
{
	// setup text in controls
	m_staticTitle->SetLabel(_T("KrxImpExp"));

	wxString released = m_staticReleaseDate->GetLabel();
	released.Replace(_T("%1"), _T(__DATE__));
	m_staticReleaseDate->SetLabel(released);
	m_hyperlinkDownloadPage->SetURL(_T("https://krximpexp.sourceforge.net"));
	m_hyperlinkDownloadPage->SetLabel(m_hyperlinkDownloadPage->GetURL());
	m_hyperlinkEngSupForum->SetURL(_T("http://forum.worldofplayers.de/forum/showthread.php?t=340148"));
	m_hyperlinkEngSupForum->SetLabel(m_hyperlinkEngSupForum->GetURL());
	m_hyperlinkRusSupForum->SetURL(_T("http://forum.worldofgothic.ru/index.php/topic,592.0.html"));
	m_hyperlinkRusSupForum->SetLabel(m_hyperlinkRusSupForum->GetURL());
	wxString usedComponents = 
		_T("wxWidgets by wxWidgets dev team\n")
		_T("     http://www.wxwidgets.org\n")
		_T("\r\n")
		_T("physiqueOps by Adam Felt, Neil Hazzard\n")
		_T("     http://ogre.svn.sourceforge.net/viewvc/ogre/trunk/Tools\n")
		_T("     /3dsmaxExport/MaxscriptExport/plugins\n")
		_T("     /PhysiqueInterface_sources\n")
		_T("\n")
		_T("tstl by PJ Arends\n")
		_T("     http://www.codeproject.com/KB/string/tstl_h.aspx");
	usedComponents.Replace(_T("\n"), _T("\r\n"));
	m_textUsedComponents->SetLabel(usedComponents);
	Fit();
}

// Dtor
wxAboutDlg::~wxAboutDlg()
{
}


// Dialog data transfer (input data file -> dialog controls)
bool wxAboutDlg::TransferDataToWindow()
{
	wxConfigBase* pConfig = wxConfigBase::Get();
	
	if(m_staticTranslator->GetLabel() == _T("TranslatorName"))
	{
		m_staticTranslator->Hide();
		m_staticTranslatedBy->Hide();
	}

	const char** pImage[] = {draconian_ladder_xpm, gobbo_wine_xpm, orc_two_swords_xpm, gold_chest_xpm};
	const int nNumImages = sizeof(pImage) / sizeof(pImage[0]);
	int nImageIndex = 0;
	pConfig->Read(_T("AboutWnd/ImageIndex"), &nImageIndex, nImageIndex);
	if(nImageIndex < 0 || nImageIndex >= nNumImages)
		nImageIndex = 0;
	m_bitmapCrazy->SetIcon(wxIcon(pImage[nImageIndex]));
	++nImageIndex;
	pConfig->Write(_T("AboutWnd/ImageIndex"), nImageIndex);

	Fit();
	return true;
}

// Dialog data transfer (dialog controls -> output data file)
bool wxAboutDlg::TransferDataFromWindow()
{
	return true;
}

// Command buttons
void wxAboutDlg::OnClose(wxCommandEvent& event)
{
	Close();
}

