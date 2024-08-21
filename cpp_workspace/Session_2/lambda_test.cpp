#include <iostream>
#include <ostream>


int main(){

    int btnganal = 10;

    auto lambda = [btnganal](int num1, int num2){
        std::cout << num1 + num2 + btnganal << std::endl;
    };

    lambda(2, 3);

    return 0;
}
