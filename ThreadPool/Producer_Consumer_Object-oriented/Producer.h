#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include "Thread.h"
#include "TaskQueue.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

class Producer
:public Thread{
public:
    Producer(TaskQueue &taskQueue);
    ~Producer();
    void run() override;
private:
    TaskQueue &_taskQueue;
};

#endif