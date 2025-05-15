#include "ThreadPool.h"
#include <iostream>
#include <functional>
#include <unistd.h>

using std::cout;
using std::endl;
using std::bind;

// 模拟一个耗时的任务
void taskFunc(int taskId) {
    cout << "Task " << taskId << " is running in thread " 
         << pthread_self() << endl;
    
    // 模拟工作负载
    // sleep(1);
    
    cout << "Task " << taskId << " finished" << endl;
}

int main() {
    // 创建一个有4个线程的线程池，任务队列大小为10
    ThreadPool threadPool(4, 10);
    
    // 启动线程池
    threadPool.start();//此时四个工作线程都在条件变量上阻塞
    cout << "Thread pool started" << endl;
    
    // 添加一些任务
    for (int i = 0; i < 10; ++i) {
        threadPool.addTask(bind(taskFunc, i));
        cout << "Added task " << i << endl;
    }
    
    // 等待一段时间让任务执行
    // sleep(10);
    
    // 停止线程池
    threadPool.stop();
    cout << "Thread pool stopped" << endl;
    
    return 0;
} 