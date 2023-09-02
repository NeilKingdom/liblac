#include "../include/matmath.h"

LAC_DECL mat2 *lac_dot_prod_mat2(const mat2 m1, const mat2 m2) {
   mat2 *output = NULL;
   output = (mat2 *)malloc(sizeof(*output)); /* Using explicit cast to satiate C++ */
   if (output == NULL) {
      //LAC_ERROR("Failed to allocate matrix");
      return NULL;
   }

   *output[0] = (m1[0] * m2[0]) + (m1[1] * m2[3]);
   *output[1] = (m1[0] * m2[1]) + (m1[1] * m2[4]);

   *output[3] = (m1[3] * m2[0]) + (m1[4] * m2[3]);
   *output[4] = (m1[3] * m2[1]) + (m1[4] * m2[4]);

   return output;
}

LAC_DECL mat3 *lac_dot_prod_mat3(const mat3 m1, const mat3 m2) {
   mat3 *output = NULL;
   output = (mat3 *)malloc(sizeof(*output)); /* Using explicit cast to satiate C++ */
   if (output == NULL) {
      //LAC_ERROR("Failed to allocate matrix");
      return NULL;
   }

   *output[0] = (m1[0] * m2[0]) + (m1[1] * m2[3]) + (m1[2] * m2[6]);
   *output[1] = (m1[0] * m2[1]) + (m1[1] * m2[4]) + (m1[2] * m2[7]);
   *output[2] = (m1[0] * m2[2]) + (m1[1] * m2[5]) + (m1[2] * m2[8]);

   *output[3] = (m1[3] * m2[0]) + (m1[4] * m2[3]) + (m1[5] * m2[6]);
   *output[4] = (m1[3] * m2[1]) + (m1[4] * m2[4]) + (m1[5] * m2[7]);
   *output[5] = (m1[3] * m2[2]) + (m1[4] * m2[5]) + (m1[5] * m2[8]);

   *output[6] = (m1[6] * m2[0]) + (m1[7] * m2[3]) + (m1[8] * m2[6]);
   *output[7] = (m1[6] * m2[1]) + (m1[7] * m2[4]) + (m1[8] * m2[7]);
   *output[8] = (m1[6] * m2[2]) + (m1[7] * m2[5]) + (m1[8] * m2[8]);

   return output;
}

LAC_DECL mat4 *lac_dot_prod_mat4(const mat4 m1, const mat4 m2) {
   mat4 *output = NULL;
   output = (mat4 *)malloc(sizeof(*output)); /* Using explicit cast to satiate C++ */
   if (output == NULL) {
      //LAC_ERROR("Failed to allocate matrix");
      return NULL;
   }

   *output[0]  = (m1[0] * m2[0])  + (m1[1] * m2[4])  + (m1[2] * m2[8])   + (m1[3] * m2[12]);
   *output[1]  = (m1[0] * m2[1])  + (m1[1] * m2[5])  + (m1[2] * m2[9])   + (m1[3] * m2[13]);
   *output[2]  = (m1[0] * m2[2])  + (m1[1] * m2[6])  + (m1[2] * m2[10])  + (m1[3] * m2[14]);
   *output[3]  = (m1[0] * m2[3])  + (m1[1] * m2[7])  + (m1[2] * m2[11])  + (m1[3] * m2[15]);

   *output[4]  = (m1[4] * m2[0])  + (m1[5] * m2[4])  + (m1[6] * m2[8])   + (m1[7] * m2[12]);
   *output[5]  = (m1[4] * m2[1])  + (m1[5] * m2[5])  + (m1[6] * m2[9])   + (m1[7] * m2[13]);
   *output[6]  = (m1[4] * m2[2])  + (m1[5] * m2[6])  + (m1[6] * m2[10])  + (m1[7] * m2[14]);
   *output[7]  = (m1[4] * m2[3])  + (m1[5] * m2[7])  + (m1[6] * m2[11])  + (m1[7] * m2[15]);

   *output[8]  = (m1[8] * m2[0])  + (m1[9] * m2[4])  + (m1[10] * m2[8])  + (m1[11] * m2[12]);
   *output[9]  = (m1[8] * m2[1])  + (m1[9] * m2[5])  + (m1[10] * m2[9])  + (m1[11] * m2[13]);
   *output[10] = (m1[8] * m2[2])  + (m1[9] * m2[6])  + (m1[10] * m2[10]) + (m1[11] * m2[14]);
   *output[11] = (m1[8] * m2[3])  + (m1[9] * m2[7])  + (m1[10] * m2[11]) + (m1[11] * m2[15]);

   *output[12] = (m1[12] * m2[0]) + (m1[13] * m2[4]) + (m1[14] * m2[8])  + (m1[15] * m2[12]);
   *output[13] = (m1[12] * m2[1]) + (m1[13] * m2[5]) + (m1[14] * m2[9])  + (m1[15] * m2[13]);
   *output[14] = (m1[12] * m2[2]) + (m1[13] * m2[6]) + (m1[14] * m2[10]) + (m1[15] * m2[14]);
   *output[15] = (m1[12] * m2[3]) + (m1[13] * m2[7]) + (m1[14] * m2[11]) + (m1[15] * m2[15]);

   return output;
}
