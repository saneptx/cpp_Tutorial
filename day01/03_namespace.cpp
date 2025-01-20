#include<iostream>
using namespace std;

namespace ptx{
    extern int var;
    extern void display();
}
int main(){
    ptx::display();
}