#include "InetAddr.h"
class Socket{
public:
    Socket(int sockfd):
        sockfd(sockfd)
    {

    };
    void Bind(const InetAddr &localAddr);
    void Listen();
    int Accept(InetAddr *peerAddr);
private:
    const int sockfd;
};