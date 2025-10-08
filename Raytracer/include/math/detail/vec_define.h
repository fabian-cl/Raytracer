#ifndef DETAILS_MATH_VEC_DEFINITIONS_H
#define DETAILS_MATH_VEC_DEFINITIONS_H

// Macro define header

#define DEFINE_VEC3_TYPE(NAME, TYPE)    \
    typedef struct {                    \
        union {                         \
            struct {TYPE x, y, z;};     \
            struct {TYPE r, g, b;};     \
            struct {TYPE s, t, p;};     \
        }                               \
    } NAME; 


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

#endif // DETAILS_MATH_VEC_DEFINITIONS_H