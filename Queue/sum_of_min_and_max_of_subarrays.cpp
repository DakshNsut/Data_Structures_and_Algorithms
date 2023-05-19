#include <iostream>
#include <queue>
using namespace std;

// to compute sum of minimum and maximum elements of all sub-array of size k. 

int solve(int arr[], int k, int n){
    deque<int> S, G;
    int sumAns = 0;

    // Traversing the first subarray
    for(int i=0; i<k; i++){
        while(!G.empty() && arr[G.back()] <= arr[i]) G.pop_back();
        while(!S.empty() && arr[S.back()] >= arr[i]) S.pop_back();
        G.push_back(i);
        S.push_back(i);
    }

    // Traversing other subarrays
    for(int i=k; i<n; i++){
        sumAns += (arr[G.front()] + arr[S.front()]);
        while(!S.empty() && S.front() <= i-k) S.pop_front();
        while(!G.empty() && G.front() <= i-k) G.pop_front();
        while(!G.empty() && arr[G.back()] <= arr[i]) G.pop_back();
        while(!S.empty() && arr[S.back()] >= arr[i]) S.pop_back();
        G.push_back(i);
        S.push_back(i);
    }

    sumAns += (arr[G.front()] + arr[S.front()]);
    return sumAns;
}

// Time Complexity: O(n)
// Auxiliary space: O(k)

int main(){
    int a[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(a)/sizeof(a[0]);
    cout << solve(a,4,n);
}