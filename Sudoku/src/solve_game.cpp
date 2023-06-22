#include <iostream>
#include <string>
#include "solve_game.h"
#include "board.h"

using namespace std;

// 检查行、列、宫是否存在重复。
bool isValid(Board& board, int row, int col, int num) {
    for (int k = 0; k < 9; k++) {
        // 判断行是否存在重复
        if (board.arr[row][k] == num) return false;
        // 判断列是否存在重复
        if (board.arr[k][col] == num) return false;
        // 判断 3 x 3 方框是否存在重复
        if (board.arr[(row / 3) * 3 + k / 3][(col / 3) * 3 + k % 3] == num)
            return false;
    }
    return true;
}

bool solveOneBoardMin(Board& board, int i, int j){
    int m = 9, n = 9;
    // 换行
    if (j == n) {
        // 穷举到最后一列的话就换到下一行重新开始。
        return solveOneBoardMin(board, i + 1, 0);
    }
    // 终止条件
    if (i == m){
        return true;
    }

    // 如果该位置是预设的数字，不用我们操心
    if (board.arr[i][j] != 0) {
        return solveOneBoardMin(board, i, j + 1);
    }

    for (int num = 1; num <= 9; num++) {
        // 如果遇到不合法的数字，就跳过
        if (!isValid(board, i, j, num))
            continue;

        board.arr[i][j] = num;

        if(solveOneBoardMin(board, i, j + 1)){
            return true;
        }
        board.arr[i][j] = 0;
    }

    return false;
}

bool solveOneBoardMax(Board& board, int i, int j){
    int m = 9, n = 9;
    // 换行
    if (j == n) {
        // 穷举到最后一列的话就换到下一行重新开始。
        return solveOneBoardMax(board, i + 1, 0);
    }
    // 终止条件
    if (i == m){
        return true;
    }

    // 如果该位置是预设的数字，不用我们操心
    if (board.arr[i][j] != 0) {
        return solveOneBoardMax(board, i, j + 1);
    }

    for (int num = 9; num >= 1; num--) {
        // 如果遇到不合法的数字，就跳过
        if (!isValid(board, i, j, num))
            continue;

        board.arr[i][j] = num;

        if(solveOneBoardMax(board, i, j + 1)){
            return true;
        }
        board.arr[i][j] = 0;
    }

    return false;
}


void solve(const string& filename){
    fstream file;
    file.open(filename, ios::in);
    Board board;
    int lines = countLines(filename);
    int BoardNum = lines / 10;

    for(int i = 0; i < BoardNum; i++){
        readOneBoard(file, board);
        bool answerExist = solveOneBoardMin(board, 0, 0);
        if(answerExist){
            board.writeBoard("sudoku.txt");
        }
    }

    file.close();
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

bool onlyResult(Board board) {
    Board temp = board;
    bool answerExist = solveOneBoardMin(temp, 0, 0);
    if(answerExist){
        solveOneBoardMax(board, 0, 0);
        return compareBoard(temp, board);
    }
    return false;
}

bool compareBoard(Board a, Board b){
    for(int i = 0;i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(a.arr[i][j]!=b.arr[i][j])
                return false;
        }
    }
    return true;
}



//int ansSum = 0;
//bool test(Board& board, int i, int j, int num){
//    int m = 9, n = 9;
//    // 换行
//    if (j == n) {
//        // 穷举到最后一列的话就换到下一行重新开始。
//        return test(board, i + 1, 0, num);
//    }
//
//    if(i==0&&j==0&num==10){
//
//    }
//
//    if(num == 10){
//        if(j == 0){
//            return test(board, i-1, 8, board.arr[i][j-1]+1);
//        }
//        return test(board, i, j - 1, board.arr[i][j-1]+1);
//    }
//    // 终止条件
//    if (i == m){
//        ansSum++;
//        return true;
//    }
//
//
//
//    // 如果遇到不合法的数字，就跳过
//    if (!isValid(board, i, j, num)){
//        test(board, i, j+1, num+1);
//    }
//
//    board.arr[i][j] = num;
//
//    if(solveOneBoard(board, i, j + 1)){
//        return true;
//    }
//    board.arr[i][j] = 0;
//
//    return false;
//}


