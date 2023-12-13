#ifndef MATRICES_H
#define MATRICES_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern mat4 lac_ident_mat4;
extern mat4 lac_ortho_proj_mat4;

/* Forward function declarations */

void lac_get_reflection_mat4(mat4 *m_out, const bool yz_plane, const bool xz_plane, const bool xy_plane);
void lac_get_translation_mat4(mat4 *m_out, const float tx, const float ty, const float tz);
void lac_get_scalar_mat4(mat4 *m_out, const float sx, const float sy, const float sz);
void lac_get_yaw_mat4(mat4 *m_out, const float yaw);
void lac_get_pitch_mat4(mat4 *m_out, const float pitch);
void lac_get_roll_mat4(mat4 *m_out, const float roll);
void lac_get_rotation_mat4(mat4 *m_out, const float rx, const float ry, const float rz);
void lac_get_projection_mat4(mat4 *m_out, const float aspect, const float fov, const float znear, const float zfar);
void lac_get_point_at_mat4(mat4 *m_out, const vec3 v_eye, const vec3 v_target, const vec3 v_up);
void lac_invert_mat4(mat4 *m_out, const mat4 m_in);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MATRICES_H */
