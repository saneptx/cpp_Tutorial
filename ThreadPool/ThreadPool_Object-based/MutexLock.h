#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include <pthread.h>
#include <stdio.h>
#include "NonCopyable.h"

class MutexLock
: NonCopyable{
public:
    MutexLock();
    ~MutexLock();
    void lock();//上锁
    void tryLock();//尝试上锁
    void unlock();//解锁
    pthread_mutex_t *getMutexLockPtr();//获取数据成员
private:
    pthread_mutex_t _mutex;
};

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
#endif