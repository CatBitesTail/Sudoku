#pragma once
#include <fstream>
#include "board.h"

using namespace std;

int countLines(const string& filename);
void readOneBoard(fstream& file, Board& board);
void solve(const string& filename);