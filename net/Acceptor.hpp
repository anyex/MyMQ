#include "InetAddr.hpp"
#include "Socket.hpp"
#include "Channel.hpp"
class Acceptor{
public:
    Acceptor(const InetAddr &addr);
    void Listen();
private:
    Socket acceptSocket;
    Channel acceptChannel;
    EventLoop *loop;
};