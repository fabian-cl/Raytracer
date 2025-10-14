cmake_minimum_required(VERSION 3.15)
project(Raytracer LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

#target_compile_options(Raytracer PRIVATE -Wall -Wextra -Werror)

# Set Unicode definition - Win32API specific configuration
add_definitions(-DUNICODE -D_UNICODE)

# Output directories (for organized builds)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-int)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-int)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Enable folders in Visual Studio for better organization
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message(STATUS "Building projects...")

# Add subdirectories (each one has its own CMakeLists.txt)
#add_subdirectory(RaytracerCore)
add_subdirectory(Tests)