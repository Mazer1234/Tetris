cmake_minimum_required(VERSION 3.10)
project(Tetris)




add_executable(tetris main.cpp GameBoard.cpp Tetromino.cpp Player.cpp TetrominoGenerator.cpp GameSession.cpp)