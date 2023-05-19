#include<iostream>
#include<climits>
using namespace std;

// get maximum count of consecutive one's

int max_consecutive_1s(int arr[], int n){
    int maxCount = INT_MIN;
    int count = 0;
    for (int i = 0; i < n; i++){
        if(arr[i] == 1){
            count++;
        }
        else{
            maxCount = max(maxCount, count);
            count = 0;
        }
    }

    return maxCount;
}

int main(){
    int arr[] = {1,1,1,1, 5,6,1,1,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << max_consecutive_1s(arr, n);
    return 0;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)