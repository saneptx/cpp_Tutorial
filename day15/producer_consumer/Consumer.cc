#include "Consumer.h"
#include "TaskQueue.h"
using std::cout;
using std::endl;

Consumer::Consumer(TaskQueue &taskQueue)
:_taskQueue(taskQueue){
    
}

Consumer::~Consumer(){

}

void Consumer::consume(){
    int cnt = 20;
    while(cnt--){
        int number = _taskQueue.pop();
        cout<<">>consume "<<number<<endl;
        // sleep(1);
    }
}