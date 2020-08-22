///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Skin.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
function GetSupportedSkinTypes = 
(
	if (classOf(physique) == modifier and classOf(physiqueOps) == Interface) then
		return HASH("Physique modifier", "Skin modifier")
	else
		return HASH("Skin modifier")
)

function ConvertToSkinObj obj skinType =
(
	if(skinType == "Skin modifier") then
	(
		obj.parent = undefined
		setCommandPanelTaskMode mode:#modify
		select obj
		modPanel.addModToSelection (skin())	
	)
	else if(skinType == "Physique modifier") then
	(
		obj.parent = undefined
		addModifier obj (physique())
	)
)

function IsSkinObj obj = 
(
	if(obj.modifiers.count < 1) then
		return false
		
	local lastmd = obj.modifiers[obj.modifiers.count]
	return (classOf(lastmd) == Skin or classOf(lastmd) == Physique)
)

struct SkinData
(
	__modifier,
	__skinNode,
	__bones,
	__physiqueInitialized,
	
	function __ActivateSkin = 
	(
		if(classOf(__modifier) == Skin) then
		(
			if(getCommandPanelTaskMode() != HASHmodify) then
			(
				setCommandPanelTaskMode mode:HASHmodify
			)
			if(modPanel.getCurrentObject() != __modifier) then
			(
				modPanel.setCurrentObject (__modifier)
			)
		)
	),
	
    function __IsAncestor ancestor bon =
	(
		while (bon.parent != undefined) do
		(
			bon = bon.parent
			if (ancestor == bon) then
				return true
		)
		return false
	),
    
	function __FindCommonAncestor bone1 bone2 =
	(
		if bone1 == bone2 then
			return bone1

		if (__IsAncestor bone1 bone2) then
			return bone1

		if (__IsAncestor bone2 bone1) then
			return bone2

		return (__FindCommonAncestor (bone1.parent) (bone2.parent))
	),

	function __FindRootBone =
	(
		if __bones.count == 0 then
			return undefined

		local rootBone = __bones[1]
		for i in 1 to __bones.count do
		(
			rootBone = (__FindCommonAncestor rootBone __bones[i])
		)
		return rootBone
	),    
    
	function __CreateDummiesForPhysique rootBone =
	(
		local modelPrefix = ""
		local rootBoneName = rootBone.name
		local k = (findString rootBoneName "Bip")
		if k != undefined then
			modelPrefix = (substring rootBoneName 1 (k - 1))
		
		for i in 1 to __bones.count do
		(
			local bon = __bones[i]
			local parent = bon.parent
			if parent != undefined then
			(
				local createDummy = true
				local parentPos = parent.position
				local bonePos = bon.position
				local eps = length(bonePos - parentPos) / 100
				local numChildren = bon.children.count
				
				for j in 1 to numChildren do
					if length(bon.children[j].position - bonePos) > eps then
					(
						createDummy = false
						exit
					)
				
				if createDummy then
				(
					local dummyName = (uniqueName (modelPrefix + _T("Dummy00")))
					local dummyPos = bonePos + (bonePos - parentPos) / 2
					local d = (dummy name:dummyName position:dummyPos parent:bon boxsize:[0.5, 0.5, 0.5])
				)				
			)
		)
	),
	
	function InitSkinData obj =
	(
		local lastmd = obj.modifiers[obj.modifiers.count]
		if(classOf(lastmd) == Skin) then
		(
			__modifier = lastmd
			__skinNode = obj
			__bones = HASH()
			__ActivateSkin()
			for i in 1 to (skinOps.getNumberBones lastmd) do
			(
				local boneName = skinOps.getBoneName lastmd i 1
				local bone = getNodeByName (copy boneName)
				append __bones bone
			)
		)
		else if(classOf(lastmd) == Physique) then
		(
			__modifier = lastmd
			__skinNode = obj
			__bones = physiqueOps.getBones obj modifier:(__modifier)
			__physiqueInitialized = (__bones.count != 0)
		)
	),
	
	function GetSkinType = 
	(
		if(classOf(__modifier) == Skin) then
			return "Skin modifier"
		else if(classOf(__modifier) == Physique) then
			return "Physique modifier"
		else
			return 0
	),

	function AddBonesToSkin bones = 
	(
		if(classOf(__modifier) == Skin) then
		(
			__ActivateSkin()
			for i = 1 to bones.count do
			(
				local bon = bones[i]
				skinOps.addBone (__modifier) bon 0
				append (__bones) bon
			)
			completeRedraw()
		)
		else if(classOf(__modifier) == Physique) then
		(
			for i = 1 to bones.count do
			(
				local bon = bones[i]
				append __bones bon
			)
		)
	),

	function GetNumSkinBones = 
	(
		return __bones.count
	),

	function GetSkinBone boneID = 
	(
		return __bones[boneID + 1]
	), 

	function GetNumSkinVerts = 
	(
		local numVerts
		if(classOf(__modifier) == Skin) then
		(
			__ActivateSkin()
			numVerts = skinOps.getNumberVertices __modifier
		)
		else if(classOf(__modifier) == Physique) then
		(
			numVerts = physiqueOps.getVertexCount (__skinNode) modifier:(__modifier)
		)
		return numVerts
	),

	function SetVertWeights vertIdx bones weights =
	(
		if(classOf(__modifier) == Skin) then
		(
			__ActivateSkin()
			local boneIDs = HASH()
			for i = 1 to bones.count do
			(
				local id = -1
				for j = 1 to __bones.count do
					if(__bones[j] == bones[i]) then
						id = j
						break
				append boneIDs id
			)
			skinOps.replaceVertexWeights (__modifier) (vertIdx + 1) boneIDs weights
		)
		else if(classOf(__modifier) == Physique) then
		(
			if not(__physiqueInitialized) then
			(
				local rootBone = __FindRootBone()
				__CreateDummiesForPhysique rootBone
				physiqueOps.attachToNode (__skinNode) rootBone modifier:(__modifier)
				physiqueOps.initialize (__skinNode) rootBone modifier:(__modifier)
				completeRedraw()
				__physiqueInitialized = true
			)
				
			physiqueOps.setVertexBone (__skinNode) (vertIdx + 1) (bones[1]) weight:(weights[1]) clear:true
			for i = 2 to bones.count do
			(
				physiqueOps.setVertexBone (__skinNode) (vertIdx + 1) (bones[i]) weight:(weights[i]) modifier:(__modifier)
			)
			physiqueOps.lockVertex (__skinNode) (vertIdx + 1) modifier:(__modifier)
		)
	),

	function GetVertNumWeights vertIdx = 
	(
		local numWeights
		if(classOf(__modifier) == Skin) then
		(
			__ActivateSkin()
			numWeights = skinOps.getVertexWeightCount __modifier (vertIdx + 1)
		)
		else if(classOf(__modifier) == Physique) then
		(	
			numWeights = physiqueOps.getVertexBoneCount (__skinNode) (vertIdx + 1) modifier:(__modifier)
		)
		return numWeights
	),

	function GetVertWeight vertIdx vertBoneIdx = 
	(
		local weight
		if(classOf(__modifier) == Skin) then
		(
			__ActivateSkin()
			weight = skinOps.getVertexWeight __modifier (vertIdx + 1) (vertBoneIdx + 1)
		)
		else if(classOf(__modifier) == Physique) then
		(
			weight = physiqueOps.getVertexWeight (__skinNode) (vertIdx + 1) (vertBoneIdx + 1) modifier:(__modifier)
		)
		return weight
	),

	function GetVertWeightBone vertIdx vertBoneIdx =
	(
		local bone
		if(classOf(__modifier) == Skin) then
		(
			__ActivateSkin()
			local boneID = (skinOps.getVertexWeightBoneID (__modifier) (vertIdx + 1) (vertBoneIdx + 1))
			bone = __bones[boneID]
		)
		else if(classOf(__modifier) == Physique) then
		(
			bone = physiqueOps.getVertexBone (__skinNode) (vertIdx + 1) (vertBoneIdx + 1) modifier:(__modifier)
		)
		return bone
	)
)


// Get list of skin types supported by the 3D Editor
#define GET_SUPPORTED_SKIN_TYPES				(GetSupportedSkinTypes())

// Convert triangular mesh object to skin object
#define CONVERT_TO_SKIN_OBJECT(obj, skintype)	(ConvertToSkinObj (obj) (skintype))

// Check if the object specified is a skin object
#define IS_SKIN_OBJECT(obj)						(IsSkinObj(obj))

// Skin data
#define TSKIN							SkinData

// Create an instance of the SkinData struct to access to the skin properties
#define GET_SKIN(obj)					(local sd = SkinData(); sd.initSkinData(obj); sd)

// Get skin type
#define GET_SKIN_TYPE(sd)				(sd.GetSkinType())

// Adds a bone to the current system.
#define ADD_BONES_TO_SKIN(sd, bones)	(sd.AddBonesToSkin(bones))

// This method returns the actual number of bones in the system.
#define GET_NUM_SKIN_BONES(sd)			(sd.GetNumSkinBones())

// This method returns the INode of a particular bone. 
#define GET_SKIN_BONE(sd, boneID)		(sd.GetSkinBone(boneID))

// Returns the number of vertices for the object the Skin modifier is applied to. 
#define GET_NUM_SKIN_VERTS(sd)			(sd.GetNumSkinVerts())

// Sets the influence of the specified bones to the specified vertex.
#define SET_VERTEX_WEIGHTS(sd, vertIdx, bones, weights) \
	(sd.SetVertWeights (vertIdx) (bones) (weights))

// Returns the number of bones influencing the specified vertex. 
#define GET_VERTEX_NUM_WEIGHTS(sd, vertIdx) \
	(sd.GetVertNumWeights(vertIdx))

// Returns the influence of the Nth bone affecting the specified vertex. 
#define GET_VERTEX_WEIGHT(sd, vertIdx, vertBoneIdx) \
	(sd.GetVertWeight (vertIdx) (vertBoneIdx))

// Returns the system bone index of the Nth bone affecting the specified vertex. 
#define GET_VERTEX_WEIGHT_BONE(sd, vertIdx, vertBoneIdx) \
	(sd.GetVertWeightBone (vertIdx) (vertBoneIdx))

