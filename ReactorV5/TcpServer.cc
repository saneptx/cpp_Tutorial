#include "TcpServer.h"
#include "TcpConnection.h"

TcpServer::TcpServer(const string &ip,unsigned short port,size_t thread_num,size_t queue_size)
:_acceptor(ip,port)
,_loop(_acceptor)
,_pool(thread_num,queue_size){

}
TcpServer::~TcpServer(){

}

void TcpServer::start(){
    _loop.setNewConnectionCallback(std::bind(&TcpServer::onNewConnection,this,std::placeholders::_1));
    _loop.setMessageCallback(std::bind(&TcpServer::onMessage,this,std::placeholders::_1));
    _loop.setCloseCallback(std::bind(&TcpServer::onClose,this,std::placeholders::_1));
    _acceptor.ready();
    _loop.loop();
    _pool.start();
}
void TcpServer::stop(){
    _loop.unloop();
    _pool.stop();
}

void TcpServer::onNewConnection(const TcpConnectionPtr &connPtr){
    cout << connPtr->toString() << " has connected!"<< endl;
}
void TcpServer::onMessage(const TcpConnectionPtr &connPtr){
    string msg = connPtr->recive();
    cout<<">>recv client msg = "<< msg;
    //业务逻辑处理
    MyTask task(msg,connPtr);
    _pool.addTask(std::bind(&MyTask::process,task));
}
void TcpServer::onClose(const TcpConnectionPtr &connPtr){
    cout << connPtr->toString() << " has closed!"<< endl;
}