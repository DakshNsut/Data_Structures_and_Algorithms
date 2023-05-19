#include<iostream>
using namespace std;

bool checkpali(string &s, int l=0){
    int r = s.size() - l - 1;
    if(l>=r){
        return true;
    }

    if(s[l] != s[r]){
        return false;
    }

    return checkpali(s, l + 1);
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    string str = "ABtBA";
    if(checkpali(str)){
        cout << "Yes! str is a palindrome.";
    }
    else cout << "No! str is not a palindrome.";
    return 0;
}