cmake_minimum_required(VERSION 3.31)
project(LibRayTracer)

set(CMAKE_CXX_STANDARD 23)

add_library(LibRayTracer main.cpp)

target_link_libraries(LibRayTracer PUBLIC
        LibAppleMetal)
target_link_libraries(LibRayTracer PUBLIC raylib)
