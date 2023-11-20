#ifndef VECMATH_H
#define VECMATH_H

#include "../include/common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Forward function declarations */

void  lac_subtract_vec2(const vec2 v_a, const vec2 v_b, vec2 *v_out);
void  lac_subtract_vec3(const vec3 v_a, const vec3 v_b, vec3 *v_out);
void  lac_subtract_vec4(const vec4 v_a, const vec4 v_b, vec4 *v_out);

void  lac_add_vec2(const vec2 v_a, const vec2 v_b, vec2 *v_out);
void  lac_add_vec3(const vec3 v_a, const vec3 v_b, vec3 *v_out);
void  lac_add_vec4(const vec4 v_a, const vec4 v_b, vec4 *v_out);

void  lac_multiply_vec2(const vec2 v_in, vec2 *v_out, float scalar);
void  lac_multiply_vec3(const vec3 v_in, vec3 *v_out, float scalar);
void  lac_multiply_vec4(const vec4 v_in, vec4 *v_out, float scalar);

void  lac_divide_vec2(const vec2 v_in, vec2 *v_out, float scalar);
void  lac_divide_vec3(const vec3 v_in, vec3 *v_out, float scalar);
void  lac_divide_vec4(const vec4 v_in, vec4 *v_out, float scalar);

void  lac_calc_cross_prod(const vec3 v_a, const vec3 v_b, vec3 *v_out);

float lac_calc_dot_prod_vec2(const vec2 v_a, const vec2 v_b);
float lac_calc_dot_prod_vec3(const vec3 v_a, const vec3 v_b);
float lac_calc_dot_prod_vec4(const vec4 v_a, const vec4 v_b);

void  lac_normalize_vec2(const vec2 v_in, vec2 *v_out);
void  lac_normalize_vec3(const vec3 v_in, vec3 *v_out);
void  lac_normalize_vec4(const vec4 v_in, vec4 *v_out);

#ifdef __cplusplus 
}
#endif /* __cplusplus */

#endif /* VECMATH_H */
