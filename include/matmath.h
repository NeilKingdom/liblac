#ifndef MATMATH_H
#define MATMATH_H

#include "common.h"
#include "transforms.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define lac_PI 3.14159265358979323846264338327950288f
#define lac_deg_to_rad(a) ((a) * lac_PI / 180.0)
#define lac_rad_to_deg(a) ((a) * 180.0 / lac_PI)

/* Forward function declarations */
LAC_DECL void lac_dot_prod_mat2(const mat2 m_a, const mat2 m_b, mat2 *m_out);
LAC_DECL void lac_dot_prod_mat3(const mat3 m_a, const mat3 m_b, mat3 *m_out);
LAC_DECL void lac_dot_prod_mat4(const mat4 m_a, const mat4 m_b, mat4 *m_out);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MATMATH_H */

