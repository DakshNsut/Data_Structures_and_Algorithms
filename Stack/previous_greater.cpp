#include <iostream>
#include <stack>
using namespace std;

void PrevGreater(int arr[], int &n){
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        int greater = (st.empty()) ? -1 : st.top();
        cout << greater << " ";
        st.push(arr[i]);
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    int arr[] = {10, 4, 2, 20, 40, 12, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    PrevGreater(arr, n);
    return 0;
}