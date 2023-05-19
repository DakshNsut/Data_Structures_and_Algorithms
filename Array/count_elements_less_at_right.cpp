#include <iostream>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// to find count elements smaller than arr[i] at its right

// we are using C++ policy based data structure ordered_set,
// because no other data structure can store duplicates in ordered form

vector<int> constructLowerArray(int *arr, int n){
	vector<int> res(n, 0);
	ordered_set s;
	for(int i=n-1; i>=0; i--){
	    res[i] = s.order_of_key(arr[i]);
	    s.insert(arr[i]);
	}

	return res;
}

void print(vector<int> &ans){
    for(int i: ans){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {12, 1, 2, 3, 0, 11, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans = constructLowerArray(arr, n);
    print(ans);
}

// Time complexity: O(nlogn) 
// Auxiliary Space: O(n)