#include"Consumer.h"


Consumer::Consumer(TaskQueue &taskQueue)
:_taskQueue(taskQueue){

}
Consumer::~Consumer(){

}
void Consumer::run(){
    int cnt = 20;
    while(cnt--){
        int number = _taskQueue.pop();
        cout<<"Consumer consume:"<<number<<endl;
        sleep(1);
    }
}