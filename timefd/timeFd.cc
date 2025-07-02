#include "timeFd.h"
#include <unistd.h>
#include <poll.h>
#include <stdio.h>
#include <sys/timerfd.h>
#include <iostream>

using std::cout;
using std::endl;

TimerFd::TimerFd(TimerFdCallback &&cb,int initSec, int peridocSec)
:_tfd(createTimerFd())
,_cb(std::move(cb))
,_isStarted(false)
,_initSec(initSec)
,_peridocSec(peridocSec)
{
}
TimerFd::~TimerFd(){
    close(_tfd);
}

void TimerFd::start(){
    struct  pollfd pfd;
    pfd.fd = _tfd;
    pfd.events = POLLIN;

    setTimer(_initSec,_peridocSec);
    _isStarted = true;
    while(_isStarted){
        int nready = poll(&pfd,1,3000);
        if(-1 == nready && errno == EINTR){
            continue;
        }else if(-1 == nready){
            perror("-1 == nready");
            return;
        }else if(0 == nready){
            cout<< ">>poll time_out!!!"<<endl;
        }else{
            if(pfd.revents & POLLIN){
                handleRead();
                if(_cb){
                    _cb();
                }
            }
        }
    }
    
}
void TimerFd::stop(){
    if(_isStarted){
        _isStarted = false;
        setTimer(0,0);
    }
}

void TimerFd::handleRead(){
    uint64_t one;
    ssize_t ret = read(_tfd,&one,sizeof(uint64_t));
    if(ret != sizeof(uint64_t)){
        perror("read");
        return;
    }
}
int TimerFd::createTimerFd(){
    int fd = timerfd_create(CLOCK_REALTIME,0);
    if(fd < 0){
        perror("timerfd_create");
    }
    return fd;
}
void TimerFd::setTimer(int initSec, int peridocSec){
    struct itimerspec value;
    value.it_value.tv_sec = initSec;
    value.it_value.tv_nsec = 0;

    value.it_interval.tv_sec = _peridocSec;
    value.it_interval.tv_nsec = 0;

    int ret = timerfd_settime( _tfd, 0, &value, nullptr);
    if(ret){
        perror("timerfd_settime");
        return;
    }
    
}