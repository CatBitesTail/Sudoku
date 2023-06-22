#include <iostream>
#include <unistd.h>
#include "create_final.h"
#include "create_game.h"
#include "solve_game.h"
using namespace std;

class OptClass{
public:
    bool c;
    bool s;
    bool n;
    bool m;
    bool r;
    bool u;

    int cArg;
    string sArg;
    int nArg;
    int mArg;
    int rArgMin;
    int rArgMax;

    OptClass():c(false), s(false), n(false), m(false), r(false), u(false), cArg(0), nArg(0), mArg(0), rArgMin(0), rArgMax(0){}
    bool checkOpt(){
        if(m|r|u){
            return n;
        }
        return true;
    }
};




int main(int argc, char *argv[])
{
    OptClass option;
    int opt = 0;
    int n = 0;
    int pos = 0;
    string s;

    // 1.将所有选项与参数存入到Option种
    while ((opt = getopt(argc, argv, "c:s:n:m:r:u")) != -1)
    {
        switch (opt)
        {
        // 生成数独终局：-c 100
        case 'c':
        {
            printf("option c: %s\n", optarg);
            n = atoi(optarg);
            if (n < 1 || n > 1000000)
            {
                printf("Parameters should range from 1 to 1000000\n");
                return 0;
            }
            option.c = true;
            option.cArg = n;
            create_final(atoi(optarg));
            break;
        }
        // 求解数独：-s game.txt
        case 's':
            printf("option s: %s\n", optarg);
            option.s = true;
            option.sArg = optarg;
            break;
        // 生成数独游戏：-n 100
        case 'n':
        {
            printf("option n: %s\n", optarg);
            n = atoi(optarg);
            if (n < 1 || n > 10000)
            {
                printf("Parameters should range from 1 to 10000\n");
                return 0;
            }
            option.n = true;
            option.nArg = n;
            break;
        }
        // 生成数独游戏的难度：-m 1
        case 'm':
            printf("option m: %s\n", optarg);
            n = atoi(optarg);
            if (n < 1 || n > 3)
            {
                printf("Parameters should range from 1 to 3\n");
                return 0;
            }
            option.m = true;
            option.mArg = n;
            break;
        // 生成数独游戏的挖空范围：-r 20~55
        case 'r':
            printf("option r: %s\n", optarg);
            s = optarg;
            pos = s.find("~");
            option.rArgMin = atoi(s.substr(0, pos).c_str());
            option.rArgMax = atoi(s.substr(pos+1, s.length()).c_str());

            if (option.rArgMin < 20 || option.rArgMax > 55 || option.rArgMin >= option.rArgMax)
            {
                printf("Parameters should range from 20 to 55\n");
                return 0;
            }
            option.r = true;
            break;
        // 生成游戏的解唯一
        case 'u':
            printf("option u\n");
            break;
        default:
            printf("the command is wrong!\n");
        }
    }

    // 2.根据Option判断输入参数组合是否正确，并执行对应函数。
    // m, r, u必须与n共同使用才可。
    if(!option.checkOpt()){
        cout<<"m, r, u必须与n共同使用才可。"<<endl;
        return 0;
    }

    if(option.c){
        create_final(option.cArg);
    }
    if(option.n){
        create_game(option.nArg, option.mArg, option.rArgMin, option.rArgMax, option.u);
    }
    if(option.s){
        solve(option.sArg);
    }



    return 0;
}