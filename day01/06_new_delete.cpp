#include<iostream>
using namespace std;

int main(){
    int *pa = new int();//默认初始化为0
    cout<<*pa<<endl;
    int *pb = new int(3);//初始化为3
    cout<<*pb<<endl;
    int *pc = new int[5]();//默认初始化数组全为0
    for(int i=0;i<5;i++){
        cout<<pc[i]<<" ";
    }
    cout<<endl;
    int *pd = new int[5]{1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<pd[i]<<" ";
    }
    cout<<endl;
    delete pa;
    delete pb;
    delete []pc;
    delete []pd;
    pa = nullptr;//安全回收
}