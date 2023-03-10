#include "Connection.hpp"

Connection::Connection(EventLoop *loop,
        int sockfd)
    :m_pLoop(loop),
    m_pSocket(new Socket(sockfd)),
    m_pChannel(new Channel(m_pLoop,sockfd))
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
   int cnt = m_input.ReadFd(m_pSocket->GetFd());
   int len = m_input.ReadInt32();
  
   LOGD("接收到数据:%d,内容:%s",cnt,m_input.SerialString().c_str());
 }