#ifndef MATMATH_H
#define MATMATH_H

#include "common.h"
#include "matrices.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define lac_PI 3.14159265358979323846264338327950288f
#define lac_deg_to_rad(a) ((a) * lac_PI / 180.0f)
#define lac_rad_to_deg(a) ((a) * 180.0f / lac_PI)

/* Forward function declarations */
LAC_DECL mat2 *lac_dot_prod_mat2(const mat2 m1, const mat2 m2);
LAC_DECL mat3 *lac_dot_prod_mat3(const mat3 m1, const mat3 m2);
LAC_DECL mat4 *lac_dot_prod_mat4(const mat4 m1, const mat4 m2);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MATMATH_H */

