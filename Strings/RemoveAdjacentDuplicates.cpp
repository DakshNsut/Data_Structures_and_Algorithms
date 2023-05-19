#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// remove both the adjacent duplicates

// ---------------------- Method-1 ----------------------
void remove_adj_spaces(string &s){
    bool flag = true;

    while(flag){
        flag = false;

        for (int i = 0; i < s.size(); i++){
            if(s[i] == s[i+1]){
                s.erase(i,2);
                flag = true;
            }
        }
    }

    return;
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(1)

int main(){

    string s;
    cout << "Enter the string: ";
    getline(cin,s);

    remove_adj_spaces(s);
    cout << s;
}


// ---------------------- Method-2 ----------------------
void reverse (string &s){
    int start = 0;
    int end = s.size()-1;

    while (start < end){
        char temp;
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

}

void remove_adj_spaces(string &s){
    stack<char> st;

    for(char i: s){
        if(st.empty()){
            st.push(i);
        }
        else if(st.top() == i){
            st.pop();
        }
        else{
            st.push(i);
        }
    }

    s.clear();
    while(!st.empty()){
        s+=st.top();
        st.pop();
    }

    reverse(s);

}

// Time Complexity: O(n)
// Auxiliary Space: O(n)

int main(){

    string s;
    cout<<"Enter the string: ";
    getline(cin,s);

    remove_adj_spaces(s);
    cout << s;
}