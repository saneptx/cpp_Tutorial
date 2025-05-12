#include<iostream>
#include<functional>
using namespace std;

void func(int x1,int x2,int x3,int &x4,int x5){
    cout<<"x1 = "<<x1<<endl;
    cout<<"x2 = "<<x2<<endl;
    cout<<"x3 = "<<x3<<endl;
    cout<<"x4 = "<<x4<<endl;
    cout<<"x5 = "<<x5<<endl;
}
void test(){
    int number = 100;
    using namespace std::placeholders;
    //占位符本身代表的函数形参的位置，占位符中的数字代表实参的位置
    //bind默认采用值传递
    //std::ref = reference引用包装器
    //std::cref = const reference引用包装器
    auto f = bind(func,10,_1,_3,std::ref(number),number);
    number = 200;
    f(20,30,40);
}
int main(){
    test();
    return 0;
}