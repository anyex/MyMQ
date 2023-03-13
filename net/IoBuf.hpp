#include <sstream>

class IoBuf{
public:
    IoBuf(int fd):m_fd(fd){  
    };
    void Clear(){
        m_stream.clear();
    };
    ssize_t ReadableBytes()
    {
       return m_stream.gcount();
    }
    int16_t ReadInt16()
    {
        int16_t data;
        m_stream>>data;
        return data;
    }
private:
    std::stringstream m_stream;
    int m_fd;
};