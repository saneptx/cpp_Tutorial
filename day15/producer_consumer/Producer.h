#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include "Thread.h"
#include <stdlib.h>

class TaskQueue;
class Producer{
public:
    Producer(TaskQueue &taskQueue);
    ~Producer();

    void produce();
private:
    TaskQueue &_taskQueue;
};

#endif