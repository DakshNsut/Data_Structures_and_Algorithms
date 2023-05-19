#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// to find minimum number of swaps to bring elements <= k together

// ------------------ Brute-Force------------------
int helper(int arr[], int s, int e, int k){
    int countGreater = 0;
    for(int i=s; i<e; i++){
        if(arr[i] > k){
            countGreater++;
        }
    }
    return countGreater;
}

int minSwap(int arr[], int n, int k) {
    int a = 0; // count of elements <=k.
    for(int i=0; i<n; i++){
        if(arr[i] <= k){
            a++;
        }
    }
    if(a == 0|| a == 1){
        return 0;
    }
    int ans = INT_MAX;
    for(int i=0; i+a-1<n; i++){
        ans = min(ans,helper(arr,i,i+a,k)); // returns the number of elments > k.
    }
    return ans;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

// ------------------ Optimal------------------
int countbad(int arr[], int s, int e, int k){
    int result = 0;
    for(int i=s; i<=e; i++){
        if(arr[i] > k){
            result++;
        }
    }

    return result;
}

int minSwap(int arr[], int n, int k) {
    int CountGood = 0; // Total number of good values (ele <= k) in arr
    for(int i=0; i<n; i++){
        if(arr[i]<=k){
            CountGood++;
        }
    }
    int s = 0, e = CountGood-1; // Intial window
    int CountBad = countbad(arr,s,e,k);
    int ans = CountBad; // number of swaps in first subarray will be number of bad values
    while(e<n){
        if(arr[s]>k){
            CountBad--;
        }
        s++; e++;
        if(arr[e]>k){
            CountBad++;
        }
        if(e<n){
        ans = min(ans,CountBad);
        }
    }
    return ans;
}

// without using any pointers
// Time Complexity: O(n)
// Auxiliary Space: O(1)

void print(vector<int> &arr){
    for(int i: arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int a[] = {2, 1, 5, 6, 3};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 3;
    cout << minSwap(a, n, k);
    return 0;
}