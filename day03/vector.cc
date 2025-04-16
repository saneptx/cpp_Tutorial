#include<iostream>
#include<vector>
#include<string>
using std::endl;
using std::cout;
using std::vector;
using std::string;

int main(){
    vector<int> numbers;//无参构造，仅指明vector存放元素的种类，没有存放元素
    vector<long> numbers2(10);//存放10个0
    vector<long> numbers3(10,20); //存放10个20
    vector<int> numbers4{1,2,3,4,5,6,7};//直接指明存放的所有元素
    vector<int> numbers5(numbers4.begin(),numbers4.end() - 3);//使用迭代器方式初始化
    for(auto & e:numbers5){
        cout<<e<<" ";
    }
    cout<<endl;

    cout << numbers.size() << endl;
    cout << numbers.capacity() << endl;

    numbers.push_back(1);
    cout << numbers.size() << endl;
    cout << numbers.capacity() << endl;

    numbers.push_back(1);
    cout << numbers.size() << endl;
    cout << numbers.capacity() << endl;

    numbers.push_back(1);
    cout << numbers.size() << endl;
    cout << numbers.capacity() << endl;

    numbers.push_back(1);
    numbers.push_back(1);
    cout << numbers.size() << endl;
    cout << numbers.capacity() << endl;
    return 0;
}