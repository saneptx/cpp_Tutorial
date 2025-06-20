#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__


#include <queue>
#include <functional>
#include "MutexLock.h"
#include "Condition.h"
using std::queue;
using std::function;


using ElemType = function<void()>;
class TaskQueue{
public:
    TaskQueue(size_t queueSize);
    ~TaskQueue();
    void push(ElemType &&task);//添加任务
    ElemType pop();//获取任务

    bool isFull() const;//判满
    bool isEmpty() const;//判空
    void wakeUp();//唤醒所有等待在notEmpty的线程
private:
    size_t _queueSize;//任务队列大小
    queue<ElemType> _queue;//任务队列
    MutexLock _mutex;//互斥锁
    Condition _notFull;//非满条件变量
    Condition _notEmpty;//非空条件变量
    bool _notExit;
};

#endif