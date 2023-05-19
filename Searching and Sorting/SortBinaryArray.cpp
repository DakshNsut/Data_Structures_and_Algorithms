#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> &arr){
    int l = 0;
    int r = arr.size() - 1;

    while(l<r){
        while (arr[l] == 0 && l<r){
            l++;
        }

        while (arr[r] == 1 && l<r){
            r--;
        }

        // Here, arr[l] == 1 and arr[r] == 0
        if(l<r){
            swap(arr[l],arr[r]);
        }
    }
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

int main(){
	vector<int> a = {0,0,1,1,0,1,0,1};
	sort(a);
	cout << "Sorted array is: ";
	for(int i: a) cout << i << " ";
	return 0;
}