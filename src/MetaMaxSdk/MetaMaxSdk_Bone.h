///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Bone.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     April 2, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal function
static INode* NewBoneObj(const std::tstring& name, INode* parentBone, const Point3& boundBoxMinPoint, const Point3& boundBoxMaxPoint, const std::tstring& skinType)
{
	TriObject* tri = CreateNewTriObject();
	Mesh* msh = &(tri->mesh);
	INode* node = GetInterface()->CreateObjectNode(tri);
	node->SetName((LPTSTR) (name.c_str()));
	if(parentBone)
		parentBone->AttachChild(node, 1);
	
	float minx = boundBoxMinPoint.x;
	float miny = boundBoxMinPoint.y;
	float minz = boundBoxMinPoint.z;
	float maxx = boundBoxMaxPoint.x;
	float maxy = boundBoxMaxPoint.y;
	float maxz = boundBoxMaxPoint.z;

	msh->setNumVerts(8);
	msh->setVert(0, Point3(minx, miny, minz));
	msh->setVert(1, Point3(maxx, miny, minz));
	msh->setVert(2, Point3(minx, maxy, minz));
	msh->setVert(3, Point3(maxx, maxy, minz));
	msh->setVert(4, Point3(minx, miny, maxz));
	msh->setVert(5, Point3(maxx, miny, maxz));
	msh->setVert(6, Point3(minx, maxy, maxz));
	msh->setVert(7, Point3(maxx, maxy, maxz));
	
	msh->setNumFaces(12);
	msh->faces[0].setVerts(0, 2, 3);
	msh->faces[1].setVerts(3, 1, 0);
	msh->faces[2].setVerts(4, 5, 7);
	msh->faces[3].setVerts(7, 6, 4);
	msh->faces[4].setVerts(0, 1, 5);
	msh->faces[5].setVerts(5, 4, 0);
	msh->faces[6].setVerts(1, 3, 7);
	msh->faces[7].setVerts(7, 5, 1);
	msh->faces[8].setVerts(3, 2, 6);
	msh->faces[9].setVerts(6, 7, 3);
	msh->faces[10].setVerts(2, 0, 4);
	msh->faces[11].setVerts(4, 6, 2);
	
	for(int i = 0; i < msh->getNumFaces(); ++i)
		for(int j = 0; j < 3; ++j)
			msh->faces[i].setEdgeVis(j, true);
	
	msh->buildNormals();
	return node;
}

// Create object which will be used as bone;
// If parentBone == ROOT_OBJECT, then this function will create a bone without a parent
#define NEW_BONE_OBJECT(name, parentBone, boundBoxMinPoint, boundBoxMaxPoint, skinType)	(NewBoneObj(name, parentBone, boundBoxMinPoint, boundBoxMaxPoint, skinType))
