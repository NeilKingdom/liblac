#ifndef MATRICES_H
#define MATRICES_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef double mat2[4];
typedef double mat3[9];
typedef double mat4[16];

extern mat4 roll_mat;
extern mat4 pitch_mat;
extern mat4 yaw_mat;
extern mat4 trn_mat;
extern mat4 scl_mat;

/* Forward function declarations */
LAC_DECL void lac_translate_mat4(const mat4 m_in, mat4 *m_out, const double tx, const double ty, const double tz);
LAC_DECL void lac_scale_mat4(const mat4 m_in, mat4 *m_out, const double sx, const double sy, const double sz);
LAC_DECL void lac_rotate_mat4(const mat4 m_in, mat4 *m_out, const double rx, const double ry, const double rz);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MATRICES_H */
