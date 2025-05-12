#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class Number{
public:
    Number(size_t data = 0)
    :_data(data){};

    void print(){
        cout<<_data<<" ";
    }

    bool isEven(){
        return (_data % 2 ==0);
    }

    bool isPrimer(){
        if(1 == _data){
            return false;
        }
        for(size_t idx = 2;idx <= _data/2; ++idx){
            if(_data % idx == 0){
                return false;
            }
        }
        return true;
    }
private:
    size_t _data;
};

void test(){
    vector<Number> vec;
    for(size_t idx = 1;idx != 30;++idx){
        vec.push_back(Number(idx));
    }
    // for_each(vec.begin(),vec.end(),mem_fn(&Number::print));//第一种写法
    using namespace std::placeholders;
    for_each(vec.begin(),vec.end(),bind(&Number::print,_1));//也可以使用bind绑定
    cout<<endl;

    //移除所有偶数
    vec.erase(remove_if(vec.begin(),vec.end(),mem_fn(&Number::isEven)),vec.end());
    for_each(vec.begin(),vec.end(),mem_fn(&Number::print));
    cout<<endl;

    //移除所有质数
    vec.erase(remove_if(vec.begin(),vec.end(),mem_fn(&Number::isPrimer)),vec.end());
    for_each(vec.begin(),vec.end(),mem_fn(&Number::print)); 
    cout<<endl;
}
int main(){
    test();
    return 0;
}