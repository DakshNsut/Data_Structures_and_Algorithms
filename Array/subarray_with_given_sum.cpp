#include <iostream>
#include <algorithm>
using namespace std;

// To find a subarray with sum = k

// ------------------------ Sliding Window Approach --------------------
int subArraySum(int arr[], int n, int sum){
	int currentSum = arr[0], start = 0, i;

	for (i = 1; i <= n; i++){
		// If currentSum exceeds the sum,
		// then remove the starting elements
		while (currentSum > sum && start < i - 1) {
			currentSum = currentSum - arr[start];
			start++;
		}

		// If currentSum becomes equal to sum,
		// then return true
		if (currentSum == sum) {
			cout << "Sum found between indexes " << start
				<< " and " << i - 1;
			return 1;
		}

		// Add this element to currentSum
		if (i < n) currentSum = currentSum + arr[i];
	}

	// If we reach here, then no subarray
	cout << "No subarray found";
	return 0;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// Best Complexity but can't handle negative items

// ----------------------- Using HashMap ------------------
void subArraySum(int arr[], int n, int sum){
    unordered_map<int, int> map;
    int curr_sum = 0;
 
    for (int i = 0; i < n; i++) {
        curr_sum = curr_sum + arr[i];
 
        // if curr_sum is equal to target sum
        // we found a subarray starting from index 0
        // and ending at index i
        if (curr_sum == sum) {
            cout << "Sum found between indexes " << 0 << " to " << i << endl;
            return;
        }
 
        // If (curr_sum - sum) already exists in map
        // we have found a subarray with target sum
        if (map.find(curr_sum - sum) != map.end()) {
            cout << "Sum found between indexes " << map[curr_sum - sum] + 1 << " to " << i << endl;
            return;
        }

        map[curr_sum] = i;
    }

    // If we reach here, then no subarray exists
    cout << "No subarray with given sum exists";
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// Best Complexity but can handle negative items

// Driver Code
int main(){
	int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 23;
	subArraySum(arr, n, sum);
	return 0;
}