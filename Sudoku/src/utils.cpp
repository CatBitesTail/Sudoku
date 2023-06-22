#include <fstream>
#include <string>
using namespace std;

int countLines(const string& filename)
{
    ifstream ReadFile;
    int n = 0;
    string tmp;
    ReadFile.open(filename.c_str());//ios::in 表示以只读的方式读取文件
    if(ReadFile.fail()){
        return 0;
    }
    else{
        while(getline(ReadFile,tmp,'\n')){
            n++;
        }
        ReadFile.close();
        return n;
    }
}
