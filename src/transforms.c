#include "../include/matmath.h"

/* TODO: Use custom cosf and sinf functions */

/*
   "Geometry provides us with four types of transformations,
   namely, rotation, reflection, translation, and resizing."
*/

/* Define the identity matrix */
mat4 lac_ident_mat4 = {
   1,   0,   0,   0,
   0,   1,   0,   0,
   0,   0,   1,   0,
   0,   0,   0,   1
};

LAC_DECL void lac_get_reflection_mat4(mat4 *m_out, const bool yz_plane, const bool xz_plane, const bool xy_plane) {
   if (!yz_plane && !xz_plane && !xy_plane) return;

   memcpy(m_out, lac_ident_mat4, sizeof(ref_mat));

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

LAC_DECL void lac_get_translation_mat4(mat4 *m_out, const float tx, const float ty, const float tz) {
   mat4 trn_mat = {
      1,    0,    0,    tx,
      0,    1,    0,    ty,
      0,    0,    1,    tz,
      0,    0,    0,    1
   };

   memcpy(m_out, trn_mat, sizeof(*m_out));
}

LAC_DECL void lac_get_scalar_mat4(mat4 *m_out, const float sx, const float sy, const float sz) {
   mat4 scl_mat = {
      sx,   0,    0,    0,
      0,    sy,   0,    0,
      0,    0,    sz,   0,
      0,    0,    0,    1
   };

   memcpy(m_out, scl_mat, sizeof(*m_out));
}

LAC_DECL void lac_get_rotation_mat4(mat4 *m_out, const float rx, const float ry, const float rz) {
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
   lac_dot_prod_mat4(yaw_mat, pitch_mat, &rot_mat);
   lac_dot_prod_mat4(rot_mat, roll_mat, m_out);
}

LAC_DECL void lac_get_look_at_mat4(mat4 *m_out, const vec3 eye, const vec3 center, const vec3 up) {
   vec3 forward_unit;
   vec3 right_unit;
   vec3 up_unit;
   vec3 op_result;

   // Calculate forward_unit
   lac_subtract_vec3(center, eye, &op_result);
   lac_normalize_vec3(op_result, &forward_unit);

   // Calculate right_unit
   lac_cross_prod(up, forward_unit, &op_result);
   lac_normalize_vec3(op_result, &right_unit);

   // Calculate up_unit
   lac_cross_prod(forward_unit, right_unit, &up_unit);

   mat4 view_mat = {
      right_unit[0], up_unit[0], -forward_unit[0], eye[0],
      right_unit[1], up_unit[1], -forward_unit[1], eye[1],
      right_unit[2], up_unit[2], -forward_unit[2], eye[2],
      0,             0,          0,                1
   };

   memcpy(m_out, view_mat, sizeof(*m_out));
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
