cmake_minimum_required(VERSION 3.23)
project(Sudoku)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Sudoku")

include_directories(Sudoku/include)

add_executable(Sudoku
        Sudoku/main.cpp
        Sudoku/src/create_final.cpp
        Sudoku/src/create_game.cpp
        Sudoku/src/board.cpp
        Sudoku/src/solve_game.cpp
        Sudoku/src/utils.cpp
        )

add_executable(test
        Sudoku/test.cpp
        Sudoku/src/board.cpp
        Sudoku/src/solve_game.cpp
        Sudoku/src/utils.cpp
        )
