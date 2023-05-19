#include <iostream>
using namespace std;

void reverse(string &s, int l=0){
    int r = s.size() - l - 1;
    if(l>=r){
        return;
    }

    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;

    reverse(s, l + 1);
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    string s = "Hello panamaca";
    reverse(s);
    cout << s << endl;

    return 0;
}