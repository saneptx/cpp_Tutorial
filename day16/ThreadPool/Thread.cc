#include "Thread.h"
using std::cout;
using std::endl;

Thread::Thread(ThreadCallback &&cb)
:_tid(0)
,_isRunning(false)
,_cb(cb){

}

Thread::~Thread(){

}

void Thread::start(){
    int ret = pthread_create(&_tid,nullptr,threadFunc,this);
    if(ret){
        perror("pthread_create");
        return;
    }
    _isRunning = true;
}

void Thread::stop(){
    int ret = pthread_join(_tid,nullptr);
    if(ret){
        perror("pthread_join");
        return;
    }
    _isRunning = false;
}

void *Thread::threadFunc(void* arg){
    Thread *pthread = static_cast<Thread *>(arg);
    if(pthread){
        pthread->_cb();
    }
    else{
        cout<<"nullptr == pth"<<endl;
    }
    pthread_exit(nullptr);
}