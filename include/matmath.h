#ifndef MATMATH_H
#define MATMATH_H

#include "lac_common.h"

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

void lac_transpose_mat2(mat2 *m_out, const mat2 m_in);
void lac_transpose_mat3(mat3 *m_out, const mat3 m_in);
void lac_transpose_mat4(mat4 *m_out, const mat4 m_in);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MATMATH_H */

