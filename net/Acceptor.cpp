#include "Acceptor.hpp"

Acceptor::Acceptor(const InetAddr &addr,EventLoop* loop):
    acceptSocket(addr),
    acceptChannel(loop,acceptSocket.GetFd()),
    loop(loop)
{
       acceptSocket.Bind(addr);
       
}

void Acceptor::Listen()
{
    acceptSocket.Listen();
    acceptChannel.EnableRead();
}