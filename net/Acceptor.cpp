#include "Acceptor.hpp"

Acceptor::Acceptor(const InetAddr &addr,EventLoop* loop):
    m_acceptSocket(addr),
    m_acceptChannel(loop,m_acceptSocket.GetFd()),
    m_ploop(loop)
{
       m_acceptSocket.Bind(addr);
       
}

void Acceptor::Listen()
{
    m_acceptSocket.Listen();
    m_acceptChannel.EnableRead();
}

void Acceptor::SetConnectedCallback(std::function<void(int sockfd,const InetAddr &)> &func)
{
    m_newConnCallback = func;
}
