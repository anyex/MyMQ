#include "EventLoop.hpp"
#include "Epoller.hpp"
#include "Channel.hpp"
EventLoop::EventLoop():
    poller(new Epoller(this))
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

void EventLoop::UpDateChannel(Channel *channel)
{
    for (int i = 0; i < vecActiveChannels.size(); i++)
    {
       if(vecActiveChannels[i] == channel)
       {

       }
    }
    
}
