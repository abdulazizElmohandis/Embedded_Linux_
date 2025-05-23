#include <iostream>
#include <vector>


using namespace std;

int main(){


    //ptr example
    int x = 5;
    int *ptr = &x;
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << " ptr: " << ptr << endl;
    cout << " *ptr: " << *ptr << endl;
    cout << " &ptr: " << &ptr << endl;
    cout << " &(*ptr): " << &(*ptr) << endl;

    // ptr to array

    int arr[5] = {1,2,3,4,5};
    int *ptr2 = arr;
    cout << "Value of arr[0]: " << arr[0] << endl;
    cout << "Address of arr[0]: " << &arr[0] << endl;

    cout << " *ptr2: " << *ptr2 << endl;

    //iterate over array using ptr

    cout << "Iterating over array using ptr" << endl;
    for(int i = 0; i < 5; i++){
        cout << *ptr2 << " ";
        ptr2++;
    }
    cout << endl;
    // using array name as ptr

    cout << "Iterating over array using array name as ptr" << endl;
    for(int i = 0; i < 5; i++){
        cout << *(arr+i) << " ";
    }


    //REFRENCE EXAMPLE
    int const y = 10;
    int *ptrc = &y;
    *(ptrc) = 20;
    cout << "Value of ref: " << *ptrc << endl;



    return 0;
}