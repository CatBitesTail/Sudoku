#include "board.h"
using namespace std;

int main(){
    Board b;
    b.readBoard("sudoku_final.txt",1);
    b.output();

    return 0;
}