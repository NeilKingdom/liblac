#ifndef MATMATH_H
#define MATMATH_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Forward function declarations */

void lac_add_mat2(const mat2 m_a, const mat2 m_b, mat2 *m_out);
void lac_add_mat3(const mat3 m_a, const mat3 m_b, mat3 *m_out);
void lac_add_mat4(const mat4 m_a, const mat4 m_b, mat4 *m_out);

void lac_multiply_mat2(const mat2 m_a, const mat2 m_b, mat2 *m_out);
void lac_multiply_mat3(const mat3 m_a, const mat3 m_b, mat3 *m_out);
void lac_multiply_mat4(const mat4 m_a, const mat4 m_b, mat4 *m_out);

void lac_transpose_mat2(const mat2 m_in, mat2 *m_out);
void lac_transpose_mat3(const mat3 m_in, mat3 *m_out);
void lac_transpose_mat4(const mat4 m_in, mat4 *m_out);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MATMATH_H */

