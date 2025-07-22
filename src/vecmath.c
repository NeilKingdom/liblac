/**
 * @file vecmath.c
 * @author Neil Kingdom
 * @since 17-10-2023
 * @version 1.0
 * @brief Contains all of the maths which primarily operate on vectors.
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
 * > w1 = u2v3 - u3v2
 *
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
 *
 * @section polarcart Polar and Cartesian Coordinates
 *
 * Most of you will be familiar with the cartesian coordinate system
 * popularized by Rene Descartes. This coordinate system imagines one
 * or more infinitely traversable planes representing each dimension
 * in Euclidian space. It traditionally uses x. y. and z to represent
 * numbers along the three axes.
 *
 * Polar coordinates are specifically a 2 dimensional coordinate
 * system. All points within the polar coordinate system are relative
 * to the polar axis, which is equivallent to (0, 0) in cartesian
 * coordinates. The polar axis extends along what would normally be the
 * x axis and it extends infinitely to the right. Every polar coordinate
 * will be determined by a length and an angle which are relative to
 * the polar axis. The angle component is known as the angular
 * coordinate and the length component is known as the radial coordinate.
 * We can convert from polar to cartesian coordinates quite easily
 * by multiplying the radial coordinate length by cos of the andular
 * coordinate to get x and likewise the length times sin of the angle for
 * the y component.
 *
 * @subsection polarcart_related Related Functions
 *
 * - @ref lac_cartesian_to_polar_anchor "lac_cartesian_to_polar"
 * - @ref lac_polar_to_cartesian_anchor "lac_polar_to_cartesian"
 */

#include "lac_common.h"

/**
 * @brief Calculates the sum between two vectors of length 2.
 * @since 19-10-2023
 * @param v_out[out] The sum vector
 * @param v_a[in] The Augend vector
 * @param v_b[in] The Addend vector
 */
LAC_DECL void lac_add_vec2(vec2 v_out, const vec2 v_a, const vec2 v_b) {
    v_out[0] = v_a[0] + v_b[0];
    v_out[1] = v_a[1] + v_b[1];
}

/**
 * @brief Calculates the sum between two vectors of length 3.
 * @since 19-10-2023
 * @param[out] v_out The sum vector
 * @param[in] v_a The Augend vector
 * @param[in] v_b The Addend vector
 */
LAC_DECL void lac_add_vec3(vec3 v_out, const vec3 v_a, const vec3 v_b) {
    v_out[0] = v_a[0] + v_b[0];
    v_out[1] = v_a[1] + v_b[1];
    v_out[2] = v_a[2] + v_b[2];
}

/**
 * @brief Calculates the sum between two vectors of length 4.
 * @since 19-10-2023
 * @param[out] v_out The sum vector
 * @param[in] v_a The Augend vector
 * @param[in] v_b The Addend vector
 */
LAC_DECL void lac_add_vec4(vec4 v_out, const vec4 v_a, const vec4 v_b) {
    v_out[0] = v_a[0] + v_b[0];
    v_out[1] = v_a[1] + v_b[1];
    v_out[2] = v_a[2] + v_b[2];
    v_out[3] = v_a[3] + v_b[3];
}

/**
 * @brief Calculates the difference between two vectors of length 2.
 * @since 17-10-2023
 * @param[out] v_out The difference vector
 * @param[in] v_a The minuend vector
 * @param[in] v_b The subtrahend vector
 */
LAC_DECL void lac_subtract_vec2(vec2 v_out, const vec2 v_a, const vec2 v_b) {
    v_out[0] = v_a[0] - v_b[0];
    v_out[1] = v_a[1] - v_b[1];
}

/**
 * @brief Calculates the difference between two vectors of length 3.
 * @since 17-10-2023
 * @param[out] v_out The difference vector
 * @param[in] v_a The minuend vector
 * @param[in] v_b The subtrahend vector
 */
LAC_DECL void lac_subtract_vec3(vec3 v_out, const vec3 v_a, const vec3 v_b) {
    v_out[0] = v_a[0] - v_b[0];
    v_out[1] = v_a[1] - v_b[1];
    v_out[2] = v_a[2] - v_b[2];
}

/**
 * @brief Calculates the difference between two vectors of length 4.
 * @since 17-10-2023
 * @param[out] v_out The difference vector
 * @param[in] v_a The minuend vector
 * @param[in] v_b The subtrahend vector
 */
LAC_DECL void lac_subtract_vec4(vec4 v_out, const vec4 v_a, const vec4 v_b) {
    v_out[0] = v_a[0] - v_b[0];
    v_out[1] = v_a[1] - v_b[1];
    v_out[2] = v_a[2] - v_b[2];
    v_out[3] = v_a[3] - v_b[3];
}

/**
 * @brief Scales a vector of length 2 by a factor of __scalar__.
 * @since 19-10-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the multiplier
 */
LAC_DECL void lac_multiply_vec2(vec2 v_out, const vec2 v_in, const float scalar) {
    v_out[0] = v_in[0] * scalar;
    v_out[1] = v_in[1] * scalar;
}

/**
 * @brief Scales a vector of length 3 by a factor of __scalar__.
 * @since 19-10-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the multiplier
 */
LAC_DECL void lac_multiply_vec3(vec3 v_out, const vec3 v_in, const float scalar) {
    v_out[0] = v_in[0] * scalar;
    v_out[1] = v_in[1] * scalar;
    v_out[2] = v_in[2] * scalar;
}

/**
 * @brief Scales a vector of length 4 by a factor of __scalar__.
 * @since 19-10-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the multiplier
 */
LAC_DECL void lac_multiply_vec4(vec4 v_out, const vec4 v_in, const float scalar) {
    v_out[0] = v_in[0] * scalar;
    v_out[1] = v_in[1] * scalar;
    v_out[2] = v_in[2] * scalar;
    v_out[3] = v_in[3] * scalar;
}

/**
 * @brief Multiplies a 2x2 matrix by a vector of length 2.
 * @since 22-10-2023
 * @param[out] v_out The product vector
 * @param[in] v_in The input vector
 * @param[in] m_in The input matrix
 */
LAC_DECL void lac_multiply_vec2_mat2(vec2 v_out, const vec2 v_in, const mat2 m_in) {
    vec2 _v_out = { 0 };

#if LAC_IS_ROW_MAJOR
    _v_out[0] = (m_in[0] * v_in[0]) + (m_in[1] * v_in[1]);
    _v_out[1] = (m_in[2] * v_in[0]) + (m_in[3] * v_in[1]);
#else
    _v_out[0] = (m_in[0] * v_in[0]) + (m_in[2] * v_in[1]);
    _v_out[1] = (m_in[1] * v_in[0]) + (m_in[3] * v_in[1]);
#endif

    memcpy(v_out, _v_out, sizeof(vec2));
}

/**
 * @brief Multiplies a 3x3 matrix by a vector of length 3.
 * @since 22-10-2023
 * @param[out] v_out The product vector
 * @param[in] v_in The input vector
 * @param[in] m_in The input matrix
 */
LAC_DECL void lac_multiply_vec3_mat3(vec3 v_out, const vec3 v_in, const mat3 m_in) {
    vec3 _v_out = { 0 };

#if LAC_IS_ROW_MAJOR
    _v_out[0] = (m_in[0] * v_in[0]) + (m_in[1] * v_in[1]) + (m_in[2] * v_in[2]);
    _v_out[1] = (m_in[3] * v_in[0]) + (m_in[4] * v_in[1]) + (m_in[5] * v_in[2]);
    _v_out[2] = (m_in[6] * v_in[0]) + (m_in[7] * v_in[1]) + (m_in[8] * v_in[2]);
#else
    _v_out[0] = (m_in[0] * v_in[0]) + (m_in[3] * v_in[1]) + (m_in[6] * v_in[2]);
    _v_out[1] = (m_in[1] * v_in[0]) + (m_in[4] * v_in[1]) + (m_in[7] * v_in[2]);
    _v_out[2] = (m_in[2] * v_in[0]) + (m_in[5] * v_in[1]) + (m_in[8] * v_in[2]);
#endif

    memcpy(v_out, _v_out, sizeof(vec3));
}

/**
 * @brief Multiplies a 4x4 matrix by a vector of length 4.
 * @since 22-10-2023
 * @param[out] v_out The product vector
 * @param[in] v_in The input vector
 * @param[in] m_in The input matrix
 */
LAC_DECL void lac_multiply_vec4_mat4(vec4 v_out, const vec4 v_in, const mat4 m_in) {
    vec4 _v_out = { 0 };

#if LAC_IS_ROW_MAJOR
    _v_out[0] = (m_in[0]  * v_in[0]) + (m_in[1]  * v_in[1]) + (m_in[2]  * v_in[2]) + (m_in[3]  * v_in[3]);
    _v_out[1] = (m_in[4]  * v_in[0]) + (m_in[5]  * v_in[1]) + (m_in[6]  * v_in[2]) + (m_in[7]  * v_in[3]);
    _v_out[2] = (m_in[8]  * v_in[0]) + (m_in[9]  * v_in[1]) + (m_in[10] * v_in[2]) + (m_in[11] * v_in[3]);
    _v_out[3] = (m_in[12] * v_in[0]) + (m_in[13] * v_in[1]) + (m_in[14] * v_in[2]) + (m_in[15] * v_in[3]);
#else
    _v_out[0] = (m_in[0] * v_in[0]) + (m_in[4] * v_in[1]) + (m_in[8]  * v_in[2]) + (m_in[12] * v_in[3]);
    _v_out[1] = (m_in[1] * v_in[0]) + (m_in[5] * v_in[1]) + (m_in[9]  * v_in[2]) + (m_in[13] * v_in[3]);
    _v_out[2] = (m_in[2] * v_in[0]) + (m_in[6] * v_in[1]) + (m_in[10] * v_in[2]) + (m_in[14] * v_in[3]);
    _v_out[3] = (m_in[3] * v_in[0]) + (m_in[7] * v_in[1]) + (m_in[11] * v_in[2]) + (m_in[15] * v_in[3]);
#endif

    memcpy(v_out, _v_out, sizeof(vec4));
}

/**
 * @brief Reduces a vector of length 2 by a factor of __scalar__.
 * @since 19-10-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the divisor
 */
LAC_DECL void lac_divide_vec2(vec2 v_out, const vec2 v_in, const float scalar) {
    if (scalar == 0.0f) {
        LAC_LOG("Attempted divide by 0", LAC_WARNING);
        v_out[0] = 0.0f;
        v_out[1] = 0.0f;
    } else {
        v_out[0] = v_in[0] / scalar;
        v_out[1] = v_in[1] / scalar;
    }
}

/**
 * @brief Reduces a vector of length 3 by a factor of __scalar__.
 * @since 19-10-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the divisor
 */
LAC_DECL void lac_divide_vec3(vec3 v_out, const vec3 v_in, const float scalar) {
    if (scalar == 0.0f) {
        LAC_LOG("Attempted divide by 0", LAC_WARNING);
        v_out[0] = 0.0f;
        v_out[1] = 0.0f;
        v_out[2] = 0.0f;
    } else {
        v_out[0] = v_in[0] / scalar;
        v_out[1] = v_in[1] / scalar;
        v_out[2] = v_in[2] / scalar;
    }
}

/**
 * @brief Reduces a vector of length 4 by a factor of __scalar__.
 * @since 19-10-2023
 * @param[out] v_out The scaled vector
 * @param[in] v_in The vector to be scaled
 * @param[in] scalar A constant representing the divisor
 */
LAC_DECL void lac_divide_vec4(vec4 v_out, const vec4 v_in, const float scalar) {
    if (scalar == 0.0f) {
        LAC_LOG("Attempted divide by 0", LAC_WARNING);
        v_out[0] = 0.0f;
        v_out[1] = 0.0f;
        v_out[2] = 0.0f;
        v_out[3] = 0.0f;
    } else {
        v_out[0] = v_in[0] / scalar;
        v_out[1] = v_in[1] / scalar;
        v_out[2] = v_in[2] / scalar;
        v_out[3] = v_in[3] / scalar;
    }
}

/**
 * @brief Calculates the dot product given two vectors of length 2.
 * @anchor lac_calc_dot_prod_vec2_anchor
 * @since 17-10-2023
 * @param[out] dot_prod The scalar value
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 */
LAC_DECL void lac_calc_dot_prod_vec2(float *dot_prod, const vec2 v_a, const vec2 v_b) {
    *dot_prod = (v_a[0] * v_b[0]) + (v_a[1] * v_b[1]);
}

/**
 * @brief Calculates the dot product given two vectors of length 3.
 * @anchor lac_calc_dot_prod_vec3_anchor
 * @since 17-10-2023
 * @param[out] dot_prod The scalar value
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 */
LAC_DECL void lac_calc_dot_prod_vec3(float *dot_prod, const vec3 v_a, const vec3 v_b) {
    *dot_prod = (v_a[0] * v_b[0]) + (v_a[1] * v_b[1]) + (v_a[2] * v_b[2]);
}

/**
 * @brief Calculates the dot product given two vectors of length 4.
 * @anchor lac_calc_dot_prod_vec4_anchor
 * @since 17-10-2023
 * @param[out] dot_prod The scalar value
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 */
LAC_DECL void lac_calc_dot_prod_vec4(float *dot_prod, const vec4 v_a, const vec4 v_b) {
    *dot_prod = (v_a[0] * v_b[0]) + (v_a[1] * v_b[1]) + (v_a[2] * v_b[2]) + (v_a[3] * v_b[3]);
}

/**
 * @brief Calculates the cross product given two vectors of length 3.
 * @anchor lac_calc_cross_prod_anchor
 * @since 17-10-2023
 * @param[out] v_out The resulting vector, orthogonal to v_a and v_b
 * @param[in] v_a The left-hand operand for the operation
 * @param[in] v_b The right-hand operand for the operation
 */
LAC_DECL void lac_calc_cross_prod(vec3 v_out, const vec3 v_a, const vec3 v_b) {
    vec3 _v_out = { 0 };

    _v_out[0] = (v_a[1] * v_b[2]) - (v_a[2] * v_b[1]);
    _v_out[1] = (v_a[2] * v_b[0]) - (v_a[0] * v_b[2]);
    _v_out[2] = (v_a[0] * v_b[1]) - (v_a[1] * v_b[0]);

    memcpy(v_out, _v_out, sizeof(vec3));
}

/**
 * @brief Calculates the magnitude for a given vector of length 2.
 * @since 10-12-2023
 * @param[out] magnitude The calculated magnitude
 * @param[in] v_in The vector for which the magnitude is calculated
 */
LAC_DECL void lac_calc_magnitude_vec2(float *magnitude, const vec2 v_in) {
    *magnitude = sqrtf((v_in[0] * v_in[0]) + (v_in[1] * v_in[1]));
}

/**
 * @brief Calculates the magnitude for a given vector of length 3.
 * @since 10-12-2023
 * @param[out] magnitude The calculated magnitude
 * @param[in] v_in The vector for which the magnitude is calculated
 */
LAC_DECL void lac_calc_magnitude_vec3(float *magnitude, const vec3 v_in) {
    *magnitude = sqrtf((v_in[0] * v_in[0]) + (v_in[1] * v_in[1]) + (v_in[2] * v_in[2]));
}

/**
 * @brief Calculates the magnitude for a given vector of length 4.
 * @since 10-12-2023
 * @param[out] magnitude The calculated magnitude
 * @param[in] v_in The vector for which the magnitude is calculated
 */
LAC_DECL void lac_calc_magnitude_vec4(float *magnitude, const vec4 v_in) {
    *magnitude = sqrtf((v_in[0] * v_in[0]) + (v_in[1] * v_in[1]) + (v_in[2] * v_in[2]) + (v_in[3] * v_in[3]));
}

/**
 * @brief Normalize a vector of length 2.
 * @anchor lac_normalize_vec2_anchor
 * @since 17-10-2023
 * @param[out] v_out The normalized vector
 * @param[in] v_in The vector to be normalized
 */
LAC_DECL void lac_normalize_vec2(vec2 v_out, const vec2 v_in) {
    float magnitude, inv_magnitude;

    lac_calc_magnitude_vec2(&magnitude, v_in);
    if (magnitude != 0.0f) {
        inv_magnitude = 1.0f / magnitude;
        v_out[0] = v_in[0] * inv_magnitude;
        v_out[1] = v_in[1] * inv_magnitude;
    } else {
        v_out[0] = 0.0f;
        v_out[1] = 0.0f;
    }
}

/**
 * @brief Normalize a vector of length 3.
 * @anchor lac_normalize_vec3_anchor
 * @since 17-10-2023
 * @param[out] v_out The normalized vector
 * @param[in] v_in The vector to be normalized
 */
LAC_DECL void lac_normalize_vec3(vec3 v_out, const vec3 v_in) {
    float magnitude, inv_magnitude;

    lac_calc_magnitude_vec3(&magnitude, v_in);
    if (magnitude != 0.0f) {
        inv_magnitude = 1.0f / magnitude;
        v_out[0] = v_in[0] * inv_magnitude;
        v_out[1] = v_in[1] * inv_magnitude;
        v_out[2] = v_in[2] * inv_magnitude;
    } else {
        v_out[0] = 0.0f;
        v_out[1] = 0.0f;
        v_out[2] = 0.0f;
    }
}

/**
 * @brief Normalize a vector of length 4.
 * @anchor lac_normalize_vec4_anchor
 * @since 17-10-2023
 * @param[out] v_out The normalized vector
 * @param[in] v_in The vector to be normalized
 */
LAC_DECL void lac_normalize_vec4(vec4 v_out, const vec4 v_in) {
    float magnitude, inv_magnitude;

    lac_calc_magnitude_vec4(&magnitude, v_in);
    if (magnitude != 0.0f) {
        inv_magnitude = 1.0f / magnitude;
        v_out[0] = v_in[0] * inv_magnitude;
        v_out[1] = v_in[1] * inv_magnitude;
        v_out[2] = v_in[2] * inv_magnitude;
        v_out[3] = v_in[3] * inv_magnitude;
    } else {
        v_out[0] = 0.0f;
        v_out[1] = 0.0f;
        v_out[2] = 0.0f;
        v_out[3] = 0.0f;
    }
}

/**
 * @brief Convert polar coordinates given by __angle__ and __len__ to cartesian space.
 * @anchor lac_polar_to_cartesian_anchor
 * @since 24-09-2024
 * @param[out] v_out A vector which represents the conversion to cartesian coordinates
 * @param[in] len The radial coordinate
 * @param[in] angle The angular coordinate (given in radians)
 */
LAC_DECL void lac_polar_to_cartesian(vec2 v_out, const float len, const float angle) {
    v_out[0] = len * cosf(angle);
    v_out[1] = len * sinf(angle);
}

/**
 * @brief Convert cartesian coordinates given by __v_in__ to polar coordinates.
 * @anchor lac_cartesian_to_polar_anchor
 * @since 24-09-2024
 * @param[out] len The radial coordinate
 * @param[out] angle The angular coordinate (given in radians)
 * @param[in] v_in A vector which represents the cartesian coordinates being converted
 */
LAC_DECL void lac_cartesian_to_polar(float* restrict len, float* restrict angle, const vec2 v_in) {
    lac_calc_magnitude_vec2(len, v_in);
    *angle = atan2f(v_in[1], v_in[0]);
}
