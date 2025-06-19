#include"Consumer.h"


Consumer::Consumer()
{

}
Consumer::~Consumer(){

}
void Consumer::consume(TaskQueue &taskQueue){
    int cnt = 20;
    while(cnt--){
        int number = taskQueue.pop();
        cout<<"Consumer consume:"<<number<<endl;
        sleep(1);
    }
}