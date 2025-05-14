#ifndef __THREAD_H__
#define __THREAD_H__

#include<pthread.h>
#include<errno.h>
#include<stdio.h>
#include<iostream>

class Thread{
private:
    //线程入口函数
    static void *threadFunc(void *arg);
    //抽象任务
    virtual void run() = 0;
private:
    pthread_t _tid;//线程id
    bool _isRunning;
public:
    Thread();
    virtual ~Thread();

    //线程启动
    void start();
    //线程停止
    void stop();
};

#endif