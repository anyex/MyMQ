#include "Acceptor.hpp"

Acceptor::Acceptor(const InetAddr &addr):
    acceptSocket(addr)
{
       
}

void Acceptor::Listen()
{
    acceptSocket.Listen();
}