#include <iostream>



int main(){

    int x = 5;
    switch (x) {
        case 1:
            std::cout << "x is 1" << std::endl;
            break;
        case 2:
            std::cout << "x is 2" << std::endl;
            break;
        case 3:
            std::cout << "x is 3" << std::endl;
            break;
        case 4:
            std::cout << "x is 4" << std::endl;
            break;
        case 5:
            std::cout << "x is 5" << std::endl;
            break;
        default:
            std::cout << "x is not 1, 2, 3, 4, or 5" << std::endl;
    
    }
    return 0;
}