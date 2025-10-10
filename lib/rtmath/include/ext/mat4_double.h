#ifndef RTM_VEC2_DOUBLE_H
#define RTM_VEC2_DOUBLE_H
// double vector 2 header file

#ifdef __cplusplus
extern "C" {
#endif

#include "../detail/vec4_types.h"
#include "../detail/vec_define.h"

#include "../detail/mat_types.h"

/*===========================================================
 * CONSTRUCTORS
 *===========================================================*/

/**
 * @brief Returns an identity matrix.
 */
RTMDEF rtm_dmat4 rtm_dmat4_identity(void);

/**
 * @brief Constructs a matrix from 4 column vectors.
 * @param c0 First column.
 * @param c1 Second column.
 * @param c2 Third column.
 * @param c3 Fourth column.
 */
RTMDEF rtm_dmat4 rtm_dmat4_construct_cols(const rtm_dvec4* c0, const rtm_dvec4* c1, const rtm_dvec4* c2, const rtm_dvec4* c3);

/**
 * @brief Constructs a diagonal matrix with a given scalar on the diagonal.
 * @param s The diagonal value.
 */
RTMDEF rtm_dmat4 rtm_dmat4_construct_diagonal(double s);


//RTMDEF rtm_dmat4 rtm_dmat4_from_rows(rtm_dvec4 v0, rtm_dvec4 v1, rtm_dvec4 v2, rtm_dvec4 v3);

/*===========================================================
 * COPY/CLONE
 *===========================================================*/

RTMDEF rtm_dmat4 rtm_dmat4_copy();

/*===========================================================
 * GETTERS/SETTERS
 *===========================================================*/

RTMDEF double mat4_get(const rtm_dmat4* m, int x, int y);

double* mat4_row(rtm_dmat4* m, int i);

/*===========================================================
 * ARITHMETIC
 *===========================================================*/

RTMDEF rtm_dmat4 rtm_dmat4_add(rtm_dmat4 a, rtm_dmat4 b);
RTMDEF rtm_dmat4 rtm_dmat4_sub(rtm_dmat4 a, rtm_dmat4 b);
RTMDEF rtm_dmat4 rtm_dmat4_mult_scalar(rtm_dmat4 a, double s);
RTMDEF rtm_dmat4 rtm_dmat4_div_scalar(rtm_dmat4 a, double s);

/**
 * @brief Multiplies two 4x4 matrices (result = a * b).
 */
RTMDEF rtm_dmat4 rtm_dmat4_mul(const rtm_dmat4* a, const rtm_dmat4* b);

/**
 * @brief Multiplies a matrix by a 4D vector (result = m * v).
 */
RTMDEF rtm_dvec4 rtm_dmat4_mul_vec4(const rtm_dmat4* m, const rtm_dvec4* v);

/**
 * @brief Computes the transpose of a matrix.
 */
RTMDEF rtm_dmat4 rtm_dmat4_transpose(const rtm_dmat4* m);

/**
 * @brief Computes the determinant of a 4x4 matrix.
 */
RTMDEF double rtm_dmat4_determinant(const rtm_dmat4* m);

/**
 * @brief Computes the inverse of a 4x4 matrix.
 * @param m Input matrix.
 * @return Inverse matrix.
 */
RTMDEF rtm_dmat4 rtm_dmat4_inverse(const rtm_dmat4* m);

/*===========================================================
 * TRANSFORM
 *===========================================================*/

/**
 * @brief Creates a translation matrix.
 * @param translation 3D translation vector.
 */
RTMDEF rtm_dmat4 rtm_dmat4_translation(const rtm_dvec3* translation);

/**
 * @brief Creates a scaling matrix.
 * @param scale 3D scale vector.
 */
RTMDEF rtm_dmat4 rtm_dmat4_scale(const rtm_dvec3* scale);

/**
 * @brief Creates a rotation matrix around the X-axis.
 * @param angle_radians Angle in radians.
 */
RTMDEF rtm_dmat4 rtm_dmat4_rotation_x(double angle_radians);

/**
 * @brief Creates a rotation matrix around the Y-axis.
 * @param angle_radians Angle in radians.
 */
RTMDEF rtm_dmat4 rtm_dmat4_rotation_y(double angle_radians);

/**
 * @brief Creates a rotation matrix around the Z-axis.
 * @param angle_radians Angle in radians.
 */
RTMDEF rtm_dmat4 rtm_dmat4_rotation_z(double angle_radians);

/**
 * @brief Creates a rotation matrix from Euler angles (XYZ order).
 * @param euler 3D vector containing angles in radians.
 */
RTMDEF rtm_dmat4 rtm_dmat4_rotation_euler(const rtm_dvec3* euler);

//RTMDEF rtm_dmat4 rtm_dmat4_rotation_axis(const rtm_dvec3* axis, double radians);

// Compose TRS (transform)
RTMDEF rtm_dmat4 rtm_dmat4_trs(const rtm_dvec3* translation, 
    const rtm_dvec3* rotation, 
    const rtm_dvec3* scale);

// Decompose TRS (transform)
RTMDEF void rtm_dmat4_decompose_trs(const rtm_dmat4* m,
    rtm_dvec3* translation, 
    rtm_dvec3* rotation, 
    rtm_dvec3* scale);

/*===========================================================
 * CAMERA & PROJECTION HELPERS
 *===========================================================*/

/**
 * @brief Returns a look-at view matrix.
 * @param eye Camera position.
 * @param target Target position.
 * @param up Up direction vector.
 */
RTMDEF rtm_dmat4 rtm_dmat4_look_at(
    const rtm_dvec3* eye, 
    const rtm_dvec3* target, 
    const rtm_dvec3* up);

/**
 * @brief Returns a matrix representing a perspective projection.
 * @param fov_y Field of view in the Y direction (radians).
 * @param aspect Aspect ratio.
 * @param near Near clipping plane.
 * @param far Far clipping plane.
 */
RTMDEF rtm_dmat4 rtm_dmat4_perspective(
	double fov_y,
	double aspect,
	double near_plane,
	double far_plane);

/**
 * @brief Returns a matrix representing an orthographic projection.
 * @param left Left clipping plane.
 * @param right Right clipping plane.
 * @param bottom Bottom clipping plane.
 * @param top Top clipping plane.
 * @param near Near clipping plane.
 * @param far Far clipping plane.
 */
RTMDEF rtm_dmat4 rtm_dmat4_ortho(
	double left, double right,
	double bottom, double top,
	double near_plane, double far_plane);

// IMPLEMENTATION
#ifdef RTM_IMPLEMENTATION

#ifndef RT_MATH
#define RT_MATH
#include <math.h>
#endif

RTMDEF int _rtm_dmat4_index(int i, int j) {
	return j * MAT4_SIZE + i;
}


RTMDEF rtm_dmat4 rtm_dmat4_identity(void)
{
    rtm_dmat4 m = {0};
    m.elem[0] = 1.0; m.elem[5] = 1.0; m.elem[10] = 1.0; m.elem[15] = 1.0;
    return m;
}

RTMDEF rtm_dmat4 rtm_dmat4_zero(void)
{
    return (rtm_dmat4) {0}
}

RTMDEF rtm_dmat4 rtm_dmat4_construct_diagonal(double s)
{
    rtm_dmat4 m = {0};
    m.elem[0] = s; m.elem[5] = s; m.elem[10] = s; m.elem[15] = s;
    return m;
}

RTMDEF rtm_dmat4 rtm_dmat4_construct_cols(const rtm_dvec4* c0, const rtm_dvec4* c1, const rtm_dvec4* c2, const rtm_dvec4* c3)
{
    rtm_dmat4 m;
    m.cols[0] = *c0; m.cols[1] = *c1; m.cols[2] = *c2; m.cols[3] = *c3;
    return m;
}

#endif

#ifdef __cplusplus
}
#endif

#endif //!RTM_VEC2_DOUBLE_H