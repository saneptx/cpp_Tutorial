#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string> number ={
        {1,"hello"},
        {2,"world"},
        {3,"wangdao"},
        pair<int,string>(4,"hubei"),
        pair<int,string>(5,"wangdao"),
        make_pair(6,"shenzhen"),
        make_pair(7,"shanghai"),
        make_pair(8,"beijing")
    };
    map<int,string>::iterator it = number.begin();
    while(it!=number.end()){
        cout<<(*it).first<<" "<<it->second<<endl;
        ++it;
    }

    cout<<number.count(1)<<endl;//键值存在返回1
    cout<<number.count(9)<<endl;//键值不存在返回0

    auto it2 = number.find(3);
    if(it2 == number.end()){
        cout<<"该元素不在map中!"<<endl;
    }else{
        cout<<it2->first<<" "<<it2->second<<endl;
    }

    pair<map<int,string>::iterator,bool> ret = number.insert(pair<int,string>(8,"nanjing"));//第一个对象成员是map元素相应的迭代器，第二个成员是boll值
    if(ret.second){
        cout<<"元素插入成功！"<<endl;
    }else{
        cout<<ret.first->first<<" "<<ret.first->second<<endl;
        cout<<"该元素插入失败！"<<endl;
    }

    map<int,string> number2 = {{10,"c++"},{11,"python"}};
    number.insert(number2.begin(),number2.end());
    number.insert({{20,"java"},{21,"go"}});
    for(auto & num : number){
        cout<<num.first<<" "<<num.second<<endl;
    }

    number[1] = "hi";//可以通过下标修改元素
    cout<<number[22]<<endl;//如果通过下标访问一个键值不存在的元素会添加该元素其value值为空
    for(auto & num : number){
        cout<<num.first<<" "<<num.second<<endl;
    }
    return 0;
}