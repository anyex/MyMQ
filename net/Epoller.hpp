#include <unordered_map>
#include <vector>

class Channel;
class EventLoop;


class Epoller{
public:
    Epoller(EventLoop *loop);
    bool HasChannel(Channel *channel);
    void Poll(std::vector<Channel*> &channels);
protected:
    std::unordered_map<int,Channel*> channels;
private:
   void UpdateActiveChannel(int numEvents,std::vector<Channel*>& activeChannels);

    EventLoop *owerLoop;
    int epollfd;
    std::vector<epoll_event> events;
};