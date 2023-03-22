#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>
class PacketStreambuf:public std::streambuf{
    public:
        PacketStreambuf(std::size_t size=128):m_size(size){
            m_gbuf.resize(size);
            m_pbuf.resize(size);

            setg(m_gbuf.data(),m_gbuf.data(),m_gbuf.data());
            setp(m_pbuf.data(),m_pbuf.end().base());
            
        };
        virtual ~PacketStreambuf()
        {
            
        };

        int underflow(){
          
        };
        int overflow(){

        };
        int sync(){

        };
    private:
        std::size_t m_size;
        std::vector<char> m_gbuf;
        std::vector<char> m_pbuf;
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

