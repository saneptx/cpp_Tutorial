#ifndef __Mylogger__
#define __Mylogger__

#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>

using namespace log4cpp;

class Mylogger
{
public:
    void warn(const char *msg);
    void error(const char *msg);
    void debug(const char *msg);
    void info(const char *msg);

    static Mylogger * getInstance();
    static void destory();
private:
    Mylogger();
    ~Mylogger();
private:
    log4cpp::Category & _mycat;
    static Mylogger *_pInstance;
};
#endif