#ifndef __TIMEFD_H__
#define __TIMEFD_H__

#include <functional>
using std::function;
using std::bind;

class TimerFd{
    using TimerFdCallback = function<void()>;
public:
    TimerFd(TimerFdCallback &&cb,int initSec, int peridocSec);
    ~TimerFd();

    void start();
    void stop();
private:
    void handleRead();
    int createTimerFd();
    void setTimer(int initSec, int peridocSec);
private:
    int _tfd;
    TimerFdCallback _cb;
    bool _isStarted;
    int _initSec;
    int _peridocSec;
};



#endif