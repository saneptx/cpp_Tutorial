#include "Thread.h"
#include <iostream>
#include <unistd.h>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class MyThread:public Thread{
public:
    void run() override{
        while(1){
            cout<<"running..."<<endl;
            sleep(1);
        }
    }
};
void test1(){
    MyThread mth;//创建栈对象
    mth.start();
    mth.stop();
}
void test2(){
    unique_ptr<Thread> up(new MyThread());//创建堆对象
    up->start();
    up->stop();
}
int main(){
    test1();
}