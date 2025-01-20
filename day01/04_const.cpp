#include<iostream>
using namespace std;

int main(){
    int number1=3;
    int number2=4;


    int * const p1 = &number1;//指针常量，指向固定的地址可以改变存放地址中的值，不能指向别的地址
    *p1 = 30;
    //p1 = &number2;//不被允许

    const int * p2 = &number2;//常量指针，可以指向任意常量，但不能改变指向常量的值
    //*p2 = 40;//不被允许
    p2 = &number1;
}