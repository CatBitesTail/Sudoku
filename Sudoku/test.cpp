#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include "board.h"
#include "solve_game.h"

using namespace std;

int main(){

//    string filename = "sudoku_game.txt";
//    solve(filename);


//    string s = "20~55";
//    int pos = s.find("~");
//    string min = s.substr(0, pos);
//    string max = s.substr(pos+1, s.length());
//    cout<<min<<endl;
//    cout<<max<<endl;

//    char* s = (char*)"20~55";
//    char* s1 = strtok(s, "~");
//    cout<<s1<<endl;

    Board b;
    for(int i=0;i<100;i++){
        b.readBoard("sudoku_game.txt", i+1);
        cout<<onlyResult(b)<<endl;
    }



    return 0;
}