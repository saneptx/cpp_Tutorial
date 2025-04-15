#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

class Computer {
public:
    Computer():_brand(new char[10]()),_price(1000){
        strcpy(this->_brand,"Apple");
        cout<<"Computer()"<<endl;
    }
    Computer(const char * brand,int price)
    :_brand(new char[strlen(brand) + 1]())
    ,_price(price){
        strcpy(_brand,brand);
        cout<<"Computer(str,int)"<<endl;
    }
    Computer(const Computer & rhs)//手动定义拷贝构造函数
    :_brand(new char[strlen(rhs._brand)+1]())
    ,_price(rhs._price){
        strcpy(_brand,rhs._brand);
    }
    ~Computer(){
        if(_brand){
            delete[] _brand;
            _brand = nullptr;
            cout<<"~Computer()"<<endl;
        }
    }
    void print();
    void *operator new(size_t size){
        cout<<"operator new"<<endl;
        void * ret = malloc(size);
        return ret;
    }
    void operator delete(void * ptr){
        cout<<"operator delete"<<endl;
        free(ptr);
    }
private:
    char * _brand;
    float _price;
};
void Computer::print(){
    cout<<_brand<<" "<<_price<<endl;
}
int main(){
    Computer *cp = new Computer("Apple",10000);
    Computer *cArray = new  Computer[5]();
    cp->print();
    cArray->print();
    (cArray+1)->print();
    delete cp;
    cp = nullptr;
    delete[] cArray;
    cArray = nullptr;
    return 0;
}