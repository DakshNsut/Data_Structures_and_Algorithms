#include<iostream>
using namespace std;

// ------------------- ITERATIVE ------------------------------
void insertion_sort(int a[], int n){
    for(int i=1; i<=n-1; i++){
        int j = i-1;
        int temp = a[i];

        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

// T(n) = O(n^2)
// S(n) = O(1)

// -------------------- RECURSIVE --------------------
void insertion_sort(int arr[], int n, int j=1){
    if(j==n){
        return;
    }
    int temp = arr[j];
    int i = j-1;
    while(i>=0 && arr[i]>temp){
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i+1] = temp;

    insertion_sort(arr, n, j+1);
}

// T(n) = O(n^2)
// S(n) = O(n)

int main(){
    int arr[] = {5,3,1,5,8,3,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, n);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}
