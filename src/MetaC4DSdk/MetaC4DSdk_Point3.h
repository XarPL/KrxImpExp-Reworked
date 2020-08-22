///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Point3.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 8, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
inline void SwapAxes(Vector& vec)
{
	Real& x = vec.x;
	Real& y = vec.y;
	Real& z = vec.z;
	SWAP_AXES
}

inline float GetX(const Vector& vec)
{
	Vector vec2 = vec;
	SwapAxes(vec2);
	return (float) vec2.x;
}

inline float GetY(const Vector& vec)
{
	Vector vec2 = vec;
	SwapAxes(vec2);
	return (float) vec2.y;
}

inline float GetZ(const Vector& vec)
{
	Vector vec2 = vec;
	SwapAxes(vec2);
	return (float) vec2.z;
}

inline void SetX(Vector& vec, float x)
{
	SwapAxes(vec);
	vec.x = x;
	SwapAxes(vec);
}

inline void SetY(Vector& vec, float y)
{
	SwapAxes(vec);
	vec.y = y;
	SwapAxes(vec);
}

inline void SetZ(Vector& vec, float z)
{
	SwapAxes(vec);
	vec.z = z;
	SwapAxes(vec);
}

inline Vector NewVector(float x, float y, float z)
{
	Vector vec(x, y, z);
	SwapAxes(vec);
	return vec;
}

static const Vector& ZeroVector()
{
	static const Vector s(0, 0, 0);
	return s;
}

#define TPOINT3                 Vector
#define ZERO_POINT3				ZeroVector()
#define NEW_POINT3(x, y, z)     NewVector(x, y, z)

// Set point coordinates (y and z components must be exchanged)
#define SET_X(pt, val)          SetX(pt, x)
#define SET_Y(pt, val)          SetY(pt, y)
#define SET_Z(pt, val)          SetZ(pt, z)

// Get point coordinates (y and z components must be exchanged)
#define GET_X(pt)               (GetX(pt))
#define GET_Y(pt)               (GetY(pt))
#define GET_Z(pt)              	(GetZ(pt))

// Vector's length
#define VECLEN(pt)		 		((float) Len(pt))

// Dot production
#define DOTPROD(pt1, pt2)		((float) ((pt1) * (pt2)))