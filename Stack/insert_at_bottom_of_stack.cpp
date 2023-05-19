#include <iostream>
#include <stack>
using namespace std;

// implement insert at bottom of a stack without using another data structure

void insert_at_bottom(stack<int> &st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int a = st.top();
    st.pop();
    insert_at_bottom(st, x);
    st.push(a);
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

void print(stack<int> &st){
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}

int main(){
    stack<int> st;
    st.push(23);
    st.push(22);
    st.push(12);
    st.push(5);
    st.push(6);
    st.push(7);
    insert_at_bottom(st, 11);
    print(st);
    
    return 0;
}