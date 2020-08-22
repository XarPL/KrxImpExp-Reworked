///////////////////////////////////////////////////////////////////////////////
// Name:        MetaMaxScript_Matrix3.h
// Purpose:     Macroses to build plugins for 3ds max in MAXScript language
//              with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     January 14, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// Helper function
function determinant mat =
(
	a = mat[1][1]; b = mat[1][2]; c = mat[1][3]
	d = mat[2][1]; e = mat[2][2]; f = mat[2][3]
	g = mat[3][1]; h = mat[3][2]; i = mat[3][3]
	det = a * e * i - a * f * h - b * d * i + b * f * g + c * d * h - c * e * g
	return det
)

// 4x3 3D transformation matrix
#define TMATRIX3                Matrix3
#define ZERO_MATRIX3			(Matrix3 0)
#define IDENTITY_MATRIX3		(Matrix3 1)
#define NEW_MATRIX3(row1_point3, row2_point3, row3_point3, row4_point3) \
	(Matrix3 (row1_point3) (row2_point3) (row3_point3) (row4_point3))

// Check if this is an identity matrix
#define IS_IDENTITY(mat)		(isIdentity (mat))

// Set row
#define SET_ROW0(mat, row0_point3)          mat.row1 = (row0_point3);
#define SET_ROW1(mat, row1_point3)          mat.row2 = (row1_point3);
#define SET_ROW2(mat, row2_point3)          mat.row3 = (row2_point3);
#define SET_ROW3(mat, row3_point3)          mat.row4 = (row3_point3);
#define SET_ROW(mat, rowIndex, row_point3)  mat[rowIndex + 1] = (row_point3);

// Get row
#define GET_ROW0(mat)             ((mat).row1)
#define GET_ROW1(mat)             ((mat).row2)
#define GET_ROW2(mat)             ((mat).row3)
#define GET_ROW3(mat)             ((mat).row4)
#define GET_ROW(mat, rowIndex)    ((mat)[rowIndex + 1])

// Inverse matrix
#define INVERSE(mat)              (inverse (mat))

// Determinant
#define DETERMINANT(mat)		  (determinant (mat))

// Multiply matrix by matrix
#define MULMATMAT(mat1, mat2)     ((mat1) * (mat2))

// Multiply matrix by vector
#define MULVECMAT(vec, mat)	  ((vec) * (mat))

// Get vector which is a translation part of a specified transformation matrix
#define GET_TRANSLATION_PART(mat) ((mat).translationPart)

// Get quaternion which is a rotation part of a specified transformation matrix
#define GET_ROTATION_PART(mat)    ((mat).rotationPart)

// Create transformation matrix for translation by translation vector
#define TRANSLATION_MATRIX(pt)    (transMatrix (pt))

// Create transformation matrix for rotation by quaternion
#define ROTATION_MATRIX(q)        ((q) as Matrix3)



