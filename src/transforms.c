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
   sin_rx = sin(rx);
   cos_ry = cosf(ry);
   sin_ry = sin(ry);
   cos_rz = cosf(rz);
   sin_rz = sin(rz);

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
