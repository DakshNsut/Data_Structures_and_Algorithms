#include <iostream>
#define ll long long
using namespace std;

// spoj problem named "EKOSPOJ"

ll maxEle(ll TreeHeight[], ll N){
	ll res = -1;
	for(ll i=0; i<N; i++){
		res = max(res,TreeHeight[i]);
	}
	return res;
}

bool isPossible(ll TreeHeight[], ll N, ll M, ll mid){
	ll amountOfWood = 0;
	for(ll i=0; i<N; i++){
		// adding height of wood we will get by cutting ith Tree
		if(TreeHeight[i]-mid > 0) amountOfWood += (TreeHeight[i]-mid);
	}
	if(amountOfWood < M){
		return false;
	}
	return true;
}

void MaxHeight(ll TreeHeight[], ll N, ll M){
	ll s = 0, e = maxEle(TreeHeight, N);
	ll ans = -1;
	ll mid = s+((e-s)>>1);
	while(s<e){
		if(isPossible(TreeHeight, N, M, mid)){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
		mid = s+((e-s)>>1);
	}
	cout << ans << endl;
}

// Time Complexity: O(n*log(n))
// Auxiliary space: O(1)

int main() {
	ll N, M;
	cin >> N >> M;
	
	ll *TreeHeight = new ll[N];
	ll ind = 0;
	while(ind<N){
		cin >> TreeHeight[ind];
		ind++;
	}
	MaxHeight(TreeHeight, N, M);
	return 0;
}
