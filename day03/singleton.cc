#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

// class Point{
// public:
//     static Point* getInstance(){//返回值设为引用避免复制
//         static Point *pt = new Point(1,2);
//         return pt;
//     }
//     void print() const{
//         cout<<"x="<<_ix<<",y="<<_iy<<endl;
//     }
//     static void destroy(Point *pt){
//         delete pt;
//         pt = nullptr;
//         cout<<"call distory!"<<endl;
//     }
// private:
//     Point(int x,int y)://构造函数私有
//     _ix(x),_iy(y){
//         _ix = x;
//         _iy = y;
//     }
//     Point(const Point &rhs)
//     :_ix(rhs._ix)
//     ,_iy(rhs._iy){
//         cout<<"call copy function!"<<endl;
//     }
//     int _ix=0;
//     int _iy=0;
// };

// int main(){
//     Point *pt1 = Point::getInstance();
//     pt1->print();
//     Point *pt2 = Point::getInstance();
//     pt2->print();
//     cout<<pt1<<endl;
//     cout<<pt2<<endl;//从输出可以看出，pt1和pt2绑定的是同一个对象
//     Point::destroy(pt1);
//     return 0;
// }

class Point{
public:
    static Point* getInstance(){//返回值设为指针
        if(_pInstance == nullptr){
            _pInstance = new Point(1,2);
        }
        return _pInstance;
    }
    void print() const{
        cout<<"x="<<_ix<<",y="<<_iy<<endl;
    }
    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
private:
    Point(int x,int y)://构造函数私有
    _ix(x),_iy(y){
        _ix = x;
        _iy = y;
    }
    int _ix=0;
    int _iy=0;
    static Point *_pInstance;
};
Point* Point::_pInstance = nullptr;
int main(){
    Point *pt1 = Point::getInstance();
    pt1->print();
    Point *pt2 = Point::getInstance();
    pt2->print();
    cout<<pt1<<endl;
    cout<<pt2<<endl;//从输出可以看出，pt1和pt2绑定的是同一个对象
    return 0;
}