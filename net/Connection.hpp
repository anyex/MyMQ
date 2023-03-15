#include "InetAddr.hpp"
#include "Socket.hpp"
#include "Channel.hpp"
#include <string>
#include <memory>
#include <atomic>
#include "Buffer.hpp"

class EventLoop;

class Connection
{

public:
    Connection(EventLoop *loop,
        int sockfd);
    bool Connected();
    void Send(const std::string &buf);
private:
    void HandleRead();
    EventLoop *m_pLoop;
    std::unique_ptr<Socket> m_pSocket;
    std::unique_ptr<Channel> m_pChannel;
    std::string m_sName;
    Buffer m_input;
    Buffer m_output;
};