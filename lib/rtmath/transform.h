#ifndef RTM_TRANSFORM_TYPE_H
#define RTM_TRANSFORM_TYPE_H

#include "detail/vec4_types.h"

typedef union rtm_quat {
    rtm_dvec4 v;
    double elems[4];
};


#endif //!RTM_TRANSFORM_TYPE_H
