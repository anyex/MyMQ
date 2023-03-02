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
    int GetFd() {return fd;};
    void SetEvents(int events) {this->events = events;};
    int GetEvents() {return this->events;};
private:
    int fd;
    int events;
    int revents;
    EventLoop *loop;

};

