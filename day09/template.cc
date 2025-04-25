#include<iostream>
#include<string.h>
using namespace std;

class Point{
public:
    Point(double x,double y)
    :_x(x)
    ,_y(y)
    {}
    template<class T = int>
    T convert()
    {
        return (T)_x;
    }
    template<class T>
    T add(T t);
private:
    double _x;
    double _y;
};
template<class T>
T Point::add(T t){
    return _x + _y + t;
}
void test0(){
    Point pt(1.1,2.2);
    cout<<pt.convert()<<endl;
    cout<<pt.add(2)<<endl;
}
int main(){
    test0();
    return 0;
}