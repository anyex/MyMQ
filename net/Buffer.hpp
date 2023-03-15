#ifndef __BUFFER__H_
#define __BUFFER__H_
#include <algorithm>
#include <vector>
#include <string>
#define BUFFER_SIZE 1024
#define CHEAP_PREPEND 8
#include <sys/uio.h>
/*
消息报文采用长度+CONTENT的方式组包

*/

class Buffer{
public:
   Buffer(int initialSize = BUFFER_SIZE):
      m_buffer(CHEAP_PREPEND + initialSize),
      m_readerIndex(CHEAP_PREPEND),
      m_writerIndex(CHEAP_PREPEND)
      {

      };
   int ReadableBytes(){
      return m_writerIndex - m_readerIndex;
   };

   int WriteableBytes()
   {
      return m_buffer.capacity() - m_writerIndex;
   };

   int IsReadable()
   {
      return m_writerIndex > m_readerIndex;
   };

   int IsWriteable()
   {
      return m_buffer.capacity() - m_writerIndex;
   };

   int IsWriteable(int len)
   {
      return m_writerIndex+len < m_buffer.capacity();
   }

   void WriteByte(uint8_t value)
   {
      m_buffer[m_writerIndex++] = value;
   };
   bool Prepend(const char* data,int len)
   {
      if(len + m_readerIndex > CHEAP_PREPEND)
      {
         return false;
      }
      m_readerIndex -= len;
      std::copy(data,data+len,Begin()+m_readerIndex );
      return true;
   }
   bool PrependInt32(int data)
   {
      if(sizeof(data) + m_readerIndex > CHEAP_PREPEND)
      {
         return false;
      }
      m_readerIndex -= sizeof(data);
      std::copy(&data,&data+1,Begin()+m_readerIndex );
      return true;
   }
   bool Append(const char* data,int len)
   {
      if(! IsWriteable(len))
      {
         return false;
      }
      
      std::copy(data,data+len,Begin()+m_writerIndex);
      m_writerIndex += len;

      return true;
   };

   int ReadFd(int fd)
   {
      char extra_buf[65536];
      struct iovec vec[2];
      vec[0].iov_base = Begin() + m_writerIndex;
      vec[0].iov_len = WriteableBytes();
      vec[1].iov_base = extra_buf;
      vec[1].iov_len = sizeof(extra_buf);

      int cnt = readv(fd,vec,2);
      if(cnt < 0 )
      {
      }
      if(cnt <= WriteableBytes())
      {
         m_writerIndex += cnt;
      }else{
         m_writerIndex = m_buffer.size();
         Append(extra_buf,cnt-WriteableBytes());
      }

      return cnt;
   };
   int ReadInt32()
   {
      int ret = *(int*)Begin()+m_readerIndex;
      m_readerIndex += 4;
      return ret;
   }
   char *ReadData(int len)
   {
      char *data = Begin()+m_readerIndex;
      m_readerIndex += len;
      return data;
   }
   std::string SerialString()
   {
      return  std::string(Begin()+m_readerIndex,ReadableBytes());
   }
private:
   char* Begin(){
      return m_buffer.data();
   };

   int m_readerIndex;
   int m_writerIndex;
   std::vector<char> m_buffer;
   // void WriteRawVarint32(std::string &out,int value);
   // int ComputeRawVarint32Size(int value);
   // int ReadRawVarint32(std::string &buffer);
};

#endif