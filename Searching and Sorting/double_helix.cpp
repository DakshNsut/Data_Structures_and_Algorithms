#include<iostream>
#include<algorithm>
using namespace std;

// a spoj problem named "DOUBLE-HELIX"

// We can ‘walk” over these two sequences in the following way:
// 1. We may start at the beginning of any of the two sequences. Now start moving forward.
// 2. At each intersection point, you have the choice of either continuing with the same
// sequence you’re currently on, or switching to the other sequence.

int finder(int *seq2, int m, int val, int l, int h){
	// finding the value using binary search
	int mid;
	while(l<=h){
		mid = l + ((h-l)>>1);
		if(val == seq2[mid]){
			return mid;
		}
		else if(seq2[mid] < val){
			l = mid+1;
		}
		else{
			h = mid-1;
		}
	}
	return -1;
}

void findMaxPath(int *seq1, int n, int *seq2, int m){
	int *prefix1 = new int[n];
	int *prefix2 = new int[m];

	int sum = 0;
	for(int i=0; i<n; i++){
		sum += seq1[i];
		prefix1[i] = sum;
	}

	sum = 0;
	for(int i=0; i<m; i++){
		sum += seq2[i];
		prefix2[i] = sum;
	}

	int ind = 0;
	int ans = 0;
	int oldIntersectionPoint1 = -1, oldIntersectionPoint2 = -1;
	while(ind<n && ind<m){
		if(seq1[ind] == seq2[ind]){
			if(oldIntersectionPoint1 == -1 && oldIntersectionPoint2 == -1 && ind>0) ans += max(prefix1[ind-1], prefix2[ind-1]);
			else if(ind>0) ans += max(prefix1[ind-1] - prefix1[oldIntersectionPoint1], prefix2[ind-1] - prefix2[oldIntersectionPoint2]);
			oldIntersectionPoint1 = ind;
			oldIntersectionPoint2 = ind;
			ans += seq1[ind];
		}
		else{
			if(seq1[ind]<seq2[ind]){
				int j = finder(seq2,m,seq1[ind],oldIntersectionPoint2+1,ind-1); // finds seq1[ind] in seq2 and returns its index in seq2
				if(j!=-1){
					if(oldIntersectionPoint1 == -1 && oldIntersectionPoint2 == -1 && ind>0) ans += max(prefix1[ind-1], prefix2[j-1]);
					else if(ind>0) ans += max(prefix1[ind-1] - prefix1[oldIntersectionPoint1], prefix2[j-1] - prefix2[oldIntersectionPoint2]);
					oldIntersectionPoint1 = ind;
					oldIntersectionPoint2 = j;
					ans += seq1[ind];
				}
			}
			else{
				int j = finder(seq1,n,seq2[ind],oldIntersectionPoint1+1,ind-1); // finds seq1[ind] in seq2 and returns its index in seq2
				if(j!=-1){
					if(oldIntersectionPoint1 == -1 && oldIntersectionPoint2 == -1 && ind>0) ans += max(prefix2[ind-1], prefix1[j-1]);
					else if(ind>0) ans += max(prefix1[j-1] - prefix1[oldIntersectionPoint1], prefix2[ind-1] - prefix2[oldIntersectionPoint2]);
					oldIntersectionPoint2 = ind;
					oldIntersectionPoint1 = j;
					ans += seq2[ind];
				}
			}
		}
		ind++;
	}

	// checking if oldIntersection points are not the end
	if(oldIntersectionPoint1 != n-1 || oldIntersectionPoint2 != m-1){
		if(oldIntersectionPoint1 == -1 && oldIntersectionPoint2 == -1) ans += max(prefix2[m-1], prefix1[n-1]);
		else ans += max(prefix1[n-1] - prefix1[oldIntersectionPoint1], prefix2[m-1] - prefix2[oldIntersectionPoint2]);
	}

	cout << ans << endl;
}

// Time Complexity: O(n+m)
// Auxiliary space: O(1)

int main(){

	while(1){
		int n1;
		cin >> n1;
		if(n1==0) break;

		int *seq1 = new int[n1];
		int ind1 = 0;
		while(ind1 < n1){
			cin >> seq1[ind1];
			ind1++;
 		}

		int n2;
		cin >> n2;
		int *seq2 = new int[n2];
		int ind2 = 0;
		while(ind2 < n2){
			cin >> seq2[ind2];
			ind2++;
 		}

		findMaxPath(seq1,n1,seq2,n2);
	}

	return 0;
}