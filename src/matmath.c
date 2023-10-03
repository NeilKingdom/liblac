#include "../include/matmath.h"

LAC_DECL void lac_dot_prod_mat2(const mat2 m_a, const mat2 m_b, mat2 *m_out) {
   (*m_out[0]) = (m_a[0] * m_b[0]) + (m_a[1] * m_b[3]);
   (*m_out[1]) = (m_a[0] * m_b[1]) + (m_a[1] * m_b[4]);

   (*m_out[3]) = (m_a[3] * m_b[0]) + (m_a[4] * m_b[3]);
   (*m_out[4]) = (m_a[3] * m_b[1]) + (m_a[4] * m_b[4]);
}

LAC_DECL void lac_dot_prod_mat3(const mat3 m_a, const mat3 m_b, mat3 *m_out) {
   (*m_out[0]) = (m_a[0] * m_b[0]) + (m_a[1] * m_b[3]) + (m_a[2] * m_b[6]);
   (*m_out[1]) = (m_a[0] * m_b[1]) + (m_a[1] * m_b[4]) + (m_a[2] * m_b[7]);
   (*m_out[2]) = (m_a[0] * m_b[2]) + (m_a[1] * m_b[5]) + (m_a[2] * m_b[8]);

   (*m_out[3]) = (m_a[3] * m_b[0]) + (m_a[4] * m_b[3]) + (m_a[5] * m_b[6]);
   (*m_out[4]) = (m_a[3] * m_b[1]) + (m_a[4] * m_b[4]) + (m_a[5] * m_b[7]);
   (*m_out[5]) = (m_a[3] * m_b[2]) + (m_a[4] * m_b[5]) + (m_a[5] * m_b[8]);

   (*m_out[6]) = (m_a[6] * m_b[0]) + (m_a[7] * m_b[3]) + (m_a[8] * m_b[6]);
   (*m_out[7]) = (m_a[6] * m_b[1]) + (m_a[7] * m_b[4]) + (m_a[8] * m_b[7]);
   (*m_out[8]) = (m_a[6] * m_b[2]) + (m_a[7] * m_b[5]) + (m_a[8] * m_b[8]);
}

LAC_DECL void lac_dot_prod_mat4(const mat4 m_a, const mat4 m_b, mat4 *m_out) {
   (*m_out[0])  = (m_a[0] * m_b[0])  + (m_a[1] * m_b[4])  + (m_a[2] * m_b[8])   + (m_a[3] * m_b[12]);
   (*m_out[1])  = (m_a[0] * m_b[1])  + (m_a[1] * m_b[5])  + (m_a[2] * m_b[9])   + (m_a[3] * m_b[13]);
   (*m_out[2])  = (m_a[0] * m_b[2])  + (m_a[1] * m_b[6])  + (m_a[2] * m_b[10])  + (m_a[3] * m_b[14]);
   (*m_out[3])  = (m_a[0] * m_b[3])  + (m_a[1] * m_b[7])  + (m_a[2] * m_b[11])  + (m_a[3] * m_b[15]);

   (*m_out[4])  = (m_a[4] * m_b[0])  + (m_a[5] * m_b[4])  + (m_a[6] * m_b[8])   + (m_a[7] * m_b[12]);
   (*m_out[5])  = (m_a[4] * m_b[1])  + (m_a[5] * m_b[5])  + (m_a[6] * m_b[9])   + (m_a[7] * m_b[13]);
   (*m_out[6])  = (m_a[4] * m_b[2])  + (m_a[5] * m_b[6])  + (m_a[6] * m_b[10])  + (m_a[7] * m_b[14]);
   (*m_out[7])  = (m_a[4] * m_b[3])  + (m_a[5] * m_b[7])  + (m_a[6] * m_b[11])  + (m_a[7] * m_b[15]);

   (*m_out[8])  = (m_a[8] * m_b[0])  + (m_a[9] * m_b[4])  + (m_a[10] * m_b[8])  + (m_a[11] * m_b[12]);
   (*m_out[9])  = (m_a[8] * m_b[1])  + (m_a[9] * m_b[5])  + (m_a[10] * m_b[9])  + (m_a[11] * m_b[13]);
   (*m_out[10]) = (m_a[8] * m_b[2])  + (m_a[9] * m_b[6])  + (m_a[10] * m_b[10]) + (m_a[11] * m_b[14]);
   (*m_out[11]) = (m_a[8] * m_b[3])  + (m_a[9] * m_b[7])  + (m_a[10] * m_b[11]) + (m_a[11] * m_b[15]);

   (*m_out[12]) = (m_a[12] * m_b[0]) + (m_a[13] * m_b[4]) + (m_a[14] * m_b[8])  + (m_a[15] * m_b[12]);
   (*m_out[13]) = (m_a[12] * m_b[1]) + (m_a[13] * m_b[5]) + (m_a[14] * m_b[9])  + (m_a[15] * m_b[13]);
   (*m_out[14]) = (m_a[12] * m_b[2]) + (m_a[13] * m_b[6]) + (m_a[14] * m_b[10]) + (m_a[15] * m_b[14]);
   (*m_out[15]) = (m_a[12] * m_b[3]) + (m_a[13] * m_b[7]) + (m_a[14] * m_b[11]) + (m_a[15] * m_b[15]);
}
