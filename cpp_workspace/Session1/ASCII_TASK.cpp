#include <iostream>
int main(){

    std::cout << "ASCII Table" << std::endl;
    std::cout << "+-----+-----+--" << std::endl;
    std::cout << "| Char | ASCII |" << std::endl;
    std::cout << "+-----+-----+--" << std::endl;
    for (char i = 0; i < 127; i++)
    {
        std::cout << "|  " << i << "  |  "<<(int)i << "  |"<<std::endl; 
    }
    std::cout << "+-----+-----+--" << std::endl;


}
