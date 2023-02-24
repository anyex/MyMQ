#include <string>
#include "InetAddr.hpp"
#include "Acceptor.hpp"
class Server{
public:
    Server(std::string name,const InetAddr &addr);
    void Start();
private:
    Acceptor acceptor;
};