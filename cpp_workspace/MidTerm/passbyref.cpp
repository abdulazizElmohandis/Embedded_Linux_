#include <iostream>
using namespace std;





void modifyWithPointer(int* ptr) {
    *ptr = 100; // Modify the value of the variable via pointer
}

void modifyWithReference(int& ref) {
    ref = 200; // Modify the value of the variable via reference
}

int main() {
    int  x = 10;

    // Using a pointer
    cout << "Original value of x: " << x << endl;
    modifyWithPointer(&x); // Pass address of x
    cout << "Value of x after modifyWithPointer: " << x << endl;

    // Using a reference
    modifyWithReference(x); // Pass x as reference
    cout << "Value of x after modifyWithReference: " << x << endl;

    return 0;
}
