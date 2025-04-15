#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

class Point{
public:
    Point(){};
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
    Point point1(2,3);
    Point point2 = point1;
    point1.print();
    point2.print();
    return 0;
}