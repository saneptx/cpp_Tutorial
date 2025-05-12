#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<functional>
using namespace std;

// bool func(int value){
//     return value>4;
// }
void test(){
    vector<int> vec = {1,3,4,6,8,5,3,2};
    for_each(vec.begin(),vec.end(),[](int &value){
        cout<<value<<" ";
    });
    cout<<endl;
    //remove_if不能将满足条件的元素一次删除，需要配合erase使用
    // auto it = remove_if(vec.begin(),vec.end(),[](int value){
    //     return value>4;
    // });
    // auto it = remove_if(vec.begin(),vec.end(),bind1st(less<int>(),4));
    auto it = remove_if(vec.begin(),vec.end(),bind2nd(greater<int>(),4));
    vec.erase(it,vec.end());
    for_each(vec.begin(),vec.end(),[](int &value){
        cout<<value<<" ";
    });
    cout<<endl;
}
int main(){
    test();
    return 0;
}