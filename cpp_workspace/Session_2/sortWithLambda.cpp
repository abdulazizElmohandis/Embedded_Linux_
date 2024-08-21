#include <algorithm>
#include <iostream>

int main(){

    int arr[10] = {3,6,16,57,85,12,99
    ,56,93,1,};


    std::sort(arr, arr+9,[](int a, int b){return a > b;});
    std::cout << "Sorted Descending Array:" << std::endl;
    for (int num : arr){
        std::cout << num << ", ";
    }
    std::cout << std::endl;


    std::sort(arr, arr+9);


    std::cout << "Sorted Ascending Array:" << std::endl;

    for (int num : arr){
        std::cout << num << ", ";
    }
}