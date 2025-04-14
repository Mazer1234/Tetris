cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MDd")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GTEST_SOURCE_DIR "C:/Users/LEOPA/Desktop/Programming/Projects/google_test/googletest")

add_subdirectory(${GTEST_SOURCE_DIR} ${CMAKE_BINARY_DIR}/googletest-build)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(my_test_executable test/tests.cpp src/GameBoard.cpp)

target_link_libraries(my_test_executable PRIVATE GTest::gtest GTest::gtest_main)

