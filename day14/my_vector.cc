#include<iostream>
#include<memory>
using namespace std;

template<typename T>
class Vector{
public:
    Vector()
    :_start(nullptr)
    ,_finish(nullptr)
    ,_end_of_storage(nullptr){};
    ~Vector(){
        if(_start){
            while(_start!=_finish){
                _alloc.destroy(--_finish);//销毁对象
            }
            _alloc.deallocate(_start, capacity());//释放空间
        }
    }

    void push_back(const T &);
    void pop_back();

    int size() const;
    int capacity() const;
private:
    void reallocate();
private:
    static std::allocator<T> _alloc;

    T * _start;
    T * _finish;
    T * _end_of_storage;
};
template <typename T>
std::allocator<T> Vector<T>::_alloc;//静态成员初始化
template<typename T>
int Vector<T>::size() const{
    return _finish - _start;
}
template<typename T>
int Vector<T>::capacity() const{
    return  _end_of_storage - _start;
}
template<typename T>
void Vector<T>::push_back(const T &value){
    if(size() == capacity()){
        reallocate();
    }
    if(size()<capacity()){
        _alloc.construct(_finish++, value);
    }
}
template<typename T>
void Vector<T>::pop_back(){
    if(size()>0){
        _alloc.destroy(--_finish);
    }
}
template<typename T>
void Vector<T>::reallocate(){
    //1.申请一块内存空间
    int oldCapacity = capacity();
    int newCapacity = oldCapacity > 0 ? 2 * oldCapacity :1; 
    T *ptmp =  _alloc.allocate(newCapacity);
    if(_start){
        //2.老空间的元素拷贝到新空间
        uninitialized_copy(_start,_finish, ptmp);
        //3.将老空间的元素销毁并将空间进行回收
        while(_start!=_finish){
            _alloc.destroy(--_finish);//销毁对象
        }
        _alloc.deallocate(_start, oldCapacity);//释放空间
    }
    //4.将三个指针与新空间产生联系
    _start = ptmp;
    _finish = ptmp + oldCapacity;
    _end_of_storage = ptmp + newCapacity;
}

void printCapacity(const Vector<int> &con){
    cout<<"size()="<<con.size()<<endl;
    cout<<"capacity()="<<con.capacity()<<endl;
}
void test(){
    Vector<int> vec;
    printCapacity(vec);
    vec.push_back(1);
    printCapacity(vec);
    vec.push_back(2);
    printCapacity(vec);
    vec.push_back(3);
    printCapacity(vec);
    vec.push_back(4);
    printCapacity(vec);
    vec.push_back(5);
    printCapacity(vec);
}
int main(){
    test();
    return 0;
}