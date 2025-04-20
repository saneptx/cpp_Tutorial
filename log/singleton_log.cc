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
    MyLogger(): category(Category::getInstance("category")) {
        PatternLayout* layout1 = new PatternLayout();
        layout1->setConversionPattern("%d [%c] [%p] %m%n");
        PatternLayout* layout2 = new PatternLayout();
        layout2->setConversionPattern("%d [%c] [%p] %m%n");
        PatternLayout* layout3 = new PatternLayout();
        layout3->setConversionPattern("%d [%c] [%p] %m%n");
        
        OstreamAppender* osAppender = new OstreamAppender("console", &std::cout);
        osAppender->setLayout(layout1);
        FileAppender* fileAppender = new FileAppender("file", "mylog.log");
        fileAppender->setLayout(layout2);
        RollingFileAppender* rfAppender = new RollingFileAppender("rollingfile","rollingfile.log",5*1024,9);
        rfAppender->setLayout(layout3);

        category.setPriority(Priority::DEBUG);
        category.addAppender(osAppender);
        category.addAppender(fileAppender);
        category.addAppender(rfAppender);
    }
    ~MyLogger(){
        category.shutdown();
    }
    Category & category;//日志记录器

};
int testFunc(int x) {
    LOG_INFO("testFunc running with x = %d", x);
    return x + 10;
}
int main(){
    LOG_INFO("Start main");
    int result = testFunc(42);
    LOG_DEBUG("Result = %d", result);
    LOG_ERROR("Something went wrong: code = %d", -1);
    return 0;
}