# now entering hell
cmake_minimum_required(VERSION 3.0)
project(monkey_test C)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)

include_directories(monkey/include/)
include_directories(monkey/include/monkey/)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/monkey/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/monkey/include/monkey/)
add_subdirectory(monkey)

add_executable(mk main.c)
target_link_libraries(mk monkey-core-static)
