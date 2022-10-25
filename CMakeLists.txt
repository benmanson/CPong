cmake_minimum_required(VERSION 3.10)

project(
    CPong
    VERSION 0.0.0
    LANGUAGES C CXX
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_subdirectory(vendor/googletest)
add_subdirectory(vendor/SDL)
add_subdirectory(vendor/SDL_ttf)

# Source definitions
file(GLOB_RECURSE sources "src/*.c")

add_executable(pong ${sources})

target_include_directories(pong PRIVATE vendor/SDL/include)

target_link_libraries(pong PRIVATE SDL2)
target_link_libraries(pong PRIVATE SDL2_ttf::SDL2_ttf)

# Test definitions
enable_testing()
add_subdirectory(test)
