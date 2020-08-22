///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxSdk_Matrix3.h
// Purpose:     Macroses to use the "maxsdk" C++ library when compiling plugins for 3ds max
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Internal functions
static Matrix3 RotationMatrix(Quat q)
{
	Matrix3 mat;
	q.MakeMatrix(mat);
	return mat;
}

static Quat GetRotationPart(const Matrix3& mat)
{
	AffineParts afn;
	decomp_affine(mat, &afn);
	return afn.q;
}

static float Determinant(const Matrix3& mat)
{
	float a = mat[0][0]; float b = mat[0][1]; float c = mat[0][2];
	float d = mat[1][0]; float e = mat[1][1]; float f = mat[1][2];
	float g = mat[2][0]; float h = mat[2][1]; float i = mat[2][2];
	float det = a * e * i - a * f * h - b * d * i + b * f * g + c * d * h - c * e * g;
	return det;
}

#define TMATRIX3          Matrix3
#define ZERO_MATRIX3      Matrix3(Point3(0, 0, 0), Point3(0, 0, 0), Point3(0, 0, 0), Point3(0, 0, 0))
#define IDENTITY_MATRIX3  Matrix3(1)
#define NEW_MATRIX3(row1_point3, row2_point3, row3_point3, row4_point3) \
	Matrix3(row1_point3, row2_point3, row3_point3, row4_point3)

// Check if this is an identity matrix
#define IS_IDENTITY(mat)		(mat.IsIdentity())

// Set row
#define SET_ROW0(mat, row0_point3) mat.SetRow(0, (row0_point3));
#define SET_ROW1(mat, row1_point3) mat.SetRow(1, (row1_point3));
#define SET_ROW2(mat, row2_point3) mat.SetRow(2, (row2_point3));
#define SET_ROW3(mat, row3_point3) mat.SetRow(3, (row3_point3));
#define SET_ROW(mat, rowIndex, row_point3) mat.SetRow(rowIndex, row_point3);

// Get row
#define GET_ROW0(mat)             ((mat).GetRow(0))
#define GET_ROW1(mat)             ((mat).GetRow(1))
#define GET_ROW2(mat)             ((mat).GetRow(2))
#define GET_ROW3(mat)             ((mat).GetRow(3))
#define GET_ROW(mat, rowIndex)    ((mat).GetRow(rowIndex))

// Inverse matrix
#define INVERSE(mat)              Inverse(mat)

// Multiply matrix by matrix
#define MULMATMAT(mat1, mat2)     ((mat1) * (mat2))

// Multiply matrix by vector
#define MULVECMAT(vec, mat)       ((vec) * (mat))

// Determinant
#define DETERMINANT(mat)		  Determinant(mat)

// Get vector which is a translation part of a specified transformation matrix
#define GET_TRANSLATION_PART(mat) ((mat).GetTrans())

// Get quaternion which is a rotation part of a specified transformation matrix
#define GET_ROTATION_PART(mat)    (GetRotationPart(mat))

// Create transformation matrix for translation by translation vector
#define TRANSLATION_MATRIX(pt)    (TransMatrix(pt))

// Create transformation matrix for rotation by quaternion
#define ROTATION_MATRIX(q)        (RotationMatrix(q))