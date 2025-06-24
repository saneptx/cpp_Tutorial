#include <iostream>
#include "TcpServer.h"



void test(){
    TcpServer server("127.0.0.1",8888,4,10);
    server.start();
}
int main(){
    test();
    return 0;   

}