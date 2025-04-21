#ifndef __SINGLETONLOG__
#define __SINGLETONLOG__
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
using namespace std;
using namespace log4cpp;

// 通用宏模板
#define LOG_FMT(level, fmt, ...) \
    MyLogger::getInstance().level(("[%s:%d][%s] " fmt), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

// 各级别宏
#define LOG_INFO(fmt, ...)   LOG_FMT(info, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...)  LOG_FMT(error, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)   LOG_FMT(warn, fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...)  LOG_FMT(debug, fmt, ##__VA_ARGS__)

class MyLogger{
public: 
    static Category & getInstance(){
        static MyLogger instance;
        return instance.category;
    }
private:
    MyLogger();
    ~MyLogger();
    Category & category;//日志记录器

};
#endif