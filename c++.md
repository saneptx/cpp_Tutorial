# C++

## 命名空间

### 创建命名空间

~~~c++
namespace{
    //实体：变量、函数、类等
}
~~~

### 使用命名空间

三种方式：

1. 作用域限定符：`std::cout`
2. using编译指令：`using namespace std`
3. using声明机制：`using std::cout`

命名空间中你可以定义实体可以声明实体，但不能使用实体。使用命名空间中的实体一定是在命名空间之外。命名空间只是用来存放实体的。

## const关键字

### 修饰内置类型*

const修饰的数据类型不能修改。在c语言中通常使用`#define MAX 100`来定义常量。这样并不会对数据类型进行指定，在c++中通常使用`const int MAX =100`来指定一个常量这样就会对常量数据类型进行检查。**const常量必须进行初始化**。`int const MAX = 100`这种写法也是可以的。

~~~c
/*
const常量和宏定义常量的区别：

1.发生实际不同：c语言中的宏定义发生在预处理时，做字符串的替换。const常量是在编译时（const常量本质还是一个变量，只是用const关键字限定之后，赋
予只读属性，使用时依然是以变量的形式去使用）

2.类型和安全检查不同：宏定义没有类型，不做任何类型检查；const常量有具体的类
型，在编译期会执行类型检查。

在使用中，应尽量以const替换宏定义，可以减小犯错误的概率
*/
~~~

### 修饰指针类型*

~~~c++
#include<iostream>
using namespace std;

int main(){
    int number1=3;
    int number2=4;

    int * const p1 = &number1;//指针常量，指向固定的地址可以改变存放地址中的值，不能指向别的地址
    *p1 = 30;
    //p1 = &number2;//不被允许

    const int * p2 = &number2;//常量指针，可以指向任意常量，但不能改变指向常量的值
    //*p2 = 40;//不被允许
    p2 = &number1;
}
~~~

## new/delete表达式

new和delete并不是函数而是表达式。

~~~c++
#include<iostream>
using namespace std;

int main(){
    int *pa = new int();//默认初始化为0
    cout<<*pa<<endl;
    int *pb = new int(3);//初始化为3
    cout<<*pb<<endl;
    int *pc = new int[5]();//默认初始化数组全为0
    for(int i=0;i<5;i++){
        cout<<pc[i]<<" ";
    }
    cout<<endl;
    int *pd = new int[5]{1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<pd[i]<<" ";
    }
    cout<<endl;
    delete pa;
    delete pb;
    delete []pc;
    delete []pd;
    pa = nullptr;//安全回收
}
~~~

### new/delete与malloc/free的区别*

~~~c
/*
new delete和malloc free的区别
1. malloc/free是库函数；new/delete是表达式，后两者使用时不是函数的写法；
2. new表达式的返回值是相应类型的指针，malloc返回值是void*；
3. malloc申请的空间不会进行初始化，获取到的空间是有脏数据的，但new表达式申请空间时可以直接初始化；
4. malloc的参数是字节数，new表达式不需要传递字节数，会根据相应类型自动获取空间大小。
*/
~~~

## 引用

引用是一个已定义变量的别名。

#### 引用的使用

~~~c++
int number = 2;
int & ref = number;
~~~

1.  &在这里不再是取地址符号，而是引用符号。
2.   引用的类型需要和其绑定的变量的类型相同（目前这样使用，学习继承后这一条有所不 同）。
3.   声明引用的同时，必须对引用进行初始化，否则编译时报错。
4.  引用一经绑定，无法更改绑定。

由于引用是被限制的指针，所以引用是占据内存的，占据的大小就是一个指针的大小。有 很多的说法，都说引用不会占据存储空间，其只是一个变量的别名，但这种说法并不准 确。引用变量会占据存储空间，存放的是一个地址，但是编译器阻止对它本身的任何访 问，从一而终总是指向初始的目标单元。

#### 引用和指针的区别*

~~~c
/*
联系：
1. 引用和指针都有地址的概念，都是用来间接访问变量；
2. 引用的底层还是指针来完成，可以把引用视为一个受限制的指针。
区别：
1. 引用必须初始化，指针可以不初始化；
2. 引用不能修改绑定，但是指针可以修改指向；
3. 在代码层面对引用本身取址取到的是变量的地址，但是对指针取址取到的是指针变量本身的地址
*/
~~~

## 强制转换

c++将强制转换分为不同的情况来讨论：

1. static_cast 最常用的，在指针之间转换。
2. const_cast 去除常量属性。
3. dynamic_cast 用基类和派生类之间做转换。
4. reinterpret_cast 在任意类型之间进行转换。

~~~c++
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
~~~

## 函数重载

函数的名字相同返回值相同但参数不同称为函数的重载。

~~~c++
#include<iostream>
using std::cout;
using std::endl;

int add(int a,int b){
    return a+b;
}
int add(int a,int b,int c){
    return a+b+c;
}
int add(int a,double b){
    return a+b;
}
// float add(float x,int y){//返回值类型不同，不是add的重载
//     return x+y;
// }
int main(){
    cout<<add(2,3)<<endl;
    cout<<add(1,2,3)<<endl;
    cout<<add(1,3.14)<<endl;
    return 0;
}
~~~

~~~sh
g++ overload.c -c
nm overload.o #nm命令用于查看目标文件中的符号表信息
~~~

![image-20250415094225911](./c++.assets/image-20250415094225911.png)

在 C++ 中，函数重载通过 **名称修饰（name mangling）** 实现，即同一个函数名在编译后会被编码为不同的名字（根据参数类型），所以编译器能区分它们。

### c与c++混合编程

在需要采用c的方式调用时，可以将方法和包裹在`extern "c"`中

~~~c++
extern "C"//c与c++混合编程
{
    int add(int a,double b){
        return a+b;
    }
}//end of C
~~~

或者用`extern "c"`修饰单个函数

~~~c
extern "C" void func(){
    
}
~~~

有些代码希望做到不管是在c的编译环境下还是c++的编译环境下都希望采用C的方式执行：

~~~c++
#ifdef __cplusplus
extern "C"//c与c++混合编程
{
#endif
    int add(int a,double b){//该函数都按c的方式调用
        return a+b;
    }
#ifdef __cplusplus
}//end of C
#endif
~~~

### 默认参数

C++可以给函数定义默认参数值。通常，调用函数时，要为函数的每个参数给定对应的实参。

~~~c++
#include<iostream>
using std::cout;
using std::endl;

int add(int a=0,int b=0,int c=0){
    return a+b+c;
}

int main(){
    cout<<add()<<endl;
    cout<<add(1)<<endl;
    cout<<add(2,3)<<endl;
    cout<<add(4,5,6)<<endl;
    return 0;
}
~~~

在函数声明时给出默认参数，实现时不用再给默认参数

~~~c++
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
~~~

## 内存布局

![image-20250415102135737](./c++.assets/image-20250415102135737.png)

以32位系统为例，一个进程在执行时，能够访问的空间是虚拟地址空间。理论上为2^32， 即4G，有1G左右的空间是内核态，剩下的3G左右的空间是用户态。从高地址到低地址可 以分为五个区域：

- 栈区：操作系统控制，由高地址向低地址生长，编译器做了优化，显式地址时栈区和其 他区域保持一致的方向。 
- 堆区：程序员分配（malloc、new），由低地址向高地址生长，堆区与栈区没有明确的界限。 
- 全局/静态区：读写段（数据段），存放全局变量、静态变量。 
- 文字常量区：只读段，存放程序中直接使用的常量，如const char * p = "hello";  hello 这个内容就存在文字常量区。 
- 程序代码区：只读段，存放函数体的二进制代码。

## inline关键字(内联函数)

内联函数是C++的增强特性之一，用来降低程序的运行时间。当内联函数收到编译器的指 示时，即可发生内联：编译器将使用函数的定义体来替代函数调用语句，这种替代行为发 生在编译阶段而非程序运行阶段。

—— 内联函数就是在普通函数定义之前加上inline关键字

（1）inline是一个建议，并不是强制性的，后面会学到inline失效的情况 

（2）inline的建议如果有效，就会在 编译时展开，可以理解为是一种更高级的代码替换机 制（类似于宏——预处理）

（3）函数体内容如果太长或者有循环之类的结构，不建议inline，以免造成代码膨胀；比 较短小的代码适合用inline。

如果要把inline函数声明在头文件中，则必须把函数定义也写在头文件中。若头文件中 只有声明没有实现，被认为是没有定义替换规则。

C++的函数内联机制既具备宏代码的效率，又增加了安全性，而且可以自由操作类的数据 成员，所以在C++中应尽可能的用内联函数取代宏函数。

~~~c++
inline int max(int x, y)//内联函数只适合简短且常用的功能代码
 {
 return x > y ? x : y;
 }
~~~

## 类与对象

### 类的定义

类的定义分为两个部分：

1. 数据，相当于现实世界中的属性，称为数据成员; 
2. 对数据的操作，相当于现实世界中的行为，称为成员函数。

从程序设计的观点来说，类就是数据类型，是用户定义的数据类型，对象可以看成某个类 的实例（某类的变量）。所以说类是对象的抽象，对象是类的实例。

~~~c++
class Computer {
	void setBrand(const char * brand){
 		strcpy(_brand, brand);
    }
	void setPrice(float price){
 		_price = price;
    }
	char _brand[20];
	float _price;
};
~~~

class中的所有的成员都拥有自己的访问权 限，分别可以用以下的三个访问修饰符进行修饰

**public：**公有的访问权限，在类外可以通过对象直接访问公有成员.
**protected：**保护的访问权限，派生类中可以访问，在类外不能通过对象直接访问
**private：**私有的访问权限，在本类之外不能访问，比较敏感的数据设为private

class定义中如果在成员定义（或声明）之前没有任何访问修饰符，其默认的访问权限为私有。

~~~c++
class Computer {
public:
   void setBrand(const char * brand){
       strcpy(_brand, brand);
   }
   void setPrice(float price){
       price = price;
   }
private:
   char _brand[20];
   float _price;
};
int main(){
    Computer pc;
    pc.setPrice(10000); //ok
    //pc._price; //error,因为_price是私有的
    return 0;
}
~~~

### 成员函数的定义

成员函数可以在类内部完成定义，也可以在类内部只进行声明，在类外部完成定义。

~~~c++
class Computer {
public:
   void setBrand(const char * brand);
   void setPrice(float price);
private:
   char _brand[20];
   float _price;
};
void Computer::setBrand(const char * brand){

    strcpy(_brand, brand);
   
}
void Computer::setPrice(float price){
    price = price;
}
~~~

### 对象的创建

#### 构造函数

C++ 为类提供了一种 特殊的成员函数——构造函数来完成相同的工作。

构造函数的作用：就是用来初始化数据成员的。
构造函数的形式： 没有返回值，即使是void也不能有；函数名与类名相同，再加上函数参数列表。

当类中没有显式定义构造函数时 ，编译器会自动生成一个默认  (无参)  构造函数 ，但并不会初始化数据成员；
~~~c++
class Point{
public:
    void print(){
        cout<<"x="<<_ix<<"y="<<_iy<<endl;
    }
private:
    int _ix;
    int _iy;
};

int main(){
    Point point;
    point.print();//会初始化一个任意值
    return 0;
}
~~~

 一旦当类中显式提供了构造函数时 ，编译器就不会再自动生成默认的构造函数；

~~~c++
class Point{
public:
    Point(){
        _ix = 0;
        _iy = 0;
    }
    void print(){
        cout<<"x="<<_ix<<",y="<<_iy<<endl;
    }
private:
    int _ix;
    int _iy;
};

int main(){
    Point point;
    point.print();//会初始化一个任意值
    return 0;
}
~~~

构造函数也可以接收参数;

~~~c++
class Point{
public:
    Point(int x,int y){
        _ix = x;
        _iy = y;
    }
    void print(){
        cout<<"x="<<_ix<<",y="<<_iy<<endl;
    }
private:
    int _ix;
    int _iy;
};

int main(){
    //Point point;//error没有默认的无参构造函数调用
    Point point(2,3);
    point.print();//会初始化一个任意值
    return 0;
}
~~~

构造函数可重载；

~~~c++
class Point{
public:
    Point(){};//默认构造函数可重载
    Point(int x,int y){
        _ix = x;
        _iy = y;
    }
    void print(){
        cout<<"x="<<_ix<<",y="<<_iy<<endl;
    }
private:
    int _ix;
    int _iy;
};

int main(){
    Point point1;
    Point point2(2,3);
    point1.print();//会初始化一个任意值
    point2.print();
    return 0;
}
~~~

#### 对象的数据成员初始化

在C++中，对于类中数据成员的初始化，推荐使用初始化列表完成。初始化列表位于构造函数形参列表之后，函数体之前，用冒号开始，如果有多个数据成员，再用逗号分隔，初始值放在一对小括号中。

~~~c++
class Point{
public:
    Point(){};//默认构造函数可重载
    Point(int x,int y):
    _ix(x),_iy(y){
        _ix = x;
        _iy = y;
    }
    void print(){
        cout<<"x="<<_ix<<",y="<<_iy<<endl;
    }
private:
    int _ix;
    int _iy;
};

int main(){
    Point point1;
    Point point2(2,3);
    point1.print();//会初始化一个任意值
    point2.print();
    return 0;
}
~~~

 C++11之后，普通的数据成员也可以在声明时就进行初始化。但一些特殊的数据成员初始化只能在初始化列表中进行，故一般情况下统一推荐在初始化列表中进行数据成员初始化。

~~~c++
class Point{
public:
    Point(){};//默认构造函数可重载
    Point(int x,int y):
    _ix(x),_iy(y){
        _ix = x;
        _iy = y;
    }
    void print(){
        cout<<"x="<<_ix<<",y="<<_iy<<endl;
    }
private:
    int _ix=0;
    int _iy=0;
};

int main(){
    Point point1;
    Point point2(2,3);
    point1.print();//x=0,y=0
    point2.print();//x=2,y=3
    return 0;
}
~~~

#### 对象所占空间大小

成员函数并不影响对象的大小，对象的大小与数据成员有关（后面学习继承、多态，对象的内存布局会更复杂）；

现阶段，在不考虑继承多态的情况下，我们做以下测试。发现有时一个类所占空间大小就是其数据成员类型所占大小之和，有时则不是，这就是因为有 内存对齐的机制。

~~~c++
class A{
    int num;//4字节
    double price;//8字节
};
class B{
    int num;
    int price;
};
class C{
    int num1;
    int num2;
    double price;
};
class D{
    int num1;
    double price;
    int num2;
};
int main(){
    cout<<"sizeof(A)="<<sizeof(A)<<endl;//16
    cout<<"sizeof(B)="<<sizeof(B)<<endl;//8
    cout<<"sizeof(C)="<<sizeof(C)<<endl;//16
    cout<<"sizeof(D)="<<sizeof(D)<<endl;//24
    return 0;
}
~~~

如果数据成员中有数组类型,会按照除数组以外的其他数据成员中最大的那一个的倍数对齐

~~~c++
class E{
    double num1;
    char Arr[20];
    double num2;
    int num3;
};
class F{
    char _gArr[20];
    int _g1;
    double _g2;
};
int main(){
    cout<<"sizeof(E)="<<sizeof(E)<<endl;//48
    cout<<"sizeof(F)="<<sizeof(F)<<endl;//32
    return 0;
}
~~~

#### 指针数据成员

类的数据成员中有指针时，意味着创建该类的对象时要进行指针成员的初始化，需要申请堆空间。

~~~c++
class Computer {
public:
   Computer(const char * brand,int price)
   :_brand(new char[strlen(brand) + 1]())
   ,_price(price){
        strcpy(_brand,brand);
   }
private:
   char * _brand;
   float _price;
};

int main(){
    Computer pc("Apple",15000);
    return 0;
}
~~~

有new表达式被执行，就要想到通过delete表达式来进行回收。如果没有对应的回收机制，对象被销毁时，它所申请的堆空间不会被回收，就会发生内存泄漏。

### 对象的销毁

1. 析构函数：对象在销毁时，一定会调用析构函数
2. 析构函数的作用：清理对象的数据成员申请的资源（堆空间）—— 析构函数并不负责清 理数据成员(系统自动完成) 
3. 形式：【特殊的成员函数】
   没有返回值，即使是void也没有
   没有参数
   函数名与类名相同，在类名之前需要加上一个波浪号~ 
4. 析构函数只有一个（不能重载）
5. 析构函数默认情况下 ，系统也会自动提供一个
6. **当对象被销毁时 ，会自动调用析构函数【非常重要】**

#### 析构函数

当数据成员中有指针时，创建一个对象，会申请堆空间，销毁对象时默认析构不够用了 （造成内存泄漏），此时就需要我们自定义析构函数。在析构函数中定义堆空间上内存回 收的机制，就不会发生内存泄漏。

~~~c++
class Computer {
public:
   Computer(const char * brand,int price)
   :_brand(new char[strlen(brand) + 1]())
   ,_price(price){
        strcpy(_brand,brand);
   }
   ~Computer(){
        if(_brand){
            delete[] _brand;
            _brand = nullptr;
            cout<<"~Computer()"<<endl;
        }
   }
   void print();
private:
   char * _brand;
   float _price;
};
void Computer::print(){
    cout<<_brand<<" "<<_price<<endl;
}
int main(){
    Computer pc("Apple",15000);
    pc.print();
    return 0;
}
~~~

**对象被销毁，一定会调用析构函数； 调用了析构函数，对象并不会被销毁。**

不建议手动调用析构函数，因为容易导致各种问题，应该让析构函数自动被调用。

### 构造函数和析构函数的调用时机

![image-20250415151401145](./c++.assets/image-20250415151401145.png)

### 拷贝构造函数

可以用一个已经创建的对象赋值给另一个对象。

~~~c++
class Point{
public:
    Point(){};
    Point(int x,int y):
    _ix(x),_iy(y){
        _ix = x;
        _iy = y;
    }
    void print(){
        cout<<"x="<<_ix<<",y="<<_iy<<endl;
    }
private:
    int _ix=0;
    int _iy=0;
};

int main(){
    Point point1(2,3);
    Point point2 = point1;
    return 0;
}
~~~

既然涉及到对象的创建，就必然需要调用 构造函数，而这里会调用的就是**拷贝构造函数**(复制构造函数)。

拷贝构造函数的形式是固定的： `类名(const 类名 &) `  

1. 该函数是一个构造函数  —— 拷贝构造也是构造！ 
2. 该函数用一个已经存在的同类型的对象，来初始化新对象，即对对象本身进行复制      

默认的拷贝构造函数如下：

~~~c++
Point(const Point &rhs)
:_ix(rhs._ix)
,_iy(rhs._iy)
{}
~~~

当类中存在指针成员时事情就变得复杂了。
~~~c++
class Computer {
public:
   Computer(const char * brand,int price)
   :_brand(new char[strlen(brand) + 1]())
   ,_price(price){
        strcpy(_brand,brand);
   }
   ~Computer(){
        if(_brand){
            delete[] _brand;
            _brand = nullptr;
            cout<<"~Computer()"<<endl;
        }
   }
   void print();
private:
   char * _brand;
   float _price;
};
void Computer::print(){
    cout<<_brand<<" "<<_price<<endl;
}
int main(){
    Computer pc1("Apple",15000);
    Computer pc2 = pc1;
    pc1.print();
    pc2.print();
    return 0;
}
~~~

![image-20250415152526995](./c++.assets/image-20250415152526995.png)

如果是默认的拷贝构造函数，pc2会对pc的_brand进行浅拷贝，指向同一片内存；pc2被销毁时，会调用析构函数，将这片堆空间进行回收；pc再销毁时，析构函数中又会试图回收这片空间，出现double free问题。

![image-20250415153100690](./c++.assets/image-20250415153100690.png)

所以，如果拷贝构造函数需要显式写出时（该类有指针成员申请堆空间），在自定义的拷贝构造函数中要换成**深拷贝**的方式，先申请空间，再复制内容。

~~~c++
class Computer {
public:
   Computer(const char * brand,int price)
   :_brand(new char[strlen(brand) + 1]())
   ,_price(price){
        strcpy(_brand,brand);
   }
   Computer(const Computer & rhs)//手动定义拷贝构造函数
   :_brand(new char[strlen(rhs._brand)+1]())
   ,_price(rhs._price){
        strcpy(_brand,rhs._brand);
   }
   ~Computer(){
        if(_brand){
            delete[] _brand;
            _brand = nullptr;
            cout<<"~Computer()"<<endl;
        }
   }
   void print();
private:
   char * _brand;
   float _price;
};
void Computer::print(){
    cout<<_brand<<" "<<_price<<endl;
}
int main(){
    Computer pc1("Apple",15000);
    Computer pc2 = pc1;
    pc1.print();
    pc2.print();
    return 0;
}
~~~

![image-20250415153335930](./c++.assets/image-20250415153335930.png)

#### 拷贝构造函数的调用时机

1. 当使用一个已经存在的对象初始化另一个同类型的新对象时。
2. 将对象作为参数传递给函数时。
3. 函数返回值是对象时。

#### 拷贝构造函数的形式*

**思考1：拷贝构造函数能否去掉引用符号**

不能，首先编译器不允许这样写，其次当你需要调用拷贝构造函数时，采用的调用方式是按值传递，也就是需要再次调用拷贝构造函数，这样就出现了递归调用拷贝构造函数的情况直到栈溢出。

**思考2：拷贝构造函数能否去掉const关键字**

这种写法编译器不会报错但不推荐，加const的第一个用意：为了确保右操作数的数据成员不被改变。加const的第二个用意：为了能够复制临时对象的内容，因为非const引用不能绑定临时变 量（右值）。const引用可以绑定右值，非const引用不能绑定右值。

### 赋值运算符函数

对类可以执行如下操作：

~~~c++
Pont pt1(1,2),pt2(3,4);
pt1 = pt2;//赋值操作
~~~

在执行`pt1=pt2`时，该语句的`pt1`和`pt2`都存在，所有不存在对象的构造。

在上述例子中，当`=`作用于对象时，其实是把它当作一个函数来看待。在执行 `pt1 =  pt2;` 该语句时，需要调用的是赋值运算符函数。其形式如下：

~~~c++
ClassName& operator=(const ClassName &)
~~~

对Point类进行测试时，会发现我们不需要显式给出赋值运算符函数，就可以执行测试。这 是因为如果类中没有显式定义赋值运算符函数时，编译器会自动提供一个缺省的赋值运算 符函数。对于 Point 类而言，其实现如下:

~~~c++
Point & Point::operator=(const Point & rhs){
    _ix = rhs._ix;
    _iy = rhs._iy;
}
~~~

手动写出赋值运算符，再加上函数调用的提示语句。执行发现语句被输出，也就是说，当对象已经创建时，将另一个对象的内容复制给这个对象，会调用赋值运算符函数。

#### this指针

this指针的本质是一个指针常量 Type* const pointer; 它储存了调用它的对象的地址，不可被修改。这样成员函数才知道自己修改的成员变量是哪个对象的。

this是一个隐藏的指针，可以在类的成员函数中使用，它可以用来指向调用对象。当一个对象的成员函数被调用时，编译器会隐式地传递该对象的地址作为 this 指针。

编译器在生成程序时加入了获取对象首地址的相关代码，将获取的首地址存放在了寄存器中，这就是this指针。

this 指针的生命周期开始于成员函数的执行开始。当一个非静态成员函数被调用时，this 指针被自动设置为指向调用该函数的对象实例。在成员函数执行期间，this 指针一直有效。它可以被用来访问调用对象的成员变量和成员函数。this指针的生命周期结束于成员函数的执行结束。当成员函数返回时，this指针的作用范围就结束了。

理解一下问题：

1. 对象调用函数时，是如何找到自己本对象的数据成员的？ 通过this指针 
2. this指针代表的是什么？本对象
3. this指针在参数列表中的什么位置？参数列表的第一位
4. this指针的形式是什么？类名*const this

~~~c++
Point & operator=(const Point & rhs){
    this->_ix = rhs._ix;
    this->_iy = rhs._iy;
    cout << "Point & operator=(const Point &)" << endl;
    return *this;
}
~~~

如果对象的指针数据成员申请了堆空间，那么就不能使用默认的运算符函数。如果直接采用默认的赋值运算符函数，`_brand`指针成员就会进行浅拷贝。需要进行深拷贝：

~~~c++
class Computer {
public:
   Computer(const char * brand,int price)
   :_brand(new char[strlen(brand) + 1]())
   ,_price(price){
        strcpy(_brand,brand);
   }
   Computer(const Computer & rhs)//手动定义拷贝构造函数
   :_brand(new char[strlen(rhs._brand)+1]())
   ,_price(rhs._price){
        strcpy(_brand,rhs._brand);
   }
   ~Computer(){
        if(_brand){
            delete[] _brand;
            _brand = nullptr;
            cout<<"~Computer()"<<endl;
        }
   }
   Computer& operator=(const Computer &rhs){
        if(this!=&rhs){
            delete []this->_brand;
            this->_brand = new char[strlen(rhs._brand)+1]();
            strcpy(this->_brand,rhs._brand);
            this->_price = rhs._price;
        }
        return *this;
   }
   void print();
private:
   char * _brand;
   float _price;
};
int main(){
    Computer pc1("Apple",15000),pc2("huawei",8000);
    pc1.print();
    pc1 = pc2;
    pc1.print();
    pc2.print();
    return 0;
}
~~~

#### 三合成原则

**拷贝构造函数、赋值运算符函数、析构函数，如果需要手动定义其中的一个，那么另外两 个也需要手动定义。**

### 特殊的数据成员

#### 常量数据成员

当数据成员用 const 关键字进行修饰以后，就成为常量成员。一经初始化，该数据成员便具有“只读属性”，在程序中无法对其值修改。事实上，在构造函数体内对const 数据成员赋值是非法的， **const数据成员需在初始化列表中进行初始化**（C++11之后也允许在声明时就初始化）。

const成员初始化后也不再允许修改值。

~~~c++
class Point {
public:
    Point(int ix, int iy)
    : _ix(ix)
    , _iy(iy)
    {}
private:
    const int _ix;
    const int _iy;
};
~~~

#### 引用数据成员

引用数据成员在初始化列表中进行初始化，C++11之后允许在声明时初始化（绑定）。 之前的学习中，我们知道了引用要绑定到已经存在的变量，引用成员同样如此。

~~~c++
class Point {
public:
    Point(int ix, int iy)
    : _ix(ix)
    , _iy(iy)
    , _iz(_ix)
    {}
private:
    const int _ix;
    const int _iy;
    int & _iz;
};
~~~

#### 对象成员

有时候，一个类对象会作为另一个类对象的数据成员被使用。比如一个直线类Line对象中 包含两个Point对象。

对象成员必须在初始化列表中进行初始化。

注意： 

1. 不能在声明对象成员时就去创建。
2. 初始化列表中写的是需要被初始化的对象成员的名称，而不是对象成员的类名。

~~~c++
class Line {
public:
    Line(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1)
    , _pt2(x2, y2)
    {
    	cout << "Line(int,int,int,int)" << endl;
    }
private:
    Point _pt1;
    Point _pt2;
};
~~~

此例子中，创建一个Line类的对象，会首先调用Line的构造函数，在此过程中调用Point的构造函数完成Point类对象成员的初始化；Line对象销毁时会先调用Line的析构函数，析构函数执行完后，再调用Point的析构函数。

#### 静态数据成员

C++ 允许使用 static （静态存储）修饰数据成员，这样的成员在编译时就被创建并初始化 的（与之相比，对象是在运行时被创建的），且其实例只有一个，被所有该类的对象共 享，就像住在同一宿舍里的同学共享一个房间号一样。静态数据成员和之前介绍的静态变 量一样，当程序执行时，该成员已经存在，一直到程序结束，任何该类对象都可对其进行 访问，静态数据成员存储在全局/静态区，并不占据对象的存储空间。

**静态数据成员被整个类的所有对象共享。**

~~~c++
class Computer {
public:
	//...    
private:
    char * _brand;
    double _price;
    //数据成员的类型前面加上static关键字
    //表示这是一个static数据成员（共享）
    static double _totalPrice;
};
double Computer::_totalPrice = 0;
~~~

静态成员规则：

1. private的静态数据成员无法在类之外直接访问。
2. 对于于静态数据成员的初始化，必须放在类外。
3. 静态数据成员初始化时不能在数据类型前面加static，在数据成员名前面要加上类名+作用域限定符
4. 如果有多条静态数据成员，那么它们的初始化顺序需要与声明顺序一致（规范）

### 特殊成员函数

#### 静态成员函数

在某一个成员函数的前面加上static关键字，这个函数就是静态成员函数。静态成员函数具有以下特点：

1. **静态成员函数不依赖于某一个对象**。
2. 静态成员函数可以通过对象调用，但更常见的方式是**通过类名加上作用域限定符调用**。
3. 静态成员函数没有this指针。
4. **静态成员函数无法直接访问非静态的成员**，只能访问静态数据成员或调用静态成员函 数（因为没有this指针）。

静态成员函数不能是构造函数/析构函数/赋值运算符函数/拷贝构造（因为这四个函数都 会访问所有的数据成员，而static成员函数没有this指针）

~~~c++
class Computer {
public:
   Computer(const char * brand,int price)
   :_brand(new char[strlen(brand) + 1]())
   ,_price(price){
        strcpy(_brand,brand);
   }
   Computer(const Computer & rhs)//手动定义拷贝构造函数
   :_brand(new char[strlen(rhs._brand)+1]())
   ,_price(rhs._price){
        strcpy(_brand,rhs._brand);
   }
   ~Computer(){
        if(_brand){
            delete[] _brand;
            _brand = nullptr;
            cout<<"~Computer()"<<endl;
        }
   }
   void print();
   static void printTotalPrice(){
        cout<<"total Price:"<<_totalPrice<<endl;
        //cout<<_price<<endl;//error
   }
private:
   char * _brand;
   float _price;
   static double _totalPrice;
};
double Computer::_totalPrice = 30000;  // 静态成员变量初始化

void Computer::print(){
    cout<<_brand<<" "<<_price<<endl;
}

int main(){
    Computer::printTotalPrice();

    return 0;
}
~~~

#### const成员函数

const 在类成员函数中还有种特殊的用 法。在成员函数的参数列表之后，函数执行体之前加上const关键字，这个函数就是const 成员函数。

~~~c++
class Computer{
public:
    //...
    void print const{
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }
    //...
};
~~~

const成员函数中，不能修改对象的数据成员；

当编译器发现该函数是const成员函数时，会自动将this指针设置为双重const限定的指 针；

### 对象的组织

#### const对象

类对象也可以声明为 const 对象，一般来说，能作用于 const 对象的成员函数除了构造函 数和析构函数，就只有 const 成员函数了。因为 const 对象只能被创建、撤销和只读访 问，写操作是不允许的。

const对象与const成员函数的规则：

1. 当类中有const成员函数和非const成员函数重载时，const对象会调用const成员函数， 非const对象会调用非const成员函数；
2. 当类中只有一个const成员函数时，无论const对象还是非const对象都可以调用这个版 本；
3. 当类中只有一个非const成员函数时，const对象就不能调用非const版本。

**总结：如果一个成员函数中确定不会修改数据成员，就把它定义为const成员函数。**

#### 指向对象的指针

对象占据一定的内存空间，和普通变量一致， C++ 程序中采用如下形式声明指向对象的指针：

~~~c++
类名 *指针名 [=初始化表达式];
~~~

初始化表达式是可选的，既可以通过取地址（&对象名）给指针初始化，也可以通过申请动 态内存给指针初始化，或者干脆不初始化（比如置为 nullptr ），在程序中再对该指针赋 值。指针中存储的是对象所占内存空间的首地址。针对上述定义，则下列形式都是合法的：

~~~c++
Point pt(1, 2);
Point * p1 = nullptr;
Point * p2 = &pt;
Point * p3 = new Point(3, 4);
~~~

#### 对象数组

对象数组的声明

~~~c++
Point pts[2];
~~~

这种格式会自动调用默认构造函数或所有参数都是缺省值的构造函数。

对象数组的初始化

~~~c++
Point pts[2] = {Point(1, 2), Point(3, 4)};
Point pts[] = {Point(1, 2), Point(3, 4)};
Point pts[5] = {Point(1, 2), Point(3, 4)};
//或者
Point pts[2] = {{1, 2}, {3, 4}};
Point pts[] = {{1, 2}, {3, 4}};
Point pts[5] = {{1, 2}, {3, 4}};
~~~

#### 堆对象

和把一个简单变量创建在动态存储区一样，可以用 new 和 delete 表达式为对象分配动态 存储区，在拷贝构造函数一节中已经介绍了为类内的指针成员分配动态内存的相关范例， 这里主要讨论如何为对象和对象数组动态分配内存。如：

~~~c++
void test()
{
    Point * pt1 = new Point(11, 12);
    pt1->print();
    delete pt1;
    pt1 = nullptr;
    
    Point * pt2 = new Point[5]();//注意
    pt2->print();
    (pt2 + 1)->print();
    delete [] pt2;
    pt2 = nullptr;
}
~~~

