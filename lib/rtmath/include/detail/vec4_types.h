#ifndef RTM_VEC4_TYPES_H
#define RTM_VEC4_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vec2_types.h"
#include "vec3_types.h"

typedef union rtm_dvec4 {
    struct {
        union {
            rtm_dvec3 xyz;
            struct
            {
                double x, y, z;
            };
        };
        double w; 
    };
    struct {
        union {
            rtm_dvec3 rgb;
            struct
            {
                double r, g, b;
            };
        };
        double a; 
    };
    struct {
        union {
            rtm_dvec3 stp;
            struct
            {
                double s, t, p;
            };
        };
        double q; 
    };
    struct {
        rtm_dvec2 xy;
        double _ignored0;
        double _ignored1;
    };
    struct {
        double _ignored2;
        rtm_dvec2 yz;
        double _ignored3;
    };
    struct {
        double _ignored4;
        double _ignored5;
        rtm_dvec2 zw;
    };
    
    double elem[4];

    #ifdef __cplusplus
        inline double &operator[](int Index) { return Elements[Index]; }
        inline const double &operator[](int Index) const { return Elements[Index]; }
    #endif

} rtm_dvec4;

typedef union rtm_fvec4 {
    struct {
        union {
            rtm_fvec3 xyz;
            struct
            {
                float x, y, z;
            };
        };
        float w; 
    };
    struct {
        union {
            rtm_fvec3 rgb;
            struct
            {
                float r, g, b;
            };
        };
        float a; 
    };
    struct {
        union {
            rtm_fvec3 stp;
            struct
            {
                float s, t, p;
            };
        };
        float q; 
    };
    struct {
        rtm_fvec2 xy;
        float _ignored0;
        float _ignored1;
    };
    struct {
        float _ignored2;
        rtm_fvec2 yz;
        float _ignored3;
    };
    struct {
        float _ignored4;
        float _ignored5;
        rtm_fvec2 zw;
    };
    
    float elem[4];

    #ifdef __cplusplus
        inline float &operator[](int Index) { return Elements[Index]; }
        inline const float &operator[](int Index) const { return Elements[Index]; }
    #endif

} rtm_fvec4;

typedef union rtm_ivec4 {
    struct {
        union {
            rtm_ivec3 xyz;
            struct
            {
                int x, y, z;
            };
        };
        int w; 
    };
    struct {
        union {
            rtm_ivec3 rgb;
            struct
            {
                int r, g, b;
            };
        };
        int a; 
    };
    struct {
        union {
            rtm_ivec3 stp;
            struct
            {
                int s, t, p;
            };
        };
        int q; 
    };
    struct {
        rtm_ivec2 xy;
        int _ignored0;
        int _ignored1;
    };
    struct {
        int _ignored2;
        rtm_ivec2 yz;
        int _ignored3;
    };
    struct {
        int _ignored4;
        int _ignored5;
        rtm_ivec2 zw;
    };
    
    int elem[4];

    #ifdef __cplusplus
        inline int &operator[](int Index) { return Elements[Index]; }
        inline const int &operator[](int Index) const { return Elements[Index]; }
    #endif

} rtm_ivec4;

#ifdef __cplusplus
}
#endif

#endif //!RTM_VEC4_TYPES_H