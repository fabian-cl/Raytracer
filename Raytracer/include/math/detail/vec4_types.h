#pragma once

typedef struct vec4 {
    union 
    {
        struct {
            double x, y, z, w;
        };

        struct {
            double r, g, b, a;
        };
        struct {
            double s, t, p, q;
        };
        
        double elem[4];
    };
} vec4;

typedef struct fvec4 {
    union 
    {
        struct {
            float x, y, z, w;
        };

        struct {
            float r, g, b, a;
        };
        struct {
            float s, t, p, q;
        };
        
        float elem[4];
    };
} fvec4;

typedef struct ivec4 {
    union 
    {
        struct {
            int x, y, z, w;
        };

        struct {
            int r, g, b, a;
        };
        struct {
            int s, t, p, q;
        };
        
        int elem[4];
    };
} ivec4;