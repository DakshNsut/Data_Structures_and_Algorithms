#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// --------------------- power set --------------------
void subsequences(string &s, string stemp, int index){
    if(index==s.size()){
        if(stemp.empty()) cout << "NULL";
        cout << stemp << " ";
        return;
    }

    subsequences(s,stemp,index+1);
    stemp.push_back(s[index]);
    subsequences(s,stemp,index+1);
}

// Time Complexity: O(2^n)
// Auxiliary space: O(n)

// ---------------------- SECOND METHOD (Less efficient) ----------------------
void subset(string &str, int index, vector<string> &ans, string curr){
    int len = str.size();
    int set_size = pow(2, len);

    for(int n = 0; n<set_size; n++){
        for(int j = 1; j<=len; j++){
            if(n & (1<<(j-1)) ){
                curr+=str[j-1];
            }
        }
        ans.push_back(curr);
        curr.clear();
    }
}

// Time Complexity: O(n*2^n)
// Auxiliary space: O(n)

int main(){
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    // -------- METHOD-1 ----------
    int index = 0;
    vector<string> ans;
    string curr;
    subset(str, index, ans, curr);

    for(string s: ans){
        if(s.empty()){
            cout << "NULL ";
            continue;
        }
        cout << s << " ";
    }
    cout << endl;

    // -------- METHOD-2 ----------
    subsequences(str, "", 0);

    return 0;
}