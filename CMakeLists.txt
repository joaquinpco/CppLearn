cmake_minimum_required(VERSION 3.16)
project(MatrixProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
include(CTest)

# Fetch GoogleTest automatically
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
# Prevent GoogleTest from overriding our compiler flags
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include directories
include_directories(include)

# App executable
file(GLOB SOURCES src/*.cpp)
# add_executable(matrix_app ${SOURCES}) Optional if _main() exist

# Unit tests
add_executable(matrix_tests test/test_matrix.cpp src/matrix.cpp)
target_link_libraries(matrix_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(matrix_tests)
