///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Anim.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     April 6, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Start and end frames of the Active Time Segment
// It contains the values set in the Time Configuration dialog>Animation>Start Time and End Time 
// and displayed by the Active Time Segment option in the Time Output group of controls in the Render Scene Dialog.
#define GET_START_FRAME                            get_start_frame()
#define GET_END_FRAME                              get_end_frame()
#define SET_ANIMATION_RANGE(startFrame, endFrame)  set_frame_range(startFrame, endFrame)

// Minimum value for a frame index
#define MIN_FRAME									get_min_frame()

// Maximum value for a frame index
#define MAX_FRAME									get_max_frame()

// Current scene frame rate in frames-per-second. 
// It contains the corresponding value set in the Time Configuration dialog.
#define GET_FRAME_RATE                             get_fps()
#define SET_FRAME_RATE(rate)                       set_fps(rate)

// System time resolution. 
// There are always 4800 ticks per second, this means that ticksPerFrame is dependent on the frames per second rate 
// (ticksPerFrame * frameRate == 4800)
#define GET_TICKS_PER_FRAME                        (4800 / get_fps())
#define SET_TICKS_PER_FRAME(ticks)                 set_fps(4800 / (ticks))

// Set current frame
#define SET_CURRENT_FRAME(t)				       set_current_frame(t)

// Get current frame
#define GET_CURRENT_FRAME				           get_current_frame()

// Has an object animation for transformation matrix
#define HAS_TM_ANIMATION(obj)                     has_tm_animation(obj)

// Delete all animation keys for object's transformation matrix
#define DELETE_TM_ANIMATION(obj)                  delete_tm_animation(obj)

// Set transformation matrix at the specified frame
#define ANIMATE_TRANSFORM(obj, tm)                animate_tm(obj, tm)

// Has an object animation for mesh's vertices
#define HAS_MORPH_ANIMATION(obj)				  has_vertex_animation(obj)

// Delete all animation keys for object's mesh vertices
#define DELETE_MORPH_ANIMATION(obj)               delete_vertex_animation(obj)

// Set position of mesh vertex at the specified frame
#define ANIMATE_VERTICES(obj, points)	   		  animate_vertices(obj, points)

