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

int main(){
    //1.设置日志布局
    PatternLayout* ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout* ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");
    
    PatternLayout* ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

    //2.创建输出器对象
    OstreamAppender *pos = new OstreamAppender("console",&cout);
    //输出器与布局绑定
    pos->setLayout(ptn1);

    FileAppender *filePos = new FileAppender("file","wd.log");
    filePos->setLayout(ptn2);

    RollingFileAppender *rfPos = new RollingFileAppender("rollingfile","rollingfile.log",5*1024,9);
    rfPos->setLayout(ptn3);

    //3.创建日志记录器
    //引用名salesDepart是在代码中使用的，表示Category对象
    //参数中salesDepart是在获取日志来源是返回的记录器的名字
    //一般让两者相同，方便理解
    Category & salesDepart = Category::getInstance("salesDpart");

    //4.给Category设置优先级
    salesDepart.setPriority(Priority::INFO);

    //5.给Category设置输出器
    salesDepart.addAppender(pos);
    salesDepart.addAppender(filePos);
    salesDepart.addAppender(rfPos);

    //6.记录日志
    int count = 100;
    while(count-->0){
        salesDepart.emerg("this is an emerge msg");
        salesDepart.fatal("this is an fatal msg");
        salesDepart.alert("this is an alert msg");
        salesDepart.crit("this is an crit msg");
        salesDepart.error("this is an error msg");
        salesDepart.warn("this is an warn msg");
        salesDepart.notice("this is an notice msg");
        salesDepart.info("this is an info msg");
    }
    Category::shutdown();

    return 0;
}