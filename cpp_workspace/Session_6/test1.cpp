#include <iostream>



class Data {
public:
    std::string msg; 
    // Constructor that takes a std::string
    Data( std::string str) : msg(str){}
};

int main(){
    // Create a temporary std::string object
    std::string str = "Hello, World!";
    // Pass the temporary std::string object to the Data constructor
    Data data(str);
    Data d2 = std::string("Hello, World!");
    std::cout << d2.msg << std::endl;
    return 0;
}