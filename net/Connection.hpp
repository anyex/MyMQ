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
        int sockfd);
    bool Connected();
    void Send(const std::string &buf);
private:
    EventLoop *m_pLoop;
    std::unique_ptr<Socket> m_pSocket;
    std::unique_ptr<Channel> m_pChannel;
    std::string m_sName;
};