#include "Acceptor.h"
#include "TcpConnection.h"
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;

void test(){
    Acceptor acceptor("127.0.0.1",8888);
    acceptor.ready();//此时属于监听状态

    TcpConnection conn(acceptor.accept());
    cout << conn.toString() << " has connected" <<endl;
    while(1){
        cout<<">>recv msg from clent:"<<conn.recive()<<endl;
        conn.send("hello baby\n");
    }
}
int main(){
    test();
    return 0;  
}