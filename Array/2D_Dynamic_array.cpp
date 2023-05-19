#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    // Creating 2-D array
    int **arr = new int* [n];
    for(int i = 0; i<n; i++){
        arr[i] = new int[m];
    }

    // Storing values to the array
    for(int i=0; i<n; i++){
        for(int j=0; j<m ; j++){
            cin >> arr[i][j];
        }
    }

    // Printing the array
    cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}

// Time Complexity: O(n*m)