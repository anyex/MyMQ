#include "Connection.hpp"

Connection::Connection(EventLoop *loop,
        int sockfd)
    :m_pLoop(m_pLoop),
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
   LOGD("new conntion ");
    return true;
 }