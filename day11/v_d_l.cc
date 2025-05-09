#include<iostream>
#include<vector>
#include<deque>
#include<list>
using namespace std;

template <typename Container>
void display(const Container con){
    for(auto &elem:con){
        cout<<elem<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v = {1,7,7,3,5,7,7,7,9};
    deque<int> d = {2,4,6,8,10};
    list<int> l = {100,200,300,400,500};
    /*
        List insert操作
    */
    // display(l);
    // auto it = l.begin();
    // ++it;
    // cout<<*it<<endl;
    // l.insert(it,100);
    // cout<<"插入元素后："<<endl;
    // display(l);
    // cout<<"*it:"<<*it<<endl;


    // l.insert(it,5,22);
    // cout<<"插入一组元素后："<<endl;
    // display(l);
    // cout<<"*it:"<<*it<<endl;

    // l.insert(it,v.begin(),v.end());
    // cout<<"从迭代器中插入一组元素后："<<endl;
    // display(l);
    // cout<<"*it:"<<*it<<endl;

    // l.insert(it,{666,777,888});
    // cout<<"从大括号中插入一组元素后："<<endl;
    // display(l);
    // cout<<"*it:"<<*it<<endl;
    /*
        vector insert操作
    */

    // display(v);
    // auto it = v.begin();
    // ++it;
    // cout<<"*it:"<<*it<<endl;
    // v.insert(it,10);
    // cout<<"插入元素后："<<endl;
    // cout<<"*it:"<<*it<<endl;//此时的迭代器已失效
    // display(v);
    

    display(v);
    cout<<"执行删除操作后:"<<endl;
    for(auto it = v.begin();it!=v.end();){
        if(*it == 7){
            v.erase(it);
        }else{
            ++it;
        }
    }
    display(v);
    return 0;
}