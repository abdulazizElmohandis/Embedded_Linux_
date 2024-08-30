#include <iostream>


int main(){

std::cout << "Enter a character: ";
char c;
std::cin >> c;
std::cout << (isdigit(c)? "its a digit":"Not a digit") << std::endl;

}