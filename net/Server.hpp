#include <string>
#include <thread>
#include <unordered_map>
#include "InetAddr.hpp"
#include "Acceptor.hpp"
#include "EventLoop.hpp"
#include "Connection.hpp"
#include "../util/ThreadPool/ThreadPool.hpp"

class EventLoop;
class Server{
public:
    Server(std::string name,int threads,const InetAddr &addr);
    void Start();
private:
    void OnConnected(int sockfd, const InetAddr &peerAddr);
    std::shared_ptr<EventLoop> GetNextLoop();
    std::unique_ptr<Acceptor> m_acceptor;
    EventLoop m_mainEventLoop;
    std::unordered_map<int,std::shared_ptr<Connection>> m_Connections;
    int m_nThreads;
    std::string m_sName;
    std::vector<std::shared_ptr<EventLoop>> m_subEventLoop;
    std::atomic<int> m_IdNext;
    ThreadPool m_threadPool;
};