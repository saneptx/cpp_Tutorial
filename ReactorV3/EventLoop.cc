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
    addEpollReadFd(connfd);
    TcpConnectionPtr connPtr(new TcpConnection(connfd));
    connPtr->setNewConnectionCallback(_onNewConnectionCb);
    connPtr->setMessageCallback(_onMessageCb);
    connPtr->setCloseCallback(_onCloseCb);
    connPtr->toString();
    _conns[connfd] = connPtr;
    connPtr->handleNewConnectionCallback();
}
void EventLoop::handleMessage(int fd){
    auto it = _conns.find(fd);
    if(it != _conns.end()){
        //连接存在可以进行收发消息
        bool flag = it->second->isClosed();
        if(flag){
            it->second->handleCloseCallback();
            delEpollReadFd(fd);//断开连接后删除监听
            _conns.erase(it);
        }else{
            it->second->handleMessageCallback();
        }
    }else{
        //连接不存在，直接让程序退出
        cout<<"连接不存在！"<<endl;
        return;
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
    evt.events = EPOLLIN;
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

void EventLoop::setNewConnectionCallback(TcpConnectionCallback &&cb){
    _onNewConnectionCb = std::move(cb);
}
void EventLoop::setMessageCallback(TcpConnectionCallback &&cb){
    _onMessageCb = std::move(cb);
}
void EventLoop::setCloseCallback(TcpConnectionCallback &&cb){
    _onCloseCb = std::move(cb);
}