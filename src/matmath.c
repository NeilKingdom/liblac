/**
 * @file matmath.c
 * @since 17-10-2023
 * @author Neil Kingdom
 * @version 1.0
 * @brief Contains all of the maths which primarily operate on matrices.
 *
 * @section matmul Matrix Multiplication
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
 *
 * @subsubsection matmul_related Related Functions
 *
 * - @ref lac_multiply_mat2_anchor "lac_multiply_mat2"
 * - @ref lac_multiply_mat3_anchor "lac_multiply_mat3"
 * - @ref lac_multiply_mat4_anchor "lac_multiply_mat4"
 *
 * @section transpose Matrix Transposition
 *
 * Transposing is an operation in which we mirror a matrix along its diagonal axis.
 * This effectively alters row-major ordered matrices to become column-major ordered,
 * and vice versa.
 *
 * @subsubsection transpose_related Related Functions
 *
 * - @ref lac_transpose_mat2_anchor "lac_transpose_mat2"
 * - @ref lac_transpose_mat3_anchor "lac_transpose_mat3"
 * - @ref lac_transpose_mat4_anchor "lac_transpose_mat4"
 */

#include "matmath.h"

/**
 * @brief Adds two 2x2 matrices.
 * @since 17-10-2023
 * @param[out] m_out The sum matrix
 * @param[in] m_a The augend matrix
 * @param[in] m_b The addend matrix
 */
LAC_DECL void lac_add_mat2(mat2 m_out, const mat2 m_a, const mat2 m_b) {
    m_out[0] = m_a[0] + m_b[0];
    m_out[1] = m_a[1] + m_b[1];

    m_out[2] = m_a[2] + m_b[2];
    m_out[3] = m_a[3] + m_b[3];
}

/**
 * @brief Adds two 3x3 matrices.
 * @since 17-10-2023
 * @param[out] m_out The sum matrix
 * @param[in] m_a The augend matrix
 * @param[in] m_b The addend matrix
 */
LAC_DECL void lac_add_mat3(mat3 m_out, const mat3 m_a, const mat3 m_b) {
    m_out[0] = m_a[0] + m_b[0];
    m_out[1] = m_a[1] + m_b[1];
    m_out[2] = m_a[2] + m_b[2];

    m_out[3] = m_a[3] + m_b[3];
    m_out[4] = m_a[4] + m_b[4];
    m_out[5] = m_a[5] + m_b[5];

    m_out[6] = m_a[6] + m_b[6];
    m_out[7] = m_a[7] + m_b[7];
    m_out[8] = m_a[8] + m_b[8];
}

/**
 * @brief Adds two 4x4 matrices.
 * @since 17-10-2023
 * @param[out] m_out The sum matrix
 * @param[in] m_a The augend matrix
 * @param[in] m_b The addend matrix
 */
LAC_DECL void lac_add_mat4(mat4 m_out, const mat4 m_a, const mat4 m_b) {
    m_out[0]  = m_a[0]  + m_b[0];
    m_out[1]  = m_a[1]  + m_b[1];
    m_out[2]  = m_a[2]  + m_b[2];
    m_out[3]  = m_a[3]  + m_b[3];

    m_out[4]  = m_a[4]  + m_b[4];
    m_out[5]  = m_a[5]  + m_b[5];
    m_out[6]  = m_a[6]  + m_b[6];
    m_out[7]  = m_a[7]  + m_b[7];

    m_out[8]  = m_a[8]  + m_b[8];
    m_out[9]  = m_a[9]  + m_b[9];
    m_out[10] = m_a[10] + m_b[10];
    m_out[11] = m_a[11] + m_b[11];

    m_out[12] = m_a[12] + m_b[12];
    m_out[13] = m_a[13] + m_b[13];
    m_out[14] = m_a[14] + m_b[14];
    m_out[15] = m_a[15] + m_b[15];
}

/**
 * @brief Subtracts two 2x2 matrices.
 * @since 17-10-2023
 * @param[out] m_out The difference matrix
 * @param[in] m_a The minuend matrix
 * @param[in] m_b The subtrahend matrix
 */
LAC_DECL void lac_subtract_mat2(mat2 m_out, const mat2 m_a, const mat2 m_b) {
    m_out[0] = m_a[0] - m_b[0];
    m_out[1] = m_a[1] - m_b[1];

    m_out[2] = m_a[2] - m_b[2];
    m_out[3] = m_a[3] - m_b[3];
}

/**
 * @brief Subtracts two 3x3 matrices.
 * @since 17-10-2023
 * @param[out] m_out The difference matrix
 * @param[in] m_a The minuend matrix
 * @param[in] m_b The subtrahend matrix
 */
LAC_DECL void lac_subtract_mat3(mat3 m_out, const mat3 m_a, const mat3 m_b) {
    m_out[0] = m_a[0] - m_b[0];
    m_out[1] = m_a[1] - m_b[1];
    m_out[2] = m_a[2] - m_b[2];

    m_out[3] = m_a[3] - m_b[3];
    m_out[4] = m_a[4] - m_b[4];
    m_out[5] = m_a[5] - m_b[5];

    m_out[6] = m_a[6] - m_b[6];
    m_out[7] = m_a[7] - m_b[7];
    m_out[8] = m_a[8] - m_b[8];
}

/**
 * @brief Subtracts two 4x4 matrices.
 * @since 17-10-2023
 * @param[out] m_out The difference matrix
 * @param[in] m_a The minuend matrix
 * @param[in] m_b The subtrahend matrix
 */
LAC_DECL void lac_subtract_mat4(mat4 m_out, const mat4 m_a, const mat4 m_b) {
    m_out[0]  = m_a[0]  - m_b[0];
    m_out[1]  = m_a[1]  - m_b[1];
    m_out[2]  = m_a[2]  - m_b[2];
    m_out[3]  = m_a[3]  - m_b[3];

    m_out[4]  = m_a[4]  - m_b[4];
    m_out[5]  = m_a[5]  - m_b[5];
    m_out[6]  = m_a[6]  - m_b[6];
    m_out[7]  = m_a[7]  - m_b[7];

    m_out[8]  = m_a[8]  - m_b[8];
    m_out[9]  = m_a[9]  - m_b[9];
    m_out[10] = m_a[10] - m_b[10];
    m_out[11] = m_a[11] - m_b[11];

    m_out[12] = m_a[12] - m_b[12];
    m_out[13] = m_a[13] - m_b[13];
    m_out[14] = m_a[14] - m_b[14];
    m_out[15] = m_a[15] - m_b[15];
}

/**
 * @brief Performs matrix multiplication on two 2x2 matrices.
 * @anchor lac_multiply_mat2_anchor
 * @since 17-10-2023
 * @param[out] m_out The product matrix
 * @param[in] m_a The multiplicand matrix
 * @param[in] m_b The multiplier matrix
 */
LAC_DECL void lac_multiply_mat2(mat2 m_out, const mat2 m_a, const mat2 m_b) {
    mat2 _m_out = { 0 };

#if LAC_IS_ROW_MAJOR
    _m_out[0] = (m_a[0] * m_b[0]) + (m_a[1] * m_b[2]);
    _m_out[1] = (m_a[0] * m_b[1]) + (m_a[1] * m_b[3]);

    _m_out[2] = (m_a[2] * m_b[0]) + (m_a[3] * m_b[2]);
    _m_out[3] = (m_a[2] * m_b[1]) + (m_a[3] * m_b[3]);
#else
    _m_out[0] = (m_a[0] * m_b[0]) + (m_a[2] * m_b[1]);
    _m_out[2] = (m_a[0] * m_b[2]) + (m_a[2] * m_b[3]);

    _m_out[1] = (m_a[1] * m_b[0]) + (m_a[3] * m_b[1]);
    _m_out[3] = (m_a[1] * m_b[2]) + (m_a[3] * m_b[3]);
#endif

    memcpy(m_out, _m_out, sizeof(mat2));
}

/**
 * @brief Performs matrix multiplication on two 3x3 matrices.
 * @anchor lac_multiply_mat3_anchor
 * @since 17-10-2023
 * @param[out] m_out The product matrix
 * @param[in] m_a The multiplicand matrix
 * @param[in] m_b The multiplier matrix
 */
LAC_DECL void lac_multiply_mat3(mat3 m_out, const mat3 m_a, const mat3 m_b) {
    mat3 _m_out = { 0 };

#if LAC_IS_ROW_MAJOR
    _m_out[0] = (m_a[0] * m_b[0]) + (m_a[1] * m_b[3]) + (m_a[2] * m_b[6]);
    _m_out[1] = (m_a[0] * m_b[1]) + (m_a[1] * m_b[4]) + (m_a[2] * m_b[7]);
    _m_out[2] = (m_a[0] * m_b[2]) + (m_a[1] * m_b[5]) + (m_a[2] * m_b[8]);

    _m_out[3] = (m_a[3] * m_b[0]) + (m_a[4] * m_b[3]) + (m_a[5] * m_b[6]);
    _m_out[4] = (m_a[3] * m_b[1]) + (m_a[4] * m_b[4]) + (m_a[5] * m_b[7]);
    _m_out[5] = (m_a[3] * m_b[2]) + (m_a[4] * m_b[5]) + (m_a[5] * m_b[8]);

    _m_out[6] = (m_a[6] * m_b[0]) + (m_a[7] * m_b[3]) + (m_a[8] * m_b[6]);
    _m_out[7] = (m_a[6] * m_b[1]) + (m_a[7] * m_b[4]) + (m_a[8] * m_b[7]);
    _m_out[8] = (m_a[6] * m_b[2]) + (m_a[7] * m_b[5]) + (m_a[8] * m_b[8]);
#else
    _m_out[0] = (m_a[0] * m_b[0]) + (m_a[3] * m_b[1]) + (m_a[6] * m_b[2]);
    _m_out[3] = (m_a[0] * m_b[3]) + (m_a[3] * m_b[4]) + (m_a[6] * m_b[5]);
    _m_out[6] = (m_a[0] * m_b[6]) + (m_a[3] * m_b[7]) + (m_a[6] * m_b[8]);

    _m_out[1] = (m_a[1] * m_b[0]) + (m_a[4] * m_b[1]) + (m_a[7] * m_b[2]);
    _m_out[4] = (m_a[1] * m_b[3]) + (m_a[4] * m_b[4]) + (m_a[7] * m_b[5]);
    _m_out[7] = (m_a[1] * m_b[6]) + (m_a[4] * m_b[7]) + (m_a[7] * m_b[8]);

    _m_out[2] = (m_a[2] * m_b[0]) + (m_a[5] * m_b[1]) + (m_a[8] * m_b[2]);
    _m_out[5] = (m_a[2] * m_b[3]) + (m_a[5] * m_b[4]) + (m_a[8] * m_b[5]);
    _m_out[8] = (m_a[2] * m_b[6]) + (m_a[5] * m_b[7]) + (m_a[8] * m_b[8]);
#endif

    memcpy(m_out, _m_out, sizeof(mat3));
}

/**
 * @brief Performs matrix multiplication on two 4x4 matrices.
 * @anchor lac_multiply_mat4_anchor
 * @since 17-10-2023
 * @param[out] m_out The product matrix
 * @param[in] m_a The multiplicand matrix
 * @param[in] m_b The multiplier matrix
 */
LAC_DECL void lac_multiply_mat4(mat4 m_out, const mat4 m_a, const mat4 m_b) {
    mat4 _m_out = { 0 };

#if LAC_IS_ROW_MAJOR
    _m_out[0]  = (m_a[0] * m_b[0])  + (m_a[1] * m_b[4])  + (m_a[2] * m_b[8])   + (m_a[3] * m_b[12]);
    _m_out[1]  = (m_a[0] * m_b[1])  + (m_a[1] * m_b[5])  + (m_a[2] * m_b[9])   + (m_a[3] * m_b[13]);
    _m_out[2]  = (m_a[0] * m_b[2])  + (m_a[1] * m_b[6])  + (m_a[2] * m_b[10])  + (m_a[3] * m_b[14]);
    _m_out[3]  = (m_a[0] * m_b[3])  + (m_a[1] * m_b[7])  + (m_a[2] * m_b[11])  + (m_a[3] * m_b[15]);

    _m_out[4]  = (m_a[4] * m_b[0])  + (m_a[5] * m_b[4])  + (m_a[6] * m_b[8])   + (m_a[7] * m_b[12]);
    _m_out[5]  = (m_a[4] * m_b[1])  + (m_a[5] * m_b[5])  + (m_a[6] * m_b[9])   + (m_a[7] * m_b[13]);
    _m_out[6]  = (m_a[4] * m_b[2])  + (m_a[5] * m_b[6])  + (m_a[6] * m_b[10])  + (m_a[7] * m_b[14]);
    _m_out[7]  = (m_a[4] * m_b[3])  + (m_a[5] * m_b[7])  + (m_a[6] * m_b[11])  + (m_a[7] * m_b[15]);

    _m_out[8]  = (m_a[8] * m_b[0])  + (m_a[9] * m_b[4])  + (m_a[10] * m_b[8])  + (m_a[11] * m_b[12]);
    _m_out[9]  = (m_a[8] * m_b[1])  + (m_a[9] * m_b[5])  + (m_a[10] * m_b[9])  + (m_a[11] * m_b[13]);
    _m_out[10] = (m_a[8] * m_b[2])  + (m_a[9] * m_b[6])  + (m_a[10] * m_b[10]) + (m_a[11] * m_b[14]);
    _m_out[11] = (m_a[8] * m_b[3])  + (m_a[9] * m_b[7])  + (m_a[10] * m_b[11]) + (m_a[11] * m_b[15]);

    _m_out[12] = (m_a[12] * m_b[0]) + (m_a[13] * m_b[4]) + (m_a[14] * m_b[8])  + (m_a[15] * m_b[12]);
    _m_out[13] = (m_a[12] * m_b[1]) + (m_a[13] * m_b[5]) + (m_a[14] * m_b[9])  + (m_a[15] * m_b[13]);
    _m_out[14] = (m_a[12] * m_b[2]) + (m_a[13] * m_b[6]) + (m_a[14] * m_b[10]) + (m_a[15] * m_b[14]);
    _m_out[15] = (m_a[12] * m_b[3]) + (m_a[13] * m_b[7]) + (m_a[14] * m_b[11]) + (m_a[15] * m_b[15]);
#else
    _m_out[0]  = (m_a[0] * m_b[0])  + (m_a[4] * m_b[1])  + (m_a[8] * m_b[2])   + (m_a[12] * m_b[3]);
    _m_out[4]  = (m_a[0] * m_b[4])  + (m_a[4] * m_b[5])  + (m_a[8] * m_b[6])   + (m_a[12] * m_b[7]);
    _m_out[8]  = (m_a[0] * m_b[8])  + (m_a[4] * m_b[9])  + (m_a[8] * m_b[10])  + (m_a[12] * m_b[11]);
    _m_out[12] = (m_a[0] * m_b[12]) + (m_a[4] * m_b[13]) + (m_a[8] * m_b[14])  + (m_a[12] * m_b[15]);

    _m_out[1]  = (m_a[1] * m_b[0])  + (m_a[5] * m_b[1])  + (m_a[9] * m_b[2])   + (m_a[13] * m_b[3]);
    _m_out[5]  = (m_a[1] * m_b[4])  + (m_a[5] * m_b[5])  + (m_a[9] * m_b[6])   + (m_a[13] * m_b[7]);
    _m_out[9]  = (m_a[1] * m_b[8])  + (m_a[5] * m_b[9])  + (m_a[9] * m_b[10])  + (m_a[13] * m_b[11]);
    _m_out[13] = (m_a[1] * m_b[12]) + (m_a[5] * m_b[13]) + (m_a[9] * m_b[14])  + (m_a[13] * m_b[15]);

    _m_out[2]  = (m_a[2] * m_b[0])  + (m_a[6] * m_b[1])  + (m_a[10] * m_b[2])  + (m_a[14] * m_b[3]);
    _m_out[6]  = (m_a[2] * m_b[4])  + (m_a[6] * m_b[5])  + (m_a[10] * m_b[6])  + (m_a[14] * m_b[7]);
    _m_out[10] = (m_a[2] * m_b[8])  + (m_a[6] * m_b[9])  + (m_a[10] * m_b[10]) + (m_a[14] * m_b[11]);
    _m_out[14] = (m_a[2] * m_b[12]) + (m_a[6] * m_b[13]) + (m_a[10] * m_b[14]) + (m_a[14] * m_b[15]);

    _m_out[3]  = (m_a[3] * m_b[0])  + (m_a[7] * m_b[1])  + (m_a[11] * m_b[2])  + (m_a[15] * m_b[3]);
    _m_out[7]  = (m_a[3] * m_b[4])  + (m_a[7] * m_b[5])  + (m_a[11] * m_b[6])  + (m_a[15] * m_b[7]);
    _m_out[11] = (m_a[3] * m_b[8])  + (m_a[7] * m_b[9])  + (m_a[11] * m_b[10]) + (m_a[15] * m_b[11]);
    _m_out[15] = (m_a[3] * m_b[12]) + (m_a[7] * m_b[13]) + (m_a[11] * m_b[14]) + (m_a[15] * m_b[15]);
#endif

    memcpy(m_out, _m_out, sizeof(mat4));
}

/**
 * @brief Transpose a 2x2 matrix.
 * @anchor lac_transpose_mat2_anchor
 * @since 17-10-2023
 * @param[out] m_out The transposed matrix
 * @param[in] m_in The matrix to be transposed
 */
LAC_DECL void lac_transpose_mat2(mat2 m_out, const mat2 m_in) {
    mat2 _m_out = { 0 };

    _m_out[0] = m_in[0];
    _m_out[1] = m_in[2];

    _m_out[2] = m_in[1];
    _m_out[3] = m_in[3];

    memcpy(m_out, _m_out, sizeof(mat2));
}

/**
 * @brief Transpose a 3x3 matrix.
 * @anchor lac_transpose_mat3_anchor
 * @since 17-10-2023
 * @param[out] m_out The transposed matrix
 * @param[in] m_in The matrix to be transposed
 */
LAC_DECL void lac_transpose_mat3(mat3 m_out, const mat3 m_in) {
    mat3 _m_out = { 0 };

    _m_out[0] = m_in[0];
    _m_out[1] = m_in[3];
    _m_out[2] = m_in[6];

    _m_out[3] = m_in[1];
    _m_out[4] = m_in[4];
    _m_out[5] = m_in[7];

    _m_out[6] = m_in[2];
    _m_out[7] = m_in[5];
    _m_out[8] = m_in[8];

    memcpy(m_out, _m_out, sizeof(mat3));
}

/**
 * @brief Transpose a 4x4 matrix.
 * @anchor lac_transpose_mat4_anchor
 * @since 17-10-2023
 * @param[out] m_out The transposed matrix
 * @param[in] m_in The matrix to be transposed
 */
LAC_DECL void lac_transpose_mat4(mat4 m_out, const mat4 m_in) {
    mat4 _m_out = { 0 };

    _m_out[0]  = m_in[0];
    _m_out[1]  = m_in[4];
    _m_out[2]  = m_in[8];
    _m_out[3]  = m_in[12];

    _m_out[4]  = m_in[1];
    _m_out[5]  = m_in[5];
    _m_out[6]  = m_in[9];
    _m_out[7]  = m_in[13];

    _m_out[8]  = m_in[2];
    _m_out[9]  = m_in[6];
    _m_out[10] = m_in[10];
    _m_out[11] = m_in[14];

    _m_out[12] = m_in[3];
    _m_out[13] = m_in[7];
    _m_out[14] = m_in[11];
    _m_out[15] = m_in[15];

    memcpy(m_out, _m_out, sizeof(mat4));
}
