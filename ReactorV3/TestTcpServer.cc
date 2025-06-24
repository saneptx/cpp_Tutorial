#include "TcpConnection.h"
#include <iostream>
#include <unistd.h>
#include "TcpServer.h"

using std::cout;
using std::endl;

void onNewConnection(const TcpConnectionPtr &conn){
    cout << conn->toString() << " has connected!"<< endl;
}
void onMessage(const TcpConnectionPtr &conn){
    string msg = conn->recive();
    cout<<">>recv client msg = "<< msg;
    //业务逻辑处理
    conn->send(msg);
}
void onClose(const TcpConnectionPtr &conn){
    cout << conn->toString() << " has closed!"<< endl;
}

void test(){
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