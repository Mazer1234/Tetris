cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

target_include_directories(${CMAKE_CURRENT_BINARY_DIR}/GameBoard.h
                            ${CMAKE_CURRENT_BINARY_DIR}/Tetromino.h
                            ${CMAKE_CURRENT_BINARY_DIR}/Player.h)

add_executable(tetris main.cpp GameBoard.cpp Tetromino.cpp Player.cpp)