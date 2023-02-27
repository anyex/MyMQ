#include <functional>
#include <sys/epoll.h>
#include "util/Logger/Logger.hpp"
class EventLoop;

class Channel
{
    
public:
    Channel(EventLoop *loop,int fd);
    ~Channel();

    void HandleEvent();
    int GetFd() {return fd;};
private:
    int fd;
    int events;
    int revents;
    EventLoop *loop;

};

