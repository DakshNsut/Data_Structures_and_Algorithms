#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

// To check if array has 2 elements whose sum is equal to the given value

// ------------------ Two Pointer approach -----------------
bool findPair(int A[], int n, int sum){
	int l, r;
	// Sort the elements
	sort(A, A + n);

	// Now look for the two pairs in the sorted array
	l = 0; r = n - 1;
	while (l < r) {
		if (A[l] + A[r] == sum) return 1;
		else if (A[l] + A[r] < sum) l++;
		else r--;
	}
	return 0;
}

// Time Complexity: O(n*logn)
// Auxiliary space: O(1)

// -------------------------- Hashing ---------------------
bool findPair(int arr[], int n, int sum){
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int temp = sum-arr[i];

        if (s.find(temp) != s.end()){
            return 1;
        }
        s.insert(arr[i]);
    }
    return 0;
}

// Time Complexity: O(n)
// Auxiliary space: O(n)

// Driver program
int main(){
	int A[] = { 1, 4, 45, 6, 10, -8 };
	int n = 16;
	int arr_size = sizeof(A) / sizeof(A[0]);

	// Function calling
	if (findPair(A, arr_size, n)) cout << "Yes";
	else cout << "No";

	return 0;
}