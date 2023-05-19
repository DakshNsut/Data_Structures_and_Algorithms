#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(int a[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

// Time Complexity: O(n^2)
// Auxiliary space: O(1)

// --------------------- RECURSIVE ---------------------
void bubble_sort(int arr[], int n, int j = 0){
    if(n==1){
        return;
    }

    for (int i = 0; i < n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i + 1]);
        }
    }

    bubble_sort(arr, n - 1);
}

// Time Complexity: O(n^2)
// Auxiliary space: O(n)

int main(){
    int arr[] = {1, 2, 6, 7, 4, 5, 9, 3, 8};
    int n = sizeof(arr)/sizeof(arr[0]);    
    bubble_sort(arr, n);
    for(int i=0; i<n; i++) cout << arr[i] << " ";
}