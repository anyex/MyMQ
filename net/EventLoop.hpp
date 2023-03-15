#include <vector>
#include <memory>
#include <atomic>
#include <map>
class Channel;
class Epoller;
class EventLoop
{
public:
    EventLoop(std::string name);
    ~EventLoop();
    void Loop();
    void UpDateChannel(Channel *channel);
private:
    void HandleRead();

    std::vector<Channel*> m_vecActiveChannels;

    std::unique_ptr<Epoller> m_pEpoller;

    std::atomic<bool> m_shutdown;

    std::map<int,std::shared_ptr<Channel>> m_channels;

    std::string m_sName;
};