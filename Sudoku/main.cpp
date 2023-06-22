#include <iostream>
#include <unistd.h>
#include "create_final.h"
#include "create_game.h"

using namespace std;

int main(int argc, char *argv[])
{
    int opt = 0;
    while ((opt = getopt(argc, argv, "c:s:n:m:r:u")) != -1)
    {
        switch (opt)
        {
        // 生成数独终局：-c 100
        case 'c':
        {
            printf("option c: %s\n", optarg);
            int n = atoi(optarg);
            if (n < 1 || n > 1000000)
            {
                printf("Parameters should range from 1 to 1000000\n");
                return 0;
            }
            create_final(atoi(optarg));
            break;
        }
        // 求解数独：-s game.txt
        case 's':
            printf("option s: %s\n", optarg);
            break;
        // 生成数独游戏：-n 100
        case 'n':
        {
            printf("option n: %s\n", optarg);
            int n = atoi(optarg);
            if (n < 1 || n > 10000)
            {
                printf("Parameters should range from 1 to 1000000\n");
                return 0;
            }
             create_game(atoi(optarg));
            break;
        }
        // 生成数独游戏的难度：-m 1
        case 'm':
            printf("option m: %s\n", optarg);
            break;
        // 生成数独游戏的挖空范围：-r 10~20
        case 'r':
            printf("option r: %s\n", optarg);
            break;
        // 生成游戏的解唯一
        case 'u':
            printf("option u\n");
            break;
        default:
            printf("the command is wrong!\n");
        }
    }
    return 0;
}