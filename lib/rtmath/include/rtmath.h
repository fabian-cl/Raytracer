#ifndef RT_MATH_H
#define RT_MATH_H

// Master include

#ifdef __cplusplus
extern "C" {
#endif

// TYPE INCLUDES
#include "rtmdefine.h"
#include "detail/vec2_types.h"
#include "detail/vec3_types.h"
#include "detail/vec4_types.h"

// TYPE DEFINITION
typedef rtm_dvec2  point2;
typedef rtm_dvec2  dir2;
typedef rtm_ivec2 ipoint2;
typedef rtm_ivec2 idir2;
typedef rtm_fvec2 fpoint2;
typedef rtm_fvec2 fdir2;

typedef rtm_dvec3  point3;
typedef rtm_dvec3  dir3;
typedef rtm_ivec4 ipoint3;
typedef rtm_ivec4 idir3;
typedef rtm_fvec3 fpoint3;
typedef rtm_fvec3 fdir3;

typedef rtm_dvec4 point4;
typedef rtm_dvec4 dir4;

#define VEC2_SIZE 2
#define VEC3_SIZE 3
#define VEC4_SIZE 4

#define VEC2_SIZEOF     sizeof(rtm_dvec2)
#define FVEC2_SIZEOF    sizeof(rtm_fvec2)
#define IVEC2_SIZEOF    sizeof(rtm_ivec2)

#define VEC3_SIZEOF     sizeof(rtm_dvec3)
#define FVEC3_SIZEOF    sizeof(rtm_dvec3)
#define IVEC3_SIZEOF    sizeof(rtm_dvec3)

#define VEC4_SIZEOF     sizeof(rtm_dvec4)
#define IVEC4_SIZEOF    sizeof(rtm_dvec4)
#define FVEC4_SIZEOF    sizeof(rtm_dvec4)

// FUNCTION DEFINITION
#include "ext/vec2_double.h"
#include "ext/vec3_double.h"
#include "ext/vec4_double.h"

#include "mat4.h"

//#include "geometry/geometry_types.h"

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

#ifdef __cplusplus
}
#endif

#endif //!RT_MATH_H