#include<iostream>
using std::cout;
using std::endl;

int add(int a,int b,int c){
    return a+b+c;
}
int add(int a=0,int b=0,int c=0);
int main(){
    cout<<add()<<endl;
    cout<<add(1)<<endl;
    cout<<add(2,3)<<endl;
    cout<<add(4,5,6)<<endl;
    return 0;
}