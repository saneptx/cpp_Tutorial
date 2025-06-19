#include <iostream>
#include <memory>
#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"

using std::cout;
using std::endl;
using std::unique_ptr;

void test(){
    TaskQueue taskQueue(10);
    unique_ptr<Thread> producer(new Producer(taskQueue));
    unique_ptr<Thread> consumer(new Consumer(taskQueue));
    
    producer->start();
    consumer->start();

    producer->stop();
    consumer->stop();

}
int main(){
    test();
    return 0;
}