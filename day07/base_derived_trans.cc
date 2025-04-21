#include<iostream>
using namespace std;

class Base {
public:
    Base(){ cout << "Base()" << endl; }
    ~Base(){cout << "~Base()" << endl;}
};

class Derived
: public Base
{
public:
    Derived(){ cout << "Derived()" << endl; }
    ~Derived(){cout<<"~Derived()"<<endl;}
};

void test() {
    Base base;
    Derived dl;
    base = dl;
    //dl = base;//ERROR

    Base * pbase = &dl;
    //Derived *pderived = &base;//ERROR

    Base & rbase = dl;
    //Derived & rderived = base;//ERROR
}

int main(){
    test();
    return 0;
}