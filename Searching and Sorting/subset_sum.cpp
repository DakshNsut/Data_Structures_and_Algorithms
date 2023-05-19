#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// a spoj problem named "subset-sum"
// Given a sequence of N numbers determine how many subsets of S (including the
// empty one) have a sum between A and B inclusive.

void subset(int *arr, int l, int h, vector<int> &v, int sum = 0){
	if(l == h+1){
		v.push_back(sum);
		return;
	}

	subset(arr, l+1, h, v, sum + arr[l]);
	subset(arr, l+1, h, v, sum);
}

void numOfSubsets(int *arr, int N, int A, int B){
	vector<int> v1, v2;
	subset(arr, 0, (N>>1)-1, v1);
	subset(arr, (N>>1), N-1, v2);
	sort(v2.begin(), v2.end());
	
	int ans = 0;
	for(int i=0; i<v1.size(); i++){
		int low = lower_bound(v2.begin(), v2.end(), A-v1[i]) - v2.begin();
		int high = upper_bound(v2.begin(), v2.end(), B-v1[i]) - v2.begin();
		ans += (high-low);
	}
	cout << ans;
}

// Time Complexity: O(2^(n/2) * log(2^(n/2)))
// Auxiliary space: O(2^n)

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int *arr = new int[N];
	int i=0;
	while(i<N){
		cin >> arr[i];
		i++;
	}

	numOfSubsets(arr, N, A, B);
	return 0;
}