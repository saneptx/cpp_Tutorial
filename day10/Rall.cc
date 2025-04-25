#include<iostream>
using namespace std;

template <class T>
class RAII{
public:
    //1.在构造函数中初始化资源（托管资源）
    RAII(T *data)
    :_data(data){
        cout<<"RAII(T*)"<<endl;
    }
    //2.在析构函数中释放资源
    ~RAII(){
        cout<<"~RAII()"<<endl;
        if(_data){
            delete _data;
            _data = nullptr;
        }
    }
    //3.提供若然访问资源的方法
    T * operator->(){
        return _data;
    }
    T & operator*(){
        return *_data;
    }
    T * get() const{
        return _data;
    }
    void set(T * data){
        if(_data){
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }
    RAII(const RAII & rhs) = delete;
    RAII& operator=(const RAII & rhs) = delete;
private:
    T * _data;
};
void test0(){

}
int main(){

    return 0;
}