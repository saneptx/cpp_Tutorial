#ifndef __TCPSERVER_H__
#define __TCPSERVER_H__

#include "Acceptor.h"
#include "EventLoop.h"
#include "ThreadPool.h"
#include "TcpConnection.h"

class MyTask{
public:
    MyTask(const string &msg,TcpConnectionPtr connPtr)
    :_msg(msg)
    ,_connPtr(connPtr){
        
    }
    void process(){
        _connPtr->sendInLoop(_msg);
    }
private:
    string _msg;
    TcpConnectionPtr _connPtr;
};


class TcpServer{
public:
    TcpServer(const string &ip,unsigned short port,size_t thread_num,size_t queue_size);
    ~TcpServer();

    void start();
    void stop();

    void onNewConnection(const TcpConnectionPtr &connPtr);
    void onMessage(const TcpConnectionPtr &connPtr);
    void onClose(const TcpConnectionPtr &connPtr);


private:
    Acceptor _acceptor;
    EventLoop _loop;
    ThreadPool _pool;
};

#endif