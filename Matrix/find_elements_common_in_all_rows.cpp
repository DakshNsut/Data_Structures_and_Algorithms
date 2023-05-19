#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define n 4
#define m 5

// to find elements common in all rows of a matrix

// -------------- METHOD - 1 ------------
int FindMinRow(int mat[][m], vector<int> &colPointers){
    int min_row = 0;
    for(int i=1; i<n; i++){
        if(mat[i][colPointers[i]] < mat[min_row][colPointers[min_row]]){
        min_row = i;
        }
    }
    return min_row;
}

bool isEqual(int mat[][m], vector<int> &colPointers){
    for(int i=0; i<n-1; i++){
        if(mat[i][colPointers[i]] != mat[i+1][colPointers[i+1]]){
        return false;
        }
    }
    return true;
}

void commonEle(int mat[][m], vector<int> &ans){
    // sort each row of the matrix
    for(int i=0; i<n; i++){
        sort(mat[i],mat[i]+m);
    }

    // Vector to store at which column the pointer is on each row
    vector<int> colPointers(n,0);
    int min_row = 0; // the row with min value
    while(1){
        if(isEqual(mat,colPointers)){
			ans.push_back(mat[0][colPointers[0]]);
			// Pointing each row to next column pointer
			for(int i=0; i<n; i++){
				colPointers[i]++;
				if(colPointers[i] == m){
					return;
				}
			}
        }
        else{
			min_row = FindMinRow(mat,colPointers); // returns index of colPointer containing the min value
			colPointers[min_row]++;
			if(colPointers[min_row] == m){
				return;
			}
        }
    }
    return;
}

// Time Complexity: O(m*n*log(n))
// Auxiliary space: O(n)

void print(vector<int> &ans){
    for(int i: ans){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int mat[4][5] = { {1, 2, 1, 4, 8}, {3, 7, 8, 5, 1}, {8, 7, 7, 3, 1}, {8, 1, 2, 7, 9} };
    vector<int> ans;
    commonEle(mat, ans);
    print(ans);
    return 0;
}

// -------------- Method - 2 -----------
void commonEle(int mat[][m], unordered_set<int> &ans){
    unordered_map<int,int> map; // to store frequency of first row elements in each row of the matrix

    // Store elements of first row
    for(int i=0; i<m; i++){
        if(map[mat[0][i]] == 0){ // To store only distinct elements
			map[mat[0][i]] = 1;
        }
    }

    // increment value of element in the map if found in the row
    // Traversing each row
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
			if(map[mat[i][j]] != 0 && map[mat[i][j]] == i){
				map[mat[i][j]]++;
			}
        }
    }

    // Traversing the map to check if value of any element == n-1
    for(int i=0; i<m; i++){
        if(map[mat[0][i]] == n){
        ans.insert(mat[0][i]);
        }
    }
}

// Time Complexity: O(n*m)
// Auxiliary space: O(n)

void print(unordered_set<int> &ans){
    for(int i: ans){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int mat[4][5] = { {1, 2, 1, 4, 8}, {3, 7, 8, 5, 1}, {8, 7, 7, 3, 1}, {8, 1, 2, 7, 9} };
    unordered_set<int> ans;
    commonEle(mat, ans);
    print(ans);
    return 0;
}