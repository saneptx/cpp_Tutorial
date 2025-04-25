#include<iostream>
using namespace std;

//递归的出口
void print(){
    cout << endl;
}
void print(int x){
    cout << x << endl;
}
//重新定义一个可变参数模板，至少得有一个参数
template <class T,class ...Args>
void print(T x, Args ...args)
{
    cout << x << " ";
    print(args...);
}
void test0(){
     //调用普通函数
    //不会调用函数模板，因为函数模板至少有一个参数
    print();
    print(2.3);
    print(1,"hello",3.6,true);
    print(1,"hello",3.6,true,100);
}
int main(){
    test0();
    return 0;
}