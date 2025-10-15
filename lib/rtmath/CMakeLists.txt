# lib/rtmath/CMakeLists.txt
file(GLOB_RECURSE RTM_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/detail/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/ext/*.h"
)

file(GLOB_RECURSE RTM_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

add_library(RTM STATIC ${RTM_SOURCES} ${RTM_HEADERS})

target_include_directories(RTM PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/detail"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/ext"
)

#target_compile_definitions(RTM PRIVATE RTM_USE_STATIC_INLINE)