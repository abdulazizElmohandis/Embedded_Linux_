#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. Vector Initialization
    vector<int> vec1; // Empty vector
    vector<int> vec2 = {1, 2, 3, 4, 5}; // Initialized with values
    vector<int> vec3(5, 10); // Vector of size 5, all elements initialized to 10

    cout << "Vector 1 (empty): ";
    for (int n : vec1) cout << n << " ";
    cout << endl;

    cout << "Vector 2 (initialized with values): ";
    for (int n : vec2) cout << n << " ";
    cout << endl;

    cout << "Vector 3 (5 elements initialized to 10): ";
    for (int n : vec3) cout << n << " ";
    cout << endl;

    // 2. Adding Elements to Vector
    vec2.push_back(7); // Add single element to the end


    cout << "Vector 2 (initialized with values): ";
    for (int n : vec2) cout << n << " ";
    cout << endl;
    vec1.push_back(14);
    cout << "\nAfter adding elements to vec1: ";
    for (int n : vec1) cout << n << " ";
    cout << endl;

    // 3. Pop Elements from Vector
    vec1.pop_back(); // Removes the last element
    cout << "\nAfter popping the last element from vec1: ";
    for (int n : vec1) cout << n << " ";
    cout << endl;

    // 4. Indexing - Accessing Elements using []
    cout << "\nAccessing 2nd element in vec2: " << vec2[1] << endl; // Indexing starts from 0
    cout << "Accessing 4th element in vec2: " << vec2[3] << endl;

    vec2.at(2) = 100; // Change the value of the 3rd element

    // 5. Accessing Elements using at() method (safer than [] operator)
    cout << "\nAccessing 3rd element using at(): " << vec2.at(2) << endl; // Will throw exception if out of bounds

    // 6. Range-based for loop
    cout << "\nUsing range-based for loop to display vec2: ";
    for (auto n : vec2) {
        cout << n << " ";
    }
    cout << endl;

    // 7. Common Functions with Vectors

    // Size of the vector
    cout << "\nSize of vec2: " << vec2.size() << endl;

    // Capacity of the vector (capacity may be greater than size)
    cout << "Capacity of vec2: " << vec2.capacity() << endl;

    // Clear the entire vector
    vec2.clear();
    cout << "\nAfter clearing vec2, size is: " << vec2.capacity()<< endl;

    // Checking if the vector is empty
    if (vec2.empty()) {
        cout << "vec2 is now empty!" << endl;
    }

    // Re-initialize vec2 with elements for other functions
    vec2 = {10, 20, 30, 40, 50};
    cout << vec2.at(16);


    // Erasing an element from the vector
    vec2.erase(vec2.begin() + 2); // Removes the element at index 2 (value 30)
    cout << "\nAfter erasing the element at index 2 from vec2: ";
    for (auto n : vec2) cout << n << " ";
    cout << endl;

    // Inserting an element at a specific position
    vec2.insert(vec2.begin() + 2, 35); // Inserts 35 at index 2
    cout << "\nAfter inserting 35 at index 2 in vec2: ";
    for (auto n : vec2) cout << n << " ";
    cout << endl;

    //interate over vector using iterator
    cout << "\nIterating over vec2 using iterator: ";
    for (auto it = vec2.begin(); it != vec2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //interate over vector using back iterator 
    cout << "\nIterating over vec2 using reverse iterator: ";
    for (auto it = vec2.rbegin(); it != vec2.rend(); ++it) {
        cout << *it << " ";
    }


    return 0;
}
