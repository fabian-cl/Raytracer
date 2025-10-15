# RaytracerCore/CMakeLists.txt

message(STATUS "Building RaytracerCore project...")

file(GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core/*.h"
)

file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core/*.c"
)

add_library(RaytracerCore STATIC
    ${CORE_HEADERS}
    ${CORE_SOURCES}
)

target_include_directories(RaytracerCore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CORE_HEADERS} ${CORE_SOURCES})

set_target_properties(RaytracerCore PROPERTIES
    OUTPUT_NAME "RaytracerCore"
    FOLDER "Libraries"
)