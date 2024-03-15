#ifndef VECMATH_H
#define VECMATH_H

#include "lac_common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Forward function declarations */

void lac_add_vec2(vec2 *v_out, const vec2 v_a, const vec2 v_b);
void lac_add_vec3(vec3 *v_out, const vec3 v_a, const vec3 v_b);
void lac_add_vec4(vec4 *v_out, const vec4 v_a, const vec4 v_b);

void lac_subtract_vec2(vec2 *v_out, const vec2 v_a, const vec2 v_b);
void lac_subtract_vec3(vec3 *v_out, const vec3 v_a, const vec3 v_b);
void lac_subtract_vec4(vec4 *v_out, const vec4 v_a, const vec4 v_b);

void lac_multiply_vec2(vec2 *v_out, const vec2 v_in, float scalar);
void lac_multiply_vec3(vec3 *v_out, const vec3 v_in, float scalar);
void lac_multiply_vec4(vec4 *v_out, const vec4 v_in, float scalar);

void lac_multiply_vec2_mat2(vec2 *v_out, const vec2 v_in, const mat2 m_in);
void lac_multiply_vec3_mat3(vec3 *v_out, const vec3 v_in, const mat3 m_in);
void lac_multiply_vec4_mat4(vec4 *v_out, const vec4 v_in, const mat4 m_in);

void lac_divide_vec2(vec2 *v_out, const vec2 v_in, float scalar);
void lac_divide_vec3(vec3 *v_out, const vec3 v_in, float scalar);
void lac_divide_vec4(vec4 *v_out, const vec4 v_in, float scalar);

void lac_calc_dot_prod_vec2(float *dot_prod, const vec2 v_a, const vec2 v_b);
void lac_calc_dot_prod_vec3(float *dot_prod, const vec3 v_a, const vec3 v_b);
void lac_calc_dot_prod_vec4(float *dot_prod, const vec4 v_a, const vec4 v_b);

void lac_calc_cross_prod(vec3 *v_out, const vec3 v_a, const vec3 v_b);

void lac_calc_magnitude_vec2(float *magnitude, const vec4 v_in); 
void lac_calc_magnitude_vec3(float *magnitude, const vec4 v_in); 
void lac_calc_magnitude_vec4(float *magnitude, const vec4 v_in); 

void lac_normalize_vec2(vec2 *v_out, const vec2 v_in);
void lac_normalize_vec3(vec3 *v_out, const vec3 v_in);
void lac_normalize_vec4(vec4 *v_out, const vec4 v_in);

#ifdef __cplusplus 
}
#endif /* __cplusplus */

#endif /* VECMATH_H */
