///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Bone.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     August 5, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal function
static BaseObject* NewBoneObj(const std::tstring& name, BaseObject* parentBone, const Vector& boundBoxMinPoint, const Vector& boundBoxMaxPoint, const std::string& skinType)
{
#	if USE_BONES
	{
		if(skinType == "Claude Bonet tool")
		{
			BaseObject* obj = BaseObject::Alloc(Obone_EX);
			GetActiveDocument()->InsertObject(obj, parentBone, NULL, FALSE);
			obj->SetName(name.c_str());	
			obj->SetParameter(DescLevel(BONEOBJECT_LENGTH), GeData(boundBoxMaxPoint.x), DESCFLAGS_SET_PARAM_SET);
			obj->SetParameter(DescLevel(BONEOBJECT_VERTEXMAPMODE), GeData(TRUE), DESCFLAGS_SET_PARAM_SET);
			return obj;
		}
	}
#	endif // USE_BONES

#	if USE_JOINTS
	{
		if(skinType == "Weight tool")
		{
			BaseObject* obj = CAJointObject::Alloc();
			GetActiveDocument()->InsertObject(obj, parentBone, NULL, FALSE);
			obj->SetName(name.c_str());	
			obj->SetParameter(DescLevel(ID_CA_JOINT_OBJECT_LENGTH), GeData(boundBoxMaxPoint.x), DESCFLAGS_SET_PARAM_SET);
			return obj;
		}
	}
#	endif // USE_JOINTS

	return NULL;
}

// Create object which will be used as bone;
// If parentBone == ROOT_OBJECT, then this function will create a bone without a parent
#define NEW_BONE_OBJECT(name, parentBone, boundBoxMinPoint, boundBoxMaxPoint, skinType)	(NewBoneObj(name, parentBone, boundBoxMinPoint, boundBoxMaxPoint, skinType))
