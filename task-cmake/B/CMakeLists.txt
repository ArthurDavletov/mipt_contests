cmake_minimum_required(VERSION 3.10)

project(SortLibrary)

set(SOURCE_LIB lib.cpp)
set(SOURCE_HEADERS lib.h)
add_library(SortLibrary SHARED ${SOURCE_HEADERS} ${SOURCE_LIB})
install(
    TARGETS SortLibrary
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
)