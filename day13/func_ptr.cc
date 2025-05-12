#include<iostream>
#include<functional>
using namespace std;

int func2(int x,int y){
    return x+y;
}

int func3(int x,int y){
    return x*y;
}

int func4(){
    return 400;
}
//函数指针
typedef int (*pFunc)(int,int);

void test(){
    //延迟调用函数
    pFunc f = &func2;//注册回调函数
    /*
    执行其他代码
     */
    cout<<"f()="<<f(1,2)<<endl;//回调函数执行

    f = func3;
    cout<<"f()="<<f(10,20)<<endl;

    
}
int main(){
    test();
    return 0;
}