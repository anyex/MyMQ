#include "Connection.hpp"

Connection::Connection(EventLoop *loop,
        const std::string &name,
        int sockfd)
    :loop(loop),name(name),
    socket(new Socket(sockfd)),
    channel(new Channel(loop,sockfd))
{

};

 void Connection::Send(const std::string &buf)
 {
    LOGD("Connection Send :%s",buf);
 }

 bool Connection::Connected()
 {
    return true;
 }