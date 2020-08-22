///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Layer.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 5, 2010
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static ILayer* NewLayer(const std::tstring& name)
{
	ILayerManager* layerMgr = (ILayerManager*) GetCOREInterface()->GetScenePointer()->GetReference(10);
	ILayer* layer = layerMgr->CreateLayer();
	layer->SetName(name.c_str());
	return layer;
}

static void SetLayerName(ILayer* layer, const std::tstring& name)
{
	layer->SetName(name.c_str());
}

static std::tstring GetLayerName(ILayer* layer)
{
	return layer->GetName().data();
}

static ILayer* FindLayerByName(const std::tstring& name)
{
	ILayerManager* layerMgr = (ILayerManager*) GetCOREInterface()->GetScenePointer()->GetReference(10);
	return layerMgr->GetLayer(name.c_str());
}

static void SetObjLayer(INode* node, ILayer* layer)
{
	layer->AddToLayer(node);
	layer->SetDisplayByLayer(true, node);
	layer->SetRenderByLayer(true, node);
}

static ILayer* GetObjLayer(INode* node)
{
	return (ILayer*) node->GetReference(NODE_LAYER_REF);
}

static void SetLayerVisibility(ILayer* layer, bool visibility)
{
	layer->Hide(!visibility);
}

static bool GetLayerVisibility(ILayer* layer)
{
	return !layer->IsHidden();
}

static void SetLayerRenderable(ILayer* layer, bool renderable)
{
	layer->SetRenderable(renderable);
}

static bool GetLayerRenderable(ILayer* layer)
{
	return layer->Renderable();
}

static void SetLayerBoxMode(ILayer* layer, bool boxMode)
{
	layer->BoxMode(boxMode);
}

static bool GetLayerBoxMode(ILayer* layer)
{
	return layer->GetBoxMode();
}

static void SetLayerTransparent(ILayer* layer, bool transparent)
{
	layer->XRayMtl(transparent);
}

static bool GetLayerTransparent(ILayer* layer)
{
	return layer->HasXRayMtl();
}

// Layer
#define TLAYER							ILayer*
#define INVALID_LAYER					NULL

#define NEW_LAYER(name)					(NewLayer(name))

// Set name of a layer
#define SET_LAYER_NAME(layer, name)		SetLayerName(layer, name);

// Get name of a layer
#define GET_LAYER_NAME(layer)			(GetLayerName(layer))

// Find a layer by name; returns INVALID_LAYER if not found
#define FIND_LAYER_BY_NAME(name)		(FindLayerByName(name))

// Set an object's layer
#define SET_OBJECT_LAYER(obj, layer)	SetObjLayer(obj, layer);

// Get an object's layer
#define GET_OBJECT_LAYER(obj)			(GetObjLayer(obj))

// Access to layer's properties
#define SET_LAYER_VISIBILITY(layer, visibility)	    SetLayerVisibility(layer, visibility);
#define GET_LAYER_VISIBILITY(layer)					(GetLayerVisibility(layer))

#define SET_LAYER_RENDERABLE(layer, renderable)		SetLayerRenderable(layer, renderable);
#define GET_LAYER_RENDERABLE(layer)					(GetLayerRenderable(layer))

#define SET_LAYER_BOX_MODE(layer, boxmode)			SetLayerBoxMode(layer, boxmode);
#define GET_LAYER_BOX_MODE(layer)					(GetLayerBoxMode(layer))

#define SET_LAYER_TRANSPARENT(layer, transparent)	SetLayerTransparent(layer, transparent);
#define GET_LAYER_TRANSPARENT(layer)				(GetLayerTransparent(layer))

