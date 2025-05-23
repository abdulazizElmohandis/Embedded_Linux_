#include <iostream>
using namespace std;

// 1. Define a struct with and without typedef
struct Point {
    int x, y;
};


// Using typedef with struct
typedef struct {
    int width, height;
    float arr[5];
    char name[10];
} Rectangle;

struct student
{
   std::string name;
   int gpa;
   int age; 
};

int main() {
    // 2. Struct Initialization and Access without typedef
    student john;
    
    Point p1;
    Point p5;  // Declare a structure variable
    p1.x = 10;
    p1.y = 20;
    

    cout << "Without typedef, Accessing structure members:" << endl;
    cout << "p1.x = " << p1.x << ", p1.y = " << p1.y << endl;

    // Accessing structure members using pointer
    Point* ptr1 = &p1;
    cout << "Accessing members using pointer (ptr1):" << endl;
    cout << "ptr1->x = " << ptr1->x << ", ptr1->y = " << ptr1->y << endl;

    // 3. Struct Initialization and Access with typedef

    Rectangle r1;  // Declare a structure variable
    r1.width = 30;
    r1.height = 40;

    cout << "\nWith typedef, Accessing structure members:" << endl;
    cout << "r1.width = " << r1.width << ", r1.height = " << r1.height << endl;

    // Accessing structure members using pointer
    Rectangle* ptr2 = &r1;
    cout << "Accessing members using pointer (ptr2):" << endl;
    cout << "ptr2->width = " << ptr2->width << ", ptr2->height = " << ptr2->height << endl;

    // 4. Accessing members using dot operator and pointer-to-member syntax
    cout << "\nAccessing members using dot operator and pointer-to-member:" << endl;
    cout << "(*ptr2).width = " << (*ptr2).width << ", (*ptr2).height = " << (*ptr2).height << endl;

    // 5. Struct Initialization with an Inline Initialization List
    Point p2 = {50, 60};
    cout << "\nInline initialization (p2): p2.x = " << p2.x << ", p2.y = " << p2.y << endl;

    // 6. Accessing struct members using reference
    Point& ref1 = p2;
    cout << "\nAccessing struct members using reference (ref1): ref1.x = " << ref1.x << ", ref1.y = " << ref1.y << endl;

    return 0;
}
