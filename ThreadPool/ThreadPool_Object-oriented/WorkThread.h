#ifndef __WORKTHREAD_H__
#define __WORKTHREAD_H__

#include "Thread.h"
#include "ThreadPool.h"


class WorkThread
:public Thread
{
public:
    WorkThread(ThreadPool &pool);
    ~WorkThread();
    void run() override;
private:
    ThreadPool &_pool;
};


#endif