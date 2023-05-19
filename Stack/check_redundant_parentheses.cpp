#include <iostream>
#include <stack>
using namespace std;

// finds if expression contains redundant/useless brackets

bool checkRedundantBrackets(string s){
    stack<char> st;
    int n = s.size();

    for(char &ch : s){
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            if(st.top() == '(') return true;
            while(st.top() == '(') st.pop();
            st.pop();
        }
    }
    return false;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    cout << checkRedundantBrackets("((a+b))") << endl;
    cout << checkRedundantBrackets("(a+b)") << endl;
    cout << checkRedundantBrackets("(a+(b)/c)") << endl;
    cout << checkRedundantBrackets("(a+b/c)") << endl;

    return 0;
}