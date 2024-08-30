#include <algorithm>
#include <iostream>

int main (){

    int arr[] = {1,2,5,9,11}; //not all even
    int size = sizeof(arr)/sizeof(arr[0]);
//check if odd
    bool isAllOdd = std::all_of(arr, arr+size,[](int i){return i%2!=0;});
    if(!isAllOdd){
        std::cout << "There is an even in the array" << std::endl;
    }else{
        std::cout << "All are odd" << std::endl;
    }



}

