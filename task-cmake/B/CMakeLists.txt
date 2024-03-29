cmake_minimum_required(VERSION 3.10)

project(SortLibrary)

set(SOURCE_LIB lib.cpp)
add_library(SortLibrary SHARED ${SOURCE_LIB})
install(
    TARGETS SortLibrary
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
)