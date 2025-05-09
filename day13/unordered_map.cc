#include<iostream>
#include<map>
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
    unordered_map<string,Point> m = {
        {"hello",Point(1,2)},
        {"world",Point(2,3)},
        {"c++",Point(-1,-2)},
        {"c",Point(1,3)}
    };
    display(m);

    //map的查找操作
    // cout<<m.count("hello")<<endl;//按key值查找map中有没有key值为hello的元素，如果有返回1否则返回0
    // cout<<m.count("java")<<endl;

    // auto ret = m.find("hello");
    // if(ret!=m.end()){
    //     cout<<"map中存在元素:["<<ret->first<<","<<ret->second<<"]"<<endl;
    // }else{
    //     cout<<"map中不存在该元素"<<endl;
    // }

    //map的插入操作
    // pair<unordered_map<string,int>::iterator,bool> ret2 = m.insert({"java",5});
    // if(ret2.second){
    //     cout<<"插入成功"<<"["<<ret2.first->first<<","<<ret2.first->second<<"]"<<endl;
    // }else{
    //     cout<<"插入失败"<<endl;
    // }

    //map的下标
    // cout<<"[hello"<<","<<m["hello"]<<"]"<<endl;//map可以通过下标访问，下标为key值
    // m["python"] = 6;//也可以通过下标插入
    // m["c++"]=10;//也可以通过下标修改
    // display(m);
    return 0;
}