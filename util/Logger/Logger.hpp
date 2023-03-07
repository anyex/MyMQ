#include <iostream>
#include <time.h>
#include <thread>
#include <stdint.h>
#include <sys/types.h>
#include <errno.h>
#include <chrono>
#include <sys/time.h>

#define LOG(level,fmt, ...) \
    do\
    { \
       struct timeval tv;\
       gettimeofday(&tv,NULL);\
       char buf[128] = {0};\
       struct tm tm_time = {0};\
       localtime_r(&tv.tv_sec,&tm_time);\
       snprintf(buf, 128, "%4d-%02d-%02d %02d:%02d:%02d.%03d", \
        tm_time.tm_year + 1900,\
        tm_time.tm_mon + 1,\
        tm_time.tm_mday,\
        tm_time.tm_hour,\
        tm_time.tm_min,\
        tm_time.tm_sec,\
        tv.tv_usec/1000%1000);\
        char log[1024] = {0}; \
        snprintf(log,1024,fmt, ##__VA_ARGS__);\
        std::cout<<buf<<"\t"<< std::this_thread::get_id()<<"\t"<<level<<"\t"<<log<<std::endl;\
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
