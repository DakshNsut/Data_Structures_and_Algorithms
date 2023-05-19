#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// sort a stack
// bottom to top in ascending order

// ----------- Method -1 -----------
void insertAtCorrectPos(stack<int> &s, int &a){
    if(s.empty() || s.top() < a){
        s.push(a);
        return;
    }
    
    int x = s.top();
    s.pop();
    insertAtCorrectPos(s, a);
    s.push(x);
}

void sort(stack<int> &s)
{
    if(s.empty()) return;
    
    int a = s.top();
    s.pop();
    sort(s);
    insertAtCorrectPos(s, a);
}

// Time Complexity: O(n^2)
// Auxiliary space: O(n)

// ----------- Method -2 -----------
void sort(stack<int> &s)
{
    vector<int> v;
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }

    std::sort(v.begin(), v.end());

    for(int i : v){
        s.push(i);
    }
}

// Time Complexity: O(n*log(n))
// Auxiliary space: O(n)

void print(stack<int> &st){
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}

int main(){
    stack<int> st;
    st.push(37);
    st.push(25);
    st.push(100);
    sort(st);
    print(st);
    return 0;
}