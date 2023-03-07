#include "EveptLoopThreadPool.hpp"

EventLoopThreadPool::EventLoopThreadPool(int nThreads):
    m_nThreads(nThreads),
    m_pool(nThreads)
{
    m_pool.init();
};

void EventLoopThreadPool::Start()
{
    for (int i = 0; i < m_nThreads; i++)
    {
        std::shared_ptr<EventLoop>  pEventLoop = std::make_shared<EventLoop>();
        m_EventLoop.push_back(pEventLoop);
    }
    

};

std::shared_ptr<EventLoop> EventLoopThreadPool::GetEventLoop()
{
    return m_EventLoop[m_IdNext++%m_nThreads];
}