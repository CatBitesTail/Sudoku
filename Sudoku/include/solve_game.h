#pragma once
#include <fstream>
#include "board.h"

using namespace std;

void solve(const string& filename);
int countLines(const string& filename);
void readOneBoard(fstream& file, Board& board);
