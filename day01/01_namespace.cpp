#include <iostream>
using std::cout;
using std::endl;

namespace wd{
    int num = 100;
    void func(){
        cout<<"wd func"<<endl;
    }
}
namespace hw{
    int num = 10;
    void func(){
        cout << "hw func" << endl;
        cout << num << endl;
    }
}

void test(){
    // wd::func;
    hw::func();
}
int main(int args,char *argv[])
{
    test();
    return 0;
}

