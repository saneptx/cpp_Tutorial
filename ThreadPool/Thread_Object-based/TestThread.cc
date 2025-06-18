#include "Thread.h"
#include <iostream>
#include <unistd.h>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::bind;


class MyTask{
public:
    void process(int x){
        while(1){
            cout<<"My task is running..."<<endl;
            sleep(x);
        }
    }
};
void test1(){
    MyTask task;
    Thread mth(bind(&MyTask::process, &task,1));
    mth.start();
    mth.stop();
}
void test2(){
    MyTask task;
    unique_ptr<Thread> up(new Thread(bind(&MyTask::process,&task,1)));//创建堆对象
    up->start();
    up->stop();
}
int main(){
    test2();
}