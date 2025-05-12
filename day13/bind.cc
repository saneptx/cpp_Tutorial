#include<iostream>
#include<functional>
using namespace std;

int add(int x,int y){
    cout<<"int add (int,int)"<<endl;
    return x + y;
}
int multiply(int x,int y,int z){
    cout<<"int multiply (int,int,int)"<<endl;
    return x * y * z;
}
class Example{
public:
    int add(int x,int y){
        cout<<"int Example::add(int,int)"<<endl;
        return x + y;
    }
    int data = 250;//c++11
};
void test(){
    //add函数返回值类型是int,参数是int,int
    //函数类型 int(int,int)
    //f的形态 int();
    // auto f =bind(add,1,2);
    function<int()> f=bind(add,1,2);
    cout<<"f()="<<f()<<endl;

    //函数类型 int(int,int,int)
    //f2的形态 int()
    // auto f2 = bind(multiply,3,4,5);
    f = bind(multiply,3,4,5);
    // cout<<"f2()="<<f2()<<endl;
    cout<<"f()="<<f()<<endl;

    Example ex;
    //函数类型int(int,int)
    //f3的形态 int()
    // auto f3 = bind(&Example::add,&ex,10,30);//绑定成员函数
    f = bind(&Example::add,&ex,10,30);//绑定成员函数
    // cout<<"f3()="<<f3()<<endl;
    cout<<"f()="<<f()<<endl;

    //f4的形态 int(int);
    using namespace std::placeholders;
    // auto f4 = bind(add,10,_1);//占位符
    function<int(int)> f4 = bind(add,10,_1);//占位符
    cout<<"f4(20)="<<f4(30)<<endl;

    function<int()> f5 = bind(&Example::data,&ex);//bind绑定数据成员
    cout<<"f5()="<<f5()<<endl;
}
void test2(){
    Example ex;
    function<int()> f = bind(&Example::add,&ex,10,30);//引用传递
    cout<<"f()="<<f()<<endl;

    function<int()> f = bind(&Example::add,ex,10,30);//值传递
    cout<<"f()="<<f()<<endl;
}
int main(){
    test();
    return 0;
}