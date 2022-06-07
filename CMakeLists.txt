cmake_minimum_required(VERSION 3.10)

project(CPong)

add_subdirectory(vendor/googletest)
add_subdirectory(vendor/SDL)
add_subdirectory(vendor/spdlog)

# Test definitions

enable_testing()
add_subdirectory(test)


# Source definitions

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.c")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(pong ${sources})
target_link_libraries(pong ${SDL2_LIBRARIES})
