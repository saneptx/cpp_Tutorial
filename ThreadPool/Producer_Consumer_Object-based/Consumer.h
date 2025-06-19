#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "TaskQueue.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

class Consumer
{
public:
    Consumer();
    ~Consumer();
    void consume(TaskQueue &taskQueue);
};

#endif