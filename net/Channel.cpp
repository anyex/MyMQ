#include "Channel.hpp"
#include "Epoller.hpp"
#include "EventLoop.hpp"
Channel::Channel()
{
    
}

Channel::Channel(EventLoop *loop,int fd):
    m_pLoop(loop),
    m_fd(fd),
    m_events(0),
    m_revents(0)
{
    
}

void Channel::HandleEvent()
{
    if((m_revents & EPOLLHUP) && !(m_revents &EPOLLIN))
    {
        LOGD("关闭连接");
        m_close_func();
    }
    
    if(m_revents & EPOLLERR)
    {
        LOGD("epoll err");
        m_error_func();
    }

    if(m_revents &(EPOLLIN |EPOLLPRI))
    {
        LOGD("有数据可读");
        m_read_func();
    }

    if(m_revents & EPOLLOUT)
    {
        LOGD("有数据可写");
        m_write_func();
    }

}


void Channel::UpDateEvent()
{
    m_pLoop->UpDateChannel(this);

}

Channel::~Channel()
{

}