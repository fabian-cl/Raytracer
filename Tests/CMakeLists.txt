# Tests/CMakeLists.txt

message(STATUS "Building Tests project...")

add_executable(Tests
    main.c
)

add_compile_definitions(USE_OWN_MAIN=1) # This project define its own main

target_link_libraries(Tests PRIVATE RaytracerCore)

# Include headers from core
target_include_directories(Tests PRIVATE
    ${CMAKE_SOURCE_DIR}/RaytracerCore/include
)

set_target_properties(Tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    FOLDER "Applications"
)