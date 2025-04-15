#include<iostream>
using std::cout;
using std::endl;

void test0(){
    bool b1 = 0;
    bool b2 = 1;
    bool b3 = 2;
    bool b4 = true;
    bool b5 = false;
    bool b6 = -1;
    cout<<"sizeof(bool)"<<sizeof(bool)<<endl;
    cout<<"b1:"<<b1<<endl;//0
    cout<<"b2:"<<b2<<endl;//1
    cout<<"b3:"<<b3<<endl;//1
    cout<<"b4:"<<b4<<endl;//1
    cout<<"b5:"<<b5<<endl;//0
    cout<<"b6:"<<b6<<endl;//1
}

int main(){
    test0();
    return 0;
}