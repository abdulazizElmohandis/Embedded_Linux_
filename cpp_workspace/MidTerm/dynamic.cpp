#include <iostream>
#include <vector>


using namespace std;

int main(){

//dynamic memory allocation
//allocate memory for an integer
int *ptr = new int;
*ptr = 5;

cout << "Value: " << *ptr << endl;
//delete memory
delete ptr;

//allocate memory for an array of integers
int *arr = new int[5];
arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5;

delete[] arr;
cout<< arr[0] << endl;

return 0;

}