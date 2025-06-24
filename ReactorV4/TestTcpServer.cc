#include "TcpConnection.h"
#include <iostream>
#include <unistd.h>
#include "TcpServer.h"
#include "ThreadPool.h"

using std::cout;
using std::endl;

ThreadPool *gpool;
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

void onNewConnection(const TcpConnectionPtr &conn){
    cout << conn->toString() << " has connected!"<< endl;
}
void onMessage(const TcpConnectionPtr &conn){
    string msg = conn->recive();
    cout<<">>recv client msg = "<< msg;
    //业务逻辑处理
    MyTask task(msg,conn);
    gpool->addTask(std::bind(&MyTask::process,task));
}
void onClose(const TcpConnectionPtr &conn){
    cout << conn->toString() << " has closed!"<< endl;
}

void test(){
    ThreadPool pool(4,10);
    pool.start();
    gpool = &pool;
    TcpServer server("127.0.0.1",8888);
    server.setAllCallback(std::move(onNewConnection),
                          std::move(onMessage),
                          std::move(onClose));
    server.start();
}
int main(){
    test();
    return 0;  
}