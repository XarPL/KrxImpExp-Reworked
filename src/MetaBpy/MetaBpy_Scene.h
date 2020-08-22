///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Scene.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 14, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Returns the name of the current .blend file (but not the path). 
// For example, if the currently loaded file is "D:\MyBlendFiles\SCENES\Expgears.blend" 
// this method returns "Expgears.blend". 
#define GET_SCENE_FILENAME					get_scene_filename()

// Resets the 3D Editor
#define RESET_SCENE							reset_scene()


