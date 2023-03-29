#include "Connection.hpp"
#include "../codec/stream.hpp"
Connection::Connection(EventLoop *loop,
        int sockfd)
    :m_pLoop(loop),
    m_pSocket(new Socket(sockfd)),
    m_pChannel(new Channel(m_pLoop,sockfd)),
    m_stream(sockfd)
{
   m_pChannel->SetReadCallback(std::bind(&Connection::HandleRead,this));
   m_pChannel->EnableRead();
};

 void Connection::Send(const std::string &buf)
 {
    LOGD("Connection Send :%s",buf);
 }

 bool Connection::Connected()
 {
    return true;
 }

 void Connection::HandleRead()
 {
   Message msg;
   m_stream>>msg;
 }