#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include "TaskQueue.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

class Producer
{
public:
    Producer();
    ~Producer();
    void produce(TaskQueue &taskQueue);
};

#endif