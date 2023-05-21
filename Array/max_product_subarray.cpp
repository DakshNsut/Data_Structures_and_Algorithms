#include <iostream>
#include <algorithm>
using namespace std;

// To find maximum product of elements of a subarray

void max_product_subarray(int arr[], int n){
    int ans = arr[0]; // initialised to arr[0] so that if there is single element and that is negative, so that is the answer
    int ma = ans;
    int mi = ans;

    for(int i=0; i<n; i++){
        if(arr[i] < 0) swap(ma, mi);
        ma = max(arr[i], ma*arr[i]); // two options: start a new subarray from arr[i] or include this in the previous subarray
        mi = min(arr[i], mi*arr[i]);
        ans = max(ans, ma);
    }

    cout << ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// Driver code
int main(){
	int arr[] = { 1, 5, 7, -1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

    max_product_subarray(arr, n);
	return 0;
}