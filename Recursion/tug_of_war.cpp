#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define N 8

// Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the absolute
// difference of the sum of two subsets is as minimum as possible. If n is even, then sizes of two subsets
// must be strictly n/2 and if n is odd, then size of one subset must be (n-1)/2 and size of other subset
// must be (n+1)/2.

void TugOfWar(int arr[], int n, int i, int half1Sum, int half2Sum, vector<int> &half1, vector<int> &half2, int &minDiff, vector<int> ans[]){
	if(i == n){
		if(abs(half1Sum - half2Sum) < minDiff){
			ans[0] = half1;
			ans[1] = half2;
			minDiff = abs(half1Sum - half2Sum);
		}
		return;
	}

	// Adding in half1
	int maxSize = (n&1) ? ((n+1)>>1) : (n>>1);
	half1.push_back(arr[i]);
	if(half1.size() <= maxSize) TugOfWar(arr, n, i+1, half1Sum + arr[i], half2Sum, half1, half2, minDiff, ans);
	half1.pop_back();

	// Adding in half2
	maxSize = (n&1) ? ((n-1)>>1) : (n>>1);
	half2.push_back(arr[i]);
	if(half2.size() <= maxSize) TugOfWar(arr, n, i+1, half1Sum, half2Sum + arr[i], half1, half2, minDiff, ans);
	half2.pop_back();
}

// Time Complexity: O(2^n)
// Auxiliary space: O(n)

int main(){
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<int> ans[2];
	int minDiff = INT_MAX;
	vector<int> half1;
	vector<int> half2;
	TugOfWar(arr, n, 0, 0, 0, half1, half2, minDiff, ans);

	for(int i=0; i<2; i++){
		for(int ele : ans[i]){
			cout << ele << " ";
		}
		cout << endl;
	}
	return 0;
}