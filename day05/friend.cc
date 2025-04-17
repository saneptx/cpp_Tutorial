#include<iostream>
#include<math.h>
using namespace std;

class Point;
class Line{
public:
    //友元的成员函数形式
    float distance(const Point & lhs,const Point & rhs);
};
class Point{
public:
    Point(int x,int y)
    :_ix(x)
    ,_iy(y){}
    friend class Line;
private:
    int _ix;
    int _iy;
};

float Line::distance(const Point & lhs,const Point & rhs){
    return sqrt(pow((lhs._ix- rhs._ix),2) + pow((lhs._iy- rhs._iy),2));
}
int main(){
    Point pt1(1,2);
    Point pt2(2,3);
    Line line;
    cout<<line.distance(pt1,pt2)<<endl;
    return 0;
}