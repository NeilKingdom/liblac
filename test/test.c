#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/matmath.h"

START_TEST(dot_prod_mat4) {
   mat4 m_a = {
      1,   2,   3,   4,
      5,   6,   7,   8,
      9,   10,  11,  12,
      13,  14,  15,  16
   };

   mat4 m_b = {
      17,  18,  19,  20,
      21,  22,  23,  24,
      25,  26,  27,  28,
      29,  30,  31,  32
   };

   mat4 expected = {
      250, 260, 270, 280,
      618, 644, 670, 696,
      986,1028,1070,1112,
      1354,1412,1470,1528
   };

   mat4 actual = { 0 };

   lac_dot_prod_mat4(m_a, m_b, &actual);

   printf("Expected:\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n",
         expected[0],  expected[1],  expected[2],  expected[3],
         expected[4],  expected[5],  expected[6],  expected[7],
         expected[8],  expected[9],  expected[10], expected[11],
         expected[12], expected[13], expected[14], expected[15]);

   putchar('\n');

   printf("Actual:\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n",
         actual[0],  actual[1],  actual[2],  actual[3],
         actual[4],  actual[5],  actual[6],  actual[7],
         actual[8],  actual[9],  actual[10], actual[11],
         actual[12], actual[13], actual[14], actual[15]);

   for (int i = 0; i < (int)(sizeof(mat4)); ++i) {
      /* Using ints because the actual floats will have slight rounding errors */
      ck_assert_int_eq((int)expected[i], (int)actual[i]);
   }
}
END_TEST

START_TEST(get_rotation_mat4) {
   float rx_in_deg = 45.0f;
   float ry_in_deg = 90.0f;
   float rz_in_deg = 180.0f;

   float rx_in_rad = lac_deg_to_rad(rx_in_deg);
   float ry_in_rad = lac_deg_to_rad(ry_in_deg);
   float rz_in_rad = lac_deg_to_rad(rz_in_deg);

   mat4 actual = { 0 };
   mat4 expected = {
      0.0f,  -0.71f,   0.71f,   0.0f,
      0.0f,  -0.71f,  -0.71f,   0.0f,
      1.0f,   0.0f,    0.0f,    0.0f,
      0.0f,   0.0f,    0.0f,    1.0f
   };
   lac_get_rotation_mat4(&actual, rx_in_rad, ry_in_rad, rz_in_rad);

   printf("Expected:\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n",
         expected[0],  expected[1],  expected[2],  expected[3],
         expected[4],  expected[5],  expected[6],  expected[7],
         expected[8],  expected[9],  expected[10], expected[11],
         expected[12], expected[13], expected[14], expected[15]);

   putchar('\n');

   printf("Actual:\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n"
         "%.2f %.2f %.2f %.2f\n",
         actual[0],  actual[1],  actual[2],  actual[3],
         actual[4],  actual[5],  actual[6],  actual[7],
         actual[8],  actual[9],  actual[10], actual[11],
         actual[12], actual[13], actual[14], actual[15]);

   for (unsigned long i = 0; i < sizeof(mat4); ++i) {
      ck_assert_float_eq(expected[i], actual[i]);
   }
}
END_TEST

Suite *liblac_suite(void) {
   Suite *s;
   TCase *tc_core;

   s = suite_create("liblac Test Suite");

   /* Core test cases*/
   tc_core = tcase_create("Core");
   tcase_add_test(tc_core, dot_prod_mat4);
   tcase_add_test(tc_core, get_rotation_mat4);
   suite_add_tcase(s, tc_core);

   return s;
}

int main(void) {
   int num_failed;
   Suite *s;
   SRunner *sr;

   s = liblac_suite();
   sr = srunner_create(s);

   srunner_run_all(sr, CK_NORMAL);
   num_failed = srunner_ntests_failed(sr);
   printf("%s\n", num_failed ? "At least one test failed" : "All tests passed");
   srunner_free(sr);
   return (!num_failed ? EXIT_SUCCESS : EXIT_FAILURE);
}
