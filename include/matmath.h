#ifndef MATMATH_H
#define MATMATH_H

#include "common.h"
#include "transforms.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define lac_PI 3.14159265358979323846264338327950288
#define lac_deg_to_rad(a) ((a) * lac_PI / 180.0)
#define lac_rad_to_deg(a) ((a) * 180.0 / lac_PI)

/* Forward function declarations */
LAC_DECL void  lac_subtract_vec2(const vec2 v_a, const vec2 v_b, vec2 *v_out);
LAC_DECL void  lac_subtract_vec3(const vec3 v_a, const vec3 v_b, vec3 *v_out);
LAC_DECL void  lac_subtract_vec4(const vec4 v_a, const vec4 v_b, vec4 *v_out);

LAC_DECL float lac_calc_dot_prod_vec2(const vec2 v_a, const vec2 v_b);
LAC_DECL float lac_calc_dot_prod_vec3(const vec3 v_a, const vec3 v_b);
LAC_DECL float lac_calc_dot_prod_vec4(const vec4 v_a, const vec4 v_b);

LAC_DECL void  lac_calc_cross_prod(const vec3 v_a, const vec3 v_b, vec3 *v_out);

LAC_DECL void  lac_normalize_vec2(const vec2 v_in, vec2 *v_out);
LAC_DECL void  lac_normalize_vec3(const vec3 v_in, vec3 *v_out);
LAC_DECL void  lac_normalize_vec4(const vec4 v_in, vec4 *v_out);

LAC_DECL void  lac_add_mat2(const mat2 m_a, const mat2 m_b, mat2 *m_out);
LAC_DECL void  lac_add_mat3(const mat3 m_a, const mat3 m_b, mat3 *m_out);
LAC_DECL void  lac_add_mat4(const mat4 m_a, const mat4 m_b, mat4 *m_out);

LAC_DECL void  lac_multiply_mat2(const mat2 m_a, const mat2 m_b, mat2 *m_out);
LAC_DECL void  lac_multiply_mat3(const mat3 m_a, const mat3 m_b, mat3 *m_out);
LAC_DECL void  lac_multiply_mat4(const mat4 m_a, const mat4 m_b, mat4 *m_out);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MATMATH_H */

