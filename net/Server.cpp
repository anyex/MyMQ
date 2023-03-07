#include "Server.hpp"

Server::Server(std::string name,int threads,const InetAddr &addr):
    m_acceptor(new Acceptor(addr,&m_mainEventLoop)),
    m_nThreads(threads),
    m_sName(name)
{
    m_threadPool.init();
    for (int i = 0; i < m_nThreads; i++)
    {
      m_subEventLoop.push_back(std::shared_ptr<EventLoop>(new EventLoop()));
    }

    std::function<void(int,const InetAddr &)> cb = std::bind(&Server::OnConnected,this,std::placeholders::_1,std::placeholders::_2);
    m_acceptor->SetConnectedCallback(cb);
   
    
}

void Server::OnConnected(int sockfd, const InetAddr &peerAddr)
{
    std::shared_ptr<Connection> p_conn = std::make_shared<Connection>(sockfd,GetNextLoop());
    m_Connections.insert({{sockfd,p_conn}});
}

void Server::Start()
{
    {
      m_acceptor->Listen();
      std::function<void()> sub_loop = std::bind(&EventLoop::Loop, m_mainEventLoop);
      m_threadPool.submit(sub_loop);
    }
    for (int i = 0; i < m_nThreads; i++)
    {
      std::function<void()> sub_loop = std::bind(&EventLoop::Loop, m_subEventLoop[i]);
      m_threadPool.submit(sub_loop);
    }
}

std::shared_ptr<EventLoop>  Server::GetNextLoop()
{
    return m_subEventLoop[m_IdNext++ % m_subEventLoop.size()];
}