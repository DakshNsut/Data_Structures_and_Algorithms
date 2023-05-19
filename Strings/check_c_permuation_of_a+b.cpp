#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// check if string c is a correct permutation of concatenated string of a and b

// ---------------- Method - 1 --------------
string CheckValid(string &a, string &b, string &c){
    unordered_map<char,int> m;

    // store expected characters with their expected frequency in a map
    for(char ch: a){
        m[ch]++;
    }
    for(char ch: b){
        m[ch]++;
    }

    // Check if the characters are present with their expected frequency and no unexpected character is present
    for(char ch: c){
        if(m[ch] != 0){
			m[ch]--;
        }
        else{
			return "No";
        }
    }

    // Check if some characters were left to be present
    for(unordered_map<char,int>::iterator it=m.begin(); it!=m.end(); it++){
        if(it->second > 0){
			return "No";
        }
    }
    return "Yes";
}

// Time Complexity: O(n+m+p)
// Auxiliary space: O(n+m)

int main(){
    string a = "XY";
    string b = "12";
    string c = "1X2Y";
    cout << CheckValid(a,b,c) << endl;
    return 0;
}

// -------------- Method - 2 ---------------
    string CheckValid(string &a, string &b, string &c){
    int i=0,j=0,k=0;
    int aSize = a.size();
    int bSize = b.size();
    int cSize = c.size();

    // This helps when a and b contain common elements
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    if(aSize+bSize != cSize){
        return "No";
    }

    while(k < cSize){
        if(i<aSize && a[i] == c[k]){
			// This was found, go to check for the other one
			i++;
        }
        else if(j<bSize && b[j] == c[k]){
			// This was found, go to check for the other one
			j++;
        }
        else{
			// if the element in 'c' didn't match any of the arrays / it was an unexpected element
			return "No";
        }
        
        // check the next character of 'c'
        k++;
    }

    if(i<aSize || j<bSize){
        return "No";
    }
    return "Yes";
}

// Time Complexity: O(nlog(n) + mlog(m) + plog(p))
// Auxiliary space: O(1)

int main(){
    string a = "XY";
    string b = "12";
    string c = "1X2Y";
    cout << CheckValid(a,b,c) << endl;
    return 0;
}