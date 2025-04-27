#include<iostream>
#include<memory>
using namespace std;
class Child;

class Parent{
public:
    Parent(){cout<<"Parent()"<<endl;}
    ~Parent(){cout<<"~Parent()"<<endl;}
    shared_ptr<Child> spChild;
};
class Child{
public:
    Child(){cout<<"Child()"<<endl;}
    ~Child(){cout<<"~Child()"<<endl;}
    shared_ptr<Parent> spParent;
};
void test0(){
    shared_ptr<Parent> parentPtr(new Parent());
    shared_ptr<Child> childPtr(new Child());
    //获取到的引用计数都是1
    cout << "parentPtr.use_count():" << parentPtr.use_count() << endl;
    cout << "childPtr.use_count():" << childPtr.use_count() << endl;

    parentPtr->spChild = childPtr;
    childPtr->spParent = parentPtr;
    //获取到的引用计数都是2
    cout<<"parentPtr.use_count()"<<parentPtr.use_count()<<endl;
    cout<<"childPtr.use_count()"<<childPtr.use_count()<<endl;
}
int main(){
    test0();
    return 0;
}