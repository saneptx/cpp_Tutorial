#include<fstream>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;


int main(){
    ifstream ifs = ifstream("test.txt");
    string line;
    while(getline(ifs,line)){
        cout<<line<<endl;
    }
    ifs.close();
    return 0;
}