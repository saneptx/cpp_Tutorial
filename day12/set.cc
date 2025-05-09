#include<iostream>
#include<set>
using namespace std;

template <typename Container>
void display(const Container con){
    for(auto &elem:con){
        cout<<elem<<" ";
    }
    cout<<endl;
}

int main(){
    set<int> s = {1,3,5,7,9};
    //查找元素
    // auto it = s.end();
    // if(it==s.find(4)){
    //     cout<<"该元素不在集合中"<<endl;
    // }else{
    //     cout<<"该元素在集合中!"<<endl;
    // }

    //插入元素
    // cout<<"往集合中插入一个元素:"<<endl;
    // pair<set<int>::iterator,bool> ret = s.insert(4);
    // if(ret.second == true){
    //     cout<<"插入成功"<<*ret.first<<endl;
    // }else{
    //     cout<<"插入失败"<<*ret.first<<endl;
    // }

    //删除元素
    cout<<"删除前:"<<endl;
    display(s);
    auto it = s.begin();
    ++it;
    ++it;
    cout<<"*it="<<*it<<endl;
    s.erase(it);
    cout<<"删除后:"<<endl;
    display(s);
    return 0;
}