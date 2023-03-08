#ifndef SOCKET_H_
#define SOCKET_H_
#include "InetAddr.hpp"
class Socket{
public:
    Socket(int sockfd):
        m_sockfd(sockfd)
    {};
    Socket(const InetAddr &localAddr)
    {
        m_sockfd = socket(localAddr.GetDomain(),SOCK_STREAM |SOCK_NONBLOCK|SOCK_CLOEXEC,0);
    };
    int GetFd(){return m_sockfd;};
    void Bind(const InetAddr &localAddr);
    void Listen();
    int Accept(InetAddr *peerAddr);
private:
     int m_sockfd;
};

#endif
