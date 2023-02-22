#include <string>
#include <iostream>
#include <time.h>
#include <thread>
#include <stdint.h>
#include <sys/types.h>

#define LOG(level,fmt, ...) \
    do\
    { \
       int64_t timestamp = time(NULL);\
       char buf[128] = {0};\
       struct tm tm_time = {0};\
       localtime_r(&timestamp,&tm_time);\
       snprintf(buf, 128, "%4d-%02d-%02d %02d:%02d:%02d", \
        tm_time.tm_year + 1900,\
        tm_time.tm_mon + 1,\
        tm_time.tm_mday,\
        tm_time.tm_hour,\
        tm_time.tm_min,\
        tm_time.tm_sec);\
        char log[1024] = {0}; \
        snprintf(log,1024,fmt, ##__VA_ARGS__);\
        std::cout<<buf<<"\t"<<gettid()<<"\t"<<level<<"\t"<<log<<"\n";\
    } while(0);
    

#define LOGI(fmt, ...)   \
    do \
    { \
        LOG("INFO",fmt, ##__VA_ARGS__);\
    } while (0); 



#define LOGD(fmt,...) \
    do \
    { \
        LOG("DEBUG",fmt, ##__VA_ARGS__);\
    } while (0);


#define LOGE(fmt, ...) \
    do \
    { \
        LOG("ERROR",fmt, ##__VA_ARGS__);\
    } while (0);
