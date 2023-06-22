#include <iostream>
#include <ctime>
#include "create_game.h"
#include "board.h"
#include "utils.h"

#define FINAL_PATH "sudoku_final.txt"
#define GAME_PATH "sudoku_game.txt"

using namespace std;

int getRand(int min, int max) {
    return (rand() % (max - min) + 1);
}

void create_game(int n, int m, int rMin, int rMax, int u) {
    srand((int) time(nullptr));

    //TODO 根据命令行参数中难度、挖空数量范围来设置blank_num
    int blank_num = 20;                  // 挖空个数
    for (int i = 0; i < n; i++) {
        int final_no = getRand(0, countLines(FINAL_PATH) / 10);
        printf("%d:%d\n", i, final_no);
        game_generate(final_no, blank_num);
    }
}

//根据终局编号final_no、挖空数量blank_num，生成一个游戏
void game_generate(int final_no, int blank_num) {
    Board board;
    //读出第final_no个终局
    board.readBoard(FINAL_PATH, final_no);

    //每个九宫格第一个元素
    int base[9] = {0, 3, 6, 27, 30, 33, 54, 57, 60};
    //每个九宫格内元素相对于第一个元素的偏移
    int offset[9] = {0, 1, 2, 9, 10, 11, 18, 19, 20};

    int hole_block_num = blank_num / 9;//每个九宫格挖空数量
    int hole_remain_num = blank_num % 9;//剩余的挖空数量

    int x, y;//要挖空的位置
    int temp, dot;
    //每个九宫格随机掏空hole_block_num个
    for (int k: base) {
        int num = hole_block_num;
        while (num--) {        //挖hole_block_num个空
            do {
                temp = rand() % 9;
                dot = k + offset[temp];
                x = dot / 9;
                y = dot % 9;
            } while (board.arr[x][y] == 0);
            board.arr[x][y] = 0;
        }
    }

    //再随机挖hole_remain_num个空
    while (hole_remain_num--) {
        do {
            dot = rand() % 81;
            x = dot / 9;
            y = dot % 9;
        } while (board.arr[x][y] == 0);
        board.arr[x][y] = 0;
    }

    board.writeBoard(GAME_PATH);
}
