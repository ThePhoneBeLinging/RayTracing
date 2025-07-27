cmake_minimum_required(VERSION 3.31)
project(RayTracer)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        AppleMetal
        GIT_REPOSITORY https://github.com/ThePhoneBeLinging/AppleMetal
        GIT_TAG main
)

FetchContent_MakeAvailable(AppleMetal)

set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)
FetchContent_GetProperties(raylib)
if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    FetchContent_MakeAvailable(raylib)
endif ()

add_executable(RayTracer main.cpp)

target_link_libraries(RayTracer PUBLIC LibAppleMetal raylib)
