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
    m_acceptChannel.SetReadCallback(std::bind(&Acceptor::HandRead, this));
}

void Acceptor::SetConnectedCallback(std::function<void(int sockfd,const InetAddr &)> &func)
{
    m_newConnCallback = func;
}

void Acceptor::HandRead()
{
    InetAddr peerAddr;
    int connfd = m_acceptSocket.Accept(&peerAddr);
    if (connfd >= 0)
    {
        if (m_newConnCallback)
        {
            m_newConnCallback(connfd, peerAddr);
        }
        else
        {
           // close(connfd);
        }
    }
    else
    {
        LOGE("%s:%s:%d accept err:%d \n", __FILE__, __FUNCTION__, __LINE__, errno);
        if (errno == EMFILE)
        {
            LOGE("%s:%s:%d sockfd reached limit! \n", __FILE__, __FUNCTION__, __LINE__);
        }
    }
}