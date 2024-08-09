#include <iostream>
#include <ostream>
#include <string>
int main(){

    int Input = 0;
    std::cout << "Enter an integer: \n";
    std::cin >> Input;
    int sum  = 0;
    int sum1  = 0;

    std::string str= std::to_string(Input); 
    for(char i:str){
        sum += (i - '0');
    }

    //another mthod
    while(Input != 0){
        sum1 += (Input % 10);
        //std::cout << (Input % 10)<< std::endl;
        Input = Input / 10;
    }
   
    std::cout << "sum is:" << sum<< std::endl;
    std::cout << "sum1 is:" << sum1<< std::endl;

}
