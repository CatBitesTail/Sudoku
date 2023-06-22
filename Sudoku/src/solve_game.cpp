#include <iostream>
#include <string>
#include <fstream>
#include "solve_game.h"
#include "board.h"

using namespace std;

// 检查行、列、宫是否存在重复。
bool checkRow(){

}

bool checkColumn(){

}

bool checkBlock(){

}

void solveOneBoard(Board& board){
    board.output();
}





void solve(const string& filename){
    fstream file;
    file.open(filename, ios::in);
    string temp;
    Board board;
    int lines = countLines(filename);
    int BoardNum = lines / 10;

    for(int i = 0; i < BoardNum; i++){
        readOneBoard(file, board);
        solveOneBoard(board);
    }

}

int countLines(const string& filename)
{
    ifstream ReadFile;
    int n = 0;
    string tmp;
    ReadFile.open(filename.c_str());//ios::in 表示以只读的方式读取文件
    if(ReadFile.fail()){
        return 0;
    }
    else{
        while(getline(ReadFile,tmp,'\n')){
            n++;
        }
        ReadFile.close();
        return n;
    }
}

void readOneBoard(fstream& file, Board& board){
    string temp;
    for(auto & i : board.arr){
        getline(file, temp);
        for(int j = 0; j < 9; j++){
            i[j] = temp[j] - '0' ;
        }
    }
}

