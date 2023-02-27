#include "InetAddr.hpp"
#include "Socket.hpp"
#include "Channel.hpp"
#include <string>
#include <memory>
#include <atomic>


class EventLoop;

class Connection
{

public:
    Connection(EventLoop *loop,
        const std::string &name,
        int sockfd);
    bool Connected();
    void Send(const std::string &buf);
private:
    EventLoop *loop;
    std::unique_ptr<Socket> socket;
    std::unique_ptr<Channel> channel;
    std::string name;
};