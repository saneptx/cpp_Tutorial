#include<iostream>
using namespace std;
class Line{
public:
    class Point{
    public:
        Point(int x,int y):x(x),y(y){}
        friend ostream & operator<<(ostream & os,const Point & rhs){
            os<<"("<<rhs.x<<","<<rhs.y<<")";
            return os;
        }
    private:
        int x;
        int y;
    };
public:
    Line(int x1,int y1,int x2,int y2):pt1(x1,y1),pt2(x2,y2){}
private:
    Point pt1;
    Point pt2;
    int num = 0;
};

int main(){
    Line::Point pt(1,3);
    cout<<pt<<endl;
    return 0;
}