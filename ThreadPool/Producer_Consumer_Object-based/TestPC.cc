#include <iostream>
#include <memory>
#include <unistd.h>
#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"
#include "Thread.h"

using std::cout;
using std::endl;
using std::unique_ptr;
using std::bind;

void test(){
    TaskQueue taskQueue(10);
    Producer producer;
    Consumer consumer;
    unique_ptr<Thread> pro(new Thread(bind(&Producer::produce,&producer,std::ref(taskQueue))));
    unique_ptr<Thread> con(new Thread(bind(&Consumer::consume,&consumer,std::ref(taskQueue))));
    
    pro->start();
    con->start();

    pro->stop();
    con->stop();

}
int main(){
    test();
    return 0;
}