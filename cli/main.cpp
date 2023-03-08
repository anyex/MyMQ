#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <sys/un.h>
#include "../util/Logger/Logger.hpp"
#include <error.h>
int main()
{
    int  cli = socket(AF_UNIX,SOCK_STREAM |SOCK_NONBLOCK|SOCK_CLOEXEC,0);
    int rc = 0;
    struct sockaddr_un server_addr;
    server_addr.sun_family=AF_UNIX;
      strncpy(server_addr.sun_path,
       "tbox.sock",
       sizeof("tbox"));
    rc = connect(cli,(sockaddr*)&server_addr,sizeof(sockaddr));
    if(rc != 0)
    {
        LOGE("conn failed :%s",strerror(errno));
    }

    
    return 0;
}