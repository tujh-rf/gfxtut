# 3.25 was chosen because starting from this version of CMake supports
# LINUX in cmake-variables
cmake_minimum_required( VERSION 3.25 )

project(
    gfxtut
        C CXX
)

# cmake modules folder
list( APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_LIST_DIR}/cmake"
)

# include CMake modules
include( glfw )

# C++ options
set( CMAKE_CXX_STANDARD 23 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# force to release build if nothing else is defined
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Force to set Release build" FORCE)
endif()
add_compile_definitions(
    $<IF:$<CONFIG:DEBUG>,_DEBUG,NDEBUG>
)

# set MSVC warning C4996 to "off"
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# list of samples to build
set( SUPPORT_VULKAN false )
set( SUPPORT_OPENGL false )
set( SUPPORT_DIRECT3D false )

# detect the support from the operation system
if( LINUX )
    set( SUPPORT_VULKAN true )
    set( SUPPORT_OPENGL true )
endif()
if( WIN32 )
    set( SUPPORT_VULKAN true )
    set( SUPPORT_OPENGL true )
    set( SUPPORT_DIRECT3D true )
endif()

fetch_glfw()

add_subdirectory( 01.misc )
