#include<iostream>
using namespace std;

class Base {
public:
    Base(long _base):_base(_base){ cout << "Base(long)" << endl; }
    ~Base(){cout << "~Base()" << endl;}
    void print() const{
        cout << "Base::_base:" << _base << endl;
        cout << "Base::_data:" << _data << endl;
    }
    long _data = 100;
private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base,long derived):Base(base),_derived(derived){ cout << "Derived(long)" << endl; }
    ~Derived(){cout<<"~Derived()"<<endl;}
    void print() const{
        cout << "Derived::_derived:" << _derived << endl;
        cout << "Derived::_data:" << _data << endl;
    }
    long _data = 10;
private:
    long _derived;
};

void test() {
    Derived d(123,456);
    d.print();
}

int main(){
    test();
    return 0;
}