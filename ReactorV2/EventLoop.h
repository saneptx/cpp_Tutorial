#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

#include <vector>
#include <map>
#include <memory>
using std::vector;
using std::map;
using std::shared_ptr;

class Acceptor;
class TcpConnection;

class EventLoop{
    using TcpConnectionPtr = shared_ptr<TcpConnection>;
public:
    EventLoop(Acceptor &acceptor);
    ~EventLoop();

    void loop();
    void unloop();
private:
    void waitEpollFd();
    void handleNewConnection();
    void handleMessage(int fd);
    void addEpollReadFd(int fd);
    void delEpollReadFd(int fd);
    int createEpollFd();
private:
    int _epfd;
    vector<struct epoll_event> _evtList;
    bool _isLooping;
    Acceptor &_acceptor;
    map<int,TcpConnectionPtr> _conns;
};

#endif