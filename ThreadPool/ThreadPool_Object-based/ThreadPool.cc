#include "ThreadPool.h"



ThreadPool::ThreadPool(size_t threadNum,size_t queueSize)
:_threadNum(threadNum)
,_queueSize(queueSize)
,_isExit(false)
,_taskQueue(_queueSize)
{
    _threads.reserve(_threadNum);
}
ThreadPool::~ThreadPool(){

}
void ThreadPool::start(){
    //创建工作线程
    for(size_t idx = 0;idx != _threadNum;++idx){
        _threads.push_back(unique_ptr<Thread>(new Thread(*this,bind(&ThreadPool::doTask,this))));
    }
    for(auto &th :_threads){
        th->start();
    }
}
void ThreadPool::stop(){
    while(!_taskQueue.isEmpty()){//如果任务队列不为空则需要等待任务执行完
        sleep(1);
    }
    _isExit = true;
    _taskQueue.wakeUp();
    for(auto &th :_threads){
        th->stop();
    }
}
void ThreadPool::addTask(Task &&task){
    if(task){
        _taskQueue.push(std::move(task));
    }
}

Task ThreadPool::getTask(){
    return _taskQueue.pop();
}
void ThreadPool::doTask(){
    
    while(!_isExit){
        
        Task task = getTask();

        if(task){
            task();
        }else{
            cout<<"Thread exit!"<<endl;
        }
    }

}