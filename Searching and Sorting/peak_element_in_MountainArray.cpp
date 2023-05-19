#include <iostream>
#define ELE 1, \
2, \
3, \
4
using namespace std;

// Find a peak element i.e. an element that is not smaller than its neighbors.

// ------------------- Iterative ---------------------
// ------------------- Peak element in sorted array ------------------
void Peak(int arr[], int s, int e){
    int mid = s + (e-s)/2;
    while(s<e){
        if(arr[mid] < arr[mid+1]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }

    cout << arr[mid];
}

// Time Complexity: O(log n)
// Auxiliary Space: O(1)

// ------------------ Recursive ---------------
int Peak(int arr[], int s, int e){
    int mid = s + (e-s)/2;

    if(s>=e){
        return arr[mid];
    }

    if(arr[mid] < arr[mid+1]){
        Peak(arr, mid+1, e);
    }
    else{
        Peak(arr, s, mid);
    }
}

// Time Complexity: O(log n)
// Auxiliary Space: O(log n)

int main(){
	int m = 3;
    int n = 3;
    int arr[] = {ELE};
    int size = 4;
	Peak(arr, 0, size-1);
}