#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EXIT_FAILURE -1
#define EPSILON 1e-9
#define APPROX_EQUAL(a,b) (fabs((a)-(b)) < EPSILON)

// ---------- CUSTOM ASSERTION MACROS ----------
#define ASSERT_MSG(cond, fmt, ...) do {                                      \
    if (!(cond)) {                                                          \
        fprintf(stderr, "\n[ASSERT FAILED]\n");                             \
        fprintf(stderr, "  File: %s\n  Line: %d\n", __FILE__, __LINE__);    \
        fprintf(stderr, "  Condition: %s\n", #cond);                        \
        fprintf(stderr, "  Message: " fmt "\n", ##__VA_ARGS__);             \
        exit(EXIT_FAILURE);                                                 \
    }                                                                       \
} while(0)

#define ASSERT_EQ(a,b) ASSERT_MSG((a)==(b), "%s != %s (%f != %f)", #a, #b, (double)(a), (double)(b))
#define ASSERT_NEAR(a,b) ASSERT_MSG(APPROX_EQUAL(a,b), "%s aprox %s (|%f - %f| = %g)", #a, #b, (double)(a), (double)(b), fabs((a)-(b)))

#define TEST_PASS 0
#define TEST_FAIL 1

#define RUN_TEST(name)                          \
    printf("\n=== Running %s ===\n", #name);    \
    printf("Test %s\n", name() ? "FAIL" : "OK");

#endif