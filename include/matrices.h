#ifndef MATRICES_H
#define MATRICES_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef float mat2[4];
typedef float mat3[9];
typedef float mat4[16];

extern float Tx, Ty, Tz;
extern float Sx, Sy, Sz;

extern mat4 rot_mat_x;
extern mat4 rot_mat_y;
extern mat4 rot_mat_z;
extern mat4 trn_mat;
extern mat4 scl_mat;

/* Forward function declarations */
LAC_DECL mat4 *lac_translate_mat4(mat4 m, float tx, float ty, float tz);
LAC_DECL mat4 *lac_scale_mat4(mat4 m, float sx, float sy, float sz);
LAC_DECL mat4 *lac_rotate_mat4(mat4 m, float rx, float ry, float rz);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MATRICES_H */
