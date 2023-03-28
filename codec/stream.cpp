#include "stream.hpp"
#include "../util/Logger/Logger.hpp"
StreamBuf::StreamBuf(int socketfd,ssize_t buf_size):m_socket_fd(socketfd),m_buf_size(buf_size)
{
    char *gbuf = new char[m_buf_size];
    char *pbuf = new char[m_buf_size];

    setg(gbuf, gbuf, gbuf);
    setp(pbuf, pbuf+m_buf_size);

}

StreamBuf::~StreamBuf()
{
    delete[] eback();
    delete[] pbase();
 }


//从源读取数据到内部缓冲区
int StreamBuf::underflow()
{
    int count = grecv(eback(), m_buf_size, 0);
    if (count > 0)
    {
        setg(eback(), eback(), eback() + count);
        return traits_type::to_int_type(*gptr());
    }
    else
    {
        return traits_type::eof();
    }
}

int StreamBuf::sync()
{
    int send_cnt = 0;
    int total_flushed = pptr() - pbase();
    while(send_cnt < total_flushed)
    {
        int vRet = psend(pbase()+send_cnt,total_flushed - send_cnt,0);
        if(vRet > 0)
        {
            send_cnt += vRet;
        }else{
            return -1;
        }
    }
    setp(pbase(),pbase()+m_buf_size);
    pbump(0);

    return 0;
}
int StreamBuf::overflow(int c)
{
    if( 0 < sync())
    {
        return traits_type::eof();
    }else{
        if(!traits_type::eq_int_type(c,traits_type::eof()))
        {   
            sputc(traits_type::to_char_type(c));
        }
        return traits_type::not_eof(c);
    }

}

 ssize_t StreamBuf::grecv(void *buf,ssize_t len,int flags) 
 {
    return read(m_socket_fd,buf,len);

 }
 ssize_t StreamBuf::psend(const void *buf,ssize_t len,int flags)
 {
    return write(m_socket_fd,buf,len);
 }

std::streamsize StreamBuf::xsputn(const char* s,std::streamsize n)
{
    return psend(s,n,0);
}

 std::streamsize StreamBuf::xsgetn(char* s, std::streamsize n)
 {
    return grecv(eback(), m_buf_size, 0);
 }


SocketStream::SocketStream(int sockfd,ssize_t size):
    std::iostream(new StreamBuf(sockfd,size)),
    m_socket_fd(sockfd),
    m_buf_size(size)
{

}

SocketStream::~SocketStream()
{

}