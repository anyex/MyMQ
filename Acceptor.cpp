#include "Acceptor.h"

Acceptor::Acceptor(const InetAddr &addr):
    acceptSocket(addr)
{
       
}

void Acceptor::Listen()
{
    acceptSocket.Listen();
}