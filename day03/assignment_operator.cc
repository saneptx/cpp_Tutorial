#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

class Point{
public:
    Point(){};//默认构造函数可重载
    Point(int x,int y):
    _ix(x),_iy(y){
        _ix = x;
        _iy = y;
    }
    void print(){
        cout<<"x="<<_ix<<",y="<<_iy<<endl;
    }
    Point & operator=(const Point & rhs){
        this->_ix = rhs._ix;
        this->_iy = rhs._iy;
        cout<<"Call this function!"<<endl;
        return *this;
    }
private:
    int _ix=0;
    int _iy=0;
};
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
   Computer& operator=(const Computer &rhs){
        if(this!=&rhs){
            delete []this->_brand;
            this->_brand = new char[strlen(rhs._brand)+1]();
            strcpy(this->_brand,rhs._brand);
            this->_price = rhs._price;
        }
        return *this;
   }
   void print();
private:
   char * _brand;
   float _price;
};
void Computer::print(){
    cout<<_brand<<" "<<_price<<endl;
}

int main(){
    // Point point1(1,2),point2(3,4);
    // point1.print();
    // point1 = point2;
    // point1.print();
    // point2.print();
    Computer pc1("Apple",15000),pc2("huawei",8000);
    pc1.print();
    pc1 = pc2;
    pc1.print();
    pc2.print();
    return 0;
}