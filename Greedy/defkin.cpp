#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// this is a spoj problem named "DEFKIN- Defense Kingdom"

bool cmp(pair<int,int> &p1, pair<int,int> &p2){
	return p1.second < p2.second;
}

int LargestUndefendedArea(int &w, int &h, vector<int> &x, vector<int> &y){
    int n = x.size();
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int mh = INT_MIN, mw = INT_MIN;
	for(int i=0; i<n-1; i++){
		mw = max(mw, x[i+1]-x[i]-1);
		mh = max(mh, y[i+1]-y[i]-1);
	}

	return mw*mh;
}

// Time Complexity: O(n1log(n1) + n2log(n2))
// Auxiliary space: O(1)

int main(){
	int t;
	cin >> t;
	while(t){
		int w, h, n;
		cin >> w >> h >> n;
		int num = n;
		vector<int> x, y;
		x.push_back(0); y.push_back(0);
		while(num){
			int a, b;
			cin >> a >> b;
			x.push_back(a); y.push_back(b);
			num--;
		}
		x.push_back(w+1); y.push_back(h+1);
		cout << LargestUndefendedArea(w, h, x, y) << endl;
		t--;
	}
	return 0;
}