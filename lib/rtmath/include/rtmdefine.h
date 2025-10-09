#ifndef RTM_DEFINE_H
#define RTM_DEFINE_H

#ifndef RTMDEF
    #if (RTM_USE_STATIC_INLINE)
        #define RTMDEF static inline
    #else
        #define RTMDEF static
    #endif
#endif

#ifndef RTM_bool
    #define RTM_bool unsigned
    #define RTM_TRUE 0
    #define RTM_FALSE 1
#endif

#ifndef RTM_EPSILON
    #define RTM_EPSION 1e-9
#endif

#endif