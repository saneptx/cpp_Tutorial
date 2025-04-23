#include<iostream>
#include<string.h>
using namespace std;

class Base{
public:
    Base(long base,const char * _str)
    : _base(base)
    , _str(new char[strlen(_str)+1]()){
        strcpy(this->_str,_str);
        cout<<"Base(long base,const char * _str)"<<endl;
    }
    Base(Base & rhs)
    :_base(rhs._base)
    ,_str(new char[strlen(rhs._str)+1]()){
        strcpy(this->_str,rhs._str);
        cout<<"Base(Base & rhs)"<<endl;
    }
    ~Base(){
        if(_str){
            delete[] _str;
            _str = nullptr;
            cout<<"~Base()"<<endl;
        }
    }
    Base &operator=(const Base & rhs){
        _base = rhs._base;
        _str = new char[strlen(rhs._str)+1]();
        strcpy(_str,rhs._str);
        return *this;
    }
private:
    long _base = 10;
    char * _str;
};

class Derived
: public Base
{
public:
    Derived(long base, long derived, const char *_str)
    :Base(base,_str)
    ,_derived(derived)
    {
        cout << "Derived(long base, long derived)" << endl;
    }
    Derived(Derived & rhs)
    :Base(rhs)
    ,_derived(rhs._derived){
        cout<<"Derived(Derived & rhs)"<<endl;
    }
    Derived &operator=(const Derived & rhs){
        Base::operator=(rhs);
        _derived = rhs._derived;
        return *this;
    }
    ~Derived(){cout<<"~Derived()"<<endl;}
private:
    long _derived = 12;
};
int main(){
    Derived d1(123,456,"hello");
    Derived d2(d1);
    Derived d3 = d1;
    return 0;
}