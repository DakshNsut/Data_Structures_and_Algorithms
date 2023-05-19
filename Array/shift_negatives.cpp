#include <iostream>
using namespace std;

// SHIFT ALL -ves to left and all +ves to right

void swap(int* a, int* b){
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}
void format_neg_pos(int arr[], int n){
    int i=0, j=n-1;
    while(i<j){
        while(i<n && arr[i] < 0 ){ // if got -ve element at left side
            i++;
        }
        while(j>=0 && arr[j] >= 0){ // if got +ve element at left side
            j--;
        }
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {5,35,-23,25,-56};
    int n = sizeof(arr)/sizeof(arr[0]);
    format_neg_pos(arr, n);
    print(arr, n);
    return 0;
}