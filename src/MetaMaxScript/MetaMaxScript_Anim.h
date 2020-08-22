///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Anim.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
function GetScnStartFrame =
(
	return animationRange.start.frame as Integer
)

function GetScnEndFrame =
(
	return animationRange.end.frame as Integer
)

function SetScnAnimRange startFrame endFrame =
(
	if(endFrame < startFrame + 1) then
		endFrame = startFrame + 1
	animationRange = interval startFrame endFrame
)

function GetCurFrame =
(
	return sliderTime.frame as Integer
)

function SetCurFrame f =
(
	sliderTime = f
)

function HasTMAnimation obj =
(
	local ctrl = obj[HASHtransform]
	return (ctrl != undefined and ctrl.isAnimated)
)

function DeleteTMAnimation obj =
(
	local ctrl = obj[HASHtransform]
	if(ctrl != undefined) then
		deleteKeys ctrl
)

function AnimateTM obj tm =
(
	animate on
	(
		at time (sliderTime) obj.transform = tm
	)
)

function HasMorphAnimation obj =
(
	if(not(IS_MESH_OBJECT(obj))) then
	(
		return false
	)
	local ctrl = obj.mesh[HASHmaster_point_controller]
	return (ctrl != undefined and ctrl.isAnimated)
)

function DeleteMorphAnimation obj =
(
	if(IS_MESH_OBJECT(obj)) then
	(
		local ctrl = obj.mesh[HASHmaster_point_controller]
		if(ctrl != undefined) then
			deleteKeys ctrl
	)
)

function AnimateVertices obj points =
(
	if(not(IS_MESH_OBJECT(obj))) then
	(
		CONVERT_TO_MESH_OBJECT(obj)
	)
	animate on
	(
		for i in 1 to points.count do
		(
			animateVertex obj i
				at time (sliderTime) obj.mesh[HASHmaster_point_controller][i].value = points[i]
		)
	)
)

// Start and end frames of the Active Time Segment.
// It contains the values set in the Time Configuration dialog>Animation>Start Time and End Time 
// and displayed by the Active Time Segment option in the Time Output group of controls in the Render Scene Dialog.
#define GET_START_FRAME                           (GetScnStartFrame())
#define GET_END_FRAME                             (GetScnEndFrame())
#define SET_ANIMATION_RANGE(startFrame, endFrame)  SetScnAnimRange(startFrame) (endFrame)

// Minimum value for a frame index
#define MIN_FRAME								(-447392)

// Maximum value for a frame index
#define MAX_FRAME								(447392)

// The current scene frame rate in frames-per-second. 
// It contains the corresponding value set in the Time Configuration dialog.
#define GET_FRAME_RATE                (frameRate)
#define SET_FRAME_RATE(rate)          frameRate = (rate)

// System time resolution. 
// There are always 4800 ticks per second, this means that ticksPerFrame is dependent on the frames per second rate 
// (ticksPerFrame * frameRate = 4800)
#define GET_TICKS_PER_FRAME           (ticksPerFrame)
#define SET_TICKS_PER_FRAME(ticks)    ticksPerFrame = (ticks)

// Set current frame
#define SET_CURRENT_FRAME(t)	SetCurFrame(t)

// Get current frame
#define GET_CURRENT_FRAME	(GetCurFrame())

// Has an object animation for transformation matrix
#define HAS_TM_ANIMATION(obj)                     (HasTMAnimation (obj))

// Delete all animation keys for object's transformation matrix
#define DELETE_TM_ANIMATION(obj)                  DeleteTMAnimation(obj)

// Set transformation matrix at the specified frame
#define ANIMATE_TRANSFORM(obj, tm)                AnimateTM (obj) (tm)

// Has an object animation for mesh's vertices
#define HAS_MORPH_ANIMATION(obj)				  (HasMorphAnimation (obj))

// Delete all animation keys for object's mesh vertices
#define DELETE_MORPH_ANIMATION(obj)               DeleteMorphAnimation(obj)

// Set position of mesh vertex at the specified frame
#define ANIMATE_VERTICES(obj, points)			  AnimateVertices (obj) (points)

