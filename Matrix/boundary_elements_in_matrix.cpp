#include <iostream>
#include <vector>
using namespace std;

// to print all elements at the boundary of the matrix

vector<int> BoundaryElements(vector<vector<int>>&matrix){
    int n = matrix.size();
    vector<int> result;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            if(i == 0 || i == n-1 || j == 0 || j == n-1){
                result.push_back(matrix[i][j]);
            }
        }
    }
    return result;
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

// Driver code
int main(){
    vector<vector<int>> matrix = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    vector<int> res = BoundaryElements(matrix);
    for(int i: res){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}