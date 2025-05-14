#include"Thread_Callback.h"


using std::cout;
using std::endl;
Thread_Callback::Thread_Callback(ThreadCallback &&cb)
:_tid(0)
,_isRunning(false)
,_cb(std::move(cb)){//注册函数

}

Thread_Callback::~Thread_Callback(){

}

void Thread_Callback::start(){
    int ret = pthread_create(&_tid,nullptr,threadFunc,this);
    if(ret){
        perror("pthread_create");
        return;
    }
    _isRunning = true;
}

void Thread_Callback::stop(){
    if(_isRunning == true){
        int ret = pthread_join(_tid,nullptr);
        if(ret){
            perror("pthread_join");
            return;
        }
    }
}

void *Thread_Callback::threadFunc(void *arg){
    Thread_Callback *pth = static_cast<Thread_Callback *>(arg);
    if(pth){
        pth->_cb();
    }
    else{
        cout<<"nullptr == pth"<<endl;
    }
    pthread_exit(nullptr);
}
