#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

void func(int value){
    cout<<++value<<" ";
}
void test(){
    vector<int> vec = {1,3,7,9,5,8};
    copy(vec.begin(),vec.end(),//遍历vector
        ostream_iterator<int>(cout," "));
    cout<<endl;
    // for_each(vec.begin(),vec.end(),func);
    for_each(vec.begin(),vec.end(),[](int &value){//采用lambda表达式(匿名函数)
        ++value;
        cout<<value<<" ";
    });
    cout<<endl;
    copy(vec.begin(),vec.end(),//遍历vector
        ostream_iterator<int>(cout," "));
    cout<<endl;
}
int main(){
    test();
    return 0;
}