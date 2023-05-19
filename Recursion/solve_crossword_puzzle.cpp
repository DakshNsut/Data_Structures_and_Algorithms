#include <iostream>
#include <vector>
using namespace std;

// find word in a crossword puzzle

int solve(vector<vector<char>> &mat, string &str){
    int count = 0; // count of places where the word was present
    int r = mat.size(); // No. of rows
    int c = mat[0].size(); // No. of columns
    int size = str.size(); // size of string to be found

    // Checking top-bottom
    for(int j=0; j<c; j++){
        int k = 0; // pointer to str as its index
        for(int i=0; i<r; i++){
            if(mat[i][j] == str[k]){
                k++;
                // if all characters were matched
                if(k==size){
                    count++;
                    break;
                }
            }
            else{
                break;
            }
        }
    }

    // Checking bottom-top
    for(int j=0; j<c; j++){
        int k = 0; // pointer to str as its index
        for(int i=r-1; i>=0; i--){
            if(mat[i][j] == str[k]){
                k++;
                // if all characters were matched
                if(k==size){
                    count++;
                    break;
                }
            }
            else{
                break;
            }
        }
    }

    // Checking left to right
    for(int i=0; i<r; i++){
        int k = 0; // pointer to str as its index
        for(int j=0; j<c; j++){
            if(mat[i][j] == str[k]){
                k++;
                // if all characters were matched
                if(k==size){
                    count++;
                    break;
                }
            }
            else{
                break;
            }
        }
    }

    // Checking right to left
    for(int i=0; i<r; i++){
        int k = 0; // pointer to str as its index
        for(int j=c-1; j>=0; j--){
            if(mat[i][j] == str[k]){
                k++;
                // if all characters were matched
                if(k==size){
                    count++;
                    break;
                }
            }
            else{
                break;
            }
        }
    }

    return count;
}

// Time Complexity: O(R*C)
// Auxiliary space: O(1)

int main(){
    vector<vector<char> > board = { { 'o', 'a', 'a', 'n' }, { 'e', 't', 'a', 'e' }, { 'i', 'h', 'k', 'r' }, { 'i', 'f', 'l', 'v' } };
    vector<string> words = { "oath", "pea", "eat", "rain" };
    for(string &s: words){
        cout << solve(board, s) << endl;
    }
    return 0;
}

// ------------- another variation, can find other letters at left or right  ------------
int FindWord(vector<vector<char>> &mat, string &str, int i, int j, int ind, int rmax, int cmax){
    int count = 0;
    // Invalid index / Base Case
    if(i>=rmax || i<0 || j>=cmax || j<0){
        return 0; // add a zero to the count such that it doesn't make any difference
    }

    // means this is a possible presence of the word
    if(str[ind] == mat[i][j]){
        ind++; // check the next character
        if(str[ind] == 0){ // if we reached '\0' in str // means we have found the whole string
            return 1;
        }
        count += FindWord(mat,str,i,j+1,ind,rmax,cmax);
        count += FindWord(mat,str,i,j-1,ind,rmax,cmax);
        count += FindWord(mat,str,i+1,j,ind,rmax,cmax);
        count += FindWord(mat,str,i-1,j,ind,rmax,cmax);
    }
    return count;
}

int solve (vector<vector<char>> &mat, string &str){
    int n = mat.size();
    int m = mat[0].size();
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            count += FindWord(mat,str,i,j,0,n,m); // returns the count of times the word is present if it is starting from (i,j).
        }
    }
    return count;
}

// Time Complexity: O(4^(n*m))
// Auxiliary space: O(n*m)

int main(){
    vector<vector<char> > board = { { 'o', 'a', 'a', 'n' }, { 'e', 't', 'a', 'e' }, { 'i', 'h', 'k', 'r' }, { 'i', 'f', 'l', 'v' } };
    vector<string> words = { "oath", "pea", "eat", "rain" };
    for(string &s: words){
        cout << solve(board, s) << endl;
    }
    return 0;
}

// ----------------- Solve like crossword puzzle in straight 8 directions ----------------------
bool search(vector<vector<char>> &puzzle,string &str,int x, int y, int r, int c){
    int rd[8] = {1,-1,0,0,-1,1,1,-1};
    int cd[8] = {0,0,1,-1,-1,1,-1,1};
    int n = str.size();

    // Searching in different directions
    for(int dir=0; dir<8; dir++){
        int k;
        int i = x;
        int j = y;
        for(k=0; k<n; k++){
            if(i<0||j<0||i>=r||j>=c){
                break;
            }
            if(puzzle[i][j]!=str[k]){
                break; // we have other directions also as a hope
            }
            i += rd[dir];
            j += cd[dir];

        }
            if(k==n){
            return 1;
        }
    }
    return 0;
}

vector<vector<int>> searchWord(vector<vector<char>> &grid, string &word){
	vector<vector<int>> ans;
    int n = grid.size();
    int m = grid[0].size();
    
    // Going to each position to find if it is the possible start of the matched string/pattern
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(search(grid,word,i,j,n,m)){
                ans.push_back({i,j});
            }
        }
    }

    return ans;
}

// Time Complexity: O(8^(n*m))
// Auxiliary space: O(n*m)

void print(vector<vector<int>> arr){
    for(vector<int> &v: arr){
        for(int &i: v){
            cout << i << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<char> > board = { { 'o', 'a', 'a', 'n' }, { 'e', 't', 'a', 'e' }, { 'i', 'h', 'k', 'r' }, { 'i', 'f', 'l', 'v' } };
    vector<string> words = { "oath", "pea", "eat", "rain" };
    for(string &s: words){
        cout << s << ": ";
        print(searchWord(board,s));
        cout << endl;
    }
    return 0;
}