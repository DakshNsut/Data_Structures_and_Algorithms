#include <iostream>
#include <stack>
#include <climits>
using namespace std;

#define C 4
#define R 4

// largest rectangle with all 1's in a binary matrix
// prints the area of the largest rectangle

int getMaxArea(int arr[], int n){
    stack<int> st;
    int res = INT_MIN;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            int tp = st.top();
            st.pop();
            // for tp -> NS is at i and PS is at current st.top()
            int currArea = arr[tp] * ((st.empty()) ? i : (i-st.top()-1));
            res = max(res, currArea);
        }
        st.push(i);
    }

    // For ones that don't have NS
    while(!st.empty()){
        int tp = st.top();
        st.pop();
        int currArea = arr[tp] * ((st.empty()) ? n : (n-1-st.top()));
        res = max(res, currArea);
    }

    return res;
}

int largestRect(bool mat[][C]){
    int *arr = new int[C];
    for(int c=0; c<C; c++){
        arr[c] = int(mat[0][c]);
    }

    // Taking Row = 0 as base
    int res = getMaxArea(arr, C);
    for(int r=1; r<R; r++){
        for(int c=0; c<C; c++){
            if(mat[r][c] == 1){
                arr[c]++;
            }
            else{
                arr[c] = 0;
            }
        }
        // Taking Row = r-1 as base
        res = max(res, getMaxArea(arr, C));
    }

    return res;
}

// Time Complexity: O(R*C)
// Space Complexity: O(C)

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    bool matrix[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
    cout << largestRect(matrix);
}