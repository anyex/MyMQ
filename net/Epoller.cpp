#include "Epoller.hpp"
#include "Channel.hpp"

Epoller::Epoller(EventLoop *loop)
    :owerLoop(loop)
{

}

bool Epoller::HasChannel(Channel *channel)
{
    if(NULL == channel)
    {
        return false;
    }   
    return channels.find(channel->GetFd()) != channels.end();
}

void Epoller::Poll(std::vector<Channel*> channels)
{

}
