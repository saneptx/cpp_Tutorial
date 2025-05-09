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
private:
    int x;
    int y;
};
ostream& operator<<(ostream& os,const Point& rhs){
    os<<"("<<rhs.x<<","<<rhs.y<<")";
    return os;
}

struct PointEqual{
    bool operator()(const Point &lhs, const Point &rhs) const {
        cout<<"struct PointEqual"<<endl;
        return ((lhs.getX()==rhs.getX()) && (lhs.getY()==rhs.getY()));
    }
};

struct PointHash{
    size_t operator()(const Point &rhs) const{//调用运算符重载
        cout<<"struct PointHash"<<endl;
        return ((rhs.getX() << 2)^(rhs.getY() << 2));
    }
};
void test0(){
    unordered_multiset<Point,PointHash,PointEqual> points = {
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