#include "Logger/Logger.hpp"
#include "net/InetAddr.hpp"
#include "net/Server.hpp"
#include <unistd.h>
int main()
{
    InetAddr addr("tbox.sock");
    Server test("test",1,addr);
    test.Start();
    return 0;
}