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

// TYPE DEFINITION
typedef struct vec2 {
    double x, y;
} vec2;

typedef struct fvec2 {
    float x, y;
} fvec2;

typedef struct ivec2 {
    int x, y;
} ivec2;

typedef struct vec3 {
    double x, y, z;
} vec3;

typedef struct fvec3 {
    float x, y, z;
} fvec3;

typedef struct ivec3 {
    int x, y, z;
} ivec3;

typedef struct vec4 {
    double x, y, z, w;
} vec4;

typedef struct fvec4 {
    float x, y, z, w;
} fvec4;

typedef struct ivec4 {
    int x, y, z, w;
} ivec4;

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

// VECTOR 2 LITERAL

#ifdef __cplusplus
#define VEC2_LITERAL(x, y) vec2{ (x), (y) }
#else
#define VEC2_LITERAL(x, y) (vec2){ (x), (y) }
#endif

#ifdef __cplusplus
#define FVEC2_LITERAL(x, y) fvec2{ (x), (y) }
#else
#define FVEC2_LITERAL(x, y) (fvec2){ (x), (y) }
#endif

#ifdef __cplusplus
#define IVEC2_LITERAL(x, y) ivec2{ (x), (y) }
#else
#define IVEC2_LITERAL(x, y) (ivec2){ (x), (y) }
#endif

// VECTOR 3 LITERAL

#ifdef __cplusplus
#define VEC3_LITERAL(x, y, z) vec3{ (x), (y), (z) }
#else
#define VEC3_LITERAL(x, y, z) (vec3){ (x), (y), (z) }
#endif

#ifdef __cplusplus
#define FVEC3_LITERAL(x, y, z) fvec3{ (x), (y), (z) }
#else
#define FVEC3_LITERAL(x, y, z) (fvec3){ (x), (y), (z) }
#endif

#ifdef __cplusplus
#define IVEC3_LITERAL(x, y, z) ivec3{ (x), (y), (z) }
#else
#define IVEC3_LITERAL(x, y, z) (ivec3){ (x), (y), (z) }
#endif

// VECTOR 4 LITERAL

#ifdef __cplusplus
#define VEC4_LITERAL(x, y, z, w) vec4{ x, y, z, w }
#else
#define VEC4_LITERAL(x, y, z, w) (vec4){ x, y, z, w }
#endif

#ifdef __cplusplus
#define FVEC4_LITERAL(x, y, z, w) fvec4{ x, y }
#else
#define FVEC4_LITERAL(x, y) (fvec4){ x, y, z, w }
#endif

#ifdef __cplusplus
#define IVEC4_LITERAL(x, y, z, w) ivec4{ x, y, z, w }
#else
#define IVEC4_LITERAL(x, y, z, w) (ivec4){ x, y, z, w }
#endif

#ifndef VECTOR_IMPLEMENTATION_H
#define VECTOR_IMPLEMENTATION_H

#include "vector2.inl"
#include "vector3.inl"
#include "vector4.inl"

vec3 vec3_refract(const vec3* v, const vec3* n, double eta);

#ifdef __cplusplus
}
#endif


#endif // !VECTOR_IMPLEMENTATION_H

#endif /* MATH_VECTOR_H */
