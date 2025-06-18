#ifndef __THREAD_H__
#define __THREAD_H__
#include <pthread.h>
#include <stdio.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;


class Thread{
    using ThreadCallback = function<void()>;
public:
    Thread(ThreadCallback &&cb);
    ~Thread();

    void start();//线程启动
    void stop();//线程停止
private:
    static void *threadFunc(void* arg);//线程入口函数,为了消除this指针问题要设置成静态函数

private:
    pthread_t _tid;//线程id
    bool _isRunning;//标识是否运行
    ThreadCallback _cb;
};

#endif