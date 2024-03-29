cmake_minimum_required(VERSION 3.14)

project(SortProject)
find_package(Python COMPONENTS Interpreter REQUIRED)

add_custom_target(
  GenerateHeader
  BYPRODUCTS ${PROJECT_SOURCE_DIR}/A/index.h
  COMMAND Python::Interpreter ${PROJECT_SOURCE_DIR}/A/preparing.py
  DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
  COMMENT "Создание index.h"
)

add_subdirectory(B ../lib/)
add_executable(C C/main.cpp)
add_dependencies(C GenerateHeader)
target_link_libraries(C SortLibrary)
target_include_directories(C PUBLIC ${PROJECT_SOURCE_DIR})
set_target_properties(C PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(C)