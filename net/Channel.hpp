#include <functional>
#include <sys/epoll.h>
#include "../util/Logger/Logger.hpp"
class EventLoop;

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
private:
    void UpDateEvent();
    int m_fd;
    int m_events;
    int m_revents;
    EventLoop *m_pLoop;

};

