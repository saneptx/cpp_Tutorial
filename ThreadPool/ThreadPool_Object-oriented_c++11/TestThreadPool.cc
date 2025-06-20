#include "Task.h"
#include "ThreadPool.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;

class MyTask
:public Task
{
public:
    void process() override{
        srand(clock());//种随机种子
        int number = rand() % 100;//产生随机数
        cout<<"MyTask produce:"<<number<<endl;
    }
};
void test(){
    int cnt = 20;
    ThreadPool pool(4,10);
    pool.start();
    while(cnt--){
        //添加任务
        pool.addTask(new MyTask());
        cout<<"cnt="<<cnt<<endl;
    }
    pool.stop();
}
int main(){
    test();
}