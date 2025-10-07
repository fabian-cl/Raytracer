#pragma once

#include "vector.h"
#include "mat4.h"

#include "geometry/geometry_types.h"

static inline double degrees_to_radians(double degrees)
{
	return -1;
}
static inline double radians_to_degrees(double radians)
{
	return -1;
}

/*
static inline void look_at(
	vec3* from, 
	vec3* to,
	vec3* arbitraryUp,
	mat4* m)
{
	vec3 forward;
	vec3_sub(&forward, from, to);

	vec3 n_forward;
	vec3_normalize(&n_forward, &forward);

	vec3 right;
	vec3_cross(&right, arbitraryUp, &forward);
	vec3_normalize(&right);

	vec3_t up = vec3_cross(&forward, &right);

	mat4_set(m, 0, 0, right.x);
	mat4_set(m, 0, 1, right.y);
	mat4_set(m, 0, 2, right.z);
	
	mat4_set(m, 1, 0, up.x);
	mat4_set(m, 1, 1, up.y);
	mat4_set(m, 1, 2, up.z);
	
	mat4_set(m, 2, 0, forward.x);
	mat4_set(m, 2, 1, forward.y);
	mat4_set(m, 2, 2, forward.z);
	
	mat4_set(m, 3, 0, from->x);
	mat4_set(m, 3, 1, from->y);
	mat4_set(m, 3, 2, from->z);
}*/