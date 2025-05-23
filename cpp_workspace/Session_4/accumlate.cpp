#include <iostream>
#include <numeric>

int main (){

    int arr[] = {2,4,6,9,10}; //not all even
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    // std::accumulate is used to sum the elements of the array
    sum = std::accumulate(arr, arr+size, 0);
    std::cout << "The sum of the elements is: " << sum << std::endl;
}