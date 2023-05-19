#include <iostream>
#include <climits>
using namespace std;

int main(){
    int *jagged[10000];
    int size[10000];

    int n;
    cout << "nrows = ?" << endl;
    cin >> n;

    // Entering data
    for(int i=0; i<n; i++){
        int m;
        cout << "ncols = ?" << endl;
        cin >> m;
        size[i] = m;
        jagged[i] = new int[m];
        cout << "Enter items: " << endl;
        for(int j=0; j<m; j++){
            cin >> jagged[i][j];
        }
    }

    cout << endl << "2-D aray entered was" << endl;

    // Outputting data
    for(int i=0; i<n; i++){
        int *arr = jagged[i];
        for(int j=0; j<size[i]; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(n*m)
// Auxiliary space: O(1)