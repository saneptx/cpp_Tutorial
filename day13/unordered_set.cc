#include<iostream>
#include<unordered_set>
#include<math.h>
using namespace std;

template <typename Container>
void display(const Container con){
    for(auto &elem:con){
        cout<<elem<<" ";
    }
    cout<<endl;
}
class Point{
public:
    Point(int x, int y)
    :x(x)
    ,y(y){};
    ~Point()=default;
    float getDistance() const{
        return hypot(x,y);
    }
    int getX() const{
        return x;
    }
    int getY() const{
        return y;
    }
    friend ostream &operator<<(ostream &os,const Point &rhs);
    friend bool operator<(const Point &lhs,const Point &rhs);
    friend bool operator==(const Point &lhs,const Point &rhs);
private:
    int x;
    int y;
};
ostream& operator<<(ostream& os,const Point& rhs){
    os<<"("<<rhs.x<<","<<rhs.y<<")";
    return os;
}
bool operator==(const Point &lhs,const Point &rhs){//==运算符重载处理unordered_set中元素重复
    cout<<"bool operator=="<<endl;
    return ((lhs.getX()==rhs.getX())
            &&(lhs.getY()==rhs.getY()));
}
namespace std{
    template<>
    struct hash<Point>{//自定义hash函数
        size_t operator()(const Point &rhs) const{//调用运算符重载
            cout<<"template<>"<<endl;
            return ((rhs.getX() << 2)^(rhs.getY() << 2));
        }
    };
}
void test0(){
    unordered_set<Point> points = {
    // set<Point,ComparePoint> points = {
        Point(1,2),
        Point(-1,2),
        Point(1,2),
        Point(3,2),
        Point(1,-2),
        Point(4,2),
    };
    display(points);
}
int main(){
    test0();

    return 0;
}