#include"Thread.h"


using std::cout;
using std::endl;
Thread::Thread()
:_tid(0)
,_isRunning(false){

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
    if(_isRunning == true){
        int ret = pthread_join(_tid,nullptr);
        if(ret){
            perror("pthread_join");
            return;
        }
    }
}

void *Thread::threadFunc(void *arg){
    Thread *pth = static_cast<Thread *>(arg);
    if(pth){
        pth->run();
    }
    else{
        cout<<"nullptr == pth"<<endl;
    }
    pthread_exit(nullptr);
}
