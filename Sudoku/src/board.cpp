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
    cout<<"test"<<endl;

    // 将前(n-1)*
    string temp;

    int k = 1;
    while(getline(file,temp) && k < line){
        k++;
    }

    for(int i = 0; i < 9;i++){
        getline(file, temp);
        for(int j = 0; j < 9; j++){
            arr[i][j] = temp[j] - '0' ;
        }
    }

}

void Board::writeBoard(string filename) {
    fstream file;
    file.open(filename, ios::out);

    for(auto & i : arr){
        for(int j : i){
            file << j;
        }
        file<<std::endl;
    }
    file<<std::endl;
}

void Board::output() {
    for(auto & i : arr){
        for(int j : i){
            cout<< j;
        }
        cout<<endl;
    }
}



