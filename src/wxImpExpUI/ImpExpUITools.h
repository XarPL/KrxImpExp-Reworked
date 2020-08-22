///////////////////////////////////////////////////////////////////////////////
// Name:        ImpExpUITools.h
// Purpose:     Declaration of utility functions.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __ImpExpUITools__
#define __ImpExpUITools__


///////////////////////////////////////////////////////////////////////////////
/// Language utilities
///////////////////////////////////////////////////////////////////////////////

// Read user interface language from the configuration file
wxString ReadUILangFromConfig();

// Init wxLocale with specified language
void InitLocale(wxLocale* locale, const wxString& lang);

// Write user interface language to the configuration file
void WriteUILangToConfig(const wxString& newLang);

// Get list of all supported languages
wxArrayString GetAllSupportedLanguages();

// Show help
void ShowHelp(const wxString& helpFileName);



///////////////////////////////////////////////////////////////////////////////
/// Conversion utilities
///////////////////////////////////////////////////////////////////////////////

// Threshold spin parameters
#define THRESHOLD_MIN_VALUE (0.0f)
#define THRESHOLD_MAX_VALUE (10.0f)
#define THRESHOLD_STEP      (0.1f)
	
// Threshold conversion functions
wxString ThresholdToString(float threshold);
float StringToThreshold(const wxString& str);

// File size conversion function
wxString FileSizeToString(int filesize);


///////////////////////////////////////////////////////////////////////////////
/// Other utilities
///////////////////////////////////////////////////////////////////////////////

// Get path to directory which contains this executable
wxString GetModuleDirPath();

// String that means empty prefix when used as prefix
#define EMPTY_PREFIX_SIGN _("(empty)")

// Setup a wxChoice control with items, and select the specified item of them;
// the function returns number of choices
int FillWxChoiceWithStrings(wxChoice* winChoice, const std::vector<std::tstring>& choices, 
				  const std::tstring& selectChoice);

// Setup a wxChoice control with prefixes, and select the specified item of them;
// the function returns number of choices
int FillWxChoiceWithPrefixes(wxChoice* winChoice, const std::vector<std::tstring>& choices, 
				  const std::tstring& selectChoice);

// Get selected prefix from wxChoice;
// the function works likely as GetStringSelection but it replaces EMPTY_PREFIX_SIGN to ""
std::tstring GetPrefixFromWxChoice(wxChoice* winChoice);

// Get prefix from wxTextCtrl;
// the function works likely as GetValue but it replaces EMPTY_PREFIX_SIGN to ""
std::tstring GetPrefixFromWxTextCtrl(wxTextCtrl* winTextCtrl);

// Check the specified prefix for unique
bool CheckPrefixForUnique(const std::tstring& prefixForCheck, 
						  const std::vector<std::tstring>& usedPrefixes);


#endif // __ImpExpUITools__