#include<iostream>
using namespace std;

int main(){
    int *pa = new int[5]();
    cout<<pa[3]<<endl;
    delete pa;
    pa = nullptr;//安全回收
}