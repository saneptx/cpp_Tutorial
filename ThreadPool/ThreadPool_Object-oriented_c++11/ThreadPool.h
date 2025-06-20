#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "TaskQueue.h"
#include "Task.h"
#include <vector>
#include <memory>
#include <iostream>
#include <thread>
using std::cout;
using std::endl;
using std::vector;
using std::thread;

class ThreadPool{
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
    TaskQueue _taskQueue;
    vector<thread> _threads;
    bool _isExit;
};


#endif