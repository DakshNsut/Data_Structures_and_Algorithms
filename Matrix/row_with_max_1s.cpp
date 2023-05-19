#include <iostream>
#include <vector>
using namespace std;

// to find the 0-based index of row with maximum number of 1's in a binary matrix

int rowWithMax1s(vector<vector<bool>> arr, int n, int m) {
    int max_row_index = 0; // Initialize the first row with row with max 1s
    int max_so_far = m; // rightmost index of 1 found so far in rows 0 to i-1
    for(int i=0; i<n; i++){ // Going to each row
        bool flag = false; // to check if this row has more number of 1's
        while(max_so_far>=1 && arr[i][max_so_far-1] == 1){
            max_so_far--;
            flag = true;
        }
        if(flag){
            max_row_index = i;
        }
    }
    if(max_so_far == m){
        return -1;
    }
    return max_row_index;
}

int main(){
    vector<vector<bool>> mat = { {0, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0} };
    cout << rowWithMax1s(mat,4,4);
    return 0;
}