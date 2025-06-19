#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "TaskQueue.h"
#include "Task.h"
#include "Thread.h"
#include <vector>
#include <memory>
#include <iostream>
#include <unistd.h>
using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;


class ThreadPool{
    friend class WorkThread;
public:
    ThreadPool(size_t threadNum,size_t queueSize);
    ~ThreadPool();
    void start();
    void stop();
    void addTask(Task *ptask);
    void doTask();
private:
    Task *getTask();
    size_t _threadNum;
    size_t _queueSize;
    vector<unique_ptr<Thread>> _threads;
    TaskQueue _taskQueue;
    bool _isExit;
};


#endif