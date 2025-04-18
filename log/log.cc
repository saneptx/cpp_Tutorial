#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
using namespace std;
using namespace log4cpp;

int main(){
    //设置日志布局
    PatternLayout* ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout* ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");
    
    PatternLayout* ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

    //创建输出器对象
    OstreamAppender *pos = new OstreamAppender("console",&cout);
    
    return 0;
}