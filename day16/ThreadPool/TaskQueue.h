#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__
#include "MutexLock.h"
#include "Condition.h"
#include <queue>
#include <functional>
using std::queue;
using std::function;

class TaskQueue{
public:
    using Task = function<void()>;  // 将任务类型改为函数对象
    TaskQueue(size_t queSize);
    ~TaskQueue();
    void push(const Task &task);  // 修改为接受任务类型
    Task pop();  // 修改为返回任务类型
    bool full() const;
    bool empty() const;
    // void wakeUpALL();
private:
    size_t _queSize;
    queue<Task> _queue;  // 修改队列存储的类型
    MutexLock _mutex;
    Condition _notFull;//非满
    Condition _notEmpty;//非空
};

#endif