#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "lac_common.h"
#include "matmath.h"

START_TEST(MatrixAddition) {
    /*** 2x2 Matrices ***/

    mat2 m2_a = {
        1,  2,
        3,  4
    };

    mat2 m2_b = {
        5,  6,
        7,  8
    };

    mat2 m2_expected = {
        6,  8,
        10, 12
    };

    mat2 m2_actual = { 0 };

    lac_add_mat2(&m2_actual, m2_a, m2_b);
    ck_assert_mem_eq(m2_actual, m2_expected, sizeof(mat2));

    /*** 3x3 Matrices ***/

    mat3 m3_a = {
        1,  2,  3,
        4,  5,  6,
        7,  8,  9
    };

    mat3 m3_b = {
        1,  3,  5,
        7,  9,  11,
        13, 15, 17
    };

    mat3 m3_expected = {
        2,  5,  8,
        11, 14, 17,
        20, 23, 26
    };

    mat3 m3_actual = { 0 };

    lac_add_mat3(&m3_actual, m3_a, m3_b);
    ck_assert_mem_eq(m3_actual, m3_expected, sizeof(mat3));

    /*** 4x4 Matrices ***/

    mat4 m4_a = {
        1,  2,  3,  4,
        5,  6,  7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16
    };

    mat4 m4_b = {
        5,  4,  3,  2,
        9,  8,  7,  6,
        0,  10, 20, 25,
        1,  2,  7,  42
    };

    mat4 m4_expected = {
        6,  6,  6,  6,
        14, 14, 14, 14,
        9,  20, 31, 37,
        14, 16, 22, 58
    };

    mat4 m4_actual = { 0 };

    lac_add_mat4(&m4_actual, m4_a, m4_b);
    ck_assert_mem_eq(m4_actual, m4_expected, sizeof(mat4));
}
END_TEST

START_TEST(MatrixSubtraction) {
    /*** 2x2 Matrices ***/

    mat2 m2_a = {
        1,  2,
        3,  4
    };

    mat2 m2_b = {
        5,  6,
        7,  8
    };

    mat2 m2_expected = {
        -4,  -4,
        -4,  -4
    };

    mat2 m2_actual = { 0 };

    lac_subtract_mat2(&m2_actual, m2_a, m2_b);
    ck_assert_mem_eq(m2_actual, m2_expected, sizeof(mat2));

    /*** 3x3 Matrices ***/

    mat3 m3_a = {
        1,  2,  3,
        4,  5,  6,
        7,  8,  9
    };

    mat3 m3_b = {
        1,  3,  5,
        7,  9,  11,
        13, 15, 17
    };

    mat3 m3_expected = {
        0,  -1,  -2,
       -3,  -4,  -5,
       -6,  -7,  -8
    };

    mat3 m3_actual = { 0 };

    lac_subtract_mat3(&m3_actual, m3_a, m3_b);
    ck_assert_mem_eq(m3_actual, m3_expected, sizeof(mat3));

    /*** 4x4 Matrices ***/

    mat4 m4_a = {
        1,  2,  3,  4,
        5,  6,  7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16
    };

    mat4 m4_b = {
        5,  4,  3,  2,
        9,  8,  7,  6,
        0,  10, 20, 25,
        1,  2,  7,  42
    };

    mat4 m4_expected = {
       -4,  -2,   0,   2,
       -4,  -2,   0,   2,
        9,   0,  -9,  -13,
        12,  12,  8,  -26
    };

    mat4 m4_actual = { 0 };

    lac_subtract_mat4(&m4_actual, m4_a, m4_b);
    ck_assert_mem_eq(m4_actual, m4_expected, sizeof(mat4));
}
END_TEST

START_TEST(MatrixMultiplication) {
    /*** 2x2 Matrices ***/

    mat2 m2_a = {
        1,  2,
        3,  4
    };

    mat2 m2_b = {
        5,  6,
        7,  8
    };

    mat2 m2_expected = {
        19, 22,
        43, 50
    };

    mat2 m2_actual = { 0 };

    lac_multiply_mat2(&m2_actual, m2_a, m2_b);
    ck_assert_mem_eq(m2_actual, m2_expected, sizeof(mat2));

    /*** 3x3 Matrices ***/

    mat3 m3_a = {
        1,  2,  3,
        4,  5,  6,
        7,  8,  9
    };

    mat3 m3_b = {
        1,  3,  5,
        7,  9,  11,
        13, 15, 17
    };

    mat3 m3_expected = {
        54,  66,  78,
        117, 147, 177,
        180, 228, 276
    };

    mat3 m3_actual = { 0 };

    lac_multiply_mat3(&m3_actual, m3_a, m3_b);
    ck_assert_mem_eq(m3_actual, m3_expected, sizeof(mat3));

    /*** 4x4 Matrices ***/

    mat4 m4_a = {
        1,  2,  3,  4,
        5,  6,  7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16
    };

    mat4 m4_b = {
        5,  4,  3,  2,
        9,  8,  7,  6,
        0,  10, 20, 25,
        1,  2,  7,  42
    };

    mat4 m4_expected = {
        27,  58,  105, 257,
        87,  154, 253, 557,
        147, 250, 401, 857,
        207, 346, 549, 1157
    };

    mat4 m4_actual = { 0 };

    lac_multiply_mat4(&m4_actual, m4_a, m4_b);
    ck_assert_mem_eq(m4_actual, m4_expected, sizeof(mat4));
}
END_TEST

START_TEST(MatrixTranspose) {
    /*** 2x2 Matrices ***/

    mat2 m2 = {
        1,  2,
        3,  4
    };

    mat2 m2_expected = {
        1,  3,
        2,  4
    };

    mat2 m2_actual = { 0 };

    lac_transpose_mat2(&m2_actual, m2);
    ck_assert_mem_eq(m2_actual, m2_expected, sizeof(mat2));

    /*** 3x3 Matrices ***/

    mat3 m3 = {
        1,  2,  3,
        4,  5,  6,
        7,  8,  9
    };

    mat3 m3_expected = {
        1,  4,  7,
        2,  5,  8,
        3,  6,  9
    };

    mat3 m3_actual = { 0 };

    lac_transpose_mat3(&m3_actual, m3);
    ck_assert_mem_eq(m3_actual, m3_expected, sizeof(mat3));

    /*** 4x4 Matrices ***/

    mat4 m4 = {
        1,  2,  3,  4,
        5,  6,  7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16
    };

    mat4 m4_expected = {
        1,  5,  9,  13,
        2,  6,  10, 14,
        3,  7,  11, 15,
        4,  8,  12, 16
    };

    mat4 m4_actual = { 0 };

    lac_transpose_mat4(&m4_actual, m4);
    ck_assert_mem_eq(m4_actual, m4_expected, sizeof(mat4));
}
END_TEST

Suite *buffer_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Matrices");

    /* Core test cases */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, MatrixAddition);
    tcase_add_test(tc_core, MatrixSubtraction);
    tcase_add_test(tc_core, MatrixMultiplication);
    tcase_add_test(tc_core, MatrixTranspose);
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
