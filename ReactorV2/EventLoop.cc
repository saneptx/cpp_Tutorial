#include "EventLoop.h"
#include <sys/epoll.h>
#include "Acceptor.h"
#include <unistd.h>
#include <iostream>
#include "TcpConnection.h"

using std::cout;
using std::endl;
using std::cerr;

EventLoop::EventLoop(Acceptor &acceptor)
:_epfd(createEpollFd())
,_evtList(1024)
,_isLooping(false)
,_acceptor(acceptor)
,_conns()
{
    int listenfd = acceptor.fd();
    addEpollReadFd(listenfd);
}
EventLoop::~EventLoop(){
    close(_epfd);
}

void EventLoop::loop(){
    _isLooping = true;
    while(_isLooping){
        waitEpollFd();
    }
}
void EventLoop::unloop(){
    _isLooping = false;
}

void EventLoop::waitEpollFd(){

    int nready = 0;
    do{
        nready = epoll_wait(_epfd,&*_evtList.begin(),_evtList.size(),3000);
    }while(-1 == nready && errno == EINTR);
    if(-1 == nready){
        cerr<<"-1 == nready" <<endl;
        return; 
    }else if(0 == nready){
        cout<<">>epoll_wait timeout"<<endl;
    }else{
        //判断一下文件描述符是不是到1024了
        //如果达到1024就需要扩容
        if(nready == (int)_evtList.size()){
            _evtList.reserve(2 * nready);
        }
        for(int idx = 0;idx < nready; ++idx){
            int fd = _evtList[idx].data.fd;
            if(fd == _acceptor.fd()){
                if(_evtList[idx].events & EPOLLIN){
                    handleNewConnection();
                }
            }else{
                if(_evtList[idx].events & EPOLLIN){
                    handleMessage(fd);
                }
            }
        }
    }
}
void EventLoop::handleNewConnection(){
    int connfd = _acceptor.accept();
    if(connfd < 0){
        perror("handleNewConnection accpet");
        return;
    }
    TcpConnectionPtr connPtr(new TcpConnection(connfd));
    connPtr->toString();
    _conns[connfd] = connPtr;
    addEpollReadFd(connfd);
}
void EventLoop::handleMessage(int fd){
    auto it = _conns.find(fd);
    if(it != _conns.end()){
        //连接存在可以进行收发消息

    }else{
        //连接不存在，直接让程序退出
    }
}
int EventLoop::createEpollFd(){
    int fd = ::epoll_create1(0);
    if(fd < 0){
        perror("epoll_create");
        return fd;
    }
    return fd;
}
void EventLoop::addEpollReadFd(int fd){
    struct  epoll_event evt;
    evt.events = EPOLLIN | EPOLLOUT;
    evt.data.fd = fd;
    
    int ret = ::epoll_ctl(_epfd,EPOLL_CTL_ADD,fd,&evt);
    if(ret < 0){
        perror("epoll_ctl_add");
        return;
    }
    
}
void EventLoop::delEpollReadFd(int fd){
    struct  epoll_event evt;
    evt.data.fd = fd;
    
    int ret = ::epoll_ctl(_epfd,EPOLL_CTL_DEL,fd,&evt);
    if(ret < 0){
        perror("epoll_ctl_del");
        return;
    }
}