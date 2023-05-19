#include <iostream>
#include <stack>
#include <climits>
using namespace std;

void computeNS(int arr[], int n, int *ns){
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            ns[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ns[st.top()] = -1;
        st.pop();
    }
}

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    int arr[] = {4, 8, 5, 2, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *ns = new int[n];
    computeNS(arr, n, ns);
    print(ns, n);
}