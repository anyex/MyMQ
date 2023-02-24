#include "InetAddr.hpp"
#include <strings.h>
InetAddr::InetAddr(int port,std::string ip)
{
    bzero(&addr,sizeof(addr));
    sockaddr_in *addr_in =(sockaddr_in*) &addr;
    addr_in->sin_family = AF_INET;
    addr_in->sin_port = htons(port);
    addr_in->sin_addr.s_addr = inet_addr(ip.c_str());
    domain = AF_INET;
}

InetAddr::InetAddr(std::string path)
{
    bzero(&addr,sizeof(addr));
    sockaddr_un *addr_un = (sockaddr_un*) &addr;
    addr_un->sun_family = AF_UNIX;

    strncpy(addr_un->sun_path,
        path.c_str(),
        std::min(sizeof(addr_un->sun_path),path.length()));
    domain = AF_UNIX;
}

const sockaddr * const InetAddr::GetAddr()
{
    return &addr.sa;
}
