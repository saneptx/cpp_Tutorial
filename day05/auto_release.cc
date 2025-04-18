#include<iostream>
#include<pthread.h>
using namespace std;
class Singleton {
public:
    //单例对象创建在堆区
    static Singleton* getInstance(){
        pthread_once(&_once,init_r);
        return pInstance;
    }
    static void init_r(){
        pInstance = new Singleton(1,2);
        atexit(destory);
    }
    void print() const{
        cout<<"("<<_ix<<","<<_iy<<")"<<endl;
    }
    
private:
    Singleton(int _ix,int _iy):_ix(_ix),_iy(_iy) { std::cout << "Constructor\n"; }
    ~Singleton() { std::cout << "Destructor\n"; }
    static void destory(){
        if(pInstance){
            delete pInstance;
            pInstance = nullptr;
            cout<<"atexit: Deleted Singleton"<<endl;
        }
    }
    int _ix;
    int _iy;
    static Singleton* pInstance;
    static pthread_once_t _once;
};
Singleton* Singleton::pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;
int main(){
    Singleton::getInstance()->print();
    return 0;
}