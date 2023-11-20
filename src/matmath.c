#include "../include/matmath.h"

LAC_DECL void lac_add_mat2(const mat2 m_a, const mat2 m_b, mat2 *m_out) {
   (*m_out)[0] = m_a[0] + m_b[0];
   (*m_out)[1] = m_a[1] + m_b[1];
   (*m_out)[2] = m_a[2] + m_b[2];
   (*m_out)[3] = m_a[3] + m_b[3];
}

LAC_DECL void lac_add_mat3(const mat3 m_a, const mat3 m_b, mat3 *m_out) {
   (*m_out)[0] = m_a[0] + m_b[0];
   (*m_out)[1] = m_a[1] + m_b[1];
   (*m_out)[2] = m_a[2] + m_b[2];
   (*m_out)[3] = m_a[3] + m_b[3];
   (*m_out)[4] = m_a[4] + m_b[4];
   (*m_out)[5] = m_a[5] + m_b[5];
   (*m_out)[6] = m_a[6] + m_b[6];
   (*m_out)[7] = m_a[7] + m_b[7];
}

LAC_DECL void lac_add_mat4(const mat4 m_a, const mat4 m_b, mat4 *m_out) {
   (*m_out)[0]  = m_a[0]  + m_b[0];
   (*m_out)[1]  = m_a[1]  + m_b[1];
   (*m_out)[2]  = m_a[2]  + m_b[2];
   (*m_out)[3]  = m_a[3]  + m_b[3];
   (*m_out)[4]  = m_a[4]  + m_b[4];
   (*m_out)[5]  = m_a[5]  + m_b[5];
   (*m_out)[6]  = m_a[6]  + m_b[6];
   (*m_out)[7]  = m_a[7]  + m_b[7];
   (*m_out)[8]  = m_a[8]  + m_b[8];
   (*m_out)[9]  = m_a[9]  + m_b[9];
   (*m_out)[10] = m_a[10] + m_b[10];
   (*m_out)[11] = m_a[11] + m_b[11];
   (*m_out)[12] = m_a[12] + m_b[12];
   (*m_out)[13] = m_a[13] + m_b[13];
   (*m_out)[14] = m_a[14] + m_b[14];
   (*m_out)[15] = m_a[15] + m_b[15];
}

/*  
 ************************** Matrix Multiplication ***************************
 *
 * Matrix multiplication is an operation that takes place between two 
 * matrices. The matrices must be of the same size in order to properly 
 * compute the product matrix. Performing matrix multiplication on two 
 * transformation matrices has the effect of combining both transformations
 * into one matrix. Matrix multiplication is non-commutative, meaning that the 
 * ordering of operands within a matrix multiplication has significant impact 
 * upon the resulting product matrix. The way that matrix multiplication is 
 * computed is by taking the dot product of each row and column between the two 
 * input matrices. In row-major ordering, we take the dot product between each 
 * row in the left-hand matrix before moving to the next column in the right-hand 
 * matrix. In column-major ordering, we take the dot product between each column 
 * in the left-hand matrix before moving the the next row in the right-hand
 * matrix.
*/

LAC_DECL void lac_multiply_mat2(const mat2 m_a, const mat2 m_b, mat2 *m_out) {
   (*m_out)[0] = (m_a[0] * m_b[0]) + (m_a[1] * m_b[2]);
   (*m_out)[1] = (m_a[0] * m_b[1]) + (m_a[1] * m_b[3]);

   (*m_out)[2] = (m_a[2] * m_b[0]) + (m_a[3] * m_b[2]);
   (*m_out)[3] = (m_a[2] * m_b[1]) + (m_a[3] * m_b[3]);
}

LAC_DECL void lac_multiply_mat3(const mat3 m_a, const mat3 m_b, mat3 *m_out) {
   (*m_out)[0] = (m_a[0] * m_b[0]) + (m_a[1] * m_b[3]) + (m_a[2] * m_b[6]);
   (*m_out)[1] = (m_a[0] * m_b[1]) + (m_a[1] * m_b[4]) + (m_a[2] * m_b[7]);
   (*m_out)[2] = (m_a[0] * m_b[2]) + (m_a[1] * m_b[5]) + (m_a[2] * m_b[8]);

   (*m_out)[3] = (m_a[3] * m_b[0]) + (m_a[4] * m_b[3]) + (m_a[5] * m_b[6]);
   (*m_out)[4] = (m_a[3] * m_b[1]) + (m_a[4] * m_b[4]) + (m_a[5] * m_b[7]);
   (*m_out)[5] = (m_a[3] * m_b[2]) + (m_a[4] * m_b[5]) + (m_a[5] * m_b[8]);

   (*m_out)[6] = (m_a[6] * m_b[0]) + (m_a[7] * m_b[3]) + (m_a[8] * m_b[6]);
   (*m_out)[7] = (m_a[6] * m_b[1]) + (m_a[7] * m_b[4]) + (m_a[8] * m_b[7]);
   (*m_out)[8] = (m_a[6] * m_b[2]) + (m_a[7] * m_b[5]) + (m_a[8] * m_b[8]);
}

LAC_DECL void lac_multiply_mat4(const mat4 m_a, const mat4 m_b, mat4 *m_out) {
   (*m_out)[0]  = (m_a[0] * m_b[0])  + (m_a[1] * m_b[4])  + (m_a[2] * m_b[8])   + (m_a[3] * m_b[12]);
   (*m_out)[1]  = (m_a[0] * m_b[1])  + (m_a[1] * m_b[5])  + (m_a[2] * m_b[9])   + (m_a[3] * m_b[13]);
   (*m_out)[2]  = (m_a[0] * m_b[2])  + (m_a[1] * m_b[6])  + (m_a[2] * m_b[10])  + (m_a[3] * m_b[14]);
   (*m_out)[3]  = (m_a[0] * m_b[3])  + (m_a[1] * m_b[7])  + (m_a[2] * m_b[11])  + (m_a[3] * m_b[15]);

   (*m_out)[4]  = (m_a[4] * m_b[0])  + (m_a[5] * m_b[4])  + (m_a[6] * m_b[8])   + (m_a[7] * m_b[12]);
   (*m_out)[5]  = (m_a[4] * m_b[1])  + (m_a[5] * m_b[5])  + (m_a[6] * m_b[9])   + (m_a[7] * m_b[13]);
   (*m_out)[6]  = (m_a[4] * m_b[2])  + (m_a[5] * m_b[6])  + (m_a[6] * m_b[10])  + (m_a[7] * m_b[14]);
   (*m_out)[7]  = (m_a[4] * m_b[3])  + (m_a[5] * m_b[7])  + (m_a[6] * m_b[11])  + (m_a[7] * m_b[15]);

   (*m_out)[8]  = (m_a[8] * m_b[0])  + (m_a[9] * m_b[4])  + (m_a[10] * m_b[8])  + (m_a[11] * m_b[12]);
   (*m_out)[9]  = (m_a[8] * m_b[1])  + (m_a[9] * m_b[5])  + (m_a[10] * m_b[9])  + (m_a[11] * m_b[13]);
   (*m_out)[10] = (m_a[8] * m_b[2])  + (m_a[9] * m_b[6])  + (m_a[10] * m_b[10]) + (m_a[11] * m_b[14]);
   (*m_out)[11] = (m_a[8] * m_b[3])  + (m_a[9] * m_b[7])  + (m_a[10] * m_b[11]) + (m_a[11] * m_b[15]);

   (*m_out)[12] = (m_a[12] * m_b[0]) + (m_a[13] * m_b[4]) + (m_a[14] * m_b[8])  + (m_a[15] * m_b[12]);
   (*m_out)[13] = (m_a[12] * m_b[1]) + (m_a[13] * m_b[5]) + (m_a[14] * m_b[9])  + (m_a[15] * m_b[13]);
   (*m_out)[14] = (m_a[12] * m_b[2]) + (m_a[13] * m_b[6]) + (m_a[14] * m_b[10]) + (m_a[15] * m_b[14]);
   (*m_out)[15] = (m_a[12] * m_b[3]) + (m_a[13] * m_b[7]) + (m_a[14] * m_b[11]) + (m_a[15] * m_b[15]);
}

/*  
 ********************** Matrix Transposition ************************
 *
 * Transposing is an operation by which we flip a matrix on its 
 * diagonal axis. This effectively alters row-major ordered matrices
 * to become column-major ordered, and vice versa. 
*/

/**
 * @brief Transpose a matrix of size 2
 * @since 10-17-2023
 * @param[in] m_in The matrix to be transposed
 * @param[out] m_out The transposed matrix
 */
LAC_DECL void lac_transpose_mat2(const mat2 m_in, mat2 *m_out) {
   (*m_out)[0] = m_in[0];
   (*m_out)[1] = m_in[2];

   (*m_out)[2] = m_in[1];
   (*m_out)[3] = m_in[3];
}

/**
 * @brief Transpose a matrix of size 3
 * @since 10-17-2023
 * @param[in] m_in The matrix to be transposed
 * @param[out] m_out The transposed matrix
 */
LAC_DECL void lac_transpose_mat3(const mat3 m_in, mat3 *m_out) {
   (*m_out)[0] = m_in[0];
   (*m_out)[1] = m_in[3];
   (*m_out)[2] = m_in[6];

   (*m_out)[3] = m_in[1];
   (*m_out)[4] = m_in[4];
   (*m_out)[5] = m_in[7];

   (*m_out)[6] = m_in[2];
   (*m_out)[7] = m_in[5];
   (*m_out)[8] = m_in[8];
}

/**
 * @brief Transpose a matrix of size 4
 * @since 10-17-2023
 * @param[in] m_in The matrix to be transposed
 * @param[out] m_out The transposed matrix
 */
LAC_DECL void lac_transpose_mat4(const mat4 m_in, mat4 *m_out) {
   (*m_out)[0]  = m_in[0];
   (*m_out)[1]  = m_in[4];
   (*m_out)[2]  = m_in[8];
   (*m_out)[3]  = m_in[12];

   (*m_out)[4]  = m_in[1];
   (*m_out)[5]  = m_in[5];
   (*m_out)[6]  = m_in[9];
   (*m_out)[7]  = m_in[13];

   (*m_out)[8]  = m_in[2];
   (*m_out)[9]  = m_in[6];
   (*m_out)[10] = m_in[10];
   (*m_out)[11] = m_in[14];

   (*m_out)[12] = m_in[3];
   (*m_out)[13] = m_in[7];
   (*m_out)[14] = m_in[11];
   (*m_out)[15] = m_in[15];
}
