#pragma once

#include <string>

class Board{
public:
    int arr[9][9]{};
    Board();
    void writeBoard(std::string filename);
    void readBoard(std::string filename, int n);
    void output();
};
