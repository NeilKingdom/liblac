#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>

/* Define this as static if you want to make all functions static */
#define LAC_DECL

#define lac_PI 3.14159265358979323846264338327950288
#define lac_deg_to_rad(a) ((a) * lac_PI / 180.0)
#define lac_rad_to_deg(a) ((a) * 180.0 / lac_PI)

typedef float mat2[4];
typedef float mat3[9];
typedef float mat4[16];

typedef float vec2[2];
typedef float vec3[3];
typedef float vec4[4];

enum LAC_Error {
   LAC_EOK = 0,   /* No error */
   LAC_ERROR,     /* General error */
   LAC_EINVAL,    /* The argument was invalid */
   LAC_ENOMEM,    /* Not enough memory */
   LAC_EFREE,     /* Error freeing memory */
   LAC_EFAULT     /* Bad address */
};

static void _lac_error(char *file, const char *func, int line, const char *msg) {
   fprintf(stderr, "\n=========== ERROR ===========\n"
                   "Backtrace:\n\n"
                   "File: %s, Function: %s, Line: %d\n"
                   "Short message: %s\n"
                   "Errno message: %s\n\n",
                   file, func, line, msg, strerror(errno));
}

#define LAC_ERROR(msg) (_lac_error((__FILE__), (__func__), (__LINE__), (msg)))

#endif /* COMMON_H */
