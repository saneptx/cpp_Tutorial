#include<iostream>
#include<functional>
#include<vector>
using namespace std;

vector<function<void(const string &)>> vec;

void test(){
    int num = 10;
    string name("wangdao");
    vec.push_back([num,name](const string &value){
        cout<<"num = "<<num<<endl;
        cout<<"name = "<<name<<endl;
        cout<<"value = "<<value<<endl;
    });
}
void test2(){
    for(auto f:vec){
        f("hello");
    }
}
int main(){
    test();
    test2();
    return 0;
}