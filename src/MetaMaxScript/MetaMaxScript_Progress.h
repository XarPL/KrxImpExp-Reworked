///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Progress.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
global g_lastCaption = ""
global g_lastPercent = 0
global g_lastTimeStamp = 0

function ShowProgressBar caption percent =
(
	if caption != g_lastCaption then
	(
		if (timeStamp() - g_lastTimeStamp < 500) and (caption != "") then
			return undefined
			
		if g_lastCaption != "" then
			progressEnd()
	
		if caption != "" then
			progressStart caption

		g_lastCaption = caption
		g_lastTimeStamp = timeStamp()
	)
	
	if percent < 0 then 
		percent = 0
		
	if percent > 99 then 
		percent = 99
		
	if g_lastPercent != percent then
	(
		progressUpdate percent
		g_lastPercent = percent
	)	
)

function HideProgressBar =
(
	ShowProgressBar "" 0
)

/*
rollout progressRollout "Progress" width:500 height:75
(
	progressBar pb "ProgressBar" pos:[10,37] width:480 height:23
	label lbl "Label" pos:[11,13] width:480 height:23
)

global g_dialogShown = false

function ShowProgressBar caption percent =
(
	if not(g_dialogShown) then
	(
		createDialog progressRollout style:#(#style_border)
		g_dialogShown = true
	)

	if percent < 0 then 
		percent = 0

	if percent > 100 then
		percent = 100
		
	progressRollout.lbl.text = caption
	progressRollout.pb.value = percent
)

function HideProgressBar =
(
	if g_dialogShown then
	(
		if classOf(GetMaxWindowPos) != undefined then
		(
			offMaxPos = (GetMaxWindowPos() + GetMaxWindowSize())
			SetDialogPos progressRollout offMaxPos
		)
		destroyDialog progressRollout
		g_dialogShown = false
	)
)
*/

// Updates the bar display to show the given percentage complete (in the range 0-100)
#define SHOW_PROGRESS_BAR(caption, percent)	ShowProgressBar (caption) (percent)

// Signals the end of the operation and removes the progress bar display.
#define HIDE_PROGRESS_BAR					HideProgressBar()

