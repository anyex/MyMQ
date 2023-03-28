#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>


class StreamBuf:public std::streambuf{
public:
   StreamBuf(ssize_t buf_size);
   virtual ~StreamBuf();

   int underflow();
   int overflow(int c=traits_type::eof());
   int sync();

protected:
   virtual ssize_t recv(void *buf,ssize_t len,int flags) = 0;
   virtual ssize_t send(const void *buf,ssize_t len,int flags) = 0;

   const ssize_t m_buf_size;
};





struct middleware_data{
     uint16_t head;
     uint8_t  channel;
     std::bitset<7> reserve;
     std::bitset<1> encryptFlag;
     uint8_t  count;
     uint16_t length;
     std::vector<uint8_t> data;
     uint16_t crc;
     std::stringstream Serial(){
        std::stringstream serial_buffer(std::ios::binary);
        serial_buffer<<head<<channel<<((reserve.to_ulong()&0xef)|(encryptFlag.to_ulong() &0x01));
        serial_buffer<<count<<length;
        for (auto &item:data)
        {
            serial_buffer<<item;
        }
        return serial_buffer;
   
     };
     void Parse(std::stringstream &src)
     {
        src>>head;
        src>>channel;
        src>>reserve;
        src>>encryptFlag;
        src>>count;
        src>>length;
        data.reserve(length);
        src.readsome((char*)data.data(),length);
     };
};

