#include "InetAddr.hpp"
class Socket{
public:
    Socket(int sockfd):
        sockfd(sockfd)
    {};
    Socket(const InetAddr &localAddr)
    {
        sockfd = socket(localAddr.GetDomain(),SOCK_STREAM |SOCK_NONBLOCK|SOCK_CLOEXEC,0);
    };
    int GetFd(){return sockfd;};
    void Bind(const InetAddr &localAddr);
    void Listen();
    int Accept(InetAddr *peerAddr);
private:
     int sockfd;
};