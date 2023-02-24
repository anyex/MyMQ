#include "InetAddr.hpp"
#include "Socket.hpp"
class Acceptor{
public:
    Acceptor(const InetAddr &addr);
    void Listen();
private:
    Socket acceptSocket;
};