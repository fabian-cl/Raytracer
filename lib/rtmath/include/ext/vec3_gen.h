#ifndef VEC3_EXT_GEN_H
#define VEC3_EXT_GEN_H

#include "../details/vec3_types.h"

#include <math.h>

#define VEC3_DEFINE_EXT(TYPE, PREFIX, SQRT_FUNC)                             \
static inline TYPE PREFIX##add(TYPE a, TYPE b) {                             \
    return (TYPE){a.x + b.x, a.y + b.y, a.z + b.z};                          \
}                                                                            \
static inline TYPE PREFIX##sub(TYPE a, TYPE b) {                             \
    return (TYPE){a.x - b.x, a.y - b.y, a.z - b.z};                          \
}                                                                            \
static inline auto PREFIX##dot(TYPE a, TYPE b) {                             \
    return a.x*b.x + a.y*b.y + a.z*b.z;                                      \
}                                                                            \
static inline TYPE PREFIX##cross(TYPE a, TYPE b) {                           \
    return (TYPE){                                                             \
        a.y*b.z - a.z*b.y,                                                   \
        a.z*b.x - a.x*b.z,                                                   \
        a.x*b.y - a.y*b.x                                                    \
    };                                                                       \
}                                                                            \
static inline auto PREFIX##length(TYPE v) {                                   \
    return SQRT_FUNC(PREFIX##dot(v, v));                                      \
}                                                                            \
static inline TYPE PREFIX##normalize(TYPE v) {                                \
    auto len = PREFIX##length(v);                                            \
    return (len != 0) ? (TYPE){v.x/len, v.y/len, v.z/len} : (TYPE){0,0,0};   \
}

#endif // VEC3_EXT_GEN_H
