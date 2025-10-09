#include <core/math/transform.h>


/* PRIVATE FUNCTIONS */
void _recalculate_model_matrix(Transform* t);

void _tranform_recalculate_position_from_model(Transform* t);
void _tranform_recalculate_scale_from_model(Transform* t);
void _tranform_recalculate_rotation_from_model(Transform* t);

/******************************************************************************
 * IMPLEMENTATION
 *****************************************************************************/
void transform_construct(Transform* t)
{
	t->position = vec3_zero();
	t->scale = vec3_construct_uniform(1);
	t->rotation = vec3_zero();

	_recalculate_model_matrix(t);
}
void transform_construct_from(Transform* t, vec3 position, vec3 scale, vec3 rotation) {
	t->position = position;
	t->scale = scale;
	t->rotation = rotation;

	_recalculate_model_matrix(t);
}

//void transform_construct_ex(Transform* t);
//void transform_construct_from_ex(Transform* t, vec3 position, vec3 scale, vec3 rotation);

/*
void transform_identity(Transform* t) {
	t->position = vec3_zero();
	t->scale = (vec3) {1.0,1.0,1.0};
	t->rotation = vec3_zero();

	_recalculate_model_matrix(t);
}*/

void transform_update(Transform* t) {
	if (t->flag) {
		_recalculate_model_matrix(t);
	}
}

void _recalculate_model_matrix(Transform* t) {
	mat4* m = &(t->model);

	mat4_identity(m);

	mat4_translate(m,m, &t->position);
	mat4_rotate_z(m,m, &t->rotation.z);
	mat4_rotate_y(m,m, &t->rotation.y);
	mat4_rotate_x(m,m, &t->rotation.x);
	mat4_scale(m,m, &t->scale);

	t->flag = false;
}

/*
 *	GETTERS AND SETTERS
 */
void transform_set_position(Transform* t, vec3 p) {
	t->flag = 1;

	t->position = p; // copy
}

void transform_set_scale(Transform* t, vec3 s) {
	t->flag = 1;

	t->scale = s;
}

void transform_set_rotation(Transform* t, vec3 r) {
	t->flag = 1;

	t->rotation = r;
}

vec3 transform_get_position(const Transform* t) { return t->position; }
vec3 transform_get_scale(const Transform* t) { return t->scale; }
vec3 transform_get_rotation(const Transform* t) { return t->rotation; }

mat4 transform_get_model(const Transform* t) { return t->model; }

int transform_is_updated(const Transform* t) { return t->flag; }

/* COMPOSITION */
//void transform_combine(Transform* out, const Transform* a, const Transform* b);
//void transform_inverse(Transform* out, const Transform* t);

/* SPACE CONVERSIONS */

void transform_combine(Transform* out, const Transform* parent, const Transform* child) {
	/*
	transform_update(parent);
	transform_update(child);
		
	mat4_mul(&out->model, &parent->model, &child->model);

	_tranform_recalculate_position_from_model(out);
	_tranform_recalculate_scale_from_model(out);
	_tranform_recalculate_rotation_from_model(out);

	out->flag = FALSE;
	*/
	// TODO
}

void _tranform_recalculate_position_from_model(Transform* t) {
	// TODO
}
void _tranform_recalculate_scale_from_model(Transform* t) {
	// TODO
}
void _tranform_recalculate_rotation_from_model(Transform* t) {
	// TODO
}

// void transform_inverse(Transform* out, const Transform* t) {}