#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;

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
    // cout<<"operator"<<endl;
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
        // cout<<"comparePoint struct"<<endl;
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
#if 0
//命名空间的扩展
template<>//模板特化
struct std::less<Point>{
    bool operator()(const Point &lhs,const Point &rhs) const{
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
#endif
void test(){
    vector<Point> vec = {
        Point(1,2),
        Point(-1,2),
        Point(1,-2),
        Point(1,2),
        Point(2,3),
        Point(3,4),
        Point(1,3),
    };
    // priority_queue<int> pque(vec.begin(),vec.end());
    // priority_queue<Point,vector<Point>,ComparePoint> pque;
    priority_queue<Point> pque;
    for(size_t idx = 0;idx != vec.size();++idx){
        pque.push(vec[idx]);
        cout<<"优先级最高的元素 "<<pque.top()<<endl;
    }
    while(!pque.empty()){
        cout<<pque.top()<<" ";
        pque.pop();
    }
    cout<<endl;
}
int main(){
    test();
    return 0;
}