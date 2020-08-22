///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Anim.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

static void SetScnAnimRange(int startFrame, int endFrame)
{
	Interval rng = GetInterface()->GetAnimRange();
	if(endFrame < startFrame + 1)
		endFrame = startFrame + 1;
	rng.SetStart(startFrame * GetTicksPerFrame());
	rng.SetEnd(endFrame * GetTicksPerFrame());
	GetInterface()->SetAnimRange(rng);
}

static int GetScnStartFrame()
{
	Interval rng = GetInterface()->GetAnimRange();
	return rng.Start() / GetTicksPerFrame();
}

static int GetScnEndFrame()
{
	Interval rng = GetInterface()->GetAnimRange();
	return rng.End() / GetTicksPerFrame();
}

static int GetCurFrame()
{
	return (GetInterface()->GetTime()) / GetTicksPerFrame();
}

static void SetCurFrame(int t)
{
	GetInterface()->SetTime(t * GetTicksPerFrame());
}

static bool HasTMAnimation(INode* node)
{
	Control* cTM = node->GetTMController();
	if(cTM)
	{
		if(cTM->IsAnimated()) return true;
		Control* cPRS[] = {cTM->GetPositionController(), cTM->GetRotationController(), cTM->GetScaleController()};
		for(int i = 0; i < sizeof(cPRS) / sizeof(cPRS[0]); ++i)
			if(cPRS[i])
			{
				if(cPRS[i]->IsAnimated()) return true;
				Control* cXYZ[] = {cPRS[i]->GetXController(), cPRS[i]->GetYController(), cPRS[i]->GetZController()};
				for(int j = 0; j < sizeof(cXYZ) / sizeof(cXYZ[0]); ++j)
					if(cXYZ[j])
						if(cXYZ[j]->IsAnimated()) return true;
			}
	}	
	return false;
}

static void DeleteTMAnimation(INode* node)
{
	Control* cTM = node->GetTMController();
	if(cTM)
	{
		cTM->DeleteKeys(TRACK_DOALL);
		Control* cPRS[] = {cTM->GetPositionController(), cTM->GetRotationController(), cTM->GetScaleController()};
		for(int i = 0; i < sizeof(cPRS) / sizeof(cPRS[0]); ++i)
			if(cPRS[i])
			{
				cPRS[i]->DeleteKeys(TRACK_DOALL);
				Control* cXYZ[] = {cPRS[i]->GetXController(), cPRS[i]->GetYController(), cPRS[i]->GetZController()};
				for(int j = 0; j < sizeof(cXYZ) / sizeof(cXYZ[0]); ++j)
					if(cXYZ[j])
						cXYZ[j]->DeleteKeys(TRACK_DOALL);
			}
	}
}

static void AnimateTM(INode* node, const Matrix3& tm)
{
	Control* cTM = node->GetTMController();
	cTM->CreateLockKey(GetInterface()->GetTime(), 0);
	AnimateOn();
	node->SetNodeTM(GetInterface()->GetTime(), (Matrix3&) tm);
	AnimateOff();
}

// Defined in EditTriObj, in the 3dsMax samples
enum {ET_MASTER_CONTROL_REF = 0};
enum {ET_VERT_BASE_REF      = 1};

static bool HasMorphAnimation(INode* node)
{
	if(!IS_MESH_OBJECT(node))
	{
		return false;
	}
	TriObject* triObject = (TriObject*) (node->GetObjectRef());
	RefTargetHandle reference = triObject->GetReference(ET_MASTER_CONTROL_REF);
	if (reference == NULL || reference->ClassID().PartA() != MASTERPOINTCONT_CLASS_ID)
		return false;

	MasterPointControl* masterController = (MasterPointControl*) reference;
	return (masterController->IsAnimated() ? true : false);
}	

static void DeleteMorphAnimation(INode* node)
{
	if(!IS_MESH_OBJECT(node))
	{
		return;
	}
	TriObject* triObject = (TriObject*) (node->GetObjectRef());
	RefTargetHandle reference = triObject->GetReference(ET_MASTER_CONTROL_REF);
	if (reference == NULL || reference->ClassID().PartA() != MASTERPOINTCONT_CLASS_ID)
		return;

	MasterPointControl* masterController = (MasterPointControl*) reference;
	BitArray bitarr(masterController->GetNumSubControllers());
	bitarr.SetAll();
	masterController->DeleteControlSet(bitarr);
}

static void AnimateVertices(INode* node, const std::vector<Point3>& points)
{
	TriObject* triObject = (TriObject*) (node->GetObjectRef());
	RefTargetHandle reference = triObject->GetReference(ET_MASTER_CONTROL_REF);
	MasterPointControl* masterController = NULL;
	if (reference == NULL)
	{
		masterController = (MasterPointControl*) CreateMasterPointControl();
		triObject->AssignController(masterController, ET_MASTER_CONTROL_REF);
	}
	else if (reference->ClassID().PartA() == MASTERPOINTCONT_CLASS_ID)
	{
		masterController = (MasterPointControl*) reference;
	}
	else return;
	
	int numVertices = triObject->mesh.getNumVerts();
	int numSubControllers = masterController->GetNumSubControllers();
	if (numSubControllers < numVertices) 
	{
		masterController->SetNumSubControllers(numVertices);
	}

	AnimateOn();
	for(int i = 0; i < (int) points.size(); ++i)
	{
		Control* c = masterController->GetSubController(i);
		if(!c)
		{
			c = NewDefaultPoint3Controller();
			triObject->ReplaceReference(i + ET_VERT_BASE_REF, c, FALSE);
			masterController->SetSubController(i, c);
		}
		c->CreateLockKey(GetInterface()->GetTime(), 0);
		c->SetValue(GetInterface()->GetTime(), (void*) &points[i]);
	}
	AnimateOff();
}

// Start and end frames of the Active Time Segment
// It contains the values set in the Time Configuration dialog>Animation>Start Time and End Time 
// and displayed by the Active Time Segment option in the Time Output group of controls in the Render Scene Dialog.
#define GET_START_FRAME                            (GetScnStartFrame())
#define GET_END_FRAME                              (GetScnEndFrame())
#define SET_ANIMATION_RANGE(startFrame, endFrame)  SetScnAnimRange(startFrame, endFrame);

// Minimum value for a frame index
#define MIN_FRAME                            	(-447392)

// Maximum value for a frame index
#define MAX_FRAME                            	(447392)

// Current scene frame rate in frames-per-second. 
// It contains the corresponding value set in the Time Configuration dialog.
#define GET_FRAME_RATE                            (GetFrameRate())
#define SET_FRAME_RATE(rate)                      SetFrameRate(rate);

// System time resolution. 
// There are always 4800 ticks per second, this means that ticksPerFrame is dependent on the frames per second rate 
// (ticksPerFrame * frameRate == 4800)
#define GET_TICKS_PER_FRAME                       (GetTicksPerFrame())
#define SET_TICKS_PER_FRAME(ticks)                SetScnFrameRate(4800 / (ticks));

// Set current frame
#define SET_CURRENT_FRAME(t)				      SetCurFrame(t);

// Get current frame
#define GET_CURRENT_FRAME				          (GetCurFrame())

// Has an object animation for transformation matrix
#define HAS_TM_ANIMATION(obj)                     (HasTMAnimation(obj))

// Delete all animation keys for object's transformation matrix
#define DELETE_TM_ANIMATION(obj)                  DeleteTMAnimation(obj);

// Set transformation matrix at the specified frame
#define ANIMATE_TRANSFORM(obj, tm)                AnimateTM(obj, tm);

// Has an object animation for mesh's vertices
#define HAS_MORPH_ANIMATION(obj)				  (HasMorphAnimation(obj))

// Delete all animation keys for object's mesh vertices
#define DELETE_MORPH_ANIMATION(obj)               DeleteMorphAnimation(obj);

// Set position of mesh vertex at the specified frame
#define ANIMATE_VERTICES(obj, points)	 		 AnimateVertices(obj, points);

