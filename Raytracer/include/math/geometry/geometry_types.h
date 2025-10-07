#pragma once

#include "../vector.h"

typedef struct geo_square {
	point3 upper_left;
	point3 bottom_right;
} geo_square;

typedef struct geo_sphere {
	point3 center;
	double radius;
} geo_sphere;

typedef struct geo_triangle {
	point3 a, b, c;
} geo_triangle;

/**
typedef struct geo_plane {
	
} geo_plane;
*/