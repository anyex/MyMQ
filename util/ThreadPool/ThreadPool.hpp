#include <functional>
#include <thread>
#include <mutex>
#include "SafeQueue.hpp"
#include <future>

class ThreadPool
{

public:
    ThreadPool(const int threads = 16) : m_threads(std::vector<std::thread>(threads)),
                                         m_shutdown(false){

                                         };
    void init()
    {
        for (int i = 0; i < m_threads.size(); i++)
        {
            m_threads.at(i) = std::thread(ThreadWorker(this, i));
        };
    };
    void shutdown()
    {
        m_shutdown = true;
        m_conditional_lock.notify_all();

        for(int i = 0;i<m_threads.size();i++)
        {
            if(m_threads.at(i).joinable())
            {
                m_threads.at(i).join();
            }
        }
    }
    template <typename F,typename ... Args>
    auto submit(F &&f,Args &&... args)->std::future<decltype(f(args...))>
    {
        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);
        std::function<void()> warpper_func = [task_ptr]()
        {
            (*task_ptr)();
        };
        m_queue.enqueue(warpper_func);
        m_conditional_lock.notify_one();
        return task_ptr->get_future();
    }
private:
    class ThreadWorker
    {
    public:
        ThreadWorker(ThreadPool *pool, const int id) : m_pool(pool), m_id(id){};
        void operator()()
        {
            std::function<void()> func;
            bool dequeue_succ = false;
            while (!m_pool->m_shutdown)
            {
                {
                    std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);
                    if(m_pool->m_queue.Empty())
                    {
                        m_pool->m_conditional_lock.wait(lock);
                    }
                    dequeue_succ = m_pool->m_queue.DeQueue(func);
                }

                if(dequeue_succ)
                {
                    func();
                }
            }
        };

    private:
        int m_id;
        ThreadPool *m_pool;
    };
    std::atomic<bool> m_shutdown;
    SafeQueue<std::function<void>> m_queue;
    std::vector<std::thread> m_threads;
    std::mutex m_conditional_mutex;
    std::condition_variable m_conditional_lock;
};
