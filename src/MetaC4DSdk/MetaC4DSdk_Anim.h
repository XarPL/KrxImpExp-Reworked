///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Anim.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     August 5, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

static void SetScnAnimRange(int startFrame, int endFrame)
{
	if(endFrame < startFrame + 1)
		endFrame = startFrame + 1;
	LONG fps = GetActiveDocument()->GetFps();
	BaseTime tmin(startFrame, fps);
	BaseTime tmax(endFrame, fps);
	GetActiveDocument()->SetMinTime(tmin);
	GetActiveDocument()->SetMaxTime(tmax);
	GetActiveDocument()->SetLoopMinTime(tmin);
	GetActiveDocument()->SetLoopMaxTime(tmax);
}

static int GetScnStartFrame()
{
	LONG fps = GetActiveDocument()->GetFps();
	BaseTime tmin = GetActiveDocument()->GetMinTime();
	return tmin.GetFrame(fps);
}

static int GetScnEndFrame()
{
	LONG fps = GetActiveDocument()->GetFps();
	BaseTime tmax = GetActiveDocument()->GetMaxTime();
	return tmax.GetFrame(fps);
}

static int GetCurFrame()
{
	LONG fps = GetActiveDocument()->GetFps();
	BaseTime tcur = GetActiveDocument()->GetTime();
	return tcur.GetFrame(fps);
}

static void SetCurFrame(int t)
{
	BaseDocument* doc = GetActiveDocument();
	LONG fps = doc->GetFps();
	BaseTime tcur(Real(t) / fps);
	if(tcur != GetActiveDocument()->GetTime())
	{
		doc->SetTime(tcur);

#		if USE_BASE_DOCUMENT_EXECUTE_PASSES_BUILDFLAGS
			doc->ExecutePasses(NULL, TRUE, TRUE, TRUE, BUILDFLAGS_0);
#		elif USE_BASE_DOCUMENT_EXECUTE_PASSES
			doc->ExecutePasses(NULL, TRUE, TRUE, TRUE);
#		else
			doc->AnimateDocument(NULL, TRUE, TRUE);
#		endif

		DrawViews(DRAWFLAGS_NO_THREAD);
	}
}

static int GetScnFrameRate()
{
	LONG fps = GetActiveDocument()->GetFps();
	return fps;
}

static void SetScnFrameRate(int rate)
{
	GetActiveDocument()->SetFps(rate);
}

static bool HasTMAnimation(BaseObject* obj)
{
#	if USE_CTRACK
	{
		CTrack* track = obj->GetFirstCTrack();
		while(track)
		{
			DescID descid = track->GetDescriptionID();
			if(descid.GetDepth() >= 1)
			{
				DescLevel lvl = descid[0];
				if(lvl.id == ID_BASEOBJECT_REL_POSITION || lvl.id == ID_BASEOBJECT_REL_ROTATION || lvl.id == ID_BASEOBJECT_REL_SCALE)
				{
					return true;
				}
			}
			track = track->GetNext();
		}
		return false;
	}
#	else // !USE_CTRACK
	{
		BaseTrack* track = obj->GetFirstTrack();
		while(track)
		{
			DescID descid = track->GetDescriptionID();
			if(descid.GetDepth() >= 1)
			{
				DescLevel lvl = descid[0];
				if(lvl.id == ID_BASEOBJECT_REL_POSITION || lvl.id == ID_BASEOBJECT_REL_ROTATION || lvl.id == ID_BASEOBJECT_REL_SCALE)
				{
					return true;
				}
			}
			track = track->GetNext();
		}
		return false;
	}
#	endif // USE_CTRACK
}

static void DeleteTMAnimation(BaseObject* obj)
{
#	if USE_CTRACK
	{
		CTrack* track = obj->GetFirstCTrack();
		while(track)
		{
			CTrack* nextTrack = track->GetNext();
			DescID descid = track->GetDescriptionID();
			if(descid.GetDepth() >= 1)
			{
				DescLevel lvl = descid[0];
				if(lvl.id == ID_BASEOBJECT_REL_POSITION || lvl.id == ID_BASEOBJECT_REL_ROTATION || lvl.id == ID_BASEOBJECT_REL_SCALE)
				{
					CTrack::Free(track);
				}
			}
			track = nextTrack;
		}
	}
#	else // !USE_CTRACK
	{
		BaseTrack* track = obj->GetFirstTrack();
		while(track)
		{
			BaseTrack* nextTrack = track->GetNext();
			DescID descid = track->GetDescriptionID();
			if(descid.GetDepth() >= 1)
			{
				DescLevel lvl = descid[0];
				if(lvl.id == ID_BASEOBJECT_REL_POSITION || lvl.id == ID_BASEOBJECT_REL_ROTATION || lvl.id == ID_BASEOBJECT_REL_SCALE)
				{
					BaseTrack::Free(track);
				}
			}
			track = nextTrack;
		}
	}
#	endif // USE_CTRACK
}

static void AnimateTM(BaseObject* obj, const Matrix& transform)
{
	BaseDocument* doc = obj->GetDocument();
	BaseTime time = doc->GetTime();
	BaseTime timeEps = BaseTime(1, doc->GetFps());
	BaseTime prevTime = time - timeEps;

	SetTransform(obj, transform);
	Matrix ml = obj->GetMl();
	Vector pos = ml.off;
	Vector rot = MatrixToHPB(ml);
	Vector scale = Vector(Len(ml.v1), Len(ml.v2), Len(ml.v3));

	const int numTransformTracks = 9;
	Real transformParts[numTransformTracks] = {pos.x, pos.y, pos.z, rot.x, rot.y, rot.z, scale.x, scale.y, scale.z};
	
	DescID transformDescIDs[numTransformTracks] = {
		DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, Obase), DescLevel(VECTOR_X, DTYPE_REAL, DTYPE_VECTOR)),
		DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, Obase), DescLevel(VECTOR_Y, DTYPE_REAL, DTYPE_VECTOR)),
		DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, Obase), DescLevel(VECTOR_Z, DTYPE_REAL, DTYPE_VECTOR)),
		DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, Obase), DescLevel(VECTOR_X, DTYPE_REAL, DTYPE_VECTOR)),
		DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, Obase), DescLevel(VECTOR_Y, DTYPE_REAL, DTYPE_VECTOR)),
		DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, Obase), DescLevel(VECTOR_Z, DTYPE_REAL, DTYPE_VECTOR)),
		DescID(DescLevel(ID_BASEOBJECT_REL_SCALE,    DTYPE_VECTOR, Obase), DescLevel(VECTOR_X, DTYPE_REAL, DTYPE_VECTOR)),
		DescID(DescLevel(ID_BASEOBJECT_REL_SCALE,    DTYPE_VECTOR, Obase), DescLevel(VECTOR_Y, DTYPE_REAL, DTYPE_VECTOR)),
		DescID(DescLevel(ID_BASEOBJECT_REL_SCALE,    DTYPE_VECTOR, Obase), DescLevel(VECTOR_Z, DTYPE_REAL, DTYPE_VECTOR))};

#	if USE_CTRACK
	{
		CTrack* transformTracks[numTransformTracks] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
		CTrack* track = obj->GetFirstCTrack();
		while(track)
		{
			DescID descid = track->GetDescriptionID();
			for(int j = 0; j < numTransformTracks; ++j)
			{
				if(descid == transformDescIDs[j])
				{
					transformTracks[j] = track;
					break;
				}
			}
			track = track->GetNext();
		}

		// for each transformation track ...
		for(int j = 0; j < numTransformTracks; ++j)
		{
			track = transformTracks[j];
			
			// if the track is not found we should to create a new one
			if(!track)
			{
				track = CTrack::Alloc(obj, transformDescIDs[j]);
				obj->InsertTrackSorted(track);
				transformTracks[j] = track;
			}

			// getting a value for the new key 
			Real val = transformParts[j];

			// inserting a new key and getting previous key's value
			Real prevval = val;
			CCurve* curve = track->GetCurve();
			CKey* key = curve->FindKey(time);
			CKey* prevkey = curve->FindKey(time, NULL, FINDANIM_LEFT);
			if(prevkey)
			{
				prevval = prevkey->GetValue();
			}
			if(!key)
			{
				key = curve->AddKey(time);
				track->FillKey(obj->GetDocument(), obj, key);
				key->SetInterpolation(curve, CINTERPOLATION_LINEAR);
			}

			// recalculating the key's value for smooth rotation
			if(3 <= j && j < 6) // rotation
			{
				Real val1 = val + pi2 * floor((prevval - val) / pi2);
				Real val2 = val1 + pi2;
				if(prevval - val1 < val2 - prevval)
					val = val1;
				else
					val = val2;
			}

			// setting key's value
			key->SetValue(curve, val);
		}
	}
#	else // !USE_CTRACK
	{
		BaseTrack* transformTracks[numTransformTracks] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
		BaseTrack* track = obj->GetFirstTrack();
		while(track)
		{
			DescID descid = track->GetDescriptionID();
			for(int j = 0; j < numTransformTracks; ++j)
			{
				if(descid == transformDescIDs[j])
				{
					transformTracks[j] = track;
					break;
				}
			}
			track = track->GetNext();
		}

		// for each transformation track ...
		for(int j = 0; j < numTransformTracks; ++j)
		{
			track = transformTracks[j];
			
			// if the track is not found we should to create a new one
			if(!track)
			{
				track = BaseTrack::Alloc(Svalue);
				track->SetDescriptionId(obj, transformDescIDs[j]);
				obj->InsertTrack(track);
				transformTracks[j] = track;
			}

			// getting a value for the new key 
			Real val = transformParts[j];

			// inserting a new key and getting previous key's value
			Real prevval = val;
			BaseSequence* seq = track->GetFirstSequence();
			while(seq)
			{
				if(seq->GetT1() <= time && time <= seq->GetT2())
				{
					break;
				}
				if(seq->GetT2() < time && time <= seq->GetT3())
				{
					seq->SetT3(prevTime);
				}
				if(seq->GetT2() == prevTime)
				{
					seq->SetT2(time);
					seq->SetT3(time);
					break;
				}
				seq = seq->GetNext();
			}
			if(!seq)
			{
				seq = BaseSequence::Alloc(Svalue);
				seq->SetT1(time);
				seq->SetT2(time);
				seq->SetT3(time);
				track->InsertSequence(seq);
			}
			BaseKey* key = seq->GetFirstKey();
			while(key)
			{
				if(key->GetTime() < time)
				{
					prevval = GetKeyValue(key)->value;
				}
				if(key->GetTime() == time)
				{
					break;
				}
				key = key->GetNext();
			}
			if(!key)
			{
				key = BaseKey::Alloc(Svalue);
				key->SetTime(time);
				seq->InsertKey(key);
			}
			key->FillKey();

			// recalculating the key's value for smooth rotation
			if(3 <= j && j < 6) // rotation
			{
				Real val1 = val + pi2 * floor((prevval - val) / pi2);
				Real val2 = val1 + pi2;
				if(prevval - val1 < val2 - prevval)
					val = val1;
				else
					val = val2;
			}

			// setting key's value
			GetKeyValue(key)->value = val;
		}
	}
#	endif // USE_CTRACK
}

static bool HasMorphAnimation(BaseObject* obj)
{
#	if USE_CTRACK
	{
		CTrack* track = obj->GetFirstCTrack();
		while(track)
		{
			if(track->GetType() == CTpla)
				return true;
			track = track->GetNext();
		}
		return false;
	}
#	else // !USE_CTRACK
	{
		BaseTrack* track = obj->GetFirstTrack();
		while(track)
		{
			if(track->GetType() == Spla)
				return true;
			track = track->GetNext();
		}
		return false;
	}
#	endif // USE_CTRACK
}	

static void DeleteMorphAnimation(BaseObject* obj)
{
#	if USE_CTRACK
	{
		CTrack* track = obj->GetFirstCTrack();
		while(track)
		{
			CTrack* nextTrack = track->GetNext();
			if(track->GetType() == CTpla)
			{
				CTrack::Free(track);
			}
			track = nextTrack;
		}
	}
#	else // !USE_CTRACK
	{
		BaseTrack* track = obj->GetFirstTrack();
		while(track)
		{
			BaseTrack* nextTrack = track->GetNext();
			if(track->GetType() == Spla)
			{
				BaseTrack::Free(track);
			}
			track = nextTrack;
		}
	}
#	endif // USE_CTRACK
}

static void AnimateVertices(BaseObject* obj, const std::vector<Vector>& points)
{
	if(obj->GetType() != Opolygon)
		return;
	int pointCount = ToPoly(obj)->GetPointCount();
		
	BaseDocument* doc = obj->GetDocument();
	BaseTime time = doc->GetTime();
	BaseTime timeEps = BaseTime(1, doc->GetFps());
	BaseTime prevTime = time - timeEps;

#	if USE_CTRACK
	{
		// finding PLA-track
		CTrack* track = obj->GetFirstCTrack();
		while(track)
		{
			if(track->GetType() == CTpla)
				break;
			track = track->GetNext();
		}

		// allocating a new PLA track if it was not found
		if(!track)
		{
			track = CTrack::Alloc(obj, DescLevel(CTpla, CTpla, 0));
			obj->InsertTrackSorted(track);
		}
		
		// inserting a new key
		CCurve* curve = track->GetCurve();
		CKey* key = curve->FindKey(time);
		if(!key)
		{
			key = curve->AddKey(time);
			track->FillKey(obj->GetDocument(), obj, key);
			key->SetInterpolation(curve, CINTERPOLATION_LINEAR);
		}
		const GeData& dat = key->GetGeData();
		BaseContainer* container = dat.GetContainer();
		PLAData* pla = (PLAData*) container->GetCustomDataType(CK_PLA_DATA, CUSTOMDATATYPE_PLA);
		if(pla)
		{
			Vector* dest = NULL;
#           if USE_PLA_DATA_POINT_TAG
			{
				PointTag* pttag = NULL;
				TangentTag* tgtag = NULL;
				pla->GetVariableTags(pttag, tgtag);
				dest = pttag->GetDataAddressW();
			}
#			else // !USE_PLA_DATA_POINT_TAG
			{
				VariableTag* pttag = NULL;
				VariableTag* tgtag = NULL;
				pla->GetVariableTags(pttag, tgtag);
				dest = (Vector*) pttag->GetDataAddressW();
			}
#			endif // USE_PLA_DATA_POINT_TAG

			for(size_t i = 0; i < points.size(); ++i)
				dest[i] = points[i];
		}
	}
#	else // !USE_CTRACK
	{
		// finding PLA-track
		BaseTrack* track = obj->GetFirstTrack();
		while(track)
		{
			if(track->GetType() == Spla)
				break;
			track = track->GetNext();
		}

		// allocating a new PLA track if it was not found
		if(!track)
		{
			track = BaseTrack::Alloc(Spla);
			track->SetDescriptionId(obj, DescID());
			obj->InsertTrack(track);
		}
		
		// inserting a new key
		BaseSequence* seq = track->GetFirstSequence();
		while(seq)
		{
			if(seq->GetT1() <= time && time <= seq->GetT2())
			{
				break;
			}
			if(seq->GetT2() < time && time <= seq->GetT3())
			{
				seq->SetT3(prevTime);
			}
			if(seq->GetT2() == prevTime)
			{
				seq->SetT2(time);
				seq->SetT3(time);
				break;
			}
			seq = seq->GetNext();
		}
		if(!seq)
		{
			seq = BaseSequence::Alloc(Spla);
			seq->SetT1(time);
			seq->SetT2(time);
			seq->SetT3(time);
			track->InsertSequence(seq);
		}
		PLAKey* key = (PLAKey*) seq->FindKey(time);
		if(!key)
		{
			key = PLAKey::Alloc();
			key->SetTime(time);
			seq->InsertKey(key);
			key->FillKey();
		}
		VariableTag* ptag = key->GetPointTag();
		if(ptag && ptag->GetDataCount() == pointCount)
		{
			Vector* dest = (Vector*) ptag->GetDataAddress();	
			for(size_t i = 0; i < points.size(); ++i)
				dest[i] = points[i];
		}
	}
#	endif // USE_CTRACK
}

// Start and end frames of the Active Time Segment
// It contains the values set in the Time Configuration dialog>Animation>Start Time and End Time 
// and displayed by the Active Time Segment option in the Time Output group of controls in the Render Scene Dialog.
#define GET_START_FRAME                            (GetScnStartFrame())
#define GET_END_FRAME                              (GetScnEndFrame())
#define SET_ANIMATION_RANGE(startFrame, endFrame)  SetScnAnimRange(startFrame, endFrame);

// Minimum value for a frame index
#define MIN_FRAME                            	(-300000)

// Maximum value for a frame index
#define MAX_FRAME                            	(300000)

// Current scene frame rate in frames-per-second. 
// It contains the corresponding value set in the Time Configuration dialog.
#define GET_FRAME_RATE                            (GetScnFrameRate())
#define SET_FRAME_RATE(rate)                      SetScnFrameRate(rate);

// System time resolution. 
// There are always 4800 ticks per second, this means that ticksPerFrame is dependent on the frames per second rate 
// (ticksPerFrame * frameRate == 4800)
#define GET_TICKS_PER_FRAME                       (4800 / GetScnFrameRate())
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
#define ANIMATE_VERTICES(obj, points)			  AnimateVertices(obj, points);

