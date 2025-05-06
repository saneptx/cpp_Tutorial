#include<iostream>
#include<memory>
using namespace std;

struct FILECloser{
    void operator()(FILE * fp){
        if(fp){
            fclose(fp);
            cout << "fclose(fp)" << endl;
        }
    }
};
// void test1(){
//     string msg = "hello world\n";
//     // unique_ptr<FILE, decltype(&fclose)> up(fopen("res1.txt","a+"), fclose);
//     // if (up) {
//     //     fwrite(msg.c_str(), 1, msg.size(), up.get());
//     //     // 不要手动 fclose(up.get())，unique_ptr 析构时会自动调用 fclose
//     // }
//     unique_ptr<FILE,FILECloser> up(fopen("res1.txt","a+"));
//     fwrite(msg.c_str(),1,msg.size(),up.get());
// }
void test2(){
    string msg = "hello,world\n";
    FILECloser fc;
    //在shared_ptr的构造函数参数中加入删除器对象
    shared_ptr<FILE> sp(fopen("res1.txt","a+"),fc);
    fwrite(msg.c_str(),1,msg.size(),sp.get());
}
int main(){
    test2();
    return 0;
}