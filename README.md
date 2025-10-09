# What is the idea
The idea behind this project is to recreate a simple raytracer using C, fully in the CPU side.

# What is it the branch for ?

Feature test and developing of the math module

The layout is inspired by GLM (glm/core, glm/ext, glm/detail), stb and HandmadeMath.

# Project Structure
Raytracer/
├── include/
│   ├── core/
│   │
│   └── .../
│
├── src/
│   ├── core/
│   │   └── ...
│   └── rtmath.c
│
Tests/
├── test_vec.c
├── test_mat.c
└── test_all.c
lib/
├── rtmath/
│   ├── rtmath.h
│   ├── detail/
│   │   ├── vec2_types.h
│   │   ├── vec3_types.h
│   │   ├── vec4_types.h
│   │   ├── mat2_types.h
│   │   ├── mat3_types.h
│   │   ├── mat4_types.h
│   │   └── common.h
│   │
│   └── ext/
│       ├── vec2_ext_float.h
│       ├── vec2_ext_double.h
│       ├── vec3_ext_float.h
│       ├── vec3_ext_double.h
│       ├── vec4_ext_float.h
│       ├── vec4_ext_double.h
│       ├── mat4_ext_double.h
│       └── ...
└── ...
# Folder explication
## lib/
My own defined libraries

## smath/detail/
- Contains type definitions only.
- No logic, just structs and unions (like your vec3, fvec3, ivec3).
- These are the building blocks — low-level representations used by everything else.

Example: vec3_types.h
typedef struct vec3 {
    union {
        struct { double x, y, z; };
        struct { double r, g, b; };
        struct { double s, t, p; };
        double elem[3];
    };
} vec3;

## ext/
- Contains extensions for each type, one file per precision or variation.
- Each file provides math operations (add, dot, cross, etc.) for a single type.
- Implementations are optional via the macro pattern.

## rtmath.h
- Central include for the math core.
- Includes all types and extensions.
- Acts as a single entry point for users

# Future improvements
-[ ] Complete this README xD

# Others
## References
- <https://github.com/g-truc/glm>
- <https://github.com/nothings/stb>
- <https://github.com/HandmadeMath/HandmadeMath/tree/master>