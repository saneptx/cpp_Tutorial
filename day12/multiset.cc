#include<iostream>
#include<set>
using namespace std;

template<typename Container>
void display(const Container &con){
    for(auto &elem:con){
        cout<<elem<<" ";
    }
    cout<<endl;
}
void test0(){
    multiset<int> ms = {1,3,9,8,3,4,2,3,8,1};
    display(ms);
    auto it = ms.lower_bound(3);//返回第一个大于等于key值得迭代器
    cout<<"*it:"<<*it<<endl;
    auto it2 = ms.upper_bound(3);//返回第一个大于key值得迭代器
    cout<<"*it2:"<<*it2<<endl;
    //返回的是一个范围，第一个迭代器指向的是大于等于给定key的迭代器，第二个迭代器是大姨给定key的迭代器
    pair<multiset<int>::iterator,multiset<int>::iterator> ret = ms.equal_range(3);
    while(ret.first!=ret.second){
        cout<<*ret.first<<" ";
        ++ret.first;
    }
    cout<<endl;
}
int main(){
    test0();
    return 0;
}