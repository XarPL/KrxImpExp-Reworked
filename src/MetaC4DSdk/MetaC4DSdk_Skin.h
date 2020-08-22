///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Skin.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     August 5, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static std::vector<std::tstring> GetSupportedSkinTypes()
{
	std::vector<std::tstring> skinTypes;
	
#	if USE_JOINTS
	{
		skinTypes.push_back("Weight tool");
	}
#	endif // USE_JOINTS

#	if USE_BONES
	{
		skinTypes.push_back("Claude Bonet tool");
	}
#	endif // USE_BONES

	return skinTypes;
}

static void ConvertToSkinObj(BaseObject* obj, const std::tstring& skinType)
{
#	if USE_JOINTS
	{
		if(skinType == "Weight tool")
		{
			CAWeightTag* weightTag = CAWeightTag::Alloc();
			obj->InsertTag(weightTag);
		}
	}
#	endif // USE_JOINTS

#	if USE_BONES
	{
		if(skinType == "Claude Bonet tool")
		{
			int pointCount = ToPoly(obj)->GetPointCount();
			VariableTag* vartag = VariableTag::Alloc(Tclaudebonet_EX, pointCount);
			obj->InsertTag(vartag);
		}
	}
#	endif // USE_BONES
}

static bool IsSkinObj(BaseObject* obj)
{
#	if USE_JOINTS
	{
		if(obj->GetTag(Tweights))
			return true;
	}
#	endif // USE_JOINTS

#	if USE_BONES
	{
		if(obj->GetTag(Tclaudebonet_EX))
			return true;
	}
#	endif // USE_BONES

	return false;
}

// Internal class
class SkinData
{
	enum 
	{
		SKINTYPE_UNKNOWN,
		SKINTYPE_CLAUDE_BONET_TOOL,
		SKINTYPE_WEIGHT_TOOL
	};
	int                      __skinType;
	BaseObject*              __skinObj;
	int                      __numVerts;
	std::vector<BaseObject*> __bones;
	BaseObject*              __rootBone;
	String                   __prefix;

private:
	static void __FixBoneWithChildren(BaseObject* bone)
	{
#		if USE_BONES
		{
			GeData gdLength;
			bone->GetParameter(DescLevel(BONEOBJECT_LENGTH), gdLength, DESCFLAGS_GET_PARAM_GET);
			bone->SetParameter(DescLevel(BONEOBJECT_FIXLENGTH), gdLength, DESCFLAGS_SET_PARAM_SET);
			
			Matrix tm = bone->GetMl();
			Vector pos = tm.off;
			Vector rot = MatrixToHPB(tm);
			Vector scale = Vector(Len(tm.v1), Len(tm.v2), Len(tm.v3));
			bone->SetParameter(DescLevel(BONEOBJECT_FIXPOSITION), GeData(pos), DESCFLAGS_SET_PARAM_SET);
			bone->SetParameter(DescLevel(BONEOBJECT_FIXROTATION), GeData(rot), DESCFLAGS_SET_PARAM_SET);
			bone->SetParameter(DescLevel(BONEOBJECT_FIXSCALE), GeData(scale), DESCFLAGS_SET_PARAM_SET);

			bone->SetParameter(DescLevel(BONEOBJECT_FIXED), GeData(TRUE), DESCFLAGS_SET_PARAM_SET);
			bone->SetDeformMode(TRUE);

			for(BaseObject* child = bone->GetDown(); child != NULL; child = child->GetNext())
				if(child->GetType() == Obone_EX)
					__FixBoneWithChildren(child);
		}
#		endif // USE_BONES
	}

	void __KillWeightTags()
	{
#		if USE_JOINTS
		{
			while(__skinObj->GetTag(Tweights))
				__skinObj->KillTag(Tweights);
		}
#		endif // USE_JOINTS
	}

	void __KillClaudeBonetTags()
	{
#		if USE_BONES
		{
			while(__skinObj->GetTag(Tclaudebonet_EX))
				__skinObj->KillTag(Tclaudebonet_EX);
		}
#		endif
	}

	void __PrepareHierarchy(BaseObject* bone)
	{
		// find the root bone
		__rootBone = bone;
		while(__rootBone->GetUp() != NULL && IsBoneObj(__rootBone->GetUp()))
		{
			__rootBone = __rootBone->GetUp();
		}

		// retrieve the prefix
		String rootBoneName = __rootBone->GetName();
		String rootBoneNameUpr = rootBoneName.ToUpper();
		LONG rootBonePos;
		if(rootBoneNameUpr.FindFirst("BIP", &rootBonePos, 0))
			__prefix = rootBoneName.SubStr(0, rootBonePos);

		BaseObject* nullObj = __rootBone->GetUp();
		if(nullObj == NULL || nullObj->GetType() != Onull)
		{
			nullObj = BaseObject::Alloc(Onull);
			nullObj->SetName(__prefix);
			BaseDocument* doc = __skinObj->GetDocument();
			doc->InsertObject(nullObj, NULL, NULL, FALSE);
			SetParentObj(__rootBone, nullObj);
		}
		SetParentObj(__skinObj, nullObj);
		// Null object
		// |--> Bip01
		//      |--> zm_Skin
	}

	void __DetectSkinTypeByBoneType()
	{
		__skinType = SKINTYPE_UNKNOWN;
		LONG type = __rootBone->GetType();
#		if USE_BONES
		{
			if(type == Obone_EX)
				__skinType = SKINTYPE_CLAUDE_BONET_TOOL;
		}
#		endif // USE_BONES

#		if USE_JOINTS
		{
			if(type == Ojoint)
				__skinType = SKINTYPE_WEIGHT_TOOL;
		}
#		endif // USE_JOINTS
	}

	void __InsertSkinModifier()
	{
#		if USE_JOINTS
		{
			BaseObject* nullObj = __rootBone->GetUp();
			bool skinModFound = false;
			for(BaseObject* child = nullObj->GetDown(); child != NULL; child = child->GetNext())
				if(child->GetType() == Oskin)
				{
					skinModFound = true;
					break;
				}

			if(!skinModFound)
			{
				BaseObject* skinMod = BaseObject::Alloc(Oskin);
				skinMod->SetName(__prefix);
				BaseDocument* doc = __skinObj->GetDocument();
				doc->InsertObject(skinMod, nullObj, __skinObj, FALSE);
			}
		}
#		endif // USE_JOINTS
	}

	void __AddBone(BaseObject* bone)
	{
#		if USE_BONES
		{
			VariableTag* vartag = (VariableTag*) (__skinObj->GetTag(Tclaudebonet_EX));
			if(vartag)
			{
				GeData gedata;
				vartag->GetParameter(DescLevel(CLAUDEBONETTAG_BONE), gedata, DESCFLAGS_GET_PARAM_GET);
				BaseDocument* doc = __skinObj->GetDocument();
				if(gedata.GetLink(doc))
					vartag = NULL;
			}
			
			if(!vartag)
			{
				vartag = VariableTag::Alloc(Tclaudebonet_EX, __numVerts);
				__skinObj->InsertTag(vartag);
			}
			
			BaseLink* link = BaseLink::Alloc();
			link->SetLink(bone);
			vartag->SetParameter(DescLevel(CLAUDEBONETTAG_BONE), GeData(link), DESCFLAGS_SET_PARAM_SET);
			BaseLink::Free(link);
			
			Real* weights = (Real*) (vartag->GetLowlevelDataAddressW());
			int u = vartag->GetDataSize();
			for(int j = 0; j < __numVerts; ++j)
				weights[j] = 0.0f;
		}
#		endif // USE_BONES
	}

	void __AddJoint(BaseObject* bone)
	{
#		if USE_JOINTS
		{
			CAWeightTag* weightTag = (CAWeightTag*) (__skinObj->GetTag(Tweights));
			if(!weightTag)
			{
				weightTag = CAWeightTag::Alloc();
				__skinObj->InsertTag(weightTag);
			}

			LONG jointIndex = -1;
#					if USE_CA_WEIGHT_TAG_ADD_JOINT
			{
				jointIndex = weightTag->AddJoint(bone);
			}
#					else // !USE_CA_WEIGHT_TAG_ADD_JOINT
			{
				GeData gedata;
				if(weightTag->GetParameter(DescLevel(ID_CA_WEIGHT_TAG_JOINTS), gedata, 0))
				{
					InExcludeData* jointList = (InExcludeData*) (gedata.GetCustomDataType(CUSTOMDATATYPE_INEXCLUDE_LIST));
					jointIndex = jointList->GetObjectCount();
					jointList->InsertObject(bone, 0);
					weightTag->SetParameter(DescLevel(ID_CA_WEIGHT_TAG_JOINTS), gedata, 0);
				}
			}
#					endif // USE_CA_WEIGHT_TAG_ADD_JOINT

			if(jointIndex != -1)
			{
				for(int j = 0; j < __numVerts; ++j)
					weightTag->SetWeight(jointIndex, j, 0.0f);
			}
		}
#		endif // USE_JOINTS
	}

	void __DetectSkinTypeBySkinTag()
	{
		__skinType = SKINTYPE_UNKNOWN;

#		if USE_JOINTS
		{
			if(__skinObj->GetTag(Tweights))
			{
				__skinType = SKINTYPE_WEIGHT_TOOL;
			}
		}
#		endif // USE_JOINTS

#		if USE_BONES
		{
			if(__skinObj->GetTag(Tclaudebonet_EX))
			{
				__skinType = SKINTYPE_CLAUDE_BONET_TOOL;
			}
		}
#		endif // USE_BONES
	}

	void __GetBonesFromSkin()
	{
#		if USE_BONES
		{
			if(__skinType == SKINTYPE_CLAUDE_BONET_TOOL)
			{
				BaseTag* tag = __skinObj->GetFirstTag();
				for(; tag != NULL; tag = tag->GetNext())
				{
					if(tag->GetType() == Tclaudebonet_EX)
					{
						GeData gedata;
						tag->GetParameter(DescLevel(CLAUDEBONETTAG_BONE), gedata, DESCFLAGS_GET_PARAM_GET);
						BaseDocument* doc = __skinObj->GetDocument();
						BaseObject* bone = (BaseObject*) gedata.GetLink(doc);
						if(bone != NULL)
							__bones.push_back(bone);
					}
				}
			}
		}
#		endif // USE_BONES
	}

	void __GetJointsFromSkin()
	{
#		if USE_JOINTS
		{
			if(__skinType == SKINTYPE_WEIGHT_TOOL)
			{
				CAWeightTag* weightTag = (CAWeightTag*) (__skinObj->GetTag(Tweights));
				LONG jointCount = weightTag->GetJointCount();
				BaseDocument* doc = __skinObj->GetDocument();
				for(LONG i = 0; i < jointCount; ++i)
					__bones.push_back(weightTag->GetJoint(i, doc));
			}
		}
#		endif // USE_JOINTS
	}

public:
	SkinData(BaseObject* obj)
	{
		__rootBone = NULL;
		__skinObj = obj;
		__numVerts = ToPoly(__skinObj)->GetPointCount();

		__DetectSkinTypeBySkinTag();
		
		if(__skinType == SKINTYPE_CLAUDE_BONET_TOOL)
			__GetBonesFromSkin();
		if(__skinType == SKINTYPE_WEIGHT_TOOL)
			__GetJointsFromSkin();
	}

	std::tstring GetSkinType() const
	{
		std::tstring skinTypeAsStr = _T("");
		switch(__skinType)
		{
			case SKINTYPE_CLAUDE_BONET_TOOL: skinTypeAsStr = "Claude Bonet tool"; break;
			case SKINTYPE_WEIGHT_TOOL: skinTypeAsStr = "Weight tool"; break;
		}
		return skinTypeAsStr;
	}

	void AddBonesToSkin(const std::vector<BaseObject*>& bones)
	{
		BaseDocument* doc = __skinObj->GetDocument();
		for(size_t i = 0; i < bones.size(); ++i)
		{
			BaseObject* bone = bones[i];

			if(__bones.size() == 0)
			{
				// prepare hierarchy
				__PrepareHierarchy(bone);

				// autodetect skin type
				__DetectSkinTypeByBoneType();

				if(__skinType == SKINTYPE_CLAUDE_BONET_TOOL)
				{
					__KillWeightTags();
					__FixBoneWithChildren(__rootBone);
				}
				else if(__skinType == SKINTYPE_WEIGHT_TOOL)
				{
					__KillClaudeBonetTags();
					__InsertSkinModifier();

				}

			} // (__bones.size() == 0)

			if(__skinType == SKINTYPE_CLAUDE_BONET_TOOL)
			{
				__AddBone(bone);
			}
			else if(__skinType == SKINTYPE_WEIGHT_TOOL)
			{
				__AddJoint(bone);
			}

			__bones.push_back(bone);
		}
	}
		
	int GetNumSkinBones() const
	{
		return (int) __bones.size();
	}

	BaseObject* GetSkinBone(int nBoneIndex) const
	{
		return __bones[nBoneIndex];
	}

	int GetNumSkinVerts() const
	{
		return __numVerts;
	}

	void SetVertWeights(int vertIdx, const std::vector<BaseObject*>& bones, const std::vector<float>& weights)
	{
		BaseDocument* doc = __skinObj->GetDocument();
		for(size_t i = 0; i < bones.size(); ++i)
		{
			BaseObject* bone = bones[i];
			Real w = Real(weights[i]);

#			if USE_BONES
			{
				if(__skinType == SKINTYPE_CLAUDE_BONET_TOOL)
				{
					VariableTag* vartag = NULL;
					BaseTag* tag = __skinObj->GetFirstTag();
					for(; tag != NULL; tag = tag->GetNext())
					{
						if(tag->GetType() == Tclaudebonet_EX)
						{
							GeData gedata;
							tag->GetParameter(DescLevel(CLAUDEBONETTAG_BONE), gedata, DESCFLAGS_GET_PARAM_GET);
							if(gedata.GetLink(doc) == bone)
							{
								vartag = (VariableTag*)tag;
								break;
							}
						}
					}
					if(vartag != NULL)
					{
						Real* data = (Real*) vartag->GetLowlevelDataAddressW();
						data[vertIdx] = w;
					}
				}
			}
#			endif // USE_BONES

#			if USE_JOINTS
			{
				if(__skinType == SKINTYPE_WEIGHT_TOOL)
				{
					CAWeightTag* weightTag = (CAWeightTag*) (__skinObj->GetTag(Tweights));
					LONG jointIndex = weightTag->FindJoint(bone, GetActiveDocument());
					if(jointIndex != NOTOK)
						weightTag->SetWeight(jointIndex, vertIdx, w);
				}
			}
#			endif // USE_JOINTS
		}
	}

	int GetVertNumWeights(int vertIdx) const
	{
		int numWeights = 0;

#		if USE_BONES
		{
			if(__skinType == SKINTYPE_CLAUDE_BONET_TOOL)
			{
				BaseTag* tag = __skinObj->GetFirstTag();
				for(; tag != NULL; tag = tag->GetNext())
				{
					if(tag->GetType() == Tclaudebonet_EX)
					{
						VariableTag* vartag = (VariableTag*) tag;
						const Real* data = (const Real*) vartag->GetLowlevelDataAddressR();
						if(data[vertIdx] != 0.0)
							++numWeights;
					}
				}
			}
		}
#		endif // USE_BONES

#		if USE_JOINTS
		{
			if(__skinType == SKINTYPE_WEIGHT_TOOL)
			{
				CAWeightTag* weightTag = (CAWeightTag*) (__skinObj->GetTag(Tweights));
				LONG numJoints = weightTag->GetJointCount();
				for(LONG i = 0; i < numJoints; ++i)
				{
					if(weightTag->GetWeight(i, vertIdx) != 0.0)
						++numWeights;
				}
			}
		}
#		endif // USE_JOINTS

		return numWeights;
	}

	float GetVertWeight(int vertIdx, int vertBoneIdx) const
	{
		float weight = 0.0f;

#		if USE_BONES
		{
			if(__skinType == SKINTYPE_CLAUDE_BONET_TOOL)
			{
				int numWeights = 0;
				BaseTag* tag = __skinObj->GetFirstTag();
				for(; tag != NULL; tag = tag->GetNext())
				{
					if(tag->GetType() == Tclaudebonet_EX)
					{
						VariableTag* vartag = (VariableTag*) tag;
						const Real* data = (const Real*) vartag->GetLowlevelDataAddressR();
						if(data[vertIdx] != 0.0)
						{
							if(numWeights == vertBoneIdx)
							{
								weight = (float) data[vertIdx];
								break;
							}
							++numWeights;
						}
					}
				}
			}
		}
#		endif // USE_BONES

#		if USE_JOINTS
		{
			if(__skinType == SKINTYPE_WEIGHT_TOOL)
			{
				int numWeights = 0;
				CAWeightTag* weightTag = (CAWeightTag*) (__skinObj->GetTag(Tweights));
				LONG numJoints = weightTag->GetJointCount();
				for(LONG i = 0; i < numJoints; ++i)
				{
					Real w = weightTag->GetWeight(i, vertIdx);
					if(w != 0.0)
					{
						if(numWeights == vertBoneIdx)
						{
							weight = (float) w;
							break;
						}
						++numWeights;
					}
				}
			}
		}
#		endif // USE_JOINTS

		return weight;
	}

	BaseObject* GetVertWeightBone(int vertIdx, int vertBoneIdx) const
	{
		BaseDocument* doc = __skinObj->GetDocument();
		BaseObject* bone = NULL;

#		if USE_BONES
		{
			if(__skinType == SKINTYPE_CLAUDE_BONET_TOOL)
			{
				int numWeights = 0;
				BaseTag* tag = __skinObj->GetFirstTag();
				for(; tag != NULL; tag = tag->GetNext())
				{
					if(tag->GetType() == Tclaudebonet_EX)
					{
						VariableTag* vartag = (VariableTag*) tag;
						const Real* data = (const Real*) vartag->GetLowlevelDataAddressR();
						if(data[vertIdx] != 0.0)
						{
							if(numWeights == vertBoneIdx)
							{
								GeData gedata;
								tag->GetParameter(DescLevel(CLAUDEBONETTAG_BONE), gedata, DESCFLAGS_GET_PARAM_GET);
								bone = (BaseObject*) gedata.GetLink(doc);
								break;
							}
							++numWeights;
						}
					}
				}
			}
		}
#		endif // USE_BONES

#		if USE_JOINTS
		{
			if(__skinType == SKINTYPE_WEIGHT_TOOL)
			{
				int numWeights = 0;
				CAWeightTag* weightTag = (CAWeightTag*) (__skinObj->GetTag(Tweights));
				LONG numJoints = weightTag->GetJointCount();
				for(LONG i = 0; i < numJoints; ++i)
				{
					if(weightTag->GetWeight(i, vertIdx) != 0.0)
					{
						if(numWeights == vertBoneIdx)
						{
							bone = weightTag->GetJoint(i, doc);
							break;
						}
						++numWeights;
					}
				}
			}
		}
#		endif // USE_JOINTS

		return bone;
	}
};

// Get list of skin types supported by the 3D Editor
#define GET_SUPPORTED_SKIN_TYPES				(GetSupportedSkinTypes())

// Convert triangular mesh object to skin object
#define CONVERT_TO_SKIN_OBJECT(obj, skintype)		ConvertToSkinObj(obj, skintype);

// Check if the object specified is a skin object
#define IS_SKIN_OBJECT(obj)							(IsSkinObj(obj))

// Skin data
#define TSKIN								SkinData

// Create an instance of the SkinData struct to access to the skin properties
#define GET_SKIN(obj)						(SkinData(obj))

// Get skin type
#define GET_SKIN_TYPE(sd)					(sd.GetSkinType())

// Adds a bone to the current system.
#define ADD_BONES_TO_SKIN(sd, bones)		sd.AddBonesToSkin(bones);

// This method returns the actual number of bones in the system.
#define GET_NUM_SKIN_BONES(sd)				(sd.GetNumSkinBones())

// This method returns the INode of a particular bone. 
#define GET_SKIN_BONE(sd, boneID)			(sd.GetSkinBone(boneID))

// Returns the number of vertices for the object the Skin modifier is applied to. 
#define GET_NUM_SKIN_VERTS(sd)				(sd.GetNumSkinVerts())

// Sets the influence of the specified bones to the specified vertex.
#define SET_VERTEX_WEIGHTS(sd, vertIdx, bones, weights) \
	sd.SetVertWeights(vertIdx, bones, weights);

// Returns the number of bones influencing the specified vertex. 
#define GET_VERTEX_NUM_WEIGHTS(sd, vertIdx)	\
	(sd.GetVertNumWeights(vertIdx))

// Returns the influence of the Nth bone affecting the specified vertex. 
#define GET_VERTEX_WEIGHT(sd, vertIdx, vertBoneIdx) \
	(sd.GetVertWeight(vertIdx, vertBoneIdx))

// Returns the system bone index of the Nth bone affecting the specified vertex. 
#define GET_VERTEX_WEIGHT_BONE(sd, vertIdx, vertBoneIdx) \
	(sd.GetVertWeightBone(vertIdx, vertBoneIdx))
