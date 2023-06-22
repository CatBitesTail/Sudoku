cmake_minimum_required(VERSION 3.25)
project(Sudoku)

set(CMAKE_CXX_STANDARD 14)

include_directories(Sudoku/include)

add_executable(Sudoku
        Sudoku/main.cpp
        Sudoku/src/create_final.cpp
        Sudoku/src/create_game.cpp
        )
