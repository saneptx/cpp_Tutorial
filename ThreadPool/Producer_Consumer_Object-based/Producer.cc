#include"Producer.h"


Producer::Producer(){

}
Producer::~Producer(){

}
void Producer::produce(TaskQueue &taskQueue){
    srand(clock());//种随机种子
    int cnt = 20;
    while(cnt--){
        int number = rand() % 100;//产生随机数
        taskQueue.push(number);
        cout<<"Producer produce:"<<number<<endl;
        sleep(1);
    }
}