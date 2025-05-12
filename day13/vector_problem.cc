#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;


void test(){
    vector<int> vec;
    vec.push_back(1);
    bool flag = true;
    for(auto it = vec.begin();it!=vec.end();++it){

        cout<<*it<<" ";
        if(flag){
            vec.push_back(2);//发生扩容
            flag = false;
            it = vec.begin();//迭代器复位
        }
    }
}
int main(){
    test();
    return 0;
}