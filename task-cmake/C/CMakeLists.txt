cmake_minimum_required(VERSION 3.14)

project(GTestProject)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(CTest main_test.cpp task_A.cpp task_B.cpp)

add_dependencies(CTest GenerateHeader)

target_include_directories(CTest PRIVATE ${PROJECT_SOURCE_DIR}/..)
target_link_libraries(CTest GTest::gtest_main)
target_link_libraries(CTest SortLibrary)

include(GoogleTest)
gtest_discover_tests(CTest)
set_target_properties(CTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin)
