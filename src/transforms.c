#include "../include/matmath.h"

/* TODO: angles can stay as floats */

/* Initialize the extern transformation matrices as the identity matrix */

mat4 trn_mat = {
   1,    0,    0,    0,
   0,    1,    0,    0,
   0,    0,    1,    0,
   0,    0,    0,    1
};

mat4 scl_mat = {
   1,    0,    0,    0,
   0,    1,    0,    0,
   0,    0,    1,    0,
   0,    0,    0,    1
};

/* Rotation about the x-axis */
mat4 roll_mat = {
   1,    0,    0,    0,
   0,    1,    0,    0,
   0,    0,    1,    0,
   0,    0,    0,    1
};

/* Rotation about the y-axis */
mat4 pitch_mat = {
   1,    0,    0,    0,
   0,    1,    0,    0,
   0,    0,    1,    0,
   0,    0,    0,    1
};

/* Rotation about the z-axis */
mat4 yaw_mat = {
   1,    0,    0,    0,
   0,    1,    0,    0,
   0,    0,    1,    0,
   0,    0,    0,    1
};

/*
   "Geometry provides us with four types of transformations,
   namely, rotation, reflection, translation, and resizing."
*/

static void _lac_bind_trn_mat(const double tx, const double ty, const double tz) {
   mat4 tmp = {
      1,    0,    0,    tx,
      0,    1,    0,    ty,
      0,    0,    1,    tz,
      0,    0,    0,    1
   };

   memcpy(trn_mat, tmp, sizeof(trn_mat));
}

LAC_DECL void lac_translate_mat4(const mat4 m_in, mat4 *m_out, const double tx, const double ty, const double tz) {
   _lac_bind_trn_mat(tx, ty, tz);
   lac_dot_prod_mat4(m_in, trn_mat, m_out);
}

static void _lac_bind_scl_mat(const double sx, const double sy, const double sz) {
   mat4 tmp = {
      sx,   0,    0,    0,
      0,    sy,   0,    0,
      0,    0,    sz,   0,
      0,    0,    0,    1
   };

   memcpy(scl_mat, tmp, sizeof(scl_mat));
}

LAC_DECL void lac_scale_mat4(const mat4 m_in, mat4 *m_out, const double sx, const double sy, const double sz) {
   _lac_bind_scl_mat(sx, sy, sz);
   lac_dot_prod_mat4(m_in, scl_mat, m_out);
}

/* TODO: Make these accept custom cos and sin funcs */

static void _lac_bind_rot_mat_x(const double r) {
   mat4 tmp = {
      1,    0,          0,          0,
      0,    cos(r),   -sin(r),    0,
      0,    sin(r),    cos(r),    0,
      0,    0,          0,          1
   };

   memcpy(roll_mat, tmp, sizeof(roll_mat));
}

static void _lac_bind_rot_mat_y(const double r) {
   mat4 tmp = {
      cos(r),    0,    sin(r),    0,
      0,          1,    0,          0,
     -sin(r),    0,    cos(r),    0,
      0,          0,    0,          1
   };

   memcpy(pitch_mat, tmp, sizeof(pitch_mat));
}

static void _lac_bind_rot_mat_z(const double r) {
   mat4 tmp = {
      cos(r),   -sin(r),    0,    0,
      sin(r),    cos(r),    0,    0,
      0,          0,          1,    0,
      0,          0,          0,    1
   };

   memcpy(yaw_mat, tmp, sizeof(yaw_mat));
}

LAC_DECL void lac_rotate_mat4(const mat4 m_in, mat4 *m_out, const double rx, const double ry, const double rz) {
   mat4 rot_mat;

   _lac_bind_rot_mat_x(rx);
   _lac_bind_rot_mat_y(ry);
   _lac_bind_rot_mat_z(rz);

   /* Get the final rotation matrix by obtaining dot product of yaw * pitch * roll */
   lac_dot_prod_mat4(roll_mat, pitch_mat, &rot_mat);
   lac_dot_prod_mat4(rot_mat, yaw_mat, &rot_mat);

   /* Get dot product of input matrix and rotation matrix */
   lac_dot_prod_mat4(m_in, rot_mat, m_out);
}
