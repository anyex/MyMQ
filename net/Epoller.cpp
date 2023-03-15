#include "Epoller.hpp"
#include "Channel.hpp"
#include <errno.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>

Epoller::Epoller(EventLoop *loop)
    :owerLoop(loop),
    m_epollfd(epoll_create1(EPOLL_CLOEXEC)),
    m_vecEpollEvent(16)
{
    if(m_epollfd < 0)
    {
        LOGE("epoll_create error:%d \n",(errno));
    }
}

bool Epoller::HasChannel(Channel *channel)
{
    if(NULL == channel)
    {
        return false;
    }   
    return channels.find(channel->GetFd()) != channels.end();
}

void Epoller::Poll(std::vector<Channel*> & channels)
{
    int numEvents = epoll_wait(m_epollfd,m_vecEpollEvent.data(),m_vecEpollEvent.size(),-1);
    if(numEvents > 0)
    {
        LOGI("%d event trigger",numEvents);
        UpdateActiveChannel(numEvents,channels);
        if(numEvents == m_vecEpollEvent.size())
        {
            m_vecEpollEvent.resize(m_vecEpollEvent.size() * 2);
        }
    }else if(0 == numEvents)
    {
        LOGD("timeout");
    }else {
        LOGE("Poll  err %s",strerror(errno));
    }
}


void Epoller::UpdateActiveChannel(int numEvents,std::vector<Channel*>& activeChannels)
{
    for (int i = 0; i < numEvents; i++)
    {
        Channel *channel = static_cast<Channel*>(m_vecEpollEvent[i].data.ptr);
        channel->SetRevents(m_vecEpollEvent[i].events);
        activeChannels.push_back(channel);
    }
    
}


void Epoller::ControlChannel(int op,Channel *channel)
{
    epoll_event event;
    bzero(&event,sizeof(event));
    int fd = channel->GetFd();
    event.data.fd = fd;
    event.data.ptr = channel;
    event.events = channel->GetEvents();

    LOGD("contorl channel: events:%d,op:%d",event.events,op);

    if(epoll_ctl(m_epollfd,op,fd,&event) < 0)
    {
        LOGE("epoll ctl op:%d, error:%d",op,errno);
    }
}

