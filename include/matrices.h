#ifndef MATRICES_H
#define MATRICES_H

#include "common.h"

typedef float mat2[4];
typedef float mat3[9];
typedef float mat4[16];

extern mat4 rot_mat_x;
extern mat4 rot_mat_y;
extern mat4 rot_mat_z;

extern mat4 trn_mat_x;
extern mat4 trn_mat_y;
extern mat4 trn_mat_z;

extern mat4 scl_mat_x;
extern mat4 scl_mat_y;
extern mat4 scl_mat_z;

LAC_DECL mat2 *dot_prod_mat2(const mat2 m1, const mat2 m2);
LAC_DECL mat3 *dot_prod_mat3(const mat3 m1, const mat3 m2);
LAC_DECL mat4 *dot_prod_mat4(const mat4 m1, const mat4 m2);

#endif /* MATRICES_H */
