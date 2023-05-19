#include <iostream>
using namespace std;
#define N 9

// Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits
// (from 1 to 9) to the empty cells so that every row, column, and subgrid of size
// 3×3 contains exactly one instance of the digits from 1 to 9.

// to check if solution for sudoku exists or not

bool isSafe(int grid[][N], int i, int j, int v){

    // Checking presence in the same row's left side
    for(int y=j; y>=0; y--){
        if(grid[i][y] == v) return false;
    }
        
    // Checking presence in the same row's right side
    for(int y=j; y<N; y++){
        if(grid[i][y] == v) return false;
    }
    
    // Checking presence in the same column's down side
    for(int x=i; x<N; x++){
        if(grid[x][j] == v) return false;
    }
        
    // Checking presence in the same column's up side
    for(int x=i; x>=0; x--){
        if(grid[x][j] == v) return false;
    }
        
    // Checking presence in same grid
    // (x,y) is the first element of the grid in which (i,j) is present
    int x = i - (i%3), y = j - (j%3);
    for(int a=0; a<3; a++){
        for(int b=0; b<3; b++){
            if(grid[x+a][y+b] == v) return false;
        }
    }

    return true;
}

// Function to print grids of the Sudoku.
void printGrid (int grid[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << grid[i][j] << " ";
        }
    }
}

void FILL(int grid[][N], int i, int j, bool &ans){
    if(ans == true) return;

    // Base Case, when all unfilled elements have been filled, safely..
    if(i == N-1 && j == N){
        ans = true;
        return;
    }

    if(j == N){
        i++;
        j = 0;
    }
        

    // if a valid value is present then updating it won't be safe
    if(grid[i][j] > 0) {FILL(grid, i, j+1, ans); return;}

    for(int a = 1; a <= N; a++){
        if(isSafe(grid, i, j, a)){
            // cout << i << j << a << " ";
            grid[i][j] = a;
            FILL(grid, i, j+1, ans);
			if(ans == true) return;
            grid[i][j] = 0;
        }
    }
}

bool SolveSudoku(int grid[][N])  
{
    bool ans = false;
    
    FILL(grid, 0, 0, ans);
    return ans;
}

// Time Complexity: O(9^(n*n))
// Auxiliary space: O(1)

int main(){
    // 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    cout << SolveSudoku(grid);
    return 0;
}