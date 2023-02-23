#include "InetAddr.h"
#include "Socket.h"
class Acceptor{
public:
    Acceptor(const InetAddr &addr);
    void Listen();
private:
    Socket acceptSocket;
};