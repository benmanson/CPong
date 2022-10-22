cmake_minimum_required(VERSION 3.10)

project(CPong)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_subdirectory(vendor/googletest)

# Test definitions
enable_testing()
add_subdirectory(test)

# Source definitions
file(GLOB_RECURSE sources "src/*.c")

add_executable(pong ${sources})

find_package(SDL2 REQUIRED)
target_link_libraries(pong ${SDL2_LIBRARIES})

find_package(SDL2_ttf REQUIRED)
target_link_libraries(pong SDL2_ttf::SDL2_ttf)

find_package(SDL2_mixer REQUIRED)
target_link_libraries(pong SDL2_mixer::SDL2_mixer)
