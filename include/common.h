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
/* Define this as false if you want to use column-major ordering */
#define LAC_IS_ROW_MAJOR false

#define lac_PI 3.14159265358979323846264338327950288f
#define lac_deg_to_rad(a) ((a) * lac_PI / 180.0)
#define lac_rad_to_deg(a) ((a) * 180.0 / lac_PI)

typedef float mat2[4];
typedef float mat3[9];
typedef float mat4[16];

typedef float vec2[2];
typedef float vec3[3];
typedef float vec4[4];

#if defined(__GNUC__)
#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Wunused-function"
#elif defined(__clang__)
#pragma clang diagnostic push 
#pragma clang diagnostic ignored "-Wunused-function"
#endif
static void _lac_warn(char *file, const char *func, int line, const char *msg) {
   fprintf(stderr, "\n=========== WARNING ===========\n"
                   "Backtrace:\n\n"
                   "File: %s, Function: %s, Line: %d\n"
                   "Short message: %s\n",
                   file, func, line, msg);
}
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#define LAC_WARN(msg) (_lac_warn((__FILE__), (__func__), (__LINE__), (msg)))

#endif /* COMMON_H */
