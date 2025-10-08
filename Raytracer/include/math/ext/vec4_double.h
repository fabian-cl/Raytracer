// double vector 4 header file
#pragma once

#include <math.h>

#include "../detail/vec2_types.h"
#include "../detail/vec3_types.h"
#include "../detail/vec4_types.h"
#include "../detail/vec_define.h"

/*===========================================================
 * vec4 Constructors
 *===========================================================*/
static inline vec4 vec4_zero(void) { return (vec4) { 0 }; }
static inline vec4 vec4_one(void) {return VEC4_LITERAL(1.0,1.0,1.0,1.0);}
static inline void vec4_zero_ex(vec4* v) { v->x = 0; v->y = 0; v->z = 0; v->w = 0; }

static inline vec4 vec4_construct(double x, double y, double z, double w) { return (vec4) { x, y, z, w }; }
static inline vec4 vec4_construct_uniform(double v) { return (vec4) { v, v, v, v }; }

static inline vec4 vec4_construct_from_vec3(const vec3* v) {
    return (vec4) { v->x, v->y, v->z, 0 };
}

static inline vec4 vec4_construct_from_vec2(const vec2* v) {
    return (vec4) { v->x, v->y, 0, 0 };
}

/* COPY */
static inline void vec4_copy(vec4* out, const vec4* src)
{
    out->x = src->x;
    out->y = src->y;
    out->z = src->z;
    out->w = src->w;
}

static inline vec4 vec4_clone(const vec4* src) { return *src; }

/*===========================================================
 * vec4 Getters / Setters
 *===========================================================*/
static inline double vec4_get_x(const vec4* v) { return v->x; }
static inline double vec4_get_y(const vec4* v) { return v->y; }
static inline double vec4_get_z(const vec4* v) { return v->z; }
static inline double vec4_get_w(const vec4* v) { return v->w; }

static inline void vec4_set_x(vec4* v, double x) { v->x = x; }
static inline void vec4_set_y(vec4* v, double y) { v->y = y; }
static inline void vec4_set_z(vec4* v, double z) { v->z = z; }
static inline void vec4_set_w(vec4* v, double w) { v->w = w; }

/*===========================================================
 * vec4 Math
 *===========================================================*/
static inline vec4 vec4_add(const vec4* a, const vec4* b) {
    return (vec4) { a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w };
}
static inline void vec4_add_ex(vec4* out, const vec4* a, const vec4* b) {
    out->x = a->x + b->x; out->y = a->y + b->y; out->z = a->z + b->z; out->w = a->w + b->w;
}

static inline vec4 vec4_sub(const vec4* a, const vec4* b) {
    return (vec4) { a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w };
}
static inline void vec4_sub_ex(vec4* out, const vec4* a, const vec4* b) {
    out->x = a->x - b->x; out->y = a->y - b->y; out->z = a->z - b->z; out->w = a->w - b->w;
}

static inline vec4 vec4_mult(const vec4* v, double s) {
    return (vec4) { v->x* s, v->y* s, v->z* s, v->w* s };
}
static inline void vec4_mult_ex(vec4* out, const vec4* v, double s) {
    out->x = v->x * s; out->y = v->y * s; out->z = v->z * s; out->w = v->w * s;
}

static inline vec4 vec4_div(const vec4* v, double s) {
    return (vec4) { v->x / s, v->y / s, v->z / s, v->w / s };
}
static inline void vec4_div_ex(vec4* out, const vec4* v, double s) {
    out->x = v->x / s; out->y = v->y / s; out->z = v->z / s; out->w = v->w / s;
}

static inline double vec4_length_squared(const vec4* v) {
    return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}
static inline double vec4_length(const vec4* v) { return sqrt(vec4_length_squared(v)); }

static inline void vec4_normalize(vec4* v) {
    double l = vec4_length(v);
    v->x /= l; v->y /= l; v->z /= l; v->w /= l;
}
static inline void vec4_normalize_ex(vec4* out, const vec4* v) {
    double l = vec4_length(v);
    out->x = v->x / l; out->y = v->y / l; out->z = v->z / l; out->w = v->w / l;
}

static inline double vec4_dot(const vec4* a, const vec4* b) {
    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}
static inline double vec4_distance(const vec4* a, const vec4* b) {
    double dx = a->x - b->x, dy = a->y - b->y, dz = a->z - b->z, dw = a->w - b->w;
    return sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
}

static inline vec4 vec4_neg(const vec4* v) { return (vec4) { -v->x, -v->y, -v->z, -v->w }; }
static inline void vec4_neg_ex(vec4* out, const vec4* v) {
    out->x = -v->x; out->y = -v->y; out->z = -v->z; out->w = -v->w;
}

static inline vec4 vec4_hadamard(const vec4* a, const vec4* b) {
    return (vec4) { a->x* b->x, a->y* b->y, a->z* b->z, a->w* b->w };
}