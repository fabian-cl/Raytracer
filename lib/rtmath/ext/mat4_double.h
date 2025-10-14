#ifndef RTM_MAT4_DOUBLE_H
#define RTM_MAT4_DOUBLE_H
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
RTMDEF void rtm_dmat4_identity_to(rtm_dmat4* out);

RTMDEF rtm_dmat4 rtm_dmat4_zero(void);
RTMDEF void rtm_dmat4_zero_to(rtm_dmat4* out);

/**
 * @brief Constructs a matrix from 4 column vectors.
 * @param c0 First column.
 * @param c1 Second column.
 * @param c2 Third column.
 * @param c3 Fourth column.
 */
RTMDEF rtm_dmat4 rtm_dmat4_construct_cols(const rtm_dvec4* c0, const rtm_dvec4* c1, const rtm_dvec4* c2, const rtm_dvec4* c3);
RTMDEF void rtm_dmat4_construct_cols_to(rtm_dmat4* out, 
    const rtm_dvec4* c0, 
    const rtm_dvec4* c1, 
    const rtm_dvec4* c2, 
    const rtm_dvec4* c3);

/**
 * @brief Constructs a diagonal matrix with a given scalar on the diagonal.
 * @param s The diagonal value.
 */
RTMDEF rtm_dmat4 rtm_dmat4_construct_diagonal(double s);
RTMDEF void rtm_dmat4_construct_diagonal_to(rtm_dmat4* out , double s);

//RTMDEF rtm_dmat4 rtm_dmat4_from_rows(rtm_dvec4 v0, rtm_dvec4 v1, rtm_dvec4 v2, rtm_dvec4 v3);

/*===========================================================
 * COPY/CLONE
 *===========================================================*/

RTMDEF void rtm_dmat4_copy(rtm_dmat4* out, const rtm_dmat4* src);
RTMDEF rtm_dmat4 rtm_dmat4_clone(const rtm_dmat4* src);

/*===========================================================
 * GETTERS/SETTERS
 *===========================================================*/

RTMDEF double rtm_dmat4_get(const rtm_dmat4* m, int x, int y);
RTMDEF void rtm_dmat4_set(const rtm_dmat4* m, int x, int y, double new_value);

rtm_dvec4* rtm_dmat4_col(rtm_dmat4* m, int i);

/*===========================================================
 * ARITHMETIC
 *===========================================================*/

RTMDEF rtm_dmat4 rtm_dmat4_add(const rtm_dmat4* a, const rtm_dmat4* b);
RTMDEF void rtm_dmat4_add_to(rtm_dmat4* out, const rtm_dmat4* a, const rtm_dmat4* b);
RTMDEF void rtm_dmat4_add_inplace(rtm_dmat4* a, const rtm_dmat4* b);

RTMDEF rtm_dmat4 rtm_dmat4_sub(const rtm_dmat4* a, const rtm_dmat4* b);
RTMDEF void rtm_dmat4_sub_to(rtm_dmat4* out, const rtm_dmat4* a, const rtm_dmat4* b);
RTMDEF void rtm_dmat4_sub_inplace(rtm_dmat4* a, const rtm_dmat4* b);

RTMDEF rtm_dmat4 rtm_dmat4_mult_scalar(const rtm_dmat4* a, double s);
RTMDEF void rtm_dmat4_mult_scalar_to(rtm_dmat4* out, const rtm_dmat4* a, double s);
RTMDEF void rtm_dmat4_mult_scalar_inplace(rtm_dmat4* a, double s);

RTMDEF rtm_dmat4 rtm_dmat4_div_scalar(rtm_dmat4 a, double s);
RTMDEF void rtm_dmat4_div_scalar_to(rtm_dmat4* out, const rtm_dmat4* a, double s);
RTMDEF void rtm_dmat4_div_scalar_inplace(rtm_dmat4* a, double s);

/**
 * @brief Multiplies two 4x4 matrices (result = a * b).
 */
RTMDEF rtm_dmat4 rtm_dmat4_mult(const rtm_dmat4* a, const rtm_dmat4* b);

/**
 * @brief Multiplies two 4x4 matrices and stores the result in `out`.
 * @param out Output matrix (cannot alias `a` or `b`).
 * @param a Left operand.
 * @param b Right operand.
 */
RTMDEF void rtm_dmat4_mult_to(rtm_dmat4* out, const rtm_dmat4* a, const rtm_dmat4* b);

/**
 * @brief Multiplies matrix `a` by `b` in place (a = a * b).
 */
RTMDEF void rtm_dmat4_mult_inplace(rtm_dmat4* a, const rtm_dmat4* b);

/**
 * @brief Multiplies a matrix by a 4D vector (result = m * v).
 */
RTMDEF rtm_dvec4 rtm_dmat4_mult_vec4(const rtm_dmat4* m, const rtm_dvec4* v);
RTMDEF void rtm_dmat4_mult_vec4_to(rtm_dmat4* out, const rtm_dmat4* m, const rtm_dvec4* v);
RTMDEF void rtm_dmat4_mult_vec4_inplace(rtm_dmat4* m, const rtm_dvec4* v);


/**
 * @brief Computes the transpose of a matrix.
 */
RTMDEF rtm_dmat4 rtm_dmat4_transpose(const rtm_dmat4* m);
RTMDEF rtm_dmat4 rtm_dmat4_transpose_to(rtm_dmat4* out, const rtm_dmat4* m);
RTMDEF rtm_dmat4 rtm_dmat4_transpose_inplace(rtm_dmat4* m);

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
RTMDEF void rtm_dmat4_inverse_to(rtm_dmat4* out, const rtm_dmat4* m);
RTMDEF void rtm_dmat4_inverse_inplace(rtm_dmat4* m);

/*===========================================================
 * TRANSFORM
 *===========================================================*/

/**
 * @brief Creates a translation matrix.
 * @param translation 3D translation vector.
 */
RTMDEF rtm_dmat4 rtm_dmat4_translation(const rtm_dvec3* translation);
RTMDEF void rtm_dmat4_translation_to(rtm_dmat4* out, const rtm_dvec3* translation);

/**
 * @brief Creates a scaling matrix.
 * @param scale 3D scale vector.
 */
RTMDEF rtm_dmat4 rtm_dmat4_scale(const rtm_dvec3* scale);
RTMDEF void rtm_dmat4_scale_to(rtm_dmat4* out, const rtm_dvec3* scale);

/**
 * @brief Creates a rotation matrix around the X-axis.
 * @param angle_radians Angle in radians.
 */
RTMDEF rtm_dmat4 rtm_dmat4_rotation_x(double angle_radians);
RTMDEF void rtm_dmat4_rotation_x_to(rtm_dmat4* out, double angle_radians);

/**
 * @brief Creates a rotation matrix around the Y-axis.
 * @param angle_radians Angle in radians.
 */
RTMDEF rtm_dmat4 rtm_dmat4_rotation_y(double angle_radians);
RTMDEF void rtm_dmat4_rotation_y_to(rtm_dmat4* out, double angle_radians);

/**
 * @brief Creates a rotation matrix around the Z-axis.
 * @param angle_radians Angle in radians.
 */
RTMDEF rtm_dmat4 rtm_dmat4_rotation_z(double angle_radians);
RTMDEF void rtm_dmat4_rotation_z_to(rtm_dmat4* out, double angle_radians);

/**
 * @brief Creates a rotation matrix from Euler angles (XYZ order).
 * @param euler 3D vector containing angles in radians.
 */
RTMDEF rtm_dmat4 rtm_dmat4_rotation_euler(const rtm_dvec3* euler);
RTMDEF void rtm_dmat4_rotation_euler_to(rtm_dmat4* out, const rtm_dvec3* euler);

//RTMDEF rtm_dmat4 rtm_dmat4_rotation_axis(const rtm_dvec3* axis, double radians);

// Compose TRS (transform)
RTMDEF rtm_dmat4 rtm_dmat4_trs(const rtm_dvec3* translation, 
    const rtm_dvec3* rotation, 
    const rtm_dvec3* scale);

RTMDEF void rtm_dmat4_trs_to(rtm_dmat4* out,
    const rtm_dvec3* translation, 
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

RTMDEF void rtm_dmat4_look_at_to(rtm_dmat4* out,
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

RTMDEF void rtm_dmat4_perspective_to(rtm_dmat4* out,
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

RTMDEF void rtm_dmat4_ortho_to(rtm_dmat4* out,
	double left, double right,
	double bottom, double top,
	double near_plane, double far_plane);

/* *
 *  The math matches OpenGL’s right-handed coordinate convention.
 *  The look-at matrix builds a camera transform where +Z faces backward.
 *  You can flip the Z terms if you need DirectX-style (left-handed) space.
 * */
// IMPLEMENTATION
#ifdef RTM_IMPLEMENTATION

#ifndef RT_MATH
#define RT_MATH
#include <math.h>
#endif

#include <string.h>  // for memcpy

#include "vec3_double.h"
#include "vec4_double.h"

RTMDEF int _rtm_dmat4_index(int i, int j) {
	return j * MAT4_SIZE + i;
}


RTMDEF rtm_dmat4 rtm_dmat4_identity(void)
{
    rtm_dmat4 m = {0};
    m.elem[0] = 1.0; m.elem[5] = 1.0; m.elem[10] = 1.0; m.elem[15] = 1.0;
    return m;
}

RTMDEF void rtm_dmat4_identity_to(rtm_dmat4* out) {
    rtm_dmat4_zero_to(out);
    out->elem[0] = 1.0; 
    out->elem[5] = 1.0; 
    out->elem[10] = 1.0;
    out->elem[15] = 1.0;
}

RTMDEF rtm_dmat4 rtm_dmat4_zero(void) {
    return (rtm_dmat4) {0}
}

RTMDEF void rtm_dmat4_zero_to(rtm_dmat4* out) {
    *out = (rtm_dmat4) {0};
}

RTMDEF void rtm_dmat4_zero(rtm_dmat4* out) {
    for (int i = 0; i < MAT4_SIZE; i++)
	{
		out->values[i] = 0.0;
	}
}

RTMDEF rtm_dmat4 rtm_dmat4_construct_cols(const rtm_dvec4* c0, const rtm_dvec4* c1, const rtm_dvec4* c2, const rtm_dvec4* c3)
{
    rtm_dmat4 m;
    m.cols[0] = *c0; m.cols[1] = *c1; m.cols[2] = *c2; m.cols[3] = *c3;
    return m;
}

RTMDEF rtm_dmat4 rtm_dmat4_construct_cols_to(rtm_dmat4* out, const rtm_dvec4* c0, const rtm_dvec4* c1, const rtm_dvec4* c2, const rtm_dvec4* c3)
{
    out->cols[0] = *c0;
    out->cols[1] = *c1; 
    out->cols[2] = *c2; 
    out->cols[3] = *c3;
}

RTMDEF rtm_dmat4 rtm_dmat4_construct_diagonal(double s)
{
    rtm_dmat4 m = {0};
    m.elem[0] = s; m.elem[5] = s; m.elem[10] = s; m.elem[15] = s;
    return m;
}

RTMDEF void rtm_dmat4_construct_diagonal_to(rtm_dmat4* out, double s) {
    rtm_dmat4_zero_to(out);
    out->elem[0] = s; 
    out->elem[5] = s; 
    out->elem[10] = s;
    out->elem[15] = s;
}

RTMDEF void rtm_dmat4_copy(rtm_dmat4* out, const rtm_dmat4* src) {
    memcpy(out->values, src->values, sizeof(src->values));
}

RTMDEF rtm_dmat4 rtm_dmat4_clone(const rtm_dmat4* src) { return *src; }

RTMDEF double rtm_dmat4_get(const rtm_dmat4* m, int x, int y) {
    return m->values[_rtm_dmat4_index(x, y)];
}

RTMDEF void rtm_dmat4_set(const rtm_dmat4* m, int x, int y, double new_value) {
    m->values[_rtm_dmat4_index(x, y)] = new_value;
}

rtm_dvec4* rtm_dmat4_col(rtm_dmat4* m, int i) {
    return m->cols[i];
}

RTMDEF rtm_dmat4 rtm_dmat4_add(const rtm_dmat4* a, const rtm_dmat4* b) {
    rtm_dmat4 m = {0};

    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			m.elem[j * 4 + i] = a->values[j * 4 + i] + b->values[j * 4 + i];
		}
	}

    return m;
}

RTMDEF void rtm_dmat4_add_to(rtm_dmat4* out, const rtm_dmat4* a, const rtm_dmat4* b) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			out->elem[j * 4 + i] = a->values[j * 4 + i] + b->values[j * 4 + i];
		}
	}
}

RTMDEF void rtm_dmat4_add_inplace(rtm_dmat4* a, const rtm_dmat4* b) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			a->elem[j * 4 + i] = a->values[j * 4 + i] + b->values[j * 4 + i];
		}
	}
}

RTMDEF rtm_dmat4 rtm_dmat4_sub(const rtm_dmat4* a, const rtm_dmat4* b) {
    rtm_dmat4 m = {0};

    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			m.elem[j * 4 + i] = a->values[j * 4 + i] - b->values[j * 4 + i];
		}
	}

    return m;
}
RTMDEF void rtm_dmat4_sub_to(rtm_dmat4* out, const rtm_dmat4* a, const rtm_dmat4* b) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			out->elem[j * 4 + i] = a->values[j * 4 + i] - b->values[j * 4 + i];
		}
	}
}

RTMDEF void rtm_dmat4_sub_inplace(rtm_dmat4* a, const rtm_dmat4* b) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			a->elem[j * 4 + i] = a->values[j * 4 + i] - b->values[j * 4 + i];
		}
	}
}

RTMDEF rtm_dmat4 rtm_dmat4_mult_scalar(const rtm_dmat4* a, double s) {
    rtm_dmat4 m = {0};

    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			m.elem[j * 4 + i] = a->values[j * 4 + i] * s;
		}
	}

    return m;
}

RTMDEF void rtm_dmat4_mult_scalar_to(rtm_dmat4* out, const rtm_dmat4* a,double s) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			out->elem[j * 4 + i] = a->values[j * 4 + i] * s;
		}
	}
}

RTMDEF void rtm_dmat4_mult_scalar_inplace(rtm_dmat4* a, double s) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			a->elem[j * 4 + i] = a->values[j * 4 + i] * s;
		}
	}
}

RTMDEF rtm_dmat4 rtm_dmat4_div_scalar(const rtm_dmat4* a, double s) {
    rtm_dmat4 m = {0};

    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			m.elem[j * 4 + i] = a->values[j * 4 + i] / s;
		}
	}

    return m;
}

RTMDEF void rtm_dmat4_div_scalar_to(rtm_dmat4* out, const rtm_dmat4* a,double s) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			out->elem[j * 4 + i] = a->values[j * 4 + i] / s;
		}
	}
}

RTMDEF void rtm_dmat4_div_scalar_inplace(rtm_dmat4* a, double s) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			a->elem[j * 4 + i] = a->values[j * 4 + i] / s;
		}
	}
}

RTMDEF rtm_dmat4 rtm_dmat4_mult(const rtm_dmat4* a, const rtm_dmat4* b)
{
    rtm_dmat4 out = {0};
    for (int i = 0; i < 4; i++) // row
    {
        for (int j = 0; j < 4; j++) // col
        {
            double sum = 0.0;
            for (int k = 0; k < 4; k++)
                sum += a->elem[i*4 + k] * b->elem[k*4 + j];
            out.elem[i*4 + j] = sum;
        }
    }
    return out;
}

RTMDEF void rtm_dmat4_mult_to(rtm_dmat4* out, const rtm_dmat4* a, const rtm_dmat4* b)
{
    *out = rtm_dmat4_mult(a, b);
}

RTMDEF void rtm_dmat4_mult_inplace(rtm_dmat4* a, const rtm_dmat4* b)
{
    rtm_dmat4 temp = rtm_dmat4_mult(a, b);
    *a = temp;
}

RTMDEF rtm_dvec4 rtm_dmat4_mult_vec4(const rtm_dmat4* m, const rtm_dvec4* v)
{
    rtm_dvec4 out;
    out.x = m->cols[0].x*v->x + m->cols[1].x*v->y + m->cols[2].x*v->z + m->cols[3].x*v->w;
    out.y = m->cols[0].y*v->x + m->cols[1].y*v->y + m->cols[2].y*v->z + m->cols[3].y*v->w;
    out.z = m->cols[0].z*v->x + m->cols[1].z*v->y + m->cols[2].z*v->z + m->cols[3].z*v->w;
    out.w = m->cols[0].w*v->x + m->cols[1].w*v->y + m->cols[2].w*v->z + m->cols[3].w*v->w;
    return out;
}

RTMDEF void rtm_dmat4_mult_vec4_to(rtm_dmat4* out, const rtm_dmat4* m, const rtm_dvec4* v) {
    *out = rtm_dmat4_mult_vec4(m, v);
}

RTMDEF void rtm_dmat4_mult_vec4_inplace(rtm_dmat4* m, const rtm_dvec4* v) {
    rtm_dmat4 temp = rtm_dmat4_mult_vec4(m, v);
    *a = temp;
}

RTMDEF rtm_dmat4 rtm_dmat4_transpose(const rtm_dmat4* m) {
    rtm_dmat4 out;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            out.elem[i*4 + j] = m->elem[j*4 + i];
    return out;
}

RTMDEF void rtm_dmat4_transpose_to(rtm_dmat4* out, const rtm_dmat4* m)
{
    *out = rtm_dmat4_transpose(m);
}

RTMDEF void rtm_dmat4_transpose_inplace(rtm_dmat4* m)
{
    rtm_dmat4 temp = rtm_dmat4_transpose(m);
    *m = temp;
}

/*-----------------------------------------------------------
 * Determinant (helper: 3x3 minor)
 *-----------------------------------------------------------*/
RTMDEF _det3x3(double m[9])
{
    return m[0]*(m[4]*m[8]-m[5]*m[7]) -
           m[1]*(m[3]*m[8]-m[5]*m[6]) +
           m[2]*(m[3]*m[7]-m[4]*m[6]);
}

RTMDEF double rtm_dmat4_determinant(const rtm_dmat4* m)
{
    double det = 0.0;
    double minor[9];
    int sign = 1;

    for(int col=0; col<4; col++)
    {
        int idx = 0;
        for(int i=1;i<4;i++)
            for(int j=0;j<4;j++)
                if(j != col)
                    minor[idx++] = m->elem[i*4 + j];
        det += sign * m->elem[col] * det3x3(minor);
        sign = -sign;
    }
    return det;
}

/*-----------------------------------------------------------
 * Matrix inverse (using cofactors)
 *-----------------------------------------------------------*/
RTMDEF rtm_dmat4 rtm_dmat4_inverse(const rtm_dmat4* m)
{
    rtm_dmat4 inv;
    double det = rtm_dmat4_determinant(m);
    if(fabs(det) < 1e-12) // singular
    {
        memset(&inv, 0, sizeof(inv));
        return inv;
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            // Build minor for element (j,i) because we compute adjoint
            double minor[9];
            int idx=0;
            for(int row=0;row<4;row++)
            {
                if(row==i) continue;
                for(int col=0;col<4;col++)
                {
                    if(col==j) continue;
                    minor[idx++] = m->elem[row*4 + col];
                }
            }
            inv.elem[i*4 + j] = ((i+j)%2==0 ? 1.0 : -1.0) * det3x3(minor) / det;
        }
    }
    return inv;
}

RTMDEF void rtm_dmat4_inverse_to(rtm_dmat4* out, const rtm_dmat4* m)
{
    *out = rtm_dmat4_inverse(m);
}

RTMDEF rtm_dmat4 rtm_dmat4_inverse_inplace(rtm_dmat4* m)
{
    rtm_dmat4 temp = rtm_dmat4_inverse(m);
    *m = temp;
}

RTMDEF rtm_dmat4 rtm_dmat4_translation(const rtm_dvec3* translation) {
    rtm_dmat4 m = {0};
    m.elem[_rtm_dmat4(0,3)] = translation[0];
    m.elem[_rtm_dmat4(1,3)] = translation[1];
    m.elem[_rtm_dmat4(2,3)] = translation[2];
    m.elem[_rtm_dmat4(3,3)] = 1;

    return m;
}

RTMDEF void rtm_dmat4_translation_to(rtm_dmat4* out, const rtm_dvec3* translation) {
    *out = rtm_dmat4_translation(translation);
}

RTMDEF rtm_dmat4 rtm_dmat4_scale(const rtm_dvec3* scale) {
    rtm_dmat4 m = {0};

    m.elem[_rtm_dmat4(0,0)] = translation[0];
    m.elem[_rtm_dmat4(1,1)] = translation[1];
    m.elem[_rtm_dmat4(2,2)] = translation[2];
    m.elem[_rtm_dmat4(3,3)] = 1;

    return m;
}

RTMDEF void rtm_dmat4_scale_to(rtm_dmat4* out, const rtm_dvec3* scale) {
    *out = rtm_dmat4_translation(translation);
}

RTMDEF rtm_dmat4 rtm_dmat4_rotation_x(double angle)
{
    double c = cos(angle);
    double s = sin(angle);

    rtm_dmat4 m = {0};
    m.elem[0] = 1.0; m.elem[5] = c;  m.elem[6] = -s; m.elem[10] = c;  m.elem[9] = s; m.elem[15] = 1.0;
    return m;
}

RTMDEF void rtm_dmat4_rotation_x_to(rtm_dmat4* out, double angle)
{
    *out = rtm_dmat4_rotation_x(angle);
}

/*-----------------------------------------------------------
 * Rotation around Y-axis
 *-----------------------------------------------------------*/
RTMDEF rtm_dmat4 rtm_dmat4_rotation_y(double angle)
{
    double c = cos(angle);
    double s = sin(angle);

    rtm_dmat4 m = {0};
    m.elem[0] = c;  m.elem[2] = s;  m.elem[5] = 1.0; m.elem[8] = -s; m.elem[10] = c; m.elem[15] = 1.0;
    return m;
}

RTMDEF void rtm_dmat4_rotation_y_to(rtm_dmat4* out, double angle)
{
    *out = rtm_dmat4_rotation_y(angle);
}

/*-----------------------------------------------------------
 * Rotation around Z-axis
 *-----------------------------------------------------------*/
RTMDEF rtm_dmat4 rtm_dmat4_rotation_z(double angle)
{
    double c = cos(angle);
    double s = sin(angle);

    rtm_dmat4 m = {0};
    m.elem[0] = c;  m.elem[1] = -s; m.elem[4] = s;  m.elem[5] = c;
    m.elem[10] = 1.0; m.elem[15] = 1.0;
    return m;
}

RTMDEF void rtm_dmat4_rotation_z_to(rtm_dmat4* out, double angle)
{
    *out = rtm_dmat4_rotation_z(angle);
}

/*-----------------------------------------------------------
 * Rotation from Euler angles (XYZ order)
 *-----------------------------------------------------------*/
RTMDEF rtm_dmat4 rtm_dmat4_rotation_euler(const rtm_dvec3* euler)
{
    rtm_dmat4 rx = rtm_dmat4_rotation_x(euler->x);
    rtm_dmat4 ry = rtm_dmat4_rotation_y(euler->y);
    rtm_dmat4 rz = rtm_dmat4_rotation_z(euler->z);

    // Combined rotation: R = Rz * Ry * Rx (XYZ order)
    return rtm_dmat4_mult(&rz, &rtm_dmat4_mult(&ry, &rx));
}

RTMDEF void rtm_dmat4_rotation_euler_to(rtm_dmat4* out, const rtm_dvec3* euler)
{
    *out = rtm_dmat4_rotation_euler(euler);
}

RTMDEF rtm_dmat4 rtm_dmat4_trs(const rtm_dvec3* translation, 
    const rtm_dvec3* rotation, 
    const rtm_dvec3* scale) {

    rtm_dmat4 m = rtm_dmat4_identity();
    
    rtm_dmat4_translation(m,m, &t->position);
	rtm_dmat4_rotation_z(m,m, &t->rotation.z);
	rtm_dmat4_rotation_y(m,m, &t->rotation.y);
	rtm_dmat4_rotation_x(m,m, &t->rotation.x);
	rtm_dmat4_scale(m,m, &t->scale);

    return m;
}

RTMDEF void rtm_dmat4_trs_to(rtm_dmat4* out,
    const rtm_dvec3* translation, 
    const rtm_dvec3* rotation, 
    const rtm_dvec3* scale) {

    *out = rtm_dmat4_trs(translation, rotation, scale)
}

// Decompose TRS (transform)
RTMDEF void rtm_dmat4_decompose_trs(const rtm_dmat4* m,
    rtm_dvec3* translation, 
    rtm_dvec3* rotation, 
    rtm_dvec3* scale) {

    //TODO
}

RTMDEF rtm_dmat4 rtm_dmat4_look_at(
    const rtm_dvec3* eye, 
    const rtm_dvec3* target, 
    const rtm_dvec3* up) {

    rtm_dmat4 result;
    rtm_dmat4_look_at_to(&result, eye, target, up);
    return result;
}

RTMDEF rtm_dmat4 rtm_dmat4_look_at_to(rtm_dmat4* out,
    const rtm_dvec3* eye, 
    const rtm_dvec3* target, 
    const rtm_dvec3* up) {

    rtm_dvec3 f = rtm_dvec3_normalize(&(rtm_dvec3_sub(target, eye)));
    rtm_dvec3 s = rtm_dvec3_normalize(&(rtm_dvec3_cross(&f, up)));
    rtm_dvec3 u = rtm_dvec3_cross(&s, &f);

    out->m[0][0] =  s.x; out->m[0][1] =  u.x; out->m[0][2] = -f.x; out->m[0][3] = 0.0;
    out->m[1][0] =  s.y; out->m[1][1] =  u.y; out->m[1][2] = -f.y; out->m[1][3] = 0.0;
    out->m[2][0] =  s.z; out->m[2][1] =  u.z; out->m[2][2] = -f.z; out->m[2][3] = 0.0;
    out->m[3][0] = -rtm_dvec3_dot(&s, eye);
    out->m[3][1] = -rtm_dvec3_dot(&u, eye);
    out->m[3][2] =  rtm_dvec3_dot(&f, eye);
    out->m[3][3] = 1.0;
}

/**
 * @brief Creates a perspective projection matrix.
 */
RTMDEF rtm_dmat4 rtm_dmat4_perspective(
    double fov_y,
    double aspect,
    double near_plane,
    double far_plane)
{
    rtm_dmat4 result;
    rtm_dmat4_perspective_to(&result, fov_y, aspect, near_plane, far_plane);
    return result;
}

RTMDEF void rtm_dmat4_perspective_to(
    rtm_dmat4* out,
    double fov_y,
    double aspect,
    double near_plane,
    double far_plane)
{
    double f = 1.0 / tan(fov_y / 2.0);
    double nf = 1.0 / (near_plane - far_plane);

    out->m[0][0] = f / aspect;
    out->m[0][1] = 0.0;
    out->m[0][2] = 0.0;
    out->m[0][3] = 0.0;

    out->m[1][0] = 0.0;
    out->m[1][1] = f;
    out->m[1][2] = 0.0;
    out->m[1][3] = 0.0;

    out->m[2][0] = 0.0;
    out->m[2][1] = 0.0;
    out->m[2][2] = (far_plane + near_plane) * nf;
    out->m[2][3] = -1.0;

    out->m[3][0] = 0.0;
    out->m[3][1] = 0.0;
    out->m[3][2] = (2.0 * far_plane * near_plane) * nf;
    out->m[3][3] = 0.0;
}

/**
 * @brief Creates an orthographic projection matrix.
 */
RTMDEF rtm_dmat4 rtm_dmat4_ortho(
    double left, double right,
    double bottom, double top,
    double near_plane, double far_plane)
{
    rtm_dmat4 result;
    rtm_dmat4_ortho_to(&result, left, right, bottom, top, near_plane, far_plane);
    return result;
}

RTMDEF void rtm_dmat4_ortho_to(
    rtm_dmat4* out,
    double left, double right,
    double bottom, double top,
    double near_plane, double far_plane)
{
    double rl = right - left;
    double tb = top - bottom;
    double fn = far_plane - near_plane;

    out->m[0][0] = 2.0 / rl;
    out->m[0][1] = 0.0;
    out->m[0][2] = 0.0;
    out->m[0][3] = 0.0;

    out->m[1][0] = 0.0;
    out->m[1][1] = 2.0 / tb;
    out->m[1][2] = 0.0;
    out->m[1][3] = 0.0;

    out->m[2][0] = 0.0;
    out->m[2][1] = 0.0;
    out->m[2][2] = -2.0 / fn;
    out->m[2][3] = 0.0;

    out->m[3][0] = -(right + left) / rl;
    out->m[3][1] = -(top + bottom) / tb;
    out->m[3][2] = -(far_plane + near_plane) / fn;
    out->m[3][3] = 1.0;
}

#endif

#ifdef __cplusplus
}
#endif

#endif //!RTM_MAT4_DOUBLE_H