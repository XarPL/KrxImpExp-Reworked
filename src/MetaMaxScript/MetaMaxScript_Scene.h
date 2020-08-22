///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Scene.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Returns the name of the current MAX file (but not the path). 
// For example, if the currently loaded file is "D:\3DSMAX\SCENES\Expgears.max" 
// this method returns " Expgears.max". 
#define GET_SCENE_FILENAME					(maxFileName)

// Resets the 3D Editor
#define RESET_SCENE							resetMaxFile #noPrompt
