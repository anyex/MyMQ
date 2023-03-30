#include "Socket.hpp"
#include "../util/Logger/Logger.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
void Socket::Bind(const InetAddr &localAddr)
{
    if (localAddr.GetDomain() == AF_UNIX)
    {
        if (0 != bind(m_sockfd, (sockaddr *)localAddr.GetSockAddr(), sizeof(sockaddr_un)))
        {
            LOGE("bind failed %s", strerror(errno));
        }else{
            LOGD("bind succ");
        }
    }
    else
    {
        if (0 != bind(m_sockfd, (sockaddr *)localAddr.GetSockAddr(), sizeof(sockaddr_in)))
        {
            LOGE("bind failed %s", strerror(errno));
        }else{
            LOGD("bind succ");
        }
    }
}

void Socket::Listen()
{
    if (0 != listen(m_sockfd, 1024))
    {
        LOGE("listen sockfd:%d fail \n", m_sockfd);
    }
}


int Socket::Accept(InetAddr *peerAddr)
{
    sockaddr_u addr;
    socklen_t len = sizeof addr;
    bzero(&addr, sizeof addr);
    int connfd = accept(m_sockfd, (sockaddr*)&addr, &len);
    if (connfd >= 0)
    {
        peerAddr->SetSockAddr(addr);
    }
    return connfd;
}
