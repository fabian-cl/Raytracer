#ifndef RTM_MAT_TYPES_H
#define RTM_MAT_TYPES_H

// 4 by 4 double matrix 

#ifdef __cplusplus
extern "C" {
#endif

// INCLUDES
#include "vec2_types.h"
#include "vec3_types.h"
#include "vec4_types.h"

#define MAT2_SIZE 4
#define MAT2_ROWS 2
#define MAT2_COLS 2

#define MAT3_SIZE 9
#define MAT3_ROWS 3
#define MAT3_COLS 3

#define MAT4_SIZE 16
#define MAT4_ROWS 4
#define MAT4_COLS 4

// MAT 4x4

typedef union rtm_dmat4 {
	double elem[MAT4_SIZE];     // flat array: 16 elements
    rtm_dvec4 cols[MAT4_COLS];  // 4 column vectors of 4 elements each

    #ifdef __cplusplus
        inline rtm_dvec4 &operator[](int index) { return cols[index]; }
        inline const rtm_dvec4 &operator[](int index) const { return cols[index]; }
    #endif

} rtm_dmat4;


typedef union rtm_fmat4 {
	float elem[MAT4_SIZE];
    rtm_fvec4 cols[MAT4_COLS];

    #ifdef __cplusplus
        inline rtm_fvec4 &operator[](int index) { return cols[index]; }
        inline const rtm_fvec4 &operator[](int index) const { return cols[index]; }
    #endif

} rtm_fmat4;

typedef union rtm_imat4 {
	float elem[MAT4_SIZE];
    rtm_ivec4 cols[MAT4_COLS];

    #ifdef __cplusplus
        inline rtm_ivec4 &operator[](int index) { return cols[index]; }
        inline const rtm_ivec4 &operator[](int index) const { return cols[index]; }
    #endif

} rtm_imat4;

// MAT 3x3
typedef union rtm_dmat3 {
	double elem[MAT3_SIZE];     // flat array: 16 elements
    rtm_dvec3 cols[MAT3_COLS];  // 4 column vectors of 4 elements each

    #ifdef __cplusplus
        inline rtm_dvec3 &operator[](int index) { return cols[index]; }
        inline const rtm_dvec3 &operator[](int index) const { return cols[index]; }
    #endif

} rtm_dmat3;

typedef union rtm_fmat3 {
	float elem[MAT3_SIZE];
    rtm_fvec3 cols[MAT3_COLS];

    #ifdef __cplusplus
        inline rtm_fvec3 &operator[](int index) { return cols[index]; }
        inline const rtm_fvec3 &operator[](int index) const { return cols[index]; }
    #endif

} rtm_fmat3;

// MAT 2x2
typedef union rtm_dmat2 {
	double elem[MAT2_SIZE];     // flat array: 16 elements
    rtm_dvec2 cols[MAT2_COLS];  // 4 column vectors of 4 elements each

    #ifdef __cplusplus
        inline rtm_dvec2 &operator[](int index) { return cols[index]; }
        inline const rtm_dvec2 &operator[](int index) const { return cols[index]; }
    #endif

} rtm_dmat2;

typedef union rtm_fmat2 {
	float elem[MAT2_SIZE];
    rtm_fvec2 cols[MAT2_COLS];

    #ifdef __cplusplus
        inline rtm_fvec2 &operator[](int index) { return cols[index]; }
        inline const rtm_fvec2 &operator[](int index) const { return cols[index]; }
    #endif

} rtm_fmat2;

// macro definition mxn dimension matrix

#ifndef DEFINE_MAT_MxN_TYPE
    #ifdef __cplusplus
    #define DEFINE_MAT_MxN_TYPE(NAME, TYPE, SIZE_M, SIZE_N)     \
        typedef struct {                                        \
            TYPE elem[SIZE_M*SIZE_N];                           \
            inline TYPE &operator[](int index) { return elem[index]; } \
            inline const TYPE &operator[](int index) const { return elem[index]; }\
        } NAME;
    #else
    #define DEFINE_MAT_MxN_TYPE(NAME, TYPE, SIZE_M, SIZE_N)     \
        typedef struct {                                    \
            TYPE elem[SIZE_M*SIZE_N];                       \
        } NAME;
    #endif
#endif
#ifndef DEFINE_MAT_TYPE
    #ifdef __cplusplus
    #define DEFINE_MAT_TYPE(NAME, TYPE, SIZE)       \
        typedef struct {                            \
            TYPE elem[SIZE];                        \
            inline TYPE &operator[](int index) { return elem[index]; } \
            inline const TYPE &operator[](int index) const { return elem[index]; }\
        } NAME;
    #else 
    #define DEFINE_MAT_TYPE(NAME, TYPE, SIZE)   \
        typedef struct {                        \
            TYPE elem[SIZE];                    \
        } NAME;
    #endif
#endif

#ifdef __cplusplus
}
#endif


#endif //!RTM_MAT4_TYPES_H