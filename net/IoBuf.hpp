#include <sstream>
#include "../util/Logger/Logger.hpp"
class IoBuf{
public:
    IoBuf(int fd):m_fd(fd),
    m_stream(std::ios::binary)
    {  
    };
    void Clear(){
        m_stream.clear();
    };

    template <typename T> 
    bool ReadBytes(T &data)
    {
        if(m_stream.gcount()< sizeof(data))
        {
            return false;
        }
        m_stream >> data;
        return true;
    }

    template <typename T>
    bool AppendBytes(T data)
    {
        m_stream << data;
        return m_stream.good();
    };

    template <typename T>
    bool Prepend(T data)
    {
        std::stringstream head(data);
        head<<m_stream.rdbuf();
        if (head.good())
        {
          m_stream = std::move(head);
        }
        return m_stream.good() && head.good();
    }

    std::string SerialString()
    {
        std::string result;
        m_stream >> result;
        return result;
    }

    int RecvFd()
    {
        char extrabuf[65536] = {0};
        int nret = read(m_fd,extrabuf,sizeof(extrabuf));
        if(nret < 0)
        {
            LOGE("read fd:%d,failed:%s",m_fd,strerror(nret));
        }else{
            m_stream<<extrabuf;
        }
        return nret;
    }
private:
    std::stringstream m_stream;
    int m_fd;
};