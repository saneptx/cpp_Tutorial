#include<iostream>
using namespace std;

class Base{
public:
    Base(long x)
    : _base(x)
    {}
    virtual void display() const{
        cout << "Base::display()" << endl;
    }
private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base,long derived)
    : Base(base)//创建基类子对象
    , _derived(derived)
    {}
    virtual void display() const override{
        cout << "Derived::display()" << endl;
    }
private:
    long _derived;
};

void print(Base * pbase){
    pbase->display();
}

void test(){
    Base base(10);
    Derived derived(2,3);
    //用一个基类指针指向派生类对象
    //能够操纵的只有基类部分
    print(&base);
    print(&derived);
    cout << "sizeof(Base):" << sizeof(Base) << endl;
    cout << "sizeof(Derived):" << sizeof(Derived) << endl;
}
int main(){
    test();
    return 0;
}