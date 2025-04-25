#include<iostream>
#include<string.h>
using namespace std;
class String
{
public:
    String(): _str(new char[1]()) {
        cout<<"String()"<<endl;
    }//默认无参构造函数
    String(const char* pstr):_str(new char[strlen(pstr) + 1]()){//字符串字面量构造函数
        cout<<"String(const char* pstr)"<<endl;
        strcpy(_str, pstr);
    }
    String(const String& rhs) :_str(new char[strlen(rhs._str) + 1]()){//拷贝构造函数
        cout<<"String(const String& rhs)"<<endl;
        strcpy(_str, rhs._str);
    }
    String(String && rhs)//右值引用构造函数
    : _str(rhs._str)
    {
        cout << "String(String&&)" << endl;
        rhs._str = nullptr;
    }
    String &operator=(const String &rhs){//赋值运算符重载
        cout<<"String &operator=(const String &rhs)"<<endl;
        if (this != &rhs){
            delete[] _str;
            _str = new char[strlen(rhs._str) + 1];
            strcpy(_str, rhs._str);
        }
        return *this;
    }
    String &operator=(String&& rhs){//赋值运算符重载
        cout<<"String &&operator=called"<<endl;
        if (this != &rhs){
            delete[] _str;
            _str = rhs._str;
            rhs._str = nullptr;
        }
        return *this;
    }
    void print(){
        cout<<_str<<endl;
    }
    ~String(){
        if (_str){
        delete [] _str;
        _str = nullptr;
        }
    }
private:
    char* _str;
};
String func(){
    String str1("wangdao");
    str1.print();
    return str1;
}
void test0(){
    func();
}
int main(){
    test0();
    return 0;
}