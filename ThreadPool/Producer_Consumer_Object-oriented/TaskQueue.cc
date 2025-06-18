#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t queueSize)
:_queueSize(queueSize)
,_queue()
,_mutex()
,_notFull(_mutex)
,_notEmpty(_mutex){

}
TaskQueue::~TaskQueue(){

}
void TaskQueue::push(const int &value){
    //1.上锁
    _mutex.lock();
    //2.判满,满则睡觉
    while(isFull()){
        _notFull.wait();
    }
    //3.不为满才能,push并唤醒消费者
    _queue.push(value);
    _notEmpty.notify();
    //4.解锁
    _mutex.unlock();
}
int TaskQueue::pop(){
    //1.上锁
    _mutex.lock();
    //2.判空,空则睡觉
    while(isEmpty()){
        _notEmpty.wait();
    }
    //3.不为空才能pop,并唤醒消费者
    int tmp = _queue.front();
    _queue.pop();
    _notFull.notify();
    //4.解锁
    _mutex.unlock();
    return tmp;
}

bool TaskQueue::isFull() const{
    return _queue.size() == _queueSize;
}
bool TaskQueue::isEmpty() const{
    return _queue.size() == 0;
}