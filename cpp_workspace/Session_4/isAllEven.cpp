#include <algorithm>
#include <iostream>

int main (){

    int arr[] = {2,4,6,9,10}; //not all even
    int size = sizeof(arr)/sizeof(arr[0]);

    bool isAllEven = std::all_of(arr, arr+size,[](int i){return i%2==0;});
    if(isAllEven){
        std::cout << "All elements are even" << std::endl;
    }else{
        std::cout << "Not all elements are even" << std::endl;
    }



}

