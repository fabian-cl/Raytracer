#ifndef RTM_VEC3_TYPES_H
#define RTM_VEC3_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vec2_types.h"

typedef union rtm_dvec3 {
    struct { double x, y, z; };
    struct { double r, g, b; };
    struct { double s, t, p; };
    struct { rtm_dvec2 xy; double _ignored0;};
    struct { double _ignored1; rtm_dvec2 yz;};
    struct { rtm_dvec2 st; double _ignored2;};
    struct { double _ignored3; rtm_dvec2 tp;};
    
    double elem[3];

    #ifdef __cplusplus
        inline double &operator[](int index) { return elem[index]; }
        inline const double &operator[](int index) const { return elem[index]; }
    #endif

} rtm_dvec3;

typedef union rtm_fvec3 {
    struct { float x, y, z; };
    struct { float r, g, b; };
    struct { float s, t, p; };
    struct { rtm_fvec2 xy; float _ignored0;};
    struct { float _ignored1; rtm_fvec2 yz;};
    struct { rtm_fvec2 sp; float _ignored2;};
    struct { float _ignored3; rtm_fvec2 tp;};
    
    float elem[3];

    #ifdef __cplusplus
        inline float &operator[](int index) { return elem[index]; }
        inline const float &operator[](int index) const { return elem[index]; }
    #endif

} rtm_fvec3;

typedef union rtm_ivec3 {
    struct { int x, y, z; };
    struct { int r, g, b; };
    struct { int s, t, p; };
    struct { rtm_ivec2 xy; int _ignored0;};
    struct { int _ignored1; rtm_ivec2 yz;};
    struct { rtm_ivec2 sp; int _ignored2;};
    struct { int _ignored3; rtm_ivec2 tp;};
    
    int elem[3];

    #ifdef __cplusplus
        inline int &operator[](int index) { return elem[index]; }
        inline const int &operator[](int index) const { return elem[index]; }
    #endif

} rtm_ivec3;

#ifdef __cplusplus
}
#endif

#endif //!RTM_VEC3_TYPES_H