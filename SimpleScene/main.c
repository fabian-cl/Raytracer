#include <stddef.h>
#include <stdio.h>

//#include <entry.h>

/**
 *  Example of how to code an custom render pipeline 
 **/


// type definition
// TODO: Add unnamed union to the feature/math brach
typedef struct vec2 {
    union {
        struct {
            float x,y;
        };
        struct {
            float u,v;
        };
        
        float elem[2];
    };
    
} vec2;

typedef struct vec3 {
    union {
        struct {
            float x,y,z;
        };
        struct {
            float r,g,b;
        };
        
        float elem[3];
    };
    
} vec3;

typedef struct vec4 {
    union {
        struct 
        {
            float x,y,z,w;
        };
        struct {
            float r,g,b,a;
        };
        float elem[4];
    };
} vec4;

static vec3 vec3_normalize(vec3);

typedef enum {
    RT_FLOAT,
    RT_UNKNOWN
} RT_type;


///////////////////////////////////////////////////////////////////////////////
// CUSTOM RENDER PIPELINE

// vertex layout
typedef struct vertex_layout_in {
    vec3 position;  // Attrib 0
    vec3 color;     // Attrib 1
} vertex_layout_in;

typedef struct vertex_layout_out {
    vec3 position; // conversion position
    vec3 color; // color
} vertex_layout_out;


static void vertex_shader(void* data) {
    // compute each vertex
    vertex_layout_in* in = (vertex_layout_in*) data;
    vertex_layout_out* out = (vertex_layout_out*)data;
    // uniform
    // Render stuff
    out->position = in->position;
    out->color = in->color;
}

static void fragment_shader(void* data) {
    // compute each fragment
}

static void draw_vertices(void* vertex_data, size_t vertex_index_start, size_t vertex_count, size_t stride, RT_type type) {

    // compute all vertex
    /*void* start = vertex_data + vertex_index_start * stride;
    void* end = vertex_data + vertex_count * stride;
    for (void* index= start; index!=end; index+=stride) {
        vertex_shader(index); // pointer to the current vertex
    }*/
}

// from vertex to primitives to fragments and the compute each frament with the fragment_shader() 
///////////////////////////////////////////////////////////////////////////////
/*
int create_application(application* out_app) {
    return 1;
}

int initialize_application(application* app) {
    return 1;
}

int application_update() {
    return 1;
}

int application_draw() {
    return 1;
}
*/
typedef struct foo {
    vec3 pos;
    vec2 uvs;
} foo;

void function(void* data) {
    foo* f = (foo*)data;
    
    printf("position: %f, %f, %f\n", f->pos.x, f->pos.y, f->pos.z);
    printf("uvs: %f, %f\n", f->uvs.u, f->uvs.v);
}

int main()
{
    printf("Hello World\n");
    float data[] = {0.0f,2.0f,0.1f,1.0f,1.0f};

    printf("foo: %zu\n",sizeof(foo));
    printf("vec3: %zu\n",sizeof(vec3));
    printf("vec2: %zu\n",sizeof(vec2));
    printf("float: %zu\n",sizeof(float));

    function(data);
    
    return 0;
}