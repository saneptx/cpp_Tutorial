#include "WorkThread.h"


WorkThread::WorkThread(ThreadPool &pool)
:_pool(pool){

}
WorkThread::~WorkThread(){

}
void WorkThread::run(){
    _pool.doTask();
}
