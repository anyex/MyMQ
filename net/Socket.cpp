#include "Socket.hpp"
#include "Logger.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
void Socket::Bind(const InetAddr &localAddr)
{
    if(0 != bind(sockfd, (sockaddr*)localAddr.GetSockAddr(),sizeof(sockaddr_u)))
    {
        LOGE("bind failed %s",strerror(errno));
    }
}

void Socket::Listen()
{
    if (0 != listen(sockfd, 1024))
    {
        LOGE("listen sockfd:%d fail \n", sockfd);
    }
}


int Socket::Accept(InetAddr *peerAddr)
{
    sockaddr_u addr;
    socklen_t len = sizeof addr;
    bzero(&addr, sizeof addr);
    int connfd = accept(sockfd, (sockaddr*)&addr, &len);
    if (connfd >= 0)
    {
        peerAddr->SetSockAddr(addr);
    }
    return connfd;
}