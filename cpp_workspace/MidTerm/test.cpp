#include <iostream>
#include <vector>


using namespace std;

int main() {

    int *ptr = new int;

    *ptr = 5;
    
    delete ptr;
    delete ptr;
    cout << "im here";
    return 0;
}

