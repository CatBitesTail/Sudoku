#include <iostream>
#include <algorithm>
#include <fstream>
#include "create_final.h"
using namespace std;

void output_final(fstream &file, int *head, int *shift)
{
    for (int i = 0; i < 9; i++)
    {
        int j = shift[i];
        file << head[j % 9];
        for (j = j + 1; j < shift[i] + 9; j++)
        {
            file << head[j % 9];
        }
        file << endl;
    }
    file << endl;
}

void create_final(int n)
{
    printf("create_final_num: %d\n", n);

    fstream file;
    file.open("sudoku_final.txt", ios::out);
    if (!file.is_open())
    {
        fprintf(stderr, "ERROR: unable to open file: sudoku_final.txt!\n");
        exit(1);
    }

    // 第一行元素
    int head[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 每一行相对于第一行的移动
    int shift[9] = {0, 3, 6, 1, 4, 7, 2, 5, 8};

    while (true)
    {
        // 第4~6行交换 有3!种
        for (int i = 0; i < 6; i++)
        {
            // 第7~9行交换 有3!种
            for (int j = 0; j < 6; j++)
            {
                output_final(file, head, shift);
                if (--n <= 0)
                {
                    file.close();
                    printf("finish create_final\n");
                    return;
                }
                next_permutation(shift + 6, shift + 9);
            }
            next_permutation(shift + 3, shift + 6);
        }

        // head全排列 有9!种
        next_permutation(head, head + 9);
    }
}