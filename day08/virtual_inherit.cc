#include<iostream>
using namespace std;

class A{
    int _ia;
    char _ca;
public:
    virtual void f(){
        cout<<"A::f()"<<endl;
    }
    virtual void Af(){
        cout<<"A::Af()"<<endl;
    }
};
class B:virtual public A{
    int _ib;
    char _cb;
public:
    virtual void f(){
        cout<<"B::f()"<<endl;
    }
    virtual void f1(){
        cout<<"B:f1()"<<endl;
    }
    virtual void Bf(){
        cout<<"B::Bf()"<<endl;
    }
};
class C:virtual public A{
    int _ic;
    char _cc;
public:
    virtual void f(){
        cout<<"C::f()"<<endl;
    }
    virtual void f2(){
        cout<<"C:f2()"<<endl;
    }
    virtual void Cf(){
        cout<<"C::Cf()"<<endl;
    }
};
class D
:public B
,public C{
    int _id;
    char _cd;
public:
    virtual void f(){
        cout<<"D::f()"<<endl;
    }
    virtual void f1(){
        cout<<"D:f1()"<<endl;
    }
    virtual void f2(){
        cout<<"D:f2()"<<endl;
    }
    virtual void Df(){
        cout<<"D::Df()"<<endl;
    }
};
int main(){
    D d;
    // A *pa = &d;
    std::cout << "D*  : " << &d << std::endl;
    std::cout << "B*  : " << static_cast<B*>(&d) << std::endl;
    std::cout << "C*  : " << static_cast<C*>(&d) << std::endl;
    std::cout << "A*  : " << static_cast<A*>(&d) << std::endl;
    return 0;
}