#include<iostream>
#include"singleton_log.h"
using namespace std;
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