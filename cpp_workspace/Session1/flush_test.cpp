#include <iostream>
int main() {

    std::cout << "Hello Wolrd"; // This is buffered, not flushed
    std::cout << std::flush; //flush the buffer
    std::cout << "Hello Wolrd"<< std::endl; // This is flushed immediately
    return 0;
}