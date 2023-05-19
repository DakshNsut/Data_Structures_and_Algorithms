#include<iostream>
#include<algorithm>
using namespace std;

// a spoj problem named "ROTI-PRATA"

bool isPossible(int *cookRank, int n, int P, int mid){
	int totalParanthaCount = 1; // Indicates the parantha number to be assigned to the cook
	int paranthaCount = 1, currSum = 0, i = 0;
	// "paranthaCount" is the count of parantha we want to assign it to a cook such that the total time taken is < mid
	// "currSum" is the sum total of time taken by all cooks till now

	while(i<n && totalParanthaCount<=P){
		if(currSum + cookRank[i]*paranthaCount <= mid){
			currSum += cookRank[i]*paranthaCount;
			paranthaCount++;
			totalParanthaCount++;
		}
		else{
			i++; // try to assign it to next cook
			paranthaCount = 1; // it will be the first parantha for new cook
			currSum = 0;
			// if i>=n&& totalParanthaCount<=P then the prata left to be assigned can't be assigned to any cook
			// if i<n && cookRank[i]>mid then to cook one prata cookRank[i] time would be taken for sure which would be > mid
			if((i<n && cookRank[i]>mid) || (i>=n && totalParanthaCount<=P)){
				return false;
			}
		}
	}
	return true;
}

void findMinTime(int *cookRank, int n, int P){
	sort(cookRank, cookRank+n); // so that minimum rank cook gets maximum number of pratas, so that minimum time is taken
	// P is number of paranthas
	// n is the number of cooks
	int s = 0;
	int e = 4*(P)*(P+1); // 8(P)(P+1)/2
	int mid, ans = -1;

	while(s<=e){
		mid = s+((e-s)>>1);
		if(isPossible(cookRank,n,P,mid)){
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}

	cout << "ans = " << ans << endl;
}

// Time Complexity: O(n*log(n))
// Auxiliary space: O(1)

int main(){
	int T;
	cin >> T;
	while(T){
		int P, L;
		cin >> P >> L;
		int temp = 0;
		int *cookRank = new int[L];
		while(temp < L){
			cin >> cookRank[temp];
			temp++;
		}
		T--;
		findMinTime(cookRank,L,P);
	}
	return 0;
}