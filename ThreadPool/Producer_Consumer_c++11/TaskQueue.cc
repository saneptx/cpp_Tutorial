#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t queueSize)
:_queueSize(queueSize)
,_queue()
,_mutex()
,_notFull()
,_notEmpty(){

}
TaskQueue::~TaskQueue(){

}
void TaskQueue::push(const int &value){
    
    unique_lock<mutex> autoLock(_mutex); 

    while(isFull()){//使用while循环避免虚假唤醒
        _notFull.wait(autoLock);
    }

    _queue.push(value);
    _notEmpty.notify_one();

}
int TaskQueue::pop(){

    unique_lock<mutex> autoLock(_mutex);

    while(isEmpty()){
        _notEmpty.wait(autoLock);
    }

    int tmp = _queue.front();
    _queue.pop();
    _notFull.notify_one();

    return tmp;
}

bool TaskQueue::isFull() const{
    return _queue.size() == _queueSize;
}
bool TaskQueue::isEmpty() const{
    return _queue.size() == 0;
}