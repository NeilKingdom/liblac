#ifndef MATRICES_H
#define MATRICES_H

#include <stdbool.h>

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern mat4 yaw_mat;
extern mat4 pitch_mat;
extern mat4 roll_mat;
extern mat4 trn_mat;
extern mat4 scl_mat;
extern mat4 ref_mat;

/* Forward function declarations */
// TODO: Implement mat3 and mat2
LAC_DECL void lac_get_reflection_mat4(mat4 *m_out, const bool yz_plane, const bool xz_plane, const bool xy_plane);
LAC_DECL void lac_get_translation_mat4(mat4 *m_out, const float tx, const float ty, const float tz);
LAC_DECL void lac_get_scalar_mat4(mat4 *m_out, const float sx, const float sy, const float sz);
LAC_DECL void lac_get_rotation_mat4(mat4 *m_out, const float rx, const float ry, const float rz);
LAC_DECL void lac_get_look_at_mat4(mat4 *m_out, const vec3 eye, const vec3 center, const vec3 up);
LAC_DECL void lac_get_ortho_mat4(mat4 *m_out); // TODO
LAC_DECL void lac_get_projection_mat4(mat4 *m_out, const float aspect, const float fov, const float znear, const float zfar);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MATRICES_H */
