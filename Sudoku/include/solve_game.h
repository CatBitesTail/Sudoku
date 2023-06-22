#pragma once
#include <fstream>
#include "board.h"
#include "utils.h"

using namespace std;

void solve(const string& filename);
void readOneBoard(fstream& file, Board& board);
