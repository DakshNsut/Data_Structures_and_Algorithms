#include<iostream>
#include<vector>
using namespace std;

bool ispalindrome(string &S, int s, int e){
    while(s<e){
        if(S[s] != S[e]){
            return false;
        }
        s++;
        e--;
    }

    return true;
}

void partition(string &s, int baseindex, vector<string> path, vector<vector<string>> &ans, int n){

    if(baseindex == n){
        ans.push_back(path);
        return;
    }

    // choosing the correct point at which partitioning would be done
    for(int i=baseindex; i<n; i++){
        if(ispalindrome(s, baseindex, i)){
            path.push_back({s.substr(baseindex, i - baseindex + 1)});
            partition(s, i+1, path, ans, n);

            // Backtracking to go to explore other solutions
            path.pop_back();
        }
    }
}

// Time Complexity: O(2^n)
// Auxiliary Space: O(n^2)

int main(){
    string s = "geek";
    int n = s.size();
    vector<string> path;
    vector<vector<string>> ans;
    partition(s, 0, path, ans, n);

    for(vector<string> &v : ans){
        for(string i : v) cout << i << " ";
        cout << endl;
    }
}