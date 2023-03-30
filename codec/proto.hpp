#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "stream.hpp"
struct middleware_data :public Message{
public:
     std::string Serial(){
        std::stringstream serial_buffer(std::ios::binary);
        serial_buffer<<head<<channel<<((reserve & 0xef)|(encryptFlag & 0x01));
        serial_buffer<<count<<length;
        for (auto &item:data)
        {
            serial_buffer<<item;
        }
        return serial_buffer.rdbuf()->str();
   
     };
     void Parse()
     {
        std::stringstream src(m_content);
        src>>head;
        src>>channel;
        src>>reserve;
        src>>encryptFlag;
        src>>count;
        src>>length;
        data.reserve(length);
        src.readsome((char*)data.data(),length);
     };
     void SetHead(uint16_t head){
         this->head = head;
     };
     void SetChannel(uint8_t channel)
     {
         this->channel = channel;
     };
     void SetReserve(uint8_t reserve){
         this->reserve = reserve;
     };
     void SetEncryptFlag(uint8_t encryptFlag)
     {
         this->encryptFlag = encryptFlag;
     };
     void SetData(std::vector<uint8_t> data){
         this->data = data;
     };
     void SetCrc(uint16_t crc){
         this->crc = crc;
     }

     uint16_t GetHead(){
         return this->head;
     }

     uint8_t GetChannel()
     {
         return this->channel;
     }

     uint8_t GetReserve()
     {
         return this->reserve;
     }

      uint8_t GetEncryptFlag()
      {
         return this->encryptFlag;
      }

      uint8_t GetCount()
      {
         return this->count;
      }

      std::vector<uint8_t> GetData()
      {
         return this->data;
      }

      uint16_t GetCrc()
      {
         return this->crc;
      }

private:
     uint16_t head;
     uint8_t  channel;
     uint8_t reserve;
     uint8_t encryptFlag;
     uint8_t  count;
     uint16_t length;
     std::vector<uint8_t> data;
     uint16_t crc;
};

struct tbox_data :public Message
{

    void Serial(){
        std::stringstream serial_buffer(std::ios::binary);
        serial_buffer<<head<<length;
        for (auto &item:data)
        {
            serial_buffer<<item;
        }
        m_content = serial_buffer.rdbuf()->str();
   
     };
     void Parse()
     {
        std::stringstream src(m_content);
        src>>head;
        src>>length;
        data.reserve(length);
        src.readsome((char*)data.data(),length);
     };
     uint16_t GetHead()
     {
        return this->head;
     }

     std::vector<uint8_t> GetData()
     {
        return this->data;
     }

     void SetHead(uint16_t head){
      this->head = head;
     };

     void SetData(std::vector<uint8_t> data){
      this->data = data;
     };

private:
   uint16_t head;
   uint8_t length;
   std::vector<uint8_t> data;
};
