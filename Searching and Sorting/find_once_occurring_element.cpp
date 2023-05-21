#include <iostream>
using namespace std;

// find the element that appears once in sorted array (others repeat twice)

// ------------ Method -1 ---------------
// Linear search approach
void findOnce(int arr[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^= arr[i];
    }
    cout << ans;
}

// Time Complexity: O(n)
// Auxiliary space: O(1)

// ------------- Method -2 ---------------
// Binary Search approach
void findOnce(int arr[], int n){
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(arr[mid] == arr[mid+1]){
            bool isEven = ((r-mid+1)%2 == 0);

            // if arr[mid] and arr[mid+1] are same elements and mid to end has even number of items,
            // then element occurring once is at left
            // otherwise at right

            if(isEven) r = mid-1;
            else l = mid+2; // mid+2 is taken because mid and mid+1 have been checked and they are not once occurring but are equal
        }
        else if(arr[mid] == arr[mid-1]){
            bool isEven = ((mid-l+1)%2 == 0);

            // if arr[mid] and arr[mid-1] are same elements and begin to mid has even number of items,
            // then element occurring once is at right
            // otherwise at left

            if(isEven) l = mid+1;
            else r = mid-2; // mid-2 is taken because mid and mid-1 have been checked and they are not once occurring but are equal
        }
        else return arr[mid];
        // if mid and its adjacents are not same in a sorted array, arr[mid] is the once occurring element
    }

    return -1;
}

// Time Complexity: O(log(n))
// Auxiliary space: O(1)

int main(){
    int a[] = {1,1,2,2,3,4,4};
    int n = sizeof(a) / sizeof(a[0]);

    findOnce(a, n);
}