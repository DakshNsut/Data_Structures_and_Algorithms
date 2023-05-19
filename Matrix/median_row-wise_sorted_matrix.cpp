#include <iostream>
#include <vector>
using namespace std;

// to find median in a row-wise sorted matrix

int CountLessorEqual(vector<int> &row, int k){
    int l = 0;
    int h = row.size() - 1;
    int mid;
    while(l<=h){
        mid = l+((h-l)>>1);
        if(row[mid] <= k){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return l;
}

int median(vector<vector<int>> &matrix, int R, int C){
    int l = 1;
    int h = 1e9;
    int mid;
    while(l<=h){
        mid = l+((h-l)>>1);
        int count = 0;
        for(int i=0; i<R; i++){
            count += CountLessorEqual(matrix[i],mid); // upper_bound can also be used instead
        }
        if(count <= ((R*C)>>1)){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return l;
}

// Time Complexity: O(R*logC)
// Auxiliary space: O(1)

int main(){
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << median(matrix,3,3);
    return 0;
}