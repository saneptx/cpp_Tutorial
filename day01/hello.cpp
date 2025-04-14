#include <iostream>//标准库
using namespace std;//命名空间

void test(){
    cout << "Hello world" << endl;
}
int main(int args,char *argv[])
{
    test();
    int number = 0;
    cin >> number;
    cout << number <<endl;
    return 0;
}

