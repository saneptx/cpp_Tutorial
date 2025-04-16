#include<iostream>
#include<limits>
#include<unistd.h>
using namespace std;

void test1(){
    cerr<<1;
    cout<<3;
    sleep(2);
}
void test0(){
    for(int i =0;i<5;++i){
        cout<<'a'<<endl;
    }
    sleep(2);
}
int main(){
    test1();
    return 0;
}