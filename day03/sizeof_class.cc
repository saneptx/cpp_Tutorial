#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

class A{
    int num;
    double price;
};
class B{
    int num;
    int price;
};
class C{
    int num1;
    int num2;
    double price;
};
class D{
    int num1;
    double price;
    int num2;
};
class E{
    double num1;
    char Arr[20];
    double num2;
    int num3;
};
class F{
    char _gArr[20];
    int _g1;
    double _g2;
};
int main(){
    cout<<"sizeof(A)="<<sizeof(A)<<endl;
    cout<<"sizeof(B)="<<sizeof(B)<<endl;
    cout<<"sizeof(C)="<<sizeof(C)<<endl;
    cout<<"sizeof(D)="<<sizeof(D)<<endl;
    cout<<"sizeof(E)="<<sizeof(E)<<endl;
    cout<<"sizeof(F)="<<sizeof(F)<<endl;
    return 0;
}