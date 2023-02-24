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
    const sockaddr * const GetAddr();
    const sockaddr* GetSockAddr() const {return &addr.sa;};
    void SetSockAddr(sockaddr_u addr) {
      this->addr = addr;
    };
    const int GetDomain() const{
      return domain;
    };
private:
    sockaddr_u addr;
    int domain;
};
#endif