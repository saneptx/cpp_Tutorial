#ifndef __THREAD_H__
#define __THREAD_H__

#include<pthread.h>
#include<errno.h>
#include<stdio.h>
#include<iostream>
#include<functional>
using std::function;


class Thread{
    using ThreadCallback = function<void()>;
private:
    //线程入口函数
    static void *threadFunc(void *arg);
private:
    pthread_t _tid;//线程id
    bool _isRunning;
    ThreadCallback _cb; 
public:
    Thread(ThreadCallback &&cb);
    ~Thread();
    //线程启动
    void start();
    //线程停止
    void stop();
};

#endif