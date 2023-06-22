#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
#include "create_game.h"

#define  SUDOKUPATH "sudoku_final.txt"
#define  QUESPATH "sudoku_game.txt"

using namespace std;

int getRand(int min, int max)
{
    return (rand() % (max - min));
}

void create_game(int n)
{
    srand((int)time(nullptr));

    int blank_num = 10;                  // 挖空个数
    int *sudoku_final_line = new int[n]; // 随机选n个终局的初始行号
    for (int i = 0; i < n; i++)
    {
        sudoku_final_line[i] = getRand(0, n) * 10 + 1;
        printf("%d:%d\n",i,sudoku_final_line[i]);
    }
    delete[] sudoku_final_line;
}

void game_generate(int num)
{
    FILE *fpQues1;
    FILE *fpBase1;
    char str[200];

    fpBase1 = fopen(SUDOKUPATH, "r");
    fpQues1 = fopen(QUESPATH, "w");

    char ques_board[10][18];
    ques_board[9][0] = '\n';
    ques_board[9][1] = '\0';

    while (num--)
    {
        str[0] = '\0';
        for (int i = 0; i < 9; i++)
        {
            fgets(ques_board[i], 20, fpBase1);
        }fgetc(fpBase1);

        //int base[9] = { 0,3,6,27,30,33,54,57,60 };
        int base[9] = { 0,6,12,54,60,66,108,114,120 };
        //int plus[9] = { 0,1,2,9,10,11,18,19,20 };
        int plus[9] = { 0,2,4,18,20,22,36,38,40 };

        for (int k = 0; k < 9; k++)//每个3*3随机掏空2个
        {

            int i, j,
                    hole[2];//3*3里面掏的位置
            hole[0] = rand() % 9;
            //hole[1] *= 2;
            hole[1] = rand() % 9;
            //hole[2] *= 2;
            while (hole[0] == hole[1])//防止重复
            {
                hole[1] = rand() % 9;
            }
            for (int t = 0; t < 2; t++)
            {
                int dot;
                dot = base[k] + plus[hole[t]];
                i = dot / 18;
                j = dot % 18;
                ques_board[i][j] = '0';
            }
        }

        //已经掏空了18个
        int others;
        others = 12 + rand() % 31;//再掏12-41个就可以了
        while (others--)
        {
            int k = rand() % 81;
            int i = k / 9;
            int j = k % 9;

            j *= 2;
            if (ques_board[i][j] != '0')ques_board[i][j] = '0';
            else others++;
        }

        for (int i = 0; i < 10; i++)
        {
            strcat(str, ques_board[i]);
        }if (!num) str[161] = '\0';

        fputs(str, fpQues1);
    }
    fclose(fpBase1);
    fclose(fpQues1);
}

void game_generate2(int num)
{
    fstream ques;
    fstream base;
    ques.open(QUESPATH,ios::app);
    base.open(SUDOKUPATH,ios::in);

    char str[163];

    char ques_board[9][18];
    // ques_board[9][0] = '\n';
    // ques_board[9][1] = '\0';

    while (num--)
    {
        strcpy(str,"");
        for (int i = 0; i < 9; i++)
        {
            // fgets(ques_board[i], 20, fpBase1);
            // base.getline(ques_board[i],sizeof(ques_board[i]));
            base.read(ques_board[i],sizeof(ques_board[i]));
        }

        //int base[9] = { 0,3,6,27,30,33,54,57,60 };
        int base[9] = { 0,6,12,54,60,66,108,114,120 };
        //int plus[9] = { 0,1,2,9,10,11,18,19,20 };
        int plus[9] = { 0,2,4,18,20,22,36,38,40 };

        for (int k = 0; k < 9; k++)//每个3*3随机掏空2个
        {
            int i, j, hole[2];//3*3里面掏的位置
            hole[0] = rand() % 9;
            hole[1] = rand() % 9;
            while (hole[0] == hole[1])//防止重复
            {
                hole[1] = rand() % 9;
            }
            for (int t = 0; t < 2; t++)
            {
                int dot;
                dot = base[k] + plus[hole[t]];
                i = dot / 18;
                j = dot % 18;
                ques_board[i][j] = '0';
            }
        }

        //已经掏空了18个
        // int others;
        // others = 12 + rand() % 31;//再掏12-41个就可以了
        // while (others--)
        // {
        // 	int k = rand() % 81;
        // 	int i = k / 9;
        // 	int j = k % 9;

        // 	j *= 2;
        // 	if (ques_board[i][j] != '0')ques_board[i][j] = '0';
        // 	else others++;
        // }

        for(int i=0;i<9;i++){
            strcat(str,ques_board[i]);
        }
        str[162]='\n';
        for(int i=0;i<sizeof(str);i++){
            cout<<str[i];
        }

        // ques.write(str,sizeof(str));
        cout<<"hello"<<endl;
    }
    ques.close();
    base.close();
}
