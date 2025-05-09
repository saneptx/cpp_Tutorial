#include<iostream>
#include<set>
#include<math.h>
using namespace std;

template<typename Container>
void display(const Container &con){
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
    friend struct ComparePoint;
private:
    int x;
    int y;
};
ostream& operator<<(ostream& os,const Point& rhs){
    os<<"("<<rhs.x<<","<<rhs.y<<")";
    return os;
}
bool operator<(const Point &lhs,const Point &rhs){//比较运算符重载
    cout<<"operator"<<endl;
    if(lhs.getDistance()<rhs.getDistance()){
        return true;
    }else if(lhs.getDistance() == rhs.getDistance()){
        if(lhs.x<rhs.x){
            return true;
        }else if(lhs.x == rhs.x){
            if(lhs.y<rhs.y){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

struct ComparePoint{
    bool operator()(const Point &lhs,const Point &rhs) const{
        cout<<"comparePoint struct"<<endl;
        if(lhs.getDistance()<rhs.getDistance()){
            return true;
        }else if(lhs.getDistance() == rhs.getDistance()){
            if(lhs.x<rhs.x){
                return true;
            }else if(lhs.x == rhs.x){
                if(lhs.y<rhs.y){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
};

//命名空间的扩展
template<>//模板特化
struct std::less<Point>{
    bool operator()(const Point &lhs,const Point &rhs) const{
        cout<<"template<>"<<endl;
        if(lhs.getDistance()<rhs.getDistance()){
            return true;
        }else if(lhs.getDistance() == rhs.getDistance()){
            if(lhs.getX()<rhs.getX()){
                return true;
            }else if(lhs.getX() == rhs.getX()){
                if(lhs.getY()<rhs.getY()){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
};


void test0(){
    set<Point> points = {
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