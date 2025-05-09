#include<iostream>
#include<unordered_map>
#include<math.h>
using namespace std;

template<typename Container>
void display(const Container &con){
    for(const auto &elem:con){
        cout<<"["<<elem.first<<","<<elem.second<<"] ";
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


int main(){
    unordered_multimap<string,Point> m = {
        {"hello",Point(1,2)},
        {"world",Point(2,3)},
        {"c++",Point(-1,-2)},
        {"c",Point(1,3)}
    };
    display(m);

    return 0;
}