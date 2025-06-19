#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "Thread.h"
#include "TaskQueue.h"
#include <unistd.h>

class Consumer
:public Thread{
public:
    Consumer(TaskQueue &taskQueue);
    ~Consumer();
    void run() override;
private:
    TaskQueue &_taskQueue;
};

#endif