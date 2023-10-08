#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

/* Define this as static if you want to make all functions static */
#define LAC_DECL

typedef float mat2[4];
typedef float mat3[9];
typedef float mat4[16];

extern mat4 lac_ident_mat4;

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
