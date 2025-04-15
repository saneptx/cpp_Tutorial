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
private:
    int _ix=0;
    int _iy=0;
};

int main(){
    Point point1;
    Point point2(2,3);
    point1.print();//x=0,y=0
    point2.print();//x=2,y=3
    return 0;
}