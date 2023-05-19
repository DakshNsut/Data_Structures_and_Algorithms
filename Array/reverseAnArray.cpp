#include <iostream>
using namespace std;

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void reverse(int a[], int n){
    int s = 0;
    int e = n-1;

    while(s < e){
        int temp = a[s];
        a[s] = a[e];
        a[e] = temp;
        s++; e--;
    }
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

int main(){
    int arr[] = {80,6,3,2,1,5,78,9,3,99};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverse(arr, n);
    printArray(arr, n);

    return 0;
}