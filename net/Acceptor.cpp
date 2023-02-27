#include "Acceptor.hpp"

Acceptor::Acceptor(const InetAddr &addr):
    acceptSocket(addr)
{
       acceptSocket.Bind(addr);
       
}

void Acceptor::Listen()
{
    acceptSocket.Listen();
}