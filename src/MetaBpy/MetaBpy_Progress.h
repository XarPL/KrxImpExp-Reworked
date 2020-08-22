///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Progress.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 14, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Updates the bar display to show the given percentage complete (in the range 0-100)
#define SHOW_PROGRESS_BAR(caption, percent)	show_progress_bar(caption, percent)

// Signals the end of the operation and removes the progress bar display.
#define HIDE_PROGRESS_BAR					hide_progress_bar()


