#include"Producer.h"


Producer::Producer(TaskQueue &taskQueue)
:_taskQueue(taskQueue){

}
Producer::~Producer(){

}
void Producer::run(){
    srand(clock());//种随机种子
    int cnt = 20;
    while(cnt--){
        int number = rand() % 100;//产生随机数
        _taskQueue.push(number);
        cout<<"Producer produce:"<<number<<endl;
        sleep(1);
    }
}