#include "../include/matrices.h"

/* TODO: Make these accept my cos and sin funcs */
mat4 rot_mat_x = {
   1,    0,                  0,                  0,
   0,    cos(-theta_rad),   -sin(-theta_rad),    0,
   0,    sin(-theta_rad),    cos(-theta_rad),    0,
   0,    0,                  0,                  1
};

mat4 rot_mat_y = {
   cos(-theta_rad),    0,    sin(-theta_rad),    0,
   0,                  1,    0,                  0,
  -sin(theta_rad),     0,    cos(-theta_rad),    0,
   0,                  0,    0,                  1
};

mat4 rot_mat_z = {
   cos(-theta_rad),   -sin(-theta_rad),    0,    0,
   sin(-theta_rad),    cos(-theta_rad),    0,    0,
   0,                  0,                  1,    0,
   0,                  0,                  0,    1
};

mat4 trn_mat_x = {

};

mat4 trn_mat_y = {

};

mat4 trn_mat_z = {

};

mat4 scl_mat_x = {

};

mat4 scl_mat_y = {

};

mat4 scl_mat_z = {

};
