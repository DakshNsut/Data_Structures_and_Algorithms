#include <iostream>
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
    string s = "Hello panamaca";
    cout << checkpali(s) << endl;
    s = "MALAYALAM";
    cout << checkpali(s);

    return 0;
}