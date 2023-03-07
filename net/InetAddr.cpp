#include "InetAddr.hpp"
InetAddr::InetAddr(int port,std::string ip)
{
    bzero(&m_addr,sizeof(m_addr));
    sockaddr_in *addr_in =(sockaddr_in*) &m_addr;
    addr_in->sin_family = AF_INET;
    addr_in->sin_port = htons(port);
    addr_in->sin_addr.s_addr = inet_addr(ip.c_str());
    m_domain = AF_INET;
}

InetAddr::InetAddr(std::string path)
{
    bzero(&m_addr,sizeof(m_addr));
    sockaddr_un *addr_un = (sockaddr_un*) &m_addr;
    addr_un->sun_family = AF_UNIX;

    strncpy(addr_un->sun_path,
        path.c_str(),
        std::min(sizeof(addr_un->sun_path),path.length()));
    m_domain = AF_UNIX;
}

const sockaddr * const InetAddr::GetAddr()
{
    return &m_addr.sa;
}
