#include "ThreadPool.h"
#include <iostream>

using std::cout;
using std::endl;
using std::bind;

ThreadPool::ThreadPool(size_t threadNum, size_t queueSize)
: _threadNum(threadNum)
, _queueSize(queueSize)
, _threads()
, _taskQueue(_queueSize)
, _isExit(false) 
{
    /*预留足够的空间以容纳 _threadNum 个线程对象，
     *从而避免在后续向 _threads 添加线程对象时发生多次内存重新分配（reallocation）。 */
    _threads.reserve(_threadNum);
}

ThreadPool::~ThreadPool() {
    if (!_isExit) {
        stop();
    }
}

void ThreadPool::start() {
    // 创建线程对象并启动它们
    for (size_t i = 0; i < _threadNum; ++i) {
        unique_ptr<Thread> thread(new Thread(
            bind(&ThreadPool::threadFunc, this)
        ));
        _threads.push_back(std::move(thread));
    }

    // 启动所有线程
    for (auto &thread : _threads) {
        thread->start();
    }
}

void ThreadPool::stop() {

    while(!_taskQueue.empty()){//任务执行不完，就不能退出
        sleep(1);
    }
    // cout<<"-----2-----"<<endl;
    // 设置退出标志
    _isExit = true;
    
    // 确保所有线程都能获取到一个任务从而退出
    for (size_t i = 0; i < _threadNum; ++i) {
        // cout<<"-----3-----"<<endl;
        // 添加空任务唤醒所有等待的线程
        addTask(nullptr);
    }

    //唤醒所有工作线程
    // _taskQueue.wakeUpALL();


    // 等待所有线程结束
    for (auto &thread : _threads) {
        thread->stop();
    }
    
}

void ThreadPool::addTask(Task &&task) {
    // if (!_isExit) {
    _taskQueue.push(std::move(task));
    // }
}

ThreadPool::Task ThreadPool::getTask() {
    return _taskQueue.pop();
}

void ThreadPool::threadFunc() {
    while (!_isExit) {
        Task task = getTask();
        if (task) {  // 确保任务不为空
            task();  // 执行任务
            // cout<<"-----1-----"<<endl;
        }else{
            // cout<<"-----4-----"<<endl;
            break;//空任务则退出线程
        }
    }
}

