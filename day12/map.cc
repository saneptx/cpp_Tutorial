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
    map<string,int> m = {
        {"hello",1},
        {"world",2},
        {"c++",3},
        {"c",4}
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
    // pair<map<string,int>::iterator,bool> ret = m.insert({"java",5});
    // if(ret.second){
    //     cout<<"插入成功"<<"["<<ret.first->first<<","<<ret.first->second<<"]"<<endl;
    // }else{
    //     cout<<"插入失败"<<endl;
    // }

    //map的下标
    cout<<"[hello"<<","<<m["hello"]<<"]"<<endl;//map可以通过下标访问，下标为key值
    m["python"] = 6;//也可以通过下标插入
    m["c++"]=10;//也可以通过下标修改
    display(m);
    return 0;
}