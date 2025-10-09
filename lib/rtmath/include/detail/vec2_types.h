#ifndef RTM_VEC2_TYPES_H
#define RTM_VEC2_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef union rtm_dvec2 {
    struct { double x, y; };
    struct { double r, g; };
    struct { double s, t; };
    
    double elem[2];

    #ifdef __cplusplus
        inline double &operator[](int index) { return elem[index]; }
        inline const double &operator[](int index) const { return elem[index]; }
    #endif

} rtm_dvec2;

typedef union rtm_fvec2 {
    struct { float x, y; };
    struct { float r, g; };
    struct { float s, t; };
    
    float elem[2];

    #ifdef __cplusplus
        inline float &operator[](int index) { return elem[index]; }
        inline const float &operator[](int index) const { return elem[index]; }
    #endif

} rtm_fvec2;

typedef union rtm_ivec2 {
    struct { int x, y; };
    struct { int r, g; };
    struct { int s, t; };
    
    int elem[2];

    #ifdef __cplusplus
        inline int &operator[](int index) { return elem[index]; }
        inline const int &operator[](int index) const { return elem[index]; }
    #endif
} rtm_ivec2;

#ifdef __cplusplus
}
#endif

#endif //!RT_MATH_VEC2_TYPES_H