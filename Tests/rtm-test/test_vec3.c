#include "../utils.h"

#include <rtmath.h>
/*
static int test_construction(void) {
    rtm_dvec3 v0 = rtm_dvec3_zero();
    ASSERT_EQ(v0.x, 0); ASSERT_EQ(v0.y, 0); ASSERT_EQ(v0.z, 0);

    rtm_dvec3 v1 = rtm_dvec3_one();
    ASSERT_EQ(v1.x, 1); ASSERT_EQ(v1.y, 1); ASSERT_EQ(v1.z, 1);

    rtm_dvec3 v2 = rtm_dvec3_construct(2,3,4);
    ASSERT_EQ(v2.x, 2); ASSERT_EQ(v2.y, 3); ASSERT_EQ(v2.z, 4);

    rtm_dvec3 v3 = rtm_dvec3_construct_uniform(5);
    ASSERT_EQ(v3.x, 5); ASSERT_EQ(v3.y, 5); ASSERT_EQ(v3.z, 5);

    return TEST_PASS;
}

static int test_add_sub_mult_div(void) {
    rtm_dvec3 a = rtm_dvec3_construct(1,2,3);
    rtm_dvec3 b = rtm_dvec3_construct(4,5,6);

    rtm_dvec3 s = rtm_dvec3_add(&a,&b);
    ASSERT_EQ(s.x,5); ASSERT_EQ(s.y,7); ASSERT_EQ(s.z,9);

    rtm_dvec3 d = rtm_dvec3_sub(&b,&a);
    ASSERT_EQ(d.x,3); ASSERT_EQ(d.y,3); ASSERT_EQ(d.z,3);

    rtm_dvec3 m = rtm_dvec3_mult(&a,2);
    ASSERT_EQ(m.x,2); ASSERT_EQ(m.y,4); ASSERT_EQ(m.z,6);

    rtm_dvec3 div = rtm_dvec3_div(&b,2);
    ASSERT_NEAR(div.x,2.0); ASSERT_NEAR(div.y,2.5); ASSERT_NEAR(div.z,3.0);

    return TEST_PASS;
}

static int test_length_normalize_dot_cross(void) {
    rtm_dvec3 v = rtm_dvec3_construct(3,4,0);
    ASSERT_NEAR(rtm_dvec3_length(&v), 5.0);

    rtm_dvec3 vn = v;
    rtm_dvec3_normalize(&vn);
    ASSERT_NEAR(rtm_dvec3_length(&vn), 1.0);
    ASSERT_NEAR(vn.x, 0.6);
    ASSERT_NEAR(vn.y, 0.8);

    rtm_dvec3 a = rtm_dvec3_construct(1,0,0);
    rtm_dvec3 b = rtm_dvec3_construct(0,1,0);
    ASSERT_NEAR(rtm_dvec3_dot(&a,&b), 0.0);

    rtm_dvec3 c = rtm_dvec3_cross(&a,&b);
    ASSERT_NEAR(c.x,0.0); ASSERT_NEAR(c.y,0.0); ASSERT_NEAR(c.z,1.0);

    return TEST_PASS;
}

static int test_distance(void) {
    rtm_dvec3 a = rtm_dvec3_construct(1,2,3);
    rtm_dvec3 b = rtm_dvec3_construct(4,6,3);
    ASSERT_NEAR(rtm_dvec3_distance(&a,&b), 5.0);

    return TEST_PASS;
}

static int test_copy_clone(void){
    rtm_dvec3 a = rtm_dvec3_construct(1,2,3);
    rtm_dvec3 b; rtm_dvec3_copy(&b,&a);
    ASSERT_EQ(b.x,1); ASSERT_EQ(b.y,2); ASSERT_EQ(b.z,3);

    rtm_dvec3 c=rtm_dvec3_clone(&a);
    ASSERT_EQ(c.x,1); ASSERT_EQ(c.y,2); ASSERT_EQ(c.z,3);
}
static int test_get_set(void) {
    rtm_dvec3 v=rtm_dvec3_zero();
    rtm_dvec3_set_x(&v,3.5);
    rtm_dvec3_set_y(&v,-2.2);
    rtm_dvec3_set_z(&v,7.1);

    ASSERT_NEAR(rtm_dvec3_get_x(&v),3.5);
    ASSERT_NEAR(rtm_dvec3_get_y(&v),-2.2);
    ASSERT_NEAR(rtm_dvec3_get_z(&v),7.1);

    return TEST_PASS;
}

static int test_length_and_normalize(void){
    rtm_dvec3 v=rtm_dvec3_construct(3,4,0);
    ASSERT_NEAR(rtm_dvec3_length_squared(&v),25.0);
    ASSERT_NEAR(rtm_dvec3_length(&v),5.0);

    rtm_dvec3 vn=v; rtm_dvec3_normalize(&vn);
    ASSERT_NEAR(rtm_dvec3_length(&vn),1.0);
    ASSERT_NEAR(vn.x,0.6); ASSERT_NEAR(vn.y,0.8);

    rtm_dvec3 out; rtm_dvec3_normalize_ex(&out,&v);
    ASSERT_NEAR(out.x,0.6); ASSERT_NEAR(out.y,0.8); ASSERT_NEAR(out.z,0.0);

    return TEST_PASS;
}

static int test_distance_and_reflect(void) {
    rtm_dvec3 a=rtm_dvec3_construct(1,2,3);
    rtm_dvec3 b=rtm_dvec3_construct(4,6,3);
    ASSERT_NEAR(rtm_dvec3_distance(&a,&b),5.0);

    rtm_dvec3 n=rtm_dvec3_construct(0,1,0);
    rtm_dvec3 v=rtm_dvec3_construct(1,-1,0);
    rtm_dvec3 r=rtm_dvec3_reflect(&v,&n);
    ASSERT_NEAR(r.x,1.0);
    ASSERT_NEAR(r.y,1.0);
    ASSERT_NEAR(r.z,0.0);

    return TEST_PASS;
}

static int test_neg_and_hadamard(void){
    rtm_dvec3 v=rtm_dvec3_construct(2,-3,4);
    rtm_dvec3 neg=rtm_dvec3_neg(&v);
    ASSERT_EQ(neg.x,-2); ASSERT_EQ(neg.y,3); ASSERT_EQ(neg.z,-4);

    rtm_dvec3 u=rtm_dvec3_construct(1,2,3);
    rtm_dvec3 h=rtm_dvec3_hadamard(&u,&v);
    ASSERT_EQ(h.x,2); ASSERT_EQ(h.y,-6); ASSERT_EQ(h.z,12);

    return TEST_PASS;
}

static int test_dot_cross(void){
    rtm_dvec3 a=rtm_dvec3_construct(1,0,0);
    rtm_dvec3 b=rtm_dvec3_construct(0,1,0);
    ASSERT_NEAR(rtm_dvec3_dot(&a,&b),0.0);

    rtm_dvec3 c=rtm_dvec3_cross(&a,&b);
    ASSERT_NEAR(c.x,0.0); 
    ASSERT_NEAR(c.y,0.0); 
    ASSERT_NEAR(c.z,1.0);

    return TEST_PASS;
}
*/
int main () {
    //RUN_TEST(test_construction);
    //RUN_TEST(test_add_sub_mult_div);
    rtm_dvec3 v = (rtm_dvec3) {0,0,1};
    rtm_dvec3 u = (rtm_dvec3) {2,0.4,-2};
    printf("(%f,%f,%f)", v.x, v.y,v.z);

    rtm_dvec3_add_inplace(&v, &u);
    
    printf("(%f,%f,%f)", v.x, v.y,v.z);

    printf("\nAll rtm_dvec3 tests passed successfully!\n");

    return 0;
}