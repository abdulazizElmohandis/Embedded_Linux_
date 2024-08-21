#include <iostream>


auto square = [](int a){

return (a*a);

};

int main (){

    int num = 8;

    std::cout << "square is : " << square(num) << std::endl;

    return 0;
}