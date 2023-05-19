#include <iostream>
#include <stack>
using namespace std;

// to find length of longest valid substring

// ---------------- Method -1 -------------------
int findMaxLen(string s) {
    int res = 0, n = s.size();
    stack<int> st;
    st.push(-1);

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(!st.empty()) st.pop();
            if(!st.empty()) res = max(res, i - st.top());
            else{
                st.push(i);
            }
        }
    }
        
    return res;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// ------------- Method -2 ------------------
int findMaxLen(string s) {
    int res = 0, n = s.size(), left = 0, right = 0;

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            left++;
        }
        else{
            right++;
        }
            
        if(left < right){
            left = right = 0;
        }
            
        else if(left == right){
            res = max(res, 2*left);
        }
    }

    left = right = 0;

    for(int i=n-1; i>=0; i--){
        if(s[i] == '('){
            left++;
        }
        else{
            right++;
        }
            
        if(left > right){
            left = right = 0;
        }
            
        else if(left == right){
            res = max(res, 2*left);
        }
    }
        
    return res;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    cout << findMaxLen("()(()))))") << endl;
    return 0;
}