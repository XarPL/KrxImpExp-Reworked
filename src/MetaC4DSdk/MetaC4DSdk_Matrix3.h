///////////////////////////////////////////////////////////////////////////////
// Name:        MetaC4DSdk_Matrix3.h
// Purpose:     Macroses to use the Cinema4D C++ SDK
// Author:      Vitaly Baranov
// Created:     July 8, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// My own implementation of some matrix operation 
// to make the standard Cinema4D's Matrix class more likely to the "Matrix3" class in the 3ds max sdk.
// In the 3dsmax sdk a 3D transformation matrix has size 4x4, however only 12 components are used.
// Any matrix follows the template:
// m00 m01 m02 0
// m10 m11 m12 0
// m20 m21 m22 0
// m30 m31 m32 1
// The first 9 componenets represents rotation and scale transformations,
// and the rest three components (m30, m31, m32) represents translation.

// Creates a matrix by rows
inline void SwapAxes(Matrix& mat)
{
	Vector& x = mat.v1;
	Vector& y = mat.v2;
	Vector& z = mat.v3;
	SWAP_AXES
}

inline Vector GetRow0(const Matrix& mat)
{
	Matrix mat2 = mat;
	SwapAxes(mat2);
	return mat2.v1;
}

inline Vector GetRow1(const Matrix& mat)
{
	Matrix mat2 = mat;
	SwapAxes(mat2);
	return mat2.v2;
}

inline Vector GetRow2(const Matrix& mat)
{
	Matrix mat2 = mat;
	SwapAxes(mat2);
	return mat2.v3;
}

inline Vector GetRow3(const Matrix& mat)
{
	return mat.off;
}

inline Vector GetRow(const Matrix& mat, int rowIndex)
{
	switch(rowIndex)
	{
		case 0:  return GetRow0(mat);
		case 1:  return GetRow1(mat);
		case 2:  return GetRow2(mat);
		default: return GetRow3(mat);
	}
}

inline void SetRow0(Matrix& mat, const Vector& row0)
{
	SwapAxes(mat);
	mat.v1 = row0;
	SwapAxes(mat);
}

inline void SetRow1(Matrix& mat, const Vector& row1)
{
	SwapAxes(mat);
	mat.v2 = row1;
	SwapAxes(mat);
}

inline void SetRow2(Matrix& mat, const Vector& row2)
{
	SwapAxes(mat);
	mat.v3 = row2;
	SwapAxes(mat);
}

inline void SetRow3(Matrix& mat, const Vector& row3)
{
	mat.off = row3;
}

inline void SetRow(Matrix& mat, int rowIndex, const Vector& v)
{
	switch(rowIndex)
	{
		case 0:  SetRow0(mat, v); break;
		case 1:  SetRow1(mat, v); break;
		case 2:  SetRow2(mat, v); break;
		default: SetRow3(mat, v); break;
	}
}

inline Matrix NewMatrix(const Vector& row0, const Vector& row1, const Vector& row2, const Vector& row3)
{
	Matrix mat(row3, row0, row1, row2);
	SwapAxes(mat);
	return mat;
}

static const Matrix& ZeroMatrix()
{
	static const Matrix s(Vector(0, 0, 0), Vector(0, 0, 0), Vector(0, 0, 0), Vector(0, 0, 0));
	return s;
}

static const Matrix& IdentityMatrix()
{
	static const Matrix s(Vector(0, 0, 0), Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 1));
	return s;
}

static Matrix MultiplyMatrixMatrix(const Matrix& mat1, const Matrix& mat2)
{
	return mat2 * mat1;
}

static Vector MultiplyVectorMatrix(const Vector& vec, const Matrix& mat)
{
	return mat * vec;
}

static Matrix InverseMatrix(const Matrix& mat)
{
	return !mat;
}

static Vector GetTranslationPart(const Matrix& mat)
{
	return mat.off;
}

static Matrix TranslationMatrix(const Vector& vec)
{
	return MatrixMove(vec);
}

static Matrix RotationMatrix(const Quaternion& q)
{
	Quaternion q2 = q;
	q2.v = -q2.v;
	LMatrix lm = q2.GetMatrix();
	Matrix mat;
	mat.off.x = (Real) lm.off.x;
	mat.off.y = (Real) lm.off.y;
	mat.off.z = (Real) lm.off.z;
	mat.v1.x  = (Real) lm.v1.x;
	mat.v1.y  = (Real) lm.v1.y;
	mat.v1.z  = (Real) lm.v1.z;
	mat.v2.x  = (Real) lm.v2.x;
	mat.v2.y  = (Real) lm.v2.y;
	mat.v2.z  = (Real) lm.v2.z;
	mat.v3.x  = (Real) lm.v3.x;
	mat.v3.y  = (Real) lm.v3.y;
	mat.v3.z  = (Real) lm.v3.z;
	return mat;
}

static Quaternion GetRotationPart(const Matrix& mat)
{
	LMatrix lm;
	lm.off.x = mat.off.x;
	lm.off.y = mat.off.y;
	lm.off.z = mat.off.z;
	lm.v1.x  = mat.v1.x;
	lm.v1.y  = mat.v1.y;
	lm.v1.z  = mat.v1.z;
	lm.v2.x  = mat.v2.x;
	lm.v2.y  = mat.v2.y;
	lm.v2.z  = mat.v2.z;
	lm.v3.x  = mat.v3.x;
	lm.v3.y  = mat.v3.y;
	lm.v3.z  = mat.v3.z;
	Quaternion q;
	q.SetMatrix(lm);
	q.v = -q.v;
	return q;
}

static float Determinant(const Matrix& mat)
{
	Real a = mat.v1.x; Real b = mat.v1.y; Real c = mat.v1.z;
	Real d = mat.v2.x; Real e = mat.v2.y; Real f = mat.v2.z;
	Real g = mat.v3.x; Real h = mat.v3.y; Real i = mat.v3.z;
	Real det = a * e * i - a * f * h - b * d * i + b * f * g + c * d * h - c * e * g;
	return (float) det;
}


// Useful macroses
#define TMATRIX3          Matrix
#define ZERO_MATRIX3      ZeroMatrix()
#define IDENTITY_MATRIX3  IdentityMatrix()
#define NEW_MATRIX3(row0_point3, row1_point3, row2_point3, row3_point3) \
	NewMatrix(row0_point3, row1_point3, row2_point3, row3_point3)

// Check if this is an identity matrix
#define IS_IDENTITY(mat)	(mat == IdentityMatrix())

// Set row
#define SET_ROW0(mat, row0_point3) SetRow0(mat, row0_point3);
#define SET_ROW1(mat, row1_point3) SetRow1(mat, row1_point3);
#define SET_ROW2(mat, row2_point3) SetRow2(mat, row2_point3);
#define SET_ROW3(mat, row3_point3) SetRow3(mat, row3_point3);
#define SET_ROW(mat, rowIndex, row_point3) SetRow(mat, rowIndex, row_point3);

// Get row
#define GET_ROW0(mat)             (GetRow0(mat))
#define GET_ROW1(mat)             (GetRow1(mat))
#define GET_ROW2(mat)             (GetRow2(mat))
#define GET_ROW3(mat)             (GetRow3(mat))
#define GET_ROW(mat, rowIndex)    (GetRow(mat, rowIndex))

// Inverse matrix
#define INVERSE(mat)              (InverseMatrix(mat))

// Multiply matrix by matrix
#define MULMATMAT(mat1, mat2)     (MultiplyMatrixMatrix(mat1, mat2))

// Multiply matrix by vector
#define MULVECMAT(vec, mat)       (MultiplyVectorMatrix(vec, mat))

// Determinant
#define DETERMINANT(mat)		  (Determinant(mat))

// Get vector which is a translation part of a specified transformation matrix
#define GET_TRANSLATION_PART(mat) (GetTranslationPart(mat))

// Get quaternion which is a rotation part of a specified transformation matrix
#define GET_ROTATION_PART(mat)    (GetRotationPart(mat))

// Create transformation matrix for translation by translation vector
#define TRANSLATION_MATRIX(pt)    (TranslationMatrix(pt))

// Create transformation matrix for rotation by quaternion
#define ROTATION_MATRIX(q)        (RotationMatrix(q))