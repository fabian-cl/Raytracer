#pragma once

#ifndef MATRIX_4_H
#define MATRIX_4_H

//#include <stdalign.h> //alignas

#include <string.h>

#include "vector.h"

#define MAT4_SIZE 16
#define MAT4_ROWS 4
#define MAT4_COLS 4

// matrix of 4x4 double
typedef struct mat4 {
	//alignas(16) 
	double values[MAT4_SIZE];
} mat4;

static inline int _mat4_index(int i, int j)
{
	return j * MAT4_SIZE + i;
}

static inline void mat4_zero(mat4* out) {
	for (int i = 0; i < MAT4_SIZE; i++)
	{
		out->values[i] = 0.0;
	}
}

static inline void mat4_identity(mat4* out) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			out->values[j * 4 + i] = (i == j) ? 1 : 0;
		}
	}
}

/* COPY */
static inline void mat4_copy(mat4* out, const mat4* src) {
	memcpy(out->values, src->values, sizeof(src->values));
}

static inline mat4 mat4_clone(const mat4* src) { return *src; }

/* GET AND SETTERS */
static inline void mat4_set(mat4* m, int x, int y, double new_value)
{
	m->values[_mat4_index(x, y)] = new_value;
}

static inline double mat4_get(const mat4* m, int x, int y)
{
	return m->values[_mat4_index(x, y)];
}

// it return a pointer to the first element of row i
// The returned pointer becomes invalid if the matrix is reallocated.
double* mat4_row(mat4* m, int i);

// MATH OPERATIONS
///////////////////////////////////////////////////////////////////////////////

void mat4_add(mat4 *out, mat4 *a, mat4 *b);
void mat4_sub(mat4* out, mat4* a, mat4* b);

void mat4_mul(mat4* out, const mat4* a, const mat4* b);

void mat4_mul_point3(vec4* out, const mat4* m, const point3* p);
void mat4_mul_dir3(vec4* out, const mat4* m, const dir3* p);

void mat4_mul_vec4(vec4 *out, const mat4* m, const vec4* v);

static inline void mat4_transpose(mat4* t)
{
	for (int r = 0; r < 4; ++r) {
		for (int c = r + 1; c < 4; ++c) {
			double tmp = t->values[r * 4 + c];
			t->values[r * 4 + c] = t->values[c * 4 + r];
			t->values[c * 4 + r] = tmp;
		}
	}
}

static inline double mat4_determinant(const mat4* a)
{
	const double* m = a->values;

	double det =
		m[3] * m[6] * m[9] * m[12] - m[2] * m[7] * m[9] * m[12] -
		m[3] * m[5] * m[10] * m[12] + m[1] * m[7] * m[10] * m[12] +
		m[2] * m[5] * m[11] * m[12] - m[1] * m[6] * m[11] * m[12] -
		m[3] * m[6] * m[8] * m[13] + m[2] * m[7] * m[8] * m[13] +
		m[3] * m[4] * m[10] * m[13] - m[0] * m[7] * m[10] * m[13] -
		m[2] * m[4] * m[11] * m[13] + m[0] * m[6] * m[11] * m[13] +
		m[3] * m[5] * m[8] * m[14] - m[1] * m[7] * m[8] * m[14] -
		m[3] * m[4] * m[9] * m[14] + m[0] * m[7] * m[9] * m[14] +
		m[1] * m[4] * m[11] * m[14] - m[0] * m[5] * m[11] * m[14] -
		m[2] * m[5] * m[8] * m[15] + m[1] * m[6] * m[8] * m[15] +
		m[2] * m[4] * m[9] * m[15] - m[0] * m[6] * m[9] * m[15] -
		m[1] * m[4] * m[10] * m[15] + m[0] * m[5] * m[10] * m[15];

	return det;
}

// mat4 must be inversable!
static inline void mat4_inverse(mat4* out, const mat4* a)
{
    const double* m = a->values;
    double inv[16];

    inv[0] = m[5] * m[10] * m[15] -
        m[5] * m[11] * m[14] -
        m[9] * m[6] * m[15] +
        m[9] * m[7] * m[14] +
        m[13] * m[6] * m[11] -
        m[13] * m[7] * m[10];

    inv[4] = -m[4] * m[10] * m[15] +
        m[4] * m[11] * m[14] +
        m[8] * m[6] * m[15] -
        m[8] * m[7] * m[14] -
        m[12] * m[6] * m[11] +
        m[12] * m[7] * m[10];

    inv[8] = m[4] * m[9] * m[15] -
        m[4] * m[11] * m[13] -
        m[8] * m[5] * m[15] +
        m[8] * m[7] * m[13] +
        m[12] * m[5] * m[11] -
        m[12] * m[7] * m[9];

    inv[12] = -m[4] * m[9] * m[14] +
        m[4] * m[10] * m[13] +
        m[8] * m[5] * m[14] -
        m[8] * m[6] * m[13] -
        m[12] * m[5] * m[10] +
        m[12] * m[6] * m[9];

    inv[1] = -m[1] * m[10] * m[15] +
        m[1] * m[11] * m[14] +
        m[9] * m[2] * m[15] -
        m[9] * m[3] * m[14] -
        m[13] * m[2] * m[11] +
        m[13] * m[3] * m[10];

    inv[5] = m[0] * m[10] * m[15] -
        m[0] * m[11] * m[14] -
        m[8] * m[2] * m[15] +
        m[8] * m[3] * m[14] +
        m[12] * m[2] * m[11] -
        m[12] * m[3] * m[10];

    inv[9] = -m[0] * m[9] * m[15] +
        m[0] * m[11] * m[13] +
        m[8] * m[1] * m[15] -
        m[8] * m[3] * m[13] -
        m[12] * m[1] * m[11] +
        m[12] * m[3] * m[9];

    inv[13] = m[0] * m[9] * m[14] -
        m[0] * m[10] * m[13] -
        m[8] * m[1] * m[14] +
        m[8] * m[2] * m[13] +
        m[12] * m[1] * m[10] -
        m[12] * m[2] * m[9];

    inv[2] = m[1] * m[6] * m[15] -
        m[1] * m[7] * m[14] -
        m[5] * m[2] * m[15] +
        m[5] * m[3] * m[14] +
        m[13] * m[2] * m[7] -
        m[13] * m[3] * m[6];

    inv[6] = -m[0] * m[6] * m[15] +
        m[0] * m[7] * m[14] +
        m[4] * m[2] * m[15] -
        m[4] * m[3] * m[14] -
        m[12] * m[2] * m[7] +
        m[12] * m[3] * m[6];

    inv[10] = m[0] * m[5] * m[15] -
        m[0] * m[7] * m[13] -
        m[4] * m[1] * m[15] +
        m[4] * m[3] * m[13] +
        m[12] * m[1] * m[7] -
        m[12] * m[3] * m[5];

    inv[14] = -m[0] * m[5] * m[14] +
        m[0] * m[6] * m[13] +
        m[4] * m[1] * m[14] -
        m[4] * m[2] * m[13] -
        m[12] * m[1] * m[6] +
        m[12] * m[2] * m[5];

    inv[3] = -m[1] * m[6] * m[11] +
        m[1] * m[7] * m[10] +
        m[5] * m[2] * m[11] -
        m[5] * m[3] * m[10] -
        m[9] * m[2] * m[7] +
        m[9] * m[3] * m[6];

    inv[7] = m[0] * m[6] * m[11] -
        m[0] * m[7] * m[10] -
        m[4] * m[2] * m[11] +
        m[4] * m[3] * m[10] +
        m[8] * m[2] * m[7] -
        m[8] * m[3] * m[6];

    inv[11] = -m[0] * m[5] * m[11] +
        m[0] * m[7] * m[9] +
        m[4] * m[1] * m[11] -
        m[4] * m[3] * m[9] -
        m[8] * m[1] * m[7] +
        m[8] * m[3] * m[5];

    inv[15] = m[0] * m[5] * m[10] -
        m[0] * m[6] * m[9] -
        m[4] * m[1] * m[10] +
        m[4] * m[2] * m[9] +
        m[8] * m[1] * m[6] -
        m[8] * m[2] * m[5];

    double det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
    if (det == 0.0) return;  // Non-invertible

    det = 1.0 / det;
    for (int i = 0; i < 16; i++)
        out->values[i] = inv[i] * det;
}

// Affine / Geometric Transforms

void mat4_translate_matrix(mat4* out, const vec3* m);
void mat4_scale_matrix(mat4* out, const vec3* m);

void mat4_translate(mat4* out, const mat4* m, const vec3* v);

void mat4_scale(mat4* out, const mat4* m, const vec3* v);

void mat4_rotation_x(mat4* out, double radians);
void mat4_rotation_y(mat4* out, double radians);
void mat4_rotation_z(mat4* out, double radians);

void mat4_rotation_axis(mat4* out, const vec3* axis, double radians);

// Camera & Projection Helpers

void mat4_look_at(mat4* out,
	const vec3* eye,
	const vec3* center,
	const vec3* up);

void mat4_perspective(mat4* out,
	double fov_y_radians,
	double aspect,
	double near_plane,
	double far_plane);

void mat4_ortho(mat4* out,
	double left, double right,
	double bottom, double top,
	double near_plane, double far_plane);

// UTILITY

// compare with tolerance
int mat4_equals(const mat4* a, const mat4* b, double eps);

void mat4_print(const mat4* m);

void mat4_write(const mat4* m, char* buffer);

#endif // !MATRIX_4_H
