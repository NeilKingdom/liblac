#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "lac_common.h"
#include "vecmath.h"

START_TEST(VectorAddition) {
    /*** 2 Element Vector ***/

    vec2 v2_a = { 2, 5 };
    vec2 v2_b = { 7, 9 };
    vec2 v2_expected = { 9, 14 };
    vec2 v2_actual = { 0 };

    lac_add_vec2(&v2_actual, v2_a, v2_b);
    ck_assert_mem_eq(v2_actual, v2_expected, sizeof(vec2));

    /*** 3 Element Vector ***/

    vec3 v3_a = { 18, 43, 28 };
    vec3 v3_b = { 88, 3, 92 };
    vec3 v3_expected = { 106, 46, 120 };
    vec3 v3_actual = { 0 };

    lac_add_vec3(&v3_actual, v3_a, v3_b);
    ck_assert_mem_eq(v3_actual, v3_expected, sizeof(vec3));

    /*** 4 Element Vector ***/

    vec4 v4_a = { 62, 8, 123, 74 };
    vec4 v4_b = { 73, 22, 35, 2 };
    vec4 v4_expected = { 135, 30, 158, 76 };
    vec4 v4_actual = { 0 };

    lac_add_vec4(&v4_actual, v4_a, v4_b);
    ck_assert_mem_eq(v4_actual, v4_expected, sizeof(vec4));
}
END_TEST

START_TEST(VectorSubtraction) {
    /*** 2 Element Vector ***/

    vec2 v2_a = { 2, 5 };
    vec2 v2_b = { 7, 9 };
    vec2 v2_expected = { -5, -4 };
    vec2 v2_actual = { 0 };

    lac_subtract_vec2(&v2_actual, v2_a, v2_b);
    ck_assert_mem_eq(v2_actual, v2_expected, sizeof(vec2));

    /*** 3 Element Vector ***/

    vec3 v3_a = { 18, 43, 28 };
    vec3 v3_b = { 88, 3, 92 };
    vec3 v3_expected = { -70, 40, -64 };
    vec3 v3_actual = { 0 };

    lac_subtract_vec3(&v3_actual, v3_a, v3_b);
    ck_assert_mem_eq(v3_actual, v3_expected, sizeof(vec3));

    /*** 4 Element Vector ***/

    vec4 v4_a = { 62, 8, 123, 74 };
    vec4 v4_b = { 73, 22, 35, 2 };
    vec4 v4_expected = { -11, -14, 88, 72 };
    vec4 v4_actual = { 0 };

    lac_subtract_vec4(&v4_actual, v4_a, v4_b);
    ck_assert_mem_eq(v4_actual, v4_expected, sizeof(vec4));
}
END_TEST

START_TEST(VectorMultiplication) {
    /*** 2 Element Vector ***/

    const float scalar_v2 = 0.5f;
    vec2 v2 = { 2, 5 };
    vec2 v2_expected = { 1.0f, 2.5f };
    vec2 v2_actual = { 0 };

    lac_multiply_vec2(&v2_actual, v2, scalar_v2);
    ck_assert_mem_eq(v2_actual, v2_expected, sizeof(vec2));

    /*** 3 Element Vector ***/

    const float scalar_v3 = 1.5f;
    vec3 v3 = { 18, 43, 28 };
    vec3 v3_expected = { 27.0f, 64.5f, 42.0f };
    vec3 v3_actual = { 0 };

    lac_multiply_vec3(&v3_actual, v3, scalar_v3);
    ck_assert_mem_eq(v3_actual, v3_expected, sizeof(vec3));

    /*** 4 Element Vector ***/

    const float scalar_v4 = 2.0f;
    vec4 v4 = { 62, 8, 123, 74 };
    vec4 v4_expected = { 124, 16, 246, 148 };
    vec4 v4_actual = { 0 };

    lac_multiply_vec4(&v4_actual, v4, scalar_v4);
    ck_assert_mem_eq(v4_actual, v4_expected, sizeof(vec4));
}
END_TEST

START_TEST(VectorDivision) {
    /*** 2 Element Vector ***/

    const float scalar_v2 = 0.5f;
    vec2 v2 = { 2, 5 };
    vec2 v2_expected = { 4, 10 };
    vec2 v2_actual = { 0 };

    lac_divide_vec2(&v2_actual, v2, scalar_v2);
    ck_assert_mem_eq(v2_actual, v2_expected, sizeof(vec2));

    /*** 3 Element Vector ***/

    const float scalar_v3 = 1.5f;
    vec3 v3 = { 18, 43, 28 };
    vec3 v3_expected = { 12.0f, 28.666666666666668f, 18.666666666666668f };
    vec3 v3_actual = { 0 };

    lac_divide_vec3(&v3_actual, v3, scalar_v3);
    ck_assert_mem_eq(v3_actual, v3_expected, sizeof(vec3));

    /*** 4 Element Vector ***/

    const float scalar_v4 = 2.0f;
    vec4 v4 = { 62, 8, 123, 74 };
    vec4 v4_expected = { 31.0f, 4.0f, 61.5f, 37.0f };
    vec4 v4_actual = { 0 };

    lac_divide_vec4(&v4_actual, v4, scalar_v4);
    ck_assert_mem_eq(v4_actual, v4_expected, sizeof(vec4));
}
END_TEST

START_TEST(DotProduct) {
    /*** 2 Element Vector ***/

    vec2 v2_a = { 2, 5 };
    vec2 v2_b = { 7, 9 };
    float expected_v2 = 59;
    float actual_v2;

    lac_calc_dot_prod_vec2(&actual_v2, v2_a, v2_b);
    ck_assert_float_eq(actual_v2, expected_v2);

    /*** 3 Element Vector ***/

    vec3 v3_a = { 18, 43, 28 };
    vec3 v3_b = { 88, 3, 92 };
    float expected_v3 = 4289;
    float actual_v3;

    lac_calc_dot_prod_vec3(&actual_v3, v3_a, v3_b);
    ck_assert_float_eq(actual_v3, expected_v3);

    /*** 4 Element Vector ***/

    vec4 v4_a = { 62, 8, 123, 74 };
    vec4 v4_b = { 73, 22, 35, 2 };
    float expected_v4 = 9155;
    float actual_v4;

    lac_calc_dot_prod_vec4(&actual_v4, v4_a, v4_b);
    ck_assert_float_eq(actual_v4, expected_v4);
}
END_TEST

START_TEST(CrossProduct) {
    vec3 v3_a = { 2.4f, 829.34f, 83.03f };
    vec3 v3_b = { 84.24f, 0.7f, 93.37f };
    vec3 expected = { 77377.367188f, 6770.358887, -69861.921875 };
    vec3 actual;

    lac_calc_cross_prod(&actual, v3_a, v3_b);
    ck_assert_mem_eq(actual, expected, sizeof(vec3));
}
END_TEST

START_TEST(Magnitude) {
    /*** 2 Element Vector ***/

    vec2 v2 = { 2, 5 };
    float v2_expected = 5.385164807134504f;
    float v2_actual;

    lac_calc_magnitude_vec2(&v2_actual, v2);
    ck_assert_float_eq(v2_actual, v2_expected);

    /*** 3 Element Vector ***/

    vec3 v3 = { 18, 43, 28 };
    float v3_expected = 54.378304497290093f;
    float v3_actual;

    lac_calc_magnitude_vec3(&v3_actual, v3);
    ck_assert_float_eq(v3_actual, v3_expected);

    /*** 4 Element Vector ***/

    vec4 v4 = { 62, 8, 123, 74 };
    float v4_expected = 156.566279894490691f;
    float v4_actual;

    lac_calc_magnitude_vec4(&v4_actual, v4);
    ck_assert_float_eq(v4_actual, v4_expected);
}
END_TEST

START_TEST(Normalize) {
    /*** 2 Element Vector ***/

    vec2 v2 = { 2, 5 };
    vec2 v2_expected = { 0.37139067f, 0.92847669f };
    vec2 v2_actual = { 0 };

    lac_normalize_vec2(&v2_actual, v2);
    ck_assert_mem_eq(v2_actual, v2_expected, sizeof(vec2));

    /*** 3 Element Vector ***/

    vec3 v3 = { 18, 43, 28 };
    vec3 v3_expected = { 0.3310143650f, 0.7907565236f, 0.5149112344f };
    vec3 v3_actual = { 0 };

    lac_normalize_vec3(&v3_actual, v3);
    ck_assert_mem_eq(v3_actual, v3_expected, sizeof(vec3));

    /*** 4 Element Vector ***/

    vec4 v4 = { 62, 8, 123, 74 };
    vec4 v4_expected = { 0.39599842f, 0.05109657f, 0.78560978f, 0.47264326f };
    vec4 v4_actual = { 0 };

    lac_normalize_vec4(&v4_actual, v4);
    ck_assert_mem_eq(v4_actual, v4_expected, sizeof(vec4));
}
END_TEST

START_TEST(Polar) {
    vec2 v2 = { 2, 5 };
    float v2_expected_len = 5.3851648071345f;
    float v2_expected_angle = 1.1902899496825f;
    float v2_actual_len;
    float v2_actual_angle;

    lac_cartesian_to_polar(&v2_actual_len, &v2_actual_angle, v2);
    ck_assert_float_eq(v2_actual_len, v2_expected_len);
    ck_assert_float_eq(v2_actual_angle, v2_expected_angle);

    float angle = 8.24f;
    float len = 23.8f;
    vec2 expected = { -8.960760f, 22.048689f };
    vec2 actual = { 0 };

    lac_polar_to_cartesian(&actual, len, angle);
    ck_assert_mem_eq(actual, expected, sizeof(vec2));
}
END_TEST

Suite *buffer_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Vectors");

    /* Core test cases */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, VectorAddition);
    tcase_add_test(tc_core, VectorSubtraction);
    tcase_add_test(tc_core, VectorMultiplication);
    tcase_add_test(tc_core, VectorDivision);
    tcase_add_test(tc_core, DotProduct);
    tcase_add_test(tc_core, CrossProduct);
    tcase_add_test(tc_core, Magnitude);
    tcase_add_test(tc_core, Normalize);
    tcase_add_test(tc_core, Polar);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int num_failed;
    Suite *s;
    SRunner *sr;

    s = buffer_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    printf("%s\n", num_failed ? "At least one test failed" : "All tests passed");
    srunner_free(sr);
    return (!num_failed ? EXIT_SUCCESS : EXIT_FAILURE);
}
