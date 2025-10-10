#ifndef RTM_QUATERNION_TYPE_H
#define RTM_QUATERNION_TYPE_H

#include "vec4_types.h"

typedef union rtm_quaternion {
    rtm_dvec4 v;
    double elems[4];
};


#endif
