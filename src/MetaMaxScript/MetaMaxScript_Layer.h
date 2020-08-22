///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Layer.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 5, 2010
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
function NewLayer nam =
(
    local layer = undefined
    if(classOf(LayerManager) == Interface) then
    (
        layer = LayerManager.newLayerFromName(nam)
    )
    return layer
)

function FindLayerByName nam =
( 
    local layer = undefined
    if(classOf(LayerManager) == Interface) then
    (
        layer = LayerManager.getLayerFromName(nam)
    )
    return layer
)

function SetLayerName layer nam =
(
    if(layer != undefined) then
    (
        layer.setname(nam)
    )
)

function GetLayerName layer =
(
    local layerName = undefined
    if(layer != undefined) then
    (
        layerName = layer.name
    )
    return layerName
)

function SetObjLayer nod layer =
(
    if(layer != undefined) then
    (
        layer.addNode(nod)
        nod.displayByLayer = true
        nod.renderByLayer = true
    )
)

function GetObjLayer nod = 
(
    local lr = undefined
    if(classOf(LayerManager) == Interface) then
    (
        lr = (nod).layer
    )
    return lr
)

function SetLayerVisibility layer vis =
(
    if(layer != undefined) then
    (
        layer.on = vis
    )
)

function GetLayerVisibility layer = 
(
    local vis = true
    if(layer != undefined) then
    (
        vis = layer.on
    )
	return vis
)

function SetLayerRenderable layer r = 
(
    if(layer != undefined) then
    (
        if(isProperty layer "renderable") then
            layer.renderable = r
    )
)

function GetLayerRenderable layer =
(
    local r = true
    if(layer != undefined) then
    (
        if(isProperty layer "renderable") then
            r = layer.renderable
    )
    return r
)

function SetLayerBoxMode layer bm =
(
    if(layer != undefined) then
    (
        if(isProperty layer "boxMode") then
           	layer.boxMode = bm
    )
)

function GetLayerBoxMode layer =
(
    local bm = false
    if(layer != undefined) then
    (
        if(isProperty layer "boxMode") then
            bm = layer.boxMode
    )
    return bm
)

function SetLayerTransparent layer tr =
(
    if(layer != undefined) then
    (
        if(isProperty layer "xray") then
           	layer.xray = tr
    )
)

function GetLayerTransparent layer =
(
    local tr = false
    if(layer != undefined) then
    (
        if(isProperty layer "xray") then
            tr = layer.xray
    )
    return tr
)

// Layer
#define TLAYER							LayerProperties
#define INVALID_LAYER					undefined

#define NEW_LAYER(name)					(NewLayer(name))

// Set name of a layer
#define SET_LAYER_NAME(layer, name)		SetLayerName (layer) (name)

// Get name of a layer
#define GET_LAYER_NAME(layer)			(GetLayerName(layer))

// Find a layer by name; returns INVALID_LAYER if not found
#define FIND_LAYER_BY_NAME(name)		(FindLayerByName(name))

// Set an object's layer
#define SET_OBJECT_LAYER(nod, layer)	(SetObjLayer(nod) (layer))

// Get an object's layer
#define GET_OBJECT_LAYER(nod)			(GetObjLayer(nod))

// Access to layer's properties
#define SET_LAYER_VISIBILITY(layer, visibility)	    (SetLayerVisibility(layer) (visibility))
#define GET_LAYER_VISIBILITY(layer)					(GetLayerVisibility(layer))

#define SET_LAYER_RENDERABLE(layer, renderable)		(SetLayerRenderable(layer) (renderable))
#define GET_LAYER_RENDERABLE(layer)					(GetLayerRenderable(layer))

#define SET_LAYER_BOX_MODE(layer, boxmode)			(SetLayerBoxMode(layer) (boxmode))
#define GET_LAYER_BOX_MODE(layer)					(GetLayerBoxMode(layer))

#define SET_LAYER_TRANSPARENT(layer, transparent)	(SetLayerTransparent(layer) (transparent))
#define GET_LAYER_TRANSPARENT(layer)				(GetLayerTransparent(layer))

