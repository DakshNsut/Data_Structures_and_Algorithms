#include <iostream>
#include <stack>
using namespace std;

// to check if arr1 is a stack permutation of arr2

bool isStackPermutation(int arr1[], int arr2[], int n, int m){
    int i = 0, j = 0;
    stack<int> st;

    while(1){
        if(st.empty()){
            if(i == n && j != m) return 0;
            st.push(arr1[i++]);
        }
        if(arr2[j] == st.top()){
            st.pop();
            j++;
            if(j == m){
                // cout << (i == n && st.empty()) << endl;
                return 1;
            }
        }
        else{
            if(i == n && j != m) return 0;
            st.push(arr1[i++]);
        }
    }
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

int main(){
    int arr1[] = {1,2,3};
    int arr2[] = {2,1,3};
    cout << isStackPermutation(arr1, arr2, 3, 3) << endl;

    // int arr1[] = {1,2,3}; // same
    int arr3[] = {3,1,2};
    cout << isStackPermutation(arr1, arr3, 3, 3);

    return 0;
}