#include<iostream>
#include<memory>
#include<vector>
using namespace std;

class Point{
public:
    Point(){};
    Point(int x,int y)
    :x(x)
    ,y(y){
        cout<<"Point(int x,int y)"<<endl;
    }
    ~Point(){};
    void print(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
public:
    int x;
    int y;


};

void test0(){
    vector<unique_ptr<Point>> vec;
    unique_ptr<Point> up4(new Point(10,20));
    vec.push_back(up4);  //error
    vec.push_back(std::move(up4));  //ok
    vec.push_back(unique_ptr<Point>(new Point(1,3))); //ok
}
int main(){

    return 0;
}