#include <iostream>


using namespace std;

    int add(int a, int b) {
    return a + b;
}
//function ptoroype
int max(int a, int b);

//function pass array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void doubleValues(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] *= 2; // Modify array elements
    }
}

void print(int a) {
    cout << "Integer: " << a << endl;
}


void print(int a, int b) {
    cout << "Two Integers: " << a << ", " << b << endl;
}

void print(float a, float b = 1) {
    cout << "Float Sum: " << a + b << endl;
}

void print(float a, int b) {
    cout << "Float Sum: " << a + b << endl;
}

void print(int a, float b) {
    cout << "Float Sum: " << a + b << endl;
}


void countCalls() {
    static int counter = 0; // Static variable, retains its value between calls
    counter++;
    cout << "This function has been called " << counter << " times." << endl;
}

template <typename T>
T addTemp(T a, T b) {
return a + b;
}

int main(){

    //function example
    int x = 5;
    int y = 10;
    cout << "Sum of x and y: " << add(x, y) << endl;
    //function call
    cout << "x = "<< x << ", y = " << y << endl;
    cout << "Max of x and y: " << max(x, y) << endl;

    //pass array to function
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printArray(numbers, size); // Pass array and size
    doubleValues(numbers, size); // Pass array and size
    printArray(numbers, size);

    print(10);          // Calls print(int)
    print(10, 20); 
    
    //1. Overloading by Number of Parameters
    //2. Overloading by Data Type
    //3. Overloading by Sequence of Data Type
    cout<< "default..." << endl;
    print(3.3f);         // Calls float version with default b
    print(3.3f, 4.4f);   

    countCalls(); // First call
    countCalls(); // Second call
    countCalls(); // Third call
    
    cout << "Sum of integers: " << addTemp(5.5, 10.8) << endl;    // T replaced with int
    // cout << "Sum of doubles: " << addTemp(5.5, 10.1) << endl; // T replaced with double
    // cout << "Sum of floats: " << addTemp(3.3f, 4.4f) << endl; // T replaced with float
    
    return 0;

}

//function definition (body)
int max(int a, int b) {
    return (a > b) ? a : b;
}