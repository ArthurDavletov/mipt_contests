cmake_minimum_required(VERSION 3.10)

project(SortProject)

set(CMAKE_BINARY_DIR ../bin)
add_library(SortProject lib.cpp)
add_executable(C ../C/main.cpp)
