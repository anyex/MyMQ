#include "Logger/Logger.hpp"
#include "net/InetAddr.hpp"
#include "net/Server.hpp"
#include <unistd.h>
#include "net/IoBuf.hpp"
int main()
{
    
    // Server server("tbox",2,InetAddr("tbox.sock"));
    // server.Start();
    // LOGD("调试日志");
    // sleep(-1);
    IoBuf buf(0);
    buf.AppendBytes<std::string>("123455");
    buf.Prepend<std::string>("000");
    std::cout << "buf:"<<buf.SerialString()<<std::endl;;
    std::stringstream buf1;
    buf1<<"1234565";
    std::cout <<"buf1:" << buf1.str()<<std::endl;
    return 0;
}