#include "utils"

#include <core/math/vector.h>

static int test_construction(void) {
    vec3 v0 = vec3_zero();
    ASSERT_EQ(v0.x, 0); ASSERT_EQ(v0.y, 0); ASSERT_EQ(v0.z, 0);

    vec3 v1 = vec3_one();
    ASSERT_EQ(v1.x, 1); ASSERT_EQ(v1.y, 1); ASSERT_EQ(v1.z, 1);

    vec3 v2 = vec3_construct(2,3,4);
    ASSERT_EQ(v2.x, 2); ASSERT_EQ(v2.y, 3); ASSERT_EQ(v2.z, 4);

    vec3 v3 = vec3_construct_uniform(5);
    ASSERT_EQ(v3.x, 5); ASSERT_EQ(v3.y, 5); ASSERT_EQ(v3.z, 5);

    return TEST_PASS;
}

static int test_add_sub_mult_div(void) {
    vec3 a = vec3_construct(1,2,3);
    vec3 b = vec3_construct(4,5,6);

    vec3 s = vec3_add(&a,&b);
    ASSERT_EQ(s.x,5); ASSERT_EQ(s.y,7); ASSERT_EQ(s.z,9);

    vec3 d = vec3_sub(&b,&a);
    ASSERT_EQ(d.x,3); ASSERT_EQ(d.y,3); ASSERT_EQ(d.z,3);

    vec3 m = vec3_mult(&a,2);
    ASSERT_EQ(m.x,2); ASSERT_EQ(m.y,4); ASSERT_EQ(m.z,6);

    vec3 div = vec3_div(&b,2);
    ASSERT_NEAR(div.x,2.0); ASSERT_NEAR(div.y,2.5); ASSERT_NEAR(div.z,3.0);

    return TEST_PASS;
}

static int test_length_normalize_dot_cross(void) {
    vec3 v = vec3_construct(3,4,0);
    ASSERT_NEAR(vec3_length(&v), 5.0);

    vec3 vn = v;
    vec3_normalize(&vn);
    ASSERT_NEAR(vec3_length(&vn), 1.0);
    ASSERT_NEAR(vn.x, 0.6);
    ASSERT_NEAR(vn.y, 0.8);

    vec3 a = vec3_construct(1,0,0);
    vec3 b = vec3_construct(0,1,0);
    ASSERT_NEAR(vec3_dot(&a,&b), 0.0);

    vec3 c = vec3_cross(&a,&b);
    ASSERT_NEAR(c.x,0.0); ASSERT_NEAR(c.y,0.0); ASSERT_NEAR(c.z,1.0);

    return TEST_PASS;
}

static int test_distance(void) {
    vec3 a = vec3_construct(1,2,3);
    vec3 b = vec3_construct(4,6,3);
    ASSERT_NEAR(vec3_distance(&a,&b), 5.0);

    return TEST_PASS;
}

static int test_copy_clone(void){
    vec3 a = vec3_construct(1,2,3);
    vec3 b; vec3_copy(&b,&a);
    ASSERT_EQ(b.x,1); ASSERT_EQ(b.y,2); ASSERT_EQ(b.z,3);

    vec3 c=vec3_clone(&a);
    ASSERT_EQ(c.x,1); ASSERT_EQ(c.y,2); ASSERT_EQ(c.z,3);
}
static int test_get_set(void) {
    vec3 v=vec3_zero();
    vec3_set_x(&v,3.5);
    vec3_set_y(&v,-2.2);
    vec3_set_z(&v,7.1);
    ASSERT_NEAR(vec3_get_x(&v),3.5);
    ASSERT_NEAR(vec3_get_y(&v),-2.2);
    ASSERT_NEAR(vec3_get_z(&v),7.1);

    return TEST_PASS;
}

static int test_length_and_normalize(void){
    vec3 v=vec3_construct(3,4,0);
    ASSERT_NEAR(vec3_length_squared(&v),25.0);
    ASSERT_NEAR(vec3_length(&v),5.0);

    vec3 vn=v; vec3_normalize(&vn);
    ASSERT_NEAR(vec3_length(&vn),1.0);
    ASSERT_NEAR(vn.x,0.6); ASSERT_NEAR(vn.y,0.8);

    vec3 out; vec3_normalize_ex(&out,&v);
    ASSERT_NEAR(out.x,0.6); ASSERT_NEAR(out.y,0.8); ASSERT_NEAR(out.z,0.0);

    return TEST_PASS;
}

static int test_distance_and_reflect(void) {
    vec3 a=vec3_construct(1,2,3);
    vec3 b=vec3_construct(4,6,3);
    ASSERT_NEAR(vec3_distance(&a,&b),5.0);

    vec3 n=vec3_construct(0,1,0);
    vec3 v=vec3_construct(1,-1,0);
    vec3 r=vec3_reflect(&v,&n);
    ASSERT_NEAR(r.x,1.0);
    ASSERT_NEAR(r.y,1.0);
    ASSERT_NEAR(r.z,0.0);

    return TEST_PASS;
}

static int test_neg_and_hadamard(void){
    vec3 v=vec3_construct(2,-3,4);
    vec3 neg=vec3_neg(&v);
    ASSERT_EQ(neg.x,-2); ASSERT_EQ(neg.y,3); ASSERT_EQ(neg.z,-4);

    vec3 u=vec3_construct(1,2,3);
    vec3 h=vec3_hadamard(&u,&v);
    ASSERT_EQ(h.x,2); ASSERT_EQ(h.y,-6); ASSERT_EQ(h.z,12);

    return TEST_PASS;
}

static int test_dot_cross(void){
    vec3 a=vec3_construct(1,0,0);
    vec3 b=vec3_construct(0,1,0);
    ASSERT_NEAR(vec3_dot(&a,&b),0.0);

    vec3 c=vec3_cross(&a,&b);
    ASSERT_NEAR(c.x,0.0); 
    ASSERT_NEAR(c.y,0.0); 
    ASSERT_NEAR(c.z,1.0);

    return TEST_PASS;
}

static int run_test_vec3(void) {
    
    RUN_TEST(test_construction);
    RUN_TEST(test_add_sub_mult_div);
    printf("\nAll vec3 tests passed successfully!\n");
    return 0;
}
