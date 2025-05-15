#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__
#include"TaskQueue.h"
#include"Thread.h"
#include<functional>
#include<vector>
#include<memory>

using std::vector;
using std::unique_ptr;

class ThreadPool{
public:
    using Task = TaskQueue::Task;
    
    ThreadPool(size_t threadNum, size_t queueSize);
    ~ThreadPool();
    
    // 启动线程池
    void start();
    
    // 停止线程池
    void stop();
    
    // 添加任务到任务队列
    void addTask(Task &&task);
    
private:
    // 获取任务的函数 - 工作线程调用
    Task getTask();
    
    // 工作线程函数
    void threadFunc();
    
    size_t _threadNum;               // 线程数量
    size_t _queueSize;               // 任务队列大小
    vector<unique_ptr<Thread>> _threads;  // 工作线程
    TaskQueue _taskQueue;            // 任务队列
    bool _isExit;                    // 线程池是否退出
};

#endif