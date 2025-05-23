#include <iostream>
#include <algorithm>
#include <numeric>
int main(){

    int arr[10] = {0};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    std::iota(arr, arr+size, 0);
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
   //another way to fill the array sequentially
    int arr1[10] = {0};
    int size1 = sizeof(arr)/sizeof(arr[0]);

    std::generate_n(arr1, size1, []()  {static int n = 0; return n++; });
//another way*******************
    // std::generate_n(arr1, size1, [n = 0]() mutable {return n++; });
    // mutable is used to change the value of n (increment it)
    // The type of n is deduced from the value 0.

    for(int i = 0; i < size1; i++){
        std::cout << arr1[i] << " ";
    }
    return 0;
}