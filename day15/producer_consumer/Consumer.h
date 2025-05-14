#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "Thread.h"
#include <stdlib.h>

class TaskQueue;
class Consumer{
public:
    Consumer(TaskQueue &taskQueue);
    ~Consumer();

    void consume();
private:
    TaskQueue &_taskQueue;
};

#endif