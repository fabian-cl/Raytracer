#ifndef RTM_VEC4_DOUBLE_H
#define RTM_VEC4_DOUBLE_H

#ifdef __cplusplus
extern "C" {
#endif

// double vector 4 header file

#include "../detail/vec2_types.h"
#include "../detail/vec3_types.h"
#include "../detail/vec4_types.h"
#include "../detail/vec_define.h"

// DEFINITION
/*===========================================================
 * Constructors
 *===========================================================*/
/**
 * @brief Returns a zero vector (0, 0, 0, 0).
 */
RTMDEF rtm_dvec4 rtm_dvec4_zero(void);

/**
 * @brief Returns a vector with all components set to one (1, 1, 1, 1).
 */
RTMDEF rtm_dvec4 rtm_dvec4_one(void);

/**
 * @brief Sets the output vector to zero.
 * @param out Output vector.
 */
RTMDEF void rtm_dvec4_zero_to(rtm_dvec4* out);

/**
 * @brief Constructs a vector from four components.
 * @param x X component.
 * @param y Y component.
 * @param z Z component.
 * @param w W component.
 */
RTMDEF rtm_dvec4 rtm_dvec4_construct(double x, double y, double z, double w);

/**
 * @brief Constructs a vector with all components set to the same value.
 * @param v Scalar value to set.
 */
RTMDEF rtm_dvec4 rtm_dvec4_construct_uniform(double v);

/**
 * @brief Constructs a 4D vector from a 3D vector, setting w = 0.
 * @param v Input 3D vector.
 */
RTMDEF rtm_dvec4 rtm_dvec4_construct_from_rtm_dvec3(const rtm_dvec3* v);

/**
 * @brief Constructs a 4D vector from a 2D vector, setting z = w = 0.
 * @param v Input 2D vector.
 */
RTMDEF rtm_dvec4 rtm_dvec4_construct_from_rtm_dvec2(const rtm_dvec2* v);

/*===========================================================
 * Copy / Clone
 *===========================================================*/

/**
 * @brief Copies one vector to another.
 * @param out Output vector.
 * @param src Source vector.
 */
RTMDEF void rtm_dvec4_copy(rtm_dvec4* out, const rtm_dvec4* src);

/**
 * @brief Returns a copy of the source vector.
 * @param src Source vector.
 */
RTMDEF rtm_dvec4 rtm_dvec4_clone(const rtm_dvec4* src);

/*===========================================================
 * Getters / Setters
 *===========================================================*/

/**
 * @brief Returns the X component of the vector.
 */
RTMDEF double rtm_dvec4_get_x(const rtm_dvec4* v);

/**
 * @brief Returns the Y component of the vector.
 */
RTMDEF double rtm_dvec4_get_y(const rtm_dvec4* v);

/**
 * @brief Returns the Z component of the vector.
 */
RTMDEF double rtm_dvec4_get_z(const rtm_dvec4* v);

/**
 * @brief Returns the W component of the vector.
 */
RTMDEF double rtm_dvec4_get_w(const rtm_dvec4* v);

/**
 * @brief Sets the X component of the vector.
 */
RTMDEF void rtm_dvec4_set_x(rtm_dvec4* v, double x);

/**
 * @brief Sets the Y component of the vector.
 */
RTMDEF void rtm_dvec4_set_y(rtm_dvec4* v, double y);

/**
 * @brief Sets the Z component of the vector.
 */
RTMDEF void rtm_dvec4_set_z(rtm_dvec4* v, double z);

/**
 * @brief Sets the W component of the vector.
 */
RTMDEF void rtm_dvec4_set_w(rtm_dvec4* v, double w);

/*===========================================================
 * Math Operations
 *===========================================================*/

/**
 * @brief Adds two vectors (result = a + b).
 */
RTMDEF rtm_dvec4 rtm_dvec4_add(const rtm_dvec4* a, const rtm_dvec4* b);

/**
 * @brief Adds two vectors and stores the result in `out`.
 */
RTMDEF void rtm_dvec4_add_to(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b);

/**
 * @brief Adds another vector to this one in place (a += b).
 */
RTMDEF void rtm_dvec4_add_inplace(rtm_dvec4* a, const rtm_dvec4* b);

/**
 * @brief Subtracts two vectors (result = a - b).
 */
RTMDEF rtm_dvec4 rtm_dvec4_sub(const rtm_dvec4* a, const rtm_dvec4* b);

/**
 * @brief Subtracts two vectors and stores the result in `out`.
 */
RTMDEF void rtm_dvec4_sub_to(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b);

/**
 * @brief Subtracts another vector from this one in place (a -= b).
 */
RTMDEF void rtm_dvec4_sub_inplace(rtm_dvec4* a, const rtm_dvec4* b);

/**
 * @brief Multiplies a vector by a scalar (result = v * s).
 */
RTMDEF rtm_dvec4 rtm_dvec4_mult(const rtm_dvec4* v, double s);

/**
 * @brief Multiplies a vector by a scalar and stores the result in `out`.
 */
RTMDEF void rtm_dvec4_mult_to(rtm_dvec4* out, const rtm_dvec4* v, double s);

/**
 * @brief Multiplies a vector by a scalar in place (v *= s).
 */
RTMDEF void rtm_dvec4_mult_inplace(rtm_dvec4* v, double s);

/**
 * @brief Divides a vector by a scalar (result = v / s).
 */
RTMDEF rtm_dvec4 rtm_dvec4_div(const rtm_dvec4* v, double s);

/**
 * @brief Divides a vector by a scalar and stores the result in `out`.
 */
RTMDEF void rtm_dvec4_div_to(rtm_dvec4* out, const rtm_dvec4* v, double s);

/**
 * @brief Divides a vector by a scalar in place (v /= s).
 */
RTMDEF void rtm_dvec4_div_inplace(rtm_dvec4* v, double s);

/**
 * @brief Returns the squared length of the vector.
 */
RTMDEF double rtm_dvec4_length_squared(const rtm_dvec4* v);

/**
 * @brief Returns the Euclidean length of the vector.
 */
RTMDEF double rtm_dvec4_length(const rtm_dvec4* v);

/**
 * @brief Normalizes a vector in place (v = normalize(v)).
 */
RTMDEF void rtm_dvec4_normalize(rtm_dvec4* v);

/**
 * @brief Normalizes `v` and stores the result in `out`.
 */
RTMDEF void rtm_dvec4_normalize_to(rtm_dvec4* out, const rtm_dvec4* v);

/**
 * @brief Normalizes a vector in place (alias for `rtm_dvec4_normalize`).
 */
RTMDEF void rtm_dvec4_normalize_inplace(rtm_dvec4* v);

/**
 * @brief Computes the dot product between two vectors.
 */
RTMDEF double rtm_dvec4_dot(const rtm_dvec4* a, const rtm_dvec4* b);

/**
 * @brief Computes the Euclidean distance between two vectors.
 */
RTMDEF double rtm_dvec4_distance(const rtm_dvec4* a, const rtm_dvec4* b);

/**
 * @brief Returns the negated vector (result = -v).
 */
RTMDEF rtm_dvec4 rtm_dvec4_neg(const rtm_dvec4* v);

/**
 * @brief Negates a vector and stores the result in `out`.
 */
RTMDEF void rtm_dvec4_neg_to(rtm_dvec4* out, const rtm_dvec4* v);

/**
 * @brief Negates a vector in place.
 */
RTMDEF void rtm_dvec4_neg_inplace(rtm_dvec4* v);

/**
 * @brief Performs element-wise multiplication (Hadamard product) of two vectors.
 */
RTMDEF rtm_dvec4 rtm_dvec4_hadamard(const rtm_dvec4* a, const rtm_dvec4* b);

/**
 * @brief Performs element-wise multiplication and stores the result in `out`.
 */
RTMDEF void rtm_dvec4_hadamard_to(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b);
// IMPLEMENTATION
#ifdef RTM_IMPLEMENTATION

#ifndef RT_MATH
#define RT_MATH
#include <math.h>
#endif

/*===========================================================
 * rtm_dvec4 Constructors
 *===========================================================*/
RTMDEF rtm_dvec4 rtm_dvec4_zero(void) { return (rtm_dvec4) { 0 }; }
RTMDEF rtm_dvec4 rtm_dvec4_one(void) {return VEC4_LITERAL(1.0,1.0,1.0,1.0);}
RTMDEF void rtm_dvec4_zero_to(rtm_dvec4* v) { v->x = 0; v->y = 0; v->z = 0; v->w = 0; }

RTMDEF rtm_dvec4 rtm_dvec4_construct(double x, double y, double z, double w) { return (rtm_dvec4) { x, y, z, w }; }
RTMDEF rtm_dvec4 rtm_dvec4_construct_uniform(double v) { return (rtm_dvec4) { v, v, v, v }; }

RTMDEF rtm_dvec4 rtm_dvec4_construct_from_rtm_dvec3(const rtm_dvec3* v) {
    return (rtm_dvec4) { v->x, v->y, v->z, 0 };
}

RTMDEF rtm_dvec4 rtm_dvec4_construct_from_rtm_dvec2(const rtm_dvec2* v) {
    return (rtm_dvec4) { v->x, v->y, 0, 0 };
}

/* COPY */
RTMDEF void rtm_dvec4_copy(rtm_dvec4* out, const rtm_dvec4* src)
{
    out->x = src->x;
    out->y = src->y;
    out->z = src->z;
    out->w = src->w;
}

RTMDEF rtm_dvec4 rtm_dvec4_clone(const rtm_dvec4* src) { return *src; }

/*===========================================================
 * rtm_dvec4 Getters / Setters
 *===========================================================*/
RTMDEF double rtm_dvec4_get_x(const rtm_dvec4* v) { return v->x; }
RTMDEF double rtm_dvec4_get_y(const rtm_dvec4* v) { return v->y; }
RTMDEF double rtm_dvec4_get_z(const rtm_dvec4* v) { return v->z; }
RTMDEF double rtm_dvec4_get_w(const rtm_dvec4* v) { return v->w; }

RTMDEF void rtm_dvec4_set_x(rtm_dvec4* v, double x) { v->x = x; }
RTMDEF void rtm_dvec4_set_y(rtm_dvec4* v, double y) { v->y = y; }
RTMDEF void rtm_dvec4_set_z(rtm_dvec4* v, double z) { v->z = z; }
RTMDEF void rtm_dvec4_set_w(rtm_dvec4* v, double w) { v->w = w; }

/*===========================================================
 * rtm_dvec4 Math
 *===========================================================*/
RTMDEF rtm_dvec4 rtm_dvec4_add(const rtm_dvec4* a, const rtm_dvec4* b) {
    return (rtm_dvec4) { a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w };
}
RTMDEF void rtm_dvec4_add_to(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b) {
    out->x = a->x + b->x; out->y = a->y + b->y; out->z = a->z + b->z; out->w = a->w + b->w;
}

RTMDEF void rtm_dvec4_add_inplace(rtm_dvec4* a, const rtm_dvec4* b); {
    a->x =+ b->x; 
    a->y =+ b->y; 
    a->z =+ b->z; 
    a->w =+ b->w;
}

RTMDEF rtm_dvec4 rtm_dvec4_sub(const rtm_dvec4* a, const rtm_dvec4* b) {
    return (rtm_dvec4) { a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w };
}
RTMDEF void rtm_dvec4_sub_to(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b) {
    out->x = a->x - b->x; out->y = a->y - b->y; out->z = a->z - b->z; out->w = a->w - b->w;
}

RTMDEF void rtm_dvec4_sub_inplace(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b) {
    a->x =- b->x; 
    a->y =- b->y; 
    a->z =- b->z; 
    a->w =- b->w;
}

RTMDEF rtm_dvec4 rtm_dvec4_mult(const rtm_dvec4* v, double s) {
    return (rtm_dvec4) { v->x* s, v->y* s, v->z* s, v->w* s };
}
RTMDEF void rtm_dvec4_mult_to(rtm_dvec4* out, const rtm_dvec4* v, double s) {
    out->x = v->x * s; out->y = v->y * s; out->z = v->z * s; out->w = v->w * s;
}
RTMDEF void rtm_dvec4_mult_inplace(rtm_dvec4* v, double s) {
    v->x =* s; 
    v->y =* s; 
    v->z =* s; 
    v->w =* s;
}

RTMDEF rtm_dvec4 rtm_dvec4_div(const rtm_dvec4* v, double s) {
    return (rtm_dvec4) { v->x / s, v->y / s, v->z / s, v->w / s };
}
RTMDEF void rtm_dvec4_div_to(rtm_dvec4* out, const rtm_dvec4* v, double s) {
    out->x = v->x / s; out->y = v->y / s; out->z = v->z / s; out->w = v->w / s;
}

RTMDEF void rtm_dvec4_div_inplace(rtm_dvec4* v, double s) {
    v->x =/ s; 
    v->y =/ s; 
    v->z =/ s; 
    v->w =/ s;
}

RTMDEF double rtm_dvec4_length_squared(const rtm_dvec4* v) {
    return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}
RTMDEF double rtm_dvec4_length(const rtm_dvec4* v) { return sqrt(rtm_dvec4_length_squared(v)); }

RTMDEF void rtm_dvec4_normalize(rtm_dvec4* v) {
    double l = rtm_dvec4_length(v);
    v->x /= l; v->y /= l; v->z /= l; v->w /= l;
}
RTMDEF void rtm_dvec4_normalize_to(rtm_dvec4* out, const rtm_dvec4* v) {
    double l = rtm_dvec4_length(v);
    out->x = v->x / l; out->y = v->y / l; out->z = v->z / l; out->w = v->w / l;
}

RTMDEF void rtm_dvec4_normalize_inplace(rtm_dvec4* v) {
    double l = rtm_dvec4_length(v);
    rtm_dvec4_div_inplace(v, l);
}

RTMDEF double rtm_dvec4_dot(const rtm_dvec4* a, const rtm_dvec4* b) {
    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}
RTMDEF double rtm_dvec4_distance(const rtm_dvec4* a, const rtm_dvec4* b) {
    double dx = a->x - b->x, dy = a->y - b->y, dz = a->z - b->z, dw = a->w - b->w;
    return sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
}

RTMDEF rtm_dvec4 rtm_dvec4_neg(const rtm_dvec4* v) { return (rtm_dvec4) { -v->x, -v->y, -v->z, -v->w }; }
RTMDEF void rtm_dvec4_neg_to(rtm_dvec4* out, const rtm_dvec4* v) {
    out->x = -v->x; out->y = -v->y; out->z = -v->z; out->w = -v->w;
}

RTMDEF void rtm_dvec4_neg_inplace(rtm_dvec4* v) {
    v->x = -v->x; v->y = -v->y; v->z = -v->z; v->w = -v->w;
}

RTMDEF rtm_dvec4 rtm_dvec4_hadamard(const rtm_dvec4* a, const rtm_dvec4* b) {
    return (rtm_dvec4) { a->x* b->x, a->y* b->y, a->z* b->z, a->w* b->w };
}

RTMDEF rtm_dvec4 rtm_dvec4_hadamard_to(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b) {
    *out = rtm_dvec4_hadamard(a, b);
}

#endif //!RTM_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif //!RTM_VEC4_DOUBLE_H