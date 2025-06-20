#include <iostream>
#include <thread>
#include <unistd.h>
#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"

using std::cout;
using std::endl;
using std::thread;



void test(){

    TaskQueue taskQueue(10);
    Producer producer;
    Consumer consumer;

    thread pro(&Producer::produce,&producer,std::ref(taskQueue));
    thread con(&Consumer::consume,&consumer,std::ref(taskQueue));

    pro.join();
    con.join();

}
int main(){
    test();
    return 0;
}