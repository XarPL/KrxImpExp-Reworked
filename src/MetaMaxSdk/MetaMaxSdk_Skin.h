///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Skin.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static std::vector<std::tstring> GetSupportedSkinTypes()
{
	std::vector<std::tstring> skinTypes;
	skinTypes.push_back(_T("Physique modifier"));
	skinTypes.push_back(_T("Skin modifier"));
	return skinTypes;
}

static void ConvertToSkinObj(INode* node, const std::tstring& skinType)
{
	// Create a derived object "around" the object 
	// and make the node reference it.
	Object* obj = node->GetObjectRef();
	IDerivedObject* derObj = CreateDerivedObject(obj);
	node->SetObjectRef(derObj);

	// Create modifier
	Modifier* mod = NULL;
	if(skinType == _T("Physique modifier"))
	{
		mod = (Modifier*) (GetInterface()->CreateInstance(
				OSM_CLASS_ID, Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B)));
		GetInterface()->GetRootNode()->AttachChild(node, 1);
	}
	else if(skinType == _T("Skin modifier"))
	{
		mod = (Modifier*) (GetInterface()->CreateInstance(OSM_CLASS_ID, SKIN_CLASSID));
		GetInterface()->GetRootNode()->AttachChild(node, 1);
	}

	// Add the Skin modifier to the derived object.
	derObj->SetAFlag(A_LOCK_TARGET); 
	derObj->AddModifier(mod);
	derObj->ClearAFlag(A_LOCK_TARGET);

	// Fix by Jean-Francois Yelle:
	GetInterface()->ForceCompleteRedraw(0);
}

static bool IsSkinObj(INode* node)
{
	if(node->GetObjectRef()->SuperClassID() != GEN_DERIVOB_CLASS_ID)
		return false;
	
	IDerivedObject* derObj = (IDerivedObject*) (node->GetObjectRef());
	if(derObj && derObj->NumModifiers() < 1)
		return false;
		
	Modifier* mod = derObj->GetModifier(0);			
	if(mod && mod->ClassID() != SKIN_CLASSID 
		&& mod->ClassID() != Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B))
		return false;
		
	return true;
}

// Internal class
class SkinData
{
private:
	Modifier* 			__modifier;
	INode*				__skinNode;
	std::vector<INode*>	__bones;
	bool                __physiqueInitialized;

private:
	bool __IsAncestor(INode* ancestor, INode* bone)
	{
		while(!bone->IsRootNode())
		{
			bone = bone->GetParentNode();
			if(ancestor == bone)
				return true;
		}
		return false;
	}

	INode* __FindCommonAncestor(INode* bone1, INode* bone2)
	{
		if(bone1 == bone2)
			return bone1;

		if(__IsAncestor(bone1, bone2))
			return bone1;

		if(__IsAncestor(bone2, bone1))
			return bone2;

		return __FindCommonAncestor(bone1->GetParentNode(), bone2->GetParentNode());
	}

	INode* __FindRootBone()
	{
		if(__bones.empty())
			return NULL;

		INode* rootBone = __bones[0];
		for(size_t i = 1; i < __bones.size(); ++i)
		{
			rootBone = __FindCommonAncestor(rootBone, __bones[i]);
		}
		return rootBone;
	}

	void __CreateDummiesForPhysique(INode* rootBone)
	{
		TimeValue t = GetInterface()->GetTime();
		
		std::tstring modelPrefix = _T("");
		std::tstring rootBoneName = rootBone->GetName();
		int k = (int) UCaseStr(rootBoneName).find(_T("BIP"));
		if(k > 0)
			modelPrefix = rootBoneName.substr(0, k);
		
		for(size_t i = 0; i < __bones.size(); ++i)
		{
			INode* bone = __bones[i];
			INode* parent = bone->GetParentNode();
			if(!parent->IsRootNode())
			{
				bool createDummy = true;
				Point3 parentPos = parent->GetNodeTM(t).GetTrans();
				Point3 bonePos = bone->GetNodeTM(t).GetTrans();
				float eps = (bonePos - parentPos).Length() / 100;
				int numChildren = bone->NumberOfChildren();
				
				for(int j = 0; j < numChildren; ++j)
					if( (bone->GetChildNode(j)->GetNodeTM(t).GetTrans() - bonePos).Length() > eps )
					{
						createDummy = false;
						break;
					}
				
				if(createDummy)
				{
					std::tstring dummyName = UniqueNam(modelPrefix + _T("Dummy00"));
					Point3 dummyPos = bonePos + (bonePos - parentPos) / 2;
					DummyObject* dummyObject = (DummyObject*) GetInterface()->CreateInstance(HELPER_CLASS_ID, Class_ID(DUMMY_CLASS_ID,0));
					dummyObject->SetBox(Box3(Point3(-0.25, -0.25, -0.25), Point3(0.25, 0.25, 0.25)));
					INode* dummy = GetInterface()->CreateObjectNode(dummyObject);
					dummy->SetName((LPTSTR) (dummyName.c_str()));
					dummy->SetNodeTM(t, TransMatrix(dummyPos));
					bone->AttachChild(dummy, 1); 
				}					
			}
		}
	}
	
public:
	SkinData(INode* node)
	{
		IDerivedObject* derObj = (IDerivedObject*) (node->GetObjectRef());
		__modifier = derObj->GetModifier(0);
		__skinNode = node;
		
		if(__modifier->ClassID() == SKIN_CLASSID)
		{
			ISkin* sknIf = (ISkin*) __modifier->GetInterface(I_SKIN);
			for(int i = 0; i < sknIf->GetNumBones(); ++i)
			{
				__bones.push_back(sknIf->GetBone(i));
			}
			__modifier->ReleaseInterface(I_SKIN, sknIf);
		}
		else if(__modifier->ClassID() == Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B))
		{
			IPhysiqueExport *physiqueExport = (IPhysiqueExport *)__modifier->GetInterface(I_PHYEXPORT);
			IPhyContextExport *phyContextExport = (IPhyContextExport *) physiqueExport->GetContextInterface(__skinNode);
			phyContextExport->ConvertToRigid(true);
			phyContextExport->AllowBlending(true);
			int numVerts = phyContextExport->GetNumberVertices();
			for(int i = 0; i < numVerts; ++i)
			{
				IPhyVertexExport* vi = phyContextExport->GetVertexInterface(i);
				int vtyp = vi->GetVertexType();
				std::vector<INode*> nodes;
				if(vtyp == RIGID_BLENDED_TYPE)
				{
					IPhyBlendedRigidVertex* rb_vtx = (IPhyBlendedRigidVertex*) vi;
					for(int j = 0; j < rb_vtx->GetNumberNodes(); ++j)
						nodes.push_back(rb_vtx->GetNode(j));
				}
				else if(vtyp == RIGID_TYPE)
				{
					IPhyRigidVertex* r_vtx = (IPhyRigidVertex*) vi;
					nodes.push_back(r_vtx->GetNode());
				}
				for(int k = 0; k < (int) nodes.size(); ++k)
				{
					bool found = false;
					for(int l = 0; l < (int) __bones.size(); ++l)
						if(__bones[l] == nodes[k])
						{
							found = true;
							break;
						}
					if(!found)
						__bones.push_back(nodes[k]);
				}
				phyContextExport->ReleaseVertexInterface(vi);
			}
			physiqueExport->ReleaseContextInterface(phyContextExport);
			__modifier->ReleaseInterface(I_PHYINTERFACE, physiqueExport);
			__physiqueInitialized = !__bones.empty();
		}
	}
	
	std::tstring GetSkinType() const
	{
		if(__modifier->ClassID() == SKIN_CLASSID)
			return _T("Skin modifier");
		else if(__modifier->ClassID() == Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B))
			return _T("Physique modifier");
		else
			return _T("");
	}	

	void AddBonesToSkin(const std::vector<INode*>& bones)
	{
		if(__modifier->ClassID() == SKIN_CLASSID)
		{
			ISkinImportData *skinImportData = (ISkinImportData*) 
				(__modifier->GetInterface(I_SKINIMPORTDATA));
			for(unsigned int i = 0; i < bones.size(); ++i)
			{
				INode* bone = bones[i];
				skinImportData->AddBoneEx(bone, false);
				Matrix3 nodeTM = bone->GetNodeTM(GetInterface()->GetTime());
				Matrix3 objectTM = bone->GetObjectTM(GetInterface()->GetTime());
				skinImportData->SetBoneTm(bone, objectTM, nodeTM);
				__bones.push_back(bone);
			}
			__modifier->ReleaseInterface(I_SKINIMPORTDATA, skinImportData);		
		}
		else if(__modifier->ClassID() == Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B))
		{
			for(unsigned int i = 0; i < bones.size(); ++i)
			{
				INode* bone = bones[i];
				__bones.push_back(bone);
			}
		}
	}
	
	int GetNumSkinBones() const
	{
		return (int) __bones.size();
	}

	INode* GetSkinBone(int nBoneIndex) const
	{
		return __bones[nBoneIndex];
	}

	int GetNumSkinVerts() const
	{
		int numVerts = 0;
		if(__modifier->ClassID() == SKIN_CLASSID)
		{
			ISkin* skinIf = (ISkin*) __modifier->GetInterface(I_SKIN);
			ISkinContextData* skinContextData = skinIf->GetContextInterface(__skinNode);
			numVerts = skinContextData->GetNumPoints();
			__modifier->ReleaseInterface(I_SKIN, skinIf);
		}
		else if(__modifier->ClassID() == Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B))
		{
			IPhysiqueExport *physiqueExport = (IPhysiqueExport *) __modifier->GetInterface(I_PHYEXPORT);
			IPhyContextExport *phyContextExport = (IPhyContextExport *) physiqueExport->GetContextInterface(__skinNode);
			numVerts = phyContextExport->GetNumberVertices();		
			physiqueExport->ReleaseContextInterface(phyContextExport);
			__modifier->ReleaseInterface(I_PHYINTERFACE, physiqueExport);
		}
		return numVerts;
	}

	void SetVertWeights(int vertIdx, const std::vector<INode*>& bones, const std::vector<float>& weights)
	{
		if(__modifier->ClassID() == SKIN_CLASSID)
		{
			ISkinImportData* skinImportData = (ISkinImportData*) 
				__modifier->GetInterface(I_SKINIMPORTDATA);	

			if(vertIdx == 0)
			{
				// Fix by Jean-Francois Yelle:
				GetInterface()->SetCommandPanelTaskMode(TASK_MODE_MODIFY);
				GetInterface()->SelectNode(__skinNode);
				GetInterface()->ForceCompleteRedraw(0);
			}
			
			Tab<INode*> bonesTab;
			Tab<float>  weightsTab;
			int numWeights = (int) weights.size();
			bonesTab.Append(0, 0, numWeights);
			weightsTab.Append(0, 0, numWeights);
			for(int i = 0; i < numWeights; ++i)
			{
				INode* bone = bones[i];
				float weight = weights[i];
				weightsTab.Append(1, &weight);
				bonesTab.Append(1, &bone);
			}
			skinImportData->AddWeights(__skinNode, vertIdx, bonesTab, weightsTab);
			__modifier->ReleaseInterface(I_SKINIMPORTDATA, skinImportData);
		}
		else if(__modifier->ClassID() == Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B))
		{
			IPhysiqueImport* physiqueImport = (IPhysiqueImport*) 
				(__modifier->GetInterface(I_PHYIMPORT));

			if(!__physiqueInitialized)
			{
				INode* rootBone = __FindRootBone();
				__CreateDummiesForPhysique(rootBone);
				physiqueImport->AttachRootNode(rootBone, GetInterface()->GetTime());
				physiqueImport->InitializePhysique(__skinNode, GetInterface()->GetTime());
				__skinNode->EvalWorldState(GetInterface()->GetTime());
				__physiqueInitialized = true;
			}

			IPhyContextImport* phyContextImport = (IPhyContextImport*)
				(physiqueImport->GetContextInterface(__skinNode));
			IPhyBlendedRigidVertexImport *rb_vtx = (IPhyBlendedRigidVertexImport*)
				(phyContextImport->SetVertexInterface(vertIdx, RIGID_BLENDED_TYPE));

			int numWeights = (int) weights.size();
			for(int i = 0; i < numWeights; i++)
			{
				float weight = weights[i];
				INode* bone = bones[i];
				rb_vtx->SetWeightedNode(bone, weight, i == 0);
			}
			rb_vtx->LockVertex(TRUE);

			phyContextImport->ReleaseVertexInterface(rb_vtx);
			physiqueImport->ReleaseContextInterface(phyContextImport);
			__modifier->ReleaseInterface(I_PHYIMPORT, physiqueImport);
		}
	}

	int GetVertNumWeights(int vertIdx) const
	{
		int numWeights = 0;
		if(__modifier->ClassID() == SKIN_CLASSID)
		{
			ISkin* skinIf = (ISkin*) __modifier->GetInterface(I_SKIN);
			ISkinContextData* skinContextData = skinIf->GetContextInterface(__skinNode);
			numWeights = skinContextData->GetNumAssignedBones(vertIdx);
			__modifier->ReleaseInterface(I_SKIN, skinIf);
		}
		else if(__modifier->ClassID() == Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B))
		{
			IPhysiqueExport *physiqueExport = (IPhysiqueExport *) __modifier->GetInterface(I_PHYEXPORT);
			IPhyContextExport *phyContextExport = (IPhyContextExport *) physiqueExport->GetContextInterface(__skinNode);
			phyContextExport->ConvertToRigid(TRUE);
			IPhyVertexExport* vi = phyContextExport->GetVertexInterface(vertIdx);
			int vtyp = vi->GetVertexType();
			if(vtyp == RIGID_BLENDED_TYPE)
			{
				IPhyBlendedRigidVertex* rb_vtx = (IPhyBlendedRigidVertex*) vi;
				numWeights = rb_vtx->GetNumberNodes();
			}
			else if(vtyp == RIGID_TYPE)
			{
				IPhyRigidVertex* r_vtx = (IPhyRigidVertex*) vi;
				numWeights = 1;
			}
			phyContextExport->ReleaseVertexInterface(vi);
			physiqueExport->ReleaseContextInterface(phyContextExport);
			__modifier->ReleaseInterface(I_PHYINTERFACE, physiqueExport);
		}
		return numWeights;
	}

	float GetVertWeight(int vertIdx, int vertBoneIdx) const
	{
		float weight = 0;
		if(__modifier->ClassID() == SKIN_CLASSID)
		{
			ISkin* skinIf = (ISkin*) __modifier->GetInterface(I_SKIN);
			ISkinContextData* skinContextData = skinIf->GetContextInterface(__skinNode);
			weight = skinContextData->GetBoneWeight(vertIdx, vertBoneIdx);
			__modifier->ReleaseInterface(I_SKIN, skinIf);
		}
		else if(__modifier->ClassID() == Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B))
		{
			IPhysiqueExport *physiqueExport = (IPhysiqueExport *)__modifier->GetInterface(I_PHYEXPORT);
			IPhyContextExport *phyContextExport = (IPhyContextExport *) physiqueExport->GetContextInterface(__skinNode);
			phyContextExport->ConvertToRigid(TRUE);
			IPhyVertexExport* vi = phyContextExport->GetVertexInterface(vertIdx);
			int vtyp = vi->GetVertexType();
			if(vtyp == RIGID_BLENDED_TYPE)
			{
				IPhyBlendedRigidVertex* rb_vtx = (IPhyBlendedRigidVertex*) vi;
				weight = rb_vtx->GetWeight(vertBoneIdx);
			}
			else if(vtyp == RIGID_TYPE)
			{
				IPhyRigidVertex* r_vtx = (IPhyRigidVertex*) vi;
				weight = 1;
			}
			phyContextExport->ReleaseVertexInterface(vi);
			physiqueExport->ReleaseContextInterface(phyContextExport);
			__modifier->ReleaseInterface(I_PHYINTERFACE, physiqueExport);
		}
		return weight;
	}

	INode* GetVertWeightBone(int vertIdx, int vertBoneIdx) const
	{
		INode* bone = NULL;
		if(__modifier->ClassID() == SKIN_CLASSID)
		{
			ISkin* skinIf = (ISkin*) __modifier->GetInterface(I_SKIN);
			ISkinContextData* skinContextData = skinIf->GetContextInterface(__skinNode);
			int boneID = skinContextData->GetAssignedBone(vertIdx, vertBoneIdx);
			bone = __bones[boneID];
			__modifier->ReleaseInterface(I_SKIN, skinIf);
		}
		else if(__modifier->ClassID() == Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B))
		{
			IPhysiqueExport *physiqueExport = (IPhysiqueExport *)__modifier->GetInterface(I_PHYEXPORT);
			IPhyContextExport *phyContextExport = (IPhyContextExport *) physiqueExport->GetContextInterface(__skinNode);
			phyContextExport->ConvertToRigid(TRUE);
			IPhyVertexExport* vi = phyContextExport->GetVertexInterface(vertIdx);
			int vtyp = vi->GetVertexType();
			if(vtyp == RIGID_BLENDED_TYPE)
			{
				IPhyBlendedRigidVertex* rb_vtx = (IPhyBlendedRigidVertex*) vi;
				bone = rb_vtx->GetNode(vertBoneIdx);
			}
			else if(vtyp == RIGID_TYPE)
			{
				IPhyRigidVertex* r_vtx = (IPhyRigidVertex*) vi;
				bone = r_vtx->GetNode();
			}
			phyContextExport->ReleaseVertexInterface(vi);
			physiqueExport->ReleaseContextInterface(phyContextExport);
			__modifier->ReleaseInterface(I_PHYINTERFACE, physiqueExport);
		}
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
