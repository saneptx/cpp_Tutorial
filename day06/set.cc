#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> numbers;
    set<int> numbers2{3,1,7,2,9,6};
    set<int> numbers3 = numbers2;
    set<int> numbers4(numbers2.begin(),numbers2.end());
    
    //迭代器方式遍历
    set<int>::iterator it = numbers2.begin();
    while(it!=numbers2.end()){
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;

    //增强for循环遍历
    for(auto & nu:numbers2){
        cout<<nu<<" ";
    }
    cout<<endl;

    cout<<numbers2.count(7)<<endl;//能找到返回1
    cout<<numbers2.count(10)<<endl;//找不到返回0

    auto it2 = numbers2.find(7);
    cout<<*it2<<endl;//7 找到则返回元素相应的迭代器
    it2 = numbers2.find(10);
    if(it2==numbers2.end()){
        cout<<"未找到该元素！"<<endl;//找不到返回numbers.end()
    }

    pair<set<int>::iterator,bool> ret = numbers2.insert(8);
    if(ret.second){
        cout << "该元素插入成功:"<< *(ret.first) << endl;
    }else{
        cout << "该元素插入失败，表明该元素已存在" << endl;
    }

    int arr[5] = {67,68,69,70,71};
    numbers2.insert(arr,arr+5);
    for(auto & nu:numbers2){
        cout<<nu<<" ";
    }
    cout<<endl;
    numbers2.insert({100,105,103});
    for(auto & nu:numbers2){
        cout<<nu<<" ";
    }
    cout<<endl;
    return 0;
}