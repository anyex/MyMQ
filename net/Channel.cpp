#include "Channel.hpp"
#include "Epoller.hpp"
#include "EventLoop.hpp"
Channel::Channel()
{
    
}

Channel::Channel(EventLoop *loop,int fd):m_pLoop(loop),m_fd(fd)
{

}

void Channel::HandleEvent()
{
    if((m_revents & EPOLLHUP) && !(m_revents &EPOLLIN))
    {
        LOGD("关闭连接");
    }
    
    if(m_revents & EPOLLERR)
    {
        LOGD("epoll err");
    }

    if(m_revents &(EPOLLIN |EPOLLPRI))
    {
        LOGD("有数据可读");
    }

    if(m_revents & EPOLLOUT)
    {
        LOGD("有数据可写");
    }

}


void Channel::UpDateEvent()
{
    m_pLoop->UpDateChannel(this);

}

Channel::~Channel()
{

}