#ifndef __STREAM__H_
#define __STREAM__H_
#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <memory>
enum MESSAGE_TYPE{
    SUBCRIBER,//订阅
    UNSUBCRIBR,//取消订阅
    HEART,//心跳
    EVENT,//事件
    REQUEST,//请求
    RESPONSE,//响应
};

class Message{
public:
    Message(){

    };
    virtual std::string  SerialAsString(){

    };
    virtual void Parse(){

    };
    std::string &Intances(){
      return m_content;
    }
    std::string SerialPacket(){
         std::stringstream packet();
    };

protected:
    MESSAGE_TYPE m_type;
    std::string m_content;
};

class StreamBuf:public std::streambuf{
public:
   StreamBuf(int socketfd,ssize_t buf_size = 1024);
   virtual ~StreamBuf();

   int underflow();
   int overflow(int c=traits_type::eof());
   int sync();   
   
protected:
   virtual ssize_t grecv(void *buf,ssize_t len,int flags) ;
   virtual ssize_t psend(const void *buf,ssize_t len,int flags);
   
   ssize_t m_buf_size;
   int m_socket_fd;
};

class SocketStream :public std::iostream{
   public:
      SocketStream(int sockfd,ssize_t size = 1024);
      std::ostream & operator<<(std::shared_ptr<Message> msg){
         *this<< msg->Intances();
         return *this;
      };
      std::istream & operator >>(std::shared_ptr<Message> msg){
          *this>> msg->Intances();
         return *this;
      };
      virtual ~SocketStream();
   protected:
      ssize_t m_buf_size;
      int m_socket_fd;
};



#endif