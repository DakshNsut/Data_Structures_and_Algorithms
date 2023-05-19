// ------------------------------- METHOD-1 ------------------------------------
#include <iostream>
#include <vector>
using namespace std;

// GERGOVIA (SPOJ)

void findWorkDone(vector<pair<int,int>> buy, vector<pair<int,int>> sell){
    int i=0, j=0;
    long long int ans = 0;
    while(i<buy.size() && j<sell.size()){
        int x = min(buy[i].first, -sell[j].first);
        buy[i].first -= x;
        sell[j].first += x;
        int diff = abs(buy[i].second-sell[j].second);
        ans += diff * x;
        if(buy[i].first == 0) i++;
        if(sell[j].first == 0) j++;
    }

    cout << ans << endl;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    int n;
    cin >> n;
    while(true){
        vector<pair<int,int>> buy; // +ve values
        vector<pair<int,int>> sell; // -ve values
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x >= 0) buy.push_back(make_pair(x,i));
            if(x < 0) sell.push_back(make_pair(x,i));
        }
        findWorkDone(buy, sell);
        cin >> n;
        if(n == 0) break;
    }
    return 0;
}

// --------------------------------- METHOD-2 ------------------------------
#include <iostream>
#include <vector>
using namespace std;

void findWorkDone(vector<int> arr, int n){
	long long int ans = 0;
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += arr[i];
		ans += abs(sum);
	}

	cout << ans << endl;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

int main(){
    int n;
    cin >> n;
    while(true){
        vector<int> wines;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            wines.push_back(x);
        }
        findWorkDone(wines, n);
        cin >> n;
        if(n == 0) break;
    }
    return 0;
}