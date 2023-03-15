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
    void SetRevents(int revents) {this->m_revents = revents;};
    int GetEvents() {return this->m_events;};
    void EnableRead(){m_events |=  EPOLLIN | EPOLLPRI;UpDateEvent();};
    void EnableWrite(){m_events |= EPOLLOUT;UpDateEvent();};
    int GetChannelStatus() {return m_channel_status; };
    void SetChannelStatus(int status) {m_channel_status = (channel_net_status)status;};
    void SetReadCallback(std::function<void()> func){m_read_func = func;};
    void SetWriteCallback(std::function<void()> func){m_write_func = func;};
    void SetCloseCallback(std::function<void()> func){m_close_func = func;};
    void SetErrorCallback(std::function<void()> func){m_error_func = func;};
private:
    void UpDateEvent();
    int m_fd;
    int m_events;
    int m_revents;
    EventLoop *m_pLoop;
    channel_net_status m_channel_status;
    std::function<void()> m_read_func;
    std::function<void()> m_write_func;
    std::function<void()> m_close_func;
    std::function<void()> m_error_func;
};


#endif