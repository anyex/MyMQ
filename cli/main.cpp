#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <sys/un.h>
#include "../util/Logger/Logger.hpp"
#include <error.h>
#include <iostream>
#include "../codec/stream.hpp"
int main()
{
    int  cli = socket(AF_UNIX,SOCK_STREAM,0);
    int rc = 0;
    struct sockaddr_un server_addr ={0};
    server_addr.sun_family=AF_UNIX;
      strcpy(server_addr.sun_path,"tbox.sock");
    rc = connect(cli,(sockaddr*)&server_addr,sizeof(sockaddr));
    if(rc != 0)
    {
        LOGE("conn failed :%s",strerror(errno));
    }else{
        LOGD("conn succ");
    }
    std::string content;
    SocketStream stream(cli);
    while (true)
    {
        std::cin>>content;
      // int ret = send(cli,content.c_str(),content.length(),0);
       stream<<content;
       LOGD("发送数据:%d",content.size());
    }
    
   


    
    return 0;
}