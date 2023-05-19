#include<iostream>
using namespace std;

// find twice occuring element
// array can contain elements between 1 to n.

int main(){
    int arr[] = {1,2,3,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // ----------------- METHOD-1 ------------------------
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout<< sum - ((n*(n+1)) /2 - n);

    // -------------------- METHOD-2 ------------------
    int ans = 0;
    for(int i = 0 ; i<n ; i++){
        ans ^= arr[i];
    }
    for(int i = 1 ; i<n ;i++){
        ans ^= i;
    }
    cout << ans;
}