#include<iostream>
using namespace std;

class A{
public:
    void print() const{cout<<"A::print()"<<endl;}
    double _a;
};

class B
:virtual public A{
public:
    double _b;
};

class C
:virtual public A{
public:
    double _c;
};

class D
:public B
,public C{
public:
    double _d;
};

void test() {
    D d;
    d.print();
}

int main(){
    test();
    return 0;
}