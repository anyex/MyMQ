#include <vector>
#include <memory>
#include <atomic>
class Channel;
class Epoller;
class EventLoop
{
public:
    EventLoop();
    ~EventLoop();
    void Loop();
    void UpDateChannel(Channel *channel);
private:
    void HandleRead();

    std::vector<Channel*> m_vecActiveChannels;

    std::unique_ptr<Epoller> m_pEpoller;

    std::atomic<bool> m_shutdown;
};