#include<iostream>
using namespace std;

int main(){
    int a = 1;
    int & ref = a;
    //两个输出地址相同
    cout<<&a<<endl;
    cout<<&ref<<endl;
}