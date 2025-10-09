#ifndef RTM_DEFINE_H
#define RTM_DEFINE_H

#ifndef RTMDEF
    #if (RTM_USE_STATIC_INLINE)
        #define RTMDEF static inline
    #else
        #define RTMDEF static
    #endif
#endif

#endif