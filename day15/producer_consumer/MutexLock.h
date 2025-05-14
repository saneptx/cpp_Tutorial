#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include<pthread.h>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>

class MutexLock{
public:
    MutexLock();
    ~MutexLock();

    void lock();
    void tryLock();
    void unlock();
    pthread_mutex_t* getLockPtr();
private:
    pthread_mutex_t _mutex;
};
#endif