#include "Logger/Logger.hpp"
#include "net/InetAddr.hpp"
#include "net/Server.hpp"
#include <unistd.h>

int main()
{
    
    Server server("tbox",InetAddr("tbox.sock"));
    server.Start();
    LOGD("调试日志");
    sleep(-1);
    return 0;
}