#include "../include/matmath.h"

LAC_DECL void lac_add_mat2(const mat2 m_a, const mat2 m_b, mat2 * restrict m_out) {
   (*m_out)[0] = m_a[0] + m_b[0];
   (*m_out)[1] = m_a[1] + m_b[1];
   (*m_out)[2] = m_a[2] + m_b[2];
   (*m_out)[3] = m_a[3] + m_b[3];
}

LAC_DECL void lac_add_mat3(const mat3 m_a, const mat3 m_b, mat3 * restrict m_out) {
   (*m_out)[0] = m_a[0] + m_b[0];
   (*m_out)[1] = m_a[1] + m_b[1];
   (*m_out)[2] = m_a[2] + m_b[2];
   (*m_out)[3] = m_a[3] + m_b[3];
   (*m_out)[4] = m_a[4] + m_b[4];
   (*m_out)[5] = m_a[5] + m_b[5];
   (*m_out)[6] = m_a[6] + m_b[6];
   (*m_out)[7] = m_a[7] + m_b[7];
}

LAC_DECL void lac_add_mat4(const mat4 m_a, const mat4 m_b, mat4 * restrict m_out) {
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

/**
 * @brief Calculates the difference between two vectors of size 2
 * @since 10-17-2023
 * @param[in] v_a The minuend vector
 * @param[in] v_b The subtrahend vector
 * @param[out] v_out The difference vector
 */
LAC_DECL void lac_subtract_vec2(const vec2 v_a, const vec2 v_b, vec2 * restrict v_out) {
   (*v_out)[0] = v_a[0] - v_b[0];
   (*v_out)[1] = v_a[1] - v_b[1];
}

/**
 * @brief Calculates the difference between two vectors of size 3
 * @since 10-17-2023
 * @param[in] v_a The minuend vector
 * @param[in] v_b The subtrahend vector
 * @param[out] v_out The difference vector
 */
LAC_DECL void lac_subtract_vec3(const vec3 v_a, const vec3 v_b, vec3 * restrict v_out) {
   (*v_out)[0] = v_a[0] - v_b[0];
   (*v_out)[1] = v_a[1] - v_b[1];
   (*v_out)[2] = v_a[2] - v_b[2];
}

/**
 * @brief Calculates the difference between two vectors of size 4
 * @since 10-17-2023
 * @param[in] v_a The minuend vector
 * @param[in] v_b The subtrahend vector
 * @param[out] v_out The difference vector
 */
LAC_DECL void lac_subtract_vec4(const vec4 v_a, const vec4 v_b, vec4 * restrict v_out) {
   (*v_out)[0] = v_a[0] - v_b[0];
   (*v_out)[1] = v_a[1] - v_b[1];
   (*v_out)[2] = v_a[2] - v_b[2];
   (*v_out)[3] = v_a[3] - v_b[3];
}

/*  
 ************************** Matrix Multiplication ***************************
 *
 * Matrix multiplication is an operation that takes place between two 
 * matrices. The matrices must be of the same size in order to properly 
 * compute the product matrix. Performing matrix multiplication on two 
 * transformation matrices has the effect of combining both transformations
 * into one matrix. The ordering of operands within a matrix multiplication
 * has significant impact upon the resulting product matrix. The way that 
 * matrix multiplication is computed is by taking the dot product of each
 * row and column between the two input matrices. In row-major ordering, 
 * we take the dot product between each row in the left-hand matrix 
 * before moving to the next column in the right-hand matrix. In column-
 * major ordering, we take the dot product between each column in the 
 * left-hand matrix before moving the the next row in the right-hand
 * matrix.
*/

LAC_DECL void lac_multiply_mat2(const mat2 m_a, const mat2 m_b, mat2 * restrict m_out) {
   (*m_out)[0] = (m_a[0] * m_b[0]) + (m_a[1] * m_b[2]);
   (*m_out)[1] = (m_a[0] * m_b[1]) + (m_a[1] * m_b[3]);

   (*m_out)[2] = (m_a[2] * m_b[0]) + (m_a[3] * m_b[2]);
   (*m_out)[3] = (m_a[2] * m_b[1]) + (m_a[3] * m_b[3]);
}

LAC_DECL void lac_multiply_mat3(const mat3 m_a, const mat3 m_b, mat3 * restrict m_out) {
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

LAC_DECL void lac_multiply_mat4(const mat4 m_a, const mat4 m_b, mat4 * restrict m_out) {
   (*m_out)[0] = (m_a[0] * m_b[0])  + (m_a[1] * m_b[4])  + (m_a[2] * m_b[8])   + (m_a[3] * m_b[12]);
   (*m_out)[1] = (m_a[0] * m_b[1])  + (m_a[1] * m_b[5])  + (m_a[2] * m_b[9])   + (m_a[3] * m_b[13]);
   (*m_out)[2] = (m_a[0] * m_b[2])  + (m_a[1] * m_b[6])  + (m_a[2] * m_b[10])  + (m_a[3] * m_b[14]);
   (*m_out)[3] = (m_a[0] * m_b[3])  + (m_a[1] * m_b[7])  + (m_a[2] * m_b[11])  + (m_a[3] * m_b[15]);

   (*m_out)[4] = (m_a[4] * m_b[0])  + (m_a[5] * m_b[4])  + (m_a[6] * m_b[8])   + (m_a[7] * m_b[12]);
   (*m_out)[5] = (m_a[4] * m_b[1])  + (m_a[5] * m_b[5])  + (m_a[6] * m_b[9])   + (m_a[7] * m_b[13]);
   (*m_out)[6] = (m_a[4] * m_b[2])  + (m_a[5] * m_b[6])  + (m_a[6] * m_b[10])  + (m_a[7] * m_b[14]);
   (*m_out)[7] = (m_a[4] * m_b[3])  + (m_a[5] * m_b[7])  + (m_a[6] * m_b[11])  + (m_a[7] * m_b[15]);

   (*m_out)[8] = (m_a[8] * m_b[0])  + (m_a[9] * m_b[4])  + (m_a[10] * m_b[8])  + (m_a[11] * m_b[12]);
   (*m_out)[9] = (m_a[8] * m_b[1])  + (m_a[9] * m_b[5])  + (m_a[10] * m_b[9])  + (m_a[11] * m_b[13]);
   (*m_out)[10] = (m_a[8] * m_b[2])  + (m_a[9] * m_b[6])  + (m_a[10] * m_b[10]) + (m_a[11] * m_b[14]);
   (*m_out)[11] = (m_a[8] * m_b[3])  + (m_a[9] * m_b[7])  + (m_a[10] * m_b[11]) + (m_a[11] * m_b[15]);

   (*m_out)[12] = (m_a[12] * m_b[0]) + (m_a[13] * m_b[4]) + (m_a[14] * m_b[8])  + (m_a[15] * m_b[12]);
   (*m_out)[13] = (m_a[12] * m_b[1]) + (m_a[13] * m_b[5]) + (m_a[14] * m_b[9])  + (m_a[15] * m_b[13]);
   (*m_out)[14] = (m_a[12] * m_b[2]) + (m_a[13] * m_b[6]) + (m_a[14] * m_b[10]) + (m_a[15] * m_b[14]);
   (*m_out)[15] = (m_a[12] * m_b[3]) + (m_a[13] * m_b[7]) + (m_a[14] * m_b[11]) + (m_a[15] * m_b[15]);
}

/*  
 ************************** Dot Product ***************************
 *
 * The dot product, a.k.a scalar product, is an operation that 
 * can be performed by summing the product of each component 
 * between two vectors. The operation returns a single number
 * known as the scalar value. This value can be used to determine
 * similarity between two vectors, and is often used for 
 * computing how much lighting a given surface should receive 
 * in 3D graphics, amongst other practical applications.
*/

/**
 * @brief Calculates the dot product given two vectors of size 2
 * @since 10-17-2023
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 * @returns the scalar value 
 */
LAC_DECL float lac_calc_dot_prod_vec2(const vec2 v_a, const vec2 v_b) {
   return (v_a[0] * v_b[0]) + (v_a[1] * v_b[1]);
}

/**
 * @brief Calculates the dot product given two vectors of size 3
 * @since 10-17-2023
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 * @returns the scalar value 
 */
LAC_DECL float lac_calc_dot_prod_vec3(const vec3 v_a, const vec3 v_b) {
   return (v_a[0] * v_b[0]) + (v_a[1] * v_b[1]) + (v_a[2] * v_b[2]);
}

/**
 * @brief Calculates the dot product given two vectors of size 4
 * @since 10-17-2023
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 * @returns the scalar value 
 */
LAC_DECL float lac_calc_dot_prod_vec4(const vec4 v_a, const vec4 v_b) {
   return (v_a[0] * v_b[0]) + (v_a[1] * v_b[1]) + (v_a[2] * v_b[2]) + (v_a[3] * v_b[3]);
}

/*  
 ************************** Cross Product ***************************
 *
 * The cross product is an operation between two vectors which is 
 * calculated by taking the difference of each product between 
 * complimentary pairs in each vector. The formula for this looks 
 * something like:
 * w1 = u2v3 - u3v2
 * This is computed for each component of w. Taking the cross product 
 * yields a vector that is orthogonal to both operand vectors. 
 * The normalized version of this orthogonal vector is classically 
 * coined as the "normal". The normal is typically used in 3D graphics
 * to determine which faces of a mesh should or shouldn't be drawn
 * on top of others. In other words, it provides z-order information,
 * as well as being useful for calculating the amount of lighting that
 * a surface should receive by comparing it with the dot product of
 * a point light. Important to note is that the cross product is 
 * uniquely applicable to vectors of size 3 only. The equivallent for
 * vectors of size 2 is known as the "outer product" and for vectors
 * of size 4, the "wedge product".
*/

/**
 * @brief Calculates the cross product given two vectors of size 3
 * @since 10-17-2023
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 * @param[out] v_out The resulting vector, orthogonal to v_a and v_b
 */
LAC_DECL void lac_calc_cross_prod(const vec3 v_a, const vec3 v_b, vec3 * restrict v_out) {
   (*v_out)[0] = (v_a[1] * v_b[2]) - (v_a[2] * v_b[1]);
   (*v_out)[1] = (v_a[2] * v_b[0]) - (v_a[0] * v_b[2]);
   (*v_out)[2] = (v_a[0] * v_b[1]) - (v_a[1] * v_b[0]);
}

/*  
 *********************** Vector Normalization ***********************
 *
 * It is often beneficial to nomalize vectors so that their magnitude
 * is of length 1. When a vector is normalized, we can easily apply
 * a scalar value to make it any magnitude we'd like. For instance, 
 * we might have a direction vector which is normalized and then 
 * scaled depending upon the velocity of a moving object. Similar to 
 * how we normalize anything, in order to normalize a vector, we must
 * divide by its magnitude. Since multiplication is computationally 
 * cheaper than division, it is slightlty more efficient to multiply 
 * by the inverse of the vectors magnitude, which yields the same 
 * result. In order to compute the magnitude of a vector, we use 
 * Pythegoreas' Theorum and take the square root of the sum of 
 * squares of each side length. This is because in linear algeabra, 
 * the magnitude is equal to the hypotenuse in trigonometry. 
*/

/**
 * @brief Normalize a vector of size 2
 * @since 10-17-2023
 * @param[in] v_in The vector to be normalized
 * @param[out] v_out The normalized vector
 */
LAC_DECL void lac_normalize_vec2(const vec2 v_in, vec2 * restrict v_out) {
    float magnitude = sqrtf(lac_calc_dot_prod_vec2(v_in, v_in));

    if (magnitude > 0.0f) {
        float inv_magnitude = 1.0f / magnitude;
        (*v_out)[0] = v_in[0] * inv_magnitude;
        (*v_out)[1] = v_in[1] * inv_magnitude;
    } else { // v_in already had magnitude 0
        (*v_out)[0] = 0.0f;
        (*v_out)[1] = 0.0f;
    }
}

/**
 * @brief Normalize a vector of size 3
 * @since 10-17-2023
 * @param[in] v_in The vector to be normalized
 * @param[out] v_out The normalized vector
 */
LAC_DECL void lac_normalize_vec3(const vec3 v_in, vec3 * restrict v_out) {
    float magnitude = sqrtf(lac_calc_dot_prod_vec3(v_in, v_in));

    if (magnitude > 0.0f) {
        float inv_magnitude = 1.0f / magnitude;
        (*v_out)[0] = v_in[0] * inv_magnitude;
        (*v_out)[1] = v_in[1] * inv_magnitude;
        (*v_out)[2] = v_in[2] * inv_magnitude;
    } else { // v_in already had magnitude 0
        (*v_out)[0] = 0.0f;
        (*v_out)[1] = 0.0f;
        (*v_out)[2] = 0.0f;
    }
}

/**
 * @brief Normalize a vector of size 4
 * @since 10-17-2023
 * @param[in] v_in The vector to be normalized
 * @param[out] v_out The normalized vector
 */
LAC_DECL void lac_normalize_vec4(const vec4 v_in, vec4 * restrict v_out) {
    float magnitude = sqrtf(lac_calc_dot_prod_vec4(v_in, v_in));

    if (magnitude > 0.0f) {
        float inv_magnitude = 1.0f / magnitude;
        (*v_out)[0] = v_in[0] * inv_magnitude;
        (*v_out)[1] = v_in[1] * inv_magnitude;
        (*v_out)[2] = v_in[2] * inv_magnitude;
        (*v_out)[3] = v_in[3] * inv_magnitude;
    } else { // v_in already had magnitude 0
        (*v_out)[0] = 0.0f;
        (*v_out)[1] = 0.0f;
        (*v_out)[2] = 0.0f;
        (*v_out)[3] = 0.0f;
    }
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
 * @param[in] v_in The vector to be transposed
 * @param[out] v_out The transposed vector
 */
LAC_DECL void lac_transpose_mat2(const mat2 v_in, mat2 * restrict v_out) {
   (*v_out)[0] = v_in[0];
   (*v_out)[1] = v_in[2];

   (*v_out)[2] = v_in[1];
   (*v_out)[3] = v_in[3];
}

/**
 * @brief Transpose a matrix of size 3
 * @since 10-17-2023
 * @param[in] v_in The vector to be transposed
 * @param[out] v_out The transposed vector
 */
LAC_DECL void lac_transpose_mat3(const mat3 v_in, mat3 * restrict v_out) {
   (*v_out)[0] = v_in[0];
   (*v_out)[1] = v_in[3];
   (*v_out)[2] = v_in[6];

   (*v_out)[3] = v_in[1];
   (*v_out)[4] = v_in[4];
   (*v_out)[5] = v_in[7];

   (*v_out)[6] = v_in[2];
   (*v_out)[7] = v_in[5];
   (*v_out)[8] = v_in[8];
}

/**
 * @brief Transpose a matrix of size 4
 * @since 10-17-2023
 * @param[in] v_in The vector to be transposed
 * @param[out] v_out The transposed vector
 */
LAC_DECL void lac_transpose_mat4(const mat4 v_in, mat4 * restrict v_out) {
   (*v_out)[0]  = v_in[0];
   (*v_out)[1]  = v_in[4];
   (*v_out)[2]  = v_in[8];
   (*v_out)[3]  = v_in[12];

   (*v_out)[4]  = v_in[1];
   (*v_out)[5]  = v_in[5];
   (*v_out)[6]  = v_in[9];
   (*v_out)[7]  = v_in[13];

   (*v_out)[8]  = v_in[2];
   (*v_out)[9]  = v_in[6];
   (*v_out)[10] = v_in[10];
   (*v_out)[11] = v_in[14];

   (*v_out)[12] = v_in[3];
   (*v_out)[13] = v_in[7];
   (*v_out)[14] = v_in[11];
   (*v_out)[15] = v_in[15];
}
