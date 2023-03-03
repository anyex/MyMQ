#include "Channel.hpp"
#include "Epoller.hpp"
#include "EventLoop.hpp"
Channel::Channel()
{
    
}

Channel::Channel(EventLoop *loop,int fd):loop(loop),fd(fd)
{

}

void Channel::HandleEvent()
{
    if((revents & EPOLLHUP) && !(revents &EPOLLIN))
    {
        LOGD("关闭连接");
    }
    
    if(revents & EPOLLERR)
    {
        LOGD("epoll err");
    }

    if(revents &(EPOLLIN |EPOLLPRI))
    {
        LOGD("有数据可读");
    }

    if(revents & EPOLLOUT)
    {
        LOGD("有数据可写");
    }

}


void Channel::UpDateEvent()
{
    loop->UpDateChannel(this);

}

Channel::~Channel()
{

}