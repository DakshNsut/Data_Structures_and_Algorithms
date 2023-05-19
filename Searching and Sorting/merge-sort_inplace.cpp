#include <iostream>
using namespace std;

// merge sort implemented inplace

// ------------------------- First Method ------------------------
void MergeInPlace(int *arr, int l, int h, int mid){
	int start1 = l;
	int start2 = mid+1;
	if(arr[mid] <= arr[start2]) return; // The array is already sorted

	while(start1<=mid && start2<=h){
		if(arr[start1] <= arr[start2]){
			start1++;
		}
		else{
			int val = arr[start2];
			int index = start2;
			while(index > start1){
				arr[index] = arr[index-1];
				index--;
			}
			arr[start1] = val;
			start1++;
			start2++;
			mid++;
		}
	}
}

void MergeSort(int *arr, int l, int h){
	int mid = l + ((h-l)>>1);
	if(l<h){
		MergeSort(arr,l,mid);
		MergeSort(arr,mid+1,h);
		MergeInPlace(arr,l,h,mid);
	}
}

int main() {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	MergeSort(arr, 0, n-1);
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

// ----------------------------- Second Method --------------------------
int nextGap(int gap){
	if(gap==1) return 0;
	return ceil(gap/2.0);
}

void MergeInPlace(int *arr, int l, int h){
	int gap = (h-l+1);

	for(gap = nextGap(gap); gap > 0; gap = nextGap(gap)){
		for(int i=l; i + gap <= h; i++){
			int j = i + gap;
			if(arr[i] > arr[j]){
				swap(arr[i], arr[j]);
			}
		}
	}
}

void MergeSort(int *arr, int l, int h){
	int mid = l + ((h-l)>>1);
	if(l<h){
		MergeSort(arr,l,mid);
		MergeSort(arr,mid+1,h);
		MergeInPlace(arr,l,h);
	}
}

int main() {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	MergeSort(arr, 0, n-1);
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

// ----------------- Third Optimal Method ----------------------
void MergeInPlace(int *arr, int l, int h, int mid){
	int mx = max(arr[mid], arr[h]) + 1;

	int i = l, j = mid+1, k = l;
	while(i<=mid && j<=h && k<=h){
		int e1 = arr[i] % mx; // What is present is A = (A+B*mx)%mx;
		int e2 = arr[j] % mx;

		if(e1 < e2){
			arr[k] += e1 * mx; // e1 should be present, so B = e1
			k++;
			i++;
		}
		else{
			arr[k] += e2 * mx; // e2 should be present, so B = e2
			k++;
			j++;
		}
	}

	while(i <= mid){
		arr[k] += (arr[i] % mx) * mx;
		k++;
		i++;
	}

	while(j <= h){
		arr[k] += (arr[j] % mx) * mx;
		k++;
		j++;
	}

	// Now all arr[i] = A+B*mx, to change them to what was expected to be (B) set arr[i] /= mx;
	for(int i=l; i<=h; i++){
		arr[i] /= mx;
	}
}

void MergeSort(int *arr, int l, int h){
	int mid = l + ((h-l) >> 1);
	if(l<h){
		MergeSort(arr,l,mid);
		MergeSort(arr,mid+1,h);
		MergeInPlace(arr,l,h,mid);
	}
}

// Time Complexity: O(n*log(n))
// Auxiliary space: O(1)

int main(){
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	MergeSort(arr, 0, n-1);
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}