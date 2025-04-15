#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

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
int main(){
    Computer pc;
    pc.setPrice(10000); //ok
    //pc._price; //error,因为_price是私有的
    return 0;
}