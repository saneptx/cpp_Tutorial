#include<iostream>
#include<map>
using namespace std;

template<typename Container>
void display(const Container &con){
    for(const auto &elem:con){
        cout<<"["<<elem.first<<","<<elem.second<<"] ";
    }
    cout<<endl;
}

int main(){
    multimap<string,int> m = {
        {"hello",1},
        {"world",2},
        {"c++",3},
        {"c",4}
    };
    display(m);

    //multimap的查找操作
    cout<<m.count("hello")<<endl;//按key值查找map中有没有key值为hello的元素，如果有返回1否则返回0
    cout<<m.count("java")<<endl;

    auto ret = m.find("hello");
    if(ret!=m.end()){
        cout<<"map中存在元素:["<<ret->first<<","<<ret->second<<"]"<<endl;
    }else{
        cout<<"map中不存在该元素"<<endl;
    }

    //multimap的插入操作,由于key值可以重复所以不会插入失败
    ret = m.insert({"java",5});
    display(m);

    return 0;
}