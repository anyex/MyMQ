#include "Server.hpp"

Server::Server(std::string name,const InetAddr &addr):acceptor(addr,&loop)
{
    
}

void Server::Start()
{
    acceptor.Listen();
    loop.Loop();
}