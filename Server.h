#include <string>
#include "InetAddr.h"
#include "Acceptor.h"
class Server{
public:
    Server(std::string name,const InetAddr &addr);
    void Start();
private:
    Acceptor acceptor;
};