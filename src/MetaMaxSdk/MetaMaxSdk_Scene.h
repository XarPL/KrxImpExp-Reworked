///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Scene.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static std::tstring GetSceneFileName()
{
	return (std::tstring) (GetInterface()->GetCurFileName().data());
}

// Returns the name of the current MAX file (but not the path). 
// For example, if the currently loaded file is "D:\3DSMAX\SCENES\Expgears.max" 
// this method returns " Expgears.max". 
#define GET_SCENE_FILENAME					(GetSceneFileName())

// Resets the 3D Editor
#define RESET_SCENE							GetInterface()->FileReset(TRUE);

