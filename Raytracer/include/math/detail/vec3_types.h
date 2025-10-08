#pragma once

typedef struct vec3 {
    union 
    {
        struct {
            double x, y, z;
        };

        struct {
            double r, g, b;
        };
        struct {
            double s, t, p;
        };
        
        double elem[3];
    };
} vec3;

typedef struct fvec3 {
    union 
    {
        struct {
            float x, y, z;
        };

        struct {
            float r, g, b;
        };
        struct {
            float s, t, p;
        };
        
        float elem[3];
    };
} fvec3;

typedef struct ivec3 {
    union 
    {
        struct {
            int x, y, z;
        };

        struct {
            int r, g, b;
        };
        struct {
            int s, t, p;
        };
        
        int elem[3];
    };
} ivec3;