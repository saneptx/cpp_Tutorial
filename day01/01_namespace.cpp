#include<iostream>
using namespace std;
namespace ptx1{
    int var = 10;
    void add(int a,int b){
        cout<<a + b<<endl;
    }
    namespace ptx1_in{
        int var = 20;
        void display(){
            cout<< ptx1::ptx1_in::var <<endl;
        }
    }
}

//using namespace ptx1;
//using ptx1::add;
int main(){
    // add(2,3);
    // ptx1::add(2,3);
    ptx1::ptx1_in::display();
}