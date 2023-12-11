#ifndef MATMATH_H
#define MATMATH_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Forward function declarations */

void lac_add_mat2(mat2 *m_out, const mat2 m_a, const mat2 m_b);
void lac_add_mat3(mat3 *m_out, const mat3 m_a, const mat3 m_b);
void lac_add_mat4(mat4 *m_out, const mat4 m_a, const mat4 m_b);

void lac_multiply_mat2(mat2 *m_out, const mat2 m_a, const mat2 m_b);
void lac_multiply_mat3(mat3 *m_out, const mat3 m_a, const mat3 m_b);
void lac_multiply_mat4(mat4 *m_out, const mat4 m_a, const mat4 m_b);

void lac_multiply_mat2_vec2(vec2 *v_out, const mat2 m_in, const vec2 v_in);
void lac_multiply_mat3_vec3(vec3 *v_out, const mat3 m_in, const vec3 v_in);
void lac_multiply_mat4_vec4(vec4 *v_out, const mat4 m_in, const vec4 v_in);

void lac_transpose_mat2(mat2 *m_out, const mat2 m_in);
void lac_transpose_mat3(mat3 *m_out, const mat3 m_in);
void lac_transpose_mat4(mat4 *m_out, const mat4 m_in);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MATMATH_H */

