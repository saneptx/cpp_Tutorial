#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

class Computer {
public:
   Computer(const char * brand,int price)
   :_brand(new char[strlen(brand) + 1]())
   ,_price(price){
        strcpy(_brand,brand);
   }
   Computer(const Computer & rhs)//手动定义拷贝构造函数
   :_brand(new char[strlen(rhs._brand)+1]())
   ,_price(rhs._price){
        strcpy(_brand,rhs._brand);
   }
   ~Computer(){
        if(_brand){
            delete[] _brand;
            _brand = nullptr;
            cout<<"~Computer()"<<endl;
        }
   }
   void print();
   static void printTotalPrice(){
        cout<<"total Price:"<<_totalPrice<<endl;
        //cout<<_price<<endl;//error
   }
private:
   char * _brand;
   float _price;
   static double _totalPrice;
};
double Computer::_totalPrice = 30000;  // 静态成员变量初始化

void Computer::print(){
    cout<<_brand<<" "<<_price<<endl;
}

int main(){
    Computer *cp = new Computer("Apple",15000);
    cp->print();
    return 0;
}