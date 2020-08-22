///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Quat.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 10, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

static Quaternion IdentityQuat()
{
	Quaternion q;
	q.v.x = 0;
	q.v.y = 0;
	q.v.z = 0;
	q.w = 1;
	return q;
}

// Provides a quaternion representation for orientation in 3D space using an angle in radians and a rotation axis.
// Rotations follow the left-hand-rule (like the "AngAxis" class in 3dsmax sdk).
static Quaternion NewQuat(const Vector& axis, Real angle)
{
	Quaternion q;
	if(abs(angle) < 0.00001)
	{
		q.v.x = 0;
		q.v.y = 0;
		q.v.z = 0;
		q.w = 1;
	}
	else
	{
		Real sin_a = sin(angle / 2);
		Real cos_a = cos(angle / 2);
		Vector v = sin_a * axis / Len(axis);
		q.v.x = v.x;
		q.v.y = v.y;
		q.v.z = v.z;
		q.w = cos_a;
	}
	return q;
}

static Real GetAngle(const Quaternion& q)
{
	Real cos_a = q.w;
	Real angle = acos(cos_a) * 2;
	return angle;
}

static Vector GetAxis(const Quaternion& q)
{
	Real cos_a = q.w;
	Real sin_a = sqrt(1 - cos_a * cos_a);
	if(abs(sin_a) < 0.00001)
	{
		return Vector(0, 0, 0);
	}
	else
	{
		LVector axis = q.v / sin_a;
		return Vector( (Real) axis.x, (Real) axis.y, (Real) axis.z);
	}
}

// Quaternion
#define TQUAT                   Quaternion
#define IDENTITY_QUAT           (IdentityQuat())

// Representation of quaternion as orientation to axis in 3D space 
// using an angle in radians and a rotation axisand 
#define NEW_QUAT(axis, angle)   (NewQuat(axis, angle))
#define GET_ANGLE(q)            ((float) GetAngle(q))
#define GET_AXIS(q)             (GetAxis(q))
