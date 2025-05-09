#include<iostream>
#include<list>
using namespace std;

struct CompareList{
    bool operator()(const int &lhs,const int &rhs)const{//实现从大到小排序
        return lhs > rhs;
    }
};

void display(list<int> l){
    for(auto &elem:l){
        cout<<elem<<" ";
    }
    cout<<endl;
}
/* List特殊操作 */
void test0(){
    list<int> l = {1,3,5,7,6,6,9};
    cout<<"原链表："<<endl;
    display(l);
    // l.reverse();//链表逆置
    // cout<<"链表逆置后："<<endl;
    // display(l);
    // cout<<"链表默认从小到大排序："<<endl;
    // l.sort();
    // display(l);
    // cout<<"链表从大到小排序："<<endl;
    // l.sort(CompareList());
    // display(l);

    // cout<<"链表去重后："<<endl;
    // l.unique();
    // display(l);

    list<int> l2 = {2,4,6,10,8};
    cout<<"链表2:"<<endl;
    display(l2);
    // cout<<"链表合并："<<endl;
    // l.merge(l2);
    // display(l);
    // cout<<"l2.size():"<<l2.size()<<endl;//合并后链表2为空

    auto it = l.begin();
    ++it;
    ++it;
    // l.splice(it,l2);
    // cout<<"将链表2插入到原链表2号元素后:"<<endl;
    // display(l);
    // cout<<"*it:"<<*it<<endl;
    /*复位*/
    // it = l.begin();
    // ++it;
    // ++it;
    auto it2 = l2.end();
    --it2;
    cout<<"*it2:"<<*it2<<endl;
    l.splice(it,l2,it2);
    cout<<"插入l2指定位置元素到原链表:"<<endl;
    display(l);
}
int main(){
    test0();
    return 0;
}