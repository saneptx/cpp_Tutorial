#include<iostream>
#include<string>
#include<math.h>
#include<functional>
#define PI 3.14
using namespace std;

class Figure{
public:
    using getNameCallBack = function<string()>;
    using getAreaCallBack = function<double()>;

    getNameCallBack _getNameCallBack;
    getAreaCallBack _getAreaCallBack;

    void setGetNameCallBack(getNameCallBack &&cb){
        _getNameCallBack = std::move(cb);
    }
    void setGetAreaCallBack(getAreaCallBack &&cb){
        _getAreaCallBack = std::move(cb);
    }

    string handleGetNameCallBack() const{
        if(_getNameCallBack){
            return _getNameCallBack();
        }else{
            return "";
        }
    }
    double handleGetAreaCallBack() const{
        if(_getAreaCallBack){
            return _getAreaCallBack();
        }else{
            return 0.0;
        }
    }
};
class Rectangle//矩形
{
public:
    Rectangle(double len,double wid)
    : _length(len)
    , _width(wid){}
    string getName() const
    {
        return "矩形";
    }
    double getArea() const
    {
        return _length * _width;
    }
private:
    double _length;
    double _width;
};
class Circle
{
public:
    Circle(double r)
    : _radius(r){}
    string getName() const
    {
        return "圆形";
    }
    double getArea() const
    {
        return PI * _radius * _radius;
    }
private:
    double _radius;
};
class Triangle
{
public:
    Triangle(double a,double b,double c)
    : _a(a)
    , _b(b)
    , _c(c)
    {}
    string getName() const
    {
        return "三角形";
    }
    double getArea() const
    {
        double p = (_a + _b + _c)/2;
        return sqrt(p * (p-_a) * (p- _b)* (p- _c));
    }
private:
    double _a,_b,_c;
};

void test(){
    Rectangle rectangle(5,10);
    Circle circle(5);
    Triangle triangle(3,4,5);

    Figure figure;
    figure.setGetNameCallBack(bind(&Rectangle::getName,&rectangle));
    cout<<figure.handleGetNameCallBack()<<endl;
    figure.setGetAreaCallBack(bind(&Rectangle::getArea,&rectangle));
    cout<<figure.handleGetAreaCallBack()<<endl;

    figure.setGetNameCallBack(bind(&Circle::getName,&circle));
    cout<<figure.handleGetNameCallBack()<<endl;
    figure.setGetAreaCallBack(bind(&Circle::getArea,&circle));
    cout<<figure.handleGetAreaCallBack()<<endl;

    figure.setGetNameCallBack(bind(&Triangle::getName,&triangle));
    cout<<figure.handleGetNameCallBack()<<endl;
    figure.setGetAreaCallBack(bind(&Triangle::getArea,&triangle));
    cout<<figure.handleGetAreaCallBack()<<endl;
}
int main(){
    test();
    return 0;
}