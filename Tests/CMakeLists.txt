# Tests/CMakeLists.txt

message(STATUS "Building Tests projects...")

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/rtm-test/*.c"
)

add_executable(Tests
    ${TEST_SOURCES}
)

file(GLOB_RECURSE RTM_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/lib/rtmath/detail/*.h"
    "${CMAKE_SOURCE_DIR}/lib/rtmath/ext/*.h"
    "${CMAKE_SOURCE_DIR}/lib/rtmath/*.h"
)

file(GLOB_RECURSE TEST_UTILS CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/utils/*.h"
)

file(GLOB_RECURSE RTM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/rtmath.c" )

add_library(RTM STATIC
    ${RTM_SOURCES} ${RTM_HEADERS}
)

# Add Unity library
add_library(Unity STATIC
    "${CMAKE_SOURCE_DIR}/vendor/unity/src/unity.c"
)

target_include_directories(RTM PUBLIC
    "${CMAKE_SOURCE_DIR}/lib/rtmath"
    "${CMAKE_SOURCE_DIR}/lib/rtmath/detail"
    "${CMAKE_SOURCE_DIR}/lib/rtmath/ext"
)

#add_compile_definitions(USE_OWN_MAIN=1) # This project define its own main

target_link_libraries(Tests PRIVATE RTM Unity)

# Include headers from rtm
target_include_directories(Tests PRIVATE
    "${CMAKE_SOURCE_DIR}/lib/rtmath"
    "${CMAKE_SOURCE_DIR}/lib/rtmath/detail"
    "${CMAKE_SOURCE_DIR}/lib/rtmath/ext"
    "${CMAKE_SOURCE_DIR}/vendor/unity/src"
)

set_target_properties(Tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    FOLDER "Applications"
)