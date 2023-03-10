#include "EventLoop.hpp"
#include "Epoller.hpp"
#include "Channel.hpp"
#include <sys/prctl.h>
EventLoop::EventLoop(std::string name):
    m_pEpoller(new Epoller(this)),
    m_shutdown(false),
    m_sName(name)
{

}

EventLoop::~EventLoop()
{

}

void EventLoop::HandleRead()
{
    
}

void EventLoop::Loop()
{
    prctl(PR_SET_NAME,m_sName.c_str());
    
    while (!m_shutdown)
    {
        m_vecActiveChannels.clear();
        m_pEpoller->Poll(m_vecActiveChannels);
        for (Channel* channel : m_vecActiveChannels)
        {
           channel->HandleEvent();
        }
    }
}

void EventLoop::UpDateChannel(Channel *channel)
{
    LOGD("fd=%d,events=%d",channel->GetFd(),channel->GetEvents());
    const int channel_status = channel->GetChannelStatus();
    int fd = channel->GetFd();
    if(channel_status == NEW || channel_status == DELETED)
    {
      
        if(channel_status == NEW)
        {
            if(m_channels.find(fd) != m_channels.end())
            {
                LOGE("fd=%d, aleady exist in channels",fd);
                return;
            }
            m_channels[fd] = std::shared_ptr<Channel>(channel);
            m_pEpoller->ControlChannel(EPOLL_CTL_ADD,channel);

        }else{
            if(m_channels.find(fd) == m_channels.end())
            {
                LOGE("fd=%d, not in channels",fd);
                return;
            }
            m_pEpoller->ControlChannel(EPOLL_CTL_DEL,channel);
        }
    }else{
        m_pEpoller->ControlChannel(EPOLL_CTL_MOD,channel);
    }
}
