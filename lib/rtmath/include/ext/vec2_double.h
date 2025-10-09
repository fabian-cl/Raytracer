#ifndef RTM_VEC2_DOUBLE_H
#define RTM_VEC2_DOUBLE_H
// double vector 2 header file

#ifdef __cplusplus
extern "C" {
#endif

#include "../detail/vec2_types.h"
#include "../detail/vec_define.h"

// DECLARATION
/*===========================================================
 *  rtm_dvec2 Constructors
 *===========================================================*/
RTMDEF rtm_dvec2 rtm_dvec2_zero(void);
RTMDEF rtm_dvec2 rtm_dvec2_one(void);
RTMDEF rtm_dvec2 rtm_dvec2_construct(double x, double y);
RTMDEF rtm_dvec2 rtm_dvec2_construct_uniform(double v);

/*
 *  COPY
 */
RTMDEF void rtm_dvec2_copy(rtm_dvec2* out, const rtm_dvec2* src);
RTMDEF rtm_dvec2 rtm_dvec2_clone(const rtm_dvec2* src);

/*===========================================================
 *  rtm_dvec2 Getters / Setters
 *===========================================================*/
RTMDEF double rtm_dvec2_get_x(const rtm_dvec2* v);
RTMDEF double rtm_dvec2_get_y(const rtm_dvec2* v);
RTMDEF void   rtm_dvec2_set_x(rtm_dvec2* v, double x);
RTMDEF void   rtm_dvec2_set_y(rtm_dvec2* v, double y);

/*===========================================================
 *  rtm_dvec2 Math
 *===========================================================*/
RTMDEF rtm_dvec2 rtm_dvec2_add(const rtm_dvec2* a, const rtm_dvec2* b);
RTMDEF void rtm_dvec2_add_ex(rtm_dvec2* out, const rtm_dvec2* a, const rtm_dvec2* b);
RTMDEF rtm_dvec2 rtm_dvec2_sub(const rtm_dvec2* a, const rtm_dvec2* b);
RTMDEF void rtm_dvec2_sub_ex(rtm_dvec2* out, const rtm_dvec2* a, const rtm_dvec2* b);
RTMDEF rtm_dvec2 rtm_dvec2_mult(const rtm_dvec2* v, double s);
RTMDEF void rtm_dvec2_mult_ex(rtm_dvec2* out, const rtm_dvec2* v, double s);
RTMDEF rtm_dvec2 rtm_dvec2_div(const rtm_dvec2* v, double s);
RTMDEF void rtm_dvec2_div_ex(rtm_dvec2* out, const rtm_dvec2* v, double s);
RTMDEF double rtm_dvec2_length_squared(const rtm_dvec2* v);
RTMDEF double rtm_dvec2_length(const rtm_dvec2* v);
RTMDEF void rtm_dvec2_normalize(rtm_dvec2* v);
RTMDEF void rtm_dvec2_normalize_ex(rtm_dvec2* out, const rtm_dvec2* v);
RTMDEF double rtm_dvec2_dot(const rtm_dvec2* a, const rtm_dvec2* b);
RTMDEF double rtm_dvec2_distance(const rtm_dvec2* a, const rtm_dvec2* b);
RTMDEF rtm_dvec2 rtm_dvec2_neg(const rtm_dvec2* v);
RTMDEF void rtm_dvec2_neg_ex(rtm_dvec2* out, const rtm_dvec2* v);
RTMDEF rtm_dvec2 rtm_dvec2_hadamard(const rtm_dvec2* a, const rtm_dvec2* b);

// IMPLEMENTATION
#ifdef RTM_IMPLEMENTATION

#ifndef RT_MATH
#define RT_MATH
#include <math.h>
#endif

/*===========================================================
 *  rtm_dvec2 Constructors
 *===========================================================*/
RTMDEF rtm_dvec2 rtm_dvec2_zero(void) { return VEC2_LITERAL(0.0, 0.0); }
RTMDEF rtm_dvec2 rtm_dvec2_one(void) {return VEC2_LITERAL(1.0,1.0);}
RTMDEF rtm_dvec2 rtm_dvec2_construct(double x, double y) { return VEC2_LITERAL(x, y); }
RTMDEF rtm_dvec2 rtm_dvec2_construct_uniform(double v) { return VEC2_LITERAL(v, v); }

/*
 *  COPY
 */
RTMDEF void rtm_dvec2_copy(rtm_dvec2* out, const rtm_dvec2* src)
{
    out->x = src->x;
    out->y = src->y;
}

RTMDEF rtm_dvec2 rtm_dvec2_clone(const rtm_dvec2* src) { return *src; }

/*===========================================================
 *  rtm_dvec2 Getters / Setters
 *===========================================================*/
RTMDEF double rtm_dvec2_get_x(const rtm_dvec2* v) { return v->x; }
RTMDEF double rtm_dvec2_get_y(const rtm_dvec2* v) { return v->y; }
RTMDEF void   rtm_dvec2_set_x(rtm_dvec2* v, double x) { v->x = x; }
RTMDEF void   rtm_dvec2_set_y(rtm_dvec2* v, double y) { v->y = y; }

/*===========================================================
 *  rtm_dvec2 Math
 *===========================================================*/
RTMDEF rtm_dvec2 rtm_dvec2_add(const rtm_dvec2* a, const rtm_dvec2* b)
{
    return VEC2_LITERAL(a->x + b->x, a->y + b->y);
}

RTMDEF void rtm_dvec2_add_ex(rtm_dvec2* out, const rtm_dvec2* a, const rtm_dvec2* b)
{
    out->x = a->x + b->x; out->y = a->y + b->y;
}

RTMDEF rtm_dvec2 rtm_dvec2_sub(const rtm_dvec2* a, const rtm_dvec2* b)
{
    return VEC2_LITERAL(a->x - b->x, a->y - b->y);
}

RTMDEF void rtm_dvec2_sub_ex(rtm_dvec2* out, const rtm_dvec2* a, const rtm_dvec2* b)
{
    out->x = a->x - b->x; out->y = a->y - b->y;
}

RTMDEF rtm_dvec2 rtm_dvec2_mult(const rtm_dvec2* v, double s)
{
    return VEC2_LITERAL(v->x * s, v->y * s);
}

RTMDEF void rtm_dvec2_mult_ex(rtm_dvec2* out, const rtm_dvec2* v, double s)
{
    out->x = v->x * s; out->y = v->y * s;
}

RTMDEF rtm_dvec2 rtm_dvec2_div(const rtm_dvec2* v, double s)
{
    return VEC2_LITERAL(v->x / s, v->y / s);
}

RTMDEF void rtm_dvec2_div_ex(rtm_dvec2* out, const rtm_dvec2* v, double s)
{
    out->x = v->x / s; out->y = v->y / s;
}

RTMDEF double rtm_dvec2_length_squared(const rtm_dvec2* v)
{
    return v->x * v->x + v->y * v->y;
}

RTMDEF double rtm_dvec2_length(const rtm_dvec2* v)
{
    return sqrt(rtm_dvec2_length_squared(v));
}

RTMDEF void rtm_dvec2_normalize(rtm_dvec2* v)
{
    double l = rtm_dvec2_length(v); v->x /= l; v->y /= l;
}

RTMDEF void rtm_dvec2_normalize_ex(rtm_dvec2* out, const rtm_dvec2* v)
{
    double l = rtm_dvec2_length(v); out->x = v->x / l; out->y = v->y / l;
}

RTMDEF double rtm_dvec2_dot(const rtm_dvec2* a, const rtm_dvec2* b)
{
    return a->x * b->x + a->y * b->y;
}

RTMDEF double rtm_dvec2_distance(const rtm_dvec2* a, const rtm_dvec2* b)
{
    double dx = a->x - b->x, dy = a->y - b->y;
    return sqrt(dx * dx + dy * dy);
}

RTMDEF rtm_dvec2 rtm_dvec2_neg(const rtm_dvec2* v)
{
    return VEC2_LITERAL(-v->x, -v->y);
}

RTMDEF void rtm_dvec2_neg_ex(rtm_dvec2* out, const rtm_dvec2* v)
{
    out->x = -v->x; out->y = -v->y;
}

RTMDEF rtm_dvec2 rtm_dvec2_hadamard(const rtm_dvec2* a, const rtm_dvec2* b)
{
    return VEC2_LITERAL(a->x * b->x, a->y * b->y);
}

#endif // !#RTM_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif //!RTM_VEC2_DOUBLE_H