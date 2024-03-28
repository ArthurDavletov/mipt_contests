cmake_minimum_required(VERSION 3.10)

project(SortProject)
find_package(Python COMPONENTS Interpreter REQUIRED)

# set(CMAKE_BINARY_DIR bin)

add_custom_target(
  GenerateHeader
  BYPRODUCTS ${PROJECT_SOURCE_DIR}/A/index.h
  COMMAND Python::Interpreter ${PROJECT_SOURCE_DIR}/A/preparing.py
  DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
  COMMENT "Создание index.h"
)

add_subdirectory(B)
add_executable(C C/main.cpp)
add_dependencies(C GenerateHeader)
target_link_libraries(C SortLibrary)
set_target_properties(C PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
install(
    TARGETS SortLibrary
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
)