#include<iostream>
using namespace std;

class FunctionObject{
public:
    void operator()(){
        cout<<"void operator()()"<<endl;
        ++count;
    }
    int operator()(int x,int y){
        cout<<"int operator()(int x,int y)"<<endl;
        ++count;
        return x+y;
    }
    int count = 0;//记录被调用的次数
};
class MyClass {
public:
    void display(int x) {
        std::cout << "x = " << x << std::endl;
    }
};
int main(){
    // void (MyClass::*funcPtr)(int);  //声明一个指向MyClass类的成员函数指针
    // funcPtr = &MyClass::display;    //赋值
    // MyClass obj;
    // (obj.*funcPtr)(20);//调用函数
    // MyClass *pobj;
    // (pobj->*funcPtr)(100);
    return 0;
}