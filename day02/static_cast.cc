#include<iostream>
using std::cout;
using std::endl;


void test0(){
    //c语言风格
    int *p1 = (int*)malloc(sizeof(int));
    *p1 = 10;
    //c++static_cast强制转换
    int *p2 = static_cast<int*>(malloc(sizeof(int)));
    *p2 = 100;
    free(p1);
    free(p2);
    int iNumber = 100;
    float fNumber = 0;
    fNumber = static_cast<float>(iNumber);
}
int main(){
    test0();
    return 0;
}