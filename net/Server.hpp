#include <string>
#include <thread>
#include "InetAddr.hpp"
#include "Acceptor.hpp"
#include "EventLoop.hpp"
class EventLoop;
class Server{
public:
    Server(std::string name,const InetAddr &addr);
    void Start();
private:
    std::unique_ptr<Acceptor> m_acceptor;

};