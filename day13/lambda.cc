#include<iostream>
#include<string>
using namespace std;
void test(){
    int a = 100;
    //匿名函数写法
    //[]捕获列表，默认是值传递不可修改
    //()函数参数列表
    //{}函数体
    //->返回类型，如果是void可以不写
    [a]()mutable->void{//mutable关键字修饰变量可以修改
        cout<<"a = "<<a<<endl;
        cout<<"hello"<<endl;
        a++;
    }();//后加加上括号就代表调用匿名函数
    cout<<"a = "<<a<<endl;

    [&a](){//引用捕获可以修改值
        cout<<"a = "<<a<<endl;
        cout<<"hello"<<endl;
        a++;
    }();//后加加上括号就代表调用匿名函数
    cout<<"a = "<<a<<endl;
}
void test2(){
    //第一种调用方法
    [](const string &name){
        cout<<"test2"<<endl;
        cout<<name<<endl;
    }("wangdao");
    //第二种调用方法
    auto f = [](const string &name){
        cout<<"test2"<<endl;
        cout<<name<<endl;
    };
    f("test");
    cout<<endl;
}

void test3(){

    int num = 10;
    string name("wangdao");

    //值传递
    [num,name](const string &value) {
        cout<<"num = "<<num<<endl;
        cout<<"name = "<<name<<endl;
        cout<<"value = "<<value<<endl;
    }("hello");

    
    cout<<endl<<endl;
    [&num,&name](const string &value) {
        ++num;
        name = "hello";
        cout<<"num = "<<num<<endl;
        cout<<"name = "<<name<<endl;
        cout<<"value = "<<value<<endl;
    }("hello");
}
int main(){
    test3();
    return 0;
}