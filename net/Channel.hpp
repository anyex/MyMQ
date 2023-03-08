#ifndef CHANNEL_H_
#define CHANNEL_H_

#include <functional>
#include <sys/epoll.h>
#include "../util/Logger/Logger.hpp"
class EventLoop;

enum channel_net_status{
    NEW,
    ADDED,
    DELETED
};

class Channel
{
    
public:
    Channel(EventLoop *loop,int fd);
    Channel();
    ~Channel();

    void HandleEvent();
    int GetFd() {return m_fd;};
    void SetEvents(int events) {this->m_events = events;};
    int GetEvents() {return this->m_events;};
    void EnableRead(){m_events |=  EPOLLIN | EPOLLPRI;UpDateEvent();};
    void EnableWrite(){m_events |= EPOLLOUT;UpDateEvent();};
    int GetChannelStatus() {return m_channel_status; };
    void SetChannelStatus(int status) {m_channel_status = (channel_net_status)status;};
private:
    void UpDateEvent();
    int m_fd;
    int m_events;
    int m_revents;
    EventLoop *m_pLoop;
    channel_net_status m_channel_status;
};


#endif