#ifndef RTM_VEC2_DOUBLE_H
#define RTM_VEC2_DOUBLE_H

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
 * rtm_dvec4 Constructors
 *===========================================================*/
RTMDEF rtm_dvec4 rtm_dvec4_zero(void);
RTMDEF rtm_dvec4 rtm_dvec4_one(void);
RTMDEF void rtm_dvec4_zero_ex(rtm_dvec4* v);

RTMDEF rtm_dvec4 rtm_dvec4_construct(double x, double y, double z, double w);
RTMDEF rtm_dvec4 rtm_dvec4_construct_uniform(double v);

RTMDEF rtm_dvec4 rtm_dvec4_construct_from_rtm_dvec3(const rtm_dvec3* v);

RTMDEF rtm_dvec4 rtm_dvec4_construct_from_rtm_dvec2(const rtm_dvec2* v);

/* COPY */
RTMDEF void rtm_dvec4_copy(rtm_dvec4* out, const rtm_dvec4* src);

RTMDEF rtm_dvec4 rtm_dvec4_clone(const rtm_dvec4* src);

/*===========================================================
 * rtm_dvec4 Getters / Setters
 *===========================================================*/
RTMDEF double rtm_dvec4_get_x(const rtm_dvec4* v);
RTMDEF double rtm_dvec4_get_y(const rtm_dvec4* v);
RTMDEF double rtm_dvec4_get_z(const rtm_dvec4* v);
RTMDEF double rtm_dvec4_get_w(const rtm_dvec4* v);

RTMDEF void rtm_dvec4_set_x(rtm_dvec4* v, double x);
RTMDEF void rtm_dvec4_set_y(rtm_dvec4* v, double y);
RTMDEF void rtm_dvec4_set_z(rtm_dvec4* v, double z);
RTMDEF void rtm_dvec4_set_w(rtm_dvec4* v, double w);

/*===========================================================
 * rtm_dvec4 Math
 *===========================================================*/
RTMDEF rtm_dvec4 rtm_dvec4_add(const rtm_dvec4* a, const rtm_dvec4* b);
RTMDEF void rtm_dvec4_add_ex(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b);

RTMDEF rtm_dvec4 rtm_dvec4_sub(const rtm_dvec4* a, const rtm_dvec4* b);
RTMDEF void rtm_dvec4_sub_ex(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b);

RTMDEF rtm_dvec4 rtm_dvec4_mult(const rtm_dvec4* v, double s);
RTMDEF void rtm_dvec4_mult_ex(rtm_dvec4* out, const rtm_dvec4* v, double s);

RTMDEF rtm_dvec4 rtm_dvec4_div(const rtm_dvec4* v, double s);

RTMDEF void rtm_dvec4_div_ex(rtm_dvec4* out, const rtm_dvec4* v, double s);

RTMDEF double rtm_dvec4_length_squared(const rtm_dvec4* v);
RTMDEF double rtm_dvec4_length(const rtm_dvec4* v);

RTMDEF void rtm_dvec4_normalize(rtm_dvec4* v);
RTMDEF void rtm_dvec4_normalize_ex(rtm_dvec4* out, const rtm_dvec4* v);

RTMDEF double rtm_dvec4_dot(const rtm_dvec4* a, const rtm_dvec4* b);
RTMDEF double rtm_dvec4_distance(const rtm_dvec4* a, const rtm_dvec4* b);
RTMDEF rtm_dvec4 rtm_dvec4_neg(const rtm_dvec4* v);
RTMDEF void rtm_dvec4_neg_ex(rtm_dvec4* out, const rtm_dvec4* v);

RTMDEF rtm_dvec4 rtm_dvec4_hadamard(const rtm_dvec4* a, const rtm_dvec4* b);
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
RTMDEF void rtm_dvec4_zero_ex(rtm_dvec4* v) { v->x = 0; v->y = 0; v->z = 0; v->w = 0; }

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
RTMDEF void rtm_dvec4_add_ex(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b) {
    out->x = a->x + b->x; out->y = a->y + b->y; out->z = a->z + b->z; out->w = a->w + b->w;
}

RTMDEF rtm_dvec4 rtm_dvec4_sub(const rtm_dvec4* a, const rtm_dvec4* b) {
    return (rtm_dvec4) { a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w };
}
RTMDEF void rtm_dvec4_sub_ex(rtm_dvec4* out, const rtm_dvec4* a, const rtm_dvec4* b) {
    out->x = a->x - b->x; out->y = a->y - b->y; out->z = a->z - b->z; out->w = a->w - b->w;
}

RTMDEF rtm_dvec4 rtm_dvec4_mult(const rtm_dvec4* v, double s) {
    return (rtm_dvec4) { v->x* s, v->y* s, v->z* s, v->w* s };
}
RTMDEF void rtm_dvec4_mult_ex(rtm_dvec4* out, const rtm_dvec4* v, double s) {
    out->x = v->x * s; out->y = v->y * s; out->z = v->z * s; out->w = v->w * s;
}

RTMDEF rtm_dvec4 rtm_dvec4_div(const rtm_dvec4* v, double s) {
    return (rtm_dvec4) { v->x / s, v->y / s, v->z / s, v->w / s };
}
RTMDEF void rtm_dvec4_div_ex(rtm_dvec4* out, const rtm_dvec4* v, double s) {
    out->x = v->x / s; out->y = v->y / s; out->z = v->z / s; out->w = v->w / s;
}

RTMDEF double rtm_dvec4_length_squared(const rtm_dvec4* v) {
    return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}
RTMDEF double rtm_dvec4_length(const rtm_dvec4* v) { return sqrt(rtm_dvec4_length_squared(v)); }

RTMDEF void rtm_dvec4_normalize(rtm_dvec4* v) {
    double l = rtm_dvec4_length(v);
    v->x /= l; v->y /= l; v->z /= l; v->w /= l;
}
RTMDEF void rtm_dvec4_normalize_ex(rtm_dvec4* out, const rtm_dvec4* v) {
    double l = rtm_dvec4_length(v);
    out->x = v->x / l; out->y = v->y / l; out->z = v->z / l; out->w = v->w / l;
}

RTMDEF double rtm_dvec4_dot(const rtm_dvec4* a, const rtm_dvec4* b) {
    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}
RTMDEF double rtm_dvec4_distance(const rtm_dvec4* a, const rtm_dvec4* b) {
    double dx = a->x - b->x, dy = a->y - b->y, dz = a->z - b->z, dw = a->w - b->w;
    return sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
}

RTMDEF rtm_dvec4 rtm_dvec4_neg(const rtm_dvec4* v) { return (rtm_dvec4) { -v->x, -v->y, -v->z, -v->w }; }
RTMDEF void rtm_dvec4_neg_ex(rtm_dvec4* out, const rtm_dvec4* v) {
    out->x = -v->x; out->y = -v->y; out->z = -v->z; out->w = -v->w;
}

RTMDEF rtm_dvec4 rtm_dvec4_hadamard(const rtm_dvec4* a, const rtm_dvec4* b) {
    return (rtm_dvec4) { a->x* b->x, a->y* b->y, a->z* b->z, a->w* b->w };
}

#endif //!RTM_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif //!RTM_VEC4_DOUBLE_H