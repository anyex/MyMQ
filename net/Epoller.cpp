#include "Epoller.hpp"
#include "Channel.hpp"
#include <errno.h>
Epoller::Epoller(EventLoop *loop)
    :owerLoop(loop),
    epollfd(epoll_create1(EPOLL_CLOEXEC))
{
    if(epollfd < 0)
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
    int numEvents = epoll_wait(epollfd,events.data(),events.size(),10*100);
    if(numEvents > 0)
    {
        LOGI("%d event trigger",numEvents);
        UpdateActiveChannel(numEvents,channels);
        if(numEvents == events.size())
        {
            events.resize(events.size() * 2);
        }
    }else if(0 == numEvents)
    {
        LOGD("timeout");
    }else {
        LOGE("Poll err");
    }
}


void Epoller::UpdateActiveChannel(int numEvents,std::vector<Channel*>& activeChannels)
{
    for (int i = 0; i < numEvents; i++)
    {
        Channel *channel = static_cast<Channel*>(events[i].data.ptr);
        channel->SetEvents(events[i].events);
        activeChannels.push_back(channel);
    }
    
}
