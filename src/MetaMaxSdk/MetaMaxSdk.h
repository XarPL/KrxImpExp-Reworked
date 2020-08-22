///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Meta language macroses for maxsdk
#ifndef META_MAXSDK_H
#define META_MAXSDK_H

#include <maxversion.h>

// Disable some warnings to allow msvs2005 compile plugin 
// with maxsdk 5 and 6 without warnings.
#if MAX_PRODUCT_VERSION_MAJOR <= 5
#pragma warning(disable:4002) // too many actual parameters for macro 'FN_0'
#endif
#if MAX_PRODUCT_VERSION_MAJOR <= 6
#pragma warning(disable:4996) // 'strcpy' was declared deprecated
#endif

// maxsdk 15 (3ds max 2013) uses nullptr
#if MAX_PRODUCT_VERSION_MAJOR >= 15
#define nullptr (0)
#endif

// maxsdk headers
#include <max.h>
#include <imtl.h>
#include <stdmat.h>
#include <bmmlib.h>
#include <meshdelta.h>
#include <mnmesh.h>
#include <simpobj.h>
#include <modstack.h>
#include <iparamb2.h>
#include <iskin.h>
#include <decomp.h>
#include <dummy.h>
#include <ilayer.h>
#include <ilayermanager.h>

// physique headers
#include <phyexp.h>

// Meta macroses for common C++ language
#include "MetaCpp.h"

#include "MetaMaxSdk_Importer.h"
#include "MetaMaxSdk_Exporter.h"
#include "MetaMaxSdk_StdDirs.h"
#include "MetaMaxSdk_Color.h"
#include "MetaMaxSdk_Material.h"
#include "MetaMaxSdk_Point3.h"
#include "MetaMaxSdk_Quat.h"
#include "MetaMaxSdk_Matrix3.h"
#include "MetaMaxSdk_Object.h"
#include "MetaMaxSdk_Mesh.h"
#include "MetaMaxSdk_Bone.h"
#include "MetaMaxSdk_Skin.h"
#include "MetaMaxSdk_Anim.h"
#include "MetaMaxSdk_Scene.h"
#include "MetaMaxSdk_Unit.h"
#include "MetaMaxSdk_Progress.h"
#include "MetaMaxSdk_Layer.h"

#endif // META_MAXSDK_H