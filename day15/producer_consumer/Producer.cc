#include "Producer.h"
#include "TaskQueue.h"
using std::cout;
using std::endl;

Producer::Producer(TaskQueue &taskQueue)
:_taskQueue(taskQueue){
    
}

Producer::~Producer(){

}

void Producer::produce(){
    ::srand(::clock());
    int cnt = 20;
    while(cnt--){
        int number = rand() % 100;
        _taskQueue.push(number);
        cout<<"<<produce "<<number<<endl;
        // sleep(1);
    }
    
}