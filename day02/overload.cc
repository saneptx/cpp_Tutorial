#include<iostream>
using std::cout;
using std::endl;

int add(int a,int b){
    return a+b;
}
int add(int a,int b,int c){
    return a+b+c;
}
#ifdef __cplusplus
extern "C"//c与c++混合编程
{
#endif
    int add(int a,double b){
        return a+b;
    }
#ifdef __cplusplus
}//end of C
#endif
// float add(float x,int y){//返回值类型不同，不是add的重载
//     return x+y;
// }
int main(){
    cout<<add(2,3)<<endl;
    cout<<add(1,2,3)<<endl;
    cout<<add(1,3.14)<<endl;
    return 0;
}