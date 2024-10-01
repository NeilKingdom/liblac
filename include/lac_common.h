#ifndef LAC_COMMON_H
#define LAC_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Define this as static if you want to make all functions static */
#define LAC_DECL
/* Define this as false if you want to use column-major ordering */
#define LAC_IS_ROW_MAJOR true

#define lac_PI 3.14159265358979323846264338327950288f

typedef float mat2[4];
typedef float mat3[9];
typedef float mat4[16];

typedef float vec2[2];
typedef float vec3[3];
typedef float vec4[4];

typedef enum {
    LAC_NOTE,
    LAC_WARNING,
    LAC_ERROR
} LacLogLevel_t;

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#endif

static void _lac_log(
    const char *file,
    const char *func,
    const int line,
    const char *msg,
    const LacLogLevel_t level) {

    char header[20];
    switch (level) {
        case LAC_NOTE:
            strncpy(header, "NOTE", 20);
            break;
        case LAC_WARNING:
            strncpy(header, "WARNING", 20);
            break;
        case LAC_ERROR:
            strncpy(header, "ERROR", 20);
            break;
    }

    fprintf((level == LAC_NOTE) ? stdout : stderr,
        "\n=========== %s ===========\n"
        "Logger: %s\n"
        "File: %s, Function: %s, Line: %d\n",
        header, msg, file, func, line
    );
}

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#define LAC_LOG(msg, level) do { \
    _lac_log((__FILE__), (__func__), (__LINE__), (msg), (level)); \
} while (0)

/**
 * @brief Converts degrees to radians.
 * @since 30-09-2024
 * @param[in] deg An angle given in degrees
 * @returns The conversion of angle __deg__ to radians
 */
static inline float lac_deg_to_rad(const float deg) {
    return deg * (lac_PI / 180.0f);
}

/**
 * @brief Converts radians to degrees.
 * @since 30-09-2024
 * @param[in] rad An angle given in radians
 * @returns The conversion of angle __rad__ to degrees
 */
static inline float lac_rad_to_deg(const float rad) {
    return rad * (180.0f / lac_PI);
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LAC_COMMON_H */
