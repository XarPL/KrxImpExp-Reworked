///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Layer.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 6, 2010
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Layer
#define TLAYER								NoneType
#define INVALID_LAYER						None

#define NEW_LAYER(name)						None

// Set name of a layer
#define SET_LAYER_NAME(layerObj, name)		pass

// Get name of a layer
#define GET_LAYER_NAME(layerObj)			""

// Find a layer by name; returns INVALID_LAYER if not found
#define FIND_LAYER_BY_NAME(name)			None

// Set an object's layer
#define SET_OBJECT_LAYER(obj, layerObj)		pass

// Get an object's layer
#define GET_OBJECT_LAYER(obj)				None

// Access to layer's properties
#define SET_LAYER_VISIBILITY(layerObj, visibility)	    pass
#define GET_LAYER_VISIBILITY(layerObj)					True

#define SET_LAYER_RENDERABLE(layerObj, renderable)		pass
#define GET_LAYER_RENDERABLE(layerObj)					True

#define SET_LAYER_BOX_MODE(layerObj, boxmode)			pass
#define GET_LAYER_BOX_MODE(layerObj)					False

#define SET_LAYER_TRANSPARENT(layerObj, transparent)	pass
#define GET_LAYER_TRANSPARENT(layerObj)					False
