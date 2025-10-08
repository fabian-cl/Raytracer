#pragma once

typedef struct vec2 {
    union 
    {
        struct {
            double x, y;
        };

        struct {
            double r, g;
        };
        struct {
            double s, t;
        };
        
        double elem[2];
    };
} vec2;

typedef struct fvec2 {
    union 
    {
        struct {
            float x, y;
        };

        struct {
            float r, g;
        };
        struct {
            float s, t;
        };
        
        float elem[2];
    };
} fvec2;

typedef struct ivec2 {
    union 
    {
        struct {
            int x, y;
        };

        struct {
            int r, g;
        };
        struct {
            int s, t;
        };
        
        int elem[2];
    };
} ivec2;