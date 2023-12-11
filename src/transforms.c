/**
 * @file transforms.c
 * @author Neil Kingdom
 * @since 10-17-2023
 * @brief transforms.c provides functions for transforming matrices
 * 
 * "Geometry provides us with four types of transformations,
 * namely, rotation, reflection, translation, and resizing."
 *
 * @section pointat Point-At Matrix
 *
 * Cameras can be controlled in a few ways. One method is to have a 
 * static camera, which never actually moves. Instead, we translate and 
 * rotate every object in the scene/world around the camera to give the 
 * illusion of movement. This method has certain benefits, but is 
 * generally avoided in 3D graphics. The reason being is that when we 
 * translate an object in world space, its origin point suddenly changes.
 * In order to now apply rotation, each object must first be translated
 * to the original origin point, then rotated, then translated back to 
 * its previous location. A secondary approach is to use angles to 
 * describe rotation. This approach, however, becomes increasingly 
 * cumbersome, as it is quite difficult to have precise movement when
 * you have to guess at the number of degrees to rotate the camera in 
 * for all directions. The traditional method of moving our camera is 
 * to use a point-at matrix. In this scenario, we pass a point that we 
 * want to have the camera point towards, as well as a vector representing
 * the direction that the camera is currently looking at, and then we 
 * calculate a new point-at vector which shares the same origin point 
 * as our current point-at vector, but which now has a direction facing 
 * the point that we passed. Instead of returning just one vector, 
 * however, we return a matrix consisting of 3 unit vectors representing 
 * the cardinal directions. This ensures that the orientation of our 
 * camera is correct. Traditionally, we call these the up, forward, and 
 * right vectors, and the origin point of our matrix, we call our eye 
 * point. 
 *
 * @subsection pointat_related Related Functions
 *
 * - @ref lac_get_point_at_mat4_anchor "lac_get_point_at_mat4"
 * - @ref lac_invert_mat4_anchor "lac_invert_mat4"
 */

#include "../include/matmath.h"
#include "../include/vecmath.h"

/**
 * The identity matrix is a special matrix that is essentially 
 * equivallent to multiplying by 1 in regular multiplication. This makes
 * it a good basic starting point for matrix transformations through 
 * matrix multiplication.  
 */
mat4 lac_ident_mat4 = {
    1,   0,   0,   0,
    0,   1,   0,   0,
    0,   0,   1,   0,
    0,   0,   0,   1
};

/**
 * An orthographic projection matrix is a projection matrix that creates a 
 * 1:1 mapping from world space to screen space in terms of vertex coordinates.
 */
mat4 lac_ortho_proj_mat4 = {
    1,   0,   0,   0,
    0,   1,   0,   0, 
    0,   0,   0,   0, 
    0,   0,   0,   1
};

/**
 * @brief This function reflects a matrix along one or more planes
 * @since 10-17-2023 
 * @param[out] m_out A reflection matrix that can be applied through matrix multiplication
 * @param[in] yz_plane If set to true, reflection is applied about the y-z plane
 * @param[in] xz_plane If set to true, reflection is applied about the x-z plane
 * @param[in] xy_plane If set to true, reflection is applied about the x-y plane
 */
LAC_DECL void lac_get_reflection_mat4(
    mat4 * restrict m_out, 
    const bool yz_plane, 
    const bool xz_plane, 
    const bool xy_plane
) {
    mat4 ref_mat = { 0 };
    memcpy(ref_mat, lac_ident_mat4, sizeof(*ref_mat));

    /* Flip sign for axes that should be reflected */
#if LAC_IS_ROW_MAJOR
#else
    if (yz_plane) {
        ref_mat[0] = -1;
    }
    if (xz_plane) {
        ref_mat[5] = -1;
    }
    if (xy_plane) {
        ref_mat[10] = -1;
    }
#endif

    memcpy(m_out, ref_mat, sizeof(*m_out));
}

/**
 * @brief Gets a translation matrix according to the input parameters
 * @since 10-17-2023
 * @param[out] The translation matrix which can be applied through matrix multiplication
 * @param[in] tx Arbitrary unit for translation in the x-direction
 * @param[in] ty Arbitrary unit for translation in the y-direction
 * @param[in] tz Arbitrary unit for translation in the z-direction
 */
LAC_DECL void lac_get_translation_mat4(
    mat4 * restrict m_out, 
    const float tx, 
    const float ty, 
    const float tz
) {
#if LAC_IS_ROW_MAJOR
#else
    mat4 trn_mat = {
        1,    0,    0,    tx,
        0,    1,    0,    ty,
        0,    0,    1,    tz,
        0,    0,    0,    1
    };
#endif

    memcpy(m_out, trn_mat, sizeof(*m_out));
}

/**
 * @brief Gets a scalar matrix according to the input parameters
 * @since 10-17-2023
 * @param[out] The scalar matrix which can be applied through matrix multiplication
 * @param[in] sx Arbitrary unit for scaling in the x-direction
 * @param[in] sy Arbitrary unit for scaling in the y-direction
 * @param[in] sz Arbitrary unit for scaling in the z-direction
 */
LAC_DECL void lac_get_scalar_mat4(
    mat4 * restrict m_out, 
    const float sx, 
    const float sy, 
    const float sz
) {
#if LAC_IS_ROW_MAJOR
#else
    mat4 scl_mat = {
        sx,   0,    0,    0,
        0,    sy,   0,    0,
        0,    0,    sz,   0,
        0,    0,    0,    1
    };
#endif

    memcpy(m_out, scl_mat, sizeof(*m_out));
}

/**
 * @brief Gets a rotation matrix according to the input angles for each axis
 * @since 10-17-2023
 * @param[out] m_out The rotation matrix which can be applied through matrix multiplication
 * @param[in] rx Rotation angle in the x-axis (given in radians)
 * @param[in] ry Rotation angle in the y-axis (given in radians)
 * @param[in] rz Rotation angle in the z-axis (given in radians)
 */
LAC_DECL void lac_get_rotation_mat4(
    mat4 * restrict m_out, 
    const float rx, 
    const float ry, 
    const float rz
) {
    float cos_rx, sin_rx, cos_ry, sin_ry, cos_rz, sin_rz;

    cos_rx = cosf(rx);
    sin_rx = sinf(rx);
    cos_ry = cosf(ry);
    sin_ry = sinf(ry);
    cos_rz = cosf(rz);
    sin_rz = sinf(rz);

    mat4 rot_mat = { 0 };

#if LAC_IS_ROW_MAJOR
#else
    mat4 yaw_mat = {
        cos_rz,  -sin_rz,   0,    0,
        sin_rz,   cos_rz,   0,    0,
        0,        0,        1,    0,
        0,        0,        0,    1
    };

    mat4 pitch_mat = {
        cos_ry,   0,    sin_ry,   0,
        0,        1,    0,        0,
        -sin_ry,   0,    cos_ry,   0,
        0,        0,    0,        1
    };

    mat4 roll_mat = {
        1,    0,        0,        0,
        0,    cos_rx,  -sin_rx,   0,
        0,    sin_rx,   cos_rx,   0,
        0,    0,        0,        1
    };
#endif

    /* Get the final rotation matrix by obtaining dot product of yaw * pitch * roll */
    lac_multiply_mat4(&rot_mat, yaw_mat, pitch_mat);
    lac_multiply_mat4(m_out, rot_mat, roll_mat);
}

/**
 * @brief Gets a normalized point-at matrix 
 * @anchor lac_get_point_at_mat4_anchor
 * @since 10-20-2023
 * @param[out] m_out The point-at matrix 
 * @param[in] v_eye A vector representing the origin of the camera
 * @param[in] v_target A vector representing the target point in 3D space for the camera to point towards
 * @param[in] v_up A vector representing the "up" direction (used for camera orientation)
 */
LAC_DECL void lac_get_point_at_mat4(
    mat4 * restrict m_out, 
    const vec3 v_eye, 
    const vec3 v_target, 
    const vec3 v_up
) {
    vec3 forward_unit, right_unit, up_unit, v_res;
    float dot_prod;

    // Calculate forward_unit
    lac_subtract_vec3(&v_res, v_target, v_eye);
    lac_normalize_vec3(&forward_unit, v_res);

    // Calculate up_unit
    lac_calc_dot_prod_vec3(&dot_prod, v_up, forward_unit);
    lac_multiply_vec3(&v_res, forward_unit, dot_prod);
    lac_subtract_vec3(&up_unit, v_up, v_res);
    lac_normalize_vec3(&up_unit, up_unit);

    // Calculate right_unit
    lac_calc_cross_prod(&right_unit, up_unit, forward_unit);
    // Normalizing here isn't necessary since forward_unit & up_unit are normals

#if LAC_IS_ROW_MAJOR
#else
    mat4 point_at = {
        right_unit[0], up_unit[0], forward_unit[0], v_eye[0],
        right_unit[1], up_unit[1], forward_unit[1], v_eye[1],
        right_unit[2], up_unit[2], forward_unit[2], v_eye[2],
        0,             0,          0,               1
    };
#endif

    memcpy(m_out, point_at, sizeof(*m_out));
}

/**
 * @brief This function is designed specifically for inverting the point-at matrix
 * @warn This is not a true matrix inversion function; it only works with rotation and translation matrices.
 * @anchor lac_invert_mat4_anchor
 * @since 10-17-2023
 * @param[out] m_out The resulting look-at matrix
 * @param[in] m_in The matrix to be inverted 
 */
LAC_DECL void lac_invert_mat4(mat4 *m_out, const mat4 m_in) {
    float dot_prod;

#if LAC_IS_ROW_MAJOR
#else
    lac_calc_dot_prod_vec3(
        &dot_prod,
        (vec3){ m_in[3], m_in[7], m_in[11] }, 
        (vec3){ m_in[0], m_in[4], m_in[8]  }
    );
    (*m_out)[0]  = m_in[0];
    (*m_out)[1]  = m_in[4];
    (*m_out)[2]  = m_in[8];
    (*m_out)[3]  = -dot_prod;

    lac_calc_dot_prod_vec3(
        &dot_prod,
        (vec3){ m_in[3], m_in[7], m_in[11] }, 
        (vec3){ m_in[1], m_in[5], m_in[9]  }
    );
    (*m_out)[4]  = m_in[1];
    (*m_out)[5]  = m_in[5];
    (*m_out)[6]  = m_in[9];
    (*m_out)[7]  = -dot_prod;

    lac_calc_dot_prod_vec3(
        &dot_prod,
        (vec3){ m_in[3], m_in[7], m_in[11] }, 
        (vec3){ m_in[2], m_in[6], m_in[10] }
    );
    (*m_out)[8]  = m_in[2];
    (*m_out)[9]  = m_in[6];
    (*m_out)[10] = m_in[10];
    (*m_out)[11] = -dot_prod;

    (*m_out)[12] = 0.0f;
    (*m_out)[13] = 0.0f;
    (*m_out)[14] = 0.0f;
    (*m_out)[15] = 1.0f;
#endif
}

/**
 * @brief Returns a frustum projection matrix according to the input parameters
 * @since 10-17-2023
 * @param[out] m_out The resulting projection matrix that can be applied through matrix multiplication
 * @param[in] aspect The aspect ratio of the screen (taken by height/width)
 * @param[in] fov The field of view (given as an angle in degrees)
 * @param[in] The "near" clipping z-plane 
 * @param[in] The "far" clipping z-plane
 */
LAC_DECL void lac_get_projection_mat4(
    mat4 * restrict m_out, 
    const float aspect, 
    const float fov, 
    const float znear, 
    const float zfar
) {
#if LAC_IS_ROW_MAJOR
#else
    mat4 proj_mat = {
        (aspect * (1.0f / tanf(fov / 2.0f))), 0, 0, 0,
        0, (1.0f / tanf(fov / 2.0f)), 0, 0,
        0, 0, (zfar / (zfar - znear)), 1,
        0, 0, ((-zfar * znear) / (zfar - znear)), 0
    };
#endif

    memcpy(m_out, proj_mat, sizeof(*m_out));
}
