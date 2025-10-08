#pragma once

// double vector 2 header file

#include "../detail/vec2_types.h"
#include "../detail/vec_define.h"

/*===========================================================
 *  vec2 Constructors
 *===========================================================*/
static inline vec2 vec2_zero(void) { return VEC2_LITERAL(0.0, 0.0); }
static inline vec2 vec2_one(void) {return VEC2_LITERAL(1.0,1.0);}
static inline vec2 vec2_construct(double x, double y) { return VEC2_LITERAL(x, y); }
static inline vec2 vec2_construct_uniform(double v) { return VEC2_LITERAL(v, v); }

/*
 *  COPY
 */
static inline void vec2_copy(vec2* out, const vec2* src)
{
    out->x = src->x;
    out->y = src->y;
}

static inline vec2 vec2_clone(const vec2* src) { return *src; }

/*===========================================================
 *  vec2 Getters / Setters
 *===========================================================*/
static inline double vec2_get_x(const vec2* v) { return v->x; }
static inline double vec2_get_y(const vec2* v) { return v->y; }
static inline void   vec2_set_x(vec2* v, double x) { v->x = x; }
static inline void   vec2_set_y(vec2* v, double y) { v->y = y; }

/*===========================================================
 *  vec2 Math
 *===========================================================*/
static inline vec2 vec2_add(const vec2* a, const vec2* b)
{
    return VEC2_LITERAL(a->x + b->x, a->y + b->y);
}

static inline void vec2_add_ex(vec2* out, const vec2* a, const vec2* b)
{
    out->x = a->x + b->x; out->y = a->y + b->y;
}

static inline vec2 vec2_sub(const vec2* a, const vec2* b)
{
    return VEC2_LITERAL(a->x - b->x, a->y - b->y);
}

static inline void vec2_sub_ex(vec2* out, const vec2* a, const vec2* b)
{
    out->x = a->x - b->x; out->y = a->y - b->y;
}

static inline vec2 vec2_mult(const vec2* v, double s)
{
    return VEC2_LITERAL(v->x * s, v->y * s);
}

static inline void vec2_mult_ex(vec2* out, const vec2* v, double s)
{
    out->x = v->x * s; out->y = v->y * s;
}

static inline vec2 vec2_div(const vec2* v, double s)
{
    return VEC2_LITERAL(v->x / s, v->y / s);
}

static inline void vec2_div_ex(vec2* out, const vec2* v, double s)
{
    out->x = v->x / s; out->y = v->y / s;
}

static inline double vec2_length_squared(const vec2* v)
{
    return v->x * v->x + v->y * v->y;
}

static inline double vec2_length(const vec2* v)
{
    return sqrt(vec2_length_squared(v));
}

static inline void vec2_normalize(vec2* v)
{
    double l = vec2_length(v); v->x /= l; v->y /= l;
}

static inline void vec2_normalize_ex(vec2* out, const vec2* v)
{
    double l = vec2_length(v); out->x = v->x / l; out->y = v->y / l;
}

static inline double vec2_dot(const vec2* a, const vec2* b)
{
    return a->x * b->x + a->y * b->y;
}

static inline double vec2_distance(const vec2* a, const vec2* b)
{
    double dx = a->x - b->x, dy = a->y - b->y;
    return sqrt(dx * dx + dy * dy);
}

static inline vec2 vec2_neg(const vec2* v)
{
    return VEC2_LITERAL(-v->x, -v->y);
}

static inline void vec2_neg_ex(vec2* out, const vec2* v)
{
    out->x = -v->x; out->y = -v->y;
}

static inline vec2 vec2_hadamard(const vec2* a, const vec2* b)
{
    return VEC2_LITERAL(a->x * b->x, a->y * b->y);
}
