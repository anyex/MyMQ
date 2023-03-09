#include "InetAddr.hpp"
#include "Socket.hpp"
#include "Channel.hpp"
class Acceptor{
public:
    Acceptor(const InetAddr &addr,EventLoop* loop);
    void Listen();
    void HandRead();
    void SetConnectedCallback(std::function<void(int sockfd,const InetAddr &)> &func);
private:
    Socket m_acceptSocket;
    Channel m_acceptChannel;
    EventLoop *m_ploop;
    std::function<void(int sockfd,const InetAddr &)> m_newConnCallback;
};