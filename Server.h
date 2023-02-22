#include <string>
#include "InetAddr.h"
class Server{
public:
    Server(std::string name,const InetAddr &addr);
    void Start();
private:
    int listenfd;
};