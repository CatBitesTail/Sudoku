#include "board.h"
#include <iostream>
#include <fstream>
using namespace std;

Board::Board() {
    for(auto & i : arr){
        for(int & j : i)
            j = 0;
    }
}


void Board::readBoard(string filename, int n) {
    int line = (n-1)*10;
    fstream file;
    file.open(filename, ios::in);

    if(!file.is_open())
    {
        cout<<"cannot open the file"<<endl;
    }

    // 将前(n-1)个board读出
    string temp;

    int k = 0;
    while( k < line && getline(file,temp)){
        k++;
    }

    for(auto & i : arr){
        getline(file, temp);
        for(int j = 0; j < 9; j++){
            i[j] = temp[j] - '0' ;
        }
    }

    file.close();

}

void Board::writeBoard(const string& filename) {
    fstream file;
    file.open(filename, ios::app);

    for(auto & i : arr){
        for(int j : i){
            file << j;
        }
        file<<std::endl;
    }
    file<<std::endl;

    file.close();
}

void Board::output() {
    for(auto & i : arr){
        for(int j : i){
            cout<< j;
        }
        cout<<endl;
    }
}



