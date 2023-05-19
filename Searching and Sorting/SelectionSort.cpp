#include<iostream>
#include<vector>
using namespace std;

int find_min(int a[], int n, int i){
    int min_ind = i;
    int min_item = a[i];
    for(int j =i; j<n; j++){
        if(a[j]<min_item){
            min_ind = j;
            min_item = a[j];
        }
    }
    return min_ind;
}

void selection_sort(int a[], int n){
    for(int i=0; i<n; i++){
        int min_loc = find_min(a, n, i);

        int temp = a[min_loc];
        a[min_loc] = a[i];
        a[i] = temp;
    }
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(1)

// ---------------------- RECURSIVELY ----------------------
int find_min(int a[], int n){
    int min_ind = 0;
    int min_item = a[0];
    for(int j = 0; j<n; j++){
        if(a[j]<min_item){
            min_ind = j;
            min_item = a[j];
        }
    }
    return min_ind;
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(n)

void selection_sort(int a[], int n){
    if(n == 0) return;
    int loc = find_min(a, n);
    swap(a[0], a[loc]);
    selection_sort(a + 1, n - 1);
}

int main(){
    int arr[] = {1, 2, 6, 7, 4, 5, 9, 3, 8};
    int n = sizeof(arr)/sizeof(arr[0]);    
    selection_sort(arr, n);
    for(int i=0; i<n; i++) cout << arr[i] << " ";
}