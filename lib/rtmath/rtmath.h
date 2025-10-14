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

#include "ext/mat4_double.h"

//#include "geometry/geometry_types.h"

static inline double degrees_to_radians(double degrees)
{
	return -1;
}
static inline double radians_to_degrees(double radians)
{
	return -1;
}

#ifdef __cplusplus
}
#endif

#endif //!RT_MATH_H