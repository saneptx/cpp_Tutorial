#include<iostream>
#include<string>
using std::endl;
using std::cout;
using std::string;

int main(){
    string str1 = "hello";//初始化一个字符串
    string str2 = string(str1,3);//从已有的str1字符串开始构造一个新的字符串知道结尾
    string str3 = string(str1);//拷贝str1字符串
    string str4 = str1 + str3;//拼接字符串
    string str5 = str1 + "world!";//拼接字符串
    string str6 = string("hello world",5);//截取前五个字符构造字符串
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    cout<<str4<<endl;
    cout<<str5<<endl;
    cout<<str6<<endl;
    string str = string();//创建空字符串
    if(str.empty())
        cout<<"Empty string!"<<endl;
    cout<<str1.size()<<endl;//获取字符数
    cout<<str1.length()<<endl;
    if(str1 == str3)//判断两个字符串是否一致
        cout<<"Same string!"<<endl;
    for(size_t idx = 0;idx < str3.size();++idx){//普通for循环变量
        cout<<str3[idx]<<" ";
    }
    cout<<endl;
    for(auto & ch: str3){//增强for循环遍历
        cout<<ch<<" ";
    }
    cout<<endl;
    auto it = str3.begin();//迭代器遍历
    while(it != str3.end()){
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    return 0;
}