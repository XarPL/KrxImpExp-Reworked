///////////////////////////////////////////////////////////////////////////////
// Name:        ImpExpUITools.h
// Purpose:     Implementation of utility functions.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#include "StdHeaders.h"

// MetaCpp headers
#include "FormatMsg.meta"

// wxImpExpUI headers
#include "ImpExpUITools.h"



////////////////////////////////////////////////////////////////////////////////
// Language utilities
////////////////////////////////////////////////////////////////////////////////

// Get path to directory which contains this executable
wxString GetModuleDirPath()
{
	TCHAR szModuleFileName[MAX_PATH];
	GetModuleFileName(NULL, szModuleFileName, MAX_PATH);
	
	wxString moduleFileName = szModuleFileName;
	for(int i = moduleFileName.Length() - 1; i >= 0; --i)
		if(moduleFileName[i] == _T('\\'))
		{
			moduleFileName = moduleFileName.Left(i);
			break;
		}

	return moduleFileName;
}

// Get path to locale dir
static wxString GetLocaleDirPath()
{
	return GetModuleDirPath() + _T("\\locale");
}

// Get path to help dir
static wxString GetHelpDirPath()
{
	return GetModuleDirPath() + _T("\\help");
}

// Init wxLocale with specified language
void InitLocale(wxLocale* locale, const wxString& lang)
{
	const wxLanguageInfo* langInfo = wxLocale::FindLanguageInfo(lang);
	locale->Init(langInfo->Language);
	wxLocale::AddCatalogLookupPathPrefix(GetLocaleDirPath());
	locale->AddCatalog(wxT("messages"));
}

// Read user interface language from the configuration file
wxString ReadUILangFromConfig()
{
	wxConfigBase* pConfig = wxConfigBase::Get();
	const wxLanguageInfo* langInfo = wxLocale::GetLanguageInfo(wxLANGUAGE_DEFAULT);
	wxString str;
	if(pConfig->Read(_T("Options/UILanguage"), &str))
	{
		const wxLanguageInfo* langInfo2 = wxLocale::FindLanguageInfo(str);
		if(langInfo2)
			langInfo = langInfo2;
	}
	return langInfo->Description;
}

// Write user interface language to the configuration file
void WriteUILangToConfig(const wxString& newLang)
{
	wxConfigBase* pConfig = wxConfigBase::Get();
	pConfig->Write(_T("Options/UILanguage"), newLang);
}

// Get list of all supported languages
wxArrayString GetAllSupportedLanguages()
{
	wxArrayString arr;
	wxString str;
	wxDir dir(GetLocaleDirPath());
	bool bFound = dir.GetFirst(&str, wxEmptyString, wxDIR_DIRS);
	while(bFound)
	{
		const wxLanguageInfo* langInfo = wxLocale::FindLanguageInfo(str);
		if(langInfo)
			arr.Add(langInfo->Description);
		bFound = dir.GetNext(&str);
	}
	arr.Add(_T("English"));
	arr.Sort();
	return arr;
}

// Show help
void ShowHelp(const wxString& helpFileName)
{
	int curLang = wxLocale::FindLanguageInfo(ReadUILangFromConfig())->Language;
	wxString helpLang = _T("en");
	wxString str;
	wxDir dir(GetHelpDirPath());
	bool bFound = dir.GetFirst(&str, wxEmptyString, wxDIR_DIRS);
	while(bFound)
	{
		const wxLanguageInfo* langInfo = wxLocale::FindLanguageInfo(str);
		if(langInfo && langInfo->Language == curLang)
		{
			helpLang = str;
			break;
		}
		bFound = dir.GetNext(&str);
	}

	wxString helpDir = GetHelpDirPath() + + _T("\\") + helpLang;
	wxString helpFilePath = helpFileName + _T("_") + helpLang + _T(".html");
	ShellExecute(NULL, NULL, helpFilePath.c_str(), NULL, helpDir.c_str(), SW_SHOWNORMAL);
}



////////////////////////////////////////////////////////////////////////////////
// Conversion utilities
////////////////////////////////////////////////////////////////////////////////

// Threshold conversion functions
wxString ThresholdToString(float threshold)
{
	wxString str;
	str.Printf(_T("%3.1f"), double(threshold));
	return str;
}

float StringToThreshold(const wxString& str)
{
	double dbl;
	if(!str.ToDouble(&dbl))
		dbl = 0.0;
	return (float) dbl;
}

// File size conversion function
wxString FileSizeToString(int filesize)
{
	wxString str;
	str.Printf(_T("%i"), filesize);
	return str;
}


////////////////////////////////////////////////////////////////////////////////
// Other utilities
////////////////////////////////////////////////////////////////////////////////

int FillWxChoice(wxChoice* winChoice, const std::vector<std::tstring>& choices, const std::tstring& selectChoice, bool useEmptyPrefixSign)
{
	size_t numChoices = choices.size();
	if(numChoices != 0)
	{
		for(size_t i = 0; i < numChoices; ++i)
		{
			if(choices[i] == _T("") && useEmptyPrefixSign)
				winChoice->Append(EMPTY_PREFIX_SIGN);
			else
				winChoice->Append(choices[i]);
		}
		
		int nSel;
		if(selectChoice == _T("") && useEmptyPrefixSign)
			nSel = winChoice->FindString(EMPTY_PREFIX_SIGN);
		else
			nSel = winChoice->FindString(selectChoice);

		if(nSel == -1)
			nSel = 0;

		winChoice->Select(nSel);
	}
	return numChoices;
}

// Setup a wxChoice control with items, and select the specified item of them
int FillWxChoiceWithStrings(wxChoice* winChoice, const std::vector<std::tstring>& choices, const std::tstring& selectChoice)
{
	return FillWxChoice(winChoice, choices, selectChoice, false);
}

// Setup a wxChoice control with prefixes, and select the specified item of them;
// the function returns number of choices
int FillWxChoiceWithPrefixes(wxChoice* winChoice, const std::vector<std::tstring>& choices, 
	const std::tstring& selectChoice)
{
	return FillWxChoice(winChoice, choices, selectChoice, true);
}

// Get selected prefix from wxChoice;
// the function works likely as GetStringSelection but it replaces "(empty prefix)" to ""
std::tstring GetPrefixFromWxChoice(wxChoice* winChoice)
{
	std::tstring str = winChoice->GetStringSelection().c_str();
	if(str == EMPTY_PREFIX_SIGN)
		str = _T("");
	return str;
}

// Get prefix from wxTextCtrl;
// the function works likely as GetValue but it replaces EMPTY_PREFIX_SIGN to ""
std::tstring GetPrefixFromWxTextCtrl(wxTextCtrl* winTextCtrl)
{
	std::tstring str = winTextCtrl->GetValue();
	if(_tcsicmp(str.c_str(), EMPTY_PREFIX_SIGN) == 0)
		str = _T("");
	return str;
}

// Check the specified prefix for unique
bool CheckPrefixForUnique(const std::tstring& prefixForCheck, const std::vector<std::tstring>& usedPrefixes)
{
	for(size_t i = 0; i < usedPrefixes.size(); ++i)
	{
		if(_tcsicmp(prefixForCheck.c_str(), usedPrefixes[i].c_str()) == 0)
		{
			wxString msg = FormatMsg1(std::tstring(_("The specified prefix \"%1\" is not unique.")), prefixForCheck).c_str();
			wxMessageDialog msgdlg(NULL, msg, _T("KrxImpExpUI"), wxOK|wxICON_EXCLAMATION);
			msgdlg.ShowModal();
			return false;
		}
	}
	return true;
}
