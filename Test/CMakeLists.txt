# Test/CMakeLists.txt

message(STATUS "Building Test project...")

add_executable(Test
    entry.c
)

add_compile_definitions(USE_OWN_MAIN=0)

target_link_libraries(Test PRIVATE RaytracerCore)

# Include headers from core
target_include_directories(Test PRIVATE
    ${CMAKE_SOURCE_DIR}/RaytracerCore/include
)

set_target_properties(Test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    FOLDER "Applications"
)