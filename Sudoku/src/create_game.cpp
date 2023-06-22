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

void create_game(int n) {
    srand((int) time(nullptr));

    int blank_num = 10;                  // 挖空个数
    for (int i = 0; i < n; i++) {
        //TODO 怎么知道已经有多少个终局，从而设置getRand的max，暂定从1~100中选
        int final_no = getRand(0, countLines(FINAL_PATH)/10);
        printf("%d:%d\n", i, final_no);
//        game_generate(final_no, blank_num);
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

    //每个九宫格随机掏空hole_block_num个
    for (int k: base) {
        int i, j; // 3*3里面掏的位置
        int temp,dot;
        while (hole_block_num--) {        //挖hole_block_num个空
            do {
                temp=rand()%9;
                dot = k + offset[temp];
                i = dot / 9;
                j = dot % 9;
            }while (board.arr[i][j] == 0);
            board.arr[i][j]=0;
        }
    }

    // 已经掏空了18个
//    int others;
//    others = 12 + rand() % 31;//再掏12-41个就可以了
//    while (others--) {
//        int k = rand() % 81;
//        int i = k / 9;
//        int j = k % 9;
//
//        if (board.arr[i][j] != '0'){
//            board.arr[i][j] = '0';
//        }else{
//            others++;
//        }
//    }


    board.writeBoard(GAME_PATH);
}
