#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    vector<int> v;

    int n = 3;
    cout << "enter no of elements" << endl;

    cin >> n; 
    int num;
    for(int i = 0; i < n; i++){
        
        cout << "enter element no.:" << i+1 << " =";
        cin >> num;
        if(num % 2 != 0){
            cout << "no. is not even not acceptes\n";
            i--;
            continue;
        }

        v.push_back(num);
    }

    cout << "sorted vector:";
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    }