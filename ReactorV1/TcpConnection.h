#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__

#include "Socket.h"
#include "SocketIO.h"
#include "InetAddress.h"

class TcpConnection{
public:
    explicit TcpConnection(int fd);
    ~TcpConnection();
    void send(const string &msg);
    string recive();
    string toString();
private:
    InetAddress getLocalAddr();
    InetAddress getPeerAddr();
private:
    SocketIO _sockIO;
    Socket _sock;
    InetAddress _localAddr;
    InetAddress _peerAddr;
};


#endif