#include <vector>
#include <memory>
class Channel;
class Epoller;
class EventLoop
{
public:
    EventLoop();
    ~EventLoop();
    void Loop();
private:
    void HandleRead();

    std::vector<Channel*> vecActiveChannels;

    std::unique_ptr<Epoller> poller;

};