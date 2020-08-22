///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Progress.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
/*
static DWORD WINAPI DoNothing(LPVOID arg)
{
	return 0;
}

static void ShowProgressBar(const std::string& caption, int percent)
{
	static std::tstring s_lastCaption = _T("");
	static int s_lastPercent = 0;

	if(caption != s_lastCaption)
	{
		if(s_lastCaption != _T(""))
			GetInterface()->ProgressEnd();
	
		if(caption != _T(""))
			GetInterface()->ProgressStart((TCHAR*) (caption.c_str()), TRUE, DoNothing, NULL);

		s_lastCaption = caption;
		s_lastPercent = 0;
	}

	if(percent < 0) percent = 0;
	if(percent > 99) percent = 99;
	if(s_lastPercent != percent)
	{
		GetInterface()->ProgressUpdate(percent);
		s_lastPercent = percent;
	}
}

static void HideProgressBar()
{
	ShowProgressBar("", 0);
}
*/
static DWORD WINAPI DoNothing(LPVOID arg)
{
	return 0;
}

static void ShowProgressBar(const std::tstring& caption, int percent)
{
	static std::tstring s_lastCaption = _T("");
	static int s_lastPercent = -1;

	if(caption != s_lastCaption)
	{
		if(caption == _T(""))
		{
			if(s_lastCaption != _T(""))
			{
				GetInterface()->ProgressEnd();
				s_lastCaption = _T("");
			}
			return;
		}
		if(s_lastCaption == _T(""))
		{
			GetInterface()->ProgressStart(_T(""), TRUE, DoNothing, NULL);
		}
		s_lastCaption = caption;
		s_lastPercent = -1;
	}

	if(percent < 0) percent = 0;
	if(percent > 99) percent = 99;
	if(percent != s_lastPercent)
	{
		s_lastPercent = percent;
		GetInterface()->ProgressUpdate(percent, FALSE, (LPTSTR) (caption.c_str()));
	}
}

static void HideProgressBar()
{
	ShowProgressBar(_T(""), 0);
}


// Updates the bar display to show the given percentage complete (in the range 0-100)
#define SHOW_PROGRESS_BAR(caption, percent)	ShowProgressBar(caption, percent);

// Signals the end of the operation and removes the progress bar display.
#define HIDE_PROGRESS_BAR					HideProgressBar();


