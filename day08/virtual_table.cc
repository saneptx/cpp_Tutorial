#include<iostream>
using namespace std;

class A{
public:
    virtual void a(){ cout << "A::a()" << endl; }
    virtual void b(){ cout << "A::b()" << endl; }
    virtual void c(){ cout << "A::c()" << endl; }
};
class B{
public:
    virtual void a(){ cout << "B::a()" << endl; }
    virtual void b(){ cout << "B::b()" << endl; }
    void c(){ cout << "B::c()" << endl; }
    void d(){ cout << "B::d()" << endl; }
};
class C
: public A
, public B
{
public:
    virtual void a(){ cout << "C::a()" << endl; }
    void c(){ cout << "C::c()" << endl; }
    void d(){ cout << "C::d()" << endl; }
};
//先不看D类
class D
: public C
{
public:
    void c(){ cout << "D::c()" << endl; }
};

void test0(){
    C c;
    c.a(); //C::a()  隐藏
    //c.b(); //冲突
    c.c(); //C::c() 隐藏
    c.d(); //C::d() 隐藏
    cout << endl;
    A* pa = &c;
    pa->a(); //C::a() 覆盖
    pa->b(); //A::b()
    pa->c(); //C::c() 覆盖
    //pa->d(); //无法调用
    cout << endl;
    B* pb = &c;
    pb->a(); //C::a() 覆盖
    pb->b(); //B::b()
    pb->c(); //B::c() 不是虚函数调用
    pb->d(); //B::d() 同上
    cout << endl;
    C * pc = &c;
    pc->a(); //C::a() 隐藏
    //pc->b(); //冲突
    pc->c(); //C::c() 隐藏
    pc->d(); //C::d() 隐藏
}

int main(){
    test0();
    return 0;
}