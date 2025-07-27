cmake_minimum_required(VERSION 3.31)
project(LibRayTracer)

set(CMAKE_CXX_STANDARD 23)

add_library(LibRayTracer
        LibRayTracer.cpp
        )

if (APPLE)
    target_link_libraries(LibRayTracer PUBLIC
        LibAppleMetal)
endif ()
target_link_libraries(LibRayTracer PUBLIC raylib)
target_include_directories(LibRayTracer PUBLIC include)
