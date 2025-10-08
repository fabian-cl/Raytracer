#pragma once

#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#ifndef MATH
#define MATH
    #include <math.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

// TYPE INCLUDES
#include "detail/vec2_types.h"
#include "detail/vec3_types.h"
#include "detail/vec4_types.h"

// TYPE DEFINITION
typedef vec2  point2;
typedef vec2  dir2;
typedef ivec2 ipoint2;
typedef ivec2 idir2;
typedef fvec2 fpoint2;
typedef fvec2 fdir2;

typedef vec3  point3;
typedef vec3  dir3;
typedef ivec3 ipoint3;
typedef ivec3 idir3;
typedef fvec3 fpoint3;
typedef fvec3 fdir3;

typedef vec4 point4;
typedef vec4 dir4;

#define VEC2_SIZE 2
#define VEC3_SIZE 3
#define VEC4_SIZE 4

#define VEC2_SIZEOF     sizeof(vec2)
#define FVEC2_SIZEOF    sizeof(fvec2)
#define IVEC2_SIZEOF    sizeof(ivec2)

#define VEC3_SIZEOF     sizeof(vec3)
#define FVEC3_SIZEOF    sizeof(vec3)
#define IVEC3_SIZEOF    sizeof(vec3)

#define VEC4_SIZEOF     sizeof(vec4)
#define IVEC4_SIZEOF    sizeof(vec4)
#define FVEC4_SIZEOF    sizeof(vec4)

// FUNCTION DEFINITION
#include "ext/vec2.h"
#include "ext/vec3.h"
#include "ext/vec4.h"

#ifndef VECTOR_IMPLEMENTATION_H
#define VECTOR_IMPLEMENTATION_H

vec3 vec3_refract(const vec3* v, const vec3* n, double eta);

#ifdef __cplusplus
}
#endif


#endif // !VECTOR_IMPLEMENTATION_H

#endif /* MATH_VECTOR_H */
