#include<iostream>
#include<memory>
using namespace std;
class Point{
public:
    Point(int x,int y):
    x(x),y(y){}
    ~Point(){}
private:
    int x;
    int y;
};
// void test0(){
//     //需要人为注意避免使用不同指针托管同一区域
//     Point * pt = new Point(1,2);
//     unique_ptr<Point> up(pt);
//     unique_ptr<Point> up2(pt);
// }
void test1(){
    
    unique_ptr<Point> up(new Point(1,2));
    unique_ptr<Point> up2(new Point(1,2));
    // up.reset(new Point(8,9));
    // up.reset(up2.get());
}
int main(){
    test1();
    return 0;
}