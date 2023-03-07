#include <functional>
#include <mutex>
#include <condition_variable>
#include <string>
#include <thread>

class EventLoop;

class EventLoopThread
{
public:
    EventLoopThread(const std::string &name = std::string());
    EventLoop* StartLoop();
private:
    std::shared_ptr<std::thread> m_thread;
    pid_t pid;
    
};