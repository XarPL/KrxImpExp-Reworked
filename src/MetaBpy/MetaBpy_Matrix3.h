///////////////////////////////////////////////////////////////////////////////
// Name:        MetaBpy_Matrix3.h
// Purpose:     Macroses to build plugins for Blender in the Python language
//                 with the "Wave" precompiler.
// Author:      Vitaly Baranov
// Created:     March 14, 2009
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

// 4x3 3D transformation matrix
#define TMATRIX3
#define ZERO_MATRIX3			zero_matrix()
#define IDENTITY_MATRIX3		identity_matrix()
#define NEW_MATRIX3(row0, row1, row2, row3) new_matrix(row0, row1, row2, row3)

// Check if this is an identity matrix
#define IS_IDENTITY(mat)		is_identity_matrix(mat)

// Set row
#define SET_ROW0(mat, row0)          set_row0(mat, row0)
#define SET_ROW1(mat, row1)          set_row1(mat, row1)
#define SET_ROW2(mat, row2)          set_row2(mat, row2)
#define SET_ROW3(mat, row3)          set_row3(mat, row3)
#define SET_ROW(mat, rowIndex, row)  set_row0(mat, rowIndex, row)

// Get row
#define GET_ROW0(mat)             get_row0(mat)
#define GET_ROW1(mat)             get_row1(mat)
#define GET_ROW2(mat)             get_row2(mat)
#define GET_ROW3(mat)             get_row3(mat)
#define GET_ROW(mat, rowIndex)    get_row(mat, rowIndex)

// Inverse matrix
#define INVERSE(mat)              inverse_matrix(mat)

// Determinant
#define DETERMINANT(mat)          determinant(mat)

// Multiply matrix by matrix
#define MULMATMAT(mat1, mat2)     multiply_matrix_matrix(mat1, mat2)

// Multiply matrix by vector
#define MULVECMAT(vec, mat)	      multiply_vector_matrix(vec, mat)

// Get vector which is a translation part of a specified transformation matrix
#define GET_TRANSLATION_PART(mat) get_translation_part(mat)

// Get quaternion which is a rotation part of a specified transformation matrix
#define GET_ROTATION_PART(mat)    get_rotation_part(mat)

// Create transformation matrix for translation by translation vector
#define TRANSLATION_MATRIX(pt)    translation_matrix(pt)

// Create transformation matrix for rotation by quaternion
#define ROTATION_MATRIX(q)        rotation_matrix(q)



