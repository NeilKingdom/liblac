/**
 * @file vecmath.c
 * @author Neil Kingdom
 * @since 10-17-2023
 * @brief vecmath.c Contains all of the maths functions which pertain to vectors specifically
 *
 * @section dotprod Dot Product
 *
 * The dot product, a.k.a scalar product, is an operation that 
 * can be performed by summing the product of each component 
 * between two vectors. The operation returns a single number
 * known as the scalar value. This value can be used to determine
 * similarity between two vectors, and is often used for 
 * computing how much lighting a given surface should receive 
 * in 3D graphics, amongst other practical applications.
 *
 * @subsection dotprod_related Related Functions
 *
 * - @ref lac_calc_dot_prod_vec2_anchor "lac_calc_dot_prod_vec2"
 * - @ref lac_calc_dot_prod_vec3_anchor "lac_calc_dot_prod_vec3"
 * - @ref lac_calc_dot_prod_vec4_anchor "lac_calc_dot_prod_vec4"
 *
 * @section crossprod Cross Product
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
 *
 * @subsection crossprod_related Related Functions
 *
 * - @ref lac_calc_cross_prod_anchor "lac_calc_cross_prod"
 *
 * @section normalization Vector Normalization
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
 * squares of each side length. This is because in linear algeabra 
 * the magnitude is synonymous with the hypotenuse in trigonometry. 
 *
 * @subsection normalization_related Related Functions
 *
 * - @ref lac_normalize_vec2_anchor "lac_normalize_vec2"
 * - @ref lac_normalize_vec3_anchor "lac_normalize_vec3"
 * - @ref lac_normalize_vec4_anchor "lac_normalize_vec4"
 */

#include "../include/lac_common.h"

/**
 * @brief Calculates the sum between two vectors of size 2
 * @since 10-19-2023
 * @param[out] v_out The sum vector
 * @param[in] v_a The Augend vector
 * @param[in] v_b The Addend vector
 */
LAC_DECL void lac_add_vec2(vec2 *v_out, const vec2 v_a, const vec2 v_b) {
    (*v_out)[0] = v_a[0] + v_b[0];
    (*v_out)[1] = v_a[1] + v_b[1];
}

/**
 * @brief Calculates the sum between two vectors of size 3
 * @since 10-19-2023
 * @param[out] v_out The sum vector
 * @param[in] v_a The Augend vector
 * @param[in] v_b The Addend vector
 */
LAC_DECL void lac_add_vec3(vec3 *v_out, const vec3 v_a, const vec3 v_b) {
    (*v_out)[0] = v_a[0] + v_b[0];
    (*v_out)[1] = v_a[1] + v_b[1];
    (*v_out)[2] = v_a[2] + v_b[2];
}

/**
 * @brief Calculates the sum between two vectors of size 4
 * @since 10-19-2023
 * @param[out] v_out The sum vector
 * @param[in] v_a The Augend vector
 * @param[in] v_b The Addend vector
 */
LAC_DECL void lac_add_vec4(vec4 *v_out, const vec4 v_a, const vec4 v_b) {
    (*v_out)[0] = v_a[0] + v_b[0];
    (*v_out)[1] = v_a[1] + v_b[1];
    (*v_out)[2] = v_a[2] + v_b[2];
    (*v_out)[3] = v_a[3] + v_b[3];
}

/**
 * @brief Calculates the difference between two vectors of size 2
 * @since 10-17-2023
 * @param[out] v_out The difference vector
 * @param[in] v_a The minuend vector
 * @param[in] v_b The subtrahend vector
 */
LAC_DECL void lac_subtract_vec2(vec2 *v_out, const vec2 v_a, const vec2 v_b) {
    (*v_out)[0] = v_a[0] - v_b[0];
    (*v_out)[1] = v_a[1] - v_b[1];
}

/**
 * @brief Calculates the difference between two vectors of size 3
 * @since 10-17-2023
 * @param[out] v_out The difference vector
 * @param[in] v_a The minuend vector
 * @param[in] v_b The subtrahend vector
 */
LAC_DECL void lac_subtract_vec3(vec3 *v_out, const vec3 v_a, const vec3 v_b) {
    (*v_out)[0] = v_a[0] - v_b[0];
    (*v_out)[1] = v_a[1] - v_b[1];
    (*v_out)[2] = v_a[2] - v_b[2];
}

/**
 * @brief Calculates the difference between two vectors of size 4
 * @since 10-17-2023
 * @param[out] v_out The difference vector
 * @param[in] v_a The minuend vector
 * @param[in] v_b The subtrahend vector
 */
LAC_DECL void lac_subtract_vec4(vec4 *v_out, const vec4 v_a, const vec4 v_b) {
    (*v_out)[0] = v_a[0] - v_b[0];
    (*v_out)[1] = v_a[1] - v_b[1];
    (*v_out)[2] = v_a[2] - v_b[2];
    (*v_out)[3] = v_a[3] - v_b[3];
}

/**
 * @brief Scales a vector of size 2 up by a factor of "scalar"
 * @since 10-19-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the multiplier
 */
LAC_DECL void lac_multiply_vec2(vec2 *v_out, const vec2 v_in, float scalar) {
    (*v_out)[0] = v_in[0] * scalar;
    (*v_out)[1] = v_in[1] * scalar;
}

/**
 * @brief Scales a vector of size 3 up by a factor of "scalar"
 * @since 10-19-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the multiplier
 */
LAC_DECL void lac_multiply_vec3(vec3 *v_out, const vec3 v_in, float scalar) {
    (*v_out)[0] = v_in[0] * scalar;
    (*v_out)[1] = v_in[1] * scalar;
    (*v_out)[2] = v_in[2] * scalar;
}

/**
 * @brief Scales a vector of size 4 up by a factor of "scalar"
 * @since 10-19-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the multiplier
 */
LAC_DECL void lac_multiply_vec4(vec4 *v_out, const vec4 v_in, float scalar) {
    (*v_out)[0] = v_in[0] * scalar;
    (*v_out)[1] = v_in[1] * scalar;
    (*v_out)[2] = v_in[2] * scalar;
    (*v_out)[3] = v_in[3] * scalar;
}

/**
 * @brief Scales a vector of size 2 down by a factor of "scalar"
 * @since 10-19-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the divisor
 */
LAC_DECL void lac_divide_vec2(vec2 *v_out, const vec2 v_in, float scalar) {
    if (scalar == 0.0f) {
        LAC_WARN("Attempted divide by 0");
        (*v_out)[0] = 0.0f;
        (*v_out)[1] = 0.0f;
    } else {
        (*v_out)[0] = v_in[0] / scalar;
        (*v_out)[1] = v_in[1] / scalar;
    }
}

/**
 * @brief Scales a vector of size 3 down by a factor of "scalar"
 * @since 10-19-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the divisor
 */
LAC_DECL void lac_divide_vec3(vec3 *v_out, const vec3 v_in, float scalar) {
    if (scalar == 0.0f) {
        LAC_WARN("Attempted divide by 0");
        (*v_out)[0] = 0.0f;
        (*v_out)[1] = 0.0f;
    } else {
        (*v_out)[0] = v_in[0] / scalar;
        (*v_out)[1] = v_in[1] / scalar;
        (*v_out)[2] = v_in[2] / scalar;
    }
}

/**
 * @brief Scales a vector of size 3 down by a factor of "scalar"
 * @since 10-19-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the divisor
 */
LAC_DECL void lac_divide_vec4(vec4 *v_out, const vec4 v_in, float scalar) {
    if (scalar == 0.0f) {
        LAC_WARN("Attempted divide by 0");
        (*v_out)[0] = 0.0f;
        (*v_out)[1] = 0.0f;
    } else {
        (*v_out)[0] = v_in[0] / scalar;
        (*v_out)[1] = v_in[1] / scalar;
        (*v_out)[2] = v_in[2] / scalar;
        (*v_out)[3] = v_in[3] / scalar;
    }
}

/**
 * @brief Calculates the dot product given two vectors of size 2
 * @anchor lac_calc_dot_prod_vec2_anchor
 * @since 10-17-2023
 * @param[out] dot_prod The scalar value
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 */
LAC_DECL void lac_calc_dot_prod_vec2(float * restrict dot_prod, const vec2 v_a, const vec2 v_b) {
    *dot_prod = (v_a[0] * v_b[0]) + (v_a[1] * v_b[1]);
}

/**
 * @brief Calculates the dot product given two vectors of size 3
 * @anchor lac_calc_dot_prod_vec3_anchor
 * @since 10-17-2023
 * @param[out] dot_prod The scalar value
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 */
LAC_DECL void lac_calc_dot_prod_vec3(float * restrict dot_prod, const vec3 v_a, const vec3 v_b) {
    *dot_prod = (v_a[0] * v_b[0]) + (v_a[1] * v_b[1]) + (v_a[2] * v_b[2]);
}

/**
 * @brief Calculates the dot product given two vectors of size 4
 * @anchor lac_calc_dot_prod_vec4_anchor
 * @since 10-17-2023
 * @param[out] dot_prod The scalar value
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 */
LAC_DECL void lac_calc_dot_prod_vec4(float * restrict dot_prod, const vec4 v_a, const vec4 v_b) {
    *dot_prod = (v_a[0] * v_b[0]) + (v_a[1] * v_b[1]) + (v_a[2] * v_b[2]) + (v_a[3] * v_b[3]);
}

/**
 * @brief Calculates the cross product given two vectors of size 3
 * @anchor lac_calc_cross_prod_anchor
 * @since 10-17-2023
 * @param[out] v_out The resulting vector, orthogonal to v_a and v_b
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 */
LAC_DECL void lac_calc_cross_prod(vec3 *v_out, const vec3 v_a, const vec3 v_b) {
    (*v_out)[0] = (v_a[1] * v_b[2]) - (v_a[2] * v_b[1]);
    (*v_out)[1] = (v_a[2] * v_b[0]) - (v_a[0] * v_b[2]);
    (*v_out)[2] = (v_a[0] * v_b[1]) - (v_a[1] * v_b[0]);
}

/**
 * @brief Calculates the magnitude for a given vector of size 2
 * @since 12-10-2023
 * @param[out] magnitude The calculated magnitude
 * @param[in] The vector for which the magnitude is calculated
 */
LAC_DECL void lac_calc_magnitude_vec2(float * restrict magnitude, const vec2 v_in) {
    *magnitude = sqrtf((v_in[0] * v_in[0]) + (v_in[1] * v_in[1]));
} 

/**
 * @brief Calculates the magnitude for a given vector of size 3
 * @since 12-10-2023
 * @param[out] magnitude The calculated magnitude
 * @param[in] The vector for which the magnitude is calculated
 */
LAC_DECL void lac_calc_magnitude_vec3(float * restrict magnitude, const vec3 v_in) {
    *magnitude = sqrtf((v_in[0] * v_in[0]) + (v_in[1] * v_in[1]) + (v_in[2] * v_in[2]));
} 

/**
 * @brief Calculates the magnitude for a given vector of size 4
 * @since 12-10-2023
 * @param[out] magnitude The calculated magnitude
 * @param[in] The vector for which the magnitude is calculated
 */
LAC_DECL void lac_calc_magnitude_vec4(float * restrict magnitude, const vec4 v_in) {
    *magnitude = sqrtf((v_in[0] * v_in[0]) + (v_in[1] * v_in[1]) + (v_in[2] * v_in[2]) + (v_in[3] * v_in[3]));
} 

/**
 * @brief Normalize a vector of size 2
 * @anchor lac_normalize_vec2_anchor
 * @since 10-17-2023
 * @param[out] v_out The normalized vector
 * @param[in] v_in The vector to be normalized
 */
LAC_DECL void lac_normalize_vec2(vec2 *v_out, const vec2 v_in) {
    float magnitude;
    lac_calc_magnitude_vec2(&magnitude, v_in);

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
 * @anchor lac_normalize_vec3_anchor
 * @since 10-17-2023
 * @param[out] v_out The normalized vector
 * @param[in] v_in The vector to be normalized
 */
LAC_DECL void lac_normalize_vec3(vec3 *v_out, const vec3 v_in) {
    float magnitude;
    lac_calc_magnitude_vec3(&magnitude, v_in);

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
 * @anchor lac_normalize_vec4_anchor
 * @since 10-17-2023
 * @param[out] v_out The normalized vector
 * @param[in] v_in The vector to be normalized
 */
LAC_DECL void lac_normalize_vec4(vec4 *v_out, const vec4 v_in) {
    float magnitude;
    lac_calc_magnitude_vec4(&magnitude, v_in);

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

