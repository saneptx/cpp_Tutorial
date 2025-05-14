#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__
#include "MutexLock.h"
#include "Condition.h"
#include <queue>
using std::queue;

class TaskQueue{
public:
    TaskQueue(size_t queSize);
    ~TaskQueue();
    void push(const int &value);
    int pop();
    bool full() const;
    bool empty() const;
private:
    size_t _queSize;
    queue<int> _queue;
    MutexLock _mutex;
    Condition _notFull;//非满
    Condition _notEmpty;//非空
};

#endif