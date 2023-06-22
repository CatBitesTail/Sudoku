#include <iostream>
#include <string>
#include <fstream>
#include "solve_game.h"
#include "board.h"

using namespace std;

// 检查行、列、宫是否存在重复。
bool isValid(Board& board, int i, int j, int num) {
    for (int k = 0; k < 9; k++) {
        // 判断行是否存在重复
        if (board.arr[i][j] == num) return false;
        // 判断列是否存在重复
        if (board.arr[i][j] == num) return false;
        // 判断 3 x 3 方框是否存在重复
        if (board.arr[(i/3)*3 + i/3][(j/3)*3 + i%3] == num)
            return false;
    }
    return true;
}

bool solveOneBoard(Board& board, int i, int j){
    int m = 9, n = 9;
    // 换行
    if (j == n) {
        // 穷举到最后一列的话就换到下一行重新开始。
        return solveOneBoard(board, i + 1, 0);
    }
    // 终止条件
    if (i == m){
        return true;
    }

    // 如果该位置是预设的数字，不用我们操心
    if (board.arr[i][j] != 0) {
        return solveOneBoard(board, i, j + 1);
    }

    for (int num = 1; num <= 9; num++) {
        // 如果遇到不合法的数字，就跳过
        if (!isValid(board, i, j, num))
            continue;

        board.arr[i][j] = num;

        if(solveOneBoard(board, i, j + 1)){
            return true;
        }
        board.arr[i][j] = 0;
    }

    return false;
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
        bool answerExist = solveOneBoard(board, 0, 0);
        if(answerExist){
            board.writeBoard("result.txt");
        }
    }

    file.close();
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
    // 读最后一个换行符
    getline(file, temp);
}

