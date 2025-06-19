#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t queueSize)
:_queueSize(queueSize)
,_queue()
,_mutex()
,_notFull(_mutex)
,_notEmpty(_mutex)
,_notExit(true){

}
TaskQueue::~TaskQueue(){

}
void TaskQueue::push(const ElemType ptask){
    MutexLockGuard autoLock(_mutex);

    while(isFull()){//使用while循环避免虚假唤醒
        _notFull.wait();
    }

    _queue.push(ptask);
    _notEmpty.notify();

}
ElemType TaskQueue::pop(){

    MutexLockGuard autoLock(_mutex);
    while(isEmpty() & _notExit){//没有任务且不退出则等待新的任务
        _notEmpty.wait();
    }
    if(_notExit){
        ElemType tmp = _queue.front();
        _queue.pop();
        _notFull.notify();
        return tmp;
    }else{
        return nullptr;
    }
}

bool TaskQueue::isFull() const{
    return _queue.size() == _queueSize;
}
bool TaskQueue::isEmpty() const{
    return _queue.size() == 0;
}
void TaskQueue::wakeUp(){
    _notExit = false; //决定退出，唤醒所有等待新任务的线程进入退出流程
    _notEmpty.notifyAll();
}