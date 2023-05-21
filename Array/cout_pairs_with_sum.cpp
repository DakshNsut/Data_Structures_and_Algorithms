#include <iostream>
#include <unordered_map>
using namespace std;

// To find count of pairs with given sum

int getPairsCount(int arr[], int n, int k){
	unordered_map<int, int> m;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (m.find(k - arr[i]) != m.end()) {
			count += m[k - arr[i]];
		}
		m[arr[i]]++;
	}
	return count;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// Driver code
int main(){
	int arr[] = { 1, 5, 7, -1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 6;

	// Function Call
	cout << "Count of pairs is " << getPairsCount(arr, n, sum);
	return 0;
}