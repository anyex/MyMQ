#ifndef INET_ADDR_H_
#define INET_ADDR_H_
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <sys/un.h>

union sockaddr_u
{
  struct sockaddr sa;
  struct sockaddr_in sin;
  struct sockaddr_un sun;
};


class InetAddr{

public:
    InetAddr(int port,std::string ip);
    InetAddr(std::string path);
    InetAddr(){};
    const sockaddr * const GetAddr();
    const sockaddr* GetSockAddr() const {return &m_addr.sa;};
    void SetSockAddr(sockaddr_u addr) {
      this->m_addr = addr;
    };
    const int GetDomain() const{
      return m_domain;
    };
    int GetSockLen(){
      return m_socket_len;
    };
private:
    sockaddr_u m_addr;
    int m_domain;
    int m_socket_len;
};
#endif