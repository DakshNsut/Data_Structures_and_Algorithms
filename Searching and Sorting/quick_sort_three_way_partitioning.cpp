#include <iostream>
using namespace std;

int partition(int *arr, int l, int h){
	int lt = l, curr = l, gt = h;
	int pi = arr[l];

	while(curr <= gt){
		if(arr[curr] < pi){
			swap(arr[curr++], arr[lt++]);
		}
		else if(arr[curr] > pi){
			swap(arr[curr], arr[gt--]);
		}
		else{
			curr++;
		}
	}

	return lt;
}

void QuickSort(int *arr, int l, int h){
	if(l<h){
		int pivot = partition(arr,l,h);
		QuickSort(arr,l,pivot);
		QuickSort(arr,pivot+1,h);
	}
}

// Time Complexity: O(n*log3(n))
// Auxiliary space: O(1)

int main() {
	int arr[] = {4, 9, 4, 4, 9, 1, 1, 1};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	QuickSort(arr, 0, n-1);
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}