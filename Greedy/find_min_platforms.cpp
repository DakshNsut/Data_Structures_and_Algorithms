#include <iostream>
#include <algorithm>
using namespace std;

// find minimum number of plarforms required for the railway

// ----------- METHOD-1 ---------------
int findPlatform(int arr[], int dep[], int n){
    int res = 1;
    for(int i=0; i<n; i++){
        int plat = 0; // number of platform needed
        for(int j=0; j<n; j++){
            if(arr[i] >= arr[j] && dep[j]>= arr[i]){
                plat++;
            }
        }
        res = max(res, plat);
    }

    return res;
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

// ----------- METHOD-2 ---------------
int findPlatform(int arr[], int dep[], int n){
    sort(arr, arr+n); sort(dep, dep+n);
    int i=0, j=0;
    int plat = 0, res = 0;

    while(i<n && j<n){
        if(arr[i] <= dep[j]){
            i++;
            plat++;
        }
        else{
            plat--;
            j++;
        }
        res = max(res, plat);
    }

    return res;
}

// Time Complexity: O(n*logn)
// Auxiliary space: O(1)

// Driver Code
int main()
{
    // Train 1 => Arrival : 01:00, Departure : 09:00
    // Train 2 => Arrival : 03:00, Departure : 04:00
    // Train 3 => Arrival : 05:00, Departure : 06:00
    int arr[] = { 100, 300, 500 };
    int dep[] = { 900, 400, 600 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPlatform(arr, dep, n);
    return 0;
}