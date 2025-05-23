#include <iostream>
#include <vector>


using namespace std;

int main(){

    //2d array example  
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    cout << arr[0][0] << endl;
    cout << arr[0][1] << endl;
    cout << arr[0][2] << endl;
    cout << arr[1][0] << endl;
    cout << arr[1][1] << endl;
    cout << arr[1][2] << endl;
    cout << arr[2][0] << endl;

    //iterate over 2d array
    cout << "Iterating over 2d array" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

  
    


    return 0;
}