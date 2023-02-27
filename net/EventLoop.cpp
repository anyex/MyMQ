#include "EventLoop.hpp"
#include "Epoller.hpp"
#include "Channel.hpp"
EventLoop::EventLoop()
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
    while (true)
    {
        vecActiveChannels.clear();
        poller->Poll(vecActiveChannels);
        for (Channel* channel : vecActiveChannels)
        {
           channel->HandleEvent();
        }
        
    }
    
}