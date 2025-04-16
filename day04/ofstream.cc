#include<fstream>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;


int main(){
    ofstream ofs = ofstream("test.txt",std::ios::app);//追加方式写入
    string line = "nihao";
    ofs<<line;
    ofs.close();
    return 0;
}