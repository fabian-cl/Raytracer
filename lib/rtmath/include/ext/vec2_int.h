/**
 * @file vec2_integer.h
 * @brief Integer 2D vector math library.
 *
 * This header defines the rtm_ivec2 type and its associated operations,
 * including constructors, getters/setters, and mathematical functions.
 * All functions are implemented as inline or static inline depending on
 * the RTM_USE_STATIC_INLINE configuration.
 * 
 * NOTE: int vectors normalization and division are not provided.
 *
 */

#ifndef RTM_VEC2_INTEGER_H
#define RTM_VEC2_INTEGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../detail/vec2_types.h"
#include "../detail/vec_define.h"

/*===========================================================
 *  DECLARATIONS
 *===========================================================*/

/**
 * @brief Returns a 2D zero vector (0, 0).
 */
RTMDEF rtm_ivec2 rtm_ivec2_zero(void);

/**
 * @brief Returns a 2D vector of ones (1, 1).
 */
RTMDEF rtm_ivec2 rtm_ivec2_one(void);

/**
 * @brief Constructs a 2D vector with given x and y components.
 */
RTMDEF rtm_ivec2 rtm_ivec2_construct(int x, int y);

/**
 * @brief Constructs a 2D vector with both components set to the same value.
 */
RTMDEF rtm_ivec2 rtm_ivec2_construct_uniform(int v);

/**
 * @brief Copies a vector into another.
 */
RTMDEF void rtm_ivec2_copy(rtm_ivec2* out, const rtm_ivec2* src);

/**
 * @brief Returns a copy of the given vector.
 */
RTMDEF rtm_ivec2 rtm_ivec2_clone(const rtm_ivec2* src);

/**
 * @brief Gets the x component of a vector.
 */
RTMDEF int rtm_ivec2_get_x(const rtm_ivec2* v);

/**
 * @brief Gets the y component of a vector.
 */
RTMDEF int rtm_ivec2_get_y(const rtm_ivec2* v);

/**
 * @brief Sets the x component of a vector.
 */
RTMDEF void rtm_ivec2_set_x(rtm_ivec2* v, int x);

/**
 * @brief Sets the y component of a vector.
 */
RTMDEF void rtm_ivec2_set_y(rtm_ivec2* v, int y);

/**
 * @brief Sets the element index of a vector to a value.
 */
RTMDEF void rtm_ivec2_set_value_by_index(rtm_ivec2* v, int index, int value);

/**
 * @brief Gets the element index of a vector.
 */
RTMDEF void rtm_ivec2_get_value_by_index(rtm_ivec2* v, int index);

/**
 * @brief Adds two vectors.
 */
RTMDEF rtm_ivec2 rtm_ivec2_add(const rtm_ivec2* a, const rtm_ivec2* b);

/**
 * @brief Adds two vectors and stores the result.
 */
RTMDEF void rtm_ivec2_add_ex(rtm_ivec2* out, const rtm_ivec2* a, const rtm_ivec2* b);

/**
 * @brief Subtracts one vector from another.
 */
RTMDEF rtm_ivec2 rtm_ivec2_sub(const rtm_ivec2* a, const rtm_ivec2* b);

/**
 * @brief Subtracts one vector from another and stores the result.
 */
RTMDEF void rtm_ivec2_sub_ex(rtm_ivec2* out, const rtm_ivec2* a, const rtm_ivec2* b);

/**
 * @brief Multiplies a vector by an integer scalar.
 */
RTMDEF rtm_ivec2 rtm_ivec2_mult(const rtm_ivec2* v, int s);

/**
 * @brief Multiplies a vector by an integer scalar and stores the result.
 */
RTMDEF void rtm_ivec2_mult_ex(rtm_ivec2* out, const rtm_ivec2* v, int s);

/**
 * @brief Returns the negated vector (-x, -y).
 */
RTMDEF rtm_ivec2 rtm_ivec2_neg(const rtm_ivec2* v);

/**
 * @brief Negates a vector and stores the result.
 */
RTMDEF void rtm_ivec2_neg_ex(rtm_ivec2* out, const rtm_ivec2* v);

/**
 * @brief Performs element-wise multiplication (Hadamard) of two vectors.
 */
RTMDEF rtm_ivec2 rtm_ivec2_hadamard(const rtm_ivec2* a, const rtm_ivec2* b);

/*===========================================================
 *  IMPLEMENTATION
 *===========================================================*/
#ifdef RTM_IMPLEMENTATION

#include <math.h>

RTMDEF rtm_ivec2 rtm_ivec2_zero(void) { return VEC2_LITERAL_I(0, 0); }
RTMDEF rtm_ivec2 rtm_ivec2_one(void) { return VEC2_LITERAL_I(1, 1); }
RTMDEF rtm_ivec2 rtm_ivec2_construct(int x, int y) { return VEC2_LITERAL_I(x, y); }
RTMDEF rtm_ivec2 rtm_ivec2_construct_uniform(int v) { return VEC2_LITERAL_I(v, v); }
RTMDEF void rtm_ivec2_copy(rtm_ivec2* out, const rtm_ivec2* src) { *out = *src; }
RTMDEF rtm_ivec2 rtm_ivec2_clone(const rtm_ivec2* src) { return *src; }
RTMDEF int rtm_ivec2_get_x(const rtm_ivec2* v) { return v->x; }
RTMDEF int rtm_ivec2_get_y(const rtm_ivec2* v) { return v->y; }
RTMDEF void rtm_ivec2_set_x(rtm_ivec2* v, int x) { v->x = x; }
RTMDEF void rtm_ivec2_set_y(rtm_ivec2* v, int y) { v->y = y; }
RTMDEF rtm_ivec2 rtm_ivec2_add(const rtm_ivec2* a, const rtm_ivec2* b) { return VEC2_LITERAL_I(a->x+b->x, a->y+b->y); }
RTMDEF void rtm_ivec2_add_ex(rtm_ivec2* out, const rtm_ivec2* a, const rtm_ivec2* b) { out->x = a->x+b->x; out->y = a->y+b->y; }
RTMDEF rtm_ivec2 rtm_ivec2_sub(const rtm_ivec2* a, const rtm_ivec2* b) { return VEC2_LITERAL_I(a->x-b->x, a->y-b->y); }
RTMDEF void rtm_ivec2_sub_ex(rtm_ivec2* out, const rtm_ivec2* a, const rtm_ivec2* b) { out->x = a->x-b->x; out->y = a->y-b->y; }
RTMDEF rtm_ivec2 rtm_ivec2_mult(const rtm_ivec2* v, int s) { return VEC2_LITERAL_I(v->x*s, v->y*s); }
RTMDEF void rtm_ivec2_mult_ex(rtm_ivec2* out, const rtm_ivec2* v, int s) { out->x = v->x*s; out->y = v->y*s; }
RTMDEF int rtm_ivec2_dot(const rtm_ivec2* a, const rtm_ivec2* b) { return a->x*b->x + a->y*b->y; }
RTMDEF rtm_ivec2 rtm_ivec2_neg(const rtm_ivec2* v) { return VEC2_LITERAL_I(-v->x, -v->y); }
RTMDEF void rtm_ivec2_neg_ex(rtm_ivec2* out, const rtm_ivec2* v) { out->x=-v->x; out->y=-v->y; }
RTMDEF rtm_ivec2 rtm_ivec2_hadamard(const rtm_ivec2* a, const rtm_ivec2* b) { return VEC2_LITERAL_I(a->x*b->x, a->y*b->y); }

#endif // RTM_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // RTM_VEC2_INTEGER_H
