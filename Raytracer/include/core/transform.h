#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector.h"
#include "mat4.h"

#ifndef __cplusplus
#ifndef BOOL
#define BOOL

#define TRUE	0
#define FALSE	1

typedef enum { false = 0, true = 1 } bool;

#endif // !BOOL
#endif // !__cplusplus


typedef struct Transform {
	/* world-space translation */
	vec3 position;
	/* per-axis scale */
	vec3 scale;
	/* Euler angles in radians: pitch (x), yaw (y), roll (z) */
	vec3 rotation;

	mat4 model;

	/* 
	 * Dirty Flag 
	 * If its value is 0 it means that the transform matrix model its up to date
	 * Any changes made to the transform put flag value to 1
	 */
	int flag;
} Transform;


/******************************************************************************
 * DECLARATION
 *****************************************************************************/

/*
 *	Create an initial transfrom matrix.
 *	- Position is set to (0,0,0)
 *	- Scale is set to (1,1,1)
 *	- Rotation is set to (0,0,0)
 */ 
void transform_construct(Transform* t);
void transform_construct_from(Transform* t, vec3 position, vec3 scale, vec3 rotation);

//void transform_construct_ex(Transform* t);
//void transform_construct_from_ex(Transform* t, vec3 position, vec3 scale, vec3 rotation);

//void transform_identity(void);

/*
 *	GETTERS AND SETTERS 
 */
void transform_set_position(Transform* t, vec3 p);
void transform_set_scale(Transform* t, vec3 s);
void transform_set_rotation(Transform* t, vec3 r);

vec3 transform_get_position(const Transform* t);
vec3 transform_get_scale(const Transform* t);
vec3 transform_get_rotation(const Transform* t);

/* Does not check if the transform model is up to date */
mat4 transform_get_model(const Transform* t);

/* MODIFIERS */
void transform_translate(Transform* t, vec3 delta);
void transform_rotate(Transform* t, vec3 delta);
void transform_scale(Transform* t, vec3 factor);

/* Update the transform matrix */
void transform_update(Transform* t);

/* SPACE CONVERSIONS */
void transform_point(const Transform* t, const vec3* p_local);
vec3 transform_direction(const Transform* t, const vec3* d_local);

/* COMPOSITION */
void transform_combine(Transform* out, const Transform* parent, const Transform* child);
//void transform_inverse(Transform* out, const Transform* t);

/* DEBUG */
// show the matrix to the console.
void transform_print(Transform* t);
// Write matrix to buffer.
void transform_write(Transform* t, char* buf);

#endif // !TRANSFORM_H

