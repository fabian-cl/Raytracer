# Tests/CMakeLists.txt

message(STATUS "Building Tests projects...")

# ----------------------------------------------------------
# Collect all test sources
# ----------------------------------------------------------
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/rtm-test/*.c"
    #"${CMAKE_CURRENT_SOURCE_DIR}/hello_world/*.c"
)

if(NOT TEST_SOURCES)
    message(FATAL_ERROR "No source files found for Test!")
endif()

#add_executable(Tests ${TEST_SOURCES} )

# ----------------------------------------------------------
# Add Unity (test framework)
# ----------------------------------------------------------
add_library(Unity STATIC
    "${CMAKE_SOURCE_DIR}/vendor/unity/src/unity.c"
)

# ==========================================================
# Build one executable per test file
# ==========================================================
foreach(TEST_FILE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    message(STATUS "Building test ${TEST_NAME}...")

    add_executable(${TEST_NAME} ${TEST_FILE})
    # ----------------------------------------------------------
    # Link everything together
    # ----------------------------------------------------------
    target_link_libraries(${TEST_NAME} PRIVATE RTM)

    target_include_directories(${TEST_NAME} PUBLIC
        "${CMAKE_SOURCE_DIR}/lib/rtmath/include"
        "${CMAKE_SOURCE_DIR}/lib/rtmath/include/detail"
        "${CMAKE_SOURCE_DIR}/lib/rtmath/include/ext"
        "${CMAKE_SOURCE_DIR}/vendor/unity/src"
    )

    # ----------------------------------------------------------
    # Output path and folder grouping
    # ----------------------------------------------------------
    set_target_properties(${TEST_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/Tests
        FOLDER "Tests"
    )

    # Register with CTest
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()


#set_target_properties(Tests PROPERTIES
#    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
#    FOLDER "Applications"
#)