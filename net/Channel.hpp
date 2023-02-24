#include <functional>
class EventLoop;
class Channel
{
    
public:
    Channel(/* args */);
    ~Channel();
private:
    int fd;
    int events;
    int revents;
    EventLoop *loop;
    

};

