#include <iostream>
using namespace std;

int partition(int arr[], int l, int r){
    int piv = l;
    int i = l;
    int j = r;
    while(i<j){
        while(arr[i]>=arr[piv]){
            i++;
        }
        while(arr[j]<arr[piv]){
            j--;
        }
            
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j], arr[piv]);
    return j;
}

int kthLargest(int arr[], int l, int r, int k) {
    int pivot = partition(arr,l,r);
    if(pivot-l == k-1){
        return arr[pivot];
    }
    if(pivot-l > k-1){
        return kthLargest(arr,l,pivot-1,k);
    }
    else{
        return kthLargest(arr,pivot+1,r,k-pivot+l-1);
    }
}

// Time Complexity = O(n^2) - Worst Case
// Auxiliary space = O(log(n))

int main(){
    int arr[] = {5,43,23,25,56,35};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << kthLargest(arr, 0, n-1, 2);
    return 0;
}