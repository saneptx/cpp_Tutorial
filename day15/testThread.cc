#include"Thread.h"
#include"Thread_Callback.h"
#include<iostream>
#include<memory>
#include<unistd.h>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::bind;

class MyThread
:public Thread{
public:
    void run() override{
        //...实现具体逻辑
        while(1){
            cout<<"MyThread is running!"<<endl;
            sleep(1);
        }
        
    }
};
class MyTask{
public:
    void process(int x){
        //...实现具体逻辑
        while(1){
            cout<<"MyTask is running!"<<endl;
            sleep(1);
        }
        
    }
};
void test(){
    MyTask task;
    Thread_Callback mth(bind(&MyTask::process,&task,1));
    mth.start();
    mth.stop();
}
void test2(){
    // unique_ptr<Thread> up(new MyThread());
    // up->start();
    // up->stop();
    MyTask task;
    unique_ptr<Thread_Callback> up(new Thread_Callback(std::bind(&MyTask::process,&task,1)));
    up->start();
    up->stop();
}
int main(){
    test();
    // test2();
    return 0;
}