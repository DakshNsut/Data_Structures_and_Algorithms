#include <iostream>
#include <vector>
using namespace std;

// -------- METHOD -1 ------------
void permutations(string s, int l, int r){
    if(l==r){
        cout << s << " ";
        return;
    }

    for(int i=l; i<=r; i++){
        swap(s[l],s[i]);
        permutations(s,l+1,r);
        swap(s[l],s[i]);
    }
}

// Time Complexity: O(n*n!)
// Auxiliary Space: O(n)

// -------- METHOD -2 ------------
void permute(string s, string ans=""){
    if(s.size()==0){
        cout << ans << " ";
        return;
    }

    for(int i=0; i<s.size(); i++){
        char ch = s[i];
        string left_substr = s.substr(0,i); // substring from 0 to i-1
        string right_substr = s.substr(i+1); // substring from i+1 to end()
        string rest = left_substr + right_substr;
        permute(rest,ans+ch);
    }
}

// Time Complexity: O(n*n!)
// Auxiliary Space: O(n)

int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin, str);

    permutations(str, 0, str.size()-1);
    cout << endl;

    permute(str, "");
    cout << endl;
}