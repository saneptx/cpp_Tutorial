#include<iostream>
#include "Mylogger.h"
using namespace std;

Mylogger* Mylogger::_pInstance = nullptr;
Mylogger::Mylogger()
:_mycat(Category::getInstance("mycat")){
    //1.设置日志布局
    auto ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    auto ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");
    
    auto ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

    //2.创建输出器对象
    auto *pos = new OstreamAppender("console",&cout);
    //输出器与布局绑定
    pos->setLayout(ptn1);

    auto *filePos = new FileAppender("file","wd.log");
    filePos->setLayout(ptn2);

    auto *rfPos = new RollingFileAppender("rollingfile","rollingfile.log",5*1024,9);
    rfPos->setLayout(ptn3);

    //3.创建日志记录器
    //引用名salesDepart是在代码中使用的，表示Category对象
    //参数中salesDepart实在获取日志来源是返回的记录器的名字
    //一般让两者相同，方便理解

    //4.给Category设置优先级
    _mycat.setPriority(Priority::INFO);

    //5.给Category设置输出器
    _mycat.addAppender(pos);
    _mycat.addAppender(filePos);
    _mycat.addAppender(rfPos);
    cout<<"Mylogger()"<<endl;
}

Mylogger::~Mylogger(){
    Category::shutdown();
    cout<<"~Mylogger()"<<endl;
}

Mylogger * Mylogger::getInstance(){
    if(_pInstance == nullptr){
        _pInstance = new Mylogger();
    }
    return _pInstance;
}

void Mylogger::destory(){
    if(_pInstance){
        delete _pInstance;
        _pInstance = nullptr;
    }
}

void Mylogger::warn(const char * msg){
    _mycat.warn(msg);
}
void Mylogger::error(const char * error){
    _mycat.error(error);
}
void Mylogger::debug(const char * debug){
    _mycat.debug(debug);
}
void Mylogger::info(const char * info){
    _mycat.info(info);
}