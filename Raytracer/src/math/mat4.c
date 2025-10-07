#include <core/math/mat4.h>

double* mat4_row(mat4* m, int i)
{
	return &m->values[i * 4];
}

void mat4_mul_vec4(vec4* out, const mat4* m, const vec4* v)
{
	int r = 0;
	out->x =
		m->values[r * 4 + 0] * v->x +
		m->values[r * 4 + 1] * v->y +
		m->values[r * 4 + 2] * v->z +
		m->values[r * 4 + 3] * v->w;

	r = 1;
	out->y =
		m->values[r * 4 + 0] * v->x +
		m->values[r * 4 + 1] * v->y +
		m->values[r * 4 + 2] * v->z +
		m->values[r * 4 + 3] * v->w;

	r = 2;
	out->y =
		m->values[r * 4 + 0] * v->x +
		m->values[r * 4 + 1] * v->y +
		m->values[r * 4 + 2] * v->z +
		m->values[r * 4 + 3] * v->w;

	r = 3;
	out->z =
		m->values[r * 4 + 0] * v->x +
		m->values[r * 4 + 1] * v->y +
		m->values[r * 4 + 2] * v->z +
		m->values[r * 4 + 3] * v->w;
}

void mat4_add(mat4* out, mat4* a, mat4* b) {
	for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			out->values[j * 4 + i] = a->values[j * 4 + i] + b->values[j * 4 + i];
		}
	}
}

void mat4_sub(mat4* out, mat4* a, mat4* b) {
	for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			out->values[j * 4 + i] = a->values[j * 4 + i] - b->values[j * 4 + i];
		}
	}
}

void mat4_mul_point3(vec4* out, const mat4* m, const point3* p) {
	vec4 tmp = vec4_construct_from_vec3(p);

	mat4_mul_vec4(out, m, &tmp);
}

void mat4_mul_dir3(vec4* out, const mat4* m, const dir3* p) {
	vec4 tmp = vec4_construct_from_vec3(p);
	tmp.w = 1;

	mat4_mul_vec4(out, m, &tmp);
}

void mat4_mul(mat4* out, const mat4* a, const mat4* b)
{
	for (size_t row = 0; row < 4; ++row) {
		for (size_t col = 0; col < 4; ++col) {
			double sum = 0.0;
			for (size_t k = 0; k < 4; ++k) {
				sum += a->values[row * 4 + k] * b->values[k * 4 + col];
			}
			out->values[row * 4 + col] = sum;
		}
	}
}

void mat4_translate_matrix(mat4* out, const vec3* m) {
	mat4_identity(out);
	
	out->values[_mat4_index(0, 3)] = m->x;
	out->values[_mat4_index(1, 3)] = m->x;
	out->values[_mat4_index(2, 3)] = m->x;
	out->values[_mat4_index(3, 3)] = 1;
}

void mat4_scale_matrix(mat4* out, const vec3* m) {
	mat4_identity(out);

	out->values[_mat4_index(0, 0)] = m->x;
	out->values[_mat4_index(1, 1)] = m->x;
	out->values[_mat4_index(2, 2)] = m->x;
	out->values[_mat4_index(3, 3)] = 1;
}

void mat4_translate(mat4* out, const mat4* m, const vec3* v) {
	mat4 translation_matrix;
	mat4_zero(&translation_matrix);

	mat4_translation_matrix(&translation_matrix, v);

	mat4_mul(out, m, &translation_matrix);
}

void mat4_scale(mat4* out, const mat4* m, const vec3* v) {
	mat4 scale_matrix;
	mat4_zero(&scale_matrix);

	mat4_scale_matrix(&scale_matrix, v);

	mat4_mul(out, m, &scale_matrix);
}