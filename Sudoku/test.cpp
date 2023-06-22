#include <iostream>
#include <string>
#include "board.h"


using namespace std;




int main(){
    Board b;
    b.readBoard("test.txt",3);
    b.output();





    return 0;
}