#include "EventLoop.hpp"
#include "Epoller.hpp"
#include "Channel.hpp"
EventLoop::EventLoop():
    m_pEpoller(new Epoller(this)),
    m_shutdown(false)
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
    while (m_shutdown)
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
       
}
