#include<iostream>
using namespace std;

class Point{
public:
    Point(int _ix,int _iy):_ix(_ix),_iy(_iy){}
    operator int(){
        cout << "operator int()" << endl;
        return _ix + _iy;
    }
    friend ostream & operator<<(ostream & os,const Point &rhs);
private:
    int _ix;
    int _iy;
};
ostream & operator<<(ostream & os,const Point &rhs){
    os<<"("<<rhs._ix<<","<<rhs._iy<<")";
    return os;
}
class Complex{
public:
    Complex(int real,int image):real(real),image(image){}
    operator Point(){
        cout<<"operator Point()"<<endl;
        return Point(real,image);
    }
    friend ostream & operator<<(ostream & os,const Complex &rhs);
private:
    int real;
    int image;
};
ostream & operator<<(ostream & os,const Complex &rhs){
    os<<rhs.real<<" "<<rhs.image;
    return os;
}
int main(){
    Complex cx(1,2);
    Point pt = cx;
    cout<<pt<<endl;
    return 0;
}