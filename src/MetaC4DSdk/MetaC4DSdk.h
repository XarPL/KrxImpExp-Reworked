///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 13, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef META_C4DSDK_H
#define META_C4DSDK_H

// Meta macroses for common C++ language
#include "MetaCpp.h"

// Undefining FALSE and TRUE
#ifdef FALSE
#undef FALSE
#endif
#ifdef TRUE
#undef TRUE
#endif

// Cinema4D C++ SDK headers
#include "c4d.h"
#include "c4d_quaternion.h"
#include "obone.h"
#include "obase.h"
#include "tclaudebonet.h"

#if API_VERSION >= 9800
#include "customgui_pla.h"
#include "customgui_inexclude.h"
#include "lib_ca.h"
#include "ocajoint.h"
#include "ocaskin.h"
#include "tcaweight.h"
#endif

// The "USE_*" macroses
#define USE_CTRACK                  0 // use the "CTrack" class (instead of "BaseTrack")
#define USE_JOINTS                  0 // use joints and the "CAWeightTag" class
#define USE_CA_WEIGHT_TAG_ADD_JOINT 0 // use the "CAWeightTag::AddJoint" function
#define USE_BONES                   0 // use bones and the claude-bonet tool
#define USE_LAYERS                  0 // use the "LayerObject" class
#define USE_UVW_HANDLE              0 // use the UVWHandle typedef
#define USE_PLA_DATA_POINT_TAG      0 // use the new form of PLAData::GetVariableTags which gets a pointer to PointTag
#define USE_BASE_DOCUMENT_EXECUTE_PASSES            0 // use the "BaseDocument::ExecutePasses" function
#define USE_BASE_DOCUMENT_EXECUTE_PASSES_BUILDFLAGS 0 //  use the "BaseDocument::ExecutePasses" function with the BUILDFLAGS parameter

#if API_VERSION >= 9800
#undef  USE_CTRACK    
#define USE_CTRACK    1        
#undef  USE_JOINTS
#define USE_JOINTS    1        
#undef  USE_LAYERS
#define USE_LAYERS    1        
#endif

#if API_VERSION >= 11500
#undef  USE_CA_WEIGHT_TAG_ADD_JOINT
#define USE_CA_WEIGHT_TAG_ADD_JOINT       1  
#undef  USE_BASE_DOCUMENT_EXECUTE_PASSES
#define USE_BASE_DOCUMENT_EXECUTE_PASSES  1
#endif

#if API_VERSION >= 12000
#undef  USE_UVW_HANDLE
#define USE_UVW_HANDLE	        1		
#undef  USE_PLA_DATA_POINT_TAG
#define USE_PLA_DATA_POINT_TAG  1
#undef  USE_BASE_DOCUMENT_EXECUTE_PASSES_BUILDFLAGS
#define USE_BASE_DOCUMENT_EXECUTE_PASSES_BUILDFLAGS 1
#endif

#if API_VERSION < 12000
#undef  USE_BONES
#define USE_BONES  1
#endif

// The renaming macroses
#if API_VERSION < 9800
#define GetPointR        GetPoint
#define GetPointW        GetPoint
#define GetPolygonR      GetPolygon
#define GetPolygonW      GetPolygon
#define GetDataAddressR  GetDataAddress
#define GetDataAddressW  GetDataAddress
#endif  

#if API_VERSION < 12000
#define COPYFLAGS_NO_HIERARCHY      COPY_NO_HIERARCHY    
#define COPYFLAGS_NO_BITS           COPY_NO_BITS        
#define COPYFLAGS_NO_ANIMATION      COPY_NO_ANIMATION   
#define Obone_EX                    Obone               
#define Tclaudebonet_EX	            Tclaudebonet        
#define CINTERPOLATION_LINEAR       CINTER_LINEAR       
#define ID_BASEOBJECT_REL_POSITION  ID_BASEOBJECT_POSITION  
#define ID_BASEOBJECT_REL_ROTATION  ID_BASEOBJECT_ROTATION  
#define ID_BASEOBJECT_REL_SCALE     ID_BASEOBJECT_SCALE     
#define DESCFLAGS_SET_PARAM_SET     0
#define DESCFLAGS_GET_PARAM_GET     0
#define DRAWFLAGS_NO_THREAD         DA_NO_THREAD
#define GetLowlevelDataAddressR     GetDataAddressR
#define GetLowlevelDataAddressW     GetDataAddressW
#endif


// Disable some warnings to allow compile plugin 
// with c4dsdk 10.5 without warnings.
#pragma warning(disable:4291) // a placement new is used for which there is no placement delete.

// Defining FALSE and TRUE again
#ifdef FALSE
#undef FALSE
#endif
#define FALSE	false
#ifdef TRUE
#undef TRUE
#endif
#define TRUE	true

#include "MetaC4DSdk_Importer.h"
#include "MetaC4DSdk_Exporter.h"
#include "MetaC4DSdk_StdDirs.h"
#include "MetaC4DSdk_Color.h"
#include "MetaC4DSdk_Material.h"
#include "MetaC4DSdk_SwapAxes.h"
#include "MetaC4DSdk_Point3.h"
#include "MetaC4DSdk_Quat.h"
#include "MetaC4DSdk_Matrix3.h"
#include "MetaC4DSdk_Object.h"
#include "MetaC4DSdk_Mesh.h"
#include "MetaC4DSdk_Bone.h"
#include "MetaC4DSdk_Skin.h"
#include "MetaC4DSdk_Anim.h"
#include "MetaC4DSdk_Scene.h"
#include "MetaC4DSdk_Unit.h"
#include "MetaC4DSdk_Layer.h"
#include "MetaC4DSdk_Progress.h"

#endif // META_C4DSDK_H