#include "EventLoop.hpp"
#include "util/ThreadPool/ThreadPool.hpp"

#define DEFAULT_EVENTLOOP_THREAD 2


class EventLoopThreadPool{
public:
    EventLoopThreadPool(int n_threads = DEFAULT_EVENTLOOP_THREAD);
    void Start();
    std::shared_ptr<EventLoop> GetEventLoop();
private:
    int m_nThreads;//启动线程数
    ThreadPool m_pool;
    std::vector<std::shared_ptr<EventLoop>> m_EventLoop;
    std::atomic<int> m_IdNext;
};