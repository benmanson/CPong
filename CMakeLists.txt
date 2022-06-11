cmake_minimum_required(VERSION 3.10)

project(CPong)

add_subdirectory(vendor/googletest)
add_subdirectory(vendor/SDL)
add_subdirectory(vendor/SDL_mixer)

# Test definitions

enable_testing()
add_subdirectory(test)


# Source definitions

file(GLOB sources "src/*.c")

find_package(SDL2 REQUIRED)

include_directories(
    "${SDL2_INCLUDE_DIRS}"
    "${PROJECT_SOURCE_DIR}/include"
)

add_executable(pong ${sources})
target_link_libraries(pong ${SDL2_LIBRARIES})
