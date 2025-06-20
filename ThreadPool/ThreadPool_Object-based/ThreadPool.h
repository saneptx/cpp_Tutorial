#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "TaskQueue.h"
#include "Thread.h"
#include <vector>
#include <memory>
#include <iostream>
#include <unistd.h>
using std::bind;
using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;


class Thread;
using Task = function<void()>;
class ThreadPool{
public:
    ThreadPool(size_t threadNum,size_t queueSize);
    ~ThreadPool();
    void start();
    void stop();
    void addTask(Task &&task);
    void doTask();
private:
    Task getTask();
    size_t _threadNum;
    size_t _queueSize;
    vector<unique_ptr<Thread>> _threads;
    TaskQueue _taskQueue;
    bool _isExit;
};


#endif