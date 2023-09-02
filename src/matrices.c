#include "../include/matmath.h"

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

mat4 rot_mat_x = {
   1,    0,    0,    0,
   0,    1,    0,    0,
   0,    0,    1,    0,
   0,    0,    0,    1
};

mat4 rot_mat_y = {
   1,    0,    0,    0,
   0,    1,    0,    0,
   0,    0,    1,    0,
   0,    0,    0,    1
};

mat4 rot_mat_z = {
   1,    0,    0,    0,
   0,    1,    0,    0,
   0,    0,    1,    0,
   0,    0,    0,    1
};

static void _lac_bind_trn_mat(float tx, float ty, float tz) {
   mat4 tmp = {
      1,    0,    0,    tx,
      0,    1,    0,    ty,
      0,    0,    1,    tz,
      0,    0,    0,    1
   };

   memmove(trn_mat, tmp, sizeof(trn_mat));
}

LAC_DECL mat4 *lac_translate_mat4(mat4 m, float tx, float ty, float tz) {
   _lac_bind_trn_mat(tx, ty, tz);
   return lac_dot_prod_mat4(m, trn_mat);
}

static void _lac_bind_scl_mat(float sx, float sy, float sz) {
   mat4 tmp = {
      sx,   0,    0,    0,
      0,    sy,   0,    0,
      0,    0,    sz,   0,
      0,    0,    0,    1
   };

   memmove(scl_mat, tmp, sizeof(scl_mat));
}

LAC_DECL mat4 *lac_scale_mat4(mat4 m, float sx, float sy, float sz) {
   _lac_bind_scl_mat(sx, sy, sz);
   return lac_dot_prod_mat4(m, scl_mat);
}

/* TODO: Make these accept custom cos and sin funcs */

static void _lac_bind_rot_mat_x(float r) {
   mat4 tmp = {
      1,    0,          0,          0,
      0,    cosf(r),   -sinf(r),    0,
      0,    sinf(r),    cosf(r),    0,
      0,    0,          0,          1
   };

   memmove(rot_mat_x, tmp, sizeof(rot_mat_x));
}

static void _lac_bind_rot_mat_y(float r) {
   mat4 tmp = {
      cosf(r),    0,    sinf(r),    0,
      0,          1,    0,          0,
     -sinf(r),    0,    cosf(r),    0,
      0,          0,    0,          1
   };

   memmove(rot_mat_y, tmp, sizeof(rot_mat_y));
}

static void _lac_bind_rot_mat_z(float r) {
   mat4 tmp = {
      cosf(r),   -sinf(r),    0,    0,
      sinf(r),    cosf(r),    0,    0,
      0,          0,          1,    0,
      0,          0,          0,    1
   };

   memmove(rot_mat_z, tmp, sizeof(rot_mat_z));
}

LAC_DECL mat4 *lac_rotate_mat4(mat4 m, float rx, float ry, float rz) {
   mat4 *tmp = NULL;

   _lac_bind_rot_mat_x(rx);
   _lac_bind_rot_mat_y(ry);
   _lac_bind_rot_mat_z(rz);

   tmp = lac_dot_prod_mat4(m, rot_mat_x);
   tmp = lac_dot_prod_mat4(*tmp, rot_mat_y);
   tmp = lac_dot_prod_mat4(*tmp, rot_mat_z);

   return tmp;
}
