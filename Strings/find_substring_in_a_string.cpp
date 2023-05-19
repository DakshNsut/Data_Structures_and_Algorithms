#include <iostream>
#include <climits>
using namespace std;

// find a substring in a string

// --------------------------- Naive approach ----------------------
void findS(string &str, string &s){
    int n = str.size();
    int m = s.size();
    for(int i=0; i<n-m+1; i++){
        int j;
        for(j=0; j<m; j++){
            if(str[i+j]!=s[j]){
                break;
            }
        }
        if(j == m){
            cout << "Found at " << i << endl;
        }
    }
}

// Time complexity: O(n*m)
// Auxiliary Space: O(1)

// --------------------- Rabin-Karp algorithm ---------------------
void findS(string &text, string &pat){
    int q = INT_MAX;
    int t = 0; // Hash value of text
    int p = 0; // Hash value of pattern
    int n = text.size(); // Size of text
    int m = pat.size(); // Size of pattern
    int d = 256; // total number of possible characters in the string

    int h = 1; // h = pow(d,m-1)
    for (int i=1; i<=m-1; i++){
        h = (h*d)%q;
    }

    // calculating hash value of pattern and first window of size 'm' of the text
    for(int i=0; i<m; i++){
        t = (t*d+text[i])%q;
        p = (p*d+pat[i])%q;
    }
    // We might get negative value of t or p, converting
    // it to positive
    if (t < 0) t = (t + q);
    if (p < 0) p = (p + q);

    for(int i=0; i<n-m+1; i++){
        // If hash values are same
        if(t==p){
            int j;
            // checking each value in the window
            for(j=0; j<m; j++){
                if(text[i+j] != pat[j]){
                    break;
                }
            }

            // If the window sub-string was matched
            if(j==m){
                cout << "Found at " << i << endl;
            }
        }

        // Calculating hash value for the next window
        // Remove leading digit, add trailing digit
        t = (((t-text[i]*h)*d)+text[i+m])%q;

        // We might get negative value of t, converting
        // it to positive
        if (t < 0) t = (t + q);
    }
}

// Time complexity: O(n+m) - O(n*m) worst case
// Auxiliary Space: O(1)

// ---------------------- KMP Algorithm --------------------
int* computeLPS(string &pat){
    int* lps = new int[pat.size()];
    int i=0, j=1, n=pat.size();
    lps[i] = 0;
    while(j<n){
        if(pat[i] == pat[j]){
            lps[j] = i+1;
            i++;
            j++;
        }
        else{
            if (i!=0){
                i = lps[i-1];
            }
            else{
                lps[j] = 0;
                j++;
            }
        }
    }
    return lps;
}

void findS(string &text, string &pat){
    int n = text.size();
    int m = pat.size();

    int* lps = computeLPS(pat);

    int i = 0; // for text
    int j = 0; // for pattern
    while((n-i)>=(m-j)){
        if(pat[j] == text[i]){
            j++;
            i++;
            if(j==m){
                cout << "Found at index " << i-m << endl;
                j = lps[j-1];
            }
            if(i>=n){
                return;
            }
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }

    delete[] lps;
}

// Time Complexity: O(n+m)
// Auxiliary Space: O(m)

int main(){
    string str = "abcdefg";
    string s = "cde";
    findS(str, s);
    return 0;
}