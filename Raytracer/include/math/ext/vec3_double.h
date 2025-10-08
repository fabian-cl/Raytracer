#pragma once
// double vector 3 header file

#include "../detail/vec3_types.h"
#include "../detail/vec2_types.h"
#include "../detail/vec_define.h"

#include <math.h>

// CONSTRUCTION
static inline vec3 vec3_zero(void) { return (vec3) { 0 }; }
static inline vec3 vec3_one(void) {return VEC3_LITERAL(1.0,1.0,1.0);}
static inline void vec3_zero_ex(vec3* v) { v->x = 0; v->y = 0; v->z = 0; }

static inline vec3 vec3_construct(double x, double y, double z) {
	return (vec3) { x, y, z };
}

static inline vec3 vec3_construct_uniform(double value) {
	return (vec3) { value, value, value };
}

static inline vec3 vec3_construct_from_vec2(const vec2* v) {
	return (vec3) { v->x, v->y, 0 };
}

/* COPY */
static inline void vec3_copy(vec3* out, const vec3* src)
{
	out->x = src->x;
	out->y = src->y;
	out->z = src->z;
}

static inline vec3 vec3_clone(const vec3* src) { return *src; }

// GETTERS AND SETTERS
static inline double vec3_get_x(const vec3* v) { return v->x; }

static inline double vec3_get_y(const vec3* v) { return v->y; }

static inline double vec3_get_z(const vec3* v) { return v->z; }

static inline void vec3_set_x(vec3* v, double x) { v->x = x; }

static inline void vec3_set_y(vec3* v, double y) { v->y = y; }

static inline void vec3_set_z(vec3* v, double z) { v->z = z; }

// MATH FUNCTIONS
static inline vec3 vec3_add(const vec3* v, const vec3* u) {
	return (vec3) { u->x + v->x, u->y + v->y, u->z + v->z };
}

static inline void vec3_add_ex(vec3* out, const vec3* v, const vec3* u) {
	out->x = v->x + u->x;
	out->y = v->y + u->y;
	out->z = v->z + u->z;
}

static inline vec3 vec3_sub(const vec3* v, const vec3* u) {
	return (vec3)
	{
		v->x - u->x,
			v->y - u->y,
			v->z - u->z
	};
}

static inline void vec3_sub_ex(vec3* out, const vec3* v, const vec3* u) {
	out->x = v->x - u->x;
	out->y = v->y - u->y;
	out->z = v->z - u->z;
}

static inline vec3 vec3_mult(const vec3* v, double t)
{
	return (vec3) { v->x* t, v->y* t, v->z* t };
}
static inline void vec3_mult_ex(vec3* out, const vec3* v, double t)
{
	out->x = v->x * t;
	out->y = v->y * t;
	out->z = v->z * t;
}

static inline vec3 vec3_div(const vec3* v, double t)
{
	return (vec3) { v->x / t, v->y / t, v->z / t };
}
static inline void vec3_div_ex(vec3* out, const vec3* v, double t)
{
	out->x = v->x / t;
	out->y = v->y / t;
	out->z = v->z / t;
}

static inline double vec3_length_squared(const vec3* v) {
	return	v->x * v->x + v->y * v->y + v->z * v->z;
}

static inline double vec3_length(const vec3* v) {
	return sqrt(vec3_length_squared(v));
}

static inline void vec3_normalize(vec3* v) {
	double len = vec3_length(v);

	v->x /= len;
	v->y /= len;
	v->z /= len;
}

static inline void vec3_normalize_ex(vec3* out, const vec3* v) {
	double len = vec3_length(v);

	out->x = v->x / len;
	out->y = v->y / len;
	out->z = v->z / len;
}

static inline double vec3_dot(const vec3* v, const vec3* u) {
	return	v->x * u->x +
		v->y * u->y +
		v->z * u->z;
}

static inline vec3 vec3_cross(const vec3* a,const vec3* b){
	return (vec3){
		a->y * b->z - a->z * b->y,
		a->z * b->x - a->x * b->z,
		a->x * b->y - a->y * b->x
		};
	}

static inline void vec3_cross_ex(vec3* out, const vec3* v, const vec3* u) {
		out->x = u->y * v->z - u->z * v->y,
		out->y = u->z * v->x - u->x * v->z,
		out->z = u->x * v->y - u->y * v->x;
}

static inline vec3 vec3_neg(const vec3* v) {
	return (vec3) { -v->x, -v->y, -v->z };
}

static inline void vec3_neg_ex(vec3* out, const vec3* v) {
	out->x = -v->x;
	out->y = -v->y;
	out->z = -v->z;
}

static inline vec3 vec3_hadamard(const vec3* u, const vec3* v)
{
	return (vec3) {
		v->x* u->x,
			v->y* u->y,
			v->z* u->z
	};
}

static inline double vec3_distance(const vec3* a, const vec3* b) {
	double dx = a->x - b->x;
	double dy = a->y - b->y;
	double dz = a->z - b->z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

static inline vec3 vec3_reflect(const vec3* v, const vec3* n) {
	// r = v - 2 * dot(v,n) * n
	double d = v->x * n->x + v->y * n->y + v->z * n->z;
	double k = 2.0 * d;
	return (vec3) {
		v->x - k * n->x,
			v->y - k * n->y,
			v->z - k * n->z
	};
}
