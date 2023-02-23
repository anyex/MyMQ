#include "InetAddr.h"
class Socket{
public:
    Socket(int sockfd):
        sockfd(sockfd)
    {};
    Socket(const InetAddr &localAddr)
    {
        sockfd = socket(localAddr.GetDomain(),SOCK_STREAM |SOCK_NONBLOCK|SOCK_CLOEXEC,0);
    };
    void Bind(const InetAddr &localAddr);
    void Listen();
    int Accept(InetAddr *peerAddr);
private:
     int sockfd;
};