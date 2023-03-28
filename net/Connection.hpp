#include "InetAddr.hpp"
#include "Socket.hpp"
#include "Channel.hpp"
#include <string>
#include <memory>
#include <atomic>
#include "../codec/stream.hpp"
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
    SocketStream m_stream;
};