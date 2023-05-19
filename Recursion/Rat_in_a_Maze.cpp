#include<iostream>
#include<vector>
#include<string>
#define n 4
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &m, vector<vector<int>> &visited){
    if((x<n && x>=0) && (y<n && y>=0) && m[x][y] == 1 && visited[x][y] == 0){
        return true;
    }
    return false;
}

void rat_in_maze(vector<vector<int>> &m, vector<string> &ans, vector<vector<int>> &visited, string &curr, int i, int j){
    if(i == n-1 && j==n-1){
        ans.push_back(curr);
        return;
    }

    visited[i][j] = 1;

    // Move DOWN
    if(isSafe(i+1, j, m, visited)){
        curr.push_back('D');
        rat_in_maze(m, ans, visited, curr, i+1 ,j);

        // Backtracking, so that we can go to a next possible path
        curr.pop_back();
    }

    // Move UP
    if(isSafe(i-1, j, m, visited)){
        curr.push_back('U');
        rat_in_maze(m, ans, visited, curr, i-1 ,j);

        curr.pop_back();
    }

    // Move LEFT
    if(isSafe(i, j-1, m, visited)){
        curr.push_back('L');
        rat_in_maze(m, ans, visited, curr, i , j-1);

        curr.pop_back();
    }

    // Move RIGHT
    if(isSafe(i, j+1, m, visited)){

        curr.push_back('R');
        rat_in_maze(m, ans, visited, curr, i, j+1);

        curr.pop_back();
    }

    // Going back after seeing all paths
    visited[i][j] = 0;
}

// Time Complexity: O(3^(n^2))
// Auxiliary space: O(n^2)

int main(){
    vector<vector<int>> m = { {1, 0, 0 ,0} , {1, 1, 0, 1} , {1, 1, 0, 0} , {0, 1, 1, 1} };
    vector<vector<int>> visited = { {0, 0, 0 ,0} , {0, 0, 0, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} };

    vector<string> ans;
    string curr;
    int i=0, j=0;
    if(m[0][0]){
        rat_in_maze(m, ans, visited, curr,i ,j);
    }

    for(string s:ans){
        cout << s << endl;
    }
}