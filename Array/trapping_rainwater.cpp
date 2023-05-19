#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ------------------------- Method-1 -------------------------
int trapping_rainwater(int arr[], int n){
    int *left = new int[n];
    int *right = new int[n];

    left[0] = arr[0];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1],arr[i]);
    }

    right[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        right[i] = max(right[i+1],arr[i]);
    }

    long long unit_water = 0;
    for(int i=0; i<n; i++){
        unit_water += min(left[i],right[i]) - arr[i];
    }
    return unit_water;
}

// Time Complexity: O(n)
// Auxiliary Space: O(n)

// ------------------------- Method-2 -------------------------
int trapping_rainwater(int arr[], int n){
    int i = 0;
    int j = n-1;
    int left_max = 0; // Initailly = 0 because we don't have value at -1 index
    int right_max = 0; // Initailly = 0 because we don't have value at -1 index
    long long water_stored = 0;

    while(i<=j){
        if(left_max <= right_max){
            water_stored += max(0,left_max - arr[i]); // water that can be stored at arr[left]
            left_max = max(left_max,arr[i]);
            i++;
        }
        else{
            water_stored += max(0,right_max - arr[j]); // water that can be stored at arr[right]
            right_max = max(right_max,arr[j]);
            j--;
        }
    }
    return water_stored;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

int main(){
    int arr[] = {3, 0, 2, 0, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << trapping_rainwater(arr, n);
    return 0;
}