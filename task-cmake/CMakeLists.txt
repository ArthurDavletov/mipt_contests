cmake_minimum_required(VERSION 3.10)

project(SortProject)

set(CMAKE_BINARY_DIR ../bin)

add_subdirectory(B)
add_executable(C C/main.cpp)
target_link_libraries(C SortLibrary)