///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Layer.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     January 6, 2010
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#if USE_LAYERS

// Internal functions
static LayerObject* NewLayer(const std::string& name)
{
    BaseDocument* doc = GetActiveDocument();
    LayerObject* layerObj = LayerObject::Alloc();
    layerObj->SetName(name.c_str());
    doc->GetLayerObjectRoot()->InsertLast(layerObj);
	return layerObj;
}

static void SetLayerName(LayerObject* layerObj, const std::string& name)
{
	layerObj->SetName(name.c_str());
}

static std::string GetLayerName(LayerObject* layerObj)
{
	const String& str = layerObj->GetName();
	int len = str.GetCStringLen();
	std::tstring tstr(len, ' ');
	str.GetCString(&tstr[0], len + 1);
	return tstr;
}

static LayerObject* FindLayerByName(const std::string& name)
{
    BaseDocument* doc = GetActiveDocument();
    GeListHead* list = doc->GetLayerObjectRoot();
    for(LayerObject* layerObj = (LayerObject*) list->GetFirst(); layerObj != NULL; layerObj = layerObj->GetNext())
        if(layerObj->GetName() == name.c_str())
            return layerObj;
            
    return NULL;
}

static void SetObjLayer(BaseObject* obj, LayerObject* layerObj)
{
	obj->SetLayerObject(layerObj);
}

static LayerObject* GetObjLayer(BaseObject* obj)
{
    BaseDocument* doc = GetActiveDocument();
	return obj->GetLayerObject(doc);
}

static void SetLayerVisibility(LayerObject* layerObj, bool visibility)
{
    BaseDocument* doc = GetActiveDocument();
    const LayerData* data = layerObj->GetLayerData(doc);
    LayerData newdata(*data);
    newdata.view = visibility;
    layerObj->SetLayerData(doc, newdata);
}

static bool GetLayerVisibility(LayerObject* layerObj)
{
    BaseDocument* doc = GetActiveDocument();
    const LayerData* data = layerObj->GetLayerData(doc);
	return data->view != 0;
}

static void SetLayerRenderable(LayerObject* layerObj, bool renderable)
{
    BaseDocument* doc = GetActiveDocument();
    const LayerData* data = layerObj->GetLayerData(doc);
    LayerData newdata(*data);
    newdata.render = renderable;
    layerObj->SetLayerData(doc, newdata);
}

static bool GetLayerRenderable(LayerObject* layerObj)
{
    BaseDocument* doc = GetActiveDocument();
    const LayerData* data = layerObj->GetLayerData(doc);
    return data->render != 0;
}

static void SetLayerBoxMode(LayerObject* layerObj, bool boxMode)
{
}

static bool GetLayerBoxMode(LayerObject* layerObj)
{
	return false;
}

static void SetLayerTransparent(LayerObject* layerObj, bool transparent)
{
}

static bool GetLayerTransparent(LayerObject* layerObj)
{
	return false;
}

// Layer
#define TLAYER								LayerObject*
#define INVALID_LAYER						NULL

#define NEW_LAYER(name)						(NewLayer(name))

// Set name of a layer
#define SET_LAYER_NAME(layerObj, name)		SetLayerName(layerObj, name);

// Get name of a layer
#define GET_LAYER_NAME(layerObj)			(GetLayerName(layerObj))

// Find a layer by name; returns INVALID_LAYER if not found
#define FIND_LAYER_BY_NAME(name)			(FindLayerByName(name))

// Set an object's layer
#define SET_OBJECT_LAYER(obj, layerObj)		SetObjLayer(obj, layerObj);

// Get an object's layer
#define GET_OBJECT_LAYER(obj)				(GetObjLayer(obj))

// Access to layer's properties
#define SET_LAYER_VISIBILITY(layerObj, visibility)	    SetLayerVisibility(layerObj, visibility);
#define GET_LAYER_VISIBILITY(layerObj)					(GetLayerVisibility(layerObj))

#define SET_LAYER_RENDERABLE(layerObj, renderable)		SetLayerRenderable(layerObj, renderable);
#define GET_LAYER_RENDERABLE(layerObj)					(GetLayerRenderable(layerObj))

#define SET_LAYER_BOX_MODE(layerObj, boxmode)			SetLayerBoxMode(layerObj, boxmode);
#define GET_LAYER_BOX_MODE(layerObj)					(GetLayerBoxMode(layerObj))

#define SET_LAYER_TRANSPARENT(layerObj, transparent)	SetLayerTransparent(layerObj, transparent);
#define GET_LAYER_TRANSPARENT(layerObj)					(GetLayerTransparent(layerObj))

#else // !USE_LAYERS
///////////////////////////////////////////////////////////////////////////////////////////////////////////

// Layer
#define TLAYER								void*
#define INVALID_LAYER						NULL

#define NEW_LAYER(name)						NULL

// Set name of a layer
#define SET_LAYER_NAME(layerObj, name)		NULL;

// Get name of a layer
#define GET_LAYER_NAME(layerObj)			""

// Find a layer by name; returns INVALID_LAYER if not found
#define FIND_LAYER_BY_NAME(name)			NULL

// Set an object's layer
#define SET_OBJECT_LAYER(obj, layerObj)		NULL;

// Get an object's layer
#define GET_OBJECT_LAYER(obj)				NULL

// Access to layer's properties
#define SET_LAYER_VISIBILITY(layerObj, visibility)	    NULL;
#define GET_LAYER_VISIBILITY(layerObj)					true

#define SET_LAYER_RENDERABLE(layerObj, renderable)		NULL;
#define GET_LAYER_RENDERABLE(layerObj)					true

#define SET_LAYER_BOX_MODE(layerObj, boxmode)			NULL;
#define GET_LAYER_BOX_MODE(layerObj)					false

#define SET_LAYER_TRANSPARENT(layerObj, transparent)	NULL;
#define GET_LAYER_TRANSPARENT(layerObj)					false

#endif // USE_LAYERS
