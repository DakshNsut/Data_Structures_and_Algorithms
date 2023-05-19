#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

string infix_to_postfix(string s){
    stack<int> st;
    string postfix;
    unordered_map<int,int> opPrec;
    opPrec['+'] = 1;
    opPrec['-'] = 1;
    opPrec['*'] = 2;
    opPrec['/'] = 2;
    opPrec['^'] = 3;

    for(char &ch : s){
        if(ch == '('){
            // if ch is '('
            st.push(ch);
        }
        else if(ch == ')'){
            // if ch is ')'
            while(!st.empty() && st.top() != '('){
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop(); // removing '(' that was encountered
        }
        else if(opPrec.find(ch) != opPrec.end()){
            // If ch is operator
            while(!st.empty() && opPrec[st.top()] >= opPrec[ch]){
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(ch);
        }
        else{
            // If ch is operand
            postfix.push_back(ch);
        }
    }
    
    while(!st.empty()){
        postfix.push_back(st.top());
        st.pop();
    }
    
    return postfix;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    cout << infix_to_postfix("((A+B)-C*(D/E))+F");
    return 0;
}