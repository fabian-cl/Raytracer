// General Math Utilities
#ifndef RTM_COMMON_H
#define RTM_COMMON_H

#ifndef RTMDEF
    #ifdef RTM_USE_STATIC_INLINE
        #define RTMDEF static inline
    #else
        #define RTMDEF extern
    #endif
#endif

#ifndef RTM_bool
    #define RTM_bool unsigned
    #define RTM_TRUE 0
    #define RTM_FALSE 1
#endif

#ifndef RTM_EPSILON
    #define RTM_EPSION 1e-9
#endif

#define RTM_PI 3.14159265358979323846
#define RTM_PI32 3.14159265359f

#if !defined(RTM_PROVIDE_MATH_FUNCTIONS)
	#include <math.h>
	#define RTM_SINF sinf
	#define RTM_COSF cosf
	#define RTM_TANF tanf
	#define RTM_SQRTF sqrtf
	#define RTM_ACOSF acosf
#endif

#include <stdbool.h>

#define RTM_MIN(a, b) ((a) > (b) ? (b) : (a))
#define RTM_MAX(a, b) ((a) < (b) ? (b) : (a))
#define RTM_ABS(a) ((a) > 0 ? (a) : -(a))
#define RTM_MOD(a, m) (((a) % (m)) >= 0 ? ((a) % (m)) : (((a) % (m)) + (m)))
#define RTM_SQUARE(x) ((x) * (x))

#define uint32_t unsigned int

/*===========================================================
 * FLOAT PRECISION FUNCTIONS
 *===========================================================*/

 /**
 * @brief Clamps a float between min and max.
 * @param x Value to clamp.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return Clamped value.
 */
RTMDEF float rtm_fclamp(float x, float min, float max);

/**
 * @brief Saturates a float value to [0, 1].
 * @param x Value to saturate.
 * @return Saturated value.
 */
RTMDEF float rtm_fsaturate(float x);

/**
 * @brief Linear interpolation between two floats.
 * @param a Start value.
 * @param b End value.
 * @param t Interpolation factor [0, 1].
 * @return Interpolated value.
 */
RTMDEF float rtm_flerp(float a, float b, float t);

/**
 * @brief Smoothstep interpolation.
 * @param edge0 Lower edge.
 * @param edge1 Upper edge.
 * @param x Value to interpolate.
 * @return Smoothstep result.
 */
RTMDEF float rtm_fsmoothstep(float edge0, float edge1, float x);

/**
 * @brief Returns sign of value (-1, 0, 1).
 * @param x Input value.
 * @return Sign of x.
 */
RTMDEF int rtm_fsign(float x);

/**
 * @brief Clamps x to [0, 1].
 */
#define rtm_fsaturate(x) rtm_fclamp((x), 0.0f, 1.0f)

/**
 * @brief Converts degrees to radians.
 * @param deg Angle in degrees.
 * @return Angle in radians.
 */
RTMDEF float rtm_fdeg_to_rad(float deg);

/**
 * @brief Converts radians to degrees.
 * @param rad Angle in radians.
 * @return Angle in degrees.
 */
RTMDEF float rtm_frad_to_deg(float rad);

/**
 * @brief Absolute value.
 */
RTMDEF float rtm_fabs(float x);

/**
 * @brief Returns minimum of two floats.
 */
RTMDEF float rtm_fmin(float a, float b);

/**
 * @brief Returns maximum of two floats.
 */
RTMDEF float rtm_fmax(float a, float b);

/**
 * @brief Floating point modulus.
 */
RTMDEF float rtm_fmod(float x, float y);

/**
 * @brief Fractional part of x.
 */
RTMDEF float rtm_ffract(float x);

/*===========================================================
 * DOUBLE PRECISION FUNCTIONS
 *===========================================================*/

RTMDEF double rtm_dclamp(double x, double min, double max);
RTMDEF double rtm_dsaturate(double x);
RTMDEF double rtm_dlerp(double a, double b, double t);
RTMDEF double rtm_dsmoothstep(double edge0, double edge1, double x);
RTMDEF int rtm_dsign(double x);
RTMDEF double rtm_ddeg_to_rad(double deg);
RTMDEF double rtm_drad_to_deg(double rad);
RTMDEF double rtm_dabs(double x);
RTMDEF double rtm_dmin(double a, double b);
RTMDEF double rtm_dmax(double a, double b);
RTMDEF double rtm_dmod(double x, double y);
RTMDEF double rtm_dfract(double x);

/*===========================================================
 * COMPARISON / EPSILON
 *===========================================================*/

RTMDEF bool rtm_fequal(float a, float b, float eps);
RTMDEF bool rtm_dequal(double a, double b, double eps);
RTMDEF bool rtm_fzero(float x, float eps);
RTMDEF bool rtm_dzero(double x, double eps);

/*===========================================================
 * RANDOM / HASH
 *===========================================================*/

RTMDEF float rtm_frand(void);                     /**< Uniform [0,1) */
RTMDEF float rtm_frand_range(float min, float max); 
RTMDEF double rtm_drand(void);                    /**< Uniform [0,1) */
RTMDEF double rtm_drand_range(double min, double max);
RTMDEF uint32_t rtm_hash_u32(uint32_t x);

/*===========================================================
 * TRIGONOMETRIC HELPERS
 *===========================================================*/

#ifdef RTM_MATH_IMPLEMENTATION
/*================ Float ==================*/
RTMDEF float rtm_fclamp(float x, float min, float max) { 
    return (x < min) ? min : ((x > max) ? max : x); 
}

RTMDEF float rtm_fsaturate(float x) { return rtm_fclamp(x, 0.0f, 1.0f); }

RTMDEF float rtm_flerp(float a, float b, float t) { return a + t * (b - a); }

RTMDEF float rtm_fsmoothstep(float edge0, float edge1, float x) {
    float t = rtm_fclamp((x - edge0)/(edge1 - edge0), 0.0f, 1.0f);
    return t*t*(3.0f - 2.0f*t);
}

RTMDEF int rtm_fsign(float x) { return (x > 0) - (x < 0); }

RTMDEF float rtm_fdeg_to_rad(float deg) { return deg * 0.017453292519943295f; }
RTMDEF float rtm_frad_to_deg(float rad) { return rad * 57.29577951308232f; }

RTMDEF float rtm_fabs(float x) { return fabsf(x); }
RTMDEF float rtm_fmin(float a, float b) { return (a < b) ? a : b; }
RTMDEF float rtm_fmax(float a, float b) { return (a > b) ? a : b; }
RTMDEF float rtm_fmod(float x, float y) { return fmodf(x, y); }
RTMDEF float rtm_ffract(float x) { return x - floorf(x); }

/*================ Double ==================*/
RTMDEF double rtm_dclamp(double x, double min, double max) { 
    return (x < min) ? min : ((x > max) ? max : x); 
}

RTMDEF double rtm_dsaturate(double x) { return rtm_dclamp(x, 0.0, 1.0); }
RTMDEF double rtm_dlerp(double a, double b, double t) { return a + t * (b - a); }
RTMDEF double rtm_dsmoothstep(double edge0, double edge1, double x) {
    double t = rtm_dclamp((x - edge0)/(edge1 - edge0), 0.0, 1.0);
    return t*t*(3.0 - 2.0*t);
}

RTMDEF int rtm_dsign(double x) { return (x > 0) - (x < 0); }

RTMDEF double rtm_ddeg_to_rad(double deg) { return deg * 0.017453292519943295; }
RTMDEF double rtm_drad_to_deg(double rad) { return rad * 57.29577951308232; }

RTMDEF double rtm_dabs(double x) { return fabs(x); }
RTMDEF double rtm_dmin(double a, double b) { return (a < b) ? a : b; }
RTMDEF double rtm_dmax(double a, double b) { return (a > b) ? a : b; }
RTMDEF double rtm_dmod(double x, double y) { return fmod(x, y); }
RTMDEF double rtm_dfract(double x) { return x - floor(x); }

/*================ Comparison ==================*/
RTMDEF bool rtm_fequal(float a, float b, float eps) { return fabsf(a-b) < eps; }
RTMDEF bool rtm_dequal(double a, double b, double eps) { return fabs(a-b) < eps; }
RTMDEF bool rtm_fzero(float x, float eps) { return fabsf(x) < eps; }
RTMDEF bool rtm_dzero(double x, double eps) { return fabs(x) < eps; }

/*================ Random ==================*/
#include <stdlib.h>

RTMDEF float rtm_frand(void) { return (float)rand()/(float)RAND_MAX; }
RTMDEF float rtm_frand_range(float min, float max) { return min + (max-min)*rtm_frand(); }
RTMDEF double rtm_drand(void) { return (double)rand()/(double)RAND_MAX; }
RTMDEF double rtm_drand_range(double min, double max) { return min + (max-min)*rtm_drand(); }

/* Simple integer hash (for procedural generation) */
RTMDEF uint32_t rtm_hash_u32(uint32_t x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

#endif // RTM_MATH_IMPLEMENTATION

#endif //!RTM_COMMON_H