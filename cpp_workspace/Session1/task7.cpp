#include <bitset>
#include <iostream>
#include <string>
int main(){

int num = 0;
std::string binaryStr;

std::cout << "Enter a decimal num:\n";
std::cin >> num;
std::bitset<8> b(num);
std::string binaryRep = b.to_string();

std::cout << "Enter a binary 8-bit num:\n";
std::cin >> binaryStr;
std::bitset<8> b1(binaryStr);

std::cout << "decimal ----> binary: "<<binaryRep << std::endl ;
std::cout << "binary  ----> decimal: "<< b1.to_ulong() << std::endl ;




}