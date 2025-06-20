#include "ThreadPool.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <functional>

using std::cout;
using std::endl;
using std::bind;

class MyTask
{
public:
    void process(){
        srand(clock());//种随机种子
        int number = rand() % 100;//产生随机数
        cout<<"MyTask produce:"<<number<<endl;
    }
};
void test(){
    MyTask task;
    int cnt = 20;
    ThreadPool pool(4,10);
    pool.start();
    while(cnt--){
        //添加任务
        pool.addTask(bind(&MyTask::process,&task));
        cout<<"cnt="<<cnt<<endl;
    }
    pool.stop();
}
int main(){
    test();
}