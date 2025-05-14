#include"TaskQueue.h"

TaskQueue::TaskQueue(size_t queSize)
:_queSize(queSize)
,_queue()
,_mutex()
,_notFull(_mutex)
,_notEmpty(_mutex){

}

TaskQueue::~TaskQueue(){

}
void TaskQueue::push(const int &value){

    //1.上锁
    MutexLockGuard autoLock(_mutex);
    // _mutex.lock();
    //2.是不是满的
    while(full()){//while可以避免虚假唤醒
        //队列满要wait
        _notFull.wait();
    }
    //队列不满才能push，并唤醒消费者
    _queue.push(value);
    _notEmpty.notify();
    //3.解锁
    // _mutex.unlock();
}

int TaskQueue::pop(){
    //1.上锁
    MutexLockGuard autoLock(_mutex);
    // _mutex.lock();
    //2.是否为空
    while(empty()){
        //队列空需要wait
        _notEmpty.wait();
    }
    //队列不空才能pop，并唤醒生产者
    int tmp = _queue.front();
    _queue.pop();
    _notFull.notify();
    //3.解锁
    // _mutex.unlock();
    
    return tmp;
}
bool TaskQueue::full() const{
    return _queue.size() == _queSize; 
}
bool TaskQueue::empty() const{
    return _queue.size() == 0;
}

class MutexLockGuard{
public:
    MutexLockGuard(MutexLock &mutex)
    :_mutex(mutex){
        _mutex.lock();
    }
    ~MutexLockGuard(){
        _mutex.unlock();
    }
private:
    MutexLock &_mutex;
};