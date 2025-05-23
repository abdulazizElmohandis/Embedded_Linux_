#include <iostream>
#include <vector>


using namespace std;


int main(){

    vector<int> v = {1,2,3};


    for(int x : v){ 
        cout << x << endl;
    }


    v.push_back(4);
   



    for(int x : v){ 
        cout << x << endl;
    }
    return 0;

}