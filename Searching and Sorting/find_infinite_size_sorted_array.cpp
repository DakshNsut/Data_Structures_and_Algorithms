#include <iostream>
using namespace std;

// to find an element in an infinite size sorted array

// Simple binary search algorithm
int binarySearch(int arr[], int l, int r, int x){
	if (r >= l){
		int mid = l + (r - l)/2;
		if (arr[mid] == x) return mid;
		if (arr[mid] > x) r = mid-1;
		return l = mid+1;
	}
	return -1;
}

int findPos(int arr[], int key){
	int l = 0, h = 1;
	int val = arr[0];

	// Find h to do binary search
	while (val < key){
		l = h;	 // store previous high
		h = 2*h;	 // double high index
		val = arr[h]; // update new val
	}

	// at this point we have found the l and h range within which we will have our key
	return binarySearch(arr, l, h, key);
}

// Driver program
int main(){
	int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
	int ans = findPos(arr, 10);
	if (ans == -1) cout << "Element not found";
	else cout << "Element found at index " << ans;
	return 0;
}