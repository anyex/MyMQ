#include "Connection.hpp"

Connection::Connection(EventLoop *loop,
        const std::string &name,
        int sockfd)
    :m_pLoop(m_pLoop),m_sName(name),
    m_pSocket(new Socket(sockfd)),
    m_pChannel(new Channel(m_pLoop,sockfd))
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