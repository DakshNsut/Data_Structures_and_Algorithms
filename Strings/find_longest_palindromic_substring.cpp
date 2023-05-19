#include <iostream>
#include <cstring>
using namespace std;

// find longest palindromic substring in a string

// --------------------------- DP - with extra space ------------------
string longestPalin (string S) {
    int n = S.size();
    bool table[n][n];
    memset(table,0,sizeof(table));

    // pre-compute some values
    for(int i=0; i<n; i++){
        table[i][i] = 1;
    }

    int maxLen = 1;
    int start = 0;

    // finding substrings of length = 2
    int len = 2;
    for(int i=0; i<n-len+1; i++){
        int j = i+len-1;
        if(S[i] == S[j]){
            table[i][j] = 1;
            // No need to check because we are increasing the len of substrings
            // and if we found such substrings that is max
                
            if(len>maxLen){
                start = i;
                maxLen = len;
            }
        }
    }

    // finding substrings of length = 3 or more
    for(len=3; len<=n; len++){
        for(int i=0; i<n-len+1; i++){
            int j = i+len-1;
            if(table[i+1][j-1] && (S[i] == S[j])){
                table[i][j] = 1;

                // change only if it is the greater length, because if it is the same length
                // we don't want to change it because we want the first substring
                if(len>maxLen){
                    start = i;
                    maxLen = len;
                }
            }
        }
    }

    string ans;
    for(int i=start; i<start+maxLen; i++){
        ans.push_back(S[i]);
    }

    return ans;
}

// Time complexity: O(N^2)
// Auxiliary Space: O(N^2)

// ------------------------------- without extra space -------------------------
string longestPalin (string S) {
    int n = S.size();
    if(n<2){
        return S;
    }
        
    int start = 0;
    int maxLen = 1;
    for(int i=0; i<n; i++){
        int low = i-1, high = i+1;

        while(low>=0 && S[low] == S[i]){
            low--;
        }

        while(high<n && S[high] == S[i]){
            high++;
        }

        while(low>=0 && high<n && S[low] == S[high]){
            low--;
            high++;
        }
            
        // int len = (high-1) - (low+1) + 1;
        int len = high -low - 1;
        if(len > maxLen){
            maxLen = len;
            start = low+1;
        }
    }

    string ans;
    for(int i=start; i<start+maxLen; i++){
        ans.push_back(S[i]);
    }
    return ans;
}

// Time complexity: O(N2)
// Auxiliary Space: O(1)

int main(){
    cout << longestPalin("forgeeksskeegfor");
    return 0;
}