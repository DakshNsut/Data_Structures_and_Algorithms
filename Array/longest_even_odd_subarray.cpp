#include <iostream>
using namespace std;

// to find length of longest alternating even odd subarray

// ---------------- Method -1 ------------------
int longest_alternate_subarray(int arr[], int n){
    int ans = 1; // the final answer
    for(int i=0; i<n; i++){
        int cnt = 1; // alternate subarray length starting from i index
        for(int j=i; j<n-1; j++){
            if((arr[j]%2 == 0 && arr[j+1]%2 != 0) || (arr[j]%2 != 0 && arr[j+1]%2 == 0)){
                cnt++;
            }
            else break;
        }

        ans = max(ans, cnt);
    }

    return ans;
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

// ------------------- Method -2 -----------------
// Inspired by Kadane's algorithm
int longest_alternate_subarray(int arr[], int n){
    int ans =1, cnt =1;
    for(int i=0; i<n-1; i++){
        if((arr[i]%2 == 0 && arr[i+1]%2 != 0) || (arr[i]%2 != 0 && arr[i+1]%2 == 0)){
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt = 1;
    }
    return ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    int a[] = {1,2,3,4,5,7,9};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Length of longest alternate subarray is: " << longest_alternate_subarray(a,n);
}