#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t threadNum,size_t queueSize)
:_threadNum(threadNum)
,_queueSize(queueSize)
,_taskQueue(_queueSize)
,_isExit(false)
{
    _threads.reserve(_threadNum);
}
ThreadPool::~ThreadPool(){

}
void ThreadPool::start(){
    //创建工作线程
    for(size_t idx = 0;idx != _threadNum;++idx){
        _threads.push_back(thread(&ThreadPool::doTask,this));
    }

}
void ThreadPool::stop(){
    while(!_taskQueue.isEmpty()){//如果任务队列不为空则需要等待任务执行完
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    _isExit = true;
    _taskQueue.wakeUp();
    for(auto &th :_threads){
        th.join();
    }
}
void ThreadPool::addTask(Task *ptask){
    if(ptask){
        _taskQueue.push(ptask);
    }
}

Task *ThreadPool::getTask(){
    return _taskQueue.pop();
}
void ThreadPool::doTask(){
    
    while(!_isExit){
        
        Task *ptask = getTask();
        if(ptask){
            ptask->process();
        }else{
            cout<<"Thread exit!"<<endl;
        }
    }

}