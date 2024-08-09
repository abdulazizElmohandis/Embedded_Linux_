#include <iostream>
#include <ostream>
int main(){

    std::cout << "Enter three nums:\n";
    int num = 0, num1 = 0, num3 = 0;
    std::cin >> num >> num1 >> num3;
    int max = num;

    if(max < num1)
        max = num1;

    if(max < num3)
        max = num3;

    std::cout << "max is :" << max <<std::endl;

}
