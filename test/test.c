#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/matmath.h"

START_TEST(rotate) {
   mat4 input = {
      1,   0,   0,   0,
      0,   1,   0,   0,
      0,   0,   1,   0,
      0,   0,   0,   1
   };

   float rx_in_deg = 45.0f;
   float ry_in_deg = 90.0f;
   float rz_in_deg = 180.0f;

   float rx_in_rad = lac_deg_to_rad(rx_in_deg);
   float ry_in_rad = lac_deg_to_rad(ry_in_deg);
   float rz_in_rad = lac_deg_to_rad(rz_in_deg);

   mat4 expected = {
      0.0f,  -0.71f,   0.71f,   0.0f,
      0.0f,  -0.71f,  -0.71f,   0.0f,
      1.0f,    0.0f,    0.0f,   0.0f,
      0.0f,    0.0f,    0.0f,   1.0f
   };
   float *actual = *lac_rotate_mat4(input, rx_in_rad, ry_in_rad, rz_in_rad);

   printf("Expected:\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n",
         expected[0],  expected[1],  expected[2],  expected[3],
         expected[4],  expected[5],  expected[6],  expected[7],
         expected[8],  expected[9],  expected[10], expected[11],
         expected[12], expected[13], expected[14], expected[15]);

   printf("Actual:\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n",
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
   tcase_add_test(tc_core, rotate);

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
