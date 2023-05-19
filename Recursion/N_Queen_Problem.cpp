#include<iostream>
#include<vector>
using namespace std;

#define n 4
bool isSafe(vector<vector<int>> &chess, int r, int c){
    // Note: we will always check at the left because no element is put at the right
    // Putting elements is done from left to right
    // Checking if any queen is already placed in the left side "row" of this queen which is to be placed
    for(int j = 0; j<c; j++){
        if(chess[r][j]){
            return false;
        }
    }

    // Checking if any queen is already placed at left side upper diagonal of this queen which is to be placed
    // 
    //     / * * * *
    //     * / * * *
    //     * * / * *
    //     * * * & *
    //     * * * * *
    // 
    for(int i=r, j=c; i>=0 && j>=0; i--, j-- ){
        if(chess[i][j]){
            return false;
        }
    }

    // Checking if any queen is already placed at left side lower diagonal of this queen which is to be placed
    // 
    //     * * * * *
    //     * * * & *
    //     * * / * *
    //     * / * * *
    //     / * * * *
    //
    for(int i=r, j=c; j>=0 && i<n; i++, j--){
        if(chess[i][j]){
            return false;
        }
    }
    return true;
}

bool N_Queen(vector<vector<int>> &chess, int col){

    if(col>=n){
        return true;
    }

    for(int i=0; i<n; i++){
        if(isSafe(chess, i, col)){
            chess[i][col] = 1;

            if(N_Queen(chess, col+1)){
                return true;
            }

            // Backtracking, when queen could not be placed in this way, go to other way to find the best solution
            chess[i][col] = 0;
        }
    }
    return false;
}

// Time Complexity: O(n!)
// Auxiliary Space: O(n^2)

int main(){
    vector<vector<int>> chess = { {0, 0, 0, 0}, 
                                  {0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 0, 0} };

    N_Queen(chess, 0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// ------------------------------------------------------ A variation ------------------------------------------------------
// Print all possible solutions
// place one queen in one column, print the row corresponding to each column where the queen is placed

bool isSafe(vector<vector<int>> &chess, int n, int x, int y){
        int i = x, j = y;
        while(i>=0 && i<n && j>=0 && j<n){
            if(chess[i][j] == 1) return false;
            j--;
        }

        i = x, j = y;
        while(i>=0 && i<n && j>=0 && j<n){
            if(chess[i][j] == 1) return false;
            j++;
        }

        i = x, j = y;
        while(i>=0 && i<n && j>=0 && j<n){
            if(chess[i][j] == 1) return false;
            i++;
        }

        i = x, j = y;
        while(i>=0 && i<n && j>=0 && j<n){
            if(chess[i][j] == 1) return false;
            i--;
        }

        i = x, j = y;
        while(i>=0 && i<n && j>=0 && j<n){
            if(chess[i][j] == 1) return false;
            i--; j--;
        }

        i = x, j = y;
        while(i>=0 && i<n && j>=0 && j<n){
            if(chess[i][j] == 1) return false;
            i++; j++;
        }

        i = x, j = y;
        while(i>=0 && i<n && j>=0 && j<n){
            if(chess[i][j] == 1) return false;
            i--; j++;
        }

        i = x, j = y;
        while(i>=0 && i<n && j>=0 && j<n){
            if(chess[i][j] == 1) return false;
            i++; j--;
        }

        return true;
    }

void Traverse(vector<vector<int>> &chess, int n, int j, vector<int> &curr, vector<vector<int>> &ans){
        if(j == n){
            ans.push_back(curr);
            return;
        }

        for(int i=0; i<n; i++){
            if(isSafe(chess, n, i, j)){
                curr.push_back(i+1);
                chess[i][j] = 1;
                Traverse(chess, n, j+1, curr, ans);
                chess[i][j] = 0;
                curr.pop_back();
            }
        }
    }

vector<vector<int>> nQueen(int n) {
        vector<vector<int>> chess(n, vector<int> (n,0));
        vector<vector<int>> ans;
        vector<int> curr;
        
        // Traversing 0th column and ith row
        for(int i=0; i<n; i++){
            curr.push_back(i+1);
            chess[i][0] = 1;
            Traverse(chess, n, 1, curr, ans);
            chess[i][0] = 0;
            curr.pop_back();
        }
        
        return ans;
    }

int main(){
    vector<vector<int>> ans = nQueen(4);
    for(vector<int> &v : ans){
        for(int i: v) cout << i << " ";
        cout << endl;
    }

    return 0;
}