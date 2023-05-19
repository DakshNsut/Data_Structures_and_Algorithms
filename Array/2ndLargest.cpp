#include<iostream>
#include<climits>
using namespace std;

// to find the second largest element in the array

int large2(int * arr, int n){
    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++){
        if(arr[i]>first){
            second = first;
            first = arr[i];
        }

        else if(arr[i]>second){
            second = arr[i];
        }
    }

    if(second == INT_MIN){
        return -1;
    }
    return second;
}

int main(){
    int a[] = {12,34,56};
    int n = sizeof(a)/sizeof(a[0]);
    cout << large2(a, n);
    return 0;
}

// Time Complexity: O(n)