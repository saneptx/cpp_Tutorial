#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<limits>
using namespace std;

//重载+ ++ +=运算符
class Complex{
public:
    Complex(int _real,int _image):_real(_real),_image(_image){};
    Complex operator+=(const Complex & rhs){
        _real += rhs._real;
        _image += rhs._image;
        return *this;
    }
    Complex operator+(const Complex & rhs){
        return Complex(_real + rhs._real,_image+ rhs._image);
    }
    Complex & operator++(){//前置++
        ++_real;
        ++_image;
        return *this;
    }
    Complex operator++(int){//后置++运算符重载函数的参数列表加入一个int与前置++做区分，返回值类型为对象而不是引用
        Complex temp(*this);
        ++_real;
        ++_image;
        return temp;
    }
    void print();
private:
    int _real;
    int _image;
};
void Complex::print(){
    cout<<_real<<" "<<_image<<endl;
}
//重载[]运算符
class CharArray{
public:
    CharArray(const char * pstr)
    : _capacity(strlen(pstr) + 1)
    , _data(new char[_capacity]())
    {
        strcpy(_data,pstr);
    }
    ~CharArray(){
        if(_data){
        delete [] _data;
        _data = nullptr;
        }
    }
    char & operator[](size_t idx){
        if(idx < _capacity-1){
            return _data[idx];
        }else{
            cout<<"out of range"<<endl;
            static char nullchar = '\0';
            return nullchar;
        }
    }
    /*
    //采用这种方式可以禁止CharArray地域性通过下标访问修改字符数组的元素
    //第一个const的效果，函数返回值是一个const引用
    //调用函数得到的结果不允许进行写操作
    //第二个const的效果，在函数中不能修改数据成员
    //const对象只能调用const成员函数
    const char & operator[](size_t idx) const{
        if(idx < _capacity-1){
            return _data[idx];
        }else{
            cout<<"out of range"<<endl;
            static char nullchar = '\0';
            return nullchar;
        }
    }
    */
    void print() const{
        cout<<_data<<endl;
    }
private:
    size_t _capacity;
    char * _data;
};
void readInputInt(istream & is,int & number){
    cout<<"please input a int number:"<<endl;
    //等价于is>>number;while(!is.eof())
    while(is>>number,!is.eof()){
        if(is.bad()){
            cout<<"istream is broken"<<endl;
            return;
        }else if(is.fail()){
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"please input a int number"<<endl;
        }else{
            break;
        }
    }
}
class Point{
public:
    Point(){};
    Point(int _ix,int _iy):_ix(_ix),_iy(_iy){};
    friend
    ostream & operator<<(ostream & os,const Point & rhs);
    friend
    istream & operator>>(istream & is,Point & rhs);
private:
    int _ix;
    int _iy;
};
ostream & operator<<(ostream & os,const Point & rhs){
    os<<"("<<rhs._ix<<","<<rhs._iy<<")";
    return os;
}
istream & operator>>(istream & is,Point & rhs){
    // is>>rhs._ix;
    // is>>rhs._iy;
    readInputInt(is,rhs._ix);
    readInputInt(is,rhs._iy);
    return is;
}
class Data{
public:
    Data(){
        cout<<"Data()"<<endl;
    }
    Data(int x):_data(x){};
    ~Data(){
        cout<<"~Data()"<<endl;
    }
    int getData() const{
        return _data;
    }
private:
    int _data;
};
class MiddleLayer{
public:
    MiddleLayer(Data *p):_pdata(p){
        cout<<"MiddleLayer(Data*)"<<endl;
    }
    ~MiddleLayer(){
        delete _pdata;
        _pdata = nullptr;
        cout<<"~MiddleLayer"<<endl;
    }
    Data * operator->(){
        return _pdata;
    }
    Data & operator*(){
        return *_pdata;
    }
private:
    Data *_pdata;
};
class ThirdLayer{
public:
    ThirdLayer(MiddleLayer *_pmid):_pmid(_pmid){
        cout<<"ThirdLayer(Data*)"<<endl;
    }
    ~ThirdLayer(){
        delete _pmid;
        _pmid = nullptr;
        cout<<"~ThirdLayerLayer"<<endl;
    }
    MiddleLayer & operator->(){
        return *_pmid;
    }
    MiddleLayer & operator*(){
        return *_pmid;
    }
private:
    MiddleLayer *_pmid;
};
int main(){
    ThirdLayer thirdl(new MiddleLayer(new Data(3)));
    cout<<thirdl->getData()<<endl;
    cout<<(*(*thirdl)).getData()<<endl;
    return 0;
}