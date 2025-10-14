#ifndef RTM_VEC3_DOUBLE_H
#define RTM_VEC3_DOUBLE_H

#ifdef __cplusplus
extern "C" {
#endif
// double vector 3 header file

#include "../detail/vec3_types.h"
#include "../detail/vec2_types.h"
#include "../detail/vec_define.h"

// DEFINITION
// CONSTRUCTION

RTMDEF rtm_dvec3 rtm_dvec3_zero(void);
RTMDEF void rtm_dvec3_zero_to(rtm_dvec3* v);
RTMDEF rtm_dvec3 rtm_dvec3_one(void);

RTMDEF rtm_dvec3 rtm_dvec3_construct(double x, double y, double z);
RTMDEF void rtm_dvec3_construct_to(rtm_dvec3* out, double x, double y, double z);

RTMDEF rtm_dvec3 rtm_dvec3_construct_uniform(double value);
RTMDEF void rtm_dvec3_construct_uniform_to(rtm_dvec3* out, double value);

RTMDEF rtm_dvec3 rtm_dvec3_construct_from_rtm_dvec2(const rtm_dvec2* v);

/* COPY */
RTMDEF void rtm_dvec3_copy(rtm_dvec3* out, const rtm_dvec3* src);

RTMDEF rtm_dvec3 rtm_dvec3_clone(const rtm_dvec3* src);

// GETTERS AND SETTERS
RTMDEF double rtm_dvec3_get_x(const rtm_dvec3* v);
RTMDEF double rtm_dvec3_get_y(const rtm_dvec3* v);
RTMDEF double rtm_dvec3_get_z(const rtm_dvec3* v);

RTMDEF void rtm_dvec3_set_x(rtm_dvec3* v, double x);
RTMDEF void rtm_dvec3_set_y(rtm_dvec3* v, double y);
RTMDEF void rtm_dvec3_set_z(rtm_dvec3* v, double z);

// MATH FUNCTIONS
RTMDEF rtm_dvec3 rtm_dvec3_add(const rtm_dvec3* a, const rtm_dvec3* b);
RTMDEF void rtm_dvec3_add_to(rtm_dvec3* out, const rtm_dvec3* a, const rtm_dvec3* b);
RTMDEF void rtm_dvec3_add_inplace(rtm_dvec3* a, const rtm_dvec3* b);

RTMDEF rtm_dvec3 rtm_dvec3_sub(const rtm_dvec3* a, const rtm_dvec3* b);
RTMDEF void rtm_dvec3_sub_to(rtm_dvec3* out, const rtm_dvec3* a, const rtm_dvec3* b);
RTMDEF void rtm_dvec3_sub_inplace(rtm_dvec3* a, const rtm_dvec3* b);

RTMDEF rtm_dvec3 rtm_dvec3_mult(const rtm_dvec3* v, double t);
RTMDEF void rtm_dvec3_mult_to(rtm_dvec3* out, const rtm_dvec3* v, double t);
RTMDEF void rtm_dvec3_mult_inplace(rtm_dvec3* out, const rtm_dvec3* v, double t);

RTMDEF rtm_dvec3 rtm_dvec3_div(const rtm_dvec3* v, double t);
RTMDEF void rtm_dvec3_div_to(rtm_dvec3* out, const rtm_dvec3* v, double t);
RTMDEF void rtm_dvec3_div_inplace(rtm_dvec3* out, const rtm_dvec3* v, double t);

RTMDEF double rtm_dvec3_length_squared(const rtm_dvec3* v);
RTMDEF double rtm_dvec3_length(const rtm_dvec3* v);

RTMDEF void rtm_dvec3_normalize(rtm_dvec3* v);
RTMDEF void rtm_dvec3_normalize_to(rtm_dvec3* out, const rtm_dvec3* v);
RTMDEF void rtm_dvec3_normalize_inplace(rtm_dvec3* v);

RTMDEF double rtm_dvec3_dot(const rtm_dvec3* v, const rtm_dvec3* u);

RTMDEF rtm_dvec3 rtm_dvec3_cross(const rtm_dvec3* a,const rtm_dvec3* b);
RTMDEF void rtm_dvec3_cross_to(rtm_dvec3* out, const rtm_dvec3* v, const rtm_dvec3* u);

RTMDEF rtm_dvec3 rtm_dvec3_neg(const rtm_dvec3* v);
RTMDEF void rtm_dvec3_neg_to(rtm_dvec3* out, const rtm_dvec3* v);

RTMDEF rtm_dvec3 rtm_dvec3_hadamard(const rtm_dvec3* u, const rtm_dvec3* v);

RTMDEF double rtm_dvec3_distance(const rtm_dvec3* a, const rtm_dvec3* b);

RTMDEF rtm_dvec3 rtm_dvec3_reflect(const rtm_dvec3* v, const rtm_dvec3* n);

// refract

// IMPLEMENTATION
#ifdef RTM_IMPLEMENTATION

#ifndef RT_MATH
#define RT_MATH
#include <math.h>
#endif

// CONSTRUCTION
RTMDEF rtm_dvec3 rtm_dvec3_zero(void) { return (rtm_dvec3) { 0 }; }
RTMDEF rtm_dvec3 rtm_dvec3_one(void) {return VEC3_LITERAL(1.0,1.0,1.0);}
RTMDEF void rtm_dvec3_zero_to(rtm_dvec3* v) { v->x = 0; v->y = 0; v->z = 0; }

RTMDEF rtm_dvec3 rtm_dvec3_construct(double x, double y, double z) {
	return (rtm_dvec3) { x, y, z };
}

RTMDEF void rtm_dvec3_construct_to(rtm_dvec3* out, double x, double y, double z) {
	*out = (rtm_dvec3) { x, y, z };
}

RTMDEF rtm_dvec3 rtm_dvec3_construct_uniform(double value) {
	return (rtm_dvec3) { value, value, value };
}

RTMDEF void rtm_dvec3_construct_uniform_to(rtm_dvec3* out, double value) {
	*out = (rtm_dvec3) { value, value, value };
}

RTMDEF rtm_dvec3 rtm_dvec3_construct_from_rtm_dvec2(const rtm_dvec2* v) {
	return (rtm_dvec3) { v->x, v->y, 0 };
}

/* COPY */
RTMDEF void rtm_dvec3_copy(rtm_dvec3* out, const rtm_dvec3* src)
{
	out->x = src->x;
	out->y = src->y;
	out->z = src->z;
}

RTMDEF rtm_dvec3 rtm_dvec3_clone(const rtm_dvec3* src) { return *src; }

// GETTERS AND SETTERS
RTMDEF double rtm_dvec3_get_x(const rtm_dvec3* v) { return v->x; }

RTMDEF double rtm_dvec3_get_y(const rtm_dvec3* v) { return v->y; }

RTMDEF double rtm_dvec3_get_z(const rtm_dvec3* v) { return v->z; }

RTMDEF void rtm_dvec3_set_x(rtm_dvec3* v, double x) { v->x = x; }

RTMDEF void rtm_dvec3_set_y(rtm_dvec3* v, double y) { v->y = y; }

RTMDEF void rtm_dvec3_set_z(rtm_dvec3* v, double z) { v->z = z; }

// MATH FUNCTIONS
RTMDEF rtm_dvec3 rtm_dvec3_add(const rtm_dvec3* a, const rtm_dvec3* b) {
	return (rtm_dvec3) { a->x + b->x, a->y + b->y, a->z + b->z };
}

RTMDEF void rtm_dvec3_add_to(rtm_dvec3* out, const rtm_dvec3* a, const rtm_dvec3* b) {
	out->x = a->x + b->x;
	out->y = a->y + b->y;
	out->z = a->z + b->z;
}

RTMDEF void rtm_dvec3_add_inplace(rtm_dvec3* a, const rtm_dvec3* b) {
	a->x = a->x + b->x;
	a->y = a->y + b->y;
	a->z = a->z + b->z;
}

RTMDEF rtm_dvec3 rtm_dvec3_sub(const rtm_dvec3* a, const rtm_dvec3* b) {
	return (rtm_dvec3)
	{
		a->x - b->x,
		a->y - b->y,
		a->z - b->z
	};
}

RTMDEF void rtm_dvec3_sub_to(rtm_dvec3* out, const rtm_dvec3* a, const rtm_dvec3* b) {
	out->x = a->x - b->x;
	out->y = a->y - b->y;
	out->z = a->z - b->z;
}

RTMDEF void rtm_dvec3_sub_inplace(rtm_dvec3* out, const rtm_dvec3* a, const rtm_dvec3* b) {
	a->x = a->x - b->x;
	a->y = a->y - b->y;
	a->z = a->z - b->z;
}

RTMDEF rtm_dvec3 rtm_dvec3_mult(const rtm_dvec3* v, double t)
{
	return (rtm_dvec3) { v->x* t, v->y* t, v->z* t };
}

RTMDEF void rtm_dvec3_mult_to(rtm_dvec3* out, const rtm_dvec3* v, double t)
{
	out->x = v->x * t;
	out->y = v->y * t;
	out->z = v->z * t;
}

RTMDEF void rtm_dvec3_mult_inplace(rtm_dvec3* out, const rtm_dvec3* v, double t)
{
	v->x = v->x * t;
	v->y = v->y * t;
	v->z = v->z * t;
}

RTMDEF rtm_dvec3 rtm_dvec3_div(const rtm_dvec3* v, double t)
{
	return (rtm_dvec3) { v->x / t, v->y / t, v->z / t };
}
RTMDEF void rtm_dvec3_div_to(rtm_dvec3* out, const rtm_dvec3* v, double t)
{
	out->x = v->x / t;
	out->y = v->y / t;
	out->z = v->z / t;
}

RTMDEF void rtm_dvec3_div_inplace(rtm_dvec3* out, const rtm_dvec3* v, double t)
{
	v->x = v->x / t;
	v->y = v->y / t;
	v->z = v->z / t;
}

RTMDEF double rtm_dvec3_length_squared(const rtm_dvec3* v) {
	return	v->x * v->x + v->y * v->y + v->z * v->z;
}

RTMDEF double rtm_dvec3_length(const rtm_dvec3* v) {
	return sqrt(rtm_dvec3_length_squared(v));
}

RTMDEF void rtm_dvec3_normalize(rtm_dvec3* v) {
	double len = rtm_dvec3_length(v);

	v->x /= len;
	v->y /= len;
	v->z /= len;
}

RTMDEF void rtm_dvec3_normalize_to(rtm_dvec3* out, const rtm_dvec3* v) {
	double len = rtm_dvec3_length(v);

	out->x = v->x / len;
	out->y = v->y / len;
	out->z = v->z / len;
}

RTMDEF void rtm_dvec3_normalize_inplace(rtm_dvec3* v) {
	double len = rtm_dvec3_length(v);

	v->x = v->x / len;
	v->y = v->y / len;
	v->z = v->z / len;
}

RTMDEF double rtm_dvec3_dot(const rtm_dvec3* v, const rtm_dvec3* u) {
	return	v->x * u->x +
		v->y * u->y +
		v->z * u->z;
}

RTMDEF rtm_dvec3 rtm_dvec3_cross(const rtm_dvec3* a,const rtm_dvec3* b){
	return (rtm_dvec3){
		a->y * b->z - a->z * b->y,
		a->z * b->x - a->x * b->z,
		a->x * b->y - a->y * b->x
		};
	}

RTMDEF void rtm_dvec3_cross_to(rtm_dvec3* out, const rtm_dvec3* v, const rtm_dvec3* u) {
		out->x = u->y * v->z - u->z * v->y,
		out->y = u->z * v->x - u->x * v->z,
		out->z = u->x * v->y - u->y * v->x;
}

RTMDEF rtm_dvec3 rtm_dvec3_neg(const rtm_dvec3* v) {
	return (rtm_dvec3) { -v->x, -v->y, -v->z };
}

RTMDEF void rtm_dvec3_neg_to(rtm_dvec3* out, const rtm_dvec3* v) {
	out->x = -v->x;
	out->y = -v->y;
	out->z = -v->z;
}

RTMDEF void rtm_dvec3_neg_inplace(rtm_dvec3* v) {
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
}

RTMDEF rtm_dvec3 rtm_dvec3_hadamard(const rtm_dvec3* u, const rtm_dvec3* v)
{
	return (rtm_dvec3) {
		v->x* u->x,
		v->y* u->y,
		v->z* u->z
	};
}

RTMDEF double rtm_dvec3_distance(const rtm_dvec3* a, const rtm_dvec3* b) {
	double dx = a->x - b->x;
	double dy = a->y - b->y;
	double dz = a->z - b->z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

RTMDEF rtm_dvec3 rtm_dvec3_reflect(const rtm_dvec3* v, const rtm_dvec3* n) {
	// r = v - 2 * dot(v,n) * n
	double d = v->x * n->x + v->y * n->y + v->z * n->z;
	double k = 2.0 * d;
	return (rtm_dvec3) {
		v->x - k * n->x,
		v->y - k * n->y,
		v->z - k * n->z
	};
}

#endif


#ifdef __cplusplus
}
#endif

#endif //!RTM_VEC3_DOUBLE_H