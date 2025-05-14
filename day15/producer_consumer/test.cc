#include<iostream>
#include<memory>
#include"Producer.h"
#include"Consumer.h"
#include"TaskQueue.h"
using namespace std;

void test(){
    TaskQueue taskqueue(10);
    Producer p(taskqueue);
    Consumer c(taskqueue);
    unique_ptr<Thread> upp(new Thread(bind(&Producer::produce,&p)));
    unique_ptr<Thread> upc(new Thread(bind(&Consumer::consume,&c)));
    cout<<"start produce!"<<endl;
    upp->start();
    cout<<"start consume!"<<endl;
    upc->start();

    upp->stop();
    upc->stop();
}
int main(){
    test();
    return 0;
}