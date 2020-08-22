///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Progress.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 11, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static void ShowProgressBar(const std::tstring& caption, int percent)
{
	if(percent < 0) percent = 0;
	if(percent > 99) percent = 99;
	StatusSetText(caption.c_str());
	StatusSetBar(percent);
}

static void HideProgressBar()
{
	StatusClear();
}


// Updates the bar display to show the given percentage complete (in the range 0-100)
#define SHOW_PROGRESS_BAR(caption, percent)	ShowProgressBar(caption, percent);

// Signals the end of the operation and removes the progress bar display.
#define HIDE_PROGRESS_BAR					HideProgressBar();


