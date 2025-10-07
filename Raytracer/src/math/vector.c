#include <core/math/vector.h>

vec3 vec3_refract(const vec3* v, const vec3* n, double eta) {
    // Snell’s law
    double dotVN = v->x * n->x + v->y * n->y + v->z * n->z;
    double k = 1.0 - eta * eta * (1.0 - dotVN * dotVN);
    if (k < 0.0) {
        // total internal reflection, return a zero vector or your chosen convention
        return (vec3) { 0.0, 0.0, 0.0 };
    }
    double a = eta * dotVN + sqrt(k);
    return (vec3) {
        eta* v->x - a * n->x,
            eta* v->y - a * n->y,
            eta* v->z - a * n->z
    };
}