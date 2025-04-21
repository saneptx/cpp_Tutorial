#include "Mylogger.h"
#include <iostream>
using namespace std;
void test0(){
    Mylogger::getInstance()->warn("this is a warm msg");
    Mylogger::getInstance()->error("this is a error msg");
    Mylogger::getInstance()->debug("this is a debug msg");
    Mylogger::getInstance()->info("this is a info msg");
    Mylogger::destory();
}
int main(){
    test0();
    return 0;
}