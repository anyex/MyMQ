#include <queue>
#include <mutex>
#include <shared_mutex>
template<typename T>
class SafeQueue{

public:
    SafeQueue(){

    };
    SafeQueue(SafeQueue &queue)
    {

    };
    bool Empty(){
        std::shread_lock<std::shared_mutex> lock(m_mutex);
        return m_queue.empty();
    };
    int Size(){
        std::shread_lock<std::shared_mutex> lock(m_mutex);
        return m_queue.size();
    };
    bool DeQueue(T &t)
    {
        if(Empty())
        {
            return false;
        }
        std::unique_lock<std::shread_mutex> lock(m_mutex);

        t = std::move(m_queue.front());
        m_queue.pop();
        return true;
    };
    void EnQueue(T &t)
    {
        std::unique_lock<std::shread_mutex> lock(m_mutex);
        m_queue.emplace(t);
    }
private:
    std::queue<T> m_queue;
    std::shared_mutex m_mutex;

};