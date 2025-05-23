#include <iostream>

int& refReturn(void){
   static int a = 5;
   //should be static so i can return it
   std::cout << a << std::endl;
    return a;
}

int main(){


refReturn() = 10;
// the variable is changed to 10
refReturn()= 7;

refReturn();

}