#include "InetAddr.hpp"
#include "Socket.hpp"
#include "Channel.hpp"
class Acceptor{
public:
    Acceptor(const InetAddr &addr,EventLoop* loop);
    void Listen();
    
private:
    Socket m_acceptSocket;
    Channel m_acceptChannel;
    EventLoop *m_ploop;
};