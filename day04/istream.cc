#include<iostream>
#include<limits>
using namespace std;
void printStreamStatus(std::istream & is){
    cout << "is's goodbit:" << is.good() << endl;
    cout << "is's badbit:" << is.bad() << endl;
    cout << "is's failbit:" << is.fail() << endl;
    cout << "is's eofbit:" << is.eof() << endl;
}
int main(){
    printStreamStatus(cin);
    int num1 = 0,num2 = 0;
    cin >> num1 >> num2;
    cout<<"num1:"<<num1<<" num2:"<<num2<<endl;
    if(!cin.good()){
        cin.clear();//恢复流的状态
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//清空缓冲区
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//清空缓冲区
    string line;
    //cin>>line;//cin会跳过空格、table、换行符等空白字符
    getline(cin,line);//一般使用getline获取字符串
    cout<<"line:"<<line<<endl;
    if(!cin.good()){
        cin.clear();//恢复流的状态
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//清空缓冲区
        cout << endl;
        printStreamStatus(cin);
    }
    printStreamStatus(cin);
    return 0;
}