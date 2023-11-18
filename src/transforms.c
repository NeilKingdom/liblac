#include "../include/matmath.h"

/* TODO: Use custom cosf and sinf functions */

/*
   "Geometry provides us with four types of transformations,
   namely, rotation, reflection, translation, and resizing."
*/

mat4 lac_ident_mat4 = {
   1,   0,   0,   0,
   0,   1,   0,   0,
   0,   0,   1,   0,
   0,   0,   0,   1
};

mat4 lac_ortho_proj_mat4 = {
   1,   0,   0,   0,
   0,   1,   0,   0, 
   0,   0,   0,   0, 
   0,   0,   0,   1
};

LAC_DECL void lac_get_reflection_mat4(mat4 * restrict m_out, const bool yz_plane, const bool xz_plane, const bool xy_plane) {
   if (!yz_plane && !xz_plane && !xy_plane) return;

   /* Flip sign for axes that should be reflected */
   if (yz_plane) {
      (*m_out)[0] = -1;
   }
   if (xz_plane) {
      (*m_out)[5] = -1;
   }
   if (xy_plane) {
      (*m_out)[10] = -1;
   }
}

LAC_DECL void lac_get_translation_mat4(mat4 * restrict m_out, const float tx, const float ty, const float tz) {
   mat4 trn_mat = {
      1,    0,    0,    tx,
      0,    1,    0,    ty,
      0,    0,    1,    tz,
      0,    0,    0,    1
   };

   memcpy(m_out, trn_mat, sizeof(*m_out));
}

LAC_DECL void lac_get_scalar_mat4(mat4 * restrict m_out, const float sx, const float sy, const float sz) {
   mat4 scl_mat = {
      sx,   0,    0,    0,
      0,    sy,   0,    0,
      0,    0,    sz,   0,
      0,    0,    0,    1
   };

   memcpy(m_out, scl_mat, sizeof(*m_out));
}

LAC_DECL void lac_get_rotation_mat4(mat4 * restrict m_out, const float rx, const float ry, const float rz) {
   float cos_rx, sin_rx, cos_ry, sin_ry, cos_rz, sin_rz;

   cos_rx = cosf(rx);
   sin_rx = sinf(rx);
   cos_ry = cosf(ry);
   sin_ry = sinf(ry);
   cos_rz = cosf(rz);
   sin_rz = sinf(rz);

   mat4 rot_mat = { 0 };

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

   /* Get the final rotation matrix by obtaining dot product of yaw * pitch * roll */
   lac_multiply_mat4(yaw_mat, pitch_mat, &rot_mat);
   lac_multiply_mat4(rot_mat, roll_mat, m_out);
}

/*  
 ************************** Look At Matrix ***************************
 *
 * Traditionally, the "look-at" matrix represents our view into world
 * space in 3D graphics. We typically follow the Model-View-Projection
 * (MVP) pattern. In this pattern, we start by translating our entities
 * into world space via the model matrix. The model matrix can be an 
 * amalgamation of transformation matrices. Next, we translate into 
 * view space, which is typically done through the look-at matrix. 
 * Finally, we translate to projection space via our projection matrix. 
 * The two main kinds of projection are orthogonal projection and 
 * frustum projection. The look at matrix uses some terminology which 
 * may be confusing to those who have never heard of it. Let us 
 * consider a point within 3D space. This will be the origin of our 
 * camera. This origin point is referred to as the "eye" point. 
 * Confusingly, the center vector represents the position in 3D space
 * where the camera is focused towards. An up vector is also required
 * to determine orienation of the camera, since our graphics libraries
 * cannot assume that the camera is always facing upright (it could
 * very well be upside-down). From these three vectors, we can calculate 
 * what we actually care about, which are the forward, right, and up 
 * vectors, which we normalize so that we can place them within our 
 * view matrix to be later multiplied with the entities in world space.
*/

/**
 *
 */
LAC_DECL void lac_get_look_at_mat4(mat4 *m_out, const vec3 eye, const vec3 center, const vec3 up) {
   vec3 forward_unit;
   vec3 right_unit;
   vec3 up_unit;
   vec3 result;

   // Calculate forward_unit
   lac_subtract_vec3(center, eye, &result);
   lac_normalize_vec3(result, &forward_unit);

   // Calculate right_unit
   lac_calc_cross_prod(up, forward_unit, &result);
   lac_normalize_vec3(result, &right_unit);

   // Calculate up_unit
   lac_calc_cross_prod(forward_unit, right_unit, &result);
   lac_normalize_vec3(result, &up_unit);

   mat4 look_at = {
      right_unit[0], up_unit[0], -forward_unit[0], eye[0],
      right_unit[1], up_unit[1], -forward_unit[1], eye[1],
      right_unit[2], up_unit[2], -forward_unit[2], eye[2],
      0,             0,          0,                1
   };

   memcpy(m_out, look_at, sizeof(*m_out));
}

LAC_DECL void lac_get_projection_mat4(mat4 *m_out, const float aspect, const float fov, const float znear, const float zfar) {
   mat4 proj_mat = {
      (aspect * (1.0f / tanf(fov / 2.0f))), 0, 0, 0,
      0, (1.0f / tanf(fov / 2.0f)), 0, 0,
      0, 0, (zfar / (zfar - znear)), 1,
      0, 0, ((-zfar * znear) / (zfar - znear)), 0
   };

   memcpy(m_out, proj_mat, sizeof(*m_out));
}
